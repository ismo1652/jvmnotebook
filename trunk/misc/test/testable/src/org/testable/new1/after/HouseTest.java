package org.testable.new1.after;

/**
 * New and Improved is trivially testable, with any 
 * test-double objects as collaborators. 
 * @author berlinbrown
 */
public class HouseTest extends TestCase {
    
    public void testThisIsEasyAndFlexible() {
        Kitchen dummyKitchen = new DummyKitchen();
        Bedroom dummyBedroom = new DummyBedroom(); 
        //   Bedroom objects created in the 
        House house = 
                new House(dummyKitchen, dummyBedroom); 
        
        // Awesome, I can use test doubles that 

    }
    
}
