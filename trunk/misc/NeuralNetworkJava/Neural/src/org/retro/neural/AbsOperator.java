//
// Berlin Brown
//
// $Id: AbsOperator.java,v 1.1.1.1 2004/04/26 13:27:27 bigbinc Exp $
//
//

package org.retro.neural;


class AbsOperator implements MonadicOperator {

    public FieldElement apply(FieldElement x) {
	return x.lt(x.zero()) ? x.zero().subtract(x) : x;
    }

} // end of the class ..........................
