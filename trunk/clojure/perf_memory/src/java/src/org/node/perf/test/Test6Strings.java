package org.node.perf.test;

import org.node.perf.test.Test1BaselineHello.Test2Times;
import org.node.perf.test.util.Callback;
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
public class Test6Strings implements Test {

    public static final void main(String [] args) {
        final Test test = new Test6Strings();
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

    public static final String testStrJoin() {
        /*
         (defn test-str-join
          "Test the clojure contrib join.  This join uses apply, interpose"
          []
          ;;;
          ;; 100x100 character string
          (let [a (build-split-str 100 100)
                b (.split a "\\|")]    
            (str-join "|" b)))        
         */
        String a = StringUtils.buildSplitStr(100, 100, "|", "[END]");
        String [] b = a.split("\\|");
        return StringUtils.join("|", b); 
    }
    
    public static final String testStrJoin2() {
        /*
         (defn test-str-join
          "Test the clojure contrib join.  This join uses apply, interpose"
          []
          ;;;
          ;; 100x100 character string
          (let [a (build-split-str 100 100)
                b (.split a "\\|")]    
            (str-join "|" b)))        
         */        
        String [] b = new String [] { "my", "dog", "has", "some", "problems" }; 
        return StringUtils.join("|", b); 
    }
    
    /////////////////////////////////////////////////////////////////
/*
 
 Mimic the following clojure functionality using the Times and DoTimes interfaces:
 
  (time (dotimes [_ 1e6] (* 2.2 4.1 5.4)))
     
 */
    public final class Test1Times implements Times {

        private int n = 0;
        
        public Test1Times(int z) {
            this.n = z;
        }
        
        public final void execute() {            
        
            /*
            (dotimes [x 10]
                      (println "i: " (* (+ 1 x) 10))
                    (time 
                     (dotimes [_ (* (+ 1 x) 10)]
                         (test-str-join))))
             */
            
            for (int i = 0; i < this.n; i++) {
                String z = testStrJoin();
                z.length();
            }
        }
        
    } // End of Class //
    
    public final class Test2Times implements Times {

        private int n = 0;
        
        public Test2Times(int z) {
            this.n = z;
        }
        
        public final void execute() {            
        
            /*
            (dotimes [x 10]
                      (println "i: " (* (+ 1 x) 10))
                    (time 
                     (dotimes [_ (* (+ 1 x) 10)]
                         (test-str-join))))
             */
            
            for (int i = 0; i < this.n; i++) {
                String z = testStrJoin2();
                z.length();
            }
        }
        
    } // End of Class //
    
    
    public final class Test3Times implements Times {

        private int n = 0;
        
        public Test3Times(int z) {
            this.n = z;
        }
        
        public final void execute() {            
        
            /*
            (dotimes [x 10]
                      (println "i: " (* (+ 1 x) 10))
                    (time 
                     (dotimes [_ (* (+ 1 x) 10)]
                         (test-str-join))))
             */
            
            for (int i = 0; i < this.n; i++) {
                String c = "ABC 123 UUU XXX END END";
                String z = c.replaceAll("XXX", "YYY");
                z.length();
            }
        }
        
    } // End of Class //
    
    
    /////////////////////////////////////////////////////////////////
    
    public void runTest() {
                
        System.out.println("Running Test " + SystemUtils.currentDate());
        System.out.println("[1] START APP -- " + SystemUtils.memoryUsage());
        
        String c = "ABC 123 UUU XXX END END";
        System.out.println(c.replaceAll("XXX", "YYY"));
        
        // In clojure: (time (dotimes [_ 1e6] (* 2.2 4.1 5.4)))
        // new SimpleTime(new SimpleDoTimes(new Test2Times(), (int)1e6)).execute();
        /*
        (time 
         (dotimes [_ (* (+ 1 x) 10)]
             (test-str-join))))
         */
        for (int i = 1; i < 11; i++) {
            
            System.out.println("i: " + (i * 10));          
            Times times = new Test1Times(i * 10);
            times.execute();
            new SimpleTime(times).execute();
        }        
        System.out.println(SystemUtils.memoryUsage());
        
        /*
  (println "Smaller Test")
  (dotimes [x 6]
      (println "i: " (int (Math/pow 10.0 x)))
    (time 
     (dotimes [_ (int (Math/pow 10.0 x))]
         (test-str-join-2)))         
         */
        System.out.println("Smaller Test");
        
        for (int i = 1; i < 6; i++) {
            
            int x = (int) Math.pow(10.0, i);
            System.out.println("i: " + x);          
            Times times = new Test2Times(x);
            times.execute();            
            new SimpleTime(times).execute();
        }
        
        System.out.println(SystemUtils.memoryUsage());                
        System.out.println("gsub test");
        
        for (int i = 1; i < 6; i++) {
            
            int x = (int) Math.pow(10.0, i);
            System.out.println("i: " + x);          
            Times times = new Test3Times(x);
            times.execute();            
            new SimpleTime(times).execute();
        }
        
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
