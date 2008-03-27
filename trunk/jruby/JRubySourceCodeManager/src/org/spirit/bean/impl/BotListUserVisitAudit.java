/* 
 * Created on Sep 26, 2006
 * 
 */
package org.spirit.bean.impl;

import java.util.Calendar;

/**
 * @author AP417
 *
 */
public class BotListUserVisitAudit implements java.io.Serializable {

	private Long id;
	private String remoteHost;	
	private Calendar createdOn;
	private String partyPoll;
	
	private static final long serialVersionUID = 3487495895819393L;

	/**
	 * @return
	 */
	public Long getId() {
		return id;
	}




	/**
	 * @param long1
	 */
	public void setId(Long long1) {
		id = long1;
	}


	/**
	 * @return
	 */
	public Calendar getCreatedOn() {
		if (createdOn == null) {
			createdOn = Calendar.getInstance();
		}
		return createdOn;
	}

	/**
	 * @param calendar
	 */
	public void setCreatedOn(Calendar calendar) {
		createdOn = calendar;
	}

	/**
	 * @return
	 */
	public static long getSerialVersionUID() {
		return serialVersionUID;
	}

	/**
	 * @return
	 */
	public String getRemoteHost() {
		return remoteHost;
	}

	/**
	 * @param string
	 */
	public void setRemoteHost(String string) {
		remoteHost = string;
	}

	/**
	 * @return the partyPoll
	 */
	public String getPartyPoll() {
		return partyPoll;
	}

	/**
	 * @param partyPoll the partyPoll to set
	 */
	public void setPartyPoll(String partyPoll) {
		this.partyPoll = partyPoll;
	}

}
