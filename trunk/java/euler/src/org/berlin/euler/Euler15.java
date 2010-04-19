package org.berlin.euler;

import java.util.ArrayList;
import java.util.List;

import junit.framework.TestCase;
import junit.textui.TestRunner;

/**
 * Starting in the top left corner of a 2×2 grid, there are 6 routes (without backtracking) 
 * to the bottom right corner.
 * 
 *
 *
factorial :: Integer -> Integer
factorial n = product [1..n]

grid_routes :: Integer -> Integer -> Integer
grid_routes n m = (factorial (m+n)) `div` ((factorial m) * (factorial n))

main = print $ grid_routes 20 20
~
 * 
 * @author BerlinBrown
 *
 */
public class Euler15 extends TestCase {

    private List<Path> paths = new ArrayList<Path>(); 
    
    private final int maxX;
    private final int maxY;
    
    public Euler15() {
        maxX = 0;
        maxY = 0;
    }
    
    public Euler15(final int x, final int y) {
        this.maxX = x;
        this.maxY = y;
    }
    
    
    /**
     * 
     * @author BerlinBrown
     *
     */
    public static class Point extends Object {
        
        private final int x;
        private final int y;
        
        public Point(final int x, final int y) {
            this.x = x;
            this.y = y;            
        }        
        
        public final boolean equals(final Object o) {
            if (o == null) {
                return false;
            }
            if (!(o instanceof Point)) {
                return false;
            }
            final Point p = (Point) o;
            if ((this.x == p.x) && (this.y == p.y)) {
                return true;
            }
            return false;
        }
        
    } // End of Class //

    public static class Path extends Object {
        
        private final List<Point> pathSet = new ArrayList<Point>();
        
        public int size() {
            return this.pathSet.size();
        }
        
        public final boolean equals(final Object o) {
            if (o == null) {
                return false;
            }
            if (!(o instanceof Path)) {
                return false;
            }
            
            final Path p = (Path) o;
            if (this.pathSet.size() != p.size()) {
                return false;
            }
            return false;
        }
    } // End of Class //
    
    public void testEuler15() {
               
        
    }
    
    public static void main(String [] args) {
                
        TestRunner.run(Euler15.class);
        
    }
    
    
} // End of the Class //
