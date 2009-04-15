package org.adder.test;

import java.util.Random;

import org.adder.EquationGenome;

import junit.framework.TestCase;

public class AdderTest extends TestCase {

    /**
     * The Random Seem.
     */
    public static final Random TheSeed = new Random(System.currentTimeMillis());
    
    public void testSample() {
    
        for (int i = 0; i < 20; i++) {
            final int res = EquationGenome.nextInt(TheSeed, 1, 20);
            System.out.println("Res=>" + res);
        }
        System.out.println("----");
        for (int i = 0; i < 20; i++) {
            final int res = EquationGenome.nextInt(TheSeed, 10, 20);
            System.out.println("Res=>" + res);
        }
        
    }
    
} // End of the Class //
