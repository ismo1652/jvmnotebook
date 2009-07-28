package org.node.perf.test;

import org.node.perf.test.util.Callback;
import org.node.perf.test.util.SimpleDoTimes;
import org.node.perf.test.util.SimpleTime;
import org.node.perf.test.util.Test;
import org.node.perf.test.util.Times;
import org.node.perf.util.SystemUtils;

/**
 * 
-----------------------------
Current clojure baseline test:


-----------------------------
 *
 */
public class Test9Fractal implements Test {

    public static final void main(String [] args) {
        final Test test = new Test9Fractal();
        test.main(args, null);
    }
        
    public void main(String [] args, Object input) {
        
        try {            
            this.runTest();
            this.runCoolDown();
            System.out.println("Done");
        } catch(Exception e) {
            e.printStackTrace();
        }
        
    }
        
    public int mandelbrotIterate(int max_iterations, double ci, double cr) {
        return mandelbrotLoop(max_iterations, 4.0, 0.0, 0.0, 1, ci, cr);
    }
    
    public int mandelbrotLoop(int max_iterations, double bailout, double zi, double zr, int i, double ci, double cr) {
        if (i <= max_iterations) {
            double zr2 = zr * zr;
            double zi2 = zi * zi;
            
            if ((zi2 + zr2) <= bailout) {                
                return mandelbrotLoop(max_iterations, bailout, zr * zi * 2.0 + ci, zr2 - zi2 + cr, i + 1, ci, cr);
            } else {                
                return i;
            }
        } else {
            return 0;
        }
    }
    
    public void mandelbrot() {
        
        // The default value of '99888' gets stack overflow
        // errors
        // 2500, is the threshold
        int max_iterations = 2200;
        
        for (double y = -39.0; y < 39.0; y += 1.0) {
            //System.out.println();
            for (double x = -39.0; x < 39.0; x += 1.0) {                
                int i = mandelbrotIterate(max_iterations, (x / 40.0), (y / 40.0) - 0.5);
                //System.out.print((i == 0) ? "*" : " ");
                String res = (i == 0) ? "*" : " ";
                // Don't print
            }
        }
    }

    /////////////////////////////////////////////////////////////////
/*
 
 Mimic the following clojure functionality using the Times and DoTimes interfaces:
 
  (time (dotimes [_ 1e6] (* 2.2 4.1 5.4)))
     
 */
    public final class Test1Times implements Times {

        public final void execute() {            
            mandelbrot();
        }
        
    } // End of Class //
    
    
    /////////////////////////////////////////////////////////////////
    
    public void runTest() {
                
        System.out.println("Running Test " + SystemUtils.currentDate());
        System.out.println("[1] START APP -- " + SystemUtils.memoryUsage());
        
        mandelbrot();
        
        // In clojure: (time (dotimes [_ 1e6] (* 2.2 4.1 5.4)))
        new SimpleTime(new SimpleDoTimes(new Test1Times(), SystemUtils.once)).execute();              
        
        System.out.println(SystemUtils.memoryUsage());       
    }

 /*
  ---------------------------
  Mimic Clojure Code:
  ---------------------------
(defn run-cool-down
  "Allow a little time to see if JVM garbage collects.
 This may not have any effect"
  []
  ;;;
  (println (*memory-usage*))
  (Thread/sleep 100)
  (println (*memory-usage*))
  (Thread/sleep 80))
    
  */
    public void runCoolDown() {
        try {
            System.out.println(SystemUtils.memoryUsage());
            Thread.sleep(100);
            System.out.println(SystemUtils.memoryUsage());
            Thread.sleep(80);
        } catch(InterruptedException e) {
            
        }
    }
    
    public void runTest2() {
        
    }

    public void runTest3() {
        
    }

    public void runTest4() {        
        
    }

} // End of Class //
