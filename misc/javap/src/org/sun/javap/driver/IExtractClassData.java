
import java.io.InputStream;
import java.io.PrintWriter;

/**
 * Entry point for javap, class file disassembler.
 */
public interface IExtractClassData {

    void setInputClassName(final String in);

    String getInputClassName();

    void appMain(String argv[]);

    String convertClassnameFormat(final String inclass);

    void entry(String argv[]);

    /**
     * Process the arguments and perform the desired action
     */
    void perform();

    void error(String msg);

    void displayResults(final InputStream classinMem);

    String getResult();

    public PrintWriter getOut();

    public void setOut(PrintWriter out);

    public void setVerbose(boolean v);

} // End of the Class //
