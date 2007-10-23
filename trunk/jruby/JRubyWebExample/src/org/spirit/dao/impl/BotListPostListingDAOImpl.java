/* 
 * Created on Nov 6, 2006
 * 
 */
package org.spirit.dao.impl;

import java.util.List;

import org.hibernate.HibernateException;
import org.hibernate.Query;
import org.hibernate.Session;
import org.spirit.bean.impl.BotListPostListing;
import org.spirit.dao.BotListPostListingDAO;
import org.springframework.dao.DataAccessException;
import org.springframework.orm.hibernate3.HibernateCallback;
import org.springframework.orm.hibernate3.support.HibernateDaoSupport;


/**
 * @author AP417
 *
 */
public class BotListPostListingDAOImpl extends HibernateDaoSupport 
			implements BotListPostListingDAO {
			
	/**
	 * @see org.spirit.dao.BotListUserLinkDAO#createLink(org.spirit.bean.impl.BotListUserLink)
	 */
	public void createPostListing(BotListPostListing listing) {
		getHibernateTemplate().save(listing);
	}

	/**
	 * @see org.spirit.dao.BotListPostListingDAO#listPostListings()
	 */
	public List listPostListings(final String queryStr) {
		return getHibernateTemplate().executeFind(
				new HibernateCallback() {
					public Object doInHibernate(Session session) throws HibernateException {
						Query query = session.createQuery(queryStr);

						// Set the maximum results
						query.setMaxResults(400);
						return query.list();
					}
				});
	}
	
	/**
	 * @see org.spirit.dao.BotListCityListingDAO#readCityListing(int)
	 */
	public BotListPostListing readPostListing(final int id) throws DataAccessException {			
		return (BotListPostListing) getHibernateTemplate().execute(
				new HibernateCallback() {
					public Object doInHibernate(Session session) throws HibernateException {
						Query query = 
							session.createQuery("from org.spirit.bean.impl.BotListPostListing post where post.id = " + id);
						return query.uniqueResult();
					}
				});		
	}
	 
}
