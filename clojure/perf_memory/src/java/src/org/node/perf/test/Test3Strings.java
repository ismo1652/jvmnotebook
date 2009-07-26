package org.node.perf.test;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

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
public class Test3Strings implements Test {

    public static final void main(String [] args) {
        final Test test = new Test3Strings();
        test.main(args, null);
    }
        
    public void main(String [] args, Object input) {
        
        try {            
            this.runTest3();
            this.runCoolDown();
            System.out.println("Done");
        } catch(Exception e) {
            e.printStackTrace();
        }          
    } // End of Main

    public static final Map withLoopTestStrPut1(final int n) {           
    /*
    (defn with-loop-test-str-put-1
            "Test the hash/key 'put'.  Use a tiny data value"
            [n]
            ;;;
            (loop [data {}
                   i    0]
              (if (< i n)
                ;; Perform operation:
                ;; (println "debug: " data)
                ;; Associate the keyword with the some 'data value'
                (recur (assoc data (keyword (random-string 80)) "test-tiny-data")
                       (+ i 1))
                data)))
    */
        final Map map = new HashMap();
        for (int i = 0; i < n; i++) {
            map.put(StringUtils.randomString(80), "test-tiny-data");
        } // End of the for //
        return map;
    }
    
    public static final Map withLoopTestStrPut2(final int n) {                   
            final Map map = new HashMap();
            for (int i = 0; i < n; i++) {
                map.put(StringUtils.randomString(500), StringUtils.randomString(500));
            } // End of the for //
            return map;
    }
    
    public static final Map withLoopTestStrPut3(final int n) {                   
        final Map map = new HashMap();
        for (int i = 0; i < n; i++) {
            map.put(StringUtils.randomString(SystemUtils.e4), StringUtils.randomString(SystemUtils.e4));
        } // End of the for //
        return map;
    }
    
    public static final List buildTestSortListSmall(int n) {
    /*
    (defn build-test-sort-list-small            
            [n]
            ;;;;;
            (for [x (range n)]
              (random-string 100)))

          (defn build-test-sort-list-big
            "See: 'for' 'List comprehension. Takes a vector of one or more 
           binding-form/collection-expr pairs, each followed by zero or more modifiers, 
           and yields a lazy sequence of evaluations of expr.'"
            [n]
            ;;;;;
            ;; Build a collection of strings
            ;; each string will have 100k of data
            (for [x (range n)]
              (random-string 100000)))
     */
        final List list = new ArrayList(40);
        for (int i = 0; i < n; i++) {
            list.add(StringUtils.randomString(100));
        } // End of the for //
        return list;
    }
    
    public static final List buildTestSortListBig(int n) {
        
            final List list = new ArrayList(40);
            for (int i = 0; i < n; i++) {
                list.add(StringUtils.randomString(100000));
            } // End of the for //
            return list;
    }
    
    public static final List buildTestSortListSmallLinked(int n) {
        
        final List list = new LinkedList();
        for (int i = 0; i < n; i++) {
            list.add(StringUtils.randomString(100));
        } // End of the for //
        return list;
    }
    
    public static final List buildTestSortListBigLinked(int n) {
        
        final List list = new LinkedList();
        for (int i = 0; i < n; i++) {
            list.add(StringUtils.randomString(100000));
        } // End of the for //
        return list;
    }
    
    /////////////////////////////////////////////////////////////////
/*
 
 Mimic the following clojure functionality using the Times and DoTimes interfaces:
 
  (time (dotimes [_ 1e6] (* 2.2 4.1 5.4)))
  
(time (let [lst (build-test-sort-list-small 1e4)]
          (println (count lst))
          (println (first lst))
          (let [z (sort lst)]
            (println (count z))
            (println (first z)))))
  ;; Now, perform the same 'for' test but use 'large string data'
  (println (*memory-usage*))
  (time (let [lst (build-test-sort-list-big 100)]
          (println (count lst))
          ;; To avoid printing the large string, just
          ;; print the count
          (println (count (first lst)))
          (let [z (sort lst)]
            (println (count z))
            ;; To avoid printing the large string, just
            ;; print the count
            (println (count (first z))))))     
 */
    public final class Test1Times implements Times {

