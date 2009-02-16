;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; Copyright (c) ....:. All rights reserved.
;;;
;;; Copyright (c) 2006-2007, 

;;; All rights reserved.

;;; Redistribution and use in source and binary forms, with or without modification,
;;; is NOT permitted.
;;; PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
;;;
;;; Date:  1/5/2009
;;; Description:
;;;     Simple 'Find' keyword in File with SWT and Clojure
;;; Contact:  ... Brown <berlin dot brown at gmail.com>
;;; Usage:   java -cp $CP clojure.lang.Repl src/octane_main.clj
;;;          Enter a search term and then open a file, if the term
;;;          is found on the line then the line will be higlighted.

;;; Key Functions: simple-swt create-file-menu
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(ns octane.toolkit.ws_garbage_collection
	(:use octane.toolkit.octane_utils)
	(:import 
	 (java.text SimpleDateFormat)
	 (java.io InputStreamReader BufferedReader ByteArrayInputStream)))

(defn parse-timestamp-date
  "Return the long representation for the timestamp"
  [str-date]
  ;;;;;;;;;;;;;;;  
  (let [sdf (new SimpleDateFormat "MMM d HH:mm:ss yyyy")]
	(try (. (. sdf parse str-date) getTime)
		 (catch Exception e (println "Warn: invalid date format =>" str-date)
				str-date))))

(defn get-timestamp-attr
  "Get the timestamp attributes from the 'af' tag
 Extract from : :attrs {:id 1, :type tenured, :timestamp

 Example Test Case:
 {:tag :af, :attrs {:timestamp 'Feb 14 06:02:17 2009', :id 1 }}]
	(Assert/assertEquals 'Feb 14 06:02:17 2009' (get-timestamp-attr data))))"
  [af-tag]
  ;;;;;;;;;;;;
  (let [attrs (af-tag :attrs) tstamp (attrs :timestamp)]
	tstamp))

(defn parse-gc-aftags
  "The XML document is loaded into the clojure datastructure.  Parse the
 document to extract the relevant memory content"
  [xml-doc]
  ;;;;;;;;;;;;;;
  (let [af-tag-data (xml-doc :content)]
	(for [tag af-tag-data
			  :when
			  (and (= clojure.lang.PersistentStructMap (class tag))
				   (= ":af" (str (tag :tag))))]
	  ;; Build a datastructure with the relevant information
	  ;; {:af-tag 'The Tag Data' :timestamp ...
	  { :af-tag (tag :content) :timestamp (parse-timestamp-date (get-timestamp-attr tag)) })))

(defn get-mem-attrs
 " Get the memory data from the attributes gc/tenured
 Example:: {:tag :tenured, :attrs {:percent 4, :freebytes 5032960, :totalbytes 100663296},..."
 [tenure-data]
 ;;;;;;;;;;;;;;
 (for [tenured tenure-data] (tenured :attrs)))

(defn get-single-tenured-tags
  "There are normally two 'tenured' tags, loop and extract them and build a list."
  [single-gc-tags]
  ;;;;;;;;;;;;;;;;
  (for [inner-tenr-tag single-gc-tags
					   :when
					   (and (= clojure.lang.PersistentStructMap (class inner-tenr-tag))
							(= ":tenured" (str (inner-tenr-tag :tag))))]
	inner-tenr-tag))

(defn get-tenured-tags
  "There are normally two 'tenured' tags, loop and extract them and build a list.
  Build a list of struct of structs with : {:memory {:totalbytes, etc} :timestamp 12312 }"
  [gc-tags-data]
  ;;;;;;;;;;;;;;;;
  (when gc-tags-data
	;; Loop through each one of the 'af tags' and only collect
	;; the 'tenured' data.
	(for [pre-tag gc-tags-data]
	  (let [af-content-data (pre-tag :af-content)
							tstamp (pre-tag :timestamp)
							single-tenr (get-single-tenured-tags af-content-data)]
		{:memory (get-mem-attrs single-tenr) :timestamp tstamp } ))))

(defn build-all-af-util
  "Utility function, loop and then extract the relevant AF content. Return a list of structs."
  [af-structs-data]
  ;;;;;;;;;;;;;;;;;
  (for [af-tag af-structs-data]
	  (let [my-af-tag (af-tag :af-tag) tstamp (af-tag :timestamp)]
		{ :af-content my-af-tag :timestamp tstamp } )))
   
(defn parse-aftags-tenured
  "With the sequence of aftags, extract the tentured memory information.
  Example Input af-data:
  ( {:af-tag [{:tag :minimum, :attrs {:requested_bytes 32}, :content nil}], :timestamp 1234609337000} 
    {:af-tag [{:tag :minimum, :attrs {:requested_bytes 34}, :content nil}], :timestamp 1234609397000})"
  [af-structs-data]
  ;;;;;;;;;;
  (let [tags (build-all-af-util af-structs-data)]
	;; Clean the output from get-tenured
	(when-let [tenr-tags (get-tenured-tags tags)]
			  ;; Extract ONLY the second element from the list of lists			  
			  ;; tenr-tags has the following datastructure:
			  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
			  ;; {:timestamp 1234617924000, 
              ;;  :memory ({:totalbytes 116293120, :freebytes 11632, :percent 0} 
              ;;              {:totalbytes 116293120, :freebytes 47940784, :percent 41})}
			  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
			  (for [my-mem-data tenr-tags]
				(let [mem-lst (my-mem-data :memory)]
				  ;; Memory list is a list, we only want the second element.
				  {:timestamp (my-mem-data :timestamp) :memeory (second mem-lst) } )))))
			  
(defn load-native-gc-xml
  "Load the garbage collection xml document, native_stderr.log.
 Extract the XML memory data after the 'gc/garbage collection' tag.
 @return List of data point values {:totalbytes 100663296, :freebytes 88476392, :percent 87} ..."
  [xml-str]
  ;;;;;;;;;;;;;;;
  (when xml-str
	(let [strm (new ByteArrayInputStream (. xml-str getBytes))]
	  (when-let [xml-data (when-try (clojure.xml/parse strm))]
				(parse-aftags-tenured (parse-gc-aftags xml-data))))))
				
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; End of Script
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;