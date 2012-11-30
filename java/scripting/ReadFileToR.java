/**
 * Simple Java, read file, convert to R format
 * Data mine to detect problem in system log file
 * Berlin Brown
 */
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

public class ReadFileToR {
    // Read format : 2012.11.30:00:00:08:275
    private static final String P = "\\\\logs\\Log.Fri";
    private static final SimpleDateFormat df1 = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
    private static final SimpleDateFormat df2 = new SimpleDateFormat("yyyy.MM.dd:HH:mm:ss:SSS");

    public void readFile(final PrintWriter out, final String path) {
        BufferedReader bufferedReader = null;
        final File f = new File(path);
        try {
            int linesProc = 0;
            bufferedReader = new BufferedReader(new FileReader(f));
            String line = null;
            while ((line = bufferedReader.readLine()) != null) {
                if (line != null) {
                    final String ln = line.trim();
                    if (ln.length() > 10) {
                        final String [] cols = ln.split("\\|");
                        if (cols.length > 7) {
                            final String dt = cols[5].trim();
                            try {
                                final Date d = df2.parse(dt);
                                // Parsed, now reformat :
                                final String dateForR = df1.format(d);
                                out.println("'" + dateForR + "'\t10");
                                linesProc++;
                                if (linesProc % 1000 == 0) {
                                    System.out.println("Processing Lines : " + linesProc);
                                }
                            } catch(ParseException pe) { pe.printStackTrace(); }
                        }
                    } // End of the if -  ///
                } // End of if - line
            } // End of while //
        } catch(final Exception e) {
            e.printStackTrace();
        } finally {
            if (bufferedReader != null) {
                try {
                    bufferedReader.close();
                } catch(Exception e) { }
            }
        }
    } // End of method //
    public void readAndWrite(final String file) {
        BufferedOutputStream bos = null;
        PrintWriter out = null;
        try {
            bos = new BufferedOutputStream(new FileOutputStream(file));
            out = new PrintWriter(bos);
            readFile(out, P);
            out.flush();
        } catch(final Exception e) {
            e.printStackTrace();
        } finally {
            if (bos != null) {
                try {
                    bos.flush();
                    bos.close();
                } catch(IOException ioe) {
                }
            }
            if (out != null) {
                out.close();
            }
        } // End of the try catch finally //
    } // End of the method //
    public void writeScript(final String file) {
		BufferedOutputStream bos = null;
		        PrintWriter out = null;
		        try {
		            bos = new BufferedOutputStream(new FileOutputStream(file));
		            out = new PrintWriter(bos);
		            out.println(script);
		            out.flush();
		        } catch(final Exception e) {
		            e.printStackTrace();
		        } finally {
		            if (bos != null) {
		                try {
		                    bos.flush();
		                    bos.close();
		                } catch(IOException ioe) {
		                }
		            }
		            if (out != null) {
		                out.close();
		            }
        } // End of the try catch finally //
	}

    public static void main(final String [] args) {
        System.out.println("Running");
        final ReadFileToR reader = new ReadFileToR();
        reader.readAndWrite("./times1.dat");
        reader.writeScript("./line_plot2.r");
        System.out.println("Done");
    }

    private static final String script = new StringBuffer().append(
	"# Simple R plot for data  \r\n").append(
	"# '2012-02-01 17:42:44'   \r\n").append(
	"# Line plot to detect anomalous database queries \r\n").append(
	"# Run with: \r\n").append(
	"# r CMD BATCH /home/src/jvmnotebook/java/scripting/line_plot2.r \r\n").append(
	" \r\n").append(
	"library(ggplot2) \r\n").append(
	" \r\n").append(
	"req <- read.table(\"times1.dat\") \r\n").append(
	"summary(req) \r\n").append(
	" \r\n").append(
	"tt <- req$V1 \r\n").append(
	"MyDates <- as.POSIXct(tt) \r\n").append(
	"# Break by 30 min intervals and add-in frequency \r\n" ).append(
	"MyDatesTable <- table(cut(MyDates, breaks=\"60 mins\")) \r\n" ).append(
	"MyDatesDF <- data.frame(MyDatesTable, grp = 1) \r\n" ).append(
	" \r\n" ).append(
	"png('time_data_errs2.png', width=800, height=600) \r\n" ).append(
	"gg <- ggplot(MyDatesDF, aes(Var1, Freq)) + geom_line(aes(group = grp))  \r\n" ).append(
	"print(gg) \r\n").append(
	"dev.off() \r\n").toString();

} // End of the class //

