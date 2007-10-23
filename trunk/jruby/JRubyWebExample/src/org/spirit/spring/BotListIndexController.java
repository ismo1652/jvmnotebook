/**
 * Berlin Brown
 * Nov 16, 2006
 */
package org.spirit.spring;

import java.util.Collection;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.spirit.dao.BotListCityListingDAO;
import org.springframework.web.servlet.ModelAndView;
import org.springframework.web.servlet.mvc.AbstractController;

/**
 * This is class is used by botverse.
 * @author Berlin Brown
 *
 */
public class BotListIndexController extends AbstractController {
	
	/**
	 * City Listing.
	 */
	private BotListCityListingDAO cityListingDao = null;
	
	/**
	 * Access the BotList Ruby DAO Handler.
	 */
	private BotListRubyDAOHandler handler;
	
	/**
	 * @return the handler
	 */
	public BotListRubyDAOHandler getHandler() {
		return handler;
	}


	/**
	 * @param handler the handler to set
	 */
	public void setHandler(BotListRubyDAOHandler handler) {
		this.handler = handler;
	}


	/**
	 * @return the cityListingDao
	 */
	public BotListCityListingDAO getCityListingDao() {
		return cityListingDao;
	}


	/**
	 * @param cityListingDao the cityListingDao to set
	 */
	public void setCityListingDao(BotListCityListingDAO cityListingDao) {
		this.cityListingDao = cityListingDao;
	}


	private Collection findCityListings() {
		if (this.getCityListingDao() != null) {
			return this.getCityListingDao().findCityListings();
		} else {
			return null;
		}
	}
		
	/**
	 * @see org.springframework.web.servlet.mvc.AbstractController#handleRequestInternal(javax.servlet.http.HttpServletRequest, javax.servlet.http.HttpServletResponse)
	 */
	protected ModelAndView handleRequestInternal(HttpServletRequest request, HttpServletResponse response) throws Exception {
		ModelAndView mvc = new ModelAndView("index");					
		mvc.addObject("citylistings", findCityListings());
		
		// Perform an audit of this page.
		if (getHandler() != null) {
			getHandler().auditLogPage(request, "index.html");
		}
		
		return mvc;
	}

}
