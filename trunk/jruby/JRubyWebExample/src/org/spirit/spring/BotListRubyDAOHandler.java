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

import javax.servlet.http.HttpServletRequest;

import org.spirit.bean.impl.BotListUserVisitLog;
import org.spirit.dao.BotListCityListingDAO;
import org.spirit.dao.BotListPostListingDAO;
import org.spirit.dao.BotListUserLinkDAO;
import org.spirit.dao.BotListUserVisitLogDAO;
import org.springframework.web.servlet.mvc.AbstractFormController;

/**
 * Spring Controller that interfaces between spring and jruby; reads the ruby script and invokes the
 * correct model and view.
 * 
 * @author Berlin Brown 
 */
public abstract class BotListRubyDAOHandler extends AbstractFormController {

	/**
	 * User Link Data Access Object.
	 */
	private BotListUserLinkDAO userLinkDAO = null;

	/**
	 * User Visit Audit Object.
	 */
	private BotListUserVisitLogDAO userVisitAudit = null;

	/**
	 * Post Listing DAO.
	 */
	private BotListPostListingDAO postListingDAO = null;
	
	/**
	 * City Listing.
	 */
	private BotListCityListingDAO cityListingDao = null;
	
	
	/******************************************************
	 * 
	 *  Audit Utilities
	 *  
	 ******************************************************/
	
	/**
	 * To call, use:
	 * 
	 */
	public void auditLogPage(HttpServletRequest request, String curPage) {
		if (userVisitAudit != null) {
			BotListUserVisitLog link = new BotListUserVisitLog();
			link.setRequestUri(request.getRequestURI());
			link.setRequestPage(curPage);
			link.setHost(request.getHeader("host"));
			link.setReferer(request.getHeader("referer"));
			link.setRemoteHost(request.getRemoteAddr());
			link.setUserAgent(request.getHeader("user-agent"));
			userVisitAudit.createVisitLog(link);
		}
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

	public void setUserVisitLogDao(BotListUserVisitLogDAO dao) {
		this.userVisitAudit = dao;
	}

	public BotListUserVisitLogDAO getUserVisitLogDao() {
		return this.userVisitAudit;
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

}