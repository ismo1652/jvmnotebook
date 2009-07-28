/********************************************************************
 *
 * Copyright (c) 2006-2007 Berlin Brown and botnode.com  All Rights Reserved
 *
 * http://www.opensource.org/licenses/bsd-license.php

 * All rights reserved.

 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:

 * * Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 * * Neither the name of the Botnode.com (Berlin Brown) nor
 * the names of its contributors may be used to endorse or promote
 * products derived from this software without specific prior written permission.

 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Date: 1/5/2009
 *       7/15/2009 - Added Clojure 1.0, other performance fixes and cleanups.
 *       
 * Main Description: Light Log Viewer is a tool for making it easier to search log files.  
 * Light Log Viewer adds some text highlighting, quick key navigation to text files, simple graphs 
 * and charts for monitoring logs, file database to quickly navigate to files of interest, 
 * and HTML to PDF convert tool.  
 * Light Log was developed with a combination of Clojure 1.0, Java and Scala with use of libs, SWT 3.4, JFreeChart, iText. 
 * 
 * Quickstart : the best way to run the Light Log viewer is to click on the win32 batch script light_logs.bat
 * (you may need to edit the Linux script for Unix/Linux environments).
 * Edit the win32 script to add more heap memory or other parameters.
 * 
 * The clojure source is contained in : HOME/src/octane
 * The java source is contained in :  HOME/src/java/src
 * 
 * To build the java source, see : HOME/src/java/build.xml and build_pdf_gui.xml
 * 
 * Metrics: (as of 7/15/2009) Light Log Viewer consists of 6500 lines of Clojure code, and contains wrapper code
 *  around the Java source.  There are 2000+ lines of Java code in the Java library for Light Log Viewer.
 *  
 * Additional Development Notes: The SWT gui and other libraries are launched from a dynamic classloader.  Clojure is also
 *   started from the same code, and reflection is used to dynamically initiate Clojure. See the 'start' package.  The binary
 *   code is contained in the octane_start.jar library.
 *   
 * Home Page: http://code.google.com/p/lighttexteditor/
 * 
 * Contact: Berlin Brown <berlin dot brown at gmail.com>
 *********************************************************************/

package org.node.perf.util;

import java.io.BufferedReader;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Random;
import java.util.Set;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * @author Berlin
 * @version $Revision: 1.0 $
 */
public class StringUtils {

    /**
     * Field NL.
     */
    public static final char NL = '\n';

    /**
     * Field EMPTY.
     * (value is """")
     */
    public static final String EMPTY = "";
    
    public static final Integer ONE = new Integer(1);
    
    public static final Random rand = new Random(System.currentTimeMillis()); 
    
    /**
     * Generate a random string of characters.
     */
    public static final String randomString(final Random random, final int n) {

/*
 * In Clojure, this code might look like:
 ----------------------------------------- 
(defn random-string_
  "Generate a random string of characters"
  [#^java.util.Random random n]
  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
  (let [buf (StringBuffer. (+ n 16))]
    (dotimes [_ n]
        (.append buf (char (+ 97 (.nextInt random 26)))))
    (.toString buf)))

(defn random-string
  "Generate a random string of characters"
  [n]
  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
  (random-string_ (java.util.Random.) n))
 */
        
        final StringBuffer buf = new StringBuffer(n + 16);
        for (int i = 0; i < n; i++) {
            final char c = (char)('a' + random.nextInt(26));
            buf.append(c);        
        } // End of the for //
        return buf.toString();
    }

    public static String buildSplitStr(int sz, int n, String delim, String postfix) {
    /*
    (defn build-split-str
            "Build a string that can separated by a '|' char"
            [sz n]
            ;;;
            (let [str-size (* 1 sz)
                  buf-1 (StringBuffer. (* str-size n))]
              (dotimes [_ n]
                  (let [b (random-string str-size)]
                    (.append buf-1 (str b "|"))))
              (.append buf-1 "[END]")
              (.toString buf-1)))
     */
        final StringBuffer buf1 = new StringBuffer(sz * n);
        String b = "";
        for (int i = 0; i < n; i++) {
            b = randomString(sz);
            buf1.append(b).append(delim);
        } // End of For //
        buf1.append(postfix);
        return buf1.toString();
    }
    
    public static final String join(final String sep, final String [] seq) {
        
        final StringBuffer buf = new StringBuffer(40);
        for (int i = 0; i < seq.length; i++) {
            buf.append(seq[i]);
        }
        return buf.toString();
        
    }
        
    public static Map frequencies(final List list) {
        final Map map = new HashMap();
        // Simple Box and then unbox the count as the value for this map //
        for (Iterator it = list.iterator(); it.hasNext(); ) {
            final Object o = it.next();
            final String s = o.toString();
            Integer prev = (Integer) map.get(s);
            if (prev == null) {
                // Put a new value on th map
                final Integer count = ONE;
                map.put(s, count);
            } else {
                final Integer inc = new Integer(prev.intValue() + 1);
                map.put(s, inc);
            } // End of the if - else //                       
        }
        return map;
    }
    
    public static void printMap(final Map map) {
        Set set = map.entrySet();        
        for (Iterator it = set.iterator(); it.hasNext();) {
            Map.Entry e = (Map.Entry) it.next();
            System.out.println("{Map} Key: " + e.getKey() + " | Value: " + e.getValue()); 
        }    
    }
    
