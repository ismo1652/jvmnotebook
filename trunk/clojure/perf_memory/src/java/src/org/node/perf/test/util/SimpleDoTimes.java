package org.node.perf.test.util;

public class SimpleDoTimes implements DoTimes {
    
    /*
    
    Mimic the following clojure functionality using the Times and DoTimes interfaces:
    
     (time (dotimes [_ 1e6] (* 2.2 4.1 5.4)))
        
    */
    
    private final Times callback;
    private final int n;
    private long iter = 0;
    
   
    public SimpleDoTimes(final Times callback, int n) {
        this.callback = callback;
        this.n = n;
    }
    
    private SimpleDoTimes() {
        throw new AssertionError();
    }

    public String toString() {
        return "dotimes:" + this.iter;
    }
    
    public final void execute(int N) {
        for (int i = 0; i < N; i++) {
            if (callback != null) {
                callback.execute();
                iter++;
            }
        } // End of for //
    }    
    
    public final void execute() {
        for (int i = 0; i < n; i++) {
            if (callback != null) {
                callback.execute();
                iter++;
            }
        } // End of for //
    }
    
    /**
     * @return the iter
     */
    public final long getIter() {
        return iter;
    }
    
} // End of Class //
