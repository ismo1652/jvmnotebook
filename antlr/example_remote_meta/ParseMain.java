
import java.io.*;
import org.antlr.*;
import org.antlr.runtime.*;

public class ParseMain {
	public static void main(String [] args)  throws Exception { 
 	        RemoteDefLexer lex = new RemoteDefLexer(
				new ANTLRFileStream(args[0]));
 	        CommonTokenStream tokens = new CommonTokenStream(lex);
			RemoteDefParser g = new RemoteDefParser(tokens);

			System.out.println("Running Parse");
			System.out.println("Done");
	}
}
