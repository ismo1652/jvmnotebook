//
// Berlin Brown
//
// $Id: Roulette.java,v 1.2 2004/06/17 10:57:18 bigbinc Exp $
//
//  author      Simon Levy
//

package org.retro.neural;

import java.util.Arrays;
import java.util.Random;


class Roulette {

    // close enough to 1 for probability sum
    private static final double EPSILON = 1e-6;

    // random-number generator
    private Random m_rand;

    // biased roulette wheel
    private int [] m_wheel ;

    /**
     * Creates a roulette wheel with arbitrary initial conditions.
     *
     * @param probs probabilities (must sum to 1)
     *
     */
    public Roulette(double [] probs) throws IllegalArgumentException {

	this(probs, new Random());
    }

    /**
     * Creates a roulette wheel with seed for random-number generator,
     * to support reproducible results.
     *
     * @param probs probabilities (must sum to 1)
     * @param seed seed for random-number generator
     *
     */
    public Roulette(double [] probs, long seed)  
	throws IllegalArgumentException {

	this(probs, new Random(seed));
    }

    /**
     * Creates a roulette wheel with specified random-number generator,
     * to support reproducible results.
     *
     * @param probs probabilities (must sum to 1)
     * @param rand random-number generator
     *
     */
    public Roulette(double [] probs, Random rand)  
	throws IllegalArgumentException {

	// this makes things a little easier
	SNVector p = new SNVector(probs);

	// make sure probabilities sum to one
	if (Math.abs(1-p.sum()) > EPSILON) {
	    throw new IllegalArgumentException("Probabilities must sum to 1");
	}

	// wheel size is inverse of smallest encodable probability
	m_wheel = new int [(int)(1/p.min())+1];

	// fill the wheel array with integers corresponding to each position, 
	// represented proportionally by probability
	int beg = 0;
	for (int i=0; i<probs.length; ++i) {
	    int end = beg + (int)(probs[i] * m_wheel.length);
	    Arrays.fill(m_wheel, beg, end, i);
	    beg = end;
	}

	// hold onto random-number generator
	m_rand = rand;

    }

    /**
     * "Rolls the wheel" to get an integer in [0,N), where N is the number
     * of fitness values specified in the constructor.
     *
     * @return an integer in [0,N)
     */
    public int roll() {

	// generate a random index into wheel
	int index = m_rand.nextInt(m_wheel.length);

	// pick the number at that index in the wheel
	return m_wheel[index];
    }

} // end of the class ................................
