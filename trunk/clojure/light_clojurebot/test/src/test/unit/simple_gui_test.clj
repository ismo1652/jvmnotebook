;;; -------------------------------------------------------
;;; Copyright (c) Berlin Brown:. All rights reserved.
;;;
;;; Copyright (c) 2006-2007, Botnode.com, Berlin Brown
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
;;; File: OctaneSampleTestGen.clj
;;;
;;; Date: 1/5/2009
;;; Description: Clojure JUnit Test Suite
;;; Environment:
;;;       Tested with junit-4.4, clojure_200812.jar
;;; Usage:
;;; java -Xms128m -Xmx200m -classpath $CP -Doctane.install.dir="$INSTALL_DIR" clojure.lang.Repl main_gen_tests.clj
;;; java -Xms128m -Xmx200m -classpath $CP -Doctane.install.dir="$INSTALL_DIR" test.OctaneTestSuite 

;;; -------------------------------------------------------

(ns test.unit.simple_gui_test
  (:use
   light.toolkit.light_gui_utils
   light.toolkit.public_objects)
  (:import 
   (junit.framework Assert)
   (org.jibble.pircbot PircBot))
  (:gen-class
   :extends junit.framework.TestCase
   :methods 
   [
	[ testSimpleGUICheck [] void ]
	[ testCreateGridLayout [] void ]
	[ testInitColorVec [] void ]
	[ testPublicObjects [] void ]
	]))

(defn -init [_] ())
	   
(defn -testSimpleGUICheck [_]
  (let [gl (create-grid-layout 1)]
	(Assert/assertEquals 1 (. gl numColumns))))

(defn -testCreateGridLayout [_]
  (let [gl (create-grid-layout 1)]
	(Assert/assertEquals 1 (. gl numColumns))))

(defn -testInitColorVec [_]
  (init-color-vec-colors)
  (Assert/assertTrue (> (count colors-vec) 7)))

(defn -testPublicObjects [_]
  (Assert/assertNotNull *shell*)
  (Assert/assertNotNull *display*)
  (Assert/assertNotNull *styled-text*))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; End of Test Case
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

