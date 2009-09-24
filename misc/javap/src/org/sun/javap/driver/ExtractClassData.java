

import java.io.ByteArrayOutputStream;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import com.ca.apps.debugdev.javap.JavapEnvironment;
import com.ca.apps.debugdev.javap.JavapPrinter;

public class ExtractClassData implements IExtractClassData {

    public static final String VERSION = "9999";

    private PrintWriter out = new PrintWriter(new ByteArrayOutputStream());

    private final JavapEnvironment env = new JavapEnvironment();

    private static boolean errorOccurred = false;

    private String inputClassName = "java.lang.Object";

    private String resultString = "";

    private boolean verbose = false;

    /////////////////////////////////////////////////////////////////

    public void appMain(String[] argv) {
        entry(argv);
    }

    public String convertClassnameFormat(String inclass) {

        if ((inclass == null) || (inclass.length() == 0)) {
            // Return the default java lang object
            return "java/lang/Object.class";
        }

        boolean endClass = false;
        // Replace . with /
        // Ensure that the string ends in .class
        final Pattern chkEndClassPattr = Pattern.compile(".*?\\.class$");
        final Matcher mEndClassPattr = chkEndClassPattr.matcher(inclass);
        if (mEndClassPattr.find()) {
            // Ends in .class //
            endClass = true;
        }
        final String token1 = endClass ? inclass.replace(".class", "___CLASS___") : inclass;

        final String repl1 = token1.replaceAll("\\.", "/");
        final String repl2 = repl1.replaceAll("\\\\", "/");
        return endClass ? repl2.replace("___CLASS___", ".class") : (repl2 + ".class");
    }

    public void displayResults(InputStream classinMem) {

        final InputStream classin = classinMem;
        try {
            // actual do display
            JavapPrinter printer = new JavapPrinter(classin, out, env);
            printer.print();

        } catch (IllegalArgumentException exc) {
            error(exc.getMessage());
        }

    }

    public void entry(String[] argv) {

        final ByteArrayOutputStream baos = new ByteArrayOutputStream();
        this.out = new PrintWriter(baos);
        try {

            this.perform();

        } finally {
            out.close();
        } // End of the try - Catch Finally //

        final String res = new String(baos.toByteArray());
        this.resultString = res;

    }

    public void error(String msg) {
        errorOccurred = true;

    }

    public String getInputClassName() {
        return inputClassName;
    }

    public String getResult() {
        return this.resultString;
    }

    public void perform() {

        final String classNameParm =  convertClassnameFormat(this.inputClassName);

        if (verbose) {
            this.env.setShowVerbose(true);
            this.env.setShowDisassembled(true);
            this.env.setShowLineAndLocal(true);
        }
        final InputStream input = Thread.currentThread().getContextClassLoader().getResourceAsStream(classNameParm);

        if (input == null) {
            throw new IllegalStateException("Invalid class resource, classname=" + classNameParm);
        }
        displayResults(input);
    }

    public void setInputClassName(String in) {
        this.inputClassName = in;
    }

    /**
     * @return the out
     */
    public PrintWriter getOut() {
        return out;
    }

    /**
     * @param out the out to set
     */
    public void setOut(PrintWriter out) {
        this.out = out;
    }

    public void setVerbose(boolean v) {
        this.verbose= v;

    }

} // End of the Class //