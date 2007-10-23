/**
 * Berlin Brown
 * Nov 9, 2006
 */

package org.spirit.form;

import java.util.Calendar;

import org.spirit.form.base.BotListBaseForm;

/**
 * This is class is used by botverse.
 * 
 * @author Berlin Brown
 * 
 */

public class BotListCityListingForm extends BotListBaseForm {

		private String cityName;
		private Calendar createdOn;
		private Long id;
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


}
