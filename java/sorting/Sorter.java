///
/// JNI example
/// Also see: http://www3.ntu.edu.sg/home/ehchua/programming/java/JavaNativeInterface.html
/// Bridge between low-level C/C++ and Java 
/// Berlin Brown 

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.text.ParseException;
import java.io.BufferedOutputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Random;

public class Sorter {

    public native void sort(final String path);

    static {
        System.loadLibrary("sort");
    }

    private final static Random rand = new Random();

    public void rand(final PrintWriter out, final int ct) {
        for (int i = 0; i < ct; i++) {
            final int r = (rand.nextInt(100000)) + 0; 
            out.println(String.valueOf(r));
        }
    }

    public void writeDataFile(final String file, final int count) {
        System.out.println("Writing random number data file " + file);
        BufferedOutputStream bos = null;
        PrintWriter out = null;
        try {
            bos = new BufferedOutputStream(new FileOutputStream(file));
            out = new PrintWriter(bos);
            rand(out, count);
            out.flush();
        } catch(final Exception e) {
            e.printStackTrace();
        } finally {
            if (bos != null) {
                try {
                    bos.flush();
                    bos.close();
                } catch(IOException ioe) { }
            }
        }         
    }
    public static void main(final String [] args) throws Exception {
        System.out.println("Running sorter, launch native");
        final Sorter sorter = new Sorter();
        final int sz = 80000;
        final int brute = sz * sz;
        final int nlogn = sz * (int) Math.log(sz);
        System.out.println("Average : " + nlogn + " Brute : " + brute);
        sorter.writeDataFile("./numbers.dat", sz);
        sorter.sort("./numbers.dat");
        System.out.println("Done");
    }

} // End of the class // 
