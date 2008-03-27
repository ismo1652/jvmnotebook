//
// Berlin Brown
//
// $Id: OrOperator.java,v 1.1.1.1 2004/04/26 13:27:33 bigbinc Exp $
//
// 

package org.retro.neural;


class OrOperator implements DyadicOperator {

    public FieldElement apply(FieldElement x, FieldElement y) {
	return (x.isZero() && y.isZero()) ? x.zero() : x.one();
    }

} // end of the class .......................
