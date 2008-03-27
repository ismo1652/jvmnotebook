//
// Berlin Brown
//
// $Id: NeuralTestC.java,v 1.3 2004/05/06 13:29:53 bigbinc Exp $
//
//

package org.retro.gis;

import org.retro.neural.*;
import java.util.Random;

public class NeuralTestC {

    public static void main(String [] args) {

        double [] zero = {0,1};
        double [] one  = {1,0};
        double [][] a = {zero, zero, one, one};
        double [][] b = {zero, one, zero, one};
        double [][] c = {zero, one, one, zero};

        if (args.length < 3) {
            System.err.println("Usage: java XorSP <epochs> <eta> <mu> [seed]");
            System.exit(1);
        }
        
        int nep = Integer.parseInt(args[0]);
        double eta = Double.parseDouble(args[1]);
        double mu = Double.parseDouble(args[2]);

        BPLayer i1 = new BPLayer(2);
        BPLayer i2 = new BPLayer(2);
        BPLayer o = new BPLayer(2);
        
        o.connect(i1, i2);

        if (args.length > 3) 
            o.randomize(Long.parseLong(args[3]));
        else
            o.randomize();

        i1.attach(a);
        i2.attach(b);

        o.attach(c);
        o.batch(nep, eta, mu, 100);

        double [][] yy = o.test();

        System.out.println();
        for (int i=0; i<yy.length; ++i) {
            for (int j=0; j<yy[i].length; ++j) {
                System.out.print(yy[i][j] + " ");
            }
            System.out.println();
        }
    } // end of the method ...


} // end of the of the method  ...
