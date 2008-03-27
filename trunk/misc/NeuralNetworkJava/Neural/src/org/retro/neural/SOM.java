//
// Berlin Brown
//
// $Id: SOM.java,v 1.2 2004/06/17 10:49:02 bigbinc Exp $
//
//
// author      Simon Levy
//

package org.retro.neural;

import java.util.Random;


public class SOM extends Map2D {

    private double _sigma_i, _sigma_f;

    public SOM(double [][] X, int N1, int N2, double [] P, Random rand) 
        throws IllegalArgumentException {
	super(X, N1, N2, P, rand);
    }


    public SOM(double [][] X, int N1, int N2, double [] P) 
	throws IllegalArgumentException {
        this(X, N1, N2, P, new Random());
    }



    public SOM(double [][] X, int N1, int N2, double [] P , long seed)  
        throws IllegalArgumentException {
        this(X, N1, N2, P, new Random(seed));
    }



    public SOM(double [][] X, int N1, int N2) {
        this(X, N1, N2, new Random());
    }


    /** 
     * Builds SOM with random initial weights and uniform probability
     * density function.
     * @param X data to learn
     * @param N1 number of rows
     * @param N2 number of columns
     * @param seed seed for random-number generator
     */
    public SOM(double [][] X, int N1, int N2, long seed) {
        this(X, N1, N2, new Random(seed));
    }

    /** 
     * Builds SOM with random initial weights and uniform probability
     * density function.
     * @param X data to learn
     * @param N1 number of rows
     * @param N2 number of columns
     * @param rand random-number generator
     */
    public SOM(double [][] X, int N1, int N2, Random rand) {
        this(X, N1, N2, updf(X), rand);
    }


    /** 
     * Runs learning iterations. Learning rate e(t) = ei(ef/ei)^{t/tmax}.
     * @param e_i initial learning rate
     * @param e_f final learning rate
     * @param sigma_i initial width parameter
     * @param sigma_f final width parameter
     * @param tmax total number of time-steps to run
     */
    public void learn(double ei, double ef, double sigma_i, double sigma_f,
		      int tmax) {

	_sigma_i = sigma_i;
	_sigma_f = sigma_f;

	super.learn(ei, ef, tmax, "Learning");
    }

    // Initialize A to contain N = _N1*_N2 units Ci, with reference
    // vectors Wci in R^n chosen randomly according to P(X).
    protected void initA() {
	for (int i=0; i<_N1; ++i) {
	    for (int j=0; j<_N2; ++j) {
		_A[i][j] = randomSignal();
	    }
	}
    }

    // returns width parameter
    protected double sigma(int t, int tmax) {
	return scale(_sigma_i, _sigma_f, t, tmax);
    }

} // end of the class --------------------

