/* 
 * Created on Nov 6, 2006
 * 
 */
package org.spirit.dao.impl;

import java.util.ArrayList;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.spirit.bean.impl.BotListUserVisitAudit;
import org.spirit.dao.BotListUserVisitAuditDAO;
import org.springframework.orm.hibernate3.support.HibernateDaoSupport;


/**
 * @author AP417
 *
 */
public class BotListUserVisitAuditDAOImpl extends HibernateDaoSupport 
			implements BotListUserVisitAuditDAO {
	
	private Log log = LogFactory.getLog(getClass());
	
	/**
	 * @see org.spirit.dao.BotListUserVisitAuditDAO#createVisitAudit(org.spirit.bean.impl.BotListUserVisitAudit)
	 */
	public void createVisitAudit(BotListUserVisitAudit link) {
		log.info("\n\n\n\n/////////////////////////////////");
		log.info("Saving record =" + link);
		getHibernateTemplate().save(link);		
	}

	/**
	 * Get the total users visited.
	 */	
	public long getVisitAuditCount() {
		ArrayList list = (ArrayList) getHibernateTemplate().find("select count(*) from org.spirit.bean.impl.BotListUserVisitAudit");
		if (list == null)
			return -1;
		
		if (list.get(0) instanceof java.lang.Integer) {
			return ((Integer) list.get(0)).longValue();
		} else {
			return -1;
		}
	}
	
	public long getVisitDemCount() {
		ArrayList list = (ArrayList) getHibernateTemplate().find("select count(*) from org.spirit.bean.impl.BotListUserVisitAudit c where c.partyPoll = 'DEM'");
		if (list == null)
			return -1;
		
		if (list.get(0) instanceof java.lang.Integer) {
			return ((Integer) list.get(0)).longValue();
		} else {
			return -1;
		}
	}
	
	
	public long getVisitRepCount() {
		ArrayList list = (ArrayList) getHibernateTemplate().find("select count(*) from org.spirit.bean.impl.BotListUserVisitAudit c where c.partyPoll = 'REP'");
		if (list == null)
			return -1;
		
		if (list.get(0) instanceof java.lang.Integer) {
			return ((Integer) list.get(0)).longValue();
		} else {
			return -1;
		}
	}

}
