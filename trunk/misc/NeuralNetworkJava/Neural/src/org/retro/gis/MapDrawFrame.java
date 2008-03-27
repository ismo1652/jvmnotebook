//
//
// Berlin Brown
//
// $Id: MapDrawFrame.java,v 1.3 2004/05/14 02:51:32 bigbinc Exp $
//
// 
package org.retro.gis;

import java.util.*;
import java.awt.*;

import javax.swing.*;
import java.awt.event.*;
import java.awt.*;

public class MapDrawFrame extends JFrame 
    implements WindowListener,ActionListener,MouseMotionListener {

    public static final int scrWidth = 800;
    public static final int scrHeight = 600;
    
    MapDrawPanel _panel = null;

    public MapDrawFrame() {

	super("[ Map Neural Frame ]");

	this.setSize(scrWidth, scrHeight);
	addWindowListener(this);
	
	_panel = new MapDrawPanel();
	_panel.start();
	getContentPane().add(_panel);
	
    } // end of the method ..
    
    public void windowActivated(WindowEvent e) {}
    
    public void windowClosed(WindowEvent e) {}
    
    public void windowClosing(WindowEvent e) {

	_panel.stop();

	System.out.println("++ Exiting....");
	System.exit(1);

    } // end of the functino

    public void windowDeactivated(WindowEvent e) {}    
    public void windowDeiconified(WindowEvent e) {}        
    public void windowIconified(WindowEvent e) {}        

    public void windowOpened(WindowEvent e) {}

    public void mouseDragged( MouseEvent e ) {}    
    public void mouseMoved(MouseEvent e) {}
    
    public void actionPerformed(java.awt.event.ActionEvent e) {
    } // end of the method ...    
    
} // end of the class ...
