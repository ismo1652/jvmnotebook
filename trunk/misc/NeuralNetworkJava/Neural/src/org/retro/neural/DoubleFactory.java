//
// Berlin Brown
//
// $Id: DoubleFactory.java,v 1.1.1.1 2004/04/26 13:27:31 bigbinc Exp $
//
//
// author Simon D. Levy
//

package org.retro.neural;

import java.util.Random;


public class DoubleFactory extends LinAlgFactory {

    public static Matrix buildMatrix(double [][] theValues) 
	throws InvalidOperationException {
	
	return new Matrix(wrap(theValues));
    }
    
    public static Vector buildVector(double[] theValues) 
	throws InvalidOperationException {
	return new Vector(wrap(theValues));
    }

    public Matrix gaussianNoise(int numberOfRows, int numberOfCols, 
				Random random) {

	Matrix a = new Matrix(numberOfRows, numberOfCols);
	for (int i=1; i<=numberOfRows; ++i) {
	    for (int j=1; j<=numberOfCols; ++j) {
		a.setEntry(i, j, new DoubleWrapper(random.nextGaussian()));
	    }
	}
	return a;
    }

    public Matrix gaussianNoise(int numberOfRows, int numberOfCols, 
				long seed) {
	return gaussianNoise(numberOfRows, numberOfCols, new Random(seed));
    }

    public Matrix gaussianNoise(int numberOfRows, int numberOfCols) {
	return gaussianNoise(numberOfRows, numberOfCols, new Random());
    }


    public Vector gaussianNoise(int length, Random random) {

	Vector v = new Vector(length);
	for (int i=1; i<=length; ++i) {
	    v.setEntry(i, new DoubleWrapper(random.nextGaussian()));
	}
	return v;
    }

    /**
     * Returns a Vector of normally distributed random
     * values. Values are taken from a Gaussian distribution with zero
     * mean and standard deviation one.
     * @param numberOfRows
     * @param length
     * @param seed seed for random-number generator
     * @return Vector of normally distributed random values
     */
    public Vector gaussianNoise(int length, long seed) {
	return gaussianNoise(length, new Random(seed));
    }

    /**
     * Returns a Vector of normally distributed random values.  Values are
     * taken from a Gaussian distribution with zero mean and standard 
     * deviation one.
     * @param numberOfRows
     * @param length
     * @return Vector of normally distributed random values
     */
    public Vector gaussianNoise(int length) {
	return gaussianNoise(length, new Random());
    }

    /**
     * Returns an array of double-precision floating-point values
     * contained in a Matrix.
     * @param theMatrix
     * @return 2D array of double
     * @throws InvalidOperationException if theMatrix does not contain doubles
     */
    public static double [][] doubleValues(Matrix theMatrix) 
	throws InvalidOperationException {
	check_double(theMatrix);
	int m = theMatrix.getRows(), n = theMatrix.getCols();
	double [][] result = new double [m][n];
	for (int i=1; i<=m; ++i) {
	    for (int j=1; j<=n; ++j) {
		result[i-1][j-1] = doubleValue(theMatrix, i, j);
	    }
	}
	return result;
    }

    /**
     * Returns an array of double-precision floating-point values
     * contained in a Vector.
     * @param theVector
     * @return 1D array of double
     * @throws InvalidOperationException if theVector does not contain doubles
     */
    public static double [] doubleValues(Vector theVector) 
	throws InvalidOperationException {
	check_double(theVector);
	int n = theVector.length();
	double [] result = new double [n];
	for (int i=1; i<=n; ++i) {
	    result[i-1] = doubleValue(theVector, i);
	}
	return result;
    }

    /**
     * Returns the Euclidean distance between two Vectors.
     * @param x one Vector
     * @param y the other Vector
     * @return distance between x and y
     * @throws InvalidOperationException if either Vector does not
     * contain doubles
     */
    public static double eucDist(Vector x, Vector y)
	throws InvalidOperationException {
	check_double(x);
	check_double(y);
	Vector d = x.subtract(y);
	return L2Norm(d);
    }

