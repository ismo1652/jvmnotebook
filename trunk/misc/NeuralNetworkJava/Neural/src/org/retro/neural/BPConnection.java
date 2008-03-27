//
// Berlin Brown
//
// $Id: BPConnection.java,v 1.1.1.1 2004/04/26 13:27:27 bigbinc Exp $
//
//

package org.retro.neural;

interface BPConnection {

    // reset copy of weights for momentum
    void mureset();

    // ranodmize weights
    void randomize(java.util.Random r);

    // reset weight changes
    void dwreset();

    // accumulate weight changes
    void dwadd(SNVector d);
	
    // accumulate weight changes for Back-Prop Thru Time
    void bptt_dwadd(SNVector d);

    // adds average over current pattern to total over all patterns for BPTT
    void bptt_dwavg(int patlen);

    // resets pattern weights for back-prop thru time
    void bptt_dwreset();

    // multiply activations by weights
    SNVector forward();

    // make copy of weights for momentum
    void mucopy();

    // check whether there's a connection to one layer from another
    boolean connectedFrom(BPLayer to, BPLayer from);

    // check whether there's a connection to one layer from two others
    boolean connectedFrom(BPLayer to, BPLayer from1, BPLayer from2);

    // set weight changes
    void dwset(SNVector d);

    // compute mean (over patterns) of accumulated weigh changes
    void dwavg(int npat);

    // recursively activate layer-from using pattern
    void activate(int patno);

    // recursively activate layer-from using clamped input
    void activate(BPLayer inp, SNVector inpat);

    // recursively back-propagate error on layer-to using pattern
    void backprop(int patno);

    // get error on non-output layer
    SNVector getError(BPLayer f);

    // add momentum term to weights
    void muAdd(double mu);

    // add learning term to weights
    void etaAdd(double eta, int npat);

    // returns true if weights are empty (null), else false
    boolean emptyWeights();

} // end of the interface ..........................
