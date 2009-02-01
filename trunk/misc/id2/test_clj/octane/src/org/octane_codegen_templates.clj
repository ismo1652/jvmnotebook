;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;; Copyright (c) ... Brown:. All rights reserved.
;;;
;;; Copyright (c) 2006-2007, Botnode.com, ... Brown
;;; http://www.opensource.org/licenses/bsd-license.php

;;; All rights reserved.

;;; Redistribution and use in source and binary forms, with or without modification,
;;; are permitted provided that the following conditions are met:

;;;    * Redistributions of source code must retain the above copyright notice,
;;;    this list of conditions and the following disclaimer.
;;;    * Redistributions in binary form must reproduce the above copyright notice,
;;;    this list of conditions and the following disclaimer in the documentation
;;;    and/or other materials provided with the distribution.
;;;    * Neither the name of the Botnode.com (... Brown) nor
;;;    the names of its contributors may be used to endorse or promote
;;;    products derived from this software without specific prior written permission.

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