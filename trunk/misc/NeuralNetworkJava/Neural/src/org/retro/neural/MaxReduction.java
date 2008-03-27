//
// Berlin Brown
//
// $Id: MaxReduction.java,v 1.1.1.1 2004/04/26 13:27:33 bigbinc Exp $
//
//

package org.retro.neural;

class MaxReduction extends Reduction {

    public void init(FieldElement firstValue) {
	reducedValue = firstValue.zero();
    }

    public void track(FieldElement currValue) {
	if (currValue.gt(reducedValue)) {
	    reducedValue = currValue;
	}
    }
} // end of the class ..................................
