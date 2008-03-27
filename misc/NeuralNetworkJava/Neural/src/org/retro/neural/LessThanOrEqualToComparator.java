//
// Berlin Brown
//
// bigbinc@hotmail.com
//
// $Id: LessThanOrEqualToComparator.java,v 1.1.1.1 2004/04/26 13:27:31 bigbinc Exp $
//
//

package org.retro.neural;


class LessThanOrEqualToComparator extends FEComparator {

    protected boolean compare(FieldElement a, FieldElement b) {
	return a.le(b);
    }
} // end of the class .............................
