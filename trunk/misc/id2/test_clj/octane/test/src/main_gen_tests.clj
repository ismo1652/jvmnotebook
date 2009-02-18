
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; Copyright (c) ....:. All rights reserved.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(defn main []
	(compile 'test.OctaneSampleTestGen)
	;;(compile 'test.OctaneFullTest)
	;;(compile 'test.OctaneSampleMockTest)
	(compile 'test.OctaneGraphsAnalyticsTest)
	(compile 'test.OctaneUtilsTest))

(try (main)
	(catch Exception e (. e printStackTrace)))

(. System exit 1)

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; End of Test Case
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

