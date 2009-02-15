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
	(:import (java.io InputStreamReader BufferedReader ByteArrayInputStream)))

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
	  tag)))

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
  Build a list of lists: (({:totalbytes 100663296, :freebytes 5032960, :percent 4} {:totalbytes 100663296 ..."
  [gc-tags]
  ;;;;;;;;;;;;;;;;
  (for [tag gc-tags] (get-mem-attrs (get-single-tenured-tags tag))))
	 
(defn parse-aftags-tenured
  "With the sequence of aftags, extract the tentured memory information"
  [af-data]
  ;;;;;;;;;;;  
  (let [tags (for [af-tag af-data] (af-tag :content))]
	;; Clean the output from get-tenured
	(when-let [tenr-tags (get-tenured-tags tags)]
			  ;; Extract the second element from the list of lists
			  (for [tenr-lst tenr-tags]
				(second tenr-lst)))))

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