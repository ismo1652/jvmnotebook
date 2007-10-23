/**
 * Berlin Brown
 * Nov 9, 2006
 */
package org.spirit.form.base;

import java.io.Serializable;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

/**
 * This is class is used by botverse.
 * 
 * @author Berlin Brown
 * 
 */
public abstract class BotListBaseForm  implements Serializable  {
	
	private String viewName;
	private Log log = LogFactory.getLog(getClass());

	/**
	 * @return the viewName
	 */
	public final String getViewName() {		
		return viewName;
	}

	/**
	 * @param viewName the viewName to set
	 */
	public final void setViewName(String viewName) {
		this.viewName = viewName;
	}

}
