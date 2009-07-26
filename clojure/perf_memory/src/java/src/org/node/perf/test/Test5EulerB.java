package org.node.perf.test;

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
public class Test5EulerB implements Test {

    public static final void main(String [] args) {
        final Test test = new Test5EulerB();
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
    
    /**
     * Find the sum of all the even-valued terms in the sequence which do not exceed four million.
     * @return
     */
    public static long euler2() {

        long fib = 2;
        long fib2 = 1;
        long fibSwap = 0;
        long total = 0;
        
        while (total < 4000000) {
    
                if ((fib % 2) == 0) {
                    total+= fib;
                }
                
                fibSwap = fib;
                fib += fib2;
                fib2 = fibSwap;    
        } // End of While //
        return total;
        
    }
    /////////////////////////////////////////////////////////////////
/*
 
 Mimic the following clojure functionality using the Times and DoTimes interfaces:
 
  (time (dotimes [_ 1e6] (* 2.2 4.1 5.4)))
     
 */
    public final class Test1Times implements Times {

        public final void execute() {            
            long z = euler2();
            boolean b = z == 4613732;
        }
        
    } // End of Class //       
    
    /////////////////////////////////////////////////////////////////
    
    public void runTest() {
                
        System.out.println("Running Test " + SystemUtils.currentDate());
        System.out.println("[1] START APP -- " + SystemUtils.memoryUsage());
        
        System.out.println(euler2());
        
        //new SimpleTime(new SimpleDoTimes(new Test1Times(), SystemUtils.once)).execute();
        
        // In clojure: (time (dotimes [_ 1e6] (* 2.2 4.1 5.4)))        
        for (int x = 1; x < 13; x++) {
            System.out.println("i :" + (x * 1000));
            new SimpleTime(new SimpleDoTimes(new Test1Times(), (x*100))).execute();
        
        }       
        
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
