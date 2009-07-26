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

 (println "[1] START APP -- " (*memory-usage*))  
  ;; Test the slower case
  (time (dotimes [_ 1e6] (* 2.2 4.1 5.4)))
  (println "[2] ^^^^ AFTER FIRST SLOW CASE -- " (*memory-usage*))
  ;; Slower case using anonymous function
  (time (dotimes [_ 1e6] 
            (let [f (fn [x] (* 2.2 4.1 x))]
              (f 5.4))))
  (println "[3] ^^^^ AFTER SLOW CASE WITH ANON : " (*memory-usage*))
  ;; The performance fix, binary arithmetic operation
  (time (dotimes [_ 1e6] (* 2.2 (* 4.1 5.4))))
  ;;;;;;;;;;;;;;;;;;;;;;;;;
  (println "[4] ^^^^ AFTER FAST CASE : " (*memory-usage*))

-----------------------------
 *
 */
public class Test1BaselineHello implements Test {

    public static final void main(String [] args) {
        final Test test = new Test1BaselineHello();
        test.main(args, null);
    }
        
    public void main(String [] args, Object input) {
        
        try {            
            this.runTest();
            System.out.println("Done");
        } catch(Exception e) {
            e.printStackTrace();
        }
        
    }

    /////////////////////////////////////////////////////////////////
/*
 
 Mimic the following clojure functionality using the Times and DoTimes interfaces:
 
  (time (dotimes [_ 1e6] (* 2.2 4.1 5.4)))
     
 */
    public final class Test1Times implements Times {

        public final void execute() {            
            double res = 2.2 * 4.1 * 5.4;         
        }
        
    } // End of Class //
    
    // There is not a real good way to mimic the functionality in the 
    // based line test.  But we will try with the callback.
    
    public final class Test2Times implements Times {

        public final void execute() {
            
            final Callback callback = new Callback() {
            
                public void execute() {
                    double res = 2.2 * 4.1 * 5.4;                    
                }
            }; // end of callback
            
            callback.execute();
        }
        
    } // End of Class //
    
    /////////////////////////////////////////////////////////////////
    
    public void runTest() {
                
        System.out.println("Running Test " + SystemUtils.currentDate());
        System.out.println("[1] START APP -- " + SystemUtils.memoryUsage());
        
        // In clojure: (time (dotimes [_ 1e6] (* 2.2 4.1 5.4))) 
        final SimpleDoTimes dotimes1 = new SimpleDoTimes(new Test1Times(), (int)1e6);        
        new SimpleTime(dotimes1).execute();
        System.out.println("Test 1: " + dotimes1);
        
        new SimpleTime(new SimpleDoTimes(new Test2Times(), (int)1e6)).execute();
        
        new SimpleTime(new SimpleDoTimes(new Test2Times(), (int)1e6)).execute();
        
        System.out.println(SystemUtils.memoryUsage());       
    }

    public void runTest2() {
        
    }

    public void runTest3() {
        
    }

    public void runTest4() {        
        
    }

} // End of Class //
