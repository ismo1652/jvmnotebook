package org.node.perf.test;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.Set;

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
public class Test8Collection implements Test {

    public static final void main(String [] args) {
        final Test test = new Test8Collection();
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

    public static List buildFrequencies(int n, int sz) { 
        
        final List list = new ArrayList(n);
        for (int i = 0; i < n; i++) {
            list.add(StringUtils.randomString(sz));
        }
        return list;
        
    }
    
    /////////////////////////////////////////////////////////////////
/*
 
 Mimic the following clojure functionality using the Times and DoTimes interfaces:
 
  (time (dotimes [_ 1e6] (* 2.2 4.1 5.4)))
     
 */
    public final class Test1Times implements Times {
        
        private final int n;
        public Test1Times(int g) {
            this.n = g;
        }
        
        public final void execute() {
            for (int i = 0; i < this.n; i++) {
                Map m = StringUtils.frequencies(buildFrequencies(1000, 3));
                m.size();
                Set d = m.keySet();       
            } // End of the For //
        }
        
    } // End of Class //
    
    
    /////////////////////////////////////////////////////////////////
    
    public void runTest() {
                
        System.out.println("Running Test " + SystemUtils.currentDate());
        System.out.println("[1] START APP -- " + SystemUtils.memoryUsage());
        
        // Small test
        long a = System.nanoTime();
        StringUtils.checkMap(StringUtils.frequencies(buildFrequencies(1000, 3)));
        long b = System.nanoTime();
        double d = (b - a) * 1e-6;
        System.out.println(d + " ms");
        /////
        
        long a2 = System.nanoTime();
        StringUtils.frequencies(buildFrequencies(1000, 3));
        long b2 = System.nanoTime();
        double d2 = (b2 - a2) * 1e-6;
        System.out.println(d2 + " ms");
        
        for (int i = 1; i < 4; i++) {
            
            int x = (int) Math.pow(10.0, i);
            System.out.println("i: " + x);
            Times times = new Test1Times(x);
            times.execute();            
            new SimpleTime(times).execute();
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
