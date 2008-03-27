//
// Berlin Brown
//
// $Id: BPDelay.java,v 1.1.1.1 2004/04/26 13:27:27 bigbinc Exp $
//

package org.retro.neural;

class BPDelay {
    public double w;	// weight (strength)
    public BPLayer f;	// layer from
    BPDelay(BPLayer from, double weight) {
        f = from;
	w = weight;
    }
} // end of the class .....................
