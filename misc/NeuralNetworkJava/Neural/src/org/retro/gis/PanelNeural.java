//
// Berlin Brown
//
// $Id: PanelNeural.java,v 1.3 2004/05/13 21:43:49 bigbinc Exp $
//
// 

package org.retro.gis;

import java.util.*;
import javax.swing.*;
import java.awt.event.*;
import java.awt.*;
import java.awt.geom.Point2D;

public class PanelNeural extends JPanel {

    private Point [] _pts = null;    

    public PanelNeural() {

	this.setBackground(Color.white);

    } // end of hte method ..

    public void setPoints(Point [] _in) {

	_pts = _in;

    } // end of the method ..

    public void paintComponent(Graphics g) {
	
	super.paintComponent(g);

	Font _font = null;
	_font = new Font("Arial", Font.BOLD, 16);
	g.setFont(_font);
	g.setColor(new Color(10,10,160));

	g.drawString("edge: 800,600", 500, 560);
	g.drawString("real: 1.0,0.0", 500, 530);

	// ;;; Set red color for dots ;;;

	g.setColor(Color.red);	
	for (int i = 0; i < _pts.length; i++) {

	    if (_pts[i] != null) {
		
		g.fillOval(_pts[i].x, _pts[i].y, 4, 4);

	    } // end of the if ...

	} // end of the for ....

    } // end of the method ....
    

} // end of the classs...
