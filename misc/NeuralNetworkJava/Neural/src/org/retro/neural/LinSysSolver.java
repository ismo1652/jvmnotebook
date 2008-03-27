//
//
// Berlin Brown
//
// $Id: LinSysSolver.java,v 1.1.1.1 2004/04/26 13:27:32 bigbinc Exp $
//
//.....................................................................................

package org.retro.neural;

import java.util.Stack;

public class LinSysSolver {
 
    public static AffinLinearSubspace solutionSpace(Matrix a, Vector b) throws InvalidOperationException{


	if(a.getRows() != b.length()){
	    throw new InvalidOperationException("Tried to solve an equation system with a coefficient matrix"+
					       " with "+ a.getRows() +" rows and a"+
					       " vector with length "+ b.length() +". Not correct format!");
	}

	Matrix extCoeff = LinSysSolver.isSolvableHelper(a, b);

	if(extCoeff == null){
	    return null;
	}

	Stack swaps = new Stack();
	for(int row=1; row <= extCoeff.getRows(); row++){
	    if(extCoeff.getEntry(row, row).isZero()){
		int col = row;
		while(extCoeff.getEntry(row, col).isZero()){
		    col++;
		}
		swaps.push(new Integer(row));
		swaps.push(new Integer(col));
		extCoeff.swapCols(row, col);
	    }
	}

	int dimension = a.getCols();
	
	FieldElement zero = extCoeff.getEntry(1,1).zero();
	FieldElement minusOne = zero.subtract(zero.one());

	Vector[] generatingSystem = new Vector[extCoeff.getCols() - extCoeff.getRows() - 1];
	
	for(int col = extCoeff.getRows()+1; col <= extCoeff.getCols()-1; col++){
	    Vector tmp = new Vector(dimension);
	    for(int row = 1; row <= dimension; row++){
		if(row <= extCoeff.getRows()){
		    tmp.setEntry(row, extCoeff.getEntry(row, col));
		}else if(row == col){
		    tmp.setEntry(row, minusOne);
		}else{
		    tmp.setEntry(row, zero);
		} 
	    }
	    
	    generatingSystem[col - (extCoeff.getRows()+1)] = tmp;
	}

	Vector inhomogenousPart = new Vector(dimension);
	
	for(int row = 1; row <= dimension; row++){
	    if(row <= extCoeff.getRows()){
		inhomogenousPart.setEntry(row, extCoeff.getEntry(row, extCoeff.getCols()));
	    }else{
		inhomogenousPart.setEntry(row, zero);
	    }
	}

	while(!swaps.isEmpty()){
	    int index1 = ((Integer)swaps.pop()).intValue();
	    int index2 = ((Integer)swaps.pop()).intValue();
	    inhomogenousPart.swapEntries(index1, index2);
	    for(int i=0; i < generatingSystem.length; i++){
		generatingSystem[i].swapEntries(index1,index2);
	    }
	}

	return new AffinLinearSubspace(inhomogenousPart, generatingSystem);
	
    }

    public static Vector solve(Matrix a, Vector b){

	if(a.getRows() != b.length()){
	    throw new InvalidOperationException("Tried to solve an equation system with a coefficient matrix"+
					       " with "+ a.getRows() +" rows and a"+
					       " vector with length "+ b.length() +". Not correct format!");
	}

	Matrix extCoeff = LinSysSolver.isSolvableHelper(a, b);

	if(extCoeff == null){
	    return null;
	}

	Stack swaps = new Stack();
	for(int row=1; row <= extCoeff.getRows(); row++){
	    if(extCoeff.getEntry(row, row).isZero()){
		int col = row;
		while(extCoeff.getEntry(row, col).isZero()){
		    col++;
		}
		swaps.push(new Integer(row));
		swaps.push(new Integer(col));
		extCoeff.swapCols(row, col);
	    }
	}

	int dimension = a.getCols();
	
	FieldElement zero = extCoeff.getEntry(1,1).zero();
	Vector inhomogenousPart = new Vector(dimension);
	
	for(int row = 1; row <= dimension; row++){
	    if(row <= extCoeff.getRows()){
		inhomogenousPart.setEntry(row, extCoeff.getEntry(row, extCoeff.getCols()));
	    }else{
		inhomogenousPart.setEntry(row, zero);
	    }
	}

	while(!swaps.isEmpty()){
	    int index1 = ((Integer)swaps.pop()).intValue();
	    int index2 = ((Integer)swaps.pop()).intValue();
	    inhomogenousPart.swapEntries(index1, index2);
	}

	return inhomogenousPart;
	
    }

    private static Matrix isSolvableHelper(Matrix a, Vector b){
	if(a.getRows() != b.length()){
	    throw new InvalidOperationException("Tried to solve an equation system with a coefficient matrix"+
						" with "+ a.getRows() +" rows and a"+
						" vector with length "+ b.length() +". Not correct format!");
	}
	
	Matrix tmp = a.insertCol(a.getCols()+1, b);
	
	tmp = tmp.gaussjord();
	int row = tmp.getRows();
	
	while(row > 0 && tmp.isZeroRow(row)){
	    tmp = tmp.withoutRow(row);
	    row--;
	}
	
	//Check if there is any not zero entry in a.gaussjord() (tmp.gaussjord() without last column)
	for(int col=1; col < tmp.getCols(); col++){
	    if(!tmp.getEntry(row, col).isZero()){
		return tmp;
	    }
	}
	return null;
    }

    public static boolean isSolvable(Matrix a, Vector b){

	if(a.getRows() != b.length()) {
	    throw new InvalidOperationException("Tried to solve an equation system with a coefficient matrix"+
					       " with "+ a.getRows() +" rows and a"+
					       " vector with length "+ b.length() +". Not correct format!");
	}

	Matrix tmp = a.insertCol(a.getCols()+1, b);


	
	tmp = tmp.gausselim();
	int row = tmp.getRows();
	      
	while(row > 0 && tmp.isZeroRow(row)){
	    row--;
	}
	
	for(int col=1; col < tmp.getCols(); col++){
	    if(!tmp.getEntry(row, col).isZero()){
		return true;
	    }
	}
	
	return false;
	
    }

} // end of the class ................................................