        public final void execute() {
            final List lst = buildTestSortListSmall(10000);
            System.out.println(lst.size());
            System.out.println(lst.get(0));
                                
            Collections.sort(lst);
            
            System.out.println(lst.size());
            System.out.println(lst.get(0));
        }
        
    } // End of Class //
    
    public final class Test2Times implements Times {

        public final void execute() {
            final List lst = buildTestSortListBig(100);
            System.out.println(lst.size());
            System.out.println(((String)lst.get(0)).length());
                                
            Collections.sort(lst);
            
            System.out.println(lst.size());
            System.out.println(((String)lst.get(0)).length());
        }
        
    } // End of Class //
    
    public final class Test3Times implements Times {

        public final void execute() {
            final List lst = buildTestSortListSmallLinked(10000);
            System.out.println(lst.size());
            System.out.println(((String)lst.get(0)).length());
                                
            Collections.sort(lst);
            
            System.out.println(lst.size());
            System.out.println(((String)lst.get(0)).length());
        }
        
    } // End of Class //
    
    public final class Test4Times implements Times {

        public final void execute() {
            final List lst = buildTestSortListBigLinked(100);
            System.out.println(lst.size());
            System.out.println(((String)lst.get(0)).length());
                                
            Collections.sort(lst);
            
            System.out.println(lst.size());
            System.out.println(((String)lst.get(0)).length());
        }
        
    } // End of Class //
    
    public final class Test5Times implements Times {

        public final void execute() {
            Map data = withLoopTestStrPut1(SystemUtils.e4);  
            System.out.println("Size of hash : " + data.size());   
        }
        
    } // End of Class //
    
    public final class Test6Times implements Times {

        public final void execute() {
            Map data = withLoopTestStrPut2(SystemUtils.e4);  
            System.out.println("Size of hash : " + data.size());   
        }
        
    } // End of Class //

    public final class Test7Times implements Times {

        public final void execute() {
            Map data = withLoopTestStrPut3(SystemUtils.e2);  
            System.out.println("Size of hash : " + data.size());   
        }
        
    } // End of Class //
    
    /////////////////////////////////////////////////////////////////
    
    public void runTest() {
                
        System.out.println("Running Test " + SystemUtils.currentDate());
        System.out.println(SystemUtils.memoryUsage());
        
        new SimpleTime(new SimpleDoTimes(new Test1Times(), SystemUtils.once)).execute();                      
        System.out.println(SystemUtils.memoryUsage());       
        
        System.out.println("Larger Strings");
        new SimpleTime(new SimpleDoTimes(new Test2Times(), SystemUtils.once)).execute();                      
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
        
        System.out.println("Running Test [now using linked list] " + SystemUtils.currentDate());
        System.out.println(SystemUtils.memoryUsage());
        
        new SimpleTime(new SimpleDoTimes(new Test3Times(), (int) 1)).execute();                      
        System.out.println(SystemUtils.memoryUsage());       
        
        System.out.println("Larger Strings");
        new SimpleTime(new SimpleDoTimes(new Test4Times(), (int) 1)).execute();                      
        System.out.println(SystemUtils.memoryUsage());
        
    }

    public void runTest3() {
        
        System.out.println("Running with hashmap, put");
        System.out.println(SystemUtils.memoryUsage());
        new SimpleTime(new SimpleDoTimes(new Test5Times(), SystemUtils.once)).execute();
        System.out.println(SystemUtils.memoryUsage());
        
        new SimpleTime(new SimpleDoTimes(new Test6Times(), SystemUtils.once)).execute();
        System.out.println(SystemUtils.memoryUsage());
        
        new SimpleTime(new SimpleDoTimes(new Test7Times(), SystemUtils.once)).execute();
        System.out.println(SystemUtils.memoryUsage());
    }

    public void runTest4() {        
        
    }

} // End of Class //
