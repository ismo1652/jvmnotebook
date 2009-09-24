package org.sun.javap.test;

import java.io.InputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Vector;

import com.ca.apps.debugdev.javap.JavapEnvironment;
import com.ca.apps.debugdev.javap.JavapPrinter;

/**
 * Entry point for javap, class file disassembler.
 */
public class Test1Main {
    
    public static final String VERSION = "0000000000001";
    
    private final Vector classList = new Vector();

    private PrintWriter out;

    private final JavapEnvironment env = new JavapEnvironment();

    private static boolean errorOccurred = false;

    private static final String progname = "javap";

    public Test1Main(PrintWriter out) {
        this.out = out;
    }

    public static void main(String argv[]) {
        System.out.println("Running Disassembly");
        entry(argv);
        if (errorOccurred) {
            System.exit(1);
        }
    }

    /**
     * Entry point for tool if you don't want System.exit() called.
     */
    public static void entry(String argv[]) {
        
        final PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
        try {

            Test1Main jpmain = new Test1Main(out);
            jpmain.perform();

        } finally {
            out.close();
        } // End of the try - Catch Finally //
        
    }

    /**
     * Process the arguments and perform the desired action
     */
    private void perform() {
        
        final String classNameParm = "com/ca/apps/debugdev/javap/test/Test1Main.class";
        
        this.env.setShowVerbose(true);        
        this.env.setShowDisassembled(true);
        this.env.setShowLineAndLocal(true);                
        System.out.println("Testing: " + classNameParm);        
        final InputStream input = Thread.currentThread().getContextClassLoader().getResourceAsStream(classNameParm);
        
        System.out.println("Input : " + input);
        if (input == null) {
            throw new IllegalStateException("Invalid class resource, classname=" + classNameParm);
        }
        displayResults(input);
    }

    private void error(String msg) {
        errorOccurred = true;
        System.err.println(msg);
        System.err.flush();
    }

    /**
     * Display results
     */
    private void displayResults(final InputStream classinMem) {
                          
        final InputStream classin = classinMem;
        try {
            // actual do display
            JavapPrinter printer = new JavapPrinter(classin, out, env);
            printer.print();

        } catch (IllegalArgumentException exc) {
            error(exc.getMessage());
        }       

    } // End of the method //

} // End of the Class //
