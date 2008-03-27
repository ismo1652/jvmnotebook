//
// Berlin Brown
//
// $Id: NeuralSOM.java,v 1.4 2004/05/11 15:12:17 bigbinc Exp $
//
// 
package org.retro.gis;

import java.util.Random;

import org.retro.neural.*;
import java.util.Random;

import java.util.*;
import javax.swing.*;
import java.awt.event.*;
import java.awt.*;
import java.awt.geom.Point2D;

import java.io.*;

public class NeuralSOM extends POS {

    // SOM params
    private final static double E_I       = 0.5;
    private final static double E_F       = 0.005;

    private final static double SIGMA_I   = 3.0;
    private final static double SIGMA_F   = 0.1;
    private final static int TMAX         = 10000;
    private final static int N            = 10;

    public static void main(String [] args) {

	// require input file name argument
	if (args.length < 1) {
	    System.err.println("Usage: java SOMPOS <textfile>");
			       
	    System.exit(1);
	}

	new NeuralSOM(args[0]);
    } // end of the method .........

    private NeuralSOM(String fname) {

	super(fname);

    } // end of the method ............
    
    protected Map2D getMap(double [][] hidden) {

        SOM som = new SOM(hidden, N, N);
        som.learn(E_I, E_F, SIGMA_I, SIGMA_F, TMAX);
	
	return som;
	
    } // end of the method ....
    
} // end of the class ......


