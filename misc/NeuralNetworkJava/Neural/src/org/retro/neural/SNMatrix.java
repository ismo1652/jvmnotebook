//
// Berlin Brown
//
// $Id: SNMatrix.java,v 1.2 2004/06/17 10:49:02 bigbinc Exp $
//
//
// 

package org.retro.neural;


public class SNMatrix {

    protected Matrix mat;


    public SNMatrix(int m, int n) {
	mat = (new DoubleFactory()).zeros(m, n);
    }


    /**
     * Constructs a matrix using a 2D array of double-precision
     * floating-point values.
     * @param a the array of values
     */
    public SNMatrix(double [][] x) {
	mat = DoubleFactory.buildMatrix(x);
    }

    /**
     * Returns a vector repsenting the mean over the rows of this Matrix.
     * @return the mean
     */
    public SNVector meanRows() {
	return new SNVector(mat.meanRows());
    }

    /**
     * Returns a vector representing the sum over the rows of this Matrix.
     * @return the sum
     */
    public SNVector sumRows() {
	return new SNVector(mat.sumRows());
    }

    /**
     * Returns the difference between two matrices.
     * @param a one matrix
     * @param b the other matrix
     * @return a - b
     * @throws RuntimeException if the matrices have unequal sizes
     */
    public static SNMatrix subtract(SNMatrix a, SNMatrix b) {
	return new SNMatrix(a.mat.subtract(b.mat));
    }

    /**
     * Returns a matrix containing the products of the elements of two
     * matrices.
     * @param a one matrix
     * @param b the other matrix
     * @return a .* b
     * @throws RuntimeException if the matrices have unequal sizes
     */
    public static SNMatrix arrayMultiply(SNMatrix a, SNMatrix b) {
	return new SNMatrix(a.mat.arrayMultiply(b.mat));
    }

    /**
     * Returns the number of rows of this Matrix.
     * @return number of rows
     */
    public int getRows() {
	return mat.getRows();
    }

    /**
     * Returns the number of columns of this Matrix.
     * @return number of columns
     */
    public int getCols() {
	return mat.getCols();
    }

    /**
     * Returns a 2D array of the values contained in this matrix.
     * @return values
     */
    public double [][] getValues() {
	return DoubleFactory.doubleValues(mat);
    }

    /**
     * Sets the row vector at a certain index of this matrix.  First
     * row has index 0.
     *
     * @param i index
     * @param x vector
     * @throws RuntimeException if index is out of range
     */
    public void setRow(int i, SNVector x) throws RuntimeException {
	mat.setRow(i+1, x.vec);
    }

    /**
     * Gets the row vector at a certain index of this matrix.  First
     * row has index 0.
     *
     * @param i index
     * @return vector at row i
     * @throws RuntimeException if index is out of range
     */
    public SNVector getRow(int i) {
	return new SNVector(mat.getRow(i+1));
    }

    /**
     * Returns a matrix of normally distributed random values.  Values are
     * taken from a Gaussian distribution with zero mean and standard 
     * deviation one.
     * @param m number of rows
     * @param n number of columns
     * @param random random-number generator
     * @return matrix of normally distributed random values
     */
    public static SNMatrix gaussianNoise(int m, int n, java.util.Random r) {
	DoubleFactory f = new DoubleFactory();
	return new SNMatrix(f.gaussianNoise(m, n, r));
    }

    /** 
     * Adds a matrix to this matrix.
     * @param a the other matrix
     * @throws RuntimeException if the matrices have unequal sizes
     */
    public void add(SNMatrix a) throws RuntimeException {
	mat.addReplace(a.mat);
    }

    /**
     * Returns the quotient of a matrix and a scalar.
     * @param a the matrix
     * @param s the scalar
     * @return a / s
     */
    public static SNMatrix divide(SNMatrix a, double s) {
	return new SNMatrix(a.mat.divide(wrap(s)));
    }

    /**
     * Divides this matrix by a scalar.
     * @param s the scalar
     */
    public void divide(double s) {
	mat.divideReplace(wrap(s));
    }

    /**
     * Returns the transpose of this matrix.
     * @return this^T
     */
    public SNMatrix transpose() {
	return new SNMatrix(mat.transpose());
    }

    /**
     * Returns the product of a matrix and a scalar.
     * @param a the matrix
     * @param s the scalar
     * @return a * s
     */
    public static SNMatrix multiply(SNMatrix a, double s) {
	return new SNMatrix(a.mat.multiply(wrap(s)));
    }

    /**
     * Returns the product of this matrix and a vector.
     * @param x the vector
     * @return this * x
     * @throws RuntimeException if number of columns of this matrix does not
     * equal number of elements in x
     */
    public SNVector multiply(SNVector x) {
	return new SNVector(mat.multiply(x.vec));
    }

    /**
     * Returns the sum over all elements of this Matrix.
     * @return the sum
     */
    public double sum() {
	return unwrap(mat.sum());
    }

    /**
     * Returns the value of the largest element of this matrix.
     * @return maximum value
     */
    public double max() {
	return unwrap(mat.max());
    }

    /**
     * Returns a deep copy of this matrix.
     *
     * @return matrix copy
     */
    public SNMatrix copy() {
	return new SNMatrix(mat.copy());
    }

    /**
     * Returns a matrix containing ones where this matrix's elements
     * are not equal to a scalar, and zeros elsewhere.
     * 
     * @param s the scalar
     * @return matrix of ones and zeros
     */
    public SNMatrix ne(double s) {
	return new SNMatrix(mat.ne(wrap(s)));
    }

    /**
     * Returns a String representation of this matrix.
     * @return string representation
     */
    public String toString() {
	return mat.toString();
    }

    protected SNMatrix(Matrix a) {
	mat = a;
    }

    private static DoubleWrapper wrap(double s) {
	return new DoubleWrapper(s);
    }

    private static double unwrap(FieldElement d) {
	return DoubleFactory.doubleValue(d);
    }


} // end of the class ................
