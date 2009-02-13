;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; Copyright (c) ....:. All rights reserved.
;;;
;;; Copyright (c) 2006-2007, 

;;; All rights reserved.

;;; Redistribution and use in source and binary forms, with or without modification,
;;; is NOT permitted.
;;; PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.

;;; Date:  1/5/2009
;;; Description:
;;;     Simple 'Find' keyword in File with SWT and Clojure
;;; Contact:  ... <... dot brown at gmail.com>
;;; Usage:   java -cp $CP clojure.lang.Repl src/octane_main.clj
;;;          Enter a search term and then open a file, if the term
;;;          is found on the line then the line will be higlighted.

;;; Key Functions: simple-swt create-file-menu
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(in-ns 'octane)

(import '(org.eclipse.swt SWT))
(import '(org.eclipse.swt.widgets Display Shell Text Widget TabFolder TabItem))
(import '(org.eclipse.swt.widgets Label Menu MenuItem Control Listener))
(import '(org.eclipse.swt.widgets FileDialog MessageBox TableItem Button
                                  Composite Table TableColumn))

(import '(org.eclipse.swt.custom LineStyleEvent StyledText
                                 LineStyleListener StyleRange))

(import '(org.eclipse.swt.graphics Color RGB FontData Font))
(import '(org.eclipse.swt.layout GridData GridLayout RowLayout RowData))
(import '(org.eclipse.swt.events VerifyListener SelectionAdapter ModifyListener SelectionListener
                                 SelectionEvent ShellAdapter ShellEvent))
(import '(java.util.regex Pattern))
;;(import '(org.eclipse.jface.text.source LineNumberRulerColumn))

;;; End of Script