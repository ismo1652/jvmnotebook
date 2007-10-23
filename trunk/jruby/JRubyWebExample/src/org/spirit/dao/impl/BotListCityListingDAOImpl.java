/**
 * Berlin Brown
 * Nov 9, 2006
 */

package org.spirit.dao.impl;

import java.util.Collection;

import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.hibernate.HibernateException;
import org.hibernate.Query;
import org.hibernate.Session;
import org.spirit.bean.impl.BotListCityListing;
import org.spirit.dao.BotListCityListingDAO;
import org.springframework.dao.DataAccessException;
import org.springframework.orm.hibernate3.HibernateCallback;
import org.springframework.orm.hibernate3.support.HibernateDaoSupport;

/**
 * This is class is used by botverse.
 * 
 * @author Berlin Brown
 * 
 */

public class BotListCityListingDAOImpl extends HibernateDaoSupport 
	implements BotListCityListingDAO {

	private Log log = LogFactory.getLog(getClass());
	
	private final String DEFAULT_QUERY = "from org.spirit.bean.impl.BotListCityListing city order by city.cityName";	
	
	/**
	 * @see org.spirit.dao.BotListCityListingDAO#findWebFiles()
	 */
	public Collection findCityListings() {
		return getHibernateTemplate().executeFind(
				new HibernateCallback() {
					public Object doInHibernate(Session session) throws HibernateException {
						Query query = session.createQuery(DEFAULT_QUERY);

						// Set the maximum results
						query.setMaxResults(400);
						return query.list();
					}
				});
	}

	/**
	 * @see org.spirit.dao.BotListCityListingDAO#readCityListing(int)
	 */
	public BotListCityListing readCityListing(final int id) throws DataAccessException {
		log.info("Running read query on id=" + id);		
		return (BotListCityListing) getHibernateTemplate().execute(
				new HibernateCallback() {
					public Object doInHibernate(Session session) throws HibernateException {
						Query query = 
							session.createQuery("from org.spirit.bean.impl.BotListCityListing city where city.id = " + id);
						return query.uniqueResult();
					}
				});		
	}


}
