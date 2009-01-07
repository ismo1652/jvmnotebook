;;; Copyright (c) Berlin Brown and botnode.com:. All rights reserved.
;;;
;;; http://www.java2s.com/Code/Java/SWT-JFace-Eclipse/SWTMenuExample.htm
;;; -------------------------------------------------------
(import '(org.eclipse.swt.widgets Display Shell Text Widget))
(import '(org.eclipse.swt.widgets Label Menu MenuItem))
(import '(org.eclipse.swt SWT))

(def display (new Display))
(def shell (new Shell display))

(defn exit []
  (. System (exit 0)))

(defn build-menu-bar [sh]
  (let [menu-bar (new Menu sh (. SWT BAR))]
    (doto (new MenuItem menu-bar (. SWT CASCADE))
      (setText "&File"))
    menu-bar))
  
(defn simple-swt [disp sh]
  (doto (new Text sh (. SWT MULTI))
    (setText "Test")
    (setSize 500 400)
    (selectAll))
  (doto sh
    (setMenuBar (build-menu-bar sh))
    (pack) (open))
  (loop []
    (if (. shell (isDisposed))
      (. disp (dispose))
      (let []
        (if (not (. disp (readAndDispatch)))
          (. disp (sleep)))
        (recur)))))

(println "Running")
(simple-swt display shell)

;;**************************************
;; Lock the thread on this file, to wait until the frame is closed.
;;**************************************
(let [o (new Object)] 
  (locking o (. o (wait))))

;;; End of Script