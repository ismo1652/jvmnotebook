package org.node.perf.test;

import org.node.perf.test.util.DoTimes;
import org.node.perf.test.util.SimpleDoTimes;
import org.node.perf.test.util.SimpleTime;
import org.node.perf.test.util.Test;
import org.node.perf.test.util.Times;
import org.node.perf.util.StringUtils;
import org.node.perf.util.SystemUtils;

/**
 * 
-----------------------------
Current clojure baseline test:


-----------------------------
 *
 */
public class Test2Refl implements Test {

    public static final void main(String [] args) {
        final Test test = new Test2Refl();
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

    /////////////////////////////////////////////////////////////////
    
    public static final String buildBigStr() {
        /*
         * In Clojure, this code might look like:
         ----------------------------------------- 
        (defn build-big-str
          []
          ;;;
          (let [str-size (* 1 1024)
                n        1024
                buf-1 (StringBuffer. (* str-size n))
                buf-2 (StringBuffer.)]    
          (dotimes [_ n]
              (let [b (random-string str-size)]
                (.append buf-1 (str b "|"))))
          (.toString buf-1)))
         */
        
        int strSize = 1 * 1024;
        int n = 1024;
        final StringBuffer buf1 = new StringBuffer(n * strSize);
        final StringBuffer buf2 = new StringBuffer();
        String b = "";
        for (int i = 0; i < n; i++) {
            b = StringUtils.randomString(strSize);
            buf1.append(b).append("|");
        }
        return buf1.toString();
    }
    
/*
 
 Mimic the following clojure functionality using the Times and DoTimes interfaces:
   
    (time (dotimes [_ 10] (let [data (build-big-str)]
            (println "Number of chars in str : " (count data)))))
     
 */
    public final class Test2Times implements Times {

        public final void execute() {            
            String data = buildBigStr();
            System.out.println("Count: " + data.length());
        }
        
    } // End of Class //
    
    
    /////////////////////////////////////////////////////////////////
    
    public void runTest() {
                
        System.out.println("Running Test [test string split and other str utils] " + SystemUtils.currentDate());
        System.out.println(SystemUtils.memoryUsage());
        
        // In clojure: (time (dotimes [_ 1e6] (* 2.2 4.1 5.4)))
                
        new SimpleTime(new SimpleDoTimes(new Test2Times(), (int)10)).execute();              
        
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
