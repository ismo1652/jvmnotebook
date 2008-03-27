//
// Berlin Brown
//
// $Id: F2.java,v 1.1.1.1 2004/04/26 13:27:31 bigbinc Exp $
//
//

package org.retro.neural;

  
public class F2 extends FieldElement implements Comparable {

    public int value;

    /**
     * Builds an element from an integer value.  The resulting value is 
     * simply this integer value, modulo 2.
     */    
    public F2(int value){
	this.value = value % 2;
    }

    /**
     * Calculates the sum of this element and another one.
     *
     * @param val
     * @return sum mod 2
     */
    public FieldElement add(FieldElement val){
	F2 added = (F2)val;
	return new F2((this.value + added.value) % 2); 
    }

    /**
     * Calculates the product of this element and another one.
     *
     * @param val
     * @return product mod 2
     */

    public FieldElement multiply(FieldElement val){
	F2 factor = (F2)val;
	return new F2((this.value * factor.value) % 2); 
    }

    /**
     * Calculates the inverse element of addition for this element.
     *
     * @return negated (i.e., the value itself)
     */
    public FieldElement negate(){
	return this;
    }

    /**
     * Calculates the inverse element of multiplication for this element.
     *
     * @return inverted (i.e., the value itself)
     * @throws InvalidOperationException if original value is zero
     */
    public FieldElement invert() throws InvalidOperationException{
	if(this.value == 0){
	    throw new InvalidOperationException("Division by 0");
	}
	return this;
    }

    /**
     * Returns the neutral element of addition (zero element) of this
     * FieldElement's field.
     *
     * @return zero
     */
    public FieldElement zero(){
	return new F2(0);
    }

    /**
     * Returns the neutral element of multiplication (one element) of
     * this element's field.
     *
     * @return one
     */
    public FieldElement one(){
	return new F2(1);
    }

    /**
     * Checks two elements for equality.
     *
     * @param val
     * @return true if the two FieldElements are mathematically equal.
     */
    public boolean equals(FieldElement val){
	F2 comp = (F2)val;
	return this.value == comp.value; 
    }

    /**
     * Returns a String representation of this element.
     *
     * @return String representation
     */
    public String toString(){
	return ""+this.value;
    }

    /**
     * Implements Comparable.compareTo(Object).
     * @param o the object
     * @return {-,+,0} as this object is less than, equal to, or
     * greater than the specified object.
     */

    public int compareTo(Object o) {
	F2 comp = (F2)o;
	return (value < comp.value) ? -1 : (value > comp.value ? 1 : 0);
    }

    /**
     * Returns an instance of this FieldElement to be used in computing mean
     * and other values.
     *
     * @param dval the value to use
     * @return instance
     */

    public FieldElement instance(double dval) {
	return new F2((int)dval);
    }
} // end of the class .....................................
