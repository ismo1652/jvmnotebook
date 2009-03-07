;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; Copyright (c) 2006-2007 Berlin Brown and botnode.com  All Rights Reserved
;;;
;;; http://www.opensource.org/licenses/bsd-license.php

;;; All rights reserved.

;;; Redistribution and use in source and binary forms, with or without modification,
;;; are permitted provided that the following conditions are met:

;;; * Redistributions of source code must retain the above copyright notice,
;;; this list of conditions and the following disclaimer.
;;; * Redistributions in binary form must reproduce the above copyright notice,
;;; this list of conditions and the following disclaimer in the documentation
;;; and/or other materials provided with the distribution.
;;; * Neither the name of the Botnode.com (Berlin Brown) nor
;;; the names of its contributors may be used to endorse or promote
;;; products derived from this software without specific prior written permission.

;;; THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
;;; "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
;;; LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
;;; A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
;;; CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
;;; EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
;;; PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
;;; PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
;;; LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
;;; NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
;;; SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
;;;
;;; Date: 1/5/2009
;;; Main Description: Light bot is a simple IRC/Twitter bot in clojure
;;; Contact: Berlin Brown <berlin dot brown at gmail.com>
;;;
;;; Description: simple part of speech tagger library
;;;              using open-nlp (version 1.4.3)
;;;
;;;
;;; Usage:  java -Xms128m -Xmx200m -classpath $CP -Dlight.install.dir="$INSTALL_DIR" \
;;;               clojure.lang.Script src/light/toolkit/nlp/light_pos_tagger.clj
;;;
;;;
;;; Example Test.txt Input File:
;;;
;;; Hello, my name is Berlin #RESPONSE# My name is light
;;;
;;;
;;; See http://jvmnotebook.googlecode.com/svn/trunk/clojure/light_clojurebot
;;;
;;; Make sure the NLP libaries and model are in the classpath
;;; 
;;; NLP=$INSTALL_DIR/lib/opennlp
;;; NLP1=$NLP/opennlp-tools-1.4.3.jar
;;; NLP2=$NLP/trove.jar
;;; NLP3=$NLP/maxent-2.5.2.jar
;;; NLP_LIB=$NLP1:$NLP2:$NLP3
;;; 
;;; MODELS=$INSTALL_DIR/models
;;; TESTS=$INSTALL_DIR/test/example_docs
;;; DATA=$INSTALL_DIR/data
;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(ns light.toolkit.twitter.twitter_bot
  (:use light.toolkit.light_utils
		light.toolkit.nlp.light_pos_tagger)
  (:import
   (java.util.regex Matcher Pattern)
   (java.io BufferedReader InputStreamReader FileInputStream)
   (org.light.twitter Api)))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(defn twitter-bot-main
  []
  ;;;
  (println "Running twitter bot")
  (let [api (Api. "XXXXXXXXXX" "YYYY")]
	(.updateStatus api (str  "Hello, systems are operational from client => " (date-time)))
	(doseq [t (.getDirectMessages api)]
	  (println (.getText t)))
  	(doseq [z (.getFriendsTimeline api "zzzzx")]
	  (println "----")
	  (let [message (.getText z)
			response-index (build-tag-response-index (load-pos-tag *core-tag-model* "test.txt"))
			res-key (build-tag-key (pos-tag-response *core-tag-model* message))]
		(if-let [nlp-res ((keyword res-key) response-index)]
		  (.updateStatus api nlp-res)
		  (.updateStatus api *default-light-response*))
		(. Thread sleep 5000))))
  (println "Done"))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(twitter-bot-main)
  
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; End of Script
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;