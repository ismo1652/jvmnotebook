//
// Beriln Brown
//
// $Id: BPInitException.java,v 1.1.1.1 2004/04/26 13:27:27 bigbinc Exp $
//
//

package org.retro.neural;

class BPInitException extends RuntimeException {

    public BPInitException() {
	super("Network weights unitialized");
    }

} // end of the class ................
