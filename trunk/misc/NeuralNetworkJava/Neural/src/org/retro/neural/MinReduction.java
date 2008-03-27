//
// Berlin Brown
//
// bigbinc@hotmail.com
//
// $Id: MinReduction.java,v 1.1.1.1 2004/04/26 13:27:33 bigbinc Exp $
//
//.........................................

package org.retro.neural;

class MinReduction extends Reduction {

    public void track(FieldElement currValue) {
	if (currValue.lt(reducedValue)) {
	    reducedValue = currValue;
	}
    }

} // end of the class
