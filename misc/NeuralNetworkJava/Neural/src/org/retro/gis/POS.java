package org.retro.gis;

import java.util.Random;

import org.retro.neural.*;
import java.util.Random;

import java.util.*;
import javax.swing.*;
import java.awt.event.*;
import java.awt.*;
import java.awt.geom.Point2D;
import java.text.*;

import java.io.*;


public abstract class POS {

    private final static int NHID = 8;            // hidden units
    private static final int NEP = 1760;            // epochs
    private static final double ETA = 0.20;        // learning rate

    private final static int CHUNK_SIZE = 1024; // file input chunk size
    private final static int MAX_WORD = 10;     // max word length for output

    protected POS(String filename) {


	//
        // [ 1 ] read words from file
	// [ 2 ] put words into 1-in-N dictionary table
	// [ 3 ] put 1-in-N codes into input matrix, one row per word
	// [ 4 ] create SRN with input sufficient to encode all 1-in-N words
	// [ 5 ] initialize SRN with random weights and train it on input
	//
        String [] words = read_words(filename);

	System.out.println("Number of Words --------> " + words.length);
        
        Hashtable oneInN = hash_words(words);        
        double [][] input = make_input(words, oneInN);

	System.out.println(" [ HashMap Size  --------> " + words.length);
	System.out.println(" [ Input         --------> " + input.length);
	System.out.println(" [ One - To - N  --------> " + oneInN.size());
	System.out.println(" [ Number Hidden --------> " + NHID);


        SRN srn = new SRN(oneInN.size(), NHID);
        System.err.println("Training SRN...");
        
        srn.randomize();
        srn.train(input, NEP, ETA, 1);

	// [ get keys --> get the string 'back' from the organized map ]
        String [] keys = get_keys(oneInN);
        double [][] hidden = get_hidden(srn, keys, oneInN);

	System.out.println(" Returned hidden size[rows]: ---> " + hidden.length);
	System.out.println(" Returned hidden size[cols]: ---> " + hidden[0].length);

	int w;
	int v;
	NumberFormat _nf = NumberFormat.getInstance();
	_nf.setMaximumFractionDigits(2);
	
	System.out.println("....................................");
	for (w = 0; w < hidden.length; w++) {

	    for (v = 0; v < hidden[w].length; v++) {
		System.out.print(" || " + _nf.format(hidden[w][v]));
	    } // end of the inner for...
	    System.out.println();

	} // end of outer for...
	System.out.println("....................................");

	

	// --------------------------------------------------------
        
	//
	// [ See Impl: ]
	//
	// { SOM som = new SOM(hidden, N, N);               }
        // {  som.learn(E_I, E_F, SIGMA_I, SIGMA_F, TMAX);  }
	//
	
	// --------------------------------------------------------
	
        Map2D map = getMap(hidden);
        int [][] units = map.getUnits();

	System.out.println("------------------------------------");
	System.out.println("ROWS(units): " + units.length);
	System.out.println("COLS(units): " + units[0].length);
	for (w = 0; w < units.length; w++) {

	    for (v = 0; v < units[w].length; v++) {
		System.out.print(" || " + _nf.format(units[w][v]));
	    } // end of the inner for...
	    System.out.println();

	} // end of outer for...
	System.out.println("------------------------------------");

        String [][] display = make_display(map, keys, units);

	double vector [];
	double grid [][][];

	// 2d grid of vectors
	grid = map.getWeights();

	
	System.out.println("------------------------------------");
	for (w = 0; w < grid.length; w++) {
	    
	    for (v = 0; v < grid[w].length; v++) {

		vector = grid[w][v];
		System.out.print(" " + vector.length);
		
		for (int bb = 0; bb < vector.length; bb++) {
		    System.out.print("[" +_nf.format(vector[bb]) + "]");
		} // end of the inner inner

	    } // end of the inner for...
	    System.out.println();

	} // end of outer for...
	System.out.println("------------------------------------");

       
        show(display);

    } // end of the method .....

    protected abstract Map2D getMap(double [][] hidden);

    private static String [][] make_display(Map2D map, 
                                            String [] keys, int [][] units) {
        String [][] display = 
            new String [map.getRowDimension()][map.getColumnDimension()];

        for (int i=0; i < units.length; ++i) {
	    
            
	    // ...... get [ROW][COL]
	    int x = units[i][0];
	    int y = units[i][1];

	    // [java]  || 0 || 2   [ 1 ]
	    // [java]  || 0 || 2   [ 2 ]
	    // [java]  || 0 || 2   [ 3 ]
	    // [java]  || 0 || 0   [ 4 ]
	    // [java]  || 0 || 2   [ 5 ]
	    // [java]  || 0 || 5   [ 6 ]
	    // [java]  || 2 || 1   [ 7 ]
	    
	    // is this reversed?
            display[x][y] = keys[i];

        } // end of the for ....

        return display;
    } // end of the method ........

