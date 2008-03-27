//
// Berlin Brown
//
// $Id: NeuralAND.java,v 1.1 2004/05/07 18:54:52 bigbinc Exp $
//
//

//        java -classpath $(CLASSPATH) Xor 5000 .1 .9 0
//        java -classpath $(CLASSPATH) Xor2 5000 .1 .9 0
//        java -classpath $(CLASSPATH) Autoasso 3 10000 .1 .9 0
//
// swing based on MOJ
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

//
// ;;;
// 
public class NeuralAND {

    public static void main(String [] args) {

	Point2D.Double _pts [] = new Point2D.Double[5000];
	Point _ptsImg [] = new Point[5000];

	int i = 0;
	int j = 0;

        if (args.length < 3) {
            System.err.println("Usage: java NeuralAND <epochs> <eta> <mu> " + 
                               "[seed]\n");
            System.exit(1);
        } // end of the if ......

        BPLayer inp = new BPLayer(2);
        BPLayer hid1 = new BPLayer(3);
        BPLayer hid2 = new BPLayer(3);
        BPLayer out = new BPLayer(1);

        hid1.connect(inp);
        out.connect(hid2);
        hid2.connect(hid1);

	double [][] z = {
	    { 0.0,0.0 },
	    { 0.0,0.0 }
	};


        double [][] x = {
	    {  0, 0  }, 
	    {  0, 1  }, 
	    {  1, 0  }, 
	    {  1, 1  }
	};

        double [][] y = {
	    {  0  },  
	    {  0  },   
	    {  0  },   
	    {  1  }
	};

        Random r =  new Random(1020);
	
        hid1.randomize(r);
        hid2.randomize(r);
        out.randomize(r);

        int nep = Integer.parseInt(args[0]);
        double eta = Double.parseDouble(args[1]);
        double mu = Double.parseDouble(args[2]);

        inp.attach(x);
        out.attach(y);
        out.batch(nep, eta, mu);

        double [][] yy = out.test();

        System.out.println();
        for (i=0; i<yy.length; ++i) {

            for (j=0; j<yy[i].length; ++j) {

                System.out.print(yy[i][j] + " ");
 
            } // end of the for ....

            System.out.println();
        } // end of the for ....


	System.out.println("-------------------------------------");
	inp.attach(z);
	yy = out.test();
	
        System.out.println();
        for (i=0; i < yy.length; ++i) {
	    
            for (j=0; j < yy[i].length; ++j) {
                System.out.print(yy[i][j] + " " + i + " " + j);
            } // end of the for ....

            System.out.println();
        } // end of the for ....

	for (i = 0; i < _pts.length; i++) {
	    
	    z[0][0] = 0;
	    z[0][1] = 0;
	    
	    // ;;; 

	    z[1][0] = Math.random();
	    z[1][1] = Math.random();
	    	    
	    inp.attach(z);
	    yy = out.test();

	    // [ check for greater than 0.9 ]
	    if (yy[1][0] > 0.62) {
		
		double screenSwap = 1.0 - z[1][1];

		_pts[i] = new Point2D.Double(z[1][0],screenSwap);
		
		int __x = (int)(_pts[i].x * 800);
		int __y = (int)(_pts[i].y * 600);

		_ptsImg[i] = new Point(__x, __y);
		
	    } // end of the if ...
	    

	} // end of the for

	// ;;;;; -------------------------------------------

	System.out.println("Launching Frame");

	FrameNeural _frame = new FrameNeural();
	_frame.setPoints(_ptsImg);
	_frame.addWindowListener(new WindowAdapter() {

		public void windowClosing(WindowEvent e) {

		    System.out.println("Exiting...");
		    System.exit(0);

		}  // end of the funct
		
	    });
	_frame.setVisible(true);
	
    } // end of the method ... [ main ]



} // end of the class ..................
