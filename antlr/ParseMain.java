
import java.io.*;
import org.antlr.*;
import org.antlr.runtime.*;

public class ParseMain {
	public static void main(String [] args)  throws Exception { 
 	        CParserLexer lex = new CParserLexer(
			new ANTLRFileStream(args[0]));
 	        CommonTokenStream tokens = new CommonTokenStream(lex);
 	    }
}
