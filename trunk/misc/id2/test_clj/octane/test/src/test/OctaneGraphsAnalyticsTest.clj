
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; Copyright (c) ....:. All rights reserved.
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(ns test.OctaneGraphsAnalyticsTest
    (:import (junit.framework Assert)
			 (java.io InputStreamReader BufferedReader ByteArrayInputStream))
	(:use
	 octane.toolkit.octane_utils
	 octane.toolkit.octane_main_constants
	 octane.toolkit.ws_garbage_collection
	 octane.toolkit.octane_analytics)
	(:gen-class
	 :extends junit.framework.TestCase
     :methods
	 [    
	  ;;[ test_print_gc_xml [] void ]
	  [ test_load_gc_xml [] void ]
	  ;;[ test_get_tenured [] void ]
	  [ test_get_timestamp_attr    [] void ]
	  [ test_parse-gc-aftags       [] void ]
	  [ test_simple_reglog_regex   [] void ]
	  [ test_simple_reglog_regex2  [] void ]
	  [ test_build_queryregex-list [] void ]
	  ]))

(def example-gc-xml-2
	 "<?xml version=\"1.0\" ?>
<verbosegc version=\"200802_08\">
<af type=\"tenured\" id=\"1\" timestamp=\"Feb 14 06:02:17 2009\" intervalms=\"0.000\">
  <minimum requested_bytes=\"32\" />
</af>
<af type=\"tenured\" id=\"2\" timestamp=\"Feb 14 06:03:17 2009\" intervalms=\"0.000\">
  <minimum requested_bytes=\"34\" />
</af>
</verbosegc>
")


(def example-gc-xml 
	 "<?xml version=\"1.0\" ?>

<verbosegc version=\"200802_08\">

2/14/09 06:02:13 AM EST [INFO] [Agent.Properties] UseDataSource=true

<af type=\"tenured\" id=\"1\" timestamp=\"Feb 14 06:02:17 2009\" intervalms=\"0.000\">
  <minimum requested_bytes=\"32\" />
  <time exclusiveaccessms=\"0.025\" />
  <tenured freebytes=\"5032960\" totalbytes=\"100663296\" percent=\"4\" >
    <soa freebytes=\"0\" totalbytes=\"95630336\" percent=\"0\" />
    <loa freebytes=\"5032960\" totalbytes=\"5032960\" percent=\"100\" />
  </tenured>
  <gc type=\"global\" id=\"1\" totalid=\"1\" intervalms=\"0.000\">
    <refs_cleared soft=\"280\" threshold=\"32\" weak=\"502\" phantom=\"0\" />
    <finalization objectsqueued=\"359\" />
    <timesms mark=\"19.164\" sweep=\"2.340\" compact=\"0.000\" total=\"21.612\" />
    <tenured freebytes=\"88476424\" totalbytes=\"100663296\" percent=\"87\" >
      <soa freebytes=\"83443464\" totalbytes=\"95630336\" percent=\"87\" />
      <loa freebytes=\"5032960\" totalbytes=\"5032960\" percent=\"100\" />
    </tenured>
  </gc>
  <tenured freebytes=\"88476392\" totalbytes=\"100663296\" percent=\"87\" >
    <soa freebytes=\"83443432\" totalbytes=\"95630336\" percent=\"87\" />
    <loa freebytes=\"5099960\" totalbytes=\"5099960\" percent=\"100\" />
  </tenured>
  <time totalms=\"22.213\" />
</af>

<af type=\"tenured\" id=\"2\" timestamp=\"Feb 14 06:02:21 2009\" intervalms=\"3387.788\">
  <minimum requested_bytes=\"32\" />
  <time exclusiveaccessms=\"0.026\" />
  <tenured freebytes=\"5032960\" totalbytes=\"100663296\" percent=\"4\" >
    <soa freebytes=\"0\" totalbytes=\"95630336\" percent=\"0\" />
    <loa freebytes=\"5032960\" totalbytes=\"5032960\" percent=\"100\" />
  </tenured>
  <gc type=\"global\" id=\"2\" totalid=\"2\" intervalms=\"3388.433\">
    <refs_cleared soft=\"0\" threshold=\"32\" weak=\"39\" phantom=\"0\" />
    <finalization objectsqueued=\"4\" />
    <timesms mark=\"21.233\" sweep=\"1.965\" compact=\"0.000\" total=\"23.300\" />
    <tenured freebytes=\"87948504\" totalbytes=\"100663296\" percent=\"87\" >
      <soa freebytes=\"82915544\" totalbytes=\"95630336\" percent=\"86\" />
      <loa freebytes=\"5032960\" totalbytes=\"5032960\" percent=\"100\" />
    </tenured>
  </gc>
  <tenured freebytes=\"87948472\" totalbytes=\"100663296\" percent=\"87\" >
    <soa freebytes=\"82915512\" totalbytes=\"95630336\" percent=\"86\" />
    <loa freebytes=\"5032960\" totalbytes=\"5032960\" percent=\"100\" />
  </tenured>
  <time totalms=\"23.973\" />
</af>

<af type=\"tenured\" id=\"64\" timestamp=\"Feb 14 08:25:24 2009\" intervalms=\"1076061.918\">
  <minimum requested_bytes=\"16688\" />
  <time exclusiveaccessms=\"0.088\" />
  <tenured freebytes=\"11632\" totalbytes=\"116293120\" percent=\"0\" >
    <soa freebytes=\"11632\" totalbytes=\"116293120\" percent=\"0\" />
    <loa freebytes=\"0\" totalbytes=\"0\" percent=\"0\" />
  </tenured>
  <gc type=\"global\" id=\"64\" totalid=\"64\" intervalms=\"1076062.554\">
    <refs_cleared soft=\"0\" threshold=\"32\" weak=\"340\" phantom=\"0\" />
    <finalization objectsqueued=\"1685\" />
    <timesms mark=\"198.626\" sweep=\"4.336\" compact=\"0.000\" total=\"203.115\" />
    <tenured freebytes=\"47957624\" totalbytes=\"116293120\" percent=\"41\" >
      <soa freebytes=\"47957624\" totalbytes=\"116293120\" percent=\"41\" />
      <loa freebytes=\"0\" totalbytes=\"0\" percent=\"0\" />
    </tenured>
  </gc>
  <tenured freebytes=\"47940784\" totalbytes=\"116293120\" percent=\"41\" >
    <soa freebytes=\"47940784\" totalbytes=\"116293120\" percent=\"41\" />
    <loa freebytes=\"0\" totalbytes=\"0\" percent=\"0\" />
  </tenured>
  <time totalms=\"203.807\" />
</af>

</verbosegc>
")

(def example-for-tenured  
 [
 {:tag :minimum, :attrs {:requested_bytes 32}, :content nil} 
 {:tag :time, :attrs {:exclusiveaccessms 0.025}, :content nil} 
 {:tag :tenured, :attrs {:percent 4, :freebytes 5032960, :totalbytes 100663296}, 
       :content [{:tag :soa, :attrs {:percent 0, :freebytes 0, :totalbytes 95630336}, :content nil} 
                 {:tag :loa, :attrs {:percent 100, :freebytes 5032960, :totalbytes 5032960}, :content nil}]} 
 {:tag :gc, :attrs {:id 1, :intervalms 0.000, :type "global", :totalid 1}, 
    :content [{:tag :refs_cleared, :attrs {:phantom 0, :threshold 32, :weak 502, :soft 280}, :content nil} 
       {:tag :finalization, :attrs {:objectsqueued 359}, :content nil} {:tag :timesms, :attrs {:compact 0.000, :sweep 2.340, :total 21.612, :mark 19.164}, :content nil} {:tag :tenured, :attrs {:percent 87, :freebytes 88476424, :totalbytes 100663296}, :content [{:tag :soa, :attrs {:percent 87, :freebytes 83443464, :totalbytes 95630336}, :content nil} {:tag :loa, :attrs {:percent 100, :freebytes 5032960, :totalbytes 5032960}, :content nil}]}]} 
 {:tag :tenured, :attrs {:percent 87, :freebytes 88476392, :totalbytes 100663296}, 
       :content [{:tag :soa, :attrs {:percent 87, :freebytes 83443432, :totalbytes 95630336}, :content nil} {:tag :loa, :attrs {:percent 100, :freebytes 5032960, :totalbytes 5032960}, :content nil}]} 
 {:tag :time, :attrs {:totalms 22.213}, :content nil} 
 ]
)

(def example-request-log
"
============
222.22.22.221 - ABCDX - [13/Feb/2009:07:33:38 -0400] \"POST /Servlet1 HTTP/1.1\" 200 - 
222.22.22.222 - ABCDY - [13/Feb/2009:07:33:38 -0400] \"POST /Servlet2 HTTP/1.1\" 200 - 
222.22.22.223 - ABCDZ - [13/Feb/2009:07:33:38 -0400] \"POST /Servlet3 HTTP/1.1\" 404 - 
222.22.22.224 - ABCDA - [13/Feb/2009:07:33:38 -0400] \"POST /Servlet3 HTTP/1.1\" 500 - 
222.22.22.225 - ABCDB - [13/Feb/2009:07:33:38 -0400] \"POST /Servlet5 HTTP/1.1\" 200 -
========
Example
")

(def example-query-log
"
============
 | app01 | file.sql | data2 | u3 | 2009.02.09:08:00:13:397 | 2009.02.09:08:00:15:475 | 444 | doc=3
 | app02 | file2.sql | data3 | u3 | 2009.02.09:08:00:13:397 | 2009.02.09:08:00:15:475 | 444 | doc=3
 | app03 | file3.sql | data4 | u3 | 2009.02.09:08:00:13:397 | 2009.02.09:08:00:15:475 | 444 | doc=3
 | app03 | file3.sql | data4 | u3 | 2009.02.09:08:00:13:397 | 2009.02.09:08:00:15:475 | 444 | doc=3
========
Example
")

(defn -init [_] ()) 

(defn -test_print_gc_xml [_]
  (let [s2 example-gc-xml
		   strm (new ByteArrayInputStream (. s2 getBytes))]
	(let [data (clojure.xml/parse strm)
			   content (data :content)]
	  (doseq [i content] 
		  (let []
			(println "Type: " (class i))
			(when (= (class i) clojure.lang.PersistentStructMap)
			  (println "-->" i "<--")))))))
			
(defn -test_load_gc_xml [_]
  (let [s2 example-gc-xml]
	(let [res (load-native-gc-xml s2 false)]
	  (Assert/assertNotNull res)
	  (doseq [node res]
		  (Assert/assertNotNull "Invalid Result Data" node))
	  )))

(defn -test_get_tenured [_]
  (let [s (list example-for-tenured)]
	(get-tenured-tags s)))

(defn -test_get_timestamp_attr [_]
  (let [data {:tag :af, :attrs {:timestamp "Feb 14 06:02:17 2009", :id 1 }}]
	(Assert/assertEquals "Feb 14 06:02:17 2009" (get-timestamp-attr data))
	(Assert/assertTrue (= 1234609337000 (parse-timestamp-date "Feb 14 06:02:17 2009")))))

(defn -test_parse-gc-aftags [_]
  (let [str example-gc-xml-2
			strm (new ByteArrayInputStream (. str getBytes))
			doc (clojure.xml/parse strm)
			content-print (doc :content)]
	;; Example Input af-data:
	;;  ( {:af-tag [{:tag :minimum, :attrs {:requested_bytes 32}, :content nil}], :timestamp 1234609337000} 
    ;;    {:af-tag [{:tag :minimum, :attrs {:requested_bytes 34}, :content nil}], :timestamp 1234609397000})
	(Assert/assertNotNull (parse-gc-aftags doc))))

(defn -test_simple_reglog_regex [_] 
  (let [r *request-log-regex*
		  line "222.22.22.222 - ABCDE - [13/Feb/2009:07:33:38 -0400] \"POST /Servlet1 HTTP/1.1\" 200 - "
		  p  (octane-pattern_ r)
		  m  (. p matcher line)]
	(. m find)
	(Assert/assertTrue   "Invalid group count" (= (. m groupCount) 5))
	(Assert/assertEquals "222.22.22.222" (. m group 1))
	(Assert/assertEquals "ABCDE" (. m group 2))
	(Assert/assertEquals "13/Feb/2009:07:33:38 -0400" (. m group 3))
	(Assert/assertEquals "POST /Servlet1 HTTP/1.1" (. m group 4))
	(Assert/assertEquals "200" (. m group 5))))

(defn -test_simple_reglog_regex2 [_] 
  (let [r *request-log-regex*
		  data example-request-log
		  lines (seq (.split data *newline*))
		  pttr  (octane-pattern_ r)]
	(let [freq 
		  (keyword-frequency
		   (flatten
			(loop [all-lines lines prev-list ()]
			  (if all-lines
				(let [res (when-let [lst (build-request-list pttr all-lines)]
									(cons lst prev-list))]
				  (recur (rest all-lines) (if res res prev-list)))
				prev-list))))]
	  (Assert/assertNotNull freq))))

(defn -test_simple_reglog_regex3 [_] 
  (Assert/assertNotNull (request-frequency example-request-log)))

(defn -test_build_queryregex-list [_]
  (let [data example-query-log
			 lines (seq (.split data *newline*))]
	(let [res (loop [all-lines lines prev-list ()]
				(if all-lines
				  (let [res (when-let [lst (build-queryregex-list all-lines)]
									  (cons lst prev-list))]
					(recur (rest all-lines) (if res res prev-list)))
				  prev-list))]
	  (println (keyword-frequency (flatten res))))))
		 
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; End of Test Case
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