    private static void show(String [][] map) {
	
        int N1 = map.length, N2 = map[0].length;

	System.out.println(" N1: --> " + N1);
 	System.out.println(" N2: --> " + N2);

        for (int i=0; i < N1; ++i) {

            System.out.println();
            for (int j=0; j < N2; ++j) {
		
                if (map[i][j] == null) {

                    System.out.print("*");
                    dump_spaces(MAX_WORD-1);

                } else {
                
                    String word = map[i][j];
                    System.out.print(word);

                    int skip = MAX_WORD - word.length();        
                    dump_spaces(skip);

                } // end of the if - else


            } // end of the for ...


            System.out.println();

        } // end of the for ....

    } // end of the method .........................

    private static void dump_spaces(int n) {

        for (int i=0; i<n; ++i) {
            System.out.print(" ");
        } // end of the for ...

    } // end of the method ...


    // read words from named file
    private static String [] read_words(String fname) {

        String s = new String();

        // read file chunks into string until EOF
        try {
            FileInputStream fis = new FileInputStream(fname);
            while (true) {        
                byte [] chunk = new byte[CHUNK_SIZE];
                int nread = fis.read(chunk);
                s += new String(chunk, 0, nread);
                if (nread < CHUNK_SIZE) break;
            }
        }        
        catch (Exception e) {
            System.err.println(e);
            System.exit(1);
        } // end of try - catch

        // tokenize string, ignoring punctuation
        StringTokenizer st = new StringTokenizer(s, ".,;: \n");
        String [] w = new String [st.countTokens()];
	
        for (int i=0; st.hasMoreTokens(); i++) {
            w[i] = st.nextToken();
        } // end of the for 

        return w;
    } // end of the method ..........

    private static Hashtable hash_words(String [] words) {

        Hashtable h = new Hashtable();
        int n = 0;

        for (int i=0; i < words.length; ++i) {

            if (!h.containsKey(words[i])) {

		//...................................................
		//
		// [ we are just putting the number in there ]
		//
		// [ basically the number that it occurs at ]
		//...................................................

                h.put(words[i], new Integer(n++));

            } // end of the if ........

        } // end of the for .....

        return h;

    } // end of the method .....

    private static double [][] make_input(String [] words, Hashtable oneInN) {

	
	// 15 different words?
	// [java] Number of Words --------> 4698
	// [java]  [ ROW ] x [ COL ]
	// [java]  (double) (words.length)rows: 4698
	// [java]  (double) (oneInN.size)cols: 15
	// [java]  [ HashMap Size  --------> 4698
	// [java]  [ Input         --------> 4698
	// [java]  [ One - To - N  --------> 15
	// [java]  [ Number Hidden --------> 5
	//

	System.out.println(" [ ROW ] x [ COL ] ");
	System.out.println(" (double) (words.length)rows: " + words.length);
	System.out.println(" (double) (oneInN.size)cols: " + oneInN.size());

        double [][] a = new double [words.length][oneInN.size()];

        for (int i=0; i < words.length; ++i) {

	    
	    // [ what are we putting in this long row ]

            Integer n = (Integer)oneInN.get(words[i]);
            a[i][n.intValue()] = 1;

        } // end of the for .........

        return a;
    } // end of the method ......

    //
    // [ on the post processing part, get our results from SOM
    //
    private static double [][] get_hidden(SRN srn, String [] keys,
                                         Hashtable oneInN) {

        double [][] hidden = new double [oneInN.size()][];

	// keys = 4900

        for (int i=0; i < keys.length; ++i) {
	    

	    // [ tall ]

            String key = keys[i];
            Integer n = (Integer)oneInN.get(key);

	    // [  n = 320 ]
           
            double [] input = new double [oneInN.size()];
            input[n.intValue()] = 1;

	    // [ it can only have one value ]
            
            hidden[i] = srn.getHidden(input);

        } // end of the for .....

        return hidden;
    
    } // end of the method .........


    private static String [] get_keys(Hashtable h) {

        String [] keys = new String [h.size()];

        int i = 0;

        for (Enumeration e = h.keys() ; e.hasMoreElements() ;) {

	    
	    String el = (String)e.nextElement();
	    System.out.println("Key... " + el + " :: " + i);

            keys[i++] = el;	    

        } // end of the for ....

        return keys;
    } // end of the method ......

} // end of the class ....
