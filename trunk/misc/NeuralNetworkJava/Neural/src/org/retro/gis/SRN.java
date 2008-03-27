//
// Berlin Brown
//
// $Id: SRN.java,v 1.3 2004/05/09 03:24:04 bigbinc Exp $
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

public class SRN {

    private BPLayer i, h, c, o;

    public SRN (int ninp, int nhid) {


	// [ 15 inputs ](cols)

        int nout = ninp;

        i = new BPLayer(ninp);
        h = new BPLayer(nhid);
        o = new BPLayer(nout);
        c = new BPLayer(nhid);

        try {
            c.delay(h);
        }
        catch (Exception e) {
            System.err.println(e);
            System.exit(1);
        }

        h.connect(c);

        h.connect(i);
        o.connect(h);

    } // end of the method ....

    public void randomize (long seed) {
	randomize(new Random(seed));
    } // end of the method ...


    public void randomize () {
	randomize(new Random());
    }


    public void randomize (Random rand) {
        h.randomize(rand);
        o.randomize(rand);
    }


    public void train (double [][] ipats, int nep, double eta, int report) 
        throws IllegalArgumentException {

        // set up to predict next pattern from current
        double [][] tpats = delay(ipats);

        // train with no momentum (momentum would screw up on-line learning)
        try {

            i.attach(ipats);
            o.attach(tpats);
            o.online(nep, eta, 0.0, report);
        }
        catch (IllegalArgumentException e) {
            throw e;
        } // end of the try - catch ...

    } // end of the method ....


    public double [][] test (double [][] ipats) 

	throws IllegalArgumentException {

        // set up to predict next pattern from current
        double [][] tpats = delay(ipats);

        try {
            i.attach(ipats);
            o.attach(tpats);
            return o.getSquaredErrors();
        }
        catch (IllegalArgumentException e) {
            throw e;
        }
    } // end of the method .....


    public double [] getHidden (double [] ipat) 

	throws IllegalArgumentException {

        return h.activate(i, ipat);
    } // end of the methdo ...

    public static double [][] delay (double [][] a) {

        int m = a.length;
        int n = a[0].length;

        double [][] d = new double [m][n];

        for (int i=1; i<m; ++i) {

            for (int j=0; j<n; ++j) {

                d[i-1][j] = a[i][j];

            } // end of the for ...

        } // end of the for ...

        return d;
    } // end of the method .....

} // end of the class .....
