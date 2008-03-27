//
// Berlin Brown
//
// $Id: NeuralTestA.java,v 1.3 2004/05/06 13:29:53 bigbinc Exp $
//
//

//        java -classpath $(CLASSPATH) Xor 5000 .1 .9 0
//        java -classpath $(CLASSPATH) Xor2 5000 .1 .9 0
//        java -classpath $(CLASSPATH) Autoasso 3 10000 .1 .9 0
//
// A: 5000, 0.1, 0.9, 0
// B: 10, 5000, 0.3, 0.9, 0
// C: 5000, 0.1, 0.9, 0
// D: 3, 10000, 0.1, 0.9, 0
//

package org.retro.gis;


import java.util.Random;

import org.retro.neural.*;
import java.util.Random;

public class NeuralTestA {

    public static void main(String [] args) {

        if (args.length < 3) {
            System.err.println("Usage: java Xor2 <epochs> <eta> <mu> " + 
                               "[seed]\n");
            System.exit(1);
        }       

        BPLayer inp = new BPLayer(2);
        BPLayer hid1 = new BPLayer(3);
        BPLayer hid2 = new BPLayer(3);
        BPLayer out = new BPLayer(1);

        hid1.connect(inp);
        out.connect(hid2);
        hid2.connect(hid1);

        double [][] x = {
	    {  0,0  }, 
	    {  0,1  }, 
	    {  1,0  }, 
	    {  1,1  }
	};

        double [][] y = {
	    {  0  },  
	    {  1  },   
	    {  1  },   
	    {  0  }
	};

        Random r =  (args.length > 3) ? 
            new Random(Long.parseLong(args[3])) : new Random();

        hid1.randomize(r);
        hid2.randomize(r);
        out.randomize(r);

        int nep = Integer.parseInt(args[0]);
        double eta = Double.parseDouble(args[1]);
        double mu = Double.parseDouble(args[2]);

        inp.attach(x);
        out.attach(y);
        out.batch(nep, eta, mu);

        double [][] yy = out.test();
        System.out.println();
        for (int i=0; i<yy.length; ++i) {
            for (int j=0; j<yy[i].length; ++j) {
                System.out.print(yy[i][j] + " ");
            }
            System.out.println();
        }
    } // end of the method ...

} // end of the class ..................
