//
// Berlin Brown
//
// $Id: AddOperator.java,v 1.1.1.1 2004/04/26 13:27:27 bigbinc Exp $
//
//

package org.retro.neural;

class AddOperator implements DyadicOperator {

    public FieldElement apply(FieldElement x, FieldElement y) {
	return x.add(y);
    }

} // end of the class ..................................
