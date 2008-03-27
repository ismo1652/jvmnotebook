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
public class BotListSystemWebFile implements java.io.Serializable {

	private Long id;	
	private Calendar createdOn;	
		
	private String filename;
	private Long fsize;
	private Long fmtime;
	private String fext;
	private String projectname;	
	
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
	 * @return the fext
	 */
	public String getFext() {
		return fext;
	}




	/**
	 * @param fext the fext to set
	 */
	public void setFext(String fext) {
		this.fext = fext;
	}




	/**
	 * @return the filename
	 */
	public String getFilename() {
		return filename;
	}




	/**
	 * @param filename the filename to set
	 */
	public void setFilename(String filename) {
		this.filename = filename;
	}




	/**
	 * @return the fmtime
	 */
	public Long getFmtime() {
		return fmtime;
	}




	/**
	 * @param fmtime the fmtime to set
	 */
	public void setFmtime(Long fmtime) {
		this.fmtime = fmtime;
	}




	/**
	 * @return the fsize
	 */
	public Long getFsize() {
		return fsize;
	}




	/**
	 * @param fsize the fsize to set
	 */
	public void setFsize(Long fsize) {
		this.fsize = fsize;
	}




	/**
	 * @return the projectname
	 */
	public String getProjectname() {
		return projectname;
	}




	/**
	 * @param projectname the projectname to set
	 */
	public void setProjectname(String projectname) {
		this.projectname = projectname;
	}

	
}
