/*
 * Berlin Brown
 * Created on Nov 2, 2006
 * 
 * -- Notes --
 * Updated, some issues with getServletPath()
 * Log oriented debugging code added. 
 * 
 */
package org.spirit.spring;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.Iterator;
import java.util.Map;
import java.util.TreeMap;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.apache.bsf.BSFException;
import org.apache.bsf.BSFManager;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.jruby.javasupport.bsf.JRubyEngine;
import org.spirit.dao.BotListPostListingDAO;
import org.spirit.dao.BotListUserLinkDAO;
import org.spirit.form.base.BotListBaseForm;
import org.springframework.context.ApplicationContext;
import org.springframework.validation.BindException;
import org.springframework.web.servlet.ModelAndView;

/**
 * Spring Controller that interfaces between spring and jruby; reads the ruby script and invokes the
 * correct model and view.
 * 
 * @author Berlin Brown 
 */
public class BotListRubyController extends BotListRubyDAOHandler {

	private Log log = LogFactory.getLog(getClass());

	private static int classInvokedId = 0;
	private static final String _CLASS_IDENTIFIER = "BotListRubyController: ";
	private static final String PROCESSING_TIME = "processingtime";

	/**
	 * User Link Data Access Object.
	 */
	private BotListUserLinkDAO userLinkDAO = null;

	/**
	 * Post Listing DAO.
	 */
	private BotListPostListingDAO postListingDAO = null;

	/**
	 * Ruby and BSF Managers.
	 */
	private BSFManager mManager;
	private JRubyEngine mEngine;

	// configuration parametes and defaults
	private String mScriptEngineClass = "org.jruby.javasupport.bsf.JRubyEngine";

	private String mJspDir = "/WEB-INF/jsps";
	private String mScriptEngineName = "ruby";
	private String mScriptExtension = "rb";
	private String mInitScript = "/WEB-INF/jsps/INIT.rb";

	/** 
	 * Record keeping, when the script starts and ends.
	 */
	private long scriptStartTime = 0;
	private long scriptEndTime = 0;

	/**
	 * Default Constructor.	 
	 */
	BotListRubyController() {
		this.setBindOnNewForm(true);
	}

	public static int getClassInvoked() {
		classInvokedId++;
		return classInvokedId; 
	}

	private static String CLASS_IDENTIFIER() {
		return getClassInvoked() + "| " + _CLASS_IDENTIFIER;
	}

	/**
	 * This function is quite similar to the Jobster internal PathToViewController.
	 * Duplicated here so that the RAD module can be self contained.
	 */
	public String getViewNameFromServletPath(String servletPath) {

		String viewName = servletPath;
		int beg = 0, end = viewName.length();		
		if (end > 0 && viewName.charAt(0) == '/') {
			beg = 1;
		} else {
			// We are now assuming incoming servletPath is actually a full URL
			beg = servletPath.lastIndexOf('/');
			beg += 1;
		}

		int dot = viewName.lastIndexOf('.');
		if (dot >= 0) {
			end = dot;
		}
		viewName = viewName.substring(beg, end);		
		return viewName;

	}

	public String getDefaultViewNameFromRequest(HttpServletRequest request) {
		log.info(CLASS_IDENTIFIER() + "getDefaultViewNameFromRequest() - From Request: " + request.getRequestURL());
		return getViewNameFromServletPath(request.getRequestURL().toString());
	}

	protected ModelAndView getModelAndView(Object rubyResult, String defaultView) {

		String viewName = null;
		if (Map.class.isAssignableFrom(rubyResult.getClass())) {
			Map map = (Map) rubyResult;
			// look for an embedded view name in the model
			viewName = (String) map.get("viewName");
			
		} else if (BotListBaseForm.class.isAssignableFrom(rubyResult.getClass())) {
			
			// Or use the Base Class Form to get the view name.
			BotListBaseForm form = (BotListBaseForm) rubyResult;
			if (form.getViewName() != null) {
				viewName = form.getViewName();
			}
		}
		
		if (viewName == null) {
			viewName = defaultView;
		}

		log.info(CLASS_IDENTIFIER() + "*** getModelAndView() View Name= " + viewName);
		log.info(CLASS_IDENTIFIER() + "*** getModelAndView() Command Name= " + getCommandName());

		TreeMap result = new TreeMap();
		result.put(getCommandName(), rubyResult);				
				
		// keep record of processing time
		scriptEndTime = System.currentTimeMillis();
		long diff = scriptEndTime - scriptStartTime;
		double diffS = diff / 1000.0d;
		result.put(PROCESSING_TIME, "" + diffS);
		return new ModelAndView(viewName, result);	
	}

	/**
	 * Print Request Information
	 */
	private void printRequestInfo(HttpServletRequest request) {					
		log.info(CLASS_IDENTIFIER() + " showForm() requestURL=" + request.getRequestURL());		
	}

