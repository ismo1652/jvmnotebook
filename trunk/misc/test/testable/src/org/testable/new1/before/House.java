package org.testable.new1.before;

/**
 * Basic new operators called directly in 
 * the class' constructor. (Forever 
 * preventing a seam to create different 
 * kitchen and bedroom collaborators).
 */
public class House {

    Kitchen kitchen = new Kitchen(); 
    Bedroom bedroom; 
    
    public House() {
        bedroom = new Bedroom();
    }
    
} // End of the Class House //
