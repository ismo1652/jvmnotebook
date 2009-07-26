package org.node.perf.test.util;

public class SimpleTime implements Time {
    
    /*
    
    Mimic the following clojure functionality using the Times and DoTimes interfaces:
    
     (time (dotimes [_ 1e6] (* 2.2 4.1 5.4)))
        
    */
    
    private final Callback callback;
    
    public SimpleTime(final Callback callback) {
        this.callback = callback;
    }
    
    private SimpleTime() {
        throw new AssertionError();
    }
    
    private final void executeMS() {
        final long startT = System.currentTimeMillis();
        if (callback != null) {
            callback.execute();
        }
        final long endT = System.currentTimeMillis();
        final long diff = endT - startT;
        System.out.println("Elapsed time: " + diff + " msecs");   
    }
    
    private final void executeNano() {
        final long startT = System.nanoTime();
        if (callback != null) {
            callback.execute();
        }
        final long endT = System.nanoTime();
        final long diff = endT - startT;
        final double diffd = (diff * 1e-6);
        System.out.println("Elapsed time: " + diffd + " msecs");   
    }
    private final void executeBoth() {
        final long startT = System.nanoTime();
        final long startT2 = System.currentTimeMillis(); 
        if (callback != null) {
            callback.execute();
        }
        final long endT = System.nanoTime();
        final long endT2 = System.currentTimeMillis();
        final long diff = endT - startT;
        final long diff2 = endT2 - startT2;
        final double diffd = (diff * 1e-6);
        System.out.println("Elapsed time: " + diffd + " msecs ;" + " diff2: " +  diff2 + " msecs");   
    }
    
    
    public final void execute() {
        executeNano();       
    }    
    
} // End of Class //
