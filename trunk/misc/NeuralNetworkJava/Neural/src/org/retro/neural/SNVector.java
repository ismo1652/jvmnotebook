//
// Berlin Brown
//
// $Id: SNVector.java,v 1.2 2004/06/17 10:49:02 bigbinc Exp $
//
//
//...................................................................

package org.retro.neural;


public class SNVector {

    protected Vector vec;


    public SNVector(int n) {
	vec = (new DoubleFactory()).zeros(n);
    }

 
    public SNVector(double [] a) {
	vec = DoubleFactory.buildVector(a);
    }

     public int length() {
	return vec.length();
    }

 
    public double getValue(int i) throws RuntimeException {
	return unwrap(vec.getEntry(i+1));	
    }

 
    public void add(double s) {
	vec.addReplace(wrap(s));
    }

 
    public void subtract(double s) {
	vec.subtractReplace(wrap(s));
    }

    public void multiply(double s) {
	vec.multiplyReplace(wrap(s));
    }


    public void divide(double s) {
	vec.divideReplace(wrap(s));
    }


    public static SNVector add(SNVector x, double s) {
	return new SNVector(x.vec.add(wrap(s)));
    }


    public static SNVector subtract(SNVector x, double s) {
	return new SNVector(x.vec.subtract(wrap(s)));
    }


    public static SNVector multiply(SNVector x, double s) {
	return new SNVector(x.vec.multiply(wrap(s)));
    }


    public static SNVector divide(SNVector x, double s) {
	return new SNVector(x.vec.divide(wrap(s)));
    }


    public void add(SNVector x) throws RuntimeException {
	vec.addReplace(x.vec);
    }


    public void subtract(SNVector x) throws RuntimeException {
	vec.subtractReplace(x.vec);
    }


    public void multiply(SNVector x) throws RuntimeException {
	vec.multiplyReplace(x.vec);
    }


    public static SNVector add(SNVector x, SNVector y) 
	throws RuntimeException {
	return new SNVector(x.vec.add(y.vec));
    }


    public static SNVector subtract(SNVector x, SNVector y) 
	throws RuntimeException {
	return new SNVector(x.vec.subtract(y.vec));
    }

    /**
     * Returns a vector containing the products of the elements of two vectors.
     * @param x one vector
     * @param y the other vector
     * @return x .* y
     * @throws RuntimeException if the vectors have unequal lengths    
     */
    public static SNVector arrayMultiply(SNVector x, SNVector y) 
	throws RuntimeException {
	return new SNVector(x.vec.arrayMultiply(y.vec));
    }

    /**
     * Multiplies the elements of this vector by those of another.
     * @param x the other vector
     * @throws RuntimeException if the vectors have unequal lengths    
     */
    public void arrayMultiply(SNVector x) throws RuntimeException {
	vec.multiplyReplace(x.vec);
    }

    /**
     * Returns a 1D array of the values contained in this vector.
     * @return values
     */
    public double [] getValues() {
	return DoubleFactory.doubleValues(vec);
    }

    /**
     * Returns the sum of the elements of this vector.
     * @return sum
     */
    public double sum() {
	return unwrap(vec.sum());
    }

    /**
     * Returns the value of the smallest element of this vector.
     * @return minimum value
     */
    public double min() {
	return unwrap(vec.min());
    }

    /**
     * Returns the Euclidean distance between this vector and another.
     * @param x the other vector
     * @return dist(this, x)
     * @throws RuntimeException if the vectors have unequal lengths    
     */
    public double eucDist(SNVector x) throws RuntimeException {
	return DoubleFactory.eucDist(vec, x.vec);
    }

    /**
     * Replicates this vector as a matrix.  Returns an
     * <i>m</i>-by-<i>n</i> matrix for a length-<i>n</i> vector replicated
     * <i>m</i> times.
     *
     * @param m number of times to replicate
     * @return an <i>m</i>-by-<i>n</i> Matrix
     */
    public SNMatrix repmat(int m) {
	return new SNMatrix(vec.repmat(m));
    }

    /**
     * Returns a copy of this vector, sorted in ascending order.
     * @return sorted copy
     */
    public SNVector sort() {
	return new SNVector(vec.sort());
    }

