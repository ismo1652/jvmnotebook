package org.node.perf.test;

import org.node.perf.bean.LargeObject;
import org.node.perf.bean.MediumObject;
import org.node.perf.bean.SmallObject;
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


-----------------------------
 *
 */
public class Test12Vars implements Test {

    public static final void main(String [] args) {
        final Test test = new Test12Vars();
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
    
    public static final String largeObjectCreate() {
/*
There is no good Java approach to copying this
code.  We will attempt to use nested anonymous inner classes.

Ideally, we should have been OK to just create N number
of variables.  But I was going to be rough on java.
-------------------------------------------------
(defn large-object-create
  []
  ;;;;;;;
  ;; Random use of 'let' and large object create test
  (let [func (fn []
                 (let [a (org.node.perf.bean.LargeObject.)]
                   (let [b (org.node.perf.bean.LargeObject.)]
                     (let [c (org.node.perf.bean.LargeObject.)]
                       (let [d (org.node.perf.bean.LargeObject.)]
                         (let [e (org.node.perf.bean.LargeObject.)]
                           (let [f (org.node.perf.bean.LargeObject.)]
                             (let [g (org.node.perf.bean.LargeObject.)]
                               (let [h (org.node.perf.bean.LargeObject.)]
                                 (let [i (org.node.perf.bean.LargeObject.)]
                                   (let [j (org.node.perf.bean.LargeObject.)]
                                     (str (.toString a)
                                          (.toString b)
                                          (.toString c)
                                          (.toString d)
                                          (.toString e)
                                          (.toString f)
                                          (.toString g)
                                          (.toString h)
                                          (.toString i)
                                          (.toString j)))))))))))))]
    (func)))
-------------------------------------------------    
 */
        
        final StringBuffer buf = new StringBuffer();
        (new Callback() {
          
            public void execute() {
                
               LargeObject a = new LargeObject();
               buf.append(a.toString());
               
               (new Callback() {
                   public void execute() {
                       
                       LargeObject b = new LargeObject();
                       buf.append(b.toString());
                       
                       (new Callback() {
                           public void execute() {
                               
                               LargeObject c = new LargeObject();
                               buf.append(c.toString());
                               
                               (new Callback() {
                                   public void execute() {
                                       
                                       LargeObject d = new LargeObject();
                                       buf.append(d.toString());
                                       
                                       (new Callback() {
                                           public void execute() {
                                               
                                               LargeObject e = new LargeObject();
                                               buf.append(e.toString());
                                               
                                               (new Callback() {
                                                   public void execute() {
                                                       
                                                       LargeObject i = new LargeObject();
                                                       buf.append(i.toString());
                                                       
                                                       (new Callback() {
                                                           public void execute() {
                                                               LargeObject j = new LargeObject();
                                                               buf.append(j.toString());
                                                               
                                                           }
                                                       }).execute();
                                                       
                                                   }
                                               }).execute();
                                               
                                           }
                                       }).execute();
                                       
                                   }
                               }).execute();
                               
                           }
                       }).execute();
                       
                   }
               }).execute(); // end for b
               
            }
            
        }).execute(); // End of Callback //
     
        return buf.toString();
        
    }
    public static final String mediumObjectCreate() {
        
        final StringBuffer buf = new StringBuffer();
        (new Callback() {
          
            public void execute() {
                
               MediumObject a = new MediumObject();
               buf.append(a.toString());
               
               (new Callback() {
                   public void execute() {
                       
                       MediumObject b = new MediumObject();
                       buf.append(b.toString());
                       
                       (new Callback() {
                           public void execute() {
                               
                               MediumObject c = new MediumObject();
                               buf.append(c.toString());
                               
                               (new Callback() {
                                   public void execute() {
                                       
                                       MediumObject d = new MediumObject();
                                       buf.append(d.toString());
                                       
                                       (new Callback() {
                                           public void execute() {
                                               
                                               MediumObject e = new MediumObject();
                                               buf.append(e.toString());
                                               
                                               (new Callback() {
                                                   public void execute() {
                                                       
                                                       MediumObject i = new MediumObject();
                                                       buf.append(i.toString());
                                                       
                                                       (new Callback() {
                                                           public void execute() {
                                                               MediumObject j = new MediumObject();
                                                               buf.append(j.toString());
                                                               
                                                           }
                                                       }).execute();
                                                       
                                                   }
                                               }).execute();
                                               
                                           }
                                       }).execute();
                                       
                                   }
                               }).execute();
                               
                           }
                       }).execute();
                       
                   }
               }).execute(); // end for b
               
            }
            
        }).execute(); // End of Callback //
     
        return buf.toString();
        
    }            
    
    public static final String smallObjectCreate() {
        
        final StringBuffer buf = new StringBuffer();
        (new Callback() {
          
            public void execute() {
                
               SmallObject a = new SmallObject();
               buf.append(a.toString());
               
               (new Callback() {
                   public void execute() {
                       
                       SmallObject b = new SmallObject();
                       buf.append(b.toString());
                       
                       (new Callback() {
                           public void execute() {
                               
                               SmallObject c = new SmallObject();
                               buf.append(c.toString());
                               
                               (new Callback() {
                                   public void execute() {
                                       
                                       SmallObject d = new SmallObject();
                                       buf.append(d.toString());
                                       
                                       (new Callback() {
                                           public void execute() {
                                               
                                               SmallObject e = new SmallObject();
                                               buf.append(e.toString());
                                               
                                               (new Callback() {
                                                   public void execute() {
                                                       
                                                       SmallObject i = new SmallObject();
                                                       buf.append(i.toString());
                                                       
                                                       (new Callback() {
                                                           public void execute() {
                                                               SmallObject j = new SmallObject();
                                                               buf.append(j.toString());
                                                               
                                                           }
                                                       }).execute();
                                                       
                                                   }
                                               }).execute();
                                               
                                           }
                                       }).execute();
                                       
                                   }
                               }).execute();
                               
                           }
                       }).execute();
                       
                   }
               }).execute(); // end for b
               
            }
            
        }).execute(); // End of Callback //
     
        return buf.toString();
        
    }
    

    /////////////////////////////////////////////////////////////////
/*
 
 Mimic the following clojure functionality using the Times and DoTimes interfaces:
 
  (time (dotimes [_ 1e6] (* 2.2 4.1 5.4)))
     
 */
    public final class Test1Times implements Times {

        public final void execute() {            
            String c = largeObjectCreate();
            c.length();
        }
        
    } // End of Class //
    
    public final class Test2Times implements Times {

        public final void execute() {            
            String c = mediumObjectCreate();
            c.length();
        }
        
    } // End of Class //
    
    public final class Test3Times implements Times {

        public final void execute() {            
            String c = smallObjectCreate();
            c.length();
        }
        
    } // End of Class //
    
    
    
    /////////////////////////////////////////////////////////////////
    
    public void runTest() {
                
        System.out.println("Running Test " + SystemUtils.currentDate());
        System.out.println("[1] START APP -- " + SystemUtils.memoryUsage());
                   
        System.out.println(largeObjectCreate());
        System.out.println(mediumObjectCreate());
        System.out.println(smallObjectCreate());
        
        new SimpleTime(new SimpleDoTimes(new Test1Times(), 56)).execute();     
        new SimpleTime(new SimpleDoTimes(new Test1Times(), 40)).execute();
        new SimpleTime(new SimpleDoTimes(new Test1Times(), 120)).execute();
        
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
