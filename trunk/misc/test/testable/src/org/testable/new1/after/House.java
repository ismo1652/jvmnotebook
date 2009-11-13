package org.testable.new1.after;

/**
 * Basic new operators called directly in 
 * the class' constructor. (Forever 
 * preventing a seam to create different 
 * kitchen and bedroom collaborators).
 */
public class House {

    Kitchen kitchen; 
    Bedroom bedroom; 
    
    public House(Kitchen k, Bedroom b) { 
        kitchen = k; 
        bedroom = b; 

    }
    
} // End of the Class House //
