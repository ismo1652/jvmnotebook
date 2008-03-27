//
// Berlin Brown
//
// $Id: DivideOperator.java,v 1.1.1.1 2004/04/26 13:27:31 bigbinc Exp $
//
//

package org.retro.neural;

class DivideOperator implements DyadicOperator {

    public FieldElement apply(FieldElement x, FieldElement y) {
	return x.divide(y);
    }

} // end of the class ............................
