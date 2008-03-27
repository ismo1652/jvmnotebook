//
// Berlin Brown
//
// $Id: AffinLinearSubspace.java,v 1.1.1.1 2004/04/26 13:27:27 bigbinc Exp $
//
// Andreas Keilhauer
//
//........................................

package org.retro.neural;


public class AffinLinearSubspace{

    protected Vector inhomogenousPart;
    protected Vector[] generatingSystem;
    protected int dimension;

    
    public AffinLinearSubspace(Vector inhomogenousPart, Vector[] generatingSystem){

	Matrix dimensionChecker = (new Matrix(generatingSystem)).gaussjord();
	
	this.dimension = dimensionChecker.rank();
	this.generatingSystem = new Vector[this.dimension];

	int index = 0;
	int index2 = 0;
	int row = 1;
	int col = 1;
	while(index < this.generatingSystem.length){
	    if(!dimensionChecker.getEntry(row, col).isZero()){
		this.generatingSystem[index2++] = generatingSystem[index];
		row++;
	    }
	    col++;
	    index++;
	}

	if(inhomogenousPart == null){
	    Vector tmp = generatingSystem[0];
	    Vector zeroVector = new Vector(tmp.length());
	    FieldElement zero = tmp.getEntry(1).zero();
	    for(int i=1; i <= zeroVector.length(); i++){
		zeroVector.setEntry(i, zero);
	    }
	    this.inhomogenousPart = zeroVector;
	}else{
	    this.inhomogenousPart = inhomogenousPart;
	}
    }
    
    /**
     * Gets the dimension of the affin linear subspace.
     *
     * @return dimension (number of independent Vectors of the generating system).
     */

    public int getDimension(){
	return dimension;
    }

    /**
     * Gets the inhomogenous part of this affin linear vector space.
     * 
     * @return inhomogenous part
     */

    public Vector getInhomogenousPart(){
	return inhomogenousPart;
    }

    /**
     * Gets the generating system of this affin linear vector space.
     *
     * @return generating system
     */

    public Vector[] getGeneratingSystem(){
	return generatingSystem;
    }

    /**
     * Returns a String representation of this affin linear subspace
     *
     * @return String representation
     */

    public String toString(){
	String tmp = this.inhomogenousPart + " + < { ";
	for(int i=0; i < this.dimension-1; i++){
	    tmp += this.generatingSystem[i].toString() + ", ";
	}
	try{
	    tmp += this.generatingSystem[this.dimension-1];
	}catch(ArrayIndexOutOfBoundsException a){
	}
	tmp += " } >";
	return tmp;
    }
} // end of the class ................................
