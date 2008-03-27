//
// Berlin Brown
//
// bigbinc@hotmail.com
//
// $Id: FieldElement.java,v 1.1.1.1 2004/04/26 13:27:31 bigbinc Exp $
//
//
// Andreas Keilhauer, Simon D. Levy
//..............................................

package org.retro.neural;


public abstract class FieldElement implements Comparable {
    
    /**
     * Calculates the sum of this FieldElement and another one.
     *
     * @param val
     * @return sum
     */

    public abstract FieldElement add(FieldElement val);
    
    /**
     * Calculates the difference of this FieldElement and another one.
     *
     * @param val
     * @return difference
     */

    public FieldElement subtract(FieldElement val){
	return this.add(val.negate());
    }
    
    /**
     * Calculates the product of this FieldElement and another one.
     *
     * @param val
     * @return product
     */
 
    public abstract FieldElement multiply(FieldElement val);
    
    /**
     * Calculates the quotient of this FieldElement and another one.
     *
     * @param val
     * @return product
     */

    public FieldElement divide(FieldElement val){
	return this.multiply(val.invert());
    }
    
    /**
     * Returns the neutral element of addition (zero element) of this
     * FieldElement's field.
     *
     * @return zero
     */

    public abstract FieldElement zero();
    
    /**
     * Returns the neutral element of multiplication (one element) of
     * this FieldElement's field.
     *
     * @return one
     */

    public abstract FieldElement one();
    
    /**
     * Calculates the inverse element of addition for this FieldElement.
     *
     * @return negated
     */

    public abstract FieldElement negate();

    /**
     * Calculates the inverse element of multiplication for this FieldElement.
     *
     * @return inverted
     */

    public abstract FieldElement invert();

    /**
     * Checks two FieldElements for equality.
     * Should be overridden due to efficiency reasons.
     *
     * @param val
     * @return true if the two FieldElements are mathematically equal.
     */
   
    public boolean equals(FieldElement val){
	return this.subtract(val).isZero();
    }
   
    /**
     * Tests if this FieldElement is the neutral element of addition (zero).
     * 
     * @return true if zero
     */

    public boolean isZero(){
	return this.equals(this.zero());
    }

    /**
     * Tests if this FieldElement is the neutral element of
     * multiplication (one).
     * 
     * @return true if one
     */

    public boolean isOne(){
	return this.equals(this.one());
    }

    /**
     * Implements Comparable.compareTo(Object).
     * @param o the object
     * @return {-,+,0} as this object is less than, equal to, or
     * greater than the specified object.
     */

    public abstract int compareTo(Object o);

    /**
     * Checks whether this FieldElement is mathematically less than another.
     *
     * @param val
     * @return true if this FieldElement is less than val, false otherwise
     */

    public boolean lt(FieldElement val) {
	return this.compareTo(val) < 0;
    }


    /**
     * Checks whether this FieldElement is mathematically greater than another.
     *
     * @param val
     * @return true if this FieldElement is greater than val, false otherwise
     */

    public boolean gt(FieldElement val) {
	return !this.lt(val) && !this.equals(val);
    }

    /**
     * Checks whether this FieldElement is mathematically less than or equal to
     * another.
     *
     * @param val
     * @return true if this FieldElement is less than or equal to val,
     * false otherwise
     */

    public boolean le(FieldElement val) {
	return this.lt(val) || this.equals(val);
    }

    /**
     * Checks whether this FieldElement is mathematically greater than
     * or equal to another.
     *
     * @param val
     * @return true if this FieldElement is greater than or equal to
     * val, false otherwise
     */

    public boolean ge(FieldElement val) {
	return this.gt(val) || this.equals(val);
    }

    /**
     * Returns an instance of this FieldElement to be used in computing mean
     * and other values.
     *
     * @param dval the value to use
     * @return instance
     */

    public abstract FieldElement instance(double dval);

}  // end of the class .......................................
