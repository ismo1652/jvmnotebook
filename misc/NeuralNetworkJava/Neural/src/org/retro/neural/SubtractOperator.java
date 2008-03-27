//
// Berlin Brown
//
// $Id: SubtractOperator.java,v 1.1.1.1 2004/04/26 13:27:35 bigbinc Exp $
//
//...................................

package org.retro.neural;


class SubtractOperator implements DyadicOperator {

    public FieldElement apply(FieldElement x, FieldElement y) {
	return x.subtract(y);
    } // end of the method 

} // end of the class ...........................
