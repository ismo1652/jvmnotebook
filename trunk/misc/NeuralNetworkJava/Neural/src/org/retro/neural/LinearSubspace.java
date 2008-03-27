//
// Berlin Brown
//
// $Id: LinearSubspace.java,v 1.1.1.1 2004/04/26 13:27:32 bigbinc Exp $
//
//
// Andreas Keilhauer

package org.retro.neural;

public class LinearSubspace extends AffinLinearSubspace {

    public LinearSubspace(Vector[] generatingSystem){
	super(null, generatingSystem); 
    }

    public String toString() {

	String tmp = "< { ";
	for(int i=0; i < this.dimension-1; i++){
	    tmp += this.generatingSystem[i].toString() + ", ";
	}
	if(dimension > 0){
	    tmp += this.generatingSystem[this.dimension-1];
	}
	return tmp+ " } >";

    }

} // end of the .....................................................