    public static void printList(final List list) {               
        for (Iterator it = list.iterator(); it.hasNext();) {
            final Object o = it.next();
            System.out.println("{List} " + o);  
        }
    }
    public static void checkList(final List list) {
        int i = 0;
        for (Iterator it = list.iterator(); it.hasNext();) {
            final Object o = it.next();
            System.out.println("{List} " + o);
            i++;
            if (i >= 6) {
                return;
            }            
        }
    }
    
    /**
     * Print a consolidated/small view of the map.  Only print the first 8 entries.
     * @param map
     */
    public static void checkMap(final Map map) {
        int index = 0;
        Set set = map.entrySet();        
        for (Iterator it = set.iterator(); it.hasNext();) {
            Map.Entry e = (Map.Entry) it.next();
            System.out.println("{Map} Key: " + e.getKey() + " | Value: " + e.getValue());
            index++;
            if (index >= 8) {
                break;
            }
        }
        System.out.println("...");
    }
    
    public static void checkMap2(final Map map) {
        int index = 0;
        Set set = map.entrySet();        
        for (Iterator it = set.iterator(); it.hasNext();) {
            Map.Entry e = (Map.Entry) it.next();
            System.out.println("{Map} Key: " + e.getKey() + " | Value: " + e.getValue());
            index++;
            if (index >= 2) {
                break;
            }
        }
        System.out.println("...");
    }
    
    /**
     * Generate a random string of characters.
     */
    public static final String randomString(final int n) {
        return randomString(rand, n);
    }
    
    /**
     * Implementation Routine trim.
     * @param val String
     * @return String
     */
    public static final String trim(final String val) {
        return (null == val) ? EMPTY : val.trim();        
    }

    /**
     * Implementation Routine empty.
     * @param val String
     * @return boolean
     */
    public static final boolean isEmpty(final String val) {
        return ((null == val) || (0 == val.length()));

    }

    /**
     * Implementation Routine notEmpty.
     * @param val String
     * @return boolean
     */
    public static final boolean isNotEmpty(final String val) {
        return !isEmpty(val);
    }
      
    /**
     * Implementation Routine filterTermBuffer.
     * @param inBuffer String
     * @param term String
     * @param formatType int
     * @return String
     * @throws IOException
     */
    public static final String filterTermBuffer(final String inBuffer, final String term, int formatType) throws IOException {
        
        if (isEmpty(term)) {
            return inBuffer;
        }
                            
        // given the search term, filter the lines that contain that term //
        // Use memory stream
        final ByteArrayInputStream stream = new ByteArrayInputStream(inBuffer.getBytes());
        final BufferedReader reader = new BufferedReader(new InputStreamReader(stream));
        final StringBuffer mainBuf = new StringBuffer(512);
        final Pattern pattern = Pattern.compile(term);
        try {                        
            String data = "";
            int lineNumber = 1;            
            do {                
                data = reader.readLine();
                if (data != null) {
                    final Matcher match = pattern.matcher(data);
                    if (match.find()) {
                        mainBuf.append(lineNumber).append(':');
                        mainBuf.append(data);
                        mainBuf.append('\n');
                    }
                }
                lineNumber++;
            } while(data != null);
            
        } finally {           
            if (reader != null) {
                try {
                    reader.close();
                } catch (IOException e) { 
                    ;
                }
            } // End of the if //
            
            if (stream != null) {
                stream.close();
            }
        } // End of Finally //
        
        return mainBuf.toString();
    }
    
    /////////////////////////////////////////////////////////////////
    
    /**
     * Concenate a sequence of strings together.
     * 
     * @param str1in String
     * @param str2in String
     * @return String
     */
    public static final String concat(final String str1in, final String str2in) {
        final String str1 = str1in == null ? EMPTY : str1in;
        final String str2 = str2in == null ? EMPTY : str2in;
        final StringBuffer buf = new StringBuffer(str1.length()+str2.length());
        buf.append(str1);
        buf.append(str2);        
        return buf.toString();
    }
    
    /**
     * Concenate a sequence of strings together.
     * 
     * @param str1in String
     * @param str2in String
     * @param str3in String
     * @return String
     */
    public static final String concat(final String str1in, final String str2in, final String str3in) {
        final String str1 = str1in == null ? "" : str1in;
        final String str2 = str2in == null ? "" : str2in;
        final String str3 = str3in == null ? "" : str3in;
        final StringBuffer buf = new StringBuffer(str1.length()+str2.length()+str3.length());
        buf.append(str1);
        buf.append(str2);
        buf.append(str3);
        return buf.toString();
    }
    
    /**
     * Concenate a sequence of strings together.
     * 
     * @param str1in String
     * @param str2in String
     * @param str3in String
     * @param str4in String
     * @return String
     */
    public static final String concat(final String str1in, final String str2in, final String str3in, final String str4in) {
        final String str1 = str1in == null ? "" : str1in;
        final String str2 = str2in == null ? "" : str2in;
        final String str3 = str3in == null ? "" : str3in;
        final String str4 = str4in == null ? "" : str4in;
        final StringBuffer buf = new StringBuffer(str1.length()+str2.length()+str3.length()+str4.length());
        buf.append(str1);
        buf.append(str2);
        buf.append(str3);
        buf.append(str4);
        return buf.toString();
    }
    
    
} // End of the Class //
