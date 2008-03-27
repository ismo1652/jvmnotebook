/*
 * Created on Nov 6, 2006
 * 
 */
package org.spirit.dao;

import java.util.Collection;

import org.spirit.bean.impl.BotListSystemWebFile;


/**
 * @author AP417
 *
 */
public interface BotListSystemWebFileDAO {
	
	public void createWebFile(BotListSystemWebFile file);		
	
	public Collection findWebFiles();
	public void setFindFileQuery(String findFileQuery);
	public String getFindFileQuery();
}
