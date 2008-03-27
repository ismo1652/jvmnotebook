//
// Berlin Brown
//
// $Id: MapDrawPanel.java,v 1.2 2004/05/14 02:51:32 bigbinc Exp $
//
//
package org.retro.gis;

import org.retro.neural.*;

import java.util.*;
import javax.swing.*;
import java.awt.event.*;
import java.awt.*;
import java.awt.geom.Point2D;

public class MapDrawPanel extends JPanel implements Runnable {


    private static final double initial_learning_rate = 0.5;
    private static final double final_learning_rate = 0.005;
    private static final double initial_width = 3.0;
    private static final double final_width = 0.1;
    private static final int timemax = 1000;
    private static final int timesteps = 10;

    private static final int grid_size = 14;    

    private static final int maxRingPoints = 10000;
    private static final int maxTimer = 10;

    private final double radOneDegree = (Math.PI / 180.0);

    private final Font _font;
    
    private static final int state_Load = 0;
    private static final int state_RunSOM = 1;
    
    private Thread _thread = null;
    
    private Point _ringScreen [] = new Point[maxRingPoints];
    private Point2D.Double _ring [] = new Point.Double[maxRingPoints];

    private Point lineFrom [] = new Point[(grid_size * (grid_size - 1)) * 2];
    private Point lineTo [] = new Point[(grid_size * (grid_size - 1)) * 2];
    
    private SOM _self_organizing_map = null;

    private Point _somScreen [] = new Point[grid_size * grid_size];
    private double _som_incoming[][] = new double[maxRingPoints][2];

    private int _timer = 0;
    private int _state = state_Load;

    // ................................................
    
    {	
	_font = new Font("Arial", Font.BOLD, 16);

    } // end of the block ...

    public MapDrawPanel() {
	
	super();
	this.setBackground(Color.white);
	
	_thread = null;
	renderRing();
	
    } // end of the method ...

    private void renderWeights() {
	
	// [ rows by 2 x 2 ]
	
	double [][][] _map = _self_organizing_map.getWeights();
       
	int ictr = 0;
	int i;
	int j;

	int scr_hw = MapDrawFrame.scrWidth / 2;
	int scr_hh = MapDrawFrame.scrHeight / 2;    
	
	// [ draw the rows ]
	ictr = 0;
	for (i = 0; i < _map.length; i++) {	    
	    for (j = 1; j < _map[i].length; j++) {

		double x = -1;
		double y = -1; 
		int scr_x = -1;
		int scr_y = -1;

		x = _map[i][j-1][0];
		y =  _map[i][j-1][1];		
		scr_x = (int)((x / 2.0) * scr_hw) + scr_hw;
		scr_y = (int)((y / 2.0) * scr_hh) + scr_hh;		
		lineFrom[ictr] = new Point(scr_x, scr_y);

		// [ draw connecting point ]
		x = _map[i][j][0];
		y =  _map[i][j][1];		
		scr_x = (int)((x / 2.0) * scr_hw) + scr_hw;
		scr_y = (int)((y / 2.0) * scr_hh) + scr_hh;		
		lineTo[ictr] = new Point(scr_x, scr_y);

		ictr++;
		
	    } // end of the for ...[inner]
	} // end of the for ..[outer]
	
	for (j = 0; j < _map.length; j++) {	    
	    for (i = 1; i < _map[j].length; i++) {

		double x = -1;
		double y = -1; 
		int scr_x = -1;
		int scr_y = -1;

		x = _map[i-1][j][0];
		y =  _map[i-1][j][1];		
		scr_x = (int)((x / 2.0) * scr_hw) + scr_hw;
		scr_y = (int)((y / 2.0) * scr_hh) + scr_hh;		
		lineFrom[ictr] = new Point(scr_x, scr_y);

		// [ draw connecting point ]
		x = _map[i][j][0];
		y =  _map[i][j][1];		
		scr_x = (int)((x / 2.0) * scr_hw) + scr_hw;
		scr_y = (int)((y / 2.0) * scr_hh) + scr_hh;		
		lineTo[ictr] = new Point(scr_x, scr_y);

		ictr++;
		
	    } // end of the for ...[inner]
	} // end of the for ..[outer]

	
	
	// [ draw the actual points ]
	//................................................................x
	ictr = 0;
	for (i = 0; i < _map.length; i++) {

	    for (j = 0; j < _map[i].length; j++) {
	    	    
		double x = _map[i][j][0];
		double y =  _map[i][j][1];		
		int scr_x = (int)((x / 2.0) * scr_hw) + scr_hw;
		int scr_y = (int)((y / 2.0) * scr_hh) + scr_hh;	    
		
		_somScreen[ictr] = new Point(scr_x, scr_y);	    
		
		ictr++;
		
	    } // end of the for [ inner ]
	    
	} // end of the [ outer ]
	
	_self_organizing_map.learn(initial_learning_rate, final_learning_rate,
				   initial_width, final_width, timesteps);

		
    } // end of the method ....

