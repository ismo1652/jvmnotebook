//
// Berlin Brown
//
// bigbinc@hotmail.com
//
// $Id: FrameNeural.java,v 1.1 2004/05/06 13:29:53 bigbinc Exp $
//
package org.retro.gis;

import java.util.*;
import javax.swing.*;
import java.awt.event.*;
import java.awt.*;

import java.awt.geom.Point2D;

public class FrameNeural extends JFrame {

    private Point [] _pts = null;

    private PanelNeural _panel = new PanelNeural();

    public FrameNeural() {
	
	super("Frame-Launch");
	this.setSize(800, 600);

	getContentPane().add(_panel);

    } // end of the method .

    public void setPoints(Point [] _in) {
	
	_pts = _in;
	_panel.setPoints(_pts);
	
    } // end of the method ...


} // end of the class .....