    /**
     * Returns indices where vector equals scalar argument.  Index of first
     * value in any vector is 0.
     * @param scalar 
     * @return indices where vector equals scalar
     */
    public int [] find(double s) {
	int [] f = vec.find(wrap(s));
	for (int i=0; i<f.length; ++i) {
	    f[i]--;
	}
	return f;
    }

    /**
     * Returns the Manhattan distance (L1 norm of differences) between
     * this vector and another.
     * @param x the other vector
     * @return Manhattan distance between this and anotherVector
     * @throws RuntimeException if Vectors have unequal lengths
     */
    public double nycDist(SNVector x) throws RuntimeException {
	return unwrap(vec.nycDist(x.vec));
    }

    /**
     * Returns a vector of normally distributed random values.  Values are
     * taken from a Gaussian distribution with zero mean and standard 
     * deviation one.
     * @param length
     * @param random random-number generator
     * @return vector of normally distributed random values
     */
    public static SNVector gaussianNoise(int n, java.util.Random r) {
	DoubleFactory f = new DoubleFactory();
	return new SNVector(f.gaussianNoise(n, r));
    }

    /**
     * Returns the outer product of this vector and another.
     * 
     * @param  x the other vector
     * @return this^T X x
     * @throws RuntimeException if the other vector is null
     */
    public SNMatrix outer(SNVector x) {
	return new SNMatrix(vec.cross(x.vec));
    }


    /**
     * Returns a deep copy of this vector.
     *
     * @return vector copy
     */
    public SNVector copy() {
	return new SNVector(vec.copy());
    }


    /**
     * Sets all entries to a scalar.
     *
     * @param s the scalar
     */
    public void setAll(double s) {
	vec.setAll(wrap(s));
    }

    /**
     * Sets an entry to a scalar at a certain index.
     *
     * @param i index
     * @param s scalar
     * @throws RuntimeException if the index is invalide
     */
    public void setValue(int i, double s) throws RuntimeException {
	vec.setEntry(i+1, wrap(s));
    }

    /**
     * Returns a vector containing ones where this vector's elements
     * are not equal to a scalar, and zeros elsewhere.
     * 
     * @param s the scalar
     * @return vector of ones and zeros
     */
    public SNVector ne(double s) {
	return new SNVector(vec.ne(wrap(s)));
    }

    /**
     * Returns a vector containing ones where this vector's elements
     * are greater than or equal to a scalar, and zeros elsewhere.
     * 
     * @param s the scalar
     * @return vector of ones and zeros
     */
    public SNVector ge(double s) {
	return new SNVector(vec.ge(wrap(s)));
    }

    /**
     * Returns a vector containing ones where this vector's elements
     * are less than or equal to a scalar, and zeros elsewhere.
     * 
     * @param s the scalar
     * @return vector of ones and zeros
     */
    public SNVector le(double s) {
	return new SNVector(vec.le(wrap(s)));
    }

    /**
     * Returns the largest value of any element in this vector.
     * @return the largest value
     */
    public double max() {
	return unwrap(vec.max());
    }

    /**
     * Returns the logical AND of this vector with another.  Elements of the
     * result are 1 where both vectors are non-zero, and zero elsewhere.
     * @param x the other vector
     * @return vector of 1's and 0's
     * @throws RuntimeException if the vectors have unequal lengths
     */
    public SNVector and(SNVector x) throws RuntimeException {
	return new SNVector(vec.and(x.vec));
    }

    /**
     * Returns the product of this Vector and a Matrix.
     * 
     * @param a the matrix
     * @return this * a
     * @throws InvalidOperationException if the matrix is null
     * @throws InvalidOperationException if the inner dimensions mismatch
     */
    public SNVector multiply(SNMatrix a) throws RuntimeException {
	return new SNVector(vec.multiply(a.mat));
    }

    /**
     * Returns a String representation of this vector.
     * @return string representation
     */
    public String toString() {
	return vec.toString();
    }

    protected SNVector(Vector x) {
	vec = x;
    }

    private static DoubleWrapper wrap(double s) {
	return new DoubleWrapper(s);
    }

    private static double unwrap(FieldElement d) {
	return DoubleFactory.doubleValue(d);
    }


} // end of the class .....................................
