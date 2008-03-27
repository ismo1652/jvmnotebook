//
// Berlin Brown
//
// $Id: AndOperator.java,v 1.1.1.1 2004/04/26 13:27:27 bigbinc Exp $
//

package org.retro.neural;


class AndOperator implements DyadicOperator {

    public FieldElement apply(FieldElement x, FieldElement y) {
	return (x.isZero() || y.isZero()) ? x.zero() : x.one();
    }
} // end of the class .........................