    private void renderRing() {
    
	double deg = 0;
	int scr_hw = MapDrawFrame.scrWidth / 2;
	int scr_hh = MapDrawFrame.scrHeight / 2;    
    
	for (int i = 0; i < _ring.length; i++) {
	    
	    double throw_x = Math.random() * 1.5 * 0.13;
	    double throw_y = Math.random() * 1.5 * 0.13;
	    
	    double x = (Math.cos(deg) * 1.5) + throw_x;
	    double y = (Math.sin(deg) * 1.5) + throw_y;

	    _som_incoming[i][0] = x;
	    _som_incoming[i][1] = y;

	    deg += radOneDegree;
	    
	    //.. [ screen conversion ] ........................................................
	    
	    // ;; 2.0 is needed to scale down the actual radius of the ring
	    int scr_x = (int)((x / 2.0) * scr_hw) + scr_hw;
	    int scr_y = (int)((y / 2.0) * scr_hh) + scr_hh;	    
	    
	    _ring[i] = new Point.Double(x, y);
	    _ringScreen[i] = new Point(scr_x, scr_y);       

	} // end of the for ...
	
	if (_self_organizing_map == null) {

	    _self_organizing_map = new SOM(_som_incoming, grid_size, grid_size);

	} else {

	    // nothing yet ;;	    

	} // end of the if ...
	

    } // end of the method ....
    
    public void changeState() {
	
	_timer++;
	if (_timer >= maxTimer) {
	    
	    _timer = 0;
	    
	    // ;; change state ;;
	    switch(_state) {
		
	    case 0:
		
		_state = state_RunSOM;

		break;

	    case 1:
		
		_state = state_RunSOM;
		
		renderWeights();

		break;		

	    }; // end of switch ;;

	} // end of the if ..

    } // end of the method .....

    public void start() {

	if (_thread == null) {

	    _timer = 0;
	    _state = state_Load;
	    
	    _thread = new Thread(this);
	    _thread.start();	   

	} // end of the if 

    } // end of the method start...

    public void stop() {
	
	_thread = null;

    } // end of the method ...

    public void run() {		
	
	while(_thread != null) {	   
	    
	    try {
		
		_thread.sleep(200);
		changeState();

		repaint();	       
		
	    } catch(Exception e) {
		
		e.printStackTrace();

	    } // end of the try - catch 
	    
	} // end of the while ...
	
	
    } // end of the method ...
    

    public void paintComponent(Graphics g) {

	super.paintComponent(g);
	
	g.setFont(_font);
	g.setColor(new Color(10,10,210));
	
	g.drawString("Panel Loaded...", 10, 20);
	g.drawString("Timer: " + _timer + " State: " + _state, 10, 44);

	g.setColor(new Color(10,210,10));
	for (int i = 0; i < _ring.length; i++) {
	    
	    g.drawOval(_ringScreen[i].x, _ringScreen[i].y, 2, 2);

	} // end of the for ...

	g.setColor(new Color(210,10,10));
	if (_somScreen[0] != null) {
	    for (int i = 0; i < _somScreen.length; i++) {
		
		g.fillOval(_somScreen[i].x, _somScreen[i].y, 4, 4);

	    } // end of the for ...
	} // end of the if ..

	// .................................
	// [ draw map2d grid ]
	g.setColor(new Color(210,210,10));
	if (lineFrom[0] != null) {

	    for (int i = 0; i < lineFrom.length; i++) {

		if (lineFrom[i] != null) {
		
		    g.drawLine(lineFrom[i].x, lineFrom[i].y, lineTo[i].x, lineTo[i].y);

		} // end of the if ..
		
	    } // end of the for ...

	} // end of the if ...

    } // end of the method ....

} // end of the class ...
