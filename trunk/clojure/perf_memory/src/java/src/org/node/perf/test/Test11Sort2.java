package org.node.perf.test;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Random;

import org.node.perf.test.Test8Collection.Test1Times;
import org.node.perf.test.util.SimpleTime;
import org.node.perf.test.util.Test;
import org.node.perf.test.util.Times;
import org.node.perf.util.StringUtils;
import org.node.perf.util.SystemUtils;

/** 
-----------------------------
Current clojure baseline test:


-----------------------------
 */
public class Test11Sort2 implements Test {

    public static final void main(String [] args) {
        final Test test = new Test11Sort2();
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
/*
 
 Mimic the following clojure functionality using the Times and DoTimes interfaces:
 
  (time (dotimes [_ 1e6] (* 2.2 4.1 5.4)))
     
 */
    
    private static final Random random = new Random(System.currentTimeMillis());
    
    public final class Test1Times implements Times {

        private int n;
        
        public Test1Times(int g) {
            this.n = g;
        }
        
        public final void execute() {           
            
            final List l = new ArrayList();            
            // Build a list and then sort the list.
            for (int i = 0; i < n; i++) {
                l.add(random.nextInt());
            } // End of the for //
            
            // Return a new quick sorted list
            List z = quicksort(l);
            int b = z.size();
            int d = b + 1;            
            Object h = z.get(0);
            h.toString();
            
        }
        
    } // End of Class //
    
    /**
     * Code from rosetta code:
     * 
     * License: Content is available under GNU Free Documentation License 1.2
     */
    public static final List quicksort(final List arr) {
        if (arr.size() <= 1) {
            return arr;
        }
        Integer pivot = (Integer) arr.get(0); //This pivot can change to get faster results
     
        List less = new LinkedList();
        List pivotList = new LinkedList();
        List more = new LinkedList();
     
        // Partition
        for (Iterator it = arr.iterator(); it.hasNext();) {
            Integer i = (Integer) it.next();
            if (i.compareTo(pivot) < 0) {
                less.add(i);
            } else if (i.compareTo(pivot) > 0) {
                more.add(i);
            } else {
                pivotList.add(i);
            } // End of the if - else //
            
        } // End of the for //
     
        // Recursively sort sublists
        less = quicksort(less);
        more = quicksort(more);
     
        // Concatenate results
        less.addAll(pivotList);
        less.addAll(more);
        return less;
    }
    
    public static final List list(int a, int b, int c, int d, int e, int f) {
        final List list = new ArrayList(6);
        list.add(new Integer(a));
        list.add(new Integer(b));
        list.add(new Integer(c));
        list.add(new Integer(d));
        list.add(new Integer(e));
        list.add(new Integer(f));
        return list;
    }
    
    /////////////////////////////////////////////////////////////////
    
    public void runTest() {
                
        System.out.println("Running Test " + SystemUtils.currentDate());
        System.out.println("[1] START APP -- " + SystemUtils.memoryUsage());
        
        // (println (qsort [ 4 5 23 1 35 3 ]))
        StringUtils.checkList(list(4, 5, 23, 1, 35, 3));
        System.out.println("sorted:");
        StringUtils.checkList(quicksort(list(4, 5, 23, 1, 35, 3)));
        
        // In clojure: (time (dotimes [_ 1e6] (* 2.2 4.1 5.4)))
        //new SimpleTime(new SimpleDoTimes(new Test1Times(), (int)1e6)).execute();
        
        for (int i = 1; i < 12; i++) {
            
            int x = (int) Math.pow(3.0, i);
            System.out.println("i-size: " + x);
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
