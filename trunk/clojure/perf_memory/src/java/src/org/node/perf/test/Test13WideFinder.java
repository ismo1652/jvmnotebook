package org.node.perf.test;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

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
public class Test13WideFinder implements Test {

    public static final void main(String [] args) {
        final Test test = new Test13WideFinder();
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
        
    public static final void wideFinder() throws IOException {
        wideFinder(new FileInputStream("./input/o10k.ap"));
    }
    
    /**
     * Wide Finder Code is from the following site:
     * 
     * http://unintentionalobjectretention.blogspot.com/2007/10/widefinder-and-java.html
     * 
     * Quote:
     * 
     * Everyone seems to getting in on Tim Bray's WideFinder challenge; there is even a C++ implementation.
     * I think it was originally supposed to be a competition between all those new and exciting dynamic languages, 
     * but they have not be overly impressive thus far. So I've decided to post up my various attempts at a solution in Java. 
     * Here is the basic WideFinder in Java (all import statements are omitted for brevity):
     * 
     * The basic version is very similar to the Ruby one, if a little more verbose. Like all of the others, it is primarily IO bound. 
     * One important thing I found, was that specifying the encoding as being ASCII made about 30% improvement in the time taken.
     * 
     * End Quote:
     * 
     * @param stream
     * @throws IOException
     */
    public static final void wideFinder(InputStream stream) throws IOException {
        
            Map<String, Integer> counts = new HashMap<String, Integer>();
            Pattern p = Pattern.compile("GET /ongoing/When/\\d\\d\\dx/(\\d\\d\\d\\d/\\d\\d/\\d\\d/[^ .]+) ");
            BufferedReader in = new BufferedReader(new InputStreamReader(stream));
          
            String line = null;
            while ((line = in.readLine()) != null) {
                Matcher m = p.matcher(line);
                if (m.find()) {
                    String key = m.group();
                    Integer currentCount = counts.get(key);
                    counts.put(key, (currentCount == null ? 1 : (currentCount + 1)));
                }
            }
            in.close();
          
            List<Entry<String, Integer>> results = new ArrayList<Map.Entry<String, Integer>>(counts.entrySet());
            Collections.sort(results, new Comparator<Entry<String, Integer>>() {

                public int compare(Entry<String, Integer> o1, Entry<String, Integer> o2)
                {
                    return o2.getValue().compareTo(o1.getValue());
                }
              
            });
          
            for (int i = 0; i < 10; i++) {
                if (i <= (results.size() - 1)) {
                    System.out.print(i + ": " + results.size() + "/");
                    System.out.println(results.get(i));                    
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
            try {
                wideFinder();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        
    } // End of Class //
    
    
    /////////////////////////////////////////////////////////////////
    
    public void runTest() {
                
        System.out.println("Running Test " + SystemUtils.currentDate());
        System.out.println("[1] START APP -- " + SystemUtils.memoryUsage());
                
        try {
            wideFinder();
        } catch (IOException e) {
            e.printStackTrace();
        }
        
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
