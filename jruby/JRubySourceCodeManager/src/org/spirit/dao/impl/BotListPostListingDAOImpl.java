/* 
 * Created on Nov 6, 2006
 * 
 */
package org.spirit.dao.impl;

import org.spirit.bean.impl.BotListPostListing;
import org.spirit.dao.BotListPostListingDAO;
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
		

}