	/**
	 * @see org.springframework.web.servlet.mvc.AbstractFormController#showForm(javax.servlet.http.HttpServletRequest, javax.servlet.http.HttpServletResponse, org.springframework.validation.BindException)
	 */
	protected ModelAndView showForm(HttpServletRequest request, HttpServletResponse response, BindException errors) throws Exception {
		printRequestInfo(request);
		return getModelAndView(this.getCommand(request), getDefaultViewNameFromRequest(request));
	}

	/**
	 * @see org.springframework.web.servlet.mvc.AbstractFormController#processFormSubmission(javax.servlet.http.HttpServletRequest, javax.servlet.http.HttpServletResponse, java.lang.Object, org.springframework.validation.BindException)
	 */
	protected ModelAndView processFormSubmission(HttpServletRequest request, HttpServletResponse response, Object command, BindException errors) throws Exception {
				
		// The command could be an instance of a map
		// or one of the Form beans
		if (command instanceof Map) {
			Map map = (java.util.Map) command;			
			for (Iterator iter = request.getParameterMap().entrySet().iterator(); iter.hasNext();) {
				Map.Entry e = (Map.Entry) iter.next();
				Object[] values = ((Object[]) e.getValue());
				map.put(e.getKey(), values[0]);				
			}					

		}
		Object result = invokeRubyControllerMethod(request, "onSubmit", 
							new Object[] { request, response, command, errors });
		
		if (errors.getErrorCount() > 0) {			
			return new ModelAndView(getDefaultViewNameFromRequest(request), errors.getModel());
		} else {						
			return getModelAndView(result, getDefaultViewNameFromRequest(request));
		}
	}


	/**
	 * Establish bean objects for Ruby environment.
	 * 
	 * @throws BSFException
	 */
	protected final void initializeManagerBeans() throws BSFException {

		// Define the hibernate database objects for later use
		mManager.declareBean("context", getApplicationContext(), ApplicationContext.class);
		if (this.getUserLinkDao() != null) {
			mManager.declareBean("daohelper", this.getUserLinkDao(), BotListUserLinkDAO.class);
		} else {
			log.error(CLASS_IDENTIFIER() + "** ERR: Invalid Database Object Helper **");
		}
		
		if (this.getPostListingDao() != null) {
			mManager.declareBean("daohelperlisting", getPostListingDao(), getPostListingDao().getClass());
		} else {
			log.error(CLASS_IDENTIFIER() + "** ERR: Invalid Database Object Helper **");
		}
		
		// Set this object for DAO access
		mManager.declareBean("controller", this, BotListRubyDAOHandler.class);		
	}

	protected void initializeManager() throws BSFException {

		BSFManager.registerScriptingEngine(getScriptEngineName(), getScriptEngineClass(), new String[] { getScriptExtension()});
		mManager = new BSFManager();
		setEngine((JRubyEngine) (mManager.loadScriptingEngine(getScriptEngineName())));
		initializeManagerBeans();

		String initFilePath = getServletContext().getRealPath(getInitScript());
		try {

			log.info(CLASS_IDENTIFIER() + " Reading Init Script File = " + initFilePath);
			String rubyCode = readRubyScript(initFilePath);
			Object controller = getManager().eval(getScriptEngineName(), "(java)", 1, 1, rubyCode);
			invokeRubyControllerMethod(controller, "initializeApplication", new Object[] {
			});
			getLogger().info("RubyRadController: Ran initialization script " + getInitScript());
			onInitializeManager();

		} catch (BSFException e) {
			// rethrow the exception with a detailed error message.
			Throwable targetException = e.getTargetException();
			getLogger().warn("Error running initialization script", e);
			throw new BSFException(e.getReason(), targetException.getMessage(), targetException);
		} catch (IOException e) {
			getLogger().warn("Unable to find initialization script", e);
		}
	}

	public BSFManager getManager() throws BSFException {

		if (mManager == null) {
			initializeManager();
		}
		return mManager;
	}

