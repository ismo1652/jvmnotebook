
import java.io.*;
import org.antlr.*;
import org.antlr.runtime.*;

import java.util.Set;
import java.util.Map;
import java.util.HashSet;
import java.util.HashMap;
import java.util.Iterator;

public class ParseMain {
	public static void main(String [] args)  throws Exception {
 	        RemoteDefLexer lex = new RemoteDefLexer(
				new ANTLRFileStream(args[0]));
 	        CommonTokenStream tokens = new CommonTokenStream(lex);
			RemoteDefParser g = new RemoteDefParser(tokens);

			System.out.println("Running Parse");
			try {
			    g.root_meta_declarations();

			    Map map = g.getRootNamespaceAttributes();
			    System.out.println("INFO: ROOT ATTRIBUTES: sz=" + map.size());
			    Iterator it = map.entrySet().iterator();
			    while(it.hasNext()) {
					Object t = it.next();
					System.out.println(t);
				}
			} catch(Exception e) {
			    e.printStackTrace();
			}
			System.out.println("Done");
	}
}
