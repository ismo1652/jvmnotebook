//
// Berlin Brown
//
// $Id: EqualToComparator.java,v 1.1.1.1 2004/04/26 13:27:31 bigbinc Exp $
//
//

package org.retro.neural;


class EqualToComparator extends FEComparator {

    protected boolean compare(FieldElement a, FieldElement b) {
	return a.equals(b);
    }
} // end of the class .................................
