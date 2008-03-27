//
// Berlin Brown
//
// $Id: SumReduction.java,v 1.1.1.1 2004/04/26 13:27:35 bigbinc Exp $
//
//

package org.retro.neural;

class SumReduction extends Reduction {


    public void track(FieldElement currValue) {
	reducedValue = reducedValue.add(currValue);
    }


} // end of the class ..................................