    /**
     * Returns the L2 norm of a vector
     * @param x the Vector
     * @return L2 norm of X
     * @throws InvalidOperationException if x does not contain doubles
     */
    public static double L2Norm(Vector x) 
	throws InvalidOperationException {
	check_double(x);
	Vector x2 = x.arrayMultiply(x);
	return Math.sqrt(unwrap(x2.sum()));
    }

    /**
     * Returns the double-precision floating-point value in a FieldElement.
     * @param d the element
     * @return double contained in d
     * @throws InvalidOperationException if d does not contain a double
     */
    public static double doubleValue(FieldElement d) 
	throws InvalidOperationException {
	check_double(d);
	return unwrap(d);
    }

    /**
     * Returns the Ith double-precision floating-point value in a Vector.
     * First index is 1.
     * @param x the Vector
     * @param i the index
     * @return double contained in at v(i)
     * @throws InvalidOperationException if v does not contain double
     * @throws InvalidOperationException if the index is out of bounds
     */
    public static double doubleValue(Vector x, int i) 
	throws InvalidOperationException {
	check_double(x);
	return unwrap(x.getEntry(i));
    }

    /**
     * Returns the I,Jth double-precision floating-point value in a Matrix.
     * First index is 1,1.
     * @param a the Matrix
     * @param i row index
     * @param j column index
     * @return double contained in at a(i,j)
     * @throws InvalidOperationException if v does not contain double
     * @throws InvalidOperationException if either index is out of bounds
     */
    public static double doubleValue(Matrix a, int i, int j) 
	throws InvalidOperationException {
	check_double(a);
	return unwrap(a.getEntry(i, j));
    }

    /**
     * Returns a FieldElement corresponding to unity (1), the neutral
     * element of multiplication.
     * @return one
     */
    public FieldElement unityValue() {
	return new DoubleWrapper(1);
    }

    /**
     * Returns a FieldElement corresponding to zero (0), the neutral
     * element of addition.
     * @return zero
     */
    public FieldElement zeroValue() {
	return new DoubleWrapper(0);
    }

    /**
     * Returns a random value.  The value is a double-precision floating-point
     * number between 0.0 and 1.0.
     * @return random value
     */
    public FieldElement randomValue(Random random) {
	return new DoubleWrapper(random.nextDouble());
    }

    // I am the Queen / Of the wrapping scene
    private static DoubleWrapper [] wrap(double [] x) {
	DoubleWrapper [] d = new DoubleWrapper [x.length];
	for (int i=0; i<x.length; ++i) {
	    d[i] = new DoubleWrapper(x[i]);
	}
	return d;
    }

    private static DoubleWrapper [][] wrap(double [][] x) {
	int m = x.length, numberOfCols, n = x[0].length;
	DoubleWrapper [][] d = new DoubleWrapper [m][n];
	for (int i=0; i<m; ++i) {
	    for (int j=0; j<n; ++j) {
		d[i][j] = new DoubleWrapper(x[i][j]);
	    }
	}
	return d;
    }

    private static double unwrap(FieldElement f) {
	return ((DoubleWrapper)f).value;
    }

    // Double, double, toil and trouble / If this don't work, your
    // code is rubble

    private static void check_double(Matrix a) 
	throws InvalidOperationException {
	check_double(a.getEntry(1,1));
    }

    private static void check_double(Vector v) 
	throws InvalidOperationException {
	check_double(v.getEntry(1));
    }

    private static void check_double(FieldElement value) 
	throws InvalidOperationException {

	DoubleWrapper d = new DoubleWrapper(0);
	if (!value.getClass().equals(d.getClass())) {
	    String err = "Matrix or Vector doesn't contain doubles";
	    throw new InvalidOperationException(err);
	}
    }

} // end of the class ...................................
