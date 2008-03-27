//
// Berlin Brown
//
// bigbinc@hotmail.com
//
// $Id: NotOperator.java,v 1.1.1.1 2004/04/26 13:27:33 bigbinc Exp $
//
//......................................................

package org.retro.neural;

class NotOperator implements MonadicOperator {

    public FieldElement apply(FieldElement x) {
	return x.isZero() ? x.one() : x.zero();
    }

} // end of the function .............................
