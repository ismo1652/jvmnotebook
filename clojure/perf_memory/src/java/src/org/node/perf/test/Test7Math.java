package org.node.perf.test;

import java.math.BigDecimal;

import org.node.perf.test.Test6Strings.Test2Times;
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
public class Test7Math implements Test {

    public static final void main(String [] args) {
        final Test test = new Test7Math();
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
    
    public int euler5() {
        boolean isSolved = false;
        int limit = 20;
        int startNumber = limit;
        int number = 0;                
        for (int i = startNumber; ; i += limit) {
            
            for (int j = 1; j <= limit; j++) {
            
                if (i % j == 0) {
                    if (j == limit) {
                            isSolved = true;
                            number = i;
                    }
                    continue;
                } else {
                    break;
                }
                
            } // End of the for //
            if (isSolved == true) {
                break;
            }
        }
        return number;
    }

    /////////////////////////////////////////////////////////////////
/*
 
 Mimic the following clojure functionality using the Times and DoTimes interfaces:
 
  (time (dotimes [_ 1e6] (* 2.2 4.1 5.4)))
     
 */
    public final class Test1Times implements Times {

        public final void execute() {            
            BigDecimal d = new BigDecimal(1234567890777777000000.0);
            // cheat and use the double value.
            Math.sqrt(d.doubleValue());
        }
        
    } // End of Class //
    
    public final class Test2Times implements Times {
        
        private final int n;
        public Test2Times(int g) {
            this.n = g;
        }
        
        public final void execute() {
            for (int i = 0; i < n; i++) {
                int z = euler5();
                int b = z + 1;
            }
        }
        
    } // End of Class //
    
    
    /////////////////////////////////////////////////////////////////
    
    public void runTest() {
                
        System.out.println("Running Test " + SystemUtils.currentDate());
        System.out.println("[1] START APP -- " + SystemUtils.memoryUsage());
        
        // In clojure: (time (dotimes [_ 1e6] (* 2.2 4.1 5.4)))
        new SimpleTime(new SimpleDoTimes(new Test1Times(), (int)1e4)).execute();              
        
        System.out.println(SystemUtils.memoryUsage());   
        
        /*
        System.out.println("Euler 5 - " + euler5());        
        for (int i = 1; i < 6; i++) {
            
            int x = (int) Math.pow(10.0, i);
            System.out.println("i: " + x);          
            Times times = new Test2Times(x);
            times.execute();            
            new SimpleTime(times).execute();
        }
        */
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
