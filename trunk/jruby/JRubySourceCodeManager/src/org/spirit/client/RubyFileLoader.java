/**
 * Berlin Brown
 * Nov 12, 2006
 * 
 * Note: Xerces required and not part of Spring2 dist.
 */
package org.spirit.client;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

import org.apache.bsf.BSFException;
import org.apache.bsf.BSFManager;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.jruby.javasupport.bsf.JRubyEngine;

import org.springframework.context.support.ClassPathXmlApplicationContext;

/**
 * This is class is used by botverse.
 * @author Berlin Brown
 *
 */
public class RubyFileLoader {
	
	private Log log = LogFactory.getLog(getClass());
	
	/**
	 * Ruby and BSF Managers.
	 */
	private BSFManager mManager;
	private JRubyEngine mEngine;

	// configuration parametes and defaults
	private String mScriptEngineClass = "org.jruby.javasupport.bsf.JRubyEngine";
	
	private String mScriptEngineName = "ruby";
	
	private void setEngine(JRubyEngine jRubyEngine) {
		mEngine = jRubyEngine;
	}
	
	/**
	 * Establish bean objects for Ruby environment.
	 * 
	 * @throws BSFException
	 */
	protected final void initializeManagerBeans() throws BSFException {
				 
	    ClassPathXmlApplicationContext appContext = new ClassPathXmlApplicationContext(new String[] {
	        "botlistings-servlet.xml"
	    });
	    	    
		// Define the hibernate database objects for later use
		mManager.declareBean("log", log, log.getClass());		
		mManager.declareBean("context", appContext, appContext.getClass());
	}
	
	/**
	 * Read an entire ruby script in from a file. Isn't there a better way to do this?
	 * @param filename
	 * @return
	 * @throws IOException
	 */
	private String readRubyScript(String filename) throws IOException {		
			
		log.info("readingRubyScript(): " + filename);		

		File rubyScript = new File(filename);
		BufferedReader reader = new BufferedReader(new FileReader(rubyScript));
		StringBuffer rubyCode = new StringBuffer();
		String s;
		while ((s = reader.readLine()) != null) {
			rubyCode.append(s);
			rubyCode.append("\n");
		}
		return rubyCode.toString();
	}
	
	/**
	 * Invoke Ruby Controller Method.
	 * 
	 * @param rubyController
	 * @param methodName
	 * @param args
	 * @return
	 * @throws BSFException
	 */
	protected Object invokeRubyControllerMethod(Object rubyController, String methodName, Object[] args) throws BSFException {
		if (rubyController == null) {
			return null;
		}
		return getEngine().call(rubyController, methodName, args);
	}
	
	public JRubyEngine getEngine() {
		return mEngine;
	}
	
	protected void initializeRubyScript(String script) throws BSFException {

		log.info("RubyRadController: *** Calling Initialize Manager");

		BSFManager.registerScriptingEngine(getScriptEngineName(), mScriptEngineClass, new String[] { "rb" });
		mManager = new BSFManager();
		setEngine((JRubyEngine) (mManager.loadScriptingEngine(getScriptEngineName())));
		initializeManagerBeans();

		String initFilePath = script;
		try {

			log.info("Reading Init Script File = " + initFilePath);
			String rubyCode = readRubyScript(initFilePath);
			Object controller = mManager.eval(getScriptEngineName(), "(java)", 1, 1, rubyCode);			
			invokeRubyControllerMethod(controller, "initializeApplication", new Object[] {
			});
			getLogger().info("RubyRadController: Ran initialization script " + script);			

		} catch (BSFException e) {
			// rethrow the exception with a detailed error message.
			Throwable targetException = e.getTargetException();
			getLogger().warn("Error running initialization script", e);
			throw new BSFException(e.getReason(), targetException.getMessage(), targetException);
		} catch (IOException e) {
			getLogger().warn("Unable to find initialization script", e);
		}
	}
	
	public Log getLogger() {
		return log;
	}
	public void setLogger(Log logger) {
		log = logger;
	}
	
	public String getScriptEngineName() {
		return mScriptEngineName;
	}
	

	/******************************************************
	 * Main Entry Point 
	 ******************************************************/
	public static void main(String [] args) throws Exception {
		
		System.out.println("Loading Scan Files");
		RubyFileLoader loader = new RubyFileLoader();
		
		if (args.length != 2) {
			System.out.println("Usage: RubyFileLoader -f <FILENAME>");
			return;
		}		
		
		loader.initializeRubyScript(args[1]);
		
	}
}
