//
// Berlin Brown
//
// $Id: Map2D.java,v 1.2 2004/05/27 12:35:40 bigbinc Exp $
//
//..............................................

package org.retro.neural;

import java.awt.Point;
import java.util.Random;
import java.util.TimerTask;
import java.util.Timer;

public abstract class Map2D {


    protected static final long REPORT_MSEC = 1000;

    protected SNVector [][] _A;    // grid of reference weights
    protected int _N1, _N2;      // grid dimensions
    protected SNVector [] _PX;     // inputs for Prob. Density Function
    protected Roulette _wheel;   // roulette wheel implementing PDF
    protected int _percent_done; // for reporting


    /** 
     * Returns current reference vector weights.  Weights are returned
     * as a 2D grid of vectors.
     * @return reference vector weights
     */
    public double [][][] getWeights() {

	double [][][] w = new double [_N1][_N2][];

        for (int i=0; i<_N1; ++i) {
            for (int j=0; j<_N2; ++j) {
                w[i][j] = _A[i][j].getValues();
            }
        }

        return w;
    }


    public int [] getUnit(double [] v) {

        if (v.length != _A[0][0].length()) {
            String err = "Argument has " + v.length + " dimensions, but IGG " +
                "has " + _A[0][0].length();
            throw new IllegalArgumentException(err);
        }

        SNVector x = new SNVector(v);

	return getUnit(x);
    }

    /** 
     * Returns indices of grid points from reference vectors. Points
     * is returned as an array of 2D integer arrays.
     * @return grid points corresponding to reference vectors
     */
    public int [][] getUnits() {

	int [][] units = new int [_PX.length][];

	for (int i=0; i<_PX.length; ++i) {
	    units[i] = getUnit(_PX[i]);
	}

	return units;
    }

    /**
     * Returns the number of rows in this map.
     * @return the number of rows in this map
     */
    public int getRowDimension() {
	return _N1;
    }

    /**
     * Returns the number of columns in this map.
     * @return the number of columns in this map
     */
    public int getColumnDimension() {
	return _N2;
    }

    // constructor builds _N1x_N2 grid of weight vectors
    protected Map2D(double [][] X, int _N1, int _N2, double [] P, 
		    Random rand) {

        // bozo filters
        if (X[0].length <2) {
            String err = "Data must have at least two dimensions";
            throw new IllegalArgumentException(err);
        }
        if (X.length != P.length) {
            String err = "Number of vectors (" + X.length +
                ") mismatches number of probabilities (" + P.length + ")";
            throw new IllegalArgumentException(err);
        }

        // implements PDF, with check for sum to 1
        _wheel = new Roulette(P, rand); 

        _PX = new SNVector [X.length];
        for (int i=0; i<X.length; ++i) {
            _PX[i] = new SNVector(X[i]);
        }

        // 1. Set the initial network width and height. 
        this._N1 = _N1; 
        this._N2 = _N2;

        //    Initialize A to contain N = _N1*_N2 units Ci, with reference
        //    vectors Wci in R^n chosen randomly according to P(X).
	_A = new SNVector[_N1][_N2];
	initA();
    }

    // general weight-adapation method
    protected void learn(double e_i, double e_f, int tmax, String name) {

        // set up a task that will fire every REPORT_MSEC milliseconds
        ReportTimerTask task = new ReportTimerTask(name);
        task.launch();

	for (int t=0; t<tmax; ++t) {

            // Generate at random an input signal X according to P(X)
            SNVector x = randomSignal();

            // Determine the winner s(X) = s
            Point s = winner(x);

            // Adapt each unit r according to dwr = e(t)*hrs*(X-wr), 
            // where e(t) = e_i(e_f/e_i)^(t/tmax), with
            // tmax = _N1*_N2/lambda_f
            adapt(s, x, scale(e_i, e_f, t, tmax), t, tmax);

          // used by timer task
          _percent_done = (int)Math.ceil(100*t/tmax);
        }

	task.complete(); // else we'd run forever
    }

    // Adapt each unit r according to dwr = e(t)*hrs*(X-wr)
    protected void adapt(Point s, SNVector X, double et, int t, int tmax) {

        for (int i=0; i<_N1; ++i) {
            for (int j=0; j<_N2; ++j) {
                Point r = new Point(i, j);
                SNVector wr = vector(r);
                SNVector dwr = SNVector.subtract(X, wr);
                dwr.multiply(et);
                dwr.multiply(hrs(r, s, t, tmax));
                wr.add(dwr);
            }
        }
    }        


    // return random signal using PDF
    protected SNVector randomSignal() {

        int i = _wheel.roll();
        return _PX[i];
    }


    // Determine the winner s(X) = s
    protected Point winner(SNVector X) {

        double mindst = Double.POSITIVE_INFINITY;
        int imax = 0, jmax = 0;

        for (int i=0; i<_N1; ++i) {
            for (int j=0; j<_N2; ++j) {
                SNVector c = _A[i][j];
                double dst = X.eucDist(c);
                if (dst < mindst) {
                    mindst = dst;
                    imax = i;
                    jmax = j;
                }
            }
        }
        
        return new Point(imax, jmax);
    }


    // returns indices of grid point whose reference vector is closest
    // to a given vector
    protected int [] getUnit(SNVector x) {

        Point s = winner(x);
        int [] p = new int [2];
        p[0] = s.x; 
        p[1] = s.y;
        return p;
    }

    // return reference vector at unit
    protected SNVector vector(Point a) {
        return _A[a.x][a.y];
    }

    // compute hrs(r, s, int t, int tmax)
    private double hrs(Point r, Point s, int t, int tmax) {
        double d1 = Math.abs(r.x - s.x) + Math.abs(r.y - s.y);
        return Math.exp((-d1*d1) / (2*sigma(t, tmax)*sigma(t, tmax)));
    }

    // inner class for reporting tuning-phase progress at timed intervals
    protected class ReportTimerTask extends TimerTask {

        Timer timer;
        String name;

        public ReportTimerTask(String name) {
            this.name = name;
            this.timer = new Timer();
        }

        public void launch() {
	    _percent_done = 0;
            timer.schedule(this, 0, REPORT_MSEC);
        }

        public void run() {
	    
            // ;; name + " " + _percent_done + 
            // ;; _percent_done

        } // end of the method .

	public void complete() {

	    timer.cancel();		    

	} // end of the method ...
    }

    // initializes A to contain N = _N1*_N2 units Ci, with reference
    // vectors Wci in R^n chosen randomly according to P(X)
    protected abstract void initA();

    // returns width parameter
    protected abstract double sigma(int t, int tmax);

    // build uniform probability density function
    protected static double [] updf(double [][] X) {
        int m = X.length;
        double [] P = new double [m];
        for (int i = 0; i<m; ++i) {
            P[i] = 1. / m;
        }
        return P;
    }

    // general formula for scale from initial to final quantities over time
    protected static double scale(double i, double f, int t, int tmax) {
	return i * Math.pow((f/i), t/(double)tmax);
    }

} // end of the class ......................................
