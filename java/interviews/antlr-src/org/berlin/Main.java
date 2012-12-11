package org.berlin;

import java.io.IOException;
import java.util.List;

import org.antlr.runtime.*;
import org.antlr.runtime.tree.*;

public class Main {
    public static void main(String... args) throws NoSuchFieldException, IllegalAccessException, IOException, RecognitionException {

        final String arg1type = "FUNCTION_METHOD_DEC";    
        // Where args[0] is the input Java source file //
        final JavaLexer lexer = new JavaLexer(new ANTLRFileStream(args[0], "UTF-8"));
        final JavaParser parser = new JavaParser(new CommonTokenStream(lexer));
        final CommonTree tree = (CommonTree)(parser.javaSource().getTree());
        // int type = ((Integer)(JavaParser.class.getDeclaredField(arg1type).get(null))).intValue();
        int type = -1;
        System.out.println(count(tree, type));
    } // End of method //

    private static int count(final CommonTree tree, final int type) {
        int count = 0;
        final List children = tree.getChildren();
        if (children != null) {
            for (Object child : children) {
                System.out.println("Parsing tree : " + child);
                count += count((CommonTree)(child), type);
            }
        } /// End of the if //
        return ((tree.getType() != type) ? count : count + 1);
    } // End of the method //
} // End of the class //
