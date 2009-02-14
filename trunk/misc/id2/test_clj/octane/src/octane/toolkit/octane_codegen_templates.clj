;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; Copyright (c) ....:. All rights reserved.
;;;
;;; Copyright (c) 2006-2007, 

;;; All rights reserved.

;;; Redistribution and use in source and binary forms, with or without modification,
;;; is NOT permitted.
;;; PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.

;;;
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

(ns octane.toolkit.octane_codegen_templates)

(def *codegen-templ-build-xml*
"<?xml version=\"1.0\" encoding=\"UTF-8\"?>
<!-- ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; -->
<!-- Copyright (c) 2009 -->
<!-- Code generated Ant Script -->
<!-- ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; -->
<project name=\"Build File\" default=\"package\" basedir=\".\">
    <property file=\"build.properties\" /> 
    <property name=\"build.dir\"            value=\"${basedir}/build\"/>
    <property name=\"build.classes.dir\"    value=\"${basedir}/build/classes\"/>
    <property name=\"src.dir\"              value=\"${basedir}/src\"/>
    <property name=\"lib.dir\"              value=\"${basedir}/lib\"/>

<target name=\"help\" description=\"Initialization\">
            <tstamp/>
            <echo>
 Additional Targets and Usage:
 -----------------
 compile - to compile the source, use this target.  
           To build the  complete release package, 
           you must compile this manually.

</echo>
    </target>    
    

    <path id=\"classpath\">
    </path>


    <!-- ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; -->
    <!-- Target: Prepare -->
    <!-- ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; -->
    <target name=\"prepare\" depends=\"help\">
        <mkdir dir=\"${build.dir}\"/>
        <mkdir dir=\"${build.classes.dir}\"/>
    </target>

    <!-- ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; -->
    <!-- Target: Compile -->
    <!-- ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; -->
    <target name=\"compile\" depends=\"prepare\">
        <javac deprecation=\"true\"
                target=\"1.5\"
                srcdir=\"${src.dir}\"
                destdir=\"${build.classes.dir}\"
                includes=\"**/*.java\">
            <classpath refid=\"classpath\"/>
            <compilerarg value=\"\" />
        </javac>
    </target>

    <!-- ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; -->        
    <!-- Target: Build -->
    <!-- ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; -->
    <target name=\"package\" depends=\"prepare\">
    </target>
   
    <!-- ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; -->
    <!-- Main Clean -->
    <!-- ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;; -->
    <target name=\"clean\">
        <delete dir=\"${build.dir}\" />
    </target>

</project>
")


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; End of Script
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;      