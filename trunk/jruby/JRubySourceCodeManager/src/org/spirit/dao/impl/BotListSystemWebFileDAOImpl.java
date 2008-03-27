/**
 * Berlin Brown
 * Nov 12, 2006
 */
package org.spirit.dao.impl;

import java.util.Collection;

import org.hibernate.HibernateException;
import org.hibernate.Query;
import org.hibernate.Session;
import org.spirit.bean.impl.BotListSystemWebFile;
import org.spirit.dao.BotListSystemWebFileDAO;
import org.springframework.orm.hibernate3.HibernateCallback;
import org.springframework.orm.hibernate3.support.HibernateDaoSupport;

/**
 * This is class is used by botverse.
 * @author Berlin Brown
 *
 */
public class BotListSystemWebFileDAOImpl extends HibernateDaoSupport 
			implements BotListSystemWebFileDAO {

	private final String DEFAULT_QUERY = "from org.spirit.bean.impl.BotListSystemWebFile file where (file.fext = 'zip' or file.fext = 'tar') order by file.filename";
	private String findFileQuery = null;	
	
	/**
	 * @see org.spirit.dao.BotListSystemWebFileDAO#createVisitAudit(org.spirit.bean.impl.BotListSystemWebFile)
	 */
	public void createWebFile(BotListSystemWebFile file) {		
		getHibernateTemplate().save(file);	
	}
			
	/**
	 * @return the findFileQuery
	 */
	public String getFindFileQuery() {
		if (findFileQuery == null) {
			return DEFAULT_QUERY;
		}
		return findFileQuery;
	}

	/**
	 * @param findFileQuery the findFileQuery to set
	 */
	public void setFindFileQuery(String findFileQuery) {
		this.findFileQuery = findFileQuery;
	}

	public Collection findWebFiles() {
		return getHibernateTemplate().executeFind(
				new HibernateCallback() {
					public Object doInHibernate(Session session) throws HibernateException {
						Query query = session.createQuery(getFindFileQuery());
							
						// Set the maximum results
						query.setMaxResults(500);
						return query.list();
					}
				});
	}
	
}
