//
// Berlin Brown
//
// $Id: NeuralWords.java,v 1.1 2004/05/08 18:54:02 bigbinc Exp $
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

import org.apache.log4j.Logger;
import org.apache.log4j.BasicConfigurator;
import org.apache.log4j.PropertyConfigurator;

//
// ;;;
// 
public class NeuralWords {

    private static Logger logger = Logger.getLogger(NeuralWords.class);
    private static final String defaultLoggerFile = "config/LOGGER_CONFIG";


    public static boolean getXORTwo(boolean _a, boolean _b) {
      
	return (_a && (!_b)) || ((!_a) && _b);

    } // end of the method ....

    public static boolean getXORThree(char a, char b, char c) {
	
	boolean _a = false;
	boolean _b = false;
	boolean _c = false;

	_a = (a == '1')  ? true : false;
	_b = (b == '1')  ? true : false;
	_c = (c == '1')  ? true : false;

	boolean xora = false;

	xora = getXORTwo(_a, _b);
	return getXORTwo(xora, _c);

    } // end of the of the method ...

    // [ too lazy to do recursion ]
    public static boolean getXORFour(char a, char b, char c, char d) {

	boolean _a = false;
	boolean _b = false;
	boolean _c = false;
	boolean _d = false;
	
	boolean xora = false;
	boolean xorc = false;
	

	_a = (a == '1')  ? true : false;
	_b = (b == '1')  ? true : false;
	_c = (c == '1')  ? true : false;
	_d = (d == '1')  ? true : false;
	      
	xora = getXORTwo(_a, _b);
	xorc = getXORTwo(_c, _d);

	return getXORTwo(xora, xorc);

    } // end of method ....

    public static boolean getBinaryFlag(char [] _a) {
		
	int ctr = 0;

	for (int i = 0; i < _a.length; i++) {

	    if (_a[i] == '1') ctr++;

	} // end of the for ....

	if (ctr == 1)
	    return true;
	else
	    return false;

    } // end of the method ....

    public static void main(String [] args) {

	Point2D.Double _pts [] = new Point2D.Double[5000];
	Point _ptsImg [] = new Point[5000];

	int i = 0;
	int j = 0;

        if (args.length < 3) {
            System.err.println("Usage: java NeuralWords <epochs> <eta> <mu> " + 
                               "[seed]\n");
            System.exit(1);
        } // end of the if ......

	PropertyConfigurator.configure(defaultLoggerFile);
	logger.info("Running bot module");

	
	// [ where XOR = (not(a) and B)
	// [ where XOR = (A AND NOT(B))


	//---------------------------------------------------------------

	// 1 ;; Greeting
	// 2 ;; Request
	// 3 ;; General Statement
	// 4 ;; Gibberish

	//
	// 8 - XOR values [ insane ] 8 dimensions
	// [ 4 - 5 nodes per dimension? ]
	// [ TruthTable: 255 values     ]
	//

	int maxInputValues = Integer.parseInt("1111", 2);

	System.out.println("MaxVal: " + maxInputValues);

	int _z = 0;
	for (_z = 0; _z <= maxInputValues; _z++) {
	    
	    if (logger.isDebugEnabled()) {
		
		String _bin = Integer.toBinaryString(_z);
		String _fin = "";
		int _missing = 4 - _bin.length();
		
		if (_missing > 0) {
		    
		    String _zeros = "";
		    for (int _k = 0; _k < _missing; _k++) {
			_zeros += "0";
		    } // end of the for
		    
		    _fin += _zeros + Integer.toBinaryString(_z);

		} else {

		    _fin = Integer.toBinaryString(_z);

		} // end of the if - else		

		
		char [] _vals = _fin.toCharArray();
		boolean _xora = false;
		boolean _xorb = false;
		boolean _xres = false;
		char XORChar = '0';		
		
		_xres = getBinaryFlag(_vals);
				
		XORChar = _xres ? '1' : '0';
		
		//logger.debug(" | " + _fin + "| " + _z + "[ " + XORChar + " ]");
		System.out.print("\t\t{  ");
		for (int _p = 0; _p < _vals.length; _p++) {
		    
		    if (_p != (_vals.length-1))
			System.out.print(_vals[_p] + ", ");
		    else
			System.out.print(_vals[_p]);

		} // end of the for ......
		System.out.println("  },");

	    } // end of the if  .....	    

	} // end of the for  ......

	for (_z = 0; _z <= maxInputValues; _z++) {
	    
	    String _bin = Integer.toBinaryString(_z);
	    String _fin = "";
	    int _missing = 8 - _bin.length();
	    
	    if (_missing > 0) {
		
		String _zeros = "";
		for (int _k = 0; _k < _missing; _k++) {
		    _zeros += "0";
		    } // end of the for
		
		_fin += _zeros + Integer.toBinaryString(_z);
		
	    } else {
		
		_fin = Integer.toBinaryString(_z);
		
	    } // end of the if - else		
	    
		char [] _vals = _fin.toCharArray();
		boolean _xres = false;
		char XORChar = '0';		
		
		_xres = getBinaryFlag(_vals);
		
		XORChar = _xres ? '1' : '0';
		
		System.out.print("\t\t{  ");		
		System.out.print("" + XORChar);
		System.out.println("  }," +  " // ;; " + _z);

	} /// end of the for 
	
	
	//---------------------------------------------------------------

	// [ 8 inputs ]
        BPLayer inp = new BPLayer(4);
        BPLayer hid1 = new BPLayer(8);
        BPLayer hid2 = new BPLayer(4);
	BPLayer hid3 = new BPLayer(5);
        BPLayer out = new BPLayer(1);

        hid1.connect(inp);     // [ in     --> hid1
        hid2.connect(hid1);    // [ hid1   --> hid2
	hid3.connect(hid2);    // [ hid2   --> hid3
	out.connect(hid3);     // [ hid3   --> out

	//  [ Test input post processing ]            
	double [][] z = {
	    { 0, 0, 0, 0   },
	    { 0, 0, 0, 0   }
	};


	double [][] x = {


	    {  0, 0, 0, 0  },
                {  0, 0, 0, 1  },
                {  0, 0, 1, 0  },
                {  0, 0, 1, 1  },
                {  0, 1, 0, 0  },
                {  0, 1, 0, 1  },
                {  0, 1, 1, 0  },
                {  0, 1, 1, 1  },
                {  1, 0, 0, 0  },
                {  1, 0, 0, 1  },
                {  1, 0, 1, 0  },
                {  1, 0, 1, 1  },
                {  1, 1, 0, 0  },
                {  1, 1, 0, 1  },
                {  1, 1, 1, 0  },
                {  1, 1, 1, 1  },
	};


	double [][] y = {
	    

	    {  0  }, // ;; 0
                {  1  }, // ;; 1
                {  1  }, // ;; 2
                {  0  }, // ;; 3
                {  1  }, // ;; 4
                {  0  }, // ;; 5
                {  0  }, // ;; 6
                {  0  }, // ;; 7
                {  1  }, // ;; 8
                {  0  }, // ;; 9
                {  0  }, // ;; 10
                {  0  }, // ;; 11
                {  0  }, // ;; 12
                {  0  }, // ;; 13
                {  0  }, // ;; 14
                {  0  }, // ;; 15
	};


        Random r =  new Random(1020);
	
        hid1.randomize(r);
        hid2.randomize(r);
	hid3.randomize(r);
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
	    if (yy[1][0] > 0.94) {
		
		System.out.println(z[1][0] + " " + z[1][1]);

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
