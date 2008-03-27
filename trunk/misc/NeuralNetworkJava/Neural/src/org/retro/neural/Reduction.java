//
// Berlin Brown
//
//
// bigbinc@hotmail.com
//
// $Id: Reduction.java,v 1.1.1.1 2004/04/26 13:27:34 bigbinc Exp $
//
//...........................................

package org.retro.neural;

abstract class Reduction {

    protected FieldElement reducedValue;

    public void init(FieldElement firstValue) {
	reducedValue = firstValue;
    }

    public abstract void track(FieldElement currValue);

} // end of the function ........................................
