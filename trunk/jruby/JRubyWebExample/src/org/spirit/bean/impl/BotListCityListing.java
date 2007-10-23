/**
 * Berlin Brown
 * Nov 9, 2006
 */

package org.spirit.bean.impl;

import java.io.Serializable;
import java.util.Calendar;
import java.util.List;

/**
 * This is class is used by botverse.
 * 
 * @author Berlin Brown
 * 
 */

public class BotListCityListing implements Serializable {

		private String cityName;
		private Calendar createdOn;
		private Long id;
		
		private List listings;
				
		/**
		 * @return the cityName
		 */
		public String getCityName() {
			return cityName;
		}
		/**
		 * @param cityName the cityName to set
		 */
		public void setCityName(String cityName) {
			this.cityName = cityName;
		}
		/**
		 * @return the createdOn
		 */
		public Calendar getCreatedOn() {
			return createdOn;
		}
		/**
		 * @param createdOn the createdOn to set
		 */
		public void setCreatedOn(Calendar createdOn) {
			this.createdOn = createdOn;
		}
		/**
		 * @return the id
		 */
		public Long getId() {
			return id;
		}
		/**
		 * @param id the id to set
		 */
		public void setId(Long id) {
			this.id = id;
		}
		/**
		 * @return the listings
		 */
		public List getListings() {
			return listings;
		}
		/**
		 * @param listings the listings to set
		 */
		public void setListings(List listings) {
			this.listings = listings;
		}


}
