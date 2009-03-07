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

(ns light.toolkit.irc.irc_client
  (:use light.toolkit.irc.irc_command_handler
		light.toolkit.irc.irc_nlp_handler)
  (:import 
   (org.jibble.pircbot PircBot)))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(def *default-server*   "irc.freenode.net")
(def *default-bot-nick* "lightbot")
(def *default-channel*  "#botwar")

(def new-bot-handler
	 (proxy [PircBot] []
	   (onMessage [channel sender login hostname message]
				  (nlp-on-message this channel sender login hostname message))
	   (onPrivateMessage [channel sender login hostname message]
						 (nlp-on-message this channel sender login hostname message))))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(defn bot-client-main
  []
  ;;;;
  (let [bot new-bot-handler]
	(.setVerbose bot true)
	(.connect bot     *default-server*)
	(.changeNick bot  *default-bot-nick*)
	(.joinChannel bot *default-channel*)))

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; End of Script
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;