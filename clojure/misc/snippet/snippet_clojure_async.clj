;;
;; SWT Async usage
(. disp asyncExec
   (proxy [Runnable] []
		  (run [] (. styled-text setText (. buffer-1 toString)))))