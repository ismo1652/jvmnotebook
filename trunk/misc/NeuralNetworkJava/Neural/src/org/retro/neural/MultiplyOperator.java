//
// Berlin Brown
//
// $Id: MultiplyOperator.java,v 1.1.1.1 2004/04/26 13:27:33 bigbinc Exp $
//
//........................................................

package org.retro.neural;


class MultiplyOperator implements DyadicOperator {

    public FieldElement apply(FieldElement x, FieldElement y) {

	return x.multiply(y);
	
    }

} /// end of the class ..................................
