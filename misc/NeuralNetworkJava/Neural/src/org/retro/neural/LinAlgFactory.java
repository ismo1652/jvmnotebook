//
// Berlin Brown
//
// bigbinc@hotmail.com
//
// $Id: LinAlgFactory.java,v 1.1.1.1 2004/04/26 13:27:31 bigbinc Exp $
//
// author Simon D. Levy
//
// Dawt.headless=true
//...................................................


package org.retro.neural;

import java.util.Random;



public abstract class LinAlgFactory {


    public Matrix ones(int numberOfRows, int numberOfCols) {
	return block_matrix(numberOfRows, numberOfCols, unityValue());
    }

    /**
     * Returns a Matrix of all zeros.
     * @param numberOfRows
     * @param numberOfCols
     * @return matrix of zeros
     */
    public Matrix zeros(int numberOfRows, int numberOfCols) {
	return block_matrix(numberOfRows, numberOfCols, zeroValue());
    }

    /**
     * Returns a Matrix of uniformly distributed random values.
     * @param numberOfRows
     * @param numberOfCols
     * @param random random-number generator
     * @return matrix of uniformly distributed random values
     */
    public Matrix uniformNoise(int numberOfRows, int numberOfCols, 
			       Random random) {

	Matrix a = new Matrix(numberOfRows, numberOfCols);
	for (int i=1; i<=numberOfRows; ++i) {
	    for (int j=1; j<=numberOfCols; ++j) {
		a.setEntry(i, j, randomValue(random));
	    }
	}
	return a;
    }

    /**
     * Returns a Matrix of uniformly distributed random values.
     * @param numberOfRows
     * @param numberOfCols
     * @param seed seed for random-number generator
     * @return matrix of uniformly distributed random values
     */
    public Matrix uniformNoise(int numberOfRows, int numberOfCols, long seed) {
	return uniformNoise(numberOfRows, numberOfCols, new Random(seed));
    }

    /**
     * Returns a Matrix of uniformly distributed random values.
     * @param numberOfRows
     * @param numberOfCols
     * @return matrix of uniformly distributed random values
     */
    public Matrix uniformNoise(int numberOfRows, int numberOfCols) {
	return uniformNoise(numberOfRows, numberOfCols, new Random());
    }

    /**
     * Returns a Vector of all ones.
     * @param length vector length
     * @return vector of ones
     */
    public Vector ones(int length) {
	return block_vector(length, unityValue());
    }

    /**
     * Returns a Vector of all zeros.
     * @param length vector length
     * @return vector of zeros
     */
    public Vector zeros(int length) {
	return block_vector(length, zeroValue());
    }

    /**
     * Returns a Vector of uniformly distributed random values.
     * @param length vector length
     * @param random random-number generator
     * @return vector of uniformly distributed random values
     */
    public Vector uniformNoise(int length, Random random) {
	Vector v = new Vector(length);
	for (int i=1; i<=length; ++i) {
	    v.setEntry(i, randomValue(random));
	}
	return v;
    }

    /**
     * Returns a Vector of uniformly distributed random values.
     * @param length vector length
     * @param seed seed for random-number generator
     * @return vector of uniformly distributed random values
     */
    public Vector uniformNoise(int length, long seed) {
	return uniformNoise(length, new Random(seed));
    }

    /**
     * Returns a Vector of uniformly distributed random values.
     * @param length vector length
     * @return vector of uniformly distributed random values
     */
    public Vector uniformNoise(int length) {
	return uniformNoise(length, new Random());
    }

    /**
     * Returns the identity Matrix. This is a square matrix with ones on
     * its diagonal and zeros elsewhere.
     * @param size number of rows (= number of columns)
     * @return identity matrix
     */
    public Matrix identity(int size) {
	Matrix a = zeros(size, size);
	for (int i=1; i<=size; ++i) {
	    for (int j=1; j<=size; ++j) {
		a.setEntry(i, j, unityValue());
	    }
	}
	return a;
    }


    /**
     * This method should return a FieldElement corresponding to unity
     * (1), the neutral element of multiplication.
     * @return one
     */
    public abstract FieldElement unityValue();

    /**
     * This method should return a FieldElement corresponding to zero
     * (0), the neutral element of addition.
     * @return zero
     */
    public abstract FieldElement zeroValue();

    /**
     * This method should return a random value.
     * @return random value
     */
    public abstract FieldElement randomValue(Random random);

    // return Vector full of value
    private Vector block_vector(int length, FieldElement value) {
	Vector v = new Vector(length);
	for (int i=1; i<=length; ++i) {
	    v.setEntry(i, value);
	}
	return v;
    }

    // return Matrix full of value
    private Matrix block_matrix(int numberOfRows, int numberOfCols, 
				FieldElement value) {
	Matrix a = new Matrix(numberOfRows, numberOfCols);
	for (int i=1; i<=numberOfRows; ++i) {
	    for (int j=1; j<=numberOfCols; ++j) {
		a.setEntry(i, j, value);
	    }
	}
	return a;
    }

} // end of the class ..............................