	/**
	 * Read an entire ruby script in from a file. Isn't there a better way to do this?
	 * @param filename
	 * @return
	 * @throws IOException
	 */
	private String readRubyScript(String filename) throws IOException {		
			
		log.info(CLASS_IDENTIFIER() + " readingRubyScript(): " + filename);		

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
	 * Get Ruby Controller.		 
	 * @param request
	 * @return
	 * @throws BSFException
	 */
	public Object getRubyController(HttpServletRequest request) throws BSFException {

		BSFManager manager = getManager();
		manager.declareBean("request", request, HttpServletRequest.class);

		final String CACHED_RUBY_CONTROLLER_ATTRIBUTE = "__RUBYCONTROLLER";

		Object controller = null;
		try {
			this.scriptStartTime = System.currentTimeMillis();
			// Currently, getServletPath() is returning an incorrect value
			// Use the full URL instead to get the correct servletPath
			//String servletPath = request.getServletPath();
			String fullURL = request.getRequestURL().toString();
			int lastPos = fullURL.lastIndexOf("/");
			String servletPath = "/" + fullURL.substring(lastPos + 1, fullURL.length()); 			
			String baseFilePath = getServletContext().getRealPath(getJspDir());

			String filename = baseFilePath + servletPath.replaceAll("\\.[a-zA-Z]+$", "." + getScriptExtension());
			log.info(CLASS_IDENTIFIER() + "Loading ruby script=" + filename);				

			String rubyCode = readRubyScript(filename);
			log.info(CLASS_IDENTIFIER() + "Running ruby script=" + filename);

			controller = manager.eval(getScriptEngineName(), "(java)", 1, 1, rubyCode);
			request.setAttribute("__manager", manager);
			request.setAttribute(CACHED_RUBY_CONTROLLER_ATTRIBUTE, controller);

		} catch (IOException e) {

			// we don't care if the controller file doesn't exist-- we don't require one.
			System.err.println("********* Controller File Does Not Exist *********");
			System.err.println(e.getMessage());


		} catch (BSFException e) {

			// rethrow the exception with a detailed error message.
			Throwable targetException = e.getTargetException();
			// BSFManager likes to get in a bad state when errors happen
			setManager(null);
			throw new BSFException(e.getReason(), targetException.getMessage(), targetException);

		}

		return controller;
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

	/**
	 * Invoke the Ruby Controller Method.
	 * 
	 * @param request
	 * @param methodName
	 * @param args
	 * @return
	 * @throws BSFException
	 */
	protected Object invokeRubyControllerMethod(HttpServletRequest request, String methodName, Object[] args) throws BSFException {
		return invokeRubyControllerMethod(getRubyController(request), methodName, args);
	}

	/**
	 * Form Backing Object.
	 * You must create the command without commandClass being set - either 
	 * set commandClass or (in a form controller) override formBackingObject.
	 */
	protected Object formBackingObject(HttpServletRequest request) throws Exception {

		Object model = null;
		Object mapOrController = getRubyController(request);
	
		log.info(CLASS_IDENTIFIER() + " [formBackingObject()]: " + request);		

		if (mapOrController != null) {
			if (Map.class.isAssignableFrom(mapOrController.getClass())) {
				model = mapOrController;
				log.info(CLASS_IDENTIFIER() + " Using Map Or Controller");
			} else {
				log.info(CLASS_IDENTIFIER() + " invoking Ruby Controller Method");
				model = invokeRubyControllerMethod(mapOrController, "getModel", new Object[] { request });
			}
		}

		if (model == null) {			
			return new TreeMap();
		}		

		return model;
	}

	/**************************************************************************
	 *  Setter and Getter Utility Methods
	 **************************************************************************/
	protected void onInitializeManager() {
	}

	private void setEngine(JRubyEngine jRubyEngine) {
		mEngine = jRubyEngine;
	}

	public String getJspDir() {
		return mJspDir;
	}
	public void setJspDir(String jspDir) {
		mJspDir = jspDir;
	}

	public Log getLogger() {
		return log;
	}
	public void setLogger(Log logger) {
		log = logger;
	}

	public void setManager(BSFManager manager) {
		mManager = manager;
	}
	public JRubyEngine getEngine() {
		return mEngine;
	}

	public String getScriptEngineClass() {
		return mScriptEngineClass;
	}

	public void setScriptEngineClass(String scriptEngineClass) {
		mScriptEngineClass = scriptEngineClass;
	}

	public String getScriptEngineName() {
		return mScriptEngineName;
	}

	public void setScriptEngineName(String scriptEngineName) {
		mScriptEngineName = scriptEngineName;
	}

	public String getScriptExtension() {
		return mScriptExtension;
	}

	public void setScriptExtension(String scriptExtension) {
		mScriptExtension = scriptExtension;
	}

	public String getInitScript() {
		return mInitScript;
	}

	public void setInitScript(String initScript) {
		mInitScript = initScript;
	}

	/******************************************************
	 * 
	 *  Set the Data Access Object
	 *  
	 ******************************************************/
	public void setUserLinkDao(BotListUserLinkDAO dao) {
		this.userLinkDAO = dao;
	}

	public BotListUserLinkDAO getUserLinkDao() {
		return this.userLinkDAO;
	}
	
	/**
	 * @return the postListingDAO
	 */
	public BotListPostListingDAO getPostListingDao() {
		return postListingDAO;
	}

	/**
	 * @param postListingDAO the postListingDAO to set
	 */
	public void setPostListingDao(BotListPostListingDAO postListingDAO) {
		this.postListingDAO = postListingDAO;
	}

}