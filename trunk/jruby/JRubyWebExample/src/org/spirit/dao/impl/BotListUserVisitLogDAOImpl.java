/**
 * Berlin Brown
 * Nov 9, 2006
 */

package org.spirit.dao.impl;

import java.util.ArrayList;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.spirit.bean.impl.BotListUserVisitLog;
import org.spirit.dao.BotListUserVisitLogDAO;
import org.springframework.orm.hibernate3.support.HibernateDaoSupport;

/**
 * This is class is used by botverse.
 * 
 * @author Berlin Brown
 * 
 */

public class BotListUserVisitLogDAOImpl extends HibernateDaoSupport 
			implements BotListUserVisitLogDAO {
	
	private Log log = LogFactory.getLog(getClass());
	
	/**
	 * @see org.spirit.dao.BotListUserVisitAuditDAO#createVisitAudit(org.spirit.bean.impl.BotListUserVisitAudit)
	 */
	public void createVisitLog(BotListUserVisitLog link) {		
		getHibernateTemplate().save(link);		
	}

	/**
	 * Get the total users visited.
	 */	
	public long getVisitAuditCount() {
		ArrayList list = (ArrayList) getHibernateTemplate().find("select count(*) from org.spirit.bean.impl.BotListUserVisitLog");
		if (list == null)
			return -1;
		
		if (list.get(0) instanceof java.lang.Integer) {
			return ((Integer) list.get(0)).longValue();
		} else {
			return -1;
		}
	}
	
	public long getUniqueVisitAuditCount() {
		ArrayList list = (ArrayList) getHibernateTemplate().find("select count(distinct remoteHost) from org.spirit.bean.impl.BotListUserVisitLog");
		if (list == null)
			return -1;
		
		if (list.get(0) instanceof java.lang.Integer) {
			return ((Integer) list.get(0)).longValue();
		} else {
			return -1;
		}
	}
	
}
