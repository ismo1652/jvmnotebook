//
// Berlin Brown
//
// $Id: MainDrawCircle.java,v 1.1 2004/05/12 21:28:16 bigbinc Exp $
//
//
//
package org.retro.gis;


import java.util.*;
import javax.swing.*;
import java.awt.event.*;
import java.awt.*;

import org.apache.log4j.Logger;
import org.apache.log4j.BasicConfigurator;
import org.apache.log4j.PropertyConfigurator;


//
// ;; Main
//
public class MainDrawCircle {

    private static Logger logger = Logger.getLogger(MainDrawCircle.class);
    private static final String defaultLoggerFile = "config/LOGGER_CONFIG";

    public static void main(String [] args) {
	
	PropertyConfigurator.configure(defaultLoggerFile);
	logger.info("Running client.... [ ok ]");

	MapDrawFrame  _map = new MapDrawFrame();
	_map.setVisible(true);

    } // end of the function main...

} // end of the class .........
