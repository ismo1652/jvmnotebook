// $ANTLR 3.5-SNAPSHOT Java.g 2012-12-11 11:24:21

  package org.berlin;


import org.antlr.runtime.*;
import java.util.Stack;
import java.util.List;
import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;

import org.antlr.runtime.tree.*;


/**
 * An ANTLRv3 capable Java 1.5 grammar for building ASTs.
 *
 * Note that there's also the tree grammar 'JavaTreeParser.g' that can be fed
 * with this grammer's output.
 *
 *
 * Please report any detected errors or even suggestions regarding this grammar
 * to
 *
 *          dieter [D O T] habelitz [A T] habelitz [D O T] com
 *
 *      with the subject
 *
 *          jsom grammar: [your subject note]
 *
 * To generate a parser based on this grammar you'll need ANTLRv3, which you can
 * get from 'http://www.antlr.org'.
 *
 *
 * This grammar is published under the ...
 *
 * BSD licence
 * 
 * Copyright (c) 2007-2008 by HABELITZ Software Developments
 *
 * All rights reserved.
 * 
 * http://www.habelitz.com
 *
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *  1. Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *  2. Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *  3. The name of the author may not be used to endorse or promote products
 *     derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY HABELITZ SOFTWARE DEVELOPMENTS ('HSD') ``AS IS'' 
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
 * ARE DISCLAIMED. IN NO EVENT SHALL 'HSD' BE LIABLE FOR ANY DIRECT, INDIRECT, 
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, 
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */
@SuppressWarnings("all")
public class JavaParser extends Parser {
	public static final String[] tokenNames = new String[] {
		"<invalid>", "<EOR>", "<DOWN>", "<UP>", "ABSTRACT", "AND", "AND_ASSIGN", "ANNOTATION_INIT_ARRAY_ELEMENT", "ANNOTATION_INIT_BLOCK", "ANNOTATION_INIT_DEFAULT_KEY", "ANNOTATION_INIT_KEY_LIST", "ANNOTATION_LIST", "ANNOTATION_METHOD_DECL", "ANNOTATION_SCOPE", "ANNOTATION_TOP_LEVEL_SCOPE", "ARGUMENT_LIST", "ARRAY_DECLARATOR", "ARRAY_DECLARATOR_LIST", "ARRAY_ELEMENT_ACCESS", "ARRAY_INITIALIZER", "ASSERT", "ASSIGN", "AT", "BIT_SHIFT_RIGHT", "BIT_SHIFT_RIGHT_ASSIGN", "BLOCK_SCOPE", "BOOLEAN", "BREAK", "BYTE", "CASE", "CAST_EXPR", "CATCH", "CATCH_CLAUSE_LIST", "CHAR", "CHARACTER_LITERAL", "CLASS", "CLASS_CONSTRUCTOR_CALL", "CLASS_INSTANCE_INITIALIZER", "CLASS_STATIC_INITIALIZER", "CLASS_TOP_LEVEL_SCOPE", "COLON", "COMMA", "COMMENT", "CONSTRUCTOR_DECL", "CONTINUE", "DEC", "DECIMAL_LITERAL", "DEFAULT", "DIV", "DIV_ASSIGN", "DO", "DOT", "DOTSTAR", "DOUBLE", "ELLIPSIS", "ELSE", "ENUM", "ENUM_TOP_LEVEL_SCOPE", "EQUAL", "ESCAPE_SEQUENCE", "EXPONENT", "EXPR", "EXTENDS", "EXTENDS_BOUND_LIST", "EXTENDS_CLAUSE", "FALSE", "FINAL", "FINALLY", "FLOAT", "FLOATING_POINT_LITERAL", "FLOAT_TYPE_SUFFIX", "FOR", "FORMAL_PARAM_LIST", "FORMAL_PARAM_STD_DECL", "FORMAL_PARAM_VARARG_DECL", "FOR_CONDITION", "FOR_EACH", "FOR_INIT", "FOR_UPDATE", "FUNCTION_METHOD_DECL", "GENERIC_TYPE_ARG_LIST", "GENERIC_TYPE_PARAM_LIST", "GREATER_OR_EQUAL", "GREATER_THAN", "HEX_DIGIT", "HEX_LITERAL", "IDENT", "IF", "IMPLEMENTS", "IMPLEMENTS_CLAUSE", "IMPORT", "INC", "INSTANCEOF", "INT", "INTEGER_TYPE_SUFFIX", "INTERFACE", "INTERFACE_TOP_LEVEL_SCOPE", "JAVA_ID_PART", "JAVA_ID_START", "JAVA_SOURCE", "LABELED_STATEMENT", "LBRACK", "LCURLY", "LESS_OR_EQUAL", "LESS_THAN", "LINE_COMMENT", "LOCAL_MODIFIER_LIST", "LOGICAL_AND", "LOGICAL_NOT", "LOGICAL_OR", "LONG", "LPAREN", "METHOD_CALL", "MINUS", "MINUS_ASSIGN", "MOD", "MODIFIER_LIST", "MOD_ASSIGN", "NATIVE", "NEW", "NOT", "NOT_EQUAL", "NULL", "OCTAL_ESCAPE", "OCTAL_LITERAL", "OR", "OR_ASSIGN", "PACKAGE", "PARENTESIZED_EXPR", "PLUS", "PLUS_ASSIGN", "POST_DEC", "POST_INC", "PRE_DEC", "PRE_INC", "PRIVATE", "PROTECTED", "PUBLIC", "QUALIFIED_TYPE_IDENT", "QUESTION", "RBRACK", "RCURLY", "RETURN", "RPAREN", "SEMI", "SHIFT_LEFT", "SHIFT_LEFT_ASSIGN", "SHIFT_RIGHT", "SHIFT_RIGHT_ASSIGN", "SHORT", "STAR", "STAR_ASSIGN", "STATIC", "STATIC_ARRAY_CREATOR", "STRICTFP", "STRING_LITERAL", "SUPER", "SUPER_CONSTRUCTOR_CALL", "SWITCH", "SWITCH_BLOCK_LABEL_LIST", "SYNCHRONIZED", "THIS", "THIS_CONSTRUCTOR_CALL", "THROW", "THROWS", "THROWS_CLAUSE", "TRANSIENT", "TRUE", "TRY", "TYPE", "UNARY_MINUS", "UNARY_PLUS", "UNICODE_ESCAPE", "VAR_DECLARATION", "VAR_DECLARATOR", "VAR_DECLARATOR_LIST", "VOID", "VOID_METHOD_DECL", "VOLATILE", "WHILE", "WS", "XOR", "XOR_ASSIGN"
	};

	public static final int EOF=-1;
	public static final int ABSTRACT=4;
	public static final int AND=5;
	public static final int AND_ASSIGN=6;
	public static final int ANNOTATION_INIT_ARRAY_ELEMENT=7;
	public static final int ANNOTATION_INIT_BLOCK=8;
	public static final int ANNOTATION_INIT_DEFAULT_KEY=9;
	public static final int ANNOTATION_INIT_KEY_LIST=10;
	public static final int ANNOTATION_LIST=11;
	public static final int ANNOTATION_METHOD_DECL=12;
	public static final int ANNOTATION_SCOPE=13;
	public static final int ANNOTATION_TOP_LEVEL_SCOPE=14;
	public static final int ARGUMENT_LIST=15;
	public static final int ARRAY_DECLARATOR=16;
	public static final int ARRAY_DECLARATOR_LIST=17;
	public static final int ARRAY_ELEMENT_ACCESS=18;
	public static final int ARRAY_INITIALIZER=19;
	public static final int ASSERT=20;
	public static final int ASSIGN=21;
	public static final int AT=22;
	public static final int BIT_SHIFT_RIGHT=23;
	public static final int BIT_SHIFT_RIGHT_ASSIGN=24;
	public static final int BLOCK_SCOPE=25;
	public static final int BOOLEAN=26;
	public static final int BREAK=27;
	public static final int BYTE=28;
	public static final int CASE=29;
	public static final int CAST_EXPR=30;
	public static final int CATCH=31;
	public static final int CATCH_CLAUSE_LIST=32;
	public static final int CHAR=33;
	public static final int CHARACTER_LITERAL=34;
	public static final int CLASS=35;
	public static final int CLASS_CONSTRUCTOR_CALL=36;
	public static final int CLASS_INSTANCE_INITIALIZER=37;
	public static final int CLASS_STATIC_INITIALIZER=38;
	public static final int CLASS_TOP_LEVEL_SCOPE=39;
	public static final int COLON=40;
	public static final int COMMA=41;
	public static final int COMMENT=42;
	public static final int CONSTRUCTOR_DECL=43;
	public static final int CONTINUE=44;
	public static final int DEC=45;
	public static final int DECIMAL_LITERAL=46;
	public static final int DEFAULT=47;
	public static final int DIV=48;
	public static final int DIV_ASSIGN=49;
	public static final int DO=50;
	public static final int DOT=51;
	public static final int DOTSTAR=52;
	public static final int DOUBLE=53;
	public static final int ELLIPSIS=54;
	public static final int ELSE=55;
	public static final int ENUM=56;
	public static final int ENUM_TOP_LEVEL_SCOPE=57;
	public static final int EQUAL=58;
	public static final int ESCAPE_SEQUENCE=59;
	public static final int EXPONENT=60;
	public static final int EXPR=61;
	public static final int EXTENDS=62;
	public static final int EXTENDS_BOUND_LIST=63;
	public static final int EXTENDS_CLAUSE=64;
	public static final int FALSE=65;
	public static final int FINAL=66;
	public static final int FINALLY=67;
	public static final int FLOAT=68;
	public static final int FLOATING_POINT_LITERAL=69;
	public static final int FLOAT_TYPE_SUFFIX=70;
	public static final int FOR=71;
	public static final int FORMAL_PARAM_LIST=72;
	public static final int FORMAL_PARAM_STD_DECL=73;
	public static final int FORMAL_PARAM_VARARG_DECL=74;
	public static final int FOR_CONDITION=75;
	public static final int FOR_EACH=76;
	public static final int FOR_INIT=77;
	public static final int FOR_UPDATE=78;
	public static final int FUNCTION_METHOD_DECL=79;
	public static final int GENERIC_TYPE_ARG_LIST=80;
	public static final int GENERIC_TYPE_PARAM_LIST=81;
	public static final int GREATER_OR_EQUAL=82;
	public static final int GREATER_THAN=83;
	public static final int HEX_DIGIT=84;
	public static final int HEX_LITERAL=85;
	public static final int IDENT=86;
	public static final int IF=87;
	public static final int IMPLEMENTS=88;
	public static final int IMPLEMENTS_CLAUSE=89;
	public static final int IMPORT=90;
	public static final int INC=91;
	public static final int INSTANCEOF=92;
	public static final int INT=93;
	public static final int INTEGER_TYPE_SUFFIX=94;
	public static final int INTERFACE=95;
	public static final int INTERFACE_TOP_LEVEL_SCOPE=96;
	public static final int JAVA_ID_PART=97;
	public static final int JAVA_ID_START=98;
	public static final int JAVA_SOURCE=99;
	public static final int LABELED_STATEMENT=100;
	public static final int LBRACK=101;
	public static final int LCURLY=102;
	public static final int LESS_OR_EQUAL=103;
	public static final int LESS_THAN=104;
	public static final int LINE_COMMENT=105;
	public static final int LOCAL_MODIFIER_LIST=106;
	public static final int LOGICAL_AND=107;
	public static final int LOGICAL_NOT=108;
	public static final int LOGICAL_OR=109;
	public static final int LONG=110;
	public static final int LPAREN=111;
	public static final int METHOD_CALL=112;
	public static final int MINUS=113;
	public static final int MINUS_ASSIGN=114;
	public static final int MOD=115;
	public static final int MODIFIER_LIST=116;
	public static final int MOD_ASSIGN=117;
	public static final int NATIVE=118;
	public static final int NEW=119;
	public static final int NOT=120;
	public static final int NOT_EQUAL=121;
	public static final int NULL=122;
	public static final int OCTAL_ESCAPE=123;
	public static final int OCTAL_LITERAL=124;
	public static final int OR=125;
	public static final int OR_ASSIGN=126;
	public static final int PACKAGE=127;
	public static final int PARENTESIZED_EXPR=128;
	public static final int PLUS=129;
	public static final int PLUS_ASSIGN=130;
	public static final int POST_DEC=131;
	public static final int POST_INC=132;
	public static final int PRE_DEC=133;
	public static final int PRE_INC=134;
	public static final int PRIVATE=135;
	public static final int PROTECTED=136;
	public static final int PUBLIC=137;
	public static final int QUALIFIED_TYPE_IDENT=138;
	public static final int QUESTION=139;
	public static final int RBRACK=140;
	public static final int RCURLY=141;
	public static final int RETURN=142;
	public static final int RPAREN=143;
	public static final int SEMI=144;
	public static final int SHIFT_LEFT=145;
	public static final int SHIFT_LEFT_ASSIGN=146;
	public static final int SHIFT_RIGHT=147;
	public static final int SHIFT_RIGHT_ASSIGN=148;
	public static final int SHORT=149;
	public static final int STAR=150;
	public static final int STAR_ASSIGN=151;
	public static final int STATIC=152;
	public static final int STATIC_ARRAY_CREATOR=153;
	public static final int STRICTFP=154;
	public static final int STRING_LITERAL=155;
	public static final int SUPER=156;
	public static final int SUPER_CONSTRUCTOR_CALL=157;
	public static final int SWITCH=158;
	public static final int SWITCH_BLOCK_LABEL_LIST=159;
	public static final int SYNCHRONIZED=160;
	public static final int THIS=161;
	public static final int THIS_CONSTRUCTOR_CALL=162;
	public static final int THROW=163;
	public static final int THROWS=164;
	public static final int THROWS_CLAUSE=165;
	public static final int TRANSIENT=166;
	public static final int TRUE=167;
	public static final int TRY=168;
	public static final int TYPE=169;
	public static final int UNARY_MINUS=170;
	public static final int UNARY_PLUS=171;
	public static final int UNICODE_ESCAPE=172;
	public static final int VAR_DECLARATION=173;
	public static final int VAR_DECLARATOR=174;
	public static final int VAR_DECLARATOR_LIST=175;
	public static final int VOID=176;
	public static final int VOID_METHOD_DECL=177;
	public static final int VOLATILE=178;
	public static final int WHILE=179;
	public static final int WS=180;
	public static final int XOR=181;
	public static final int XOR_ASSIGN=182;

	// delegates
	public Parser[] getDelegates() {
		return new Parser[] {};
	}

	// delegators


	public JavaParser(TokenStream input) {
		this(input, new RecognizerSharedState());
	}
	public JavaParser(TokenStream input, RecognizerSharedState state) {
		super(input, state);
		this.state.ruleMemo = new HashMap[355+1];
		 

	}

protected TreeAdaptor adaptor = new CommonTreeAdaptor();

public void setTreeAdaptor(TreeAdaptor adaptor) {
	this.adaptor = adaptor;
}
public TreeAdaptor getTreeAdaptor() {
	return adaptor;
}
	@Override public String[] getTokenNames() { return JavaParser.tokenNames; }
	@Override public String getGrammarFileName() { return "Java.g"; }


	    
	    private boolean mMessageCollectionEnabled = false;
	    private boolean mHasErrors = false;
	    private List<String> mMessages;

	    /**
	     *  Switches error message collection on or of.
	     *
	     *  The standard destination for parser error messages is <code>System.err</code>.
	     *  However, if <code>true</code> gets passed to this method this default
	     *  behaviour will be switched off and all error messages will be collected
	     *  instead of written to anywhere.
	     *
	     *  The default value is <code>false</code>.
	     *
	     *  @param pNewState  <code>true</code> if error messages should be collected.
	     */
	    public void enableErrorMessageCollection(boolean pNewState) {
	        mMessageCollectionEnabled = pNewState;
	        if (mMessages == null && mMessageCollectionEnabled) {
	            mMessages = new ArrayList<String>();
	        }
	    }
	    
	    /**
	     *  Collects an error message or passes the error message to <code>
	     *  super.emitErrorMessage(...)</code>.
	     *
	     *  The actual behaviour depends on whether collecting error messages
	     *  has been enabled or not.
	     *
	     *  @param pMessage  The error message.
	     */
	     @Override
	    public void emitErrorMessage(String pMessage) {
	        if (mMessageCollectionEnabled) {
	            mMessages.add(pMessage);
	        } else {
	            super.emitErrorMessage(pMessage);
	        }
	    }
	    
	    /**
	     *  Returns collected error messages.
	     *
	     *  @return  A list holding collected error messages or <code>null</code> if
	     *           collecting error messages hasn't been enabled. Of course, this
	     *           list may be empty if no error message has been emited.
	     */
	    public List<String> getMessages() {
	        return mMessages;
	    }
	    
	    /**
	     *  Tells if parsing a Java source has caused any error messages.
	     *
	     *  @return  <code>true</code> if parsing a Java source has caused at least one error message.
	     */
	    public boolean hasErrors() {
	        return mHasErrors;
	    }


	public static class javaSource_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "javaSource"
	// Java.g:324:1: javaSource : compilationUnit -> ^( JAVA_SOURCE compilationUnit ) ;
	public final JavaParser.javaSource_return javaSource() throws RecognitionException {
		JavaParser.javaSource_return retval = new JavaParser.javaSource_return();
		retval.start = input.LT(1);
		int javaSource_StartIndex = input.index();

		CommonTree root_0 = null;

		ParserRuleReturnScope compilationUnit1 =null;

		RewriteRuleSubtreeStream stream_compilationUnit=new RewriteRuleSubtreeStream(adaptor,"rule compilationUnit");

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 1) ) { return retval; }

			// Java.g:325:5: ( compilationUnit -> ^( JAVA_SOURCE compilationUnit ) )
			// Java.g:325:9: compilationUnit
			{
			pushFollow(FOLLOW_compilationUnit_in_javaSource4506);
			compilationUnit1=compilationUnit();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) stream_compilationUnit.add(compilationUnit1.getTree());
			// AST REWRITE
			// elements: compilationUnit
			// token labels: 
			// rule labels: retval
			// token list labels: 
			// rule list labels: 
			// wildcard labels: 
			if ( state.backtracking==0 ) {

			retval.tree = root_0;
			RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

			root_0 = (CommonTree)adaptor.nil();
			// 326:9: -> ^( JAVA_SOURCE compilationUnit )
			{
				// Java.g:326:13: ^( JAVA_SOURCE compilationUnit )
				{
				CommonTree root_1 = (CommonTree)adaptor.nil();
				root_1 = (CommonTree)adaptor.becomeRoot(
				(CommonTree)adaptor.create(JAVA_SOURCE, "JAVA_SOURCE")
				, root_1);

				adaptor.addChild(root_1, stream_compilationUnit.nextTree());

				adaptor.addChild(root_0, root_1);
				}

			}


			retval.tree = root_0;
			}

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 1, javaSource_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "javaSource"


	public static class compilationUnit_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "compilationUnit"
	// Java.g:329:1: compilationUnit : annotationList ( packageDeclaration )? ( importDeclaration )* ( typeDecls )* ;
	public final JavaParser.compilationUnit_return compilationUnit() throws RecognitionException {
		JavaParser.compilationUnit_return retval = new JavaParser.compilationUnit_return();
		retval.start = input.LT(1);
		int compilationUnit_StartIndex = input.index();

		CommonTree root_0 = null;

		ParserRuleReturnScope annotationList2 =null;
		ParserRuleReturnScope packageDeclaration3 =null;
		ParserRuleReturnScope importDeclaration4 =null;
		ParserRuleReturnScope typeDecls5 =null;


		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 2) ) { return retval; }

			// Java.g:330:5: ( annotationList ( packageDeclaration )? ( importDeclaration )* ( typeDecls )* )
			// Java.g:330:9: annotationList ( packageDeclaration )? ( importDeclaration )* ( typeDecls )*
			{
			root_0 = (CommonTree)adaptor.nil();


			pushFollow(FOLLOW_annotationList_in_compilationUnit4542);
			annotationList2=annotationList();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) adaptor.addChild(root_0, annotationList2.getTree());

			// Java.g:331:9: ( packageDeclaration )?
			int alt1=2;
			int LA1_0 = input.LA(1);
			if ( (LA1_0==PACKAGE) ) {
				alt1=1;
			}
			switch (alt1) {
				case 1 :
					// Java.g:331:9: packageDeclaration
					{
					pushFollow(FOLLOW_packageDeclaration_in_compilationUnit4553);
					packageDeclaration3=packageDeclaration();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) adaptor.addChild(root_0, packageDeclaration3.getTree());

					}
					break;

			}

			// Java.g:332:9: ( importDeclaration )*
			loop2:
			do {
				int alt2=2;
				int LA2_0 = input.LA(1);
				if ( (LA2_0==IMPORT) ) {
					alt2=1;
				}

				switch (alt2) {
				case 1 :
					// Java.g:332:9: importDeclaration
					{
					pushFollow(FOLLOW_importDeclaration_in_compilationUnit4565);
					importDeclaration4=importDeclaration();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) adaptor.addChild(root_0, importDeclaration4.getTree());

					}
					break;

				default :
					break loop2;
				}
			} while (true);

			// Java.g:333:9: ( typeDecls )*
			loop3:
			do {
				int alt3=2;
				int LA3_0 = input.LA(1);
				if ( (LA3_0==ABSTRACT||LA3_0==AT||LA3_0==BOOLEAN||LA3_0==BYTE||LA3_0==CHAR||LA3_0==CLASS||LA3_0==DOUBLE||LA3_0==ENUM||LA3_0==FINAL||LA3_0==FLOAT||LA3_0==IDENT||LA3_0==INT||LA3_0==INTERFACE||LA3_0==LESS_THAN||LA3_0==LONG||LA3_0==NATIVE||(LA3_0 >= PRIVATE && LA3_0 <= PUBLIC)||LA3_0==SEMI||LA3_0==SHORT||LA3_0==STATIC||LA3_0==STRICTFP||LA3_0==SYNCHRONIZED||LA3_0==TRANSIENT||LA3_0==VOID||LA3_0==VOLATILE) ) {
					alt3=1;
				}

				switch (alt3) {
				case 1 :
					// Java.g:333:9: typeDecls
					{
					pushFollow(FOLLOW_typeDecls_in_compilationUnit4577);
					typeDecls5=typeDecls();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) adaptor.addChild(root_0, typeDecls5.getTree());

					}
					break;

				default :
					break loop3;
				}
			} while (true);

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 2, compilationUnit_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "compilationUnit"


	public static class typeDecls_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "typeDecls"
	// Java.g:336:1: typeDecls : ( typeDeclaration | SEMI !);
	public final JavaParser.typeDecls_return typeDecls() throws RecognitionException {
		JavaParser.typeDecls_return retval = new JavaParser.typeDecls_return();
		retval.start = input.LT(1);
		int typeDecls_StartIndex = input.index();

		CommonTree root_0 = null;

		Token SEMI7=null;
		ParserRuleReturnScope typeDeclaration6 =null;

		CommonTree SEMI7_tree=null;

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 3) ) { return retval; }

			// Java.g:337:5: ( typeDeclaration | SEMI !)
			int alt4=2;
			int LA4_0 = input.LA(1);
			if ( (LA4_0==ABSTRACT||LA4_0==AT||LA4_0==BOOLEAN||LA4_0==BYTE||LA4_0==CHAR||LA4_0==CLASS||LA4_0==DOUBLE||LA4_0==ENUM||LA4_0==FINAL||LA4_0==FLOAT||LA4_0==IDENT||LA4_0==INT||LA4_0==INTERFACE||LA4_0==LESS_THAN||LA4_0==LONG||LA4_0==NATIVE||(LA4_0 >= PRIVATE && LA4_0 <= PUBLIC)||LA4_0==SHORT||LA4_0==STATIC||LA4_0==STRICTFP||LA4_0==SYNCHRONIZED||LA4_0==TRANSIENT||LA4_0==VOID||LA4_0==VOLATILE) ) {
				alt4=1;
			}
			else if ( (LA4_0==SEMI) ) {
				alt4=2;
			}
			else {
				if (state.backtracking>0) {state.failed=true; return retval;}
				NoViableAltException nvae =
					new NoViableAltException("", 4, 0, input);
				throw nvae;
			}
			switch (alt4) {
				case 1 :
					// Java.g:337:9: typeDeclaration
					{
					root_0 = (CommonTree)adaptor.nil();


					pushFollow(FOLLOW_typeDeclaration_in_typeDecls4597);
					typeDeclaration6=typeDeclaration();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) adaptor.addChild(root_0, typeDeclaration6.getTree());

					}
					break;
				case 2 :
					// Java.g:338:9: SEMI !
					{
					root_0 = (CommonTree)adaptor.nil();


					SEMI7=(Token)match(input,SEMI,FOLLOW_SEMI_in_typeDecls4607); if (state.failed) return retval;
					}
					break;

			}
			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 3, typeDecls_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "typeDecls"


	public static class packageDeclaration_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "packageDeclaration"
	// Java.g:341:1: packageDeclaration : PACKAGE ^ qualifiedIdentifier SEMI !;
	public final JavaParser.packageDeclaration_return packageDeclaration() throws RecognitionException {
		JavaParser.packageDeclaration_return retval = new JavaParser.packageDeclaration_return();
		retval.start = input.LT(1);
		int packageDeclaration_StartIndex = input.index();

		CommonTree root_0 = null;

		Token PACKAGE8=null;
		Token SEMI10=null;
		ParserRuleReturnScope qualifiedIdentifier9 =null;

		CommonTree PACKAGE8_tree=null;
		CommonTree SEMI10_tree=null;

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 4) ) { return retval; }

			// Java.g:342:5: ( PACKAGE ^ qualifiedIdentifier SEMI !)
			// Java.g:342:9: PACKAGE ^ qualifiedIdentifier SEMI !
			{
			root_0 = (CommonTree)adaptor.nil();


			PACKAGE8=(Token)match(input,PACKAGE,FOLLOW_PACKAGE_in_packageDeclaration4627); if (state.failed) return retval;
			if ( state.backtracking==0 ) {
			PACKAGE8_tree = 
			(CommonTree)adaptor.create(PACKAGE8)
			;
			root_0 = (CommonTree)adaptor.becomeRoot(PACKAGE8_tree, root_0);
			}

			pushFollow(FOLLOW_qualifiedIdentifier_in_packageDeclaration4630);
			qualifiedIdentifier9=qualifiedIdentifier();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) adaptor.addChild(root_0, qualifiedIdentifier9.getTree());

			SEMI10=(Token)match(input,SEMI,FOLLOW_SEMI_in_packageDeclaration4632); if (state.failed) return retval;
			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 4, packageDeclaration_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "packageDeclaration"


	public static class importDeclaration_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "importDeclaration"
	// Java.g:345:1: importDeclaration : IMPORT ^ ( STATIC )? qualifiedIdentifier ( DOTSTAR )? SEMI !;
	public final JavaParser.importDeclaration_return importDeclaration() throws RecognitionException {
		JavaParser.importDeclaration_return retval = new JavaParser.importDeclaration_return();
		retval.start = input.LT(1);
		int importDeclaration_StartIndex = input.index();

		CommonTree root_0 = null;

		Token IMPORT11=null;
		Token STATIC12=null;
		Token DOTSTAR14=null;
		Token SEMI15=null;
		ParserRuleReturnScope qualifiedIdentifier13 =null;

		CommonTree IMPORT11_tree=null;
		CommonTree STATIC12_tree=null;
		CommonTree DOTSTAR14_tree=null;
		CommonTree SEMI15_tree=null;

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 5) ) { return retval; }

			// Java.g:346:5: ( IMPORT ^ ( STATIC )? qualifiedIdentifier ( DOTSTAR )? SEMI !)
			// Java.g:346:9: IMPORT ^ ( STATIC )? qualifiedIdentifier ( DOTSTAR )? SEMI !
			{
			root_0 = (CommonTree)adaptor.nil();


			IMPORT11=(Token)match(input,IMPORT,FOLLOW_IMPORT_in_importDeclaration4658); if (state.failed) return retval;
			if ( state.backtracking==0 ) {
			IMPORT11_tree = 
			(CommonTree)adaptor.create(IMPORT11)
			;
			root_0 = (CommonTree)adaptor.becomeRoot(IMPORT11_tree, root_0);
			}

			// Java.g:346:17: ( STATIC )?
			int alt5=2;
			int LA5_0 = input.LA(1);
			if ( (LA5_0==STATIC) ) {
				alt5=1;
			}
			switch (alt5) {
				case 1 :
					// Java.g:346:17: STATIC
					{
					STATIC12=(Token)match(input,STATIC,FOLLOW_STATIC_in_importDeclaration4661); if (state.failed) return retval;
					if ( state.backtracking==0 ) {
					STATIC12_tree = 
					(CommonTree)adaptor.create(STATIC12)
					;
					adaptor.addChild(root_0, STATIC12_tree);
					}

					}
					break;

			}

			pushFollow(FOLLOW_qualifiedIdentifier_in_importDeclaration4664);
			qualifiedIdentifier13=qualifiedIdentifier();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) adaptor.addChild(root_0, qualifiedIdentifier13.getTree());

			// Java.g:346:45: ( DOTSTAR )?
			int alt6=2;
			int LA6_0 = input.LA(1);
			if ( (LA6_0==DOTSTAR) ) {
				alt6=1;
			}
			switch (alt6) {
				case 1 :
					// Java.g:346:45: DOTSTAR
					{
					DOTSTAR14=(Token)match(input,DOTSTAR,FOLLOW_DOTSTAR_in_importDeclaration4666); if (state.failed) return retval;
					if ( state.backtracking==0 ) {
					DOTSTAR14_tree = 
					(CommonTree)adaptor.create(DOTSTAR14)
					;
					adaptor.addChild(root_0, DOTSTAR14_tree);
					}

					}
					break;

			}

			SEMI15=(Token)match(input,SEMI,FOLLOW_SEMI_in_importDeclaration4669); if (state.failed) return retval;
			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 5, importDeclaration_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "importDeclaration"


	public static class typeDeclaration_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "typeDeclaration"
	// Java.g:349:1: typeDeclaration : modifierList ! ( classTypeDeclaration[$modifierList.tree] | interfaceTypeDeclaration[$modifierList.tree] | enumTypeDeclaration[$modifierList.tree] | annotationTypeDeclaration[$modifierList.tree] ) ;
	public final JavaParser.typeDeclaration_return typeDeclaration() throws RecognitionException {
		JavaParser.typeDeclaration_return retval = new JavaParser.typeDeclaration_return();
		retval.start = input.LT(1);
		int typeDeclaration_StartIndex = input.index();

		CommonTree root_0 = null;

		ParserRuleReturnScope modifierList16 =null;
		ParserRuleReturnScope classTypeDeclaration17 =null;
		ParserRuleReturnScope interfaceTypeDeclaration18 =null;
		ParserRuleReturnScope enumTypeDeclaration19 =null;
		ParserRuleReturnScope annotationTypeDeclaration20 =null;


		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 6) ) { return retval; }

			// Java.g:350:5: ( modifierList ! ( classTypeDeclaration[$modifierList.tree] | interfaceTypeDeclaration[$modifierList.tree] | enumTypeDeclaration[$modifierList.tree] | annotationTypeDeclaration[$modifierList.tree] ) )
			// Java.g:350:9: modifierList ! ( classTypeDeclaration[$modifierList.tree] | interfaceTypeDeclaration[$modifierList.tree] | enumTypeDeclaration[$modifierList.tree] | annotationTypeDeclaration[$modifierList.tree] )
			{
			root_0 = (CommonTree)adaptor.nil();


			pushFollow(FOLLOW_modifierList_in_typeDeclaration4693);
			modifierList16=modifierList();
			state._fsp--;
			if (state.failed) return retval;
			// Java.g:351:9: ( classTypeDeclaration[$modifierList.tree] | interfaceTypeDeclaration[$modifierList.tree] | enumTypeDeclaration[$modifierList.tree] | annotationTypeDeclaration[$modifierList.tree] )
			int alt7=4;
			switch ( input.LA(1) ) {
			case CLASS:
				{
				alt7=1;
				}
				break;
			case INTERFACE:
				{
				alt7=2;
				}
				break;
			case ENUM:
				{
				alt7=3;
				}
				break;
			case AT:
				{
				alt7=4;
				}
				break;
			default:
				if (state.backtracking>0) {state.failed=true; return retval;}
				NoViableAltException nvae =
					new NoViableAltException("", 7, 0, input);
				throw nvae;
			}
			switch (alt7) {
				case 1 :
					// Java.g:351:13: classTypeDeclaration[$modifierList.tree]
					{
					pushFollow(FOLLOW_classTypeDeclaration_in_typeDeclaration4708);
					classTypeDeclaration17=classTypeDeclaration((modifierList16!=null?((CommonTree)modifierList16.getTree()):null));
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) adaptor.addChild(root_0, classTypeDeclaration17.getTree());

					}
					break;
				case 2 :
					// Java.g:352:13: interfaceTypeDeclaration[$modifierList.tree]
					{
					pushFollow(FOLLOW_interfaceTypeDeclaration_in_typeDeclaration4723);
					interfaceTypeDeclaration18=interfaceTypeDeclaration((modifierList16!=null?((CommonTree)modifierList16.getTree()):null));
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) adaptor.addChild(root_0, interfaceTypeDeclaration18.getTree());

					}
					break;
				case 3 :
					// Java.g:353:13: enumTypeDeclaration[$modifierList.tree]
					{
					pushFollow(FOLLOW_enumTypeDeclaration_in_typeDeclaration4738);
					enumTypeDeclaration19=enumTypeDeclaration((modifierList16!=null?((CommonTree)modifierList16.getTree()):null));
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) adaptor.addChild(root_0, enumTypeDeclaration19.getTree());

					}
					break;
				case 4 :
					// Java.g:354:13: annotationTypeDeclaration[$modifierList.tree]
					{
					pushFollow(FOLLOW_annotationTypeDeclaration_in_typeDeclaration4753);
					annotationTypeDeclaration20=annotationTypeDeclaration((modifierList16!=null?((CommonTree)modifierList16.getTree()):null));
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) adaptor.addChild(root_0, annotationTypeDeclaration20.getTree());

					}
					break;

			}

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 6, typeDeclaration_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "typeDeclaration"


	public static class classTypeDeclaration_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "classTypeDeclaration"
	// Java.g:358:1: classTypeDeclaration[CommonTree modifiers] : CLASS IDENT ( genericTypeParameterList )? ( classExtendsClause )? ( implementsClause )? classBody -> ^( CLASS IDENT ( genericTypeParameterList )? ( classExtendsClause )? ( implementsClause )? classBody ) ;
	public final JavaParser.classTypeDeclaration_return classTypeDeclaration(CommonTree modifiers) throws RecognitionException {
		JavaParser.classTypeDeclaration_return retval = new JavaParser.classTypeDeclaration_return();
		retval.start = input.LT(1);
		int classTypeDeclaration_StartIndex = input.index();

		CommonTree root_0 = null;

		Token CLASS21=null;
		Token IDENT22=null;
		ParserRuleReturnScope genericTypeParameterList23 =null;
		ParserRuleReturnScope classExtendsClause24 =null;
		ParserRuleReturnScope implementsClause25 =null;
		ParserRuleReturnScope classBody26 =null;

		CommonTree CLASS21_tree=null;
		CommonTree IDENT22_tree=null;
		RewriteRuleTokenStream stream_IDENT=new RewriteRuleTokenStream(adaptor,"token IDENT");
		RewriteRuleTokenStream stream_CLASS=new RewriteRuleTokenStream(adaptor,"token CLASS");
		RewriteRuleSubtreeStream stream_genericTypeParameterList=new RewriteRuleSubtreeStream(adaptor,"rule genericTypeParameterList");
		RewriteRuleSubtreeStream stream_classExtendsClause=new RewriteRuleSubtreeStream(adaptor,"rule classExtendsClause");
		RewriteRuleSubtreeStream stream_implementsClause=new RewriteRuleSubtreeStream(adaptor,"rule implementsClause");
		RewriteRuleSubtreeStream stream_classBody=new RewriteRuleSubtreeStream(adaptor,"rule classBody");

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 7) ) { return retval; }

			// Java.g:359:5: ( CLASS IDENT ( genericTypeParameterList )? ( classExtendsClause )? ( implementsClause )? classBody -> ^( CLASS IDENT ( genericTypeParameterList )? ( classExtendsClause )? ( implementsClause )? classBody ) )
			// Java.g:359:9: CLASS IDENT ( genericTypeParameterList )? ( classExtendsClause )? ( implementsClause )? classBody
			{
			CLASS21=(Token)match(input,CLASS,FOLLOW_CLASS_in_classTypeDeclaration4788); if (state.failed) return retval; 
			if ( state.backtracking==0 ) stream_CLASS.add(CLASS21);

			IDENT22=(Token)match(input,IDENT,FOLLOW_IDENT_in_classTypeDeclaration4790); if (state.failed) return retval; 
			if ( state.backtracking==0 ) stream_IDENT.add(IDENT22);

			// Java.g:359:21: ( genericTypeParameterList )?
			int alt8=2;
			int LA8_0 = input.LA(1);
			if ( (LA8_0==LESS_THAN) ) {
				alt8=1;
			}
			switch (alt8) {
				case 1 :
					// Java.g:359:21: genericTypeParameterList
					{
					pushFollow(FOLLOW_genericTypeParameterList_in_classTypeDeclaration4792);
					genericTypeParameterList23=genericTypeParameterList();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_genericTypeParameterList.add(genericTypeParameterList23.getTree());
					}
					break;

			}

			// Java.g:359:47: ( classExtendsClause )?
			int alt9=2;
			int LA9_0 = input.LA(1);
			if ( (LA9_0==EXTENDS) ) {
				alt9=1;
			}
			switch (alt9) {
				case 1 :
					// Java.g:359:47: classExtendsClause
					{
					pushFollow(FOLLOW_classExtendsClause_in_classTypeDeclaration4795);
					classExtendsClause24=classExtendsClause();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_classExtendsClause.add(classExtendsClause24.getTree());
					}
					break;

			}

			// Java.g:359:67: ( implementsClause )?
			int alt10=2;
			int LA10_0 = input.LA(1);
			if ( (LA10_0==IMPLEMENTS) ) {
				alt10=1;
			}
			switch (alt10) {
				case 1 :
					// Java.g:359:67: implementsClause
					{
					pushFollow(FOLLOW_implementsClause_in_classTypeDeclaration4798);
					implementsClause25=implementsClause();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_implementsClause.add(implementsClause25.getTree());
					}
					break;

			}

			pushFollow(FOLLOW_classBody_in_classTypeDeclaration4801);
			classBody26=classBody();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) stream_classBody.add(classBody26.getTree());
			// AST REWRITE
			// elements: CLASS, classExtendsClause, genericTypeParameterList, implementsClause, classBody, IDENT
			// token labels: 
			// rule labels: retval
			// token list labels: 
			// rule list labels: 
			// wildcard labels: 
			if ( state.backtracking==0 ) {

			retval.tree = root_0;
			RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

			root_0 = (CommonTree)adaptor.nil();
			// 360:9: -> ^( CLASS IDENT ( genericTypeParameterList )? ( classExtendsClause )? ( implementsClause )? classBody )
			{
				// Java.g:360:13: ^( CLASS IDENT ( genericTypeParameterList )? ( classExtendsClause )? ( implementsClause )? classBody )
				{
				CommonTree root_1 = (CommonTree)adaptor.nil();
				root_1 = (CommonTree)adaptor.becomeRoot(
				stream_CLASS.nextNode()
				, root_1);

				adaptor.addChild(root_1, modifiers);

				adaptor.addChild(root_1, 
				stream_IDENT.nextNode()
				);

				// Java.g:360:40: ( genericTypeParameterList )?
				if ( stream_genericTypeParameterList.hasNext() ) {
					adaptor.addChild(root_1, stream_genericTypeParameterList.nextTree());

				}
				stream_genericTypeParameterList.reset();

				// Java.g:360:66: ( classExtendsClause )?
				if ( stream_classExtendsClause.hasNext() ) {
					adaptor.addChild(root_1, stream_classExtendsClause.nextTree());

				}
				stream_classExtendsClause.reset();

				// Java.g:360:86: ( implementsClause )?
				if ( stream_implementsClause.hasNext() ) {
					adaptor.addChild(root_1, stream_implementsClause.nextTree());

				}
				stream_implementsClause.reset();

				adaptor.addChild(root_1, stream_classBody.nextTree());

				adaptor.addChild(root_0, root_1);
				}

			}


			retval.tree = root_0;
			}

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 7, classTypeDeclaration_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "classTypeDeclaration"


	public static class classExtendsClause_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "classExtendsClause"
	// Java.g:363:1: classExtendsClause : EXTENDS type -> ^( EXTENDS_CLAUSE[$EXTENDS, \"EXTENDS_CLAUSE\"] type ) ;
	public final JavaParser.classExtendsClause_return classExtendsClause() throws RecognitionException {
		JavaParser.classExtendsClause_return retval = new JavaParser.classExtendsClause_return();
		retval.start = input.LT(1);
		int classExtendsClause_StartIndex = input.index();

		CommonTree root_0 = null;

		Token EXTENDS27=null;
		ParserRuleReturnScope type28 =null;

		CommonTree EXTENDS27_tree=null;
		RewriteRuleTokenStream stream_EXTENDS=new RewriteRuleTokenStream(adaptor,"token EXTENDS");
		RewriteRuleSubtreeStream stream_type=new RewriteRuleSubtreeStream(adaptor,"rule type");

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 8) ) { return retval; }

			// Java.g:364:5: ( EXTENDS type -> ^( EXTENDS_CLAUSE[$EXTENDS, \"EXTENDS_CLAUSE\"] type ) )
			// Java.g:364:9: EXTENDS type
			{
			EXTENDS27=(Token)match(input,EXTENDS,FOLLOW_EXTENDS_in_classExtendsClause4854); if (state.failed) return retval; 
			if ( state.backtracking==0 ) stream_EXTENDS.add(EXTENDS27);

			pushFollow(FOLLOW_type_in_classExtendsClause4856);
			type28=type();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) stream_type.add(type28.getTree());
			// AST REWRITE
			// elements: type
			// token labels: 
			// rule labels: retval
			// token list labels: 
			// rule list labels: 
			// wildcard labels: 
			if ( state.backtracking==0 ) {

			retval.tree = root_0;
			RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

			root_0 = (CommonTree)adaptor.nil();
			// 365:9: -> ^( EXTENDS_CLAUSE[$EXTENDS, \"EXTENDS_CLAUSE\"] type )
			{
				// Java.g:365:13: ^( EXTENDS_CLAUSE[$EXTENDS, \"EXTENDS_CLAUSE\"] type )
				{
				CommonTree root_1 = (CommonTree)adaptor.nil();
				root_1 = (CommonTree)adaptor.becomeRoot(
				(CommonTree)adaptor.create(EXTENDS_CLAUSE, EXTENDS27, "EXTENDS_CLAUSE")
				, root_1);

				adaptor.addChild(root_1, stream_type.nextTree());

				adaptor.addChild(root_0, root_1);
				}

			}


			retval.tree = root_0;
			}

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 8, classExtendsClause_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "classExtendsClause"


	public static class interfaceExtendsClause_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "interfaceExtendsClause"
	// Java.g:368:1: interfaceExtendsClause : EXTENDS typeList -> ^( EXTENDS_CLAUSE[$EXTENDS, \"EXTENDS_CLAUSE\"] typeList ) ;
	public final JavaParser.interfaceExtendsClause_return interfaceExtendsClause() throws RecognitionException {
		JavaParser.interfaceExtendsClause_return retval = new JavaParser.interfaceExtendsClause_return();
		retval.start = input.LT(1);
		int interfaceExtendsClause_StartIndex = input.index();

		CommonTree root_0 = null;

		Token EXTENDS29=null;
		ParserRuleReturnScope typeList30 =null;

		CommonTree EXTENDS29_tree=null;
		RewriteRuleTokenStream stream_EXTENDS=new RewriteRuleTokenStream(adaptor,"token EXTENDS");
		RewriteRuleSubtreeStream stream_typeList=new RewriteRuleSubtreeStream(adaptor,"rule typeList");

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 9) ) { return retval; }

			// Java.g:369:5: ( EXTENDS typeList -> ^( EXTENDS_CLAUSE[$EXTENDS, \"EXTENDS_CLAUSE\"] typeList ) )
			// Java.g:369:9: EXTENDS typeList
			{
			EXTENDS29=(Token)match(input,EXTENDS,FOLLOW_EXTENDS_in_interfaceExtendsClause4900); if (state.failed) return retval; 
			if ( state.backtracking==0 ) stream_EXTENDS.add(EXTENDS29);

			pushFollow(FOLLOW_typeList_in_interfaceExtendsClause4902);
			typeList30=typeList();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) stream_typeList.add(typeList30.getTree());
			// AST REWRITE
			// elements: typeList
			// token labels: 
			// rule labels: retval
			// token list labels: 
			// rule list labels: 
			// wildcard labels: 
			if ( state.backtracking==0 ) {

			retval.tree = root_0;
			RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

			root_0 = (CommonTree)adaptor.nil();
			// 370:9: -> ^( EXTENDS_CLAUSE[$EXTENDS, \"EXTENDS_CLAUSE\"] typeList )
			{
				// Java.g:370:13: ^( EXTENDS_CLAUSE[$EXTENDS, \"EXTENDS_CLAUSE\"] typeList )
				{
				CommonTree root_1 = (CommonTree)adaptor.nil();
				root_1 = (CommonTree)adaptor.becomeRoot(
				(CommonTree)adaptor.create(EXTENDS_CLAUSE, EXTENDS29, "EXTENDS_CLAUSE")
				, root_1);

				adaptor.addChild(root_1, stream_typeList.nextTree());

				adaptor.addChild(root_0, root_1);
				}

			}


			retval.tree = root_0;
			}

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 9, interfaceExtendsClause_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "interfaceExtendsClause"


	public static class implementsClause_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "implementsClause"
	// Java.g:373:1: implementsClause : IMPLEMENTS typeList -> ^( IMPLEMENTS_CLAUSE[$IMPLEMENTS, \"IMPLEMENTS_CLAUSE\"] typeList ) ;
	public final JavaParser.implementsClause_return implementsClause() throws RecognitionException {
		JavaParser.implementsClause_return retval = new JavaParser.implementsClause_return();
		retval.start = input.LT(1);
		int implementsClause_StartIndex = input.index();

		CommonTree root_0 = null;

		Token IMPLEMENTS31=null;
		ParserRuleReturnScope typeList32 =null;

		CommonTree IMPLEMENTS31_tree=null;
		RewriteRuleTokenStream stream_IMPLEMENTS=new RewriteRuleTokenStream(adaptor,"token IMPLEMENTS");
		RewriteRuleSubtreeStream stream_typeList=new RewriteRuleSubtreeStream(adaptor,"rule typeList");

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 10) ) { return retval; }

			// Java.g:374:5: ( IMPLEMENTS typeList -> ^( IMPLEMENTS_CLAUSE[$IMPLEMENTS, \"IMPLEMENTS_CLAUSE\"] typeList ) )
			// Java.g:374:9: IMPLEMENTS typeList
			{
			IMPLEMENTS31=(Token)match(input,IMPLEMENTS,FOLLOW_IMPLEMENTS_in_implementsClause4946); if (state.failed) return retval; 
			if ( state.backtracking==0 ) stream_IMPLEMENTS.add(IMPLEMENTS31);

			pushFollow(FOLLOW_typeList_in_implementsClause4948);
			typeList32=typeList();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) stream_typeList.add(typeList32.getTree());
			// AST REWRITE
			// elements: typeList
			// token labels: 
			// rule labels: retval
			// token list labels: 
			// rule list labels: 
			// wildcard labels: 
			if ( state.backtracking==0 ) {

			retval.tree = root_0;
			RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

			root_0 = (CommonTree)adaptor.nil();
			// 375:9: -> ^( IMPLEMENTS_CLAUSE[$IMPLEMENTS, \"IMPLEMENTS_CLAUSE\"] typeList )
			{
				// Java.g:375:13: ^( IMPLEMENTS_CLAUSE[$IMPLEMENTS, \"IMPLEMENTS_CLAUSE\"] typeList )
				{
				CommonTree root_1 = (CommonTree)adaptor.nil();
				root_1 = (CommonTree)adaptor.becomeRoot(
				(CommonTree)adaptor.create(IMPLEMENTS_CLAUSE, IMPLEMENTS31, "IMPLEMENTS_CLAUSE")
				, root_1);

				adaptor.addChild(root_1, stream_typeList.nextTree());

				adaptor.addChild(root_0, root_1);
				}

			}


			retval.tree = root_0;
			}

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 10, implementsClause_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "implementsClause"


	public static class genericTypeParameterList_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "genericTypeParameterList"
	// Java.g:378:1: genericTypeParameterList : LESS_THAN genericTypeParameter ( COMMA genericTypeParameter )* genericTypeListClosing -> ^( GENERIC_TYPE_PARAM_LIST[$LESS_THAN, \"GENERIC_TYPE_PARAM_LIST\"] ( genericTypeParameter )+ ) ;
	public final JavaParser.genericTypeParameterList_return genericTypeParameterList() throws RecognitionException {
		JavaParser.genericTypeParameterList_return retval = new JavaParser.genericTypeParameterList_return();
		retval.start = input.LT(1);
		int genericTypeParameterList_StartIndex = input.index();

		CommonTree root_0 = null;

		Token LESS_THAN33=null;
		Token COMMA35=null;
		ParserRuleReturnScope genericTypeParameter34 =null;
		ParserRuleReturnScope genericTypeParameter36 =null;
		ParserRuleReturnScope genericTypeListClosing37 =null;

		CommonTree LESS_THAN33_tree=null;
		CommonTree COMMA35_tree=null;
		RewriteRuleTokenStream stream_COMMA=new RewriteRuleTokenStream(adaptor,"token COMMA");
		RewriteRuleTokenStream stream_LESS_THAN=new RewriteRuleTokenStream(adaptor,"token LESS_THAN");
		RewriteRuleSubtreeStream stream_genericTypeParameter=new RewriteRuleSubtreeStream(adaptor,"rule genericTypeParameter");
		RewriteRuleSubtreeStream stream_genericTypeListClosing=new RewriteRuleSubtreeStream(adaptor,"rule genericTypeListClosing");

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 11) ) { return retval; }

			// Java.g:379:5: ( LESS_THAN genericTypeParameter ( COMMA genericTypeParameter )* genericTypeListClosing -> ^( GENERIC_TYPE_PARAM_LIST[$LESS_THAN, \"GENERIC_TYPE_PARAM_LIST\"] ( genericTypeParameter )+ ) )
			// Java.g:379:9: LESS_THAN genericTypeParameter ( COMMA genericTypeParameter )* genericTypeListClosing
			{
			LESS_THAN33=(Token)match(input,LESS_THAN,FOLLOW_LESS_THAN_in_genericTypeParameterList4993); if (state.failed) return retval; 
			if ( state.backtracking==0 ) stream_LESS_THAN.add(LESS_THAN33);

			pushFollow(FOLLOW_genericTypeParameter_in_genericTypeParameterList4995);
			genericTypeParameter34=genericTypeParameter();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) stream_genericTypeParameter.add(genericTypeParameter34.getTree());
			// Java.g:379:40: ( COMMA genericTypeParameter )*
			loop11:
			do {
				int alt11=2;
				int LA11_0 = input.LA(1);
				if ( (LA11_0==COMMA) ) {
					alt11=1;
				}

				switch (alt11) {
				case 1 :
					// Java.g:379:41: COMMA genericTypeParameter
					{
					COMMA35=(Token)match(input,COMMA,FOLLOW_COMMA_in_genericTypeParameterList4998); if (state.failed) return retval; 
					if ( state.backtracking==0 ) stream_COMMA.add(COMMA35);

					pushFollow(FOLLOW_genericTypeParameter_in_genericTypeParameterList5000);
					genericTypeParameter36=genericTypeParameter();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_genericTypeParameter.add(genericTypeParameter36.getTree());
					}
					break;

				default :
					break loop11;
				}
			} while (true);

			pushFollow(FOLLOW_genericTypeListClosing_in_genericTypeParameterList5004);
			genericTypeListClosing37=genericTypeListClosing();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) stream_genericTypeListClosing.add(genericTypeListClosing37.getTree());
			// AST REWRITE
			// elements: genericTypeParameter
			// token labels: 
			// rule labels: retval
			// token list labels: 
			// rule list labels: 
			// wildcard labels: 
			if ( state.backtracking==0 ) {

			retval.tree = root_0;
			RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

			root_0 = (CommonTree)adaptor.nil();
			// 380:9: -> ^( GENERIC_TYPE_PARAM_LIST[$LESS_THAN, \"GENERIC_TYPE_PARAM_LIST\"] ( genericTypeParameter )+ )
			{
				// Java.g:380:13: ^( GENERIC_TYPE_PARAM_LIST[$LESS_THAN, \"GENERIC_TYPE_PARAM_LIST\"] ( genericTypeParameter )+ )
				{
				CommonTree root_1 = (CommonTree)adaptor.nil();
				root_1 = (CommonTree)adaptor.becomeRoot(
				(CommonTree)adaptor.create(GENERIC_TYPE_PARAM_LIST, LESS_THAN33, "GENERIC_TYPE_PARAM_LIST")
				, root_1);

				if ( !(stream_genericTypeParameter.hasNext()) ) {
					throw new RewriteEarlyExitException();
				}
				while ( stream_genericTypeParameter.hasNext() ) {
					adaptor.addChild(root_1, stream_genericTypeParameter.nextTree());

				}
				stream_genericTypeParameter.reset();

				adaptor.addChild(root_0, root_1);
				}

			}


			retval.tree = root_0;
			}

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 11, genericTypeParameterList_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "genericTypeParameterList"


	public static class genericTypeListClosing_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "genericTypeListClosing"
	// Java.g:383:1: genericTypeListClosing : ( GREATER_THAN | SHIFT_RIGHT | BIT_SHIFT_RIGHT |);
	public final JavaParser.genericTypeListClosing_return genericTypeListClosing() throws RecognitionException {
		JavaParser.genericTypeListClosing_return retval = new JavaParser.genericTypeListClosing_return();
		retval.start = input.LT(1);
		int genericTypeListClosing_StartIndex = input.index();

		CommonTree root_0 = null;

		Token GREATER_THAN38=null;
		Token SHIFT_RIGHT39=null;
		Token BIT_SHIFT_RIGHT40=null;

		CommonTree GREATER_THAN38_tree=null;
		CommonTree SHIFT_RIGHT39_tree=null;
		CommonTree BIT_SHIFT_RIGHT40_tree=null;

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 12) ) { return retval; }

			// Java.g:387:5: ( GREATER_THAN | SHIFT_RIGHT | BIT_SHIFT_RIGHT |)
			int alt12=4;
			switch ( input.LA(1) ) {
			case GREATER_THAN:
				{
				int LA12_1 = input.LA(2);
				if ( (synpred14_Java()) ) {
					alt12=1;
				}
				else if ( (true) ) {
					alt12=4;
				}
				else {
					if (state.backtracking>0) {state.failed=true; return retval;}
					int nvaeMark = input.mark();
					try {
						input.consume();
						NoViableAltException nvae =
							new NoViableAltException("", 12, 1, input);
						throw nvae;
					} finally {
						input.rewind(nvaeMark);
					}
				}
				}
				break;
			case SHIFT_RIGHT:
				{
				int LA12_2 = input.LA(2);
				if ( (synpred15_Java()) ) {
					alt12=2;
				}
				else if ( (true) ) {
					alt12=4;
				}
				else {
					if (state.backtracking>0) {state.failed=true; return retval;}
					int nvaeMark = input.mark();
					try {
						input.consume();
						NoViableAltException nvae =
							new NoViableAltException("", 12, 2, input);
						throw nvae;
					} finally {
						input.rewind(nvaeMark);
					}
				}
				}
				break;
			case BIT_SHIFT_RIGHT:
				{
				int LA12_3 = input.LA(2);
				if ( (synpred16_Java()) ) {
					alt12=3;
				}
				else if ( (true) ) {
					alt12=4;
				}
				else {
					if (state.backtracking>0) {state.failed=true; return retval;}
					int nvaeMark = input.mark();
					try {
						input.consume();
						NoViableAltException nvae =
							new NoViableAltException("", 12, 3, input);
						throw nvae;
					} finally {
						input.rewind(nvaeMark);
					}
				}
				}
				break;
			case EOF:
			case AND:
			case AND_ASSIGN:
			case ASSIGN:
			case BIT_SHIFT_RIGHT_ASSIGN:
			case BOOLEAN:
			case BYTE:
			case CHAR:
			case COLON:
			case COMMA:
			case DIV_ASSIGN:
			case DOT:
			case DOUBLE:
			case ELLIPSIS:
			case EQUAL:
			case EXTENDS:
			case FLOAT:
			case IDENT:
			case IMPLEMENTS:
			case INT:
			case LBRACK:
			case LCURLY:
			case LOGICAL_AND:
			case LOGICAL_OR:
			case LONG:
			case LPAREN:
			case MINUS_ASSIGN:
			case MOD_ASSIGN:
			case NOT_EQUAL:
			case OR:
			case OR_ASSIGN:
			case PLUS_ASSIGN:
			case QUESTION:
			case RBRACK:
			case RCURLY:
			case RPAREN:
			case SEMI:
			case SHIFT_LEFT_ASSIGN:
			case SHIFT_RIGHT_ASSIGN:
			case SHORT:
			case STAR_ASSIGN:
			case SUPER:
			case THIS:
			case VOID:
			case XOR:
			case XOR_ASSIGN:
				{
				alt12=4;
				}
				break;
			default:
				if (state.backtracking>0) {state.failed=true; return retval;}
				NoViableAltException nvae =
					new NoViableAltException("", 12, 0, input);
				throw nvae;
			}
			switch (alt12) {
				case 1 :
					// Java.g:387:9: GREATER_THAN
					{
					root_0 = (CommonTree)adaptor.nil();


					GREATER_THAN38=(Token)match(input,GREATER_THAN,FOLLOW_GREATER_THAN_in_genericTypeListClosing5119); if (state.failed) return retval;
					if ( state.backtracking==0 ) {
					GREATER_THAN38_tree = 
					(CommonTree)adaptor.create(GREATER_THAN38)
					;
					adaptor.addChild(root_0, GREATER_THAN38_tree);
					}

					}
					break;
				case 2 :
					// Java.g:388:9: SHIFT_RIGHT
					{
					root_0 = (CommonTree)adaptor.nil();


					SHIFT_RIGHT39=(Token)match(input,SHIFT_RIGHT,FOLLOW_SHIFT_RIGHT_in_genericTypeListClosing5129); if (state.failed) return retval;
					if ( state.backtracking==0 ) {
					SHIFT_RIGHT39_tree = 
					(CommonTree)adaptor.create(SHIFT_RIGHT39)
					;
					adaptor.addChild(root_0, SHIFT_RIGHT39_tree);
					}

					}
					break;
				case 3 :
					// Java.g:389:9: BIT_SHIFT_RIGHT
					{
					root_0 = (CommonTree)adaptor.nil();


					BIT_SHIFT_RIGHT40=(Token)match(input,BIT_SHIFT_RIGHT,FOLLOW_BIT_SHIFT_RIGHT_in_genericTypeListClosing5139); if (state.failed) return retval;
					if ( state.backtracking==0 ) {
					BIT_SHIFT_RIGHT40_tree = 
					(CommonTree)adaptor.create(BIT_SHIFT_RIGHT40)
					;
					adaptor.addChild(root_0, BIT_SHIFT_RIGHT40_tree);
					}

					}
					break;
				case 4 :
					// Java.g:391:5: 
					{
					root_0 = (CommonTree)adaptor.nil();


					}
					break;

			}
			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 12, genericTypeListClosing_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "genericTypeListClosing"


	public static class genericTypeParameter_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "genericTypeParameter"
	// Java.g:393:1: genericTypeParameter : IDENT ( bound )? -> ^( IDENT ( bound )? ) ;
	public final JavaParser.genericTypeParameter_return genericTypeParameter() throws RecognitionException {
		JavaParser.genericTypeParameter_return retval = new JavaParser.genericTypeParameter_return();
		retval.start = input.LT(1);
		int genericTypeParameter_StartIndex = input.index();

		CommonTree root_0 = null;

		Token IDENT41=null;
		ParserRuleReturnScope bound42 =null;

		CommonTree IDENT41_tree=null;
		RewriteRuleTokenStream stream_IDENT=new RewriteRuleTokenStream(adaptor,"token IDENT");
		RewriteRuleSubtreeStream stream_bound=new RewriteRuleSubtreeStream(adaptor,"rule bound");

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 13) ) { return retval; }

			// Java.g:394:5: ( IDENT ( bound )? -> ^( IDENT ( bound )? ) )
			// Java.g:394:9: IDENT ( bound )?
			{
			IDENT41=(Token)match(input,IDENT,FOLLOW_IDENT_in_genericTypeParameter5167); if (state.failed) return retval; 
			if ( state.backtracking==0 ) stream_IDENT.add(IDENT41);

			// Java.g:394:15: ( bound )?
			int alt13=2;
			int LA13_0 = input.LA(1);
			if ( (LA13_0==EXTENDS) ) {
				int LA13_1 = input.LA(2);
				if ( (LA13_1==BOOLEAN||LA13_1==BYTE||LA13_1==CHAR||LA13_1==DOUBLE||LA13_1==FLOAT||LA13_1==INT||LA13_1==LONG||LA13_1==SHORT) ) {
					int LA13_3 = input.LA(3);
					if ( (synpred17_Java()) ) {
						alt13=1;
					}
				}
				else if ( (LA13_1==IDENT) ) {
					int LA13_4 = input.LA(3);
					if ( (synpred17_Java()) ) {
						alt13=1;
					}
				}
			}
			switch (alt13) {
				case 1 :
					// Java.g:394:15: bound
					{
					pushFollow(FOLLOW_bound_in_genericTypeParameter5169);
					bound42=bound();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_bound.add(bound42.getTree());
					}
					break;

			}

			// AST REWRITE
			// elements: bound, IDENT
			// token labels: 
			// rule labels: retval
			// token list labels: 
			// rule list labels: 
			// wildcard labels: 
			if ( state.backtracking==0 ) {

			retval.tree = root_0;
			RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

			root_0 = (CommonTree)adaptor.nil();
			// 395:9: -> ^( IDENT ( bound )? )
			{
				// Java.g:395:13: ^( IDENT ( bound )? )
				{
				CommonTree root_1 = (CommonTree)adaptor.nil();
				root_1 = (CommonTree)adaptor.becomeRoot(
				stream_IDENT.nextNode()
				, root_1);

				// Java.g:395:21: ( bound )?
				if ( stream_bound.hasNext() ) {
					adaptor.addChild(root_1, stream_bound.nextTree());

				}
				stream_bound.reset();

				adaptor.addChild(root_0, root_1);
				}

			}


			retval.tree = root_0;
			}

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 13, genericTypeParameter_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "genericTypeParameter"


	public static class bound_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "bound"
	// Java.g:398:1: bound : EXTENDS type ( AND type )* -> ^( EXTENDS_BOUND_LIST[$EXTENDS, \"EXTENDS_BOUND_LIST\"] ( type )+ ) ;
	public final JavaParser.bound_return bound() throws RecognitionException {
		JavaParser.bound_return retval = new JavaParser.bound_return();
		retval.start = input.LT(1);
		int bound_StartIndex = input.index();

		CommonTree root_0 = null;

		Token EXTENDS43=null;
		Token AND45=null;
		ParserRuleReturnScope type44 =null;
		ParserRuleReturnScope type46 =null;

		CommonTree EXTENDS43_tree=null;
		CommonTree AND45_tree=null;
		RewriteRuleTokenStream stream_AND=new RewriteRuleTokenStream(adaptor,"token AND");
		RewriteRuleTokenStream stream_EXTENDS=new RewriteRuleTokenStream(adaptor,"token EXTENDS");
		RewriteRuleSubtreeStream stream_type=new RewriteRuleSubtreeStream(adaptor,"rule type");

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 14) ) { return retval; }

			// Java.g:399:5: ( EXTENDS type ( AND type )* -> ^( EXTENDS_BOUND_LIST[$EXTENDS, \"EXTENDS_BOUND_LIST\"] ( type )+ ) )
			// Java.g:399:9: EXTENDS type ( AND type )*
			{
			EXTENDS43=(Token)match(input,EXTENDS,FOLLOW_EXTENDS_in_bound5215); if (state.failed) return retval; 
			if ( state.backtracking==0 ) stream_EXTENDS.add(EXTENDS43);

			pushFollow(FOLLOW_type_in_bound5217);
			type44=type();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) stream_type.add(type44.getTree());
			// Java.g:399:22: ( AND type )*
			loop14:
			do {
				int alt14=2;
				int LA14_0 = input.LA(1);
				if ( (LA14_0==AND) ) {
					alt14=1;
				}

				switch (alt14) {
				case 1 :
					// Java.g:399:23: AND type
					{
					AND45=(Token)match(input,AND,FOLLOW_AND_in_bound5220); if (state.failed) return retval; 
					if ( state.backtracking==0 ) stream_AND.add(AND45);

					pushFollow(FOLLOW_type_in_bound5222);
					type46=type();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_type.add(type46.getTree());
					}
					break;

				default :
					break loop14;
				}
			} while (true);

			// AST REWRITE
			// elements: type
			// token labels: 
			// rule labels: retval
			// token list labels: 
			// rule list labels: 
			// wildcard labels: 
			if ( state.backtracking==0 ) {

			retval.tree = root_0;
			RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

			root_0 = (CommonTree)adaptor.nil();
			// 400:9: -> ^( EXTENDS_BOUND_LIST[$EXTENDS, \"EXTENDS_BOUND_LIST\"] ( type )+ )
			{
				// Java.g:400:13: ^( EXTENDS_BOUND_LIST[$EXTENDS, \"EXTENDS_BOUND_LIST\"] ( type )+ )
				{
				CommonTree root_1 = (CommonTree)adaptor.nil();
				root_1 = (CommonTree)adaptor.becomeRoot(
				(CommonTree)adaptor.create(EXTENDS_BOUND_LIST, EXTENDS43, "EXTENDS_BOUND_LIST")
				, root_1);

				if ( !(stream_type.hasNext()) ) {
					throw new RewriteEarlyExitException();
				}
				while ( stream_type.hasNext() ) {
					adaptor.addChild(root_1, stream_type.nextTree());

				}
				stream_type.reset();

				adaptor.addChild(root_0, root_1);
				}

			}


			retval.tree = root_0;
			}

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 14, bound_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "bound"


	public static class enumTypeDeclaration_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "enumTypeDeclaration"
	// Java.g:403:1: enumTypeDeclaration[CommonTree modifiers] : ENUM IDENT ( implementsClause )? enumBody -> ^( ENUM IDENT ( implementsClause )? enumBody ) ;
	public final JavaParser.enumTypeDeclaration_return enumTypeDeclaration(CommonTree modifiers) throws RecognitionException {
		JavaParser.enumTypeDeclaration_return retval = new JavaParser.enumTypeDeclaration_return();
		retval.start = input.LT(1);
		int enumTypeDeclaration_StartIndex = input.index();

		CommonTree root_0 = null;

		Token ENUM47=null;
		Token IDENT48=null;
		ParserRuleReturnScope implementsClause49 =null;
		ParserRuleReturnScope enumBody50 =null;

		CommonTree ENUM47_tree=null;
		CommonTree IDENT48_tree=null;
		RewriteRuleTokenStream stream_IDENT=new RewriteRuleTokenStream(adaptor,"token IDENT");
		RewriteRuleTokenStream stream_ENUM=new RewriteRuleTokenStream(adaptor,"token ENUM");
		RewriteRuleSubtreeStream stream_implementsClause=new RewriteRuleSubtreeStream(adaptor,"rule implementsClause");
		RewriteRuleSubtreeStream stream_enumBody=new RewriteRuleSubtreeStream(adaptor,"rule enumBody");

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 15) ) { return retval; }

			// Java.g:404:5: ( ENUM IDENT ( implementsClause )? enumBody -> ^( ENUM IDENT ( implementsClause )? enumBody ) )
			// Java.g:404:9: ENUM IDENT ( implementsClause )? enumBody
			{
			ENUM47=(Token)match(input,ENUM,FOLLOW_ENUM_in_enumTypeDeclaration5263); if (state.failed) return retval; 
			if ( state.backtracking==0 ) stream_ENUM.add(ENUM47);

			IDENT48=(Token)match(input,IDENT,FOLLOW_IDENT_in_enumTypeDeclaration5265); if (state.failed) return retval; 
			if ( state.backtracking==0 ) stream_IDENT.add(IDENT48);

			// Java.g:404:20: ( implementsClause )?
			int alt15=2;
			int LA15_0 = input.LA(1);
			if ( (LA15_0==IMPLEMENTS) ) {
				alt15=1;
			}
			switch (alt15) {
				case 1 :
					// Java.g:404:20: implementsClause
					{
					pushFollow(FOLLOW_implementsClause_in_enumTypeDeclaration5267);
					implementsClause49=implementsClause();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_implementsClause.add(implementsClause49.getTree());
					}
					break;

			}

			pushFollow(FOLLOW_enumBody_in_enumTypeDeclaration5270);
			enumBody50=enumBody();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) stream_enumBody.add(enumBody50.getTree());
			// AST REWRITE
			// elements: ENUM, enumBody, implementsClause, IDENT
			// token labels: 
			// rule labels: retval
			// token list labels: 
			// rule list labels: 
			// wildcard labels: 
			if ( state.backtracking==0 ) {

			retval.tree = root_0;
			RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

			root_0 = (CommonTree)adaptor.nil();
			// 405:9: -> ^( ENUM IDENT ( implementsClause )? enumBody )
			{
				// Java.g:405:13: ^( ENUM IDENT ( implementsClause )? enumBody )
				{
				CommonTree root_1 = (CommonTree)adaptor.nil();
				root_1 = (CommonTree)adaptor.becomeRoot(
				stream_ENUM.nextNode()
				, root_1);

				adaptor.addChild(root_1, modifiers);

				adaptor.addChild(root_1, 
				stream_IDENT.nextNode()
				);

				// Java.g:405:39: ( implementsClause )?
				if ( stream_implementsClause.hasNext() ) {
					adaptor.addChild(root_1, stream_implementsClause.nextTree());

				}
				stream_implementsClause.reset();

				adaptor.addChild(root_1, stream_enumBody.nextTree());

				adaptor.addChild(root_0, root_1);
				}

			}


			retval.tree = root_0;
			}

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 15, enumTypeDeclaration_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "enumTypeDeclaration"


	public static class enumBody_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "enumBody"
	// Java.g:408:1: enumBody : LCURLY enumScopeDeclarations RCURLY -> ^( ENUM_TOP_LEVEL_SCOPE[$LCURLY, \"ENUM_TOP_LEVEL_SCOPE\"] enumScopeDeclarations ) ;
	public final JavaParser.enumBody_return enumBody() throws RecognitionException {
		JavaParser.enumBody_return retval = new JavaParser.enumBody_return();
		retval.start = input.LT(1);
		int enumBody_StartIndex = input.index();

		CommonTree root_0 = null;

		Token LCURLY51=null;
		Token RCURLY53=null;
		ParserRuleReturnScope enumScopeDeclarations52 =null;

		CommonTree LCURLY51_tree=null;
		CommonTree RCURLY53_tree=null;
		RewriteRuleTokenStream stream_LCURLY=new RewriteRuleTokenStream(adaptor,"token LCURLY");
		RewriteRuleTokenStream stream_RCURLY=new RewriteRuleTokenStream(adaptor,"token RCURLY");
		RewriteRuleSubtreeStream stream_enumScopeDeclarations=new RewriteRuleSubtreeStream(adaptor,"rule enumScopeDeclarations");

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 16) ) { return retval; }

			// Java.g:409:5: ( LCURLY enumScopeDeclarations RCURLY -> ^( ENUM_TOP_LEVEL_SCOPE[$LCURLY, \"ENUM_TOP_LEVEL_SCOPE\"] enumScopeDeclarations ) )
			// Java.g:409:9: LCURLY enumScopeDeclarations RCURLY
			{
			LCURLY51=(Token)match(input,LCURLY,FOLLOW_LCURLY_in_enumBody5317); if (state.failed) return retval; 
			if ( state.backtracking==0 ) stream_LCURLY.add(LCURLY51);

			pushFollow(FOLLOW_enumScopeDeclarations_in_enumBody5319);
			enumScopeDeclarations52=enumScopeDeclarations();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) stream_enumScopeDeclarations.add(enumScopeDeclarations52.getTree());
			RCURLY53=(Token)match(input,RCURLY,FOLLOW_RCURLY_in_enumBody5321); if (state.failed) return retval; 
			if ( state.backtracking==0 ) stream_RCURLY.add(RCURLY53);

			// AST REWRITE
			// elements: enumScopeDeclarations
			// token labels: 
			// rule labels: retval
			// token list labels: 
			// rule list labels: 
			// wildcard labels: 
			if ( state.backtracking==0 ) {

			retval.tree = root_0;
			RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

			root_0 = (CommonTree)adaptor.nil();
			// 410:9: -> ^( ENUM_TOP_LEVEL_SCOPE[$LCURLY, \"ENUM_TOP_LEVEL_SCOPE\"] enumScopeDeclarations )
			{
				// Java.g:410:13: ^( ENUM_TOP_LEVEL_SCOPE[$LCURLY, \"ENUM_TOP_LEVEL_SCOPE\"] enumScopeDeclarations )
				{
				CommonTree root_1 = (CommonTree)adaptor.nil();
				root_1 = (CommonTree)adaptor.becomeRoot(
				(CommonTree)adaptor.create(ENUM_TOP_LEVEL_SCOPE, LCURLY51, "ENUM_TOP_LEVEL_SCOPE")
				, root_1);

				adaptor.addChild(root_1, stream_enumScopeDeclarations.nextTree());

				adaptor.addChild(root_0, root_1);
				}

			}


			retval.tree = root_0;
			}

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 16, enumBody_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "enumBody"


	public static class enumScopeDeclarations_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "enumScopeDeclarations"
	// Java.g:413:1: enumScopeDeclarations : enumConstants ( COMMA !)? ( enumClassScopeDeclarations )? ;
	public final JavaParser.enumScopeDeclarations_return enumScopeDeclarations() throws RecognitionException {
		JavaParser.enumScopeDeclarations_return retval = new JavaParser.enumScopeDeclarations_return();
		retval.start = input.LT(1);
		int enumScopeDeclarations_StartIndex = input.index();

		CommonTree root_0 = null;

		Token COMMA55=null;
		ParserRuleReturnScope enumConstants54 =null;
		ParserRuleReturnScope enumClassScopeDeclarations56 =null;

		CommonTree COMMA55_tree=null;

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 17) ) { return retval; }

			// Java.g:414:5: ( enumConstants ( COMMA !)? ( enumClassScopeDeclarations )? )
			// Java.g:414:9: enumConstants ( COMMA !)? ( enumClassScopeDeclarations )?
			{
			root_0 = (CommonTree)adaptor.nil();


			pushFollow(FOLLOW_enumConstants_in_enumScopeDeclarations5358);
			enumConstants54=enumConstants();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) adaptor.addChild(root_0, enumConstants54.getTree());

			// Java.g:414:23: ( COMMA !)?
			int alt16=2;
			int LA16_0 = input.LA(1);
			if ( (LA16_0==COMMA) ) {
				alt16=1;
			}
			switch (alt16) {
				case 1 :
					// Java.g:414:24: COMMA !
					{
					COMMA55=(Token)match(input,COMMA,FOLLOW_COMMA_in_enumScopeDeclarations5361); if (state.failed) return retval;
					}
					break;

			}

			// Java.g:414:33: ( enumClassScopeDeclarations )?
			int alt17=2;
			int LA17_0 = input.LA(1);
			if ( (LA17_0==SEMI) ) {
				alt17=1;
			}
			switch (alt17) {
				case 1 :
					// Java.g:414:33: enumClassScopeDeclarations
					{
					pushFollow(FOLLOW_enumClassScopeDeclarations_in_enumScopeDeclarations5366);
					enumClassScopeDeclarations56=enumClassScopeDeclarations();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) adaptor.addChild(root_0, enumClassScopeDeclarations56.getTree());

					}
					break;

			}

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 17, enumScopeDeclarations_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "enumScopeDeclarations"


	public static class enumClassScopeDeclarations_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "enumClassScopeDeclarations"
	// Java.g:417:1: enumClassScopeDeclarations : SEMI ( classScopeDeclarations )* -> ^( CLASS_TOP_LEVEL_SCOPE[$SEMI, \"CLASS_TOP_LEVEL_SCOPE\"] ( classScopeDeclarations )* ) ;
	public final JavaParser.enumClassScopeDeclarations_return enumClassScopeDeclarations() throws RecognitionException {
		JavaParser.enumClassScopeDeclarations_return retval = new JavaParser.enumClassScopeDeclarations_return();
		retval.start = input.LT(1);
		int enumClassScopeDeclarations_StartIndex = input.index();

		CommonTree root_0 = null;

		Token SEMI57=null;
		ParserRuleReturnScope classScopeDeclarations58 =null;

		CommonTree SEMI57_tree=null;
		RewriteRuleTokenStream stream_SEMI=new RewriteRuleTokenStream(adaptor,"token SEMI");
		RewriteRuleSubtreeStream stream_classScopeDeclarations=new RewriteRuleSubtreeStream(adaptor,"rule classScopeDeclarations");

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 18) ) { return retval; }

			// Java.g:418:5: ( SEMI ( classScopeDeclarations )* -> ^( CLASS_TOP_LEVEL_SCOPE[$SEMI, \"CLASS_TOP_LEVEL_SCOPE\"] ( classScopeDeclarations )* ) )
			// Java.g:418:9: SEMI ( classScopeDeclarations )*
			{
			SEMI57=(Token)match(input,SEMI,FOLLOW_SEMI_in_enumClassScopeDeclarations5386); if (state.failed) return retval; 
			if ( state.backtracking==0 ) stream_SEMI.add(SEMI57);

			// Java.g:418:14: ( classScopeDeclarations )*
			loop18:
			do {
				int alt18=2;
				int LA18_0 = input.LA(1);
				if ( (LA18_0==ABSTRACT||LA18_0==AT||LA18_0==BOOLEAN||LA18_0==BYTE||LA18_0==CHAR||LA18_0==CLASS||LA18_0==DOUBLE||LA18_0==ENUM||LA18_0==FINAL||LA18_0==FLOAT||LA18_0==IDENT||LA18_0==INT||LA18_0==INTERFACE||LA18_0==LCURLY||LA18_0==LESS_THAN||LA18_0==LONG||LA18_0==NATIVE||(LA18_0 >= PRIVATE && LA18_0 <= PUBLIC)||LA18_0==SEMI||LA18_0==SHORT||LA18_0==STATIC||LA18_0==STRICTFP||LA18_0==SYNCHRONIZED||LA18_0==TRANSIENT||LA18_0==VOID||LA18_0==VOLATILE) ) {
					alt18=1;
				}

				switch (alt18) {
				case 1 :
					// Java.g:418:14: classScopeDeclarations
					{
					pushFollow(FOLLOW_classScopeDeclarations_in_enumClassScopeDeclarations5388);
					classScopeDeclarations58=classScopeDeclarations();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_classScopeDeclarations.add(classScopeDeclarations58.getTree());
					}
					break;

				default :
					break loop18;
				}
			} while (true);

			// AST REWRITE
			// elements: classScopeDeclarations
			// token labels: 
			// rule labels: retval
			// token list labels: 
			// rule list labels: 
			// wildcard labels: 
			if ( state.backtracking==0 ) {

			retval.tree = root_0;
			RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

			root_0 = (CommonTree)adaptor.nil();
			// 419:9: -> ^( CLASS_TOP_LEVEL_SCOPE[$SEMI, \"CLASS_TOP_LEVEL_SCOPE\"] ( classScopeDeclarations )* )
			{
				// Java.g:419:13: ^( CLASS_TOP_LEVEL_SCOPE[$SEMI, \"CLASS_TOP_LEVEL_SCOPE\"] ( classScopeDeclarations )* )
				{
				CommonTree root_1 = (CommonTree)adaptor.nil();
				root_1 = (CommonTree)adaptor.becomeRoot(
				(CommonTree)adaptor.create(CLASS_TOP_LEVEL_SCOPE, SEMI57, "CLASS_TOP_LEVEL_SCOPE")
				, root_1);

				// Java.g:419:69: ( classScopeDeclarations )*
				while ( stream_classScopeDeclarations.hasNext() ) {
					adaptor.addChild(root_1, stream_classScopeDeclarations.nextTree());

				}
				stream_classScopeDeclarations.reset();

				adaptor.addChild(root_0, root_1);
				}

			}


			retval.tree = root_0;
			}

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 18, enumClassScopeDeclarations_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "enumClassScopeDeclarations"


	public static class enumConstants_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "enumConstants"
	// Java.g:422:1: enumConstants : enumConstant ( COMMA ! enumConstant )* ;
	public final JavaParser.enumConstants_return enumConstants() throws RecognitionException {
		JavaParser.enumConstants_return retval = new JavaParser.enumConstants_return();
		retval.start = input.LT(1);
		int enumConstants_StartIndex = input.index();

		CommonTree root_0 = null;

		Token COMMA60=null;
		ParserRuleReturnScope enumConstant59 =null;
		ParserRuleReturnScope enumConstant61 =null;

		CommonTree COMMA60_tree=null;

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 19) ) { return retval; }

			// Java.g:423:5: ( enumConstant ( COMMA ! enumConstant )* )
			// Java.g:423:9: enumConstant ( COMMA ! enumConstant )*
			{
			root_0 = (CommonTree)adaptor.nil();


			pushFollow(FOLLOW_enumConstant_in_enumConstants5427);
			enumConstant59=enumConstant();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) adaptor.addChild(root_0, enumConstant59.getTree());

			// Java.g:423:22: ( COMMA ! enumConstant )*
			loop19:
			do {
				int alt19=2;
				int LA19_0 = input.LA(1);
				if ( (LA19_0==COMMA) ) {
					int LA19_1 = input.LA(2);
					if ( (LA19_1==AT||LA19_1==IDENT) ) {
						alt19=1;
					}

				}

				switch (alt19) {
				case 1 :
					// Java.g:423:23: COMMA ! enumConstant
					{
					COMMA60=(Token)match(input,COMMA,FOLLOW_COMMA_in_enumConstants5430); if (state.failed) return retval;
					pushFollow(FOLLOW_enumConstant_in_enumConstants5433);
					enumConstant61=enumConstant();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) adaptor.addChild(root_0, enumConstant61.getTree());

					}
					break;

				default :
					break loop19;
				}
			} while (true);

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 19, enumConstants_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "enumConstants"


	public static class enumConstant_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "enumConstant"
	// Java.g:426:1: enumConstant : annotationList IDENT ^ ( arguments )? ( classBody )? ;
	public final JavaParser.enumConstant_return enumConstant() throws RecognitionException {
		JavaParser.enumConstant_return retval = new JavaParser.enumConstant_return();
		retval.start = input.LT(1);
		int enumConstant_StartIndex = input.index();

		CommonTree root_0 = null;

		Token IDENT63=null;
		ParserRuleReturnScope annotationList62 =null;
		ParserRuleReturnScope arguments64 =null;
		ParserRuleReturnScope classBody65 =null;

		CommonTree IDENT63_tree=null;

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 20) ) { return retval; }

			// Java.g:427:5: ( annotationList IDENT ^ ( arguments )? ( classBody )? )
			// Java.g:427:9: annotationList IDENT ^ ( arguments )? ( classBody )?
			{
			root_0 = (CommonTree)adaptor.nil();


			pushFollow(FOLLOW_annotationList_in_enumConstant5458);
			annotationList62=annotationList();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) adaptor.addChild(root_0, annotationList62.getTree());

			IDENT63=(Token)match(input,IDENT,FOLLOW_IDENT_in_enumConstant5460); if (state.failed) return retval;
			if ( state.backtracking==0 ) {
			IDENT63_tree = 
			(CommonTree)adaptor.create(IDENT63)
			;
			root_0 = (CommonTree)adaptor.becomeRoot(IDENT63_tree, root_0);
			}

			// Java.g:427:31: ( arguments )?
			int alt20=2;
			int LA20_0 = input.LA(1);
			if ( (LA20_0==LPAREN) ) {
				alt20=1;
			}
			switch (alt20) {
				case 1 :
					// Java.g:427:31: arguments
					{
					pushFollow(FOLLOW_arguments_in_enumConstant5463);
					arguments64=arguments();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) adaptor.addChild(root_0, arguments64.getTree());

					}
					break;

			}

			// Java.g:427:42: ( classBody )?
			int alt21=2;
			int LA21_0 = input.LA(1);
			if ( (LA21_0==LCURLY) ) {
				alt21=1;
			}
			switch (alt21) {
				case 1 :
					// Java.g:427:42: classBody
					{
					pushFollow(FOLLOW_classBody_in_enumConstant5466);
					classBody65=classBody();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) adaptor.addChild(root_0, classBody65.getTree());

					}
					break;

			}

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 20, enumConstant_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "enumConstant"


	public static class interfaceTypeDeclaration_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "interfaceTypeDeclaration"
	// Java.g:430:1: interfaceTypeDeclaration[CommonTree modifiers] : INTERFACE IDENT ( genericTypeParameterList )? ( interfaceExtendsClause )? interfaceBody -> ^( INTERFACE IDENT ( genericTypeParameterList )? ( interfaceExtendsClause )? interfaceBody ) ;
	public final JavaParser.interfaceTypeDeclaration_return interfaceTypeDeclaration(CommonTree modifiers) throws RecognitionException {
		JavaParser.interfaceTypeDeclaration_return retval = new JavaParser.interfaceTypeDeclaration_return();
		retval.start = input.LT(1);
		int interfaceTypeDeclaration_StartIndex = input.index();

		CommonTree root_0 = null;

		Token INTERFACE66=null;
		Token IDENT67=null;
		ParserRuleReturnScope genericTypeParameterList68 =null;
		ParserRuleReturnScope interfaceExtendsClause69 =null;
		ParserRuleReturnScope interfaceBody70 =null;

		CommonTree INTERFACE66_tree=null;
		CommonTree IDENT67_tree=null;
		RewriteRuleTokenStream stream_IDENT=new RewriteRuleTokenStream(adaptor,"token IDENT");
		RewriteRuleTokenStream stream_INTERFACE=new RewriteRuleTokenStream(adaptor,"token INTERFACE");
		RewriteRuleSubtreeStream stream_genericTypeParameterList=new RewriteRuleSubtreeStream(adaptor,"rule genericTypeParameterList");
		RewriteRuleSubtreeStream stream_interfaceBody=new RewriteRuleSubtreeStream(adaptor,"rule interfaceBody");
		RewriteRuleSubtreeStream stream_interfaceExtendsClause=new RewriteRuleSubtreeStream(adaptor,"rule interfaceExtendsClause");

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 21) ) { return retval; }

			// Java.g:431:5: ( INTERFACE IDENT ( genericTypeParameterList )? ( interfaceExtendsClause )? interfaceBody -> ^( INTERFACE IDENT ( genericTypeParameterList )? ( interfaceExtendsClause )? interfaceBody ) )
			// Java.g:431:9: INTERFACE IDENT ( genericTypeParameterList )? ( interfaceExtendsClause )? interfaceBody
			{
			INTERFACE66=(Token)match(input,INTERFACE,FOLLOW_INTERFACE_in_interfaceTypeDeclaration5491); if (state.failed) return retval; 
			if ( state.backtracking==0 ) stream_INTERFACE.add(INTERFACE66);

			IDENT67=(Token)match(input,IDENT,FOLLOW_IDENT_in_interfaceTypeDeclaration5493); if (state.failed) return retval; 
			if ( state.backtracking==0 ) stream_IDENT.add(IDENT67);

			// Java.g:431:25: ( genericTypeParameterList )?
			int alt22=2;
			int LA22_0 = input.LA(1);
			if ( (LA22_0==LESS_THAN) ) {
				alt22=1;
			}
			switch (alt22) {
				case 1 :
					// Java.g:431:25: genericTypeParameterList
					{
					pushFollow(FOLLOW_genericTypeParameterList_in_interfaceTypeDeclaration5495);
					genericTypeParameterList68=genericTypeParameterList();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_genericTypeParameterList.add(genericTypeParameterList68.getTree());
					}
					break;

			}

			// Java.g:431:51: ( interfaceExtendsClause )?
			int alt23=2;
			int LA23_0 = input.LA(1);
			if ( (LA23_0==EXTENDS) ) {
				alt23=1;
			}
			switch (alt23) {
				case 1 :
					// Java.g:431:51: interfaceExtendsClause
					{
					pushFollow(FOLLOW_interfaceExtendsClause_in_interfaceTypeDeclaration5498);
					interfaceExtendsClause69=interfaceExtendsClause();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_interfaceExtendsClause.add(interfaceExtendsClause69.getTree());
					}
					break;

			}

			pushFollow(FOLLOW_interfaceBody_in_interfaceTypeDeclaration5501);
			interfaceBody70=interfaceBody();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) stream_interfaceBody.add(interfaceBody70.getTree());
			// AST REWRITE
			// elements: INTERFACE, genericTypeParameterList, IDENT, interfaceExtendsClause, interfaceBody
			// token labels: 
			// rule labels: retval
			// token list labels: 
			// rule list labels: 
			// wildcard labels: 
			if ( state.backtracking==0 ) {

			retval.tree = root_0;
			RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

			root_0 = (CommonTree)adaptor.nil();
			// 432:9: -> ^( INTERFACE IDENT ( genericTypeParameterList )? ( interfaceExtendsClause )? interfaceBody )
			{
				// Java.g:432:13: ^( INTERFACE IDENT ( genericTypeParameterList )? ( interfaceExtendsClause )? interfaceBody )
				{
				CommonTree root_1 = (CommonTree)adaptor.nil();
				root_1 = (CommonTree)adaptor.becomeRoot(
				stream_INTERFACE.nextNode()
				, root_1);

				adaptor.addChild(root_1, modifiers);

				adaptor.addChild(root_1, 
				stream_IDENT.nextNode()
				);

				// Java.g:432:44: ( genericTypeParameterList )?
				if ( stream_genericTypeParameterList.hasNext() ) {
					adaptor.addChild(root_1, stream_genericTypeParameterList.nextTree());

				}
				stream_genericTypeParameterList.reset();

				// Java.g:432:70: ( interfaceExtendsClause )?
				if ( stream_interfaceExtendsClause.hasNext() ) {
					adaptor.addChild(root_1, stream_interfaceExtendsClause.nextTree());

				}
				stream_interfaceExtendsClause.reset();

				adaptor.addChild(root_1, stream_interfaceBody.nextTree());

				adaptor.addChild(root_0, root_1);
				}

			}


			retval.tree = root_0;
			}

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 21, interfaceTypeDeclaration_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "interfaceTypeDeclaration"


	public static class typeList_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "typeList"
	// Java.g:435:1: typeList : type ( COMMA ! type )* ;
	public final JavaParser.typeList_return typeList() throws RecognitionException {
		JavaParser.typeList_return retval = new JavaParser.typeList_return();
		retval.start = input.LT(1);
		int typeList_StartIndex = input.index();

		CommonTree root_0 = null;

		Token COMMA72=null;
		ParserRuleReturnScope type71 =null;
		ParserRuleReturnScope type73 =null;

		CommonTree COMMA72_tree=null;

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 22) ) { return retval; }

			// Java.g:436:5: ( type ( COMMA ! type )* )
			// Java.g:436:9: type ( COMMA ! type )*
			{
			root_0 = (CommonTree)adaptor.nil();


			pushFollow(FOLLOW_type_in_typeList5551);
			type71=type();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) adaptor.addChild(root_0, type71.getTree());

			// Java.g:436:14: ( COMMA ! type )*
			loop24:
			do {
				int alt24=2;
				int LA24_0 = input.LA(1);
				if ( (LA24_0==COMMA) ) {
					alt24=1;
				}

				switch (alt24) {
				case 1 :
					// Java.g:436:15: COMMA ! type
					{
					COMMA72=(Token)match(input,COMMA,FOLLOW_COMMA_in_typeList5554); if (state.failed) return retval;
					pushFollow(FOLLOW_type_in_typeList5557);
					type73=type();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) adaptor.addChild(root_0, type73.getTree());

					}
					break;

				default :
					break loop24;
				}
			} while (true);

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 22, typeList_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "typeList"


	public static class classBody_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "classBody"
	// Java.g:439:1: classBody : LCURLY ( classScopeDeclarations )* RCURLY -> ^( CLASS_TOP_LEVEL_SCOPE[$LCURLY, \"CLASS_TOP_LEVEL_SCOPE\"] ( classScopeDeclarations )* ) ;
	public final JavaParser.classBody_return classBody() throws RecognitionException {
		JavaParser.classBody_return retval = new JavaParser.classBody_return();
		retval.start = input.LT(1);
		int classBody_StartIndex = input.index();

		CommonTree root_0 = null;

		Token LCURLY74=null;
		Token RCURLY76=null;
		ParserRuleReturnScope classScopeDeclarations75 =null;

		CommonTree LCURLY74_tree=null;
		CommonTree RCURLY76_tree=null;
		RewriteRuleTokenStream stream_LCURLY=new RewriteRuleTokenStream(adaptor,"token LCURLY");
		RewriteRuleTokenStream stream_RCURLY=new RewriteRuleTokenStream(adaptor,"token RCURLY");
		RewriteRuleSubtreeStream stream_classScopeDeclarations=new RewriteRuleSubtreeStream(adaptor,"rule classScopeDeclarations");

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 23) ) { return retval; }

			// Java.g:440:5: ( LCURLY ( classScopeDeclarations )* RCURLY -> ^( CLASS_TOP_LEVEL_SCOPE[$LCURLY, \"CLASS_TOP_LEVEL_SCOPE\"] ( classScopeDeclarations )* ) )
			// Java.g:440:9: LCURLY ( classScopeDeclarations )* RCURLY
			{
			LCURLY74=(Token)match(input,LCURLY,FOLLOW_LCURLY_in_classBody5582); if (state.failed) return retval; 
			if ( state.backtracking==0 ) stream_LCURLY.add(LCURLY74);

			// Java.g:440:16: ( classScopeDeclarations )*
			loop25:
			do {
				int alt25=2;
				int LA25_0 = input.LA(1);
				if ( (LA25_0==ABSTRACT||LA25_0==AT||LA25_0==BOOLEAN||LA25_0==BYTE||LA25_0==CHAR||LA25_0==CLASS||LA25_0==DOUBLE||LA25_0==ENUM||LA25_0==FINAL||LA25_0==FLOAT||LA25_0==IDENT||LA25_0==INT||LA25_0==INTERFACE||LA25_0==LCURLY||LA25_0==LESS_THAN||LA25_0==LONG||LA25_0==NATIVE||(LA25_0 >= PRIVATE && LA25_0 <= PUBLIC)||LA25_0==SEMI||LA25_0==SHORT||LA25_0==STATIC||LA25_0==STRICTFP||LA25_0==SYNCHRONIZED||LA25_0==TRANSIENT||LA25_0==VOID||LA25_0==VOLATILE) ) {
					alt25=1;
				}

				switch (alt25) {
				case 1 :
					// Java.g:440:16: classScopeDeclarations
					{
					pushFollow(FOLLOW_classScopeDeclarations_in_classBody5584);
					classScopeDeclarations75=classScopeDeclarations();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_classScopeDeclarations.add(classScopeDeclarations75.getTree());
					}
					break;

				default :
					break loop25;
				}
			} while (true);

			RCURLY76=(Token)match(input,RCURLY,FOLLOW_RCURLY_in_classBody5587); if (state.failed) return retval; 
			if ( state.backtracking==0 ) stream_RCURLY.add(RCURLY76);

			// AST REWRITE
			// elements: classScopeDeclarations
			// token labels: 
			// rule labels: retval
			// token list labels: 
			// rule list labels: 
			// wildcard labels: 
			if ( state.backtracking==0 ) {

			retval.tree = root_0;
			RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

			root_0 = (CommonTree)adaptor.nil();
			// 441:9: -> ^( CLASS_TOP_LEVEL_SCOPE[$LCURLY, \"CLASS_TOP_LEVEL_SCOPE\"] ( classScopeDeclarations )* )
			{
				// Java.g:441:13: ^( CLASS_TOP_LEVEL_SCOPE[$LCURLY, \"CLASS_TOP_LEVEL_SCOPE\"] ( classScopeDeclarations )* )
				{
				CommonTree root_1 = (CommonTree)adaptor.nil();
				root_1 = (CommonTree)adaptor.becomeRoot(
				(CommonTree)adaptor.create(CLASS_TOP_LEVEL_SCOPE, LCURLY74, "CLASS_TOP_LEVEL_SCOPE")
				, root_1);

				// Java.g:441:71: ( classScopeDeclarations )*
				while ( stream_classScopeDeclarations.hasNext() ) {
					adaptor.addChild(root_1, stream_classScopeDeclarations.nextTree());

				}
				stream_classScopeDeclarations.reset();

				adaptor.addChild(root_0, root_1);
				}

			}


			retval.tree = root_0;
			}

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 23, classBody_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "classBody"


	public static class interfaceBody_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "interfaceBody"
	// Java.g:444:1: interfaceBody : LCURLY ( interfaceScopeDeclarations )* RCURLY -> ^( INTERFACE_TOP_LEVEL_SCOPE[$LCURLY, \"CLASS_TOP_LEVEL_SCOPE\"] ( interfaceScopeDeclarations )* ) ;
	public final JavaParser.interfaceBody_return interfaceBody() throws RecognitionException {
		JavaParser.interfaceBody_return retval = new JavaParser.interfaceBody_return();
		retval.start = input.LT(1);
		int interfaceBody_StartIndex = input.index();

		CommonTree root_0 = null;

		Token LCURLY77=null;
		Token RCURLY79=null;
		ParserRuleReturnScope interfaceScopeDeclarations78 =null;

		CommonTree LCURLY77_tree=null;
		CommonTree RCURLY79_tree=null;
		RewriteRuleTokenStream stream_LCURLY=new RewriteRuleTokenStream(adaptor,"token LCURLY");
		RewriteRuleTokenStream stream_RCURLY=new RewriteRuleTokenStream(adaptor,"token RCURLY");
		RewriteRuleSubtreeStream stream_interfaceScopeDeclarations=new RewriteRuleSubtreeStream(adaptor,"rule interfaceScopeDeclarations");

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 24) ) { return retval; }

			// Java.g:445:5: ( LCURLY ( interfaceScopeDeclarations )* RCURLY -> ^( INTERFACE_TOP_LEVEL_SCOPE[$LCURLY, \"CLASS_TOP_LEVEL_SCOPE\"] ( interfaceScopeDeclarations )* ) )
			// Java.g:445:9: LCURLY ( interfaceScopeDeclarations )* RCURLY
			{
			LCURLY77=(Token)match(input,LCURLY,FOLLOW_LCURLY_in_interfaceBody5629); if (state.failed) return retval; 
			if ( state.backtracking==0 ) stream_LCURLY.add(LCURLY77);

			// Java.g:445:16: ( interfaceScopeDeclarations )*
			loop26:
			do {
				int alt26=2;
				int LA26_0 = input.LA(1);
				if ( (LA26_0==ABSTRACT||LA26_0==AT||LA26_0==BOOLEAN||LA26_0==BYTE||LA26_0==CHAR||LA26_0==CLASS||LA26_0==DOUBLE||LA26_0==ENUM||LA26_0==FINAL||LA26_0==FLOAT||LA26_0==IDENT||LA26_0==INT||LA26_0==INTERFACE||LA26_0==LESS_THAN||LA26_0==LONG||LA26_0==NATIVE||(LA26_0 >= PRIVATE && LA26_0 <= PUBLIC)||LA26_0==SEMI||LA26_0==SHORT||LA26_0==STATIC||LA26_0==STRICTFP||LA26_0==SYNCHRONIZED||LA26_0==TRANSIENT||LA26_0==VOID||LA26_0==VOLATILE) ) {
					alt26=1;
				}

				switch (alt26) {
				case 1 :
					// Java.g:445:16: interfaceScopeDeclarations
					{
					pushFollow(FOLLOW_interfaceScopeDeclarations_in_interfaceBody5631);
					interfaceScopeDeclarations78=interfaceScopeDeclarations();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_interfaceScopeDeclarations.add(interfaceScopeDeclarations78.getTree());
					}
					break;

				default :
					break loop26;
				}
			} while (true);

			RCURLY79=(Token)match(input,RCURLY,FOLLOW_RCURLY_in_interfaceBody5634); if (state.failed) return retval; 
			if ( state.backtracking==0 ) stream_RCURLY.add(RCURLY79);

			// AST REWRITE
			// elements: interfaceScopeDeclarations
			// token labels: 
			// rule labels: retval
			// token list labels: 
			// rule list labels: 
			// wildcard labels: 
			if ( state.backtracking==0 ) {

			retval.tree = root_0;
			RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

			root_0 = (CommonTree)adaptor.nil();
			// 446:9: -> ^( INTERFACE_TOP_LEVEL_SCOPE[$LCURLY, \"CLASS_TOP_LEVEL_SCOPE\"] ( interfaceScopeDeclarations )* )
			{
				// Java.g:446:13: ^( INTERFACE_TOP_LEVEL_SCOPE[$LCURLY, \"CLASS_TOP_LEVEL_SCOPE\"] ( interfaceScopeDeclarations )* )
				{
				CommonTree root_1 = (CommonTree)adaptor.nil();
				root_1 = (CommonTree)adaptor.becomeRoot(
				(CommonTree)adaptor.create(INTERFACE_TOP_LEVEL_SCOPE, LCURLY77, "CLASS_TOP_LEVEL_SCOPE")
				, root_1);

				// Java.g:446:75: ( interfaceScopeDeclarations )*
				while ( stream_interfaceScopeDeclarations.hasNext() ) {
					adaptor.addChild(root_1, stream_interfaceScopeDeclarations.nextTree());

				}
				stream_interfaceScopeDeclarations.reset();

				adaptor.addChild(root_0, root_1);
				}

			}


			retval.tree = root_0;
			}

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 24, interfaceBody_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "interfaceBody"


	public static class classScopeDeclarations_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "classScopeDeclarations"
	// Java.g:449:1: classScopeDeclarations : ( block -> ^( CLASS_INSTANCE_INITIALIZER block ) | STATIC block -> ^( CLASS_STATIC_INITIALIZER[$STATIC, \"CLASS_STATIC_INITIALIZER\"] block ) | modifierList ( ( genericTypeParameterList )? ( type IDENT formalParameterList ( arrayDeclaratorList )? ( throwsClause )? ( block | SEMI ) -> ^( FUNCTION_METHOD_DECL modifierList ( genericTypeParameterList )? type IDENT formalParameterList ( arrayDeclaratorList )? ( throwsClause )? ( block )? ) | VOID IDENT formalParameterList ( throwsClause )? ( block | SEMI ) -> ^( VOID_METHOD_DECL modifierList ( genericTypeParameterList )? IDENT formalParameterList ( throwsClause )? ( block )? ) |ident= IDENT formalParameterList ( throwsClause )? block -> ^( CONSTRUCTOR_DECL[$ident, \"CONSTRUCTOR_DECL\"] modifierList ( genericTypeParameterList )? formalParameterList ( throwsClause )? block ) ) | type classFieldDeclaratorList SEMI -> ^( VAR_DECLARATION modifierList type classFieldDeclaratorList ) ) | typeDeclaration | SEMI !);
	public final JavaParser.classScopeDeclarations_return classScopeDeclarations() throws RecognitionException {
		JavaParser.classScopeDeclarations_return retval = new JavaParser.classScopeDeclarations_return();
		retval.start = input.LT(1);
		int classScopeDeclarations_StartIndex = input.index();

		CommonTree root_0 = null;

		Token ident=null;
		Token STATIC81=null;
		Token IDENT86=null;
		Token SEMI91=null;
		Token VOID92=null;
		Token IDENT93=null;
		Token SEMI97=null;
		Token SEMI103=null;
		Token SEMI105=null;
		ParserRuleReturnScope block80 =null;
		ParserRuleReturnScope block82 =null;
		ParserRuleReturnScope modifierList83 =null;
		ParserRuleReturnScope genericTypeParameterList84 =null;
		ParserRuleReturnScope type85 =null;
		ParserRuleReturnScope formalParameterList87 =null;
		ParserRuleReturnScope arrayDeclaratorList88 =null;
		ParserRuleReturnScope throwsClause89 =null;
		ParserRuleReturnScope block90 =null;
		ParserRuleReturnScope formalParameterList94 =null;
		ParserRuleReturnScope throwsClause95 =null;
		ParserRuleReturnScope block96 =null;
		ParserRuleReturnScope formalParameterList98 =null;
		ParserRuleReturnScope throwsClause99 =null;
		ParserRuleReturnScope block100 =null;
		ParserRuleReturnScope type101 =null;
		ParserRuleReturnScope classFieldDeclaratorList102 =null;
		ParserRuleReturnScope typeDeclaration104 =null;

		CommonTree ident_tree=null;
		CommonTree STATIC81_tree=null;
		CommonTree IDENT86_tree=null;
		CommonTree SEMI91_tree=null;
		CommonTree VOID92_tree=null;
		CommonTree IDENT93_tree=null;
		CommonTree SEMI97_tree=null;
		CommonTree SEMI103_tree=null;
		CommonTree SEMI105_tree=null;
		RewriteRuleTokenStream stream_IDENT=new RewriteRuleTokenStream(adaptor,"token IDENT");
		RewriteRuleTokenStream stream_VOID=new RewriteRuleTokenStream(adaptor,"token VOID");
		RewriteRuleTokenStream stream_SEMI=new RewriteRuleTokenStream(adaptor,"token SEMI");
		RewriteRuleTokenStream stream_STATIC=new RewriteRuleTokenStream(adaptor,"token STATIC");
		RewriteRuleSubtreeStream stream_arrayDeclaratorList=new RewriteRuleSubtreeStream(adaptor,"rule arrayDeclaratorList");
		RewriteRuleSubtreeStream stream_throwsClause=new RewriteRuleSubtreeStream(adaptor,"rule throwsClause");
		RewriteRuleSubtreeStream stream_modifierList=new RewriteRuleSubtreeStream(adaptor,"rule modifierList");
		RewriteRuleSubtreeStream stream_genericTypeParameterList=new RewriteRuleSubtreeStream(adaptor,"rule genericTypeParameterList");
		RewriteRuleSubtreeStream stream_block=new RewriteRuleSubtreeStream(adaptor,"rule block");
		RewriteRuleSubtreeStream stream_type=new RewriteRuleSubtreeStream(adaptor,"rule type");
		RewriteRuleSubtreeStream stream_classFieldDeclaratorList=new RewriteRuleSubtreeStream(adaptor,"rule classFieldDeclaratorList");
		RewriteRuleSubtreeStream stream_formalParameterList=new RewriteRuleSubtreeStream(adaptor,"rule formalParameterList");

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 25) ) { return retval; }

			// Java.g:450:5: ( block -> ^( CLASS_INSTANCE_INITIALIZER block ) | STATIC block -> ^( CLASS_STATIC_INITIALIZER[$STATIC, \"CLASS_STATIC_INITIALIZER\"] block ) | modifierList ( ( genericTypeParameterList )? ( type IDENT formalParameterList ( arrayDeclaratorList )? ( throwsClause )? ( block | SEMI ) -> ^( FUNCTION_METHOD_DECL modifierList ( genericTypeParameterList )? type IDENT formalParameterList ( arrayDeclaratorList )? ( throwsClause )? ( block )? ) | VOID IDENT formalParameterList ( throwsClause )? ( block | SEMI ) -> ^( VOID_METHOD_DECL modifierList ( genericTypeParameterList )? IDENT formalParameterList ( throwsClause )? ( block )? ) |ident= IDENT formalParameterList ( throwsClause )? block -> ^( CONSTRUCTOR_DECL[$ident, \"CONSTRUCTOR_DECL\"] modifierList ( genericTypeParameterList )? formalParameterList ( throwsClause )? block ) ) | type classFieldDeclaratorList SEMI -> ^( VAR_DECLARATION modifierList type classFieldDeclaratorList ) ) | typeDeclaration | SEMI !)
			int alt36=5;
			switch ( input.LA(1) ) {
			case LCURLY:
				{
				alt36=1;
				}
				break;
			case STATIC:
				{
				int LA36_2 = input.LA(2);
				if ( (synpred32_Java()) ) {
					alt36=2;
				}
				else if ( (synpred43_Java()) ) {
					alt36=3;
				}
				else if ( (synpred44_Java()) ) {
					alt36=4;
				}
				else {
					if (state.backtracking>0) {state.failed=true; return retval;}
					int nvaeMark = input.mark();
					try {
						input.consume();
						NoViableAltException nvae =
							new NoViableAltException("", 36, 2, input);
						throw nvae;
					} finally {
						input.rewind(nvaeMark);
					}
				}
				}
				break;
			case PUBLIC:
				{
				int LA36_3 = input.LA(2);
				if ( (synpred43_Java()) ) {
					alt36=3;
				}
				else if ( (synpred44_Java()) ) {
					alt36=4;
				}
				else {
					if (state.backtracking>0) {state.failed=true; return retval;}
					int nvaeMark = input.mark();
					try {
						input.consume();
						NoViableAltException nvae =
							new NoViableAltException("", 36, 3, input);
						throw nvae;
					} finally {
						input.rewind(nvaeMark);
					}
				}
				}
				break;
			case PROTECTED:
				{
				int LA36_4 = input.LA(2);
				if ( (synpred43_Java()) ) {
					alt36=3;
				}
				else if ( (synpred44_Java()) ) {
					alt36=4;
				}
				else {
					if (state.backtracking>0) {state.failed=true; return retval;}
					int nvaeMark = input.mark();
					try {
						input.consume();
						NoViableAltException nvae =
							new NoViableAltException("", 36, 4, input);
						throw nvae;
					} finally {
						input.rewind(nvaeMark);
					}
				}
				}
				break;
			case PRIVATE:
				{
				int LA36_5 = input.LA(2);
				if ( (synpred43_Java()) ) {
					alt36=3;
				}
				else if ( (synpred44_Java()) ) {
					alt36=4;
				}
				else {
					if (state.backtracking>0) {state.failed=true; return retval;}
					int nvaeMark = input.mark();
					try {
						input.consume();
						NoViableAltException nvae =
							new NoViableAltException("", 36, 5, input);
						throw nvae;
					} finally {
						input.rewind(nvaeMark);
					}
				}
				}
				break;
			case ABSTRACT:
				{
				int LA36_6 = input.LA(2);
				if ( (synpred43_Java()) ) {
					alt36=3;
				}
				else if ( (synpred44_Java()) ) {
					alt36=4;
				}
				else {
					if (state.backtracking>0) {state.failed=true; return retval;}
					int nvaeMark = input.mark();
					try {
						input.consume();
						NoViableAltException nvae =
							new NoViableAltException("", 36, 6, input);
						throw nvae;
					} finally {
						input.rewind(nvaeMark);
					}
				}
				}
				break;
			case NATIVE:
				{
				int LA36_7 = input.LA(2);
				if ( (synpred43_Java()) ) {
					alt36=3;
				}
				else if ( (synpred44_Java()) ) {
					alt36=4;
				}
				else {
					if (state.backtracking>0) {state.failed=true; return retval;}
					int nvaeMark = input.mark();
					try {
						input.consume();
						NoViableAltException nvae =
							new NoViableAltException("", 36, 7, input);
						throw nvae;
					} finally {
						input.rewind(nvaeMark);
					}
				}
				}
				break;
			case SYNCHRONIZED:
				{
				int LA36_8 = input.LA(2);
				if ( (synpred43_Java()) ) {
					alt36=3;
				}
				else if ( (synpred44_Java()) ) {
					alt36=4;
				}
				else {
					if (state.backtracking>0) {state.failed=true; return retval;}
					int nvaeMark = input.mark();
					try {
						input.consume();
						NoViableAltException nvae =
							new NoViableAltException("", 36, 8, input);
						throw nvae;
					} finally {
						input.rewind(nvaeMark);
					}
				}
				}
				break;
			case TRANSIENT:
				{
				int LA36_9 = input.LA(2);
				if ( (synpred43_Java()) ) {
					alt36=3;
				}
				else if ( (synpred44_Java()) ) {
					alt36=4;
				}
				else {
					if (state.backtracking>0) {state.failed=true; return retval;}
					int nvaeMark = input.mark();
					try {
						input.consume();
						NoViableAltException nvae =
							new NoViableAltException("", 36, 9, input);
						throw nvae;
					} finally {
						input.rewind(nvaeMark);
					}
				}
				}
				break;
			case VOLATILE:
				{
				int LA36_10 = input.LA(2);
				if ( (synpred43_Java()) ) {
					alt36=3;
				}
				else if ( (synpred44_Java()) ) {
					alt36=4;
				}
				else {
					if (state.backtracking>0) {state.failed=true; return retval;}
					int nvaeMark = input.mark();
					try {
						input.consume();
						NoViableAltException nvae =
							new NoViableAltException("", 36, 10, input);
						throw nvae;
					} finally {
						input.rewind(nvaeMark);
					}
				}
				}
				break;
			case STRICTFP:
				{
				int LA36_11 = input.LA(2);
				if ( (synpred43_Java()) ) {
					alt36=3;
				}
				else if ( (synpred44_Java()) ) {
					alt36=4;
				}
				else {
					if (state.backtracking>0) {state.failed=true; return retval;}
					int nvaeMark = input.mark();
					try {
						input.consume();
						NoViableAltException nvae =
							new NoViableAltException("", 36, 11, input);
						throw nvae;
					} finally {
						input.rewind(nvaeMark);
					}
				}
				}
				break;
			case FINAL:
				{
				int LA36_12 = input.LA(2);
				if ( (synpred43_Java()) ) {
					alt36=3;
				}
				else if ( (synpred44_Java()) ) {
					alt36=4;
				}
				else {
					if (state.backtracking>0) {state.failed=true; return retval;}
					int nvaeMark = input.mark();
					try {
						input.consume();
						NoViableAltException nvae =
							new NoViableAltException("", 36, 12, input);
						throw nvae;
					} finally {
						input.rewind(nvaeMark);
					}
				}
				}
				break;
			case AT:
				{
				int LA36_13 = input.LA(2);
				if ( (synpred43_Java()) ) {
					alt36=3;
				}
				else if ( (synpred44_Java()) ) {
					alt36=4;
				}
				else {
					if (state.backtracking>0) {state.failed=true; return retval;}
					int nvaeMark = input.mark();
					try {
						input.consume();
						NoViableAltException nvae =
							new NoViableAltException("", 36, 13, input);
						throw nvae;
					} finally {
						input.rewind(nvaeMark);
					}
				}
				}
				break;
			case BOOLEAN:
			case BYTE:
			case CHAR:
			case DOUBLE:
			case FLOAT:
			case IDENT:
			case INT:
			case LESS_THAN:
			case LONG:
			case SHORT:
			case VOID:
				{
				alt36=3;
				}
				break;
			case CLASS:
			case ENUM:
			case INTERFACE:
				{
				alt36=4;
				}
				break;
			case SEMI:
				{
				alt36=5;
				}
				break;
			default:
				if (state.backtracking>0) {state.failed=true; return retval;}
				NoViableAltException nvae =
					new NoViableAltException("", 36, 0, input);
				throw nvae;
			}
			switch (alt36) {
				case 1 :
					// Java.g:450:9: block
					{
					pushFollow(FOLLOW_block_in_classScopeDeclarations5672);
					block80=block();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_block.add(block80.getTree());
					// AST REWRITE
					// elements: block
					// token labels: 
					// rule labels: retval
					// token list labels: 
					// rule list labels: 
					// wildcard labels: 
					if ( state.backtracking==0 ) {

					retval.tree = root_0;
					RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

					root_0 = (CommonTree)adaptor.nil();
					// 450:25: -> ^( CLASS_INSTANCE_INITIALIZER block )
					{
						// Java.g:450:29: ^( CLASS_INSTANCE_INITIALIZER block )
						{
						CommonTree root_1 = (CommonTree)adaptor.nil();
						root_1 = (CommonTree)adaptor.becomeRoot(
						(CommonTree)adaptor.create(CLASS_INSTANCE_INITIALIZER, "CLASS_INSTANCE_INITIALIZER")
						, root_1);

						adaptor.addChild(root_1, stream_block.nextTree());

						adaptor.addChild(root_0, root_1);
						}

					}


					retval.tree = root_0;
					}

					}
					break;
				case 2 :
					// Java.g:451:9: STATIC block
					{
					STATIC81=(Token)match(input,STATIC,FOLLOW_STATIC_in_classScopeDeclarations5701); if (state.failed) return retval; 
					if ( state.backtracking==0 ) stream_STATIC.add(STATIC81);

					pushFollow(FOLLOW_block_in_classScopeDeclarations5703);
					block82=block();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_block.add(block82.getTree());
					// AST REWRITE
					// elements: block
					// token labels: 
					// rule labels: retval
					// token list labels: 
					// rule list labels: 
					// wildcard labels: 
					if ( state.backtracking==0 ) {

					retval.tree = root_0;
					RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

					root_0 = (CommonTree)adaptor.nil();
					// 451:25: -> ^( CLASS_STATIC_INITIALIZER[$STATIC, \"CLASS_STATIC_INITIALIZER\"] block )
					{
						// Java.g:451:29: ^( CLASS_STATIC_INITIALIZER[$STATIC, \"CLASS_STATIC_INITIALIZER\"] block )
						{
						CommonTree root_1 = (CommonTree)adaptor.nil();
						root_1 = (CommonTree)adaptor.becomeRoot(
						(CommonTree)adaptor.create(CLASS_STATIC_INITIALIZER, STATIC81, "CLASS_STATIC_INITIALIZER")
						, root_1);

						adaptor.addChild(root_1, stream_block.nextTree());

						adaptor.addChild(root_0, root_1);
						}

					}


					retval.tree = root_0;
					}

					}
					break;
				case 3 :
					// Java.g:452:9: modifierList ( ( genericTypeParameterList )? ( type IDENT formalParameterList ( arrayDeclaratorList )? ( throwsClause )? ( block | SEMI ) -> ^( FUNCTION_METHOD_DECL modifierList ( genericTypeParameterList )? type IDENT formalParameterList ( arrayDeclaratorList )? ( throwsClause )? ( block )? ) | VOID IDENT formalParameterList ( throwsClause )? ( block | SEMI ) -> ^( VOID_METHOD_DECL modifierList ( genericTypeParameterList )? IDENT formalParameterList ( throwsClause )? ( block )? ) |ident= IDENT formalParameterList ( throwsClause )? block -> ^( CONSTRUCTOR_DECL[$ident, \"CONSTRUCTOR_DECL\"] modifierList ( genericTypeParameterList )? formalParameterList ( throwsClause )? block ) ) | type classFieldDeclaratorList SEMI -> ^( VAR_DECLARATION modifierList type classFieldDeclaratorList ) )
					{
					pushFollow(FOLLOW_modifierList_in_classScopeDeclarations5726);
					modifierList83=modifierList();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_modifierList.add(modifierList83.getTree());
					// Java.g:453:9: ( ( genericTypeParameterList )? ( type IDENT formalParameterList ( arrayDeclaratorList )? ( throwsClause )? ( block | SEMI ) -> ^( FUNCTION_METHOD_DECL modifierList ( genericTypeParameterList )? type IDENT formalParameterList ( arrayDeclaratorList )? ( throwsClause )? ( block )? ) | VOID IDENT formalParameterList ( throwsClause )? ( block | SEMI ) -> ^( VOID_METHOD_DECL modifierList ( genericTypeParameterList )? IDENT formalParameterList ( throwsClause )? ( block )? ) |ident= IDENT formalParameterList ( throwsClause )? block -> ^( CONSTRUCTOR_DECL[$ident, \"CONSTRUCTOR_DECL\"] modifierList ( genericTypeParameterList )? formalParameterList ( throwsClause )? block ) ) | type classFieldDeclaratorList SEMI -> ^( VAR_DECLARATION modifierList type classFieldDeclaratorList ) )
					int alt35=2;
					switch ( input.LA(1) ) {
					case LESS_THAN:
					case VOID:
						{
						alt35=1;
						}
						break;
					case BOOLEAN:
					case BYTE:
					case CHAR:
					case DOUBLE:
					case FLOAT:
					case INT:
					case LONG:
					case SHORT:
						{
						int LA35_2 = input.LA(2);
						if ( (synpred42_Java()) ) {
							alt35=1;
						}
						else if ( (true) ) {
							alt35=2;
						}
						else {
							if (state.backtracking>0) {state.failed=true; return retval;}
							int nvaeMark = input.mark();
							try {
								input.consume();
								NoViableAltException nvae =
									new NoViableAltException("", 35, 2, input);
								throw nvae;
							} finally {
								input.rewind(nvaeMark);
							}
						}
						}
						break;
					case IDENT:
						{
						int LA35_3 = input.LA(2);
						if ( (synpred42_Java()) ) {
							alt35=1;
						}
						else if ( (true) ) {
							alt35=2;
						}
						else {
							if (state.backtracking>0) {state.failed=true; return retval;}
							int nvaeMark = input.mark();
							try {
								input.consume();
								NoViableAltException nvae =
									new NoViableAltException("", 35, 3, input);
								throw nvae;
							} finally {
								input.rewind(nvaeMark);
							}
						}
						}
						break;
					default:
						if (state.backtracking>0) {state.failed=true; return retval;}
						NoViableAltException nvae =
							new NoViableAltException("", 35, 0, input);
						throw nvae;
					}
					switch (alt35) {
						case 1 :
							// Java.g:453:13: ( genericTypeParameterList )? ( type IDENT formalParameterList ( arrayDeclaratorList )? ( throwsClause )? ( block | SEMI ) -> ^( FUNCTION_METHOD_DECL modifierList ( genericTypeParameterList )? type IDENT formalParameterList ( arrayDeclaratorList )? ( throwsClause )? ( block )? ) | VOID IDENT formalParameterList ( throwsClause )? ( block | SEMI ) -> ^( VOID_METHOD_DECL modifierList ( genericTypeParameterList )? IDENT formalParameterList ( throwsClause )? ( block )? ) |ident= IDENT formalParameterList ( throwsClause )? block -> ^( CONSTRUCTOR_DECL[$ident, \"CONSTRUCTOR_DECL\"] modifierList ( genericTypeParameterList )? formalParameterList ( throwsClause )? block ) )
							{
							// Java.g:453:13: ( genericTypeParameterList )?
							int alt27=2;
							int LA27_0 = input.LA(1);
							if ( (LA27_0==LESS_THAN) ) {
								alt27=1;
							}
							switch (alt27) {
								case 1 :
									// Java.g:453:13: genericTypeParameterList
									{
									pushFollow(FOLLOW_genericTypeParameterList_in_classScopeDeclarations5740);
									genericTypeParameterList84=genericTypeParameterList();
									state._fsp--;
									if (state.failed) return retval;
									if ( state.backtracking==0 ) stream_genericTypeParameterList.add(genericTypeParameterList84.getTree());
									}
									break;

							}

							// Java.g:454:13: ( type IDENT formalParameterList ( arrayDeclaratorList )? ( throwsClause )? ( block | SEMI ) -> ^( FUNCTION_METHOD_DECL modifierList ( genericTypeParameterList )? type IDENT formalParameterList ( arrayDeclaratorList )? ( throwsClause )? ( block )? ) | VOID IDENT formalParameterList ( throwsClause )? ( block | SEMI ) -> ^( VOID_METHOD_DECL modifierList ( genericTypeParameterList )? IDENT formalParameterList ( throwsClause )? ( block )? ) |ident= IDENT formalParameterList ( throwsClause )? block -> ^( CONSTRUCTOR_DECL[$ident, \"CONSTRUCTOR_DECL\"] modifierList ( genericTypeParameterList )? formalParameterList ( throwsClause )? block ) )
							int alt34=3;
							switch ( input.LA(1) ) {
							case BOOLEAN:
							case BYTE:
							case CHAR:
							case DOUBLE:
							case FLOAT:
							case INT:
							case LONG:
							case SHORT:
								{
								alt34=1;
								}
								break;
							case IDENT:
								{
								int LA34_2 = input.LA(2);
								if ( (LA34_2==DOT||LA34_2==IDENT||LA34_2==LBRACK||LA34_2==LESS_THAN) ) {
									alt34=1;
								}
								else if ( (LA34_2==LPAREN) ) {
									alt34=3;
								}
								else {
									if (state.backtracking>0) {state.failed=true; return retval;}
									int nvaeMark = input.mark();
									try {
										input.consume();
										NoViableAltException nvae =
											new NoViableAltException("", 34, 2, input);
										throw nvae;
									} finally {
										input.rewind(nvaeMark);
									}
								}
								}
								break;
							case VOID:
								{
								alt34=2;
								}
								break;
							default:
								if (state.backtracking>0) {state.failed=true; return retval;}
								NoViableAltException nvae =
									new NoViableAltException("", 34, 0, input);
								throw nvae;
							}
							switch (alt34) {
								case 1 :
									// Java.g:454:17: type IDENT formalParameterList ( arrayDeclaratorList )? ( throwsClause )? ( block | SEMI )
									{
									pushFollow(FOLLOW_type_in_classScopeDeclarations5759);
									type85=type();
									state._fsp--;
									if (state.failed) return retval;
									if ( state.backtracking==0 ) stream_type.add(type85.getTree());
									IDENT86=(Token)match(input,IDENT,FOLLOW_IDENT_in_classScopeDeclarations5761); if (state.failed) return retval; 
									if ( state.backtracking==0 ) stream_IDENT.add(IDENT86);

									pushFollow(FOLLOW_formalParameterList_in_classScopeDeclarations5763);
									formalParameterList87=formalParameterList();
									state._fsp--;
									if (state.failed) return retval;
									if ( state.backtracking==0 ) stream_formalParameterList.add(formalParameterList87.getTree());
									// Java.g:454:48: ( arrayDeclaratorList )?
									int alt28=2;
									int LA28_0 = input.LA(1);
									if ( (LA28_0==LBRACK) ) {
										alt28=1;
									}
									switch (alt28) {
										case 1 :
											// Java.g:454:48: arrayDeclaratorList
											{
											pushFollow(FOLLOW_arrayDeclaratorList_in_classScopeDeclarations5765);
											arrayDeclaratorList88=arrayDeclaratorList();
											state._fsp--;
											if (state.failed) return retval;
											if ( state.backtracking==0 ) stream_arrayDeclaratorList.add(arrayDeclaratorList88.getTree());
											}
											break;

									}

									// Java.g:454:69: ( throwsClause )?
									int alt29=2;
									int LA29_0 = input.LA(1);
									if ( (LA29_0==THROWS) ) {
										alt29=1;
									}
									switch (alt29) {
										case 1 :
											// Java.g:454:69: throwsClause
											{
											pushFollow(FOLLOW_throwsClause_in_classScopeDeclarations5768);
											throwsClause89=throwsClause();
											state._fsp--;
											if (state.failed) return retval;
											if ( state.backtracking==0 ) stream_throwsClause.add(throwsClause89.getTree());
											}
											break;

									}

									// Java.g:454:83: ( block | SEMI )
									int alt30=2;
									int LA30_0 = input.LA(1);
									if ( (LA30_0==LCURLY) ) {
										alt30=1;
									}
									else if ( (LA30_0==SEMI) ) {
										alt30=2;
									}
									else {
										if (state.backtracking>0) {state.failed=true; return retval;}
										NoViableAltException nvae =
											new NoViableAltException("", 30, 0, input);
										throw nvae;
									}
									switch (alt30) {
										case 1 :
											// Java.g:454:84: block
											{
											pushFollow(FOLLOW_block_in_classScopeDeclarations5772);
											block90=block();
											state._fsp--;
											if (state.failed) return retval;
											if ( state.backtracking==0 ) stream_block.add(block90.getTree());
											}
											break;
										case 2 :
											// Java.g:454:92: SEMI
											{
											SEMI91=(Token)match(input,SEMI,FOLLOW_SEMI_in_classScopeDeclarations5776); if (state.failed) return retval; 
											if ( state.backtracking==0 ) stream_SEMI.add(SEMI91);

											}
											break;

									}

									// AST REWRITE
									// elements: genericTypeParameterList, block, IDENT, type, arrayDeclaratorList, formalParameterList, throwsClause, modifierList
									// token labels: 
									// rule labels: retval
									// token list labels: 
									// rule list labels: 
									// wildcard labels: 
									if ( state.backtracking==0 ) {

									retval.tree = root_0;
									RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

									root_0 = (CommonTree)adaptor.nil();
									// 455:17: -> ^( FUNCTION_METHOD_DECL modifierList ( genericTypeParameterList )? type IDENT formalParameterList ( arrayDeclaratorList )? ( throwsClause )? ( block )? )
									{
										// Java.g:455:21: ^( FUNCTION_METHOD_DECL modifierList ( genericTypeParameterList )? type IDENT formalParameterList ( arrayDeclaratorList )? ( throwsClause )? ( block )? )
										{
										CommonTree root_1 = (CommonTree)adaptor.nil();
										root_1 = (CommonTree)adaptor.becomeRoot(
										(CommonTree)adaptor.create(FUNCTION_METHOD_DECL, "FUNCTION_METHOD_DECL")
										, root_1);

										adaptor.addChild(root_1, stream_modifierList.nextTree());

										// Java.g:455:57: ( genericTypeParameterList )?
										if ( stream_genericTypeParameterList.hasNext() ) {
											adaptor.addChild(root_1, stream_genericTypeParameterList.nextTree());

										}
										stream_genericTypeParameterList.reset();

										adaptor.addChild(root_1, stream_type.nextTree());

										adaptor.addChild(root_1, 
										stream_IDENT.nextNode()
										);

										adaptor.addChild(root_1, stream_formalParameterList.nextTree());

										// Java.g:455:114: ( arrayDeclaratorList )?
										if ( stream_arrayDeclaratorList.hasNext() ) {
											adaptor.addChild(root_1, stream_arrayDeclaratorList.nextTree());

										}
										stream_arrayDeclaratorList.reset();

										// Java.g:455:135: ( throwsClause )?
										if ( stream_throwsClause.hasNext() ) {
											adaptor.addChild(root_1, stream_throwsClause.nextTree());

										}
										stream_throwsClause.reset();

										// Java.g:455:149: ( block )?
										if ( stream_block.hasNext() ) {
											adaptor.addChild(root_1, stream_block.nextTree());

										}
										stream_block.reset();

										adaptor.addChild(root_0, root_1);
										}

									}


									retval.tree = root_0;
									}

									}
									break;
								case 2 :
									// Java.g:456:17: VOID IDENT formalParameterList ( throwsClause )? ( block | SEMI )
									{
									VOID92=(Token)match(input,VOID,FOLLOW_VOID_in_classScopeDeclarations5838); if (state.failed) return retval; 
									if ( state.backtracking==0 ) stream_VOID.add(VOID92);

									IDENT93=(Token)match(input,IDENT,FOLLOW_IDENT_in_classScopeDeclarations5840); if (state.failed) return retval; 
									if ( state.backtracking==0 ) stream_IDENT.add(IDENT93);

									pushFollow(FOLLOW_formalParameterList_in_classScopeDeclarations5842);
									formalParameterList94=formalParameterList();
									state._fsp--;
									if (state.failed) return retval;
									if ( state.backtracking==0 ) stream_formalParameterList.add(formalParameterList94.getTree());
									// Java.g:456:48: ( throwsClause )?
									int alt31=2;
									int LA31_0 = input.LA(1);
									if ( (LA31_0==THROWS) ) {
										alt31=1;
									}
									switch (alt31) {
										case 1 :
											// Java.g:456:48: throwsClause
											{
											pushFollow(FOLLOW_throwsClause_in_classScopeDeclarations5844);
											throwsClause95=throwsClause();
											state._fsp--;
											if (state.failed) return retval;
											if ( state.backtracking==0 ) stream_throwsClause.add(throwsClause95.getTree());
											}
											break;

									}

									// Java.g:456:62: ( block | SEMI )
									int alt32=2;
									int LA32_0 = input.LA(1);
									if ( (LA32_0==LCURLY) ) {
										alt32=1;
									}
									else if ( (LA32_0==SEMI) ) {
										alt32=2;
									}
									else {
										if (state.backtracking>0) {state.failed=true; return retval;}
										NoViableAltException nvae =
											new NoViableAltException("", 32, 0, input);
										throw nvae;
									}
									switch (alt32) {
										case 1 :
											// Java.g:456:63: block
											{
											pushFollow(FOLLOW_block_in_classScopeDeclarations5848);
											block96=block();
											state._fsp--;
											if (state.failed) return retval;
											if ( state.backtracking==0 ) stream_block.add(block96.getTree());
											}
											break;
										case 2 :
											// Java.g:456:71: SEMI
											{
											SEMI97=(Token)match(input,SEMI,FOLLOW_SEMI_in_classScopeDeclarations5852); if (state.failed) return retval; 
											if ( state.backtracking==0 ) stream_SEMI.add(SEMI97);

											}
											break;

									}

									// AST REWRITE
									// elements: genericTypeParameterList, formalParameterList, throwsClause, IDENT, block, modifierList
									// token labels: 
									// rule labels: retval
									// token list labels: 
									// rule list labels: 
									// wildcard labels: 
									if ( state.backtracking==0 ) {

									retval.tree = root_0;
									RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

									root_0 = (CommonTree)adaptor.nil();
									// 457:17: -> ^( VOID_METHOD_DECL modifierList ( genericTypeParameterList )? IDENT formalParameterList ( throwsClause )? ( block )? )
									{
										// Java.g:457:21: ^( VOID_METHOD_DECL modifierList ( genericTypeParameterList )? IDENT formalParameterList ( throwsClause )? ( block )? )
										{
										CommonTree root_1 = (CommonTree)adaptor.nil();
										root_1 = (CommonTree)adaptor.becomeRoot(
										(CommonTree)adaptor.create(VOID_METHOD_DECL, "VOID_METHOD_DECL")
										, root_1);

										adaptor.addChild(root_1, stream_modifierList.nextTree());

										// Java.g:457:53: ( genericTypeParameterList )?
										if ( stream_genericTypeParameterList.hasNext() ) {
											adaptor.addChild(root_1, stream_genericTypeParameterList.nextTree());

										}
										stream_genericTypeParameterList.reset();

										adaptor.addChild(root_1, 
										stream_IDENT.nextNode()
										);

										adaptor.addChild(root_1, stream_formalParameterList.nextTree());

										// Java.g:457:105: ( throwsClause )?
										if ( stream_throwsClause.hasNext() ) {
											adaptor.addChild(root_1, stream_throwsClause.nextTree());

										}
										stream_throwsClause.reset();

										// Java.g:457:119: ( block )?
										if ( stream_block.hasNext() ) {
											adaptor.addChild(root_1, stream_block.nextTree());

										}
										stream_block.reset();

										adaptor.addChild(root_0, root_1);
										}

									}


									retval.tree = root_0;
									}

									}
									break;
								case 3 :
									// Java.g:458:17: ident= IDENT formalParameterList ( throwsClause )? block
									{
									ident=(Token)match(input,IDENT,FOLLOW_IDENT_in_classScopeDeclarations5911); if (state.failed) return retval; 
									if ( state.backtracking==0 ) stream_IDENT.add(ident);

									pushFollow(FOLLOW_formalParameterList_in_classScopeDeclarations5913);
									formalParameterList98=formalParameterList();
									state._fsp--;
									if (state.failed) return retval;
									if ( state.backtracking==0 ) stream_formalParameterList.add(formalParameterList98.getTree());
									// Java.g:458:49: ( throwsClause )?
									int alt33=2;
									int LA33_0 = input.LA(1);
									if ( (LA33_0==THROWS) ) {
										alt33=1;
									}
									switch (alt33) {
										case 1 :
											// Java.g:458:49: throwsClause
											{
											pushFollow(FOLLOW_throwsClause_in_classScopeDeclarations5915);
											throwsClause99=throwsClause();
											state._fsp--;
											if (state.failed) return retval;
											if ( state.backtracking==0 ) stream_throwsClause.add(throwsClause99.getTree());
											}
											break;

									}

									pushFollow(FOLLOW_block_in_classScopeDeclarations5918);
									block100=block();
									state._fsp--;
									if (state.failed) return retval;
									if ( state.backtracking==0 ) stream_block.add(block100.getTree());
									// AST REWRITE
									// elements: block, genericTypeParameterList, throwsClause, formalParameterList, modifierList
									// token labels: 
									// rule labels: retval
									// token list labels: 
									// rule list labels: 
									// wildcard labels: 
									if ( state.backtracking==0 ) {

									retval.tree = root_0;
									RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

									root_0 = (CommonTree)adaptor.nil();
									// 459:17: -> ^( CONSTRUCTOR_DECL[$ident, \"CONSTRUCTOR_DECL\"] modifierList ( genericTypeParameterList )? formalParameterList ( throwsClause )? block )
									{
										// Java.g:459:21: ^( CONSTRUCTOR_DECL[$ident, \"CONSTRUCTOR_DECL\"] modifierList ( genericTypeParameterList )? formalParameterList ( throwsClause )? block )
										{
										CommonTree root_1 = (CommonTree)adaptor.nil();
										root_1 = (CommonTree)adaptor.becomeRoot(
										(CommonTree)adaptor.create(CONSTRUCTOR_DECL, ident, "CONSTRUCTOR_DECL")
										, root_1);

										adaptor.addChild(root_1, stream_modifierList.nextTree());

										// Java.g:459:81: ( genericTypeParameterList )?
										if ( stream_genericTypeParameterList.hasNext() ) {
											adaptor.addChild(root_1, stream_genericTypeParameterList.nextTree());

										}
										stream_genericTypeParameterList.reset();

										adaptor.addChild(root_1, stream_formalParameterList.nextTree());

										// Java.g:459:127: ( throwsClause )?
										if ( stream_throwsClause.hasNext() ) {
											adaptor.addChild(root_1, stream_throwsClause.nextTree());

										}
										stream_throwsClause.reset();

										adaptor.addChild(root_1, stream_block.nextTree());

										adaptor.addChild(root_0, root_1);
										}

									}


									retval.tree = root_0;
									}

									}
									break;

							}

							}
							break;
						case 2 :
							// Java.g:461:13: type classFieldDeclaratorList SEMI
							{
							pushFollow(FOLLOW_type_in_classScopeDeclarations5982);
							type101=type();
							state._fsp--;
							if (state.failed) return retval;
							if ( state.backtracking==0 ) stream_type.add(type101.getTree());
							pushFollow(FOLLOW_classFieldDeclaratorList_in_classScopeDeclarations5984);
							classFieldDeclaratorList102=classFieldDeclaratorList();
							state._fsp--;
							if (state.failed) return retval;
							if ( state.backtracking==0 ) stream_classFieldDeclaratorList.add(classFieldDeclaratorList102.getTree());
							SEMI103=(Token)match(input,SEMI,FOLLOW_SEMI_in_classScopeDeclarations5986); if (state.failed) return retval; 
							if ( state.backtracking==0 ) stream_SEMI.add(SEMI103);

							// AST REWRITE
							// elements: type, modifierList, classFieldDeclaratorList
							// token labels: 
							// rule labels: retval
							// token list labels: 
							// rule list labels: 
							// wildcard labels: 
							if ( state.backtracking==0 ) {

							retval.tree = root_0;
							RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

							root_0 = (CommonTree)adaptor.nil();
							// 462:13: -> ^( VAR_DECLARATION modifierList type classFieldDeclaratorList )
							{
								// Java.g:462:17: ^( VAR_DECLARATION modifierList type classFieldDeclaratorList )
								{
								CommonTree root_1 = (CommonTree)adaptor.nil();
								root_1 = (CommonTree)adaptor.becomeRoot(
								(CommonTree)adaptor.create(VAR_DECLARATION, "VAR_DECLARATION")
								, root_1);

								adaptor.addChild(root_1, stream_modifierList.nextTree());

								adaptor.addChild(root_1, stream_type.nextTree());

								adaptor.addChild(root_1, stream_classFieldDeclaratorList.nextTree());

								adaptor.addChild(root_0, root_1);
								}

							}


							retval.tree = root_0;
							}

							}
							break;

					}

					}
					break;
				case 4 :
					// Java.g:464:9: typeDeclaration
					{
					root_0 = (CommonTree)adaptor.nil();


					pushFollow(FOLLOW_typeDeclaration_in_classScopeDeclarations6031);
					typeDeclaration104=typeDeclaration();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) adaptor.addChild(root_0, typeDeclaration104.getTree());

					}
					break;
				case 5 :
					// Java.g:465:9: SEMI !
					{
					root_0 = (CommonTree)adaptor.nil();


					SEMI105=(Token)match(input,SEMI,FOLLOW_SEMI_in_classScopeDeclarations6041); if (state.failed) return retval;
					}
					break;

			}
			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 25, classScopeDeclarations_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "classScopeDeclarations"


	public static class interfaceScopeDeclarations_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "interfaceScopeDeclarations"
	// Java.g:468:1: interfaceScopeDeclarations : ( modifierList ( ( genericTypeParameterList )? ( type IDENT formalParameterList ( arrayDeclaratorList )? ( throwsClause )? SEMI -> ^( FUNCTION_METHOD_DECL modifierList ( genericTypeParameterList )? type IDENT formalParameterList ( arrayDeclaratorList )? ( throwsClause )? ) | VOID IDENT formalParameterList ( throwsClause )? SEMI -> ^( VOID_METHOD_DECL modifierList ( genericTypeParameterList )? IDENT formalParameterList ( throwsClause )? ) ) | type interfaceFieldDeclaratorList SEMI -> ^( VAR_DECLARATION modifierList type interfaceFieldDeclaratorList ) ) | typeDeclaration | SEMI !);
	public final JavaParser.interfaceScopeDeclarations_return interfaceScopeDeclarations() throws RecognitionException {
		JavaParser.interfaceScopeDeclarations_return retval = new JavaParser.interfaceScopeDeclarations_return();
		retval.start = input.LT(1);
		int interfaceScopeDeclarations_StartIndex = input.index();

		CommonTree root_0 = null;

		Token IDENT109=null;
		Token SEMI113=null;
		Token VOID114=null;
		Token IDENT115=null;
		Token SEMI118=null;
		Token SEMI121=null;
		Token SEMI123=null;
		ParserRuleReturnScope modifierList106 =null;
		ParserRuleReturnScope genericTypeParameterList107 =null;
		ParserRuleReturnScope type108 =null;
		ParserRuleReturnScope formalParameterList110 =null;
		ParserRuleReturnScope arrayDeclaratorList111 =null;
		ParserRuleReturnScope throwsClause112 =null;
		ParserRuleReturnScope formalParameterList116 =null;
		ParserRuleReturnScope throwsClause117 =null;
		ParserRuleReturnScope type119 =null;
		ParserRuleReturnScope interfaceFieldDeclaratorList120 =null;
		ParserRuleReturnScope typeDeclaration122 =null;

		CommonTree IDENT109_tree=null;
		CommonTree SEMI113_tree=null;
		CommonTree VOID114_tree=null;
		CommonTree IDENT115_tree=null;
		CommonTree SEMI118_tree=null;
		CommonTree SEMI121_tree=null;
		CommonTree SEMI123_tree=null;
		RewriteRuleTokenStream stream_IDENT=new RewriteRuleTokenStream(adaptor,"token IDENT");
		RewriteRuleTokenStream stream_VOID=new RewriteRuleTokenStream(adaptor,"token VOID");
		RewriteRuleTokenStream stream_SEMI=new RewriteRuleTokenStream(adaptor,"token SEMI");
		RewriteRuleSubtreeStream stream_arrayDeclaratorList=new RewriteRuleSubtreeStream(adaptor,"rule arrayDeclaratorList");
		RewriteRuleSubtreeStream stream_throwsClause=new RewriteRuleSubtreeStream(adaptor,"rule throwsClause");
		RewriteRuleSubtreeStream stream_modifierList=new RewriteRuleSubtreeStream(adaptor,"rule modifierList");
		RewriteRuleSubtreeStream stream_genericTypeParameterList=new RewriteRuleSubtreeStream(adaptor,"rule genericTypeParameterList");
		RewriteRuleSubtreeStream stream_interfaceFieldDeclaratorList=new RewriteRuleSubtreeStream(adaptor,"rule interfaceFieldDeclaratorList");
		RewriteRuleSubtreeStream stream_type=new RewriteRuleSubtreeStream(adaptor,"rule type");
		RewriteRuleSubtreeStream stream_formalParameterList=new RewriteRuleSubtreeStream(adaptor,"rule formalParameterList");

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 26) ) { return retval; }

			// Java.g:469:5: ( modifierList ( ( genericTypeParameterList )? ( type IDENT formalParameterList ( arrayDeclaratorList )? ( throwsClause )? SEMI -> ^( FUNCTION_METHOD_DECL modifierList ( genericTypeParameterList )? type IDENT formalParameterList ( arrayDeclaratorList )? ( throwsClause )? ) | VOID IDENT formalParameterList ( throwsClause )? SEMI -> ^( VOID_METHOD_DECL modifierList ( genericTypeParameterList )? IDENT formalParameterList ( throwsClause )? ) ) | type interfaceFieldDeclaratorList SEMI -> ^( VAR_DECLARATION modifierList type interfaceFieldDeclaratorList ) ) | typeDeclaration | SEMI !)
			int alt43=3;
			switch ( input.LA(1) ) {
			case PUBLIC:
				{
				int LA43_1 = input.LA(2);
				if ( (synpred51_Java()) ) {
					alt43=1;
				}
				else if ( (synpred52_Java()) ) {
					alt43=2;
				}
				else {
					if (state.backtracking>0) {state.failed=true; return retval;}
					int nvaeMark = input.mark();
					try {
						input.consume();
						NoViableAltException nvae =
							new NoViableAltException("", 43, 1, input);
						throw nvae;
					} finally {
						input.rewind(nvaeMark);
					}
				}
				}
				break;
			case PROTECTED:
				{
				int LA43_2 = input.LA(2);
				if ( (synpred51_Java()) ) {
					alt43=1;
				}
				else if ( (synpred52_Java()) ) {
					alt43=2;
				}
				else {
					if (state.backtracking>0) {state.failed=true; return retval;}
					int nvaeMark = input.mark();
					try {
						input.consume();
						NoViableAltException nvae =
							new NoViableAltException("", 43, 2, input);
						throw nvae;
					} finally {
						input.rewind(nvaeMark);
					}
				}
				}
				break;
			case PRIVATE:
				{
				int LA43_3 = input.LA(2);
				if ( (synpred51_Java()) ) {
					alt43=1;
				}
				else if ( (synpred52_Java()) ) {
					alt43=2;
				}
				else {
					if (state.backtracking>0) {state.failed=true; return retval;}
					int nvaeMark = input.mark();
					try {
						input.consume();
						NoViableAltException nvae =
							new NoViableAltException("", 43, 3, input);
						throw nvae;
					} finally {
						input.rewind(nvaeMark);
					}
				}
				}
				break;
			case STATIC:
				{
				int LA43_4 = input.LA(2);
				if ( (synpred51_Java()) ) {
					alt43=1;
				}
				else if ( (synpred52_Java()) ) {
					alt43=2;
				}
				else {
					if (state.backtracking>0) {state.failed=true; return retval;}
					int nvaeMark = input.mark();
					try {
						input.consume();
						NoViableAltException nvae =
							new NoViableAltException("", 43, 4, input);
						throw nvae;
					} finally {
						input.rewind(nvaeMark);
					}
				}
				}
				break;
			case ABSTRACT:
				{
				int LA43_5 = input.LA(2);
				if ( (synpred51_Java()) ) {
					alt43=1;
				}
				else if ( (synpred52_Java()) ) {
					alt43=2;
				}
				else {
					if (state.backtracking>0) {state.failed=true; return retval;}
					int nvaeMark = input.mark();
					try {
						input.consume();
						NoViableAltException nvae =
							new NoViableAltException("", 43, 5, input);
						throw nvae;
					} finally {
						input.rewind(nvaeMark);
					}
				}
				}
				break;
			case NATIVE:
				{
				int LA43_6 = input.LA(2);
				if ( (synpred51_Java()) ) {
					alt43=1;
				}
				else if ( (synpred52_Java()) ) {
					alt43=2;
				}
				else {
					if (state.backtracking>0) {state.failed=true; return retval;}
					int nvaeMark = input.mark();
					try {
						input.consume();
						NoViableAltException nvae =
							new NoViableAltException("", 43, 6, input);
						throw nvae;
					} finally {
						input.rewind(nvaeMark);
					}
				}
				}
				break;
			case SYNCHRONIZED:
				{
				int LA43_7 = input.LA(2);
				if ( (synpred51_Java()) ) {
					alt43=1;
				}
				else if ( (synpred52_Java()) ) {
					alt43=2;
				}
				else {
					if (state.backtracking>0) {state.failed=true; return retval;}
					int nvaeMark = input.mark();
					try {
						input.consume();
						NoViableAltException nvae =
							new NoViableAltException("", 43, 7, input);
						throw nvae;
					} finally {
						input.rewind(nvaeMark);
					}
				}
				}
				break;
			case TRANSIENT:
				{
				int LA43_8 = input.LA(2);
				if ( (synpred51_Java()) ) {
					alt43=1;
				}
				else if ( (synpred52_Java()) ) {
					alt43=2;
				}
				else {
					if (state.backtracking>0) {state.failed=true; return retval;}
					int nvaeMark = input.mark();
					try {
						input.consume();
						NoViableAltException nvae =
							new NoViableAltException("", 43, 8, input);
						throw nvae;
					} finally {
						input.rewind(nvaeMark);
					}
				}
				}
				break;
			case VOLATILE:
				{
				int LA43_9 = input.LA(2);
				if ( (synpred51_Java()) ) {
					alt43=1;
				}
				else if ( (synpred52_Java()) ) {
					alt43=2;
				}
				else {
					if (state.backtracking>0) {state.failed=true; return retval;}
					int nvaeMark = input.mark();
					try {
						input.consume();
						NoViableAltException nvae =
							new NoViableAltException("", 43, 9, input);
						throw nvae;
					} finally {
						input.rewind(nvaeMark);
					}
				}
				}
				break;
			case STRICTFP:
				{
				int LA43_10 = input.LA(2);
				if ( (synpred51_Java()) ) {
					alt43=1;
				}
				else if ( (synpred52_Java()) ) {
					alt43=2;
				}
				else {
					if (state.backtracking>0) {state.failed=true; return retval;}
					int nvaeMark = input.mark();
					try {
						input.consume();
						NoViableAltException nvae =
							new NoViableAltException("", 43, 10, input);
						throw nvae;
					} finally {
						input.rewind(nvaeMark);
					}
				}
				}
				break;
			case FINAL:
				{
				int LA43_11 = input.LA(2);
				if ( (synpred51_Java()) ) {
					alt43=1;
				}
				else if ( (synpred52_Java()) ) {
					alt43=2;
				}
				else {
					if (state.backtracking>0) {state.failed=true; return retval;}
					int nvaeMark = input.mark();
					try {
						input.consume();
						NoViableAltException nvae =
							new NoViableAltException("", 43, 11, input);
						throw nvae;
					} finally {
						input.rewind(nvaeMark);
					}
				}
				}
				break;
			case AT:
				{
				int LA43_12 = input.LA(2);
				if ( (synpred51_Java()) ) {
					alt43=1;
				}
				else if ( (synpred52_Java()) ) {
					alt43=2;
				}
				else {
					if (state.backtracking>0) {state.failed=true; return retval;}
					int nvaeMark = input.mark();
					try {
						input.consume();
						NoViableAltException nvae =
							new NoViableAltException("", 43, 12, input);
						throw nvae;
					} finally {
						input.rewind(nvaeMark);
					}
				}
				}
				break;
			case BOOLEAN:
			case BYTE:
			case CHAR:
			case DOUBLE:
			case FLOAT:
			case IDENT:
			case INT:
			case LESS_THAN:
			case LONG:
			case SHORT:
			case VOID:
				{
				alt43=1;
				}
				break;
			case CLASS:
			case ENUM:
			case INTERFACE:
				{
				alt43=2;
				}
				break;
			case SEMI:
				{
				alt43=3;
				}
				break;
			default:
				if (state.backtracking>0) {state.failed=true; return retval;}
				NoViableAltException nvae =
					new NoViableAltException("", 43, 0, input);
				throw nvae;
			}
			switch (alt43) {
				case 1 :
					// Java.g:469:9: modifierList ( ( genericTypeParameterList )? ( type IDENT formalParameterList ( arrayDeclaratorList )? ( throwsClause )? SEMI -> ^( FUNCTION_METHOD_DECL modifierList ( genericTypeParameterList )? type IDENT formalParameterList ( arrayDeclaratorList )? ( throwsClause )? ) | VOID IDENT formalParameterList ( throwsClause )? SEMI -> ^( VOID_METHOD_DECL modifierList ( genericTypeParameterList )? IDENT formalParameterList ( throwsClause )? ) ) | type interfaceFieldDeclaratorList SEMI -> ^( VAR_DECLARATION modifierList type interfaceFieldDeclaratorList ) )
					{
					pushFollow(FOLLOW_modifierList_in_interfaceScopeDeclarations6073);
					modifierList106=modifierList();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_modifierList.add(modifierList106.getTree());
					// Java.g:470:9: ( ( genericTypeParameterList )? ( type IDENT formalParameterList ( arrayDeclaratorList )? ( throwsClause )? SEMI -> ^( FUNCTION_METHOD_DECL modifierList ( genericTypeParameterList )? type IDENT formalParameterList ( arrayDeclaratorList )? ( throwsClause )? ) | VOID IDENT formalParameterList ( throwsClause )? SEMI -> ^( VOID_METHOD_DECL modifierList ( genericTypeParameterList )? IDENT formalParameterList ( throwsClause )? ) ) | type interfaceFieldDeclaratorList SEMI -> ^( VAR_DECLARATION modifierList type interfaceFieldDeclaratorList ) )
					int alt42=2;
					switch ( input.LA(1) ) {
					case LESS_THAN:
					case VOID:
						{
						alt42=1;
						}
						break;
					case BOOLEAN:
					case BYTE:
					case CHAR:
					case DOUBLE:
					case FLOAT:
					case INT:
					case LONG:
					case SHORT:
						{
						int LA42_2 = input.LA(2);
						if ( (synpred50_Java()) ) {
							alt42=1;
						}
						else if ( (true) ) {
							alt42=2;
						}
						else {
							if (state.backtracking>0) {state.failed=true; return retval;}
							int nvaeMark = input.mark();
							try {
								input.consume();
								NoViableAltException nvae =
									new NoViableAltException("", 42, 2, input);
								throw nvae;
							} finally {
								input.rewind(nvaeMark);
							}
						}
						}
						break;
					case IDENT:
						{
						int LA42_3 = input.LA(2);
						if ( (synpred50_Java()) ) {
							alt42=1;
						}
						else if ( (true) ) {
							alt42=2;
						}
						else {
							if (state.backtracking>0) {state.failed=true; return retval;}
							int nvaeMark = input.mark();
							try {
								input.consume();
								NoViableAltException nvae =
									new NoViableAltException("", 42, 3, input);
								throw nvae;
							} finally {
								input.rewind(nvaeMark);
							}
						}
						}
						break;
					default:
						if (state.backtracking>0) {state.failed=true; return retval;}
						NoViableAltException nvae =
							new NoViableAltException("", 42, 0, input);
						throw nvae;
					}
					switch (alt42) {
						case 1 :
							// Java.g:470:13: ( genericTypeParameterList )? ( type IDENT formalParameterList ( arrayDeclaratorList )? ( throwsClause )? SEMI -> ^( FUNCTION_METHOD_DECL modifierList ( genericTypeParameterList )? type IDENT formalParameterList ( arrayDeclaratorList )? ( throwsClause )? ) | VOID IDENT formalParameterList ( throwsClause )? SEMI -> ^( VOID_METHOD_DECL modifierList ( genericTypeParameterList )? IDENT formalParameterList ( throwsClause )? ) )
							{
							// Java.g:470:13: ( genericTypeParameterList )?
							int alt37=2;
							int LA37_0 = input.LA(1);
							if ( (LA37_0==LESS_THAN) ) {
								alt37=1;
							}
							switch (alt37) {
								case 1 :
									// Java.g:470:13: genericTypeParameterList
									{
									pushFollow(FOLLOW_genericTypeParameterList_in_interfaceScopeDeclarations6087);
									genericTypeParameterList107=genericTypeParameterList();
									state._fsp--;
									if (state.failed) return retval;
									if ( state.backtracking==0 ) stream_genericTypeParameterList.add(genericTypeParameterList107.getTree());
									}
									break;

							}

							// Java.g:471:13: ( type IDENT formalParameterList ( arrayDeclaratorList )? ( throwsClause )? SEMI -> ^( FUNCTION_METHOD_DECL modifierList ( genericTypeParameterList )? type IDENT formalParameterList ( arrayDeclaratorList )? ( throwsClause )? ) | VOID IDENT formalParameterList ( throwsClause )? SEMI -> ^( VOID_METHOD_DECL modifierList ( genericTypeParameterList )? IDENT formalParameterList ( throwsClause )? ) )
							int alt41=2;
							int LA41_0 = input.LA(1);
							if ( (LA41_0==BOOLEAN||LA41_0==BYTE||LA41_0==CHAR||LA41_0==DOUBLE||LA41_0==FLOAT||LA41_0==IDENT||LA41_0==INT||LA41_0==LONG||LA41_0==SHORT) ) {
								alt41=1;
							}
							else if ( (LA41_0==VOID) ) {
								alt41=2;
							}
							else {
								if (state.backtracking>0) {state.failed=true; return retval;}
								NoViableAltException nvae =
									new NoViableAltException("", 41, 0, input);
								throw nvae;
							}
							switch (alt41) {
								case 1 :
									// Java.g:471:17: type IDENT formalParameterList ( arrayDeclaratorList )? ( throwsClause )? SEMI
									{
									pushFollow(FOLLOW_type_in_interfaceScopeDeclarations6106);
									type108=type();
									state._fsp--;
									if (state.failed) return retval;
									if ( state.backtracking==0 ) stream_type.add(type108.getTree());
									IDENT109=(Token)match(input,IDENT,FOLLOW_IDENT_in_interfaceScopeDeclarations6108); if (state.failed) return retval; 
									if ( state.backtracking==0 ) stream_IDENT.add(IDENT109);

									pushFollow(FOLLOW_formalParameterList_in_interfaceScopeDeclarations6110);
									formalParameterList110=formalParameterList();
									state._fsp--;
									if (state.failed) return retval;
									if ( state.backtracking==0 ) stream_formalParameterList.add(formalParameterList110.getTree());
									// Java.g:471:48: ( arrayDeclaratorList )?
									int alt38=2;
									int LA38_0 = input.LA(1);
									if ( (LA38_0==LBRACK) ) {
										alt38=1;
									}
									switch (alt38) {
										case 1 :
											// Java.g:471:48: arrayDeclaratorList
											{
											pushFollow(FOLLOW_arrayDeclaratorList_in_interfaceScopeDeclarations6112);
											arrayDeclaratorList111=arrayDeclaratorList();
											state._fsp--;
											if (state.failed) return retval;
											if ( state.backtracking==0 ) stream_arrayDeclaratorList.add(arrayDeclaratorList111.getTree());
											}
											break;

									}

									// Java.g:471:69: ( throwsClause )?
									int alt39=2;
									int LA39_0 = input.LA(1);
									if ( (LA39_0==THROWS) ) {
										alt39=1;
									}
									switch (alt39) {
										case 1 :
											// Java.g:471:69: throwsClause
											{
											pushFollow(FOLLOW_throwsClause_in_interfaceScopeDeclarations6115);
											throwsClause112=throwsClause();
											state._fsp--;
											if (state.failed) return retval;
											if ( state.backtracking==0 ) stream_throwsClause.add(throwsClause112.getTree());
											}
											break;

									}

									SEMI113=(Token)match(input,SEMI,FOLLOW_SEMI_in_interfaceScopeDeclarations6118); if (state.failed) return retval; 
									if ( state.backtracking==0 ) stream_SEMI.add(SEMI113);

									// AST REWRITE
									// elements: arrayDeclaratorList, throwsClause, IDENT, type, formalParameterList, genericTypeParameterList, modifierList
									// token labels: 
									// rule labels: retval
									// token list labels: 
									// rule list labels: 
									// wildcard labels: 
									if ( state.backtracking==0 ) {

									retval.tree = root_0;
									RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

									root_0 = (CommonTree)adaptor.nil();
									// 472:17: -> ^( FUNCTION_METHOD_DECL modifierList ( genericTypeParameterList )? type IDENT formalParameterList ( arrayDeclaratorList )? ( throwsClause )? )
									{
										// Java.g:472:21: ^( FUNCTION_METHOD_DECL modifierList ( genericTypeParameterList )? type IDENT formalParameterList ( arrayDeclaratorList )? ( throwsClause )? )
										{
										CommonTree root_1 = (CommonTree)adaptor.nil();
										root_1 = (CommonTree)adaptor.becomeRoot(
										(CommonTree)adaptor.create(FUNCTION_METHOD_DECL, "FUNCTION_METHOD_DECL")
										, root_1);

										adaptor.addChild(root_1, stream_modifierList.nextTree());

										// Java.g:472:57: ( genericTypeParameterList )?
										if ( stream_genericTypeParameterList.hasNext() ) {
											adaptor.addChild(root_1, stream_genericTypeParameterList.nextTree());

										}
										stream_genericTypeParameterList.reset();

										adaptor.addChild(root_1, stream_type.nextTree());

										adaptor.addChild(root_1, 
										stream_IDENT.nextNode()
										);

										adaptor.addChild(root_1, stream_formalParameterList.nextTree());

										// Java.g:472:114: ( arrayDeclaratorList )?
										if ( stream_arrayDeclaratorList.hasNext() ) {
											adaptor.addChild(root_1, stream_arrayDeclaratorList.nextTree());

										}
										stream_arrayDeclaratorList.reset();

										// Java.g:472:135: ( throwsClause )?
										if ( stream_throwsClause.hasNext() ) {
											adaptor.addChild(root_1, stream_throwsClause.nextTree());

										}
										stream_throwsClause.reset();

										adaptor.addChild(root_0, root_1);
										}

									}


									retval.tree = root_0;
									}

									}
									break;
								case 2 :
									// Java.g:473:17: VOID IDENT formalParameterList ( throwsClause )? SEMI
									{
									VOID114=(Token)match(input,VOID,FOLLOW_VOID_in_interfaceScopeDeclarations6176); if (state.failed) return retval; 
									if ( state.backtracking==0 ) stream_VOID.add(VOID114);

									IDENT115=(Token)match(input,IDENT,FOLLOW_IDENT_in_interfaceScopeDeclarations6178); if (state.failed) return retval; 
									if ( state.backtracking==0 ) stream_IDENT.add(IDENT115);

									pushFollow(FOLLOW_formalParameterList_in_interfaceScopeDeclarations6180);
									formalParameterList116=formalParameterList();
									state._fsp--;
									if (state.failed) return retval;
									if ( state.backtracking==0 ) stream_formalParameterList.add(formalParameterList116.getTree());
									// Java.g:473:48: ( throwsClause )?
									int alt40=2;
									int LA40_0 = input.LA(1);
									if ( (LA40_0==THROWS) ) {
										alt40=1;
									}
									switch (alt40) {
										case 1 :
											// Java.g:473:48: throwsClause
											{
											pushFollow(FOLLOW_throwsClause_in_interfaceScopeDeclarations6182);
											throwsClause117=throwsClause();
											state._fsp--;
											if (state.failed) return retval;
											if ( state.backtracking==0 ) stream_throwsClause.add(throwsClause117.getTree());
											}
											break;

									}

									SEMI118=(Token)match(input,SEMI,FOLLOW_SEMI_in_interfaceScopeDeclarations6185); if (state.failed) return retval; 
									if ( state.backtracking==0 ) stream_SEMI.add(SEMI118);

									// AST REWRITE
									// elements: IDENT, throwsClause, modifierList, genericTypeParameterList, formalParameterList
									// token labels: 
									// rule labels: retval
									// token list labels: 
									// rule list labels: 
									// wildcard labels: 
									if ( state.backtracking==0 ) {

									retval.tree = root_0;
									RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

									root_0 = (CommonTree)adaptor.nil();
									// 474:17: -> ^( VOID_METHOD_DECL modifierList ( genericTypeParameterList )? IDENT formalParameterList ( throwsClause )? )
									{
										// Java.g:474:21: ^( VOID_METHOD_DECL modifierList ( genericTypeParameterList )? IDENT formalParameterList ( throwsClause )? )
										{
										CommonTree root_1 = (CommonTree)adaptor.nil();
										root_1 = (CommonTree)adaptor.becomeRoot(
										(CommonTree)adaptor.create(VOID_METHOD_DECL, "VOID_METHOD_DECL")
										, root_1);

										adaptor.addChild(root_1, stream_modifierList.nextTree());

										// Java.g:474:53: ( genericTypeParameterList )?
										if ( stream_genericTypeParameterList.hasNext() ) {
											adaptor.addChild(root_1, stream_genericTypeParameterList.nextTree());

										}
										stream_genericTypeParameterList.reset();

										adaptor.addChild(root_1, 
										stream_IDENT.nextNode()
										);

										adaptor.addChild(root_1, stream_formalParameterList.nextTree());

										// Java.g:474:105: ( throwsClause )?
										if ( stream_throwsClause.hasNext() ) {
											adaptor.addChild(root_1, stream_throwsClause.nextTree());

										}
										stream_throwsClause.reset();

										adaptor.addChild(root_0, root_1);
										}

									}


									retval.tree = root_0;
									}

									}
									break;

							}

							}
							break;
						case 2 :
							// Java.g:476:13: type interfaceFieldDeclaratorList SEMI
							{
							pushFollow(FOLLOW_type_in_interfaceScopeDeclarations6248);
							type119=type();
							state._fsp--;
							if (state.failed) return retval;
							if ( state.backtracking==0 ) stream_type.add(type119.getTree());
							pushFollow(FOLLOW_interfaceFieldDeclaratorList_in_interfaceScopeDeclarations6250);
							interfaceFieldDeclaratorList120=interfaceFieldDeclaratorList();
							state._fsp--;
							if (state.failed) return retval;
							if ( state.backtracking==0 ) stream_interfaceFieldDeclaratorList.add(interfaceFieldDeclaratorList120.getTree());
							SEMI121=(Token)match(input,SEMI,FOLLOW_SEMI_in_interfaceScopeDeclarations6252); if (state.failed) return retval; 
							if ( state.backtracking==0 ) stream_SEMI.add(SEMI121);

							// AST REWRITE
							// elements: interfaceFieldDeclaratorList, modifierList, type
							// token labels: 
							// rule labels: retval
							// token list labels: 
							// rule list labels: 
							// wildcard labels: 
							if ( state.backtracking==0 ) {

							retval.tree = root_0;
							RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

							root_0 = (CommonTree)adaptor.nil();
							// 477:13: -> ^( VAR_DECLARATION modifierList type interfaceFieldDeclaratorList )
							{
								// Java.g:477:17: ^( VAR_DECLARATION modifierList type interfaceFieldDeclaratorList )
								{
								CommonTree root_1 = (CommonTree)adaptor.nil();
								root_1 = (CommonTree)adaptor.becomeRoot(
								(CommonTree)adaptor.create(VAR_DECLARATION, "VAR_DECLARATION")
								, root_1);

								adaptor.addChild(root_1, stream_modifierList.nextTree());

								adaptor.addChild(root_1, stream_type.nextTree());

								adaptor.addChild(root_1, stream_interfaceFieldDeclaratorList.nextTree());

								adaptor.addChild(root_0, root_1);
								}

							}


							retval.tree = root_0;
							}

							}
							break;

					}

					}
					break;
				case 2 :
					// Java.g:479:9: typeDeclaration
					{
					root_0 = (CommonTree)adaptor.nil();


					pushFollow(FOLLOW_typeDeclaration_in_interfaceScopeDeclarations6297);
					typeDeclaration122=typeDeclaration();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) adaptor.addChild(root_0, typeDeclaration122.getTree());

					}
					break;
				case 3 :
					// Java.g:480:9: SEMI !
					{
					root_0 = (CommonTree)adaptor.nil();


					SEMI123=(Token)match(input,SEMI,FOLLOW_SEMI_in_interfaceScopeDeclarations6307); if (state.failed) return retval;
					}
					break;

			}
			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 26, interfaceScopeDeclarations_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "interfaceScopeDeclarations"


	public static class classFieldDeclaratorList_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "classFieldDeclaratorList"
	// Java.g:483:1: classFieldDeclaratorList : classFieldDeclarator ( COMMA classFieldDeclarator )* -> ^( VAR_DECLARATOR_LIST ( classFieldDeclarator )+ ) ;
	public final JavaParser.classFieldDeclaratorList_return classFieldDeclaratorList() throws RecognitionException {
		JavaParser.classFieldDeclaratorList_return retval = new JavaParser.classFieldDeclaratorList_return();
		retval.start = input.LT(1);
		int classFieldDeclaratorList_StartIndex = input.index();

		CommonTree root_0 = null;

		Token COMMA125=null;
		ParserRuleReturnScope classFieldDeclarator124 =null;
		ParserRuleReturnScope classFieldDeclarator126 =null;

		CommonTree COMMA125_tree=null;
		RewriteRuleTokenStream stream_COMMA=new RewriteRuleTokenStream(adaptor,"token COMMA");
		RewriteRuleSubtreeStream stream_classFieldDeclarator=new RewriteRuleSubtreeStream(adaptor,"rule classFieldDeclarator");

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 27) ) { return retval; }

			// Java.g:484:5: ( classFieldDeclarator ( COMMA classFieldDeclarator )* -> ^( VAR_DECLARATOR_LIST ( classFieldDeclarator )+ ) )
			// Java.g:484:9: classFieldDeclarator ( COMMA classFieldDeclarator )*
			{
			pushFollow(FOLLOW_classFieldDeclarator_in_classFieldDeclaratorList6327);
			classFieldDeclarator124=classFieldDeclarator();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) stream_classFieldDeclarator.add(classFieldDeclarator124.getTree());
			// Java.g:484:30: ( COMMA classFieldDeclarator )*
			loop44:
			do {
				int alt44=2;
				int LA44_0 = input.LA(1);
				if ( (LA44_0==COMMA) ) {
					alt44=1;
				}

				switch (alt44) {
				case 1 :
					// Java.g:484:31: COMMA classFieldDeclarator
					{
					COMMA125=(Token)match(input,COMMA,FOLLOW_COMMA_in_classFieldDeclaratorList6330); if (state.failed) return retval; 
					if ( state.backtracking==0 ) stream_COMMA.add(COMMA125);

					pushFollow(FOLLOW_classFieldDeclarator_in_classFieldDeclaratorList6332);
					classFieldDeclarator126=classFieldDeclarator();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_classFieldDeclarator.add(classFieldDeclarator126.getTree());
					}
					break;

				default :
					break loop44;
				}
			} while (true);

			// AST REWRITE
			// elements: classFieldDeclarator
			// token labels: 
			// rule labels: retval
			// token list labels: 
			// rule list labels: 
			// wildcard labels: 
			if ( state.backtracking==0 ) {

			retval.tree = root_0;
			RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

			root_0 = (CommonTree)adaptor.nil();
			// 485:9: -> ^( VAR_DECLARATOR_LIST ( classFieldDeclarator )+ )
			{
				// Java.g:485:13: ^( VAR_DECLARATOR_LIST ( classFieldDeclarator )+ )
				{
				CommonTree root_1 = (CommonTree)adaptor.nil();
				root_1 = (CommonTree)adaptor.becomeRoot(
				(CommonTree)adaptor.create(VAR_DECLARATOR_LIST, "VAR_DECLARATOR_LIST")
				, root_1);

				if ( !(stream_classFieldDeclarator.hasNext()) ) {
					throw new RewriteEarlyExitException();
				}
				while ( stream_classFieldDeclarator.hasNext() ) {
					adaptor.addChild(root_1, stream_classFieldDeclarator.nextTree());

				}
				stream_classFieldDeclarator.reset();

				adaptor.addChild(root_0, root_1);
				}

			}


			retval.tree = root_0;
			}

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 27, classFieldDeclaratorList_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "classFieldDeclaratorList"


	public static class classFieldDeclarator_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "classFieldDeclarator"
	// Java.g:488:1: classFieldDeclarator : variableDeclaratorId ( ASSIGN variableInitializer )? -> ^( VAR_DECLARATOR variableDeclaratorId ( variableInitializer )? ) ;
	public final JavaParser.classFieldDeclarator_return classFieldDeclarator() throws RecognitionException {
		JavaParser.classFieldDeclarator_return retval = new JavaParser.classFieldDeclarator_return();
		retval.start = input.LT(1);
		int classFieldDeclarator_StartIndex = input.index();

		CommonTree root_0 = null;

		Token ASSIGN128=null;
		ParserRuleReturnScope variableDeclaratorId127 =null;
		ParserRuleReturnScope variableInitializer129 =null;

		CommonTree ASSIGN128_tree=null;
		RewriteRuleTokenStream stream_ASSIGN=new RewriteRuleTokenStream(adaptor,"token ASSIGN");
		RewriteRuleSubtreeStream stream_variableDeclaratorId=new RewriteRuleSubtreeStream(adaptor,"rule variableDeclaratorId");
		RewriteRuleSubtreeStream stream_variableInitializer=new RewriteRuleSubtreeStream(adaptor,"rule variableInitializer");

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 28) ) { return retval; }

			// Java.g:489:5: ( variableDeclaratorId ( ASSIGN variableInitializer )? -> ^( VAR_DECLARATOR variableDeclaratorId ( variableInitializer )? ) )
			// Java.g:489:9: variableDeclaratorId ( ASSIGN variableInitializer )?
			{
			pushFollow(FOLLOW_variableDeclaratorId_in_classFieldDeclarator6371);
			variableDeclaratorId127=variableDeclaratorId();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) stream_variableDeclaratorId.add(variableDeclaratorId127.getTree());
			// Java.g:489:30: ( ASSIGN variableInitializer )?
			int alt45=2;
			int LA45_0 = input.LA(1);
			if ( (LA45_0==ASSIGN) ) {
				alt45=1;
			}
			switch (alt45) {
				case 1 :
					// Java.g:489:31: ASSIGN variableInitializer
					{
					ASSIGN128=(Token)match(input,ASSIGN,FOLLOW_ASSIGN_in_classFieldDeclarator6374); if (state.failed) return retval; 
					if ( state.backtracking==0 ) stream_ASSIGN.add(ASSIGN128);

					pushFollow(FOLLOW_variableInitializer_in_classFieldDeclarator6376);
					variableInitializer129=variableInitializer();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_variableInitializer.add(variableInitializer129.getTree());
					}
					break;

			}

			// AST REWRITE
			// elements: variableInitializer, variableDeclaratorId
			// token labels: 
			// rule labels: retval
			// token list labels: 
			// rule list labels: 
			// wildcard labels: 
			if ( state.backtracking==0 ) {

			retval.tree = root_0;
			RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

			root_0 = (CommonTree)adaptor.nil();
			// 490:9: -> ^( VAR_DECLARATOR variableDeclaratorId ( variableInitializer )? )
			{
				// Java.g:490:13: ^( VAR_DECLARATOR variableDeclaratorId ( variableInitializer )? )
				{
				CommonTree root_1 = (CommonTree)adaptor.nil();
				root_1 = (CommonTree)adaptor.becomeRoot(
				(CommonTree)adaptor.create(VAR_DECLARATOR, "VAR_DECLARATOR")
				, root_1);

				adaptor.addChild(root_1, stream_variableDeclaratorId.nextTree());

				// Java.g:490:51: ( variableInitializer )?
				if ( stream_variableInitializer.hasNext() ) {
					adaptor.addChild(root_1, stream_variableInitializer.nextTree());

				}
				stream_variableInitializer.reset();

				adaptor.addChild(root_0, root_1);
				}

			}


			retval.tree = root_0;
			}

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 28, classFieldDeclarator_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "classFieldDeclarator"


	public static class interfaceFieldDeclaratorList_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "interfaceFieldDeclaratorList"
	// Java.g:493:1: interfaceFieldDeclaratorList : interfaceFieldDeclarator ( COMMA interfaceFieldDeclarator )* -> ^( VAR_DECLARATOR_LIST ( interfaceFieldDeclarator )+ ) ;
	public final JavaParser.interfaceFieldDeclaratorList_return interfaceFieldDeclaratorList() throws RecognitionException {
		JavaParser.interfaceFieldDeclaratorList_return retval = new JavaParser.interfaceFieldDeclaratorList_return();
		retval.start = input.LT(1);
		int interfaceFieldDeclaratorList_StartIndex = input.index();

		CommonTree root_0 = null;

		Token COMMA131=null;
		ParserRuleReturnScope interfaceFieldDeclarator130 =null;
		ParserRuleReturnScope interfaceFieldDeclarator132 =null;

		CommonTree COMMA131_tree=null;
		RewriteRuleTokenStream stream_COMMA=new RewriteRuleTokenStream(adaptor,"token COMMA");
		RewriteRuleSubtreeStream stream_interfaceFieldDeclarator=new RewriteRuleSubtreeStream(adaptor,"rule interfaceFieldDeclarator");

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 29) ) { return retval; }

			// Java.g:494:5: ( interfaceFieldDeclarator ( COMMA interfaceFieldDeclarator )* -> ^( VAR_DECLARATOR_LIST ( interfaceFieldDeclarator )+ ) )
			// Java.g:494:9: interfaceFieldDeclarator ( COMMA interfaceFieldDeclarator )*
			{
			pushFollow(FOLLOW_interfaceFieldDeclarator_in_interfaceFieldDeclaratorList6421);
			interfaceFieldDeclarator130=interfaceFieldDeclarator();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) stream_interfaceFieldDeclarator.add(interfaceFieldDeclarator130.getTree());
			// Java.g:494:34: ( COMMA interfaceFieldDeclarator )*
			loop46:
			do {
				int alt46=2;
				int LA46_0 = input.LA(1);
				if ( (LA46_0==COMMA) ) {
					alt46=1;
				}

				switch (alt46) {
				case 1 :
					// Java.g:494:35: COMMA interfaceFieldDeclarator
					{
					COMMA131=(Token)match(input,COMMA,FOLLOW_COMMA_in_interfaceFieldDeclaratorList6424); if (state.failed) return retval; 
					if ( state.backtracking==0 ) stream_COMMA.add(COMMA131);

					pushFollow(FOLLOW_interfaceFieldDeclarator_in_interfaceFieldDeclaratorList6426);
					interfaceFieldDeclarator132=interfaceFieldDeclarator();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_interfaceFieldDeclarator.add(interfaceFieldDeclarator132.getTree());
					}
					break;

				default :
					break loop46;
				}
			} while (true);

			// AST REWRITE
			// elements: interfaceFieldDeclarator
			// token labels: 
			// rule labels: retval
			// token list labels: 
			// rule list labels: 
			// wildcard labels: 
			if ( state.backtracking==0 ) {

			retval.tree = root_0;
			RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

			root_0 = (CommonTree)adaptor.nil();
			// 495:9: -> ^( VAR_DECLARATOR_LIST ( interfaceFieldDeclarator )+ )
			{
				// Java.g:495:13: ^( VAR_DECLARATOR_LIST ( interfaceFieldDeclarator )+ )
				{
				CommonTree root_1 = (CommonTree)adaptor.nil();
				root_1 = (CommonTree)adaptor.becomeRoot(
				(CommonTree)adaptor.create(VAR_DECLARATOR_LIST, "VAR_DECLARATOR_LIST")
				, root_1);

				if ( !(stream_interfaceFieldDeclarator.hasNext()) ) {
					throw new RewriteEarlyExitException();
				}
				while ( stream_interfaceFieldDeclarator.hasNext() ) {
					adaptor.addChild(root_1, stream_interfaceFieldDeclarator.nextTree());

				}
				stream_interfaceFieldDeclarator.reset();

				adaptor.addChild(root_0, root_1);
				}

			}


			retval.tree = root_0;
			}

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 29, interfaceFieldDeclaratorList_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "interfaceFieldDeclaratorList"


	public static class interfaceFieldDeclarator_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "interfaceFieldDeclarator"
	// Java.g:498:1: interfaceFieldDeclarator : variableDeclaratorId ASSIGN variableInitializer -> ^( VAR_DECLARATOR variableDeclaratorId variableInitializer ) ;
	public final JavaParser.interfaceFieldDeclarator_return interfaceFieldDeclarator() throws RecognitionException {
		JavaParser.interfaceFieldDeclarator_return retval = new JavaParser.interfaceFieldDeclarator_return();
		retval.start = input.LT(1);
		int interfaceFieldDeclarator_StartIndex = input.index();

		CommonTree root_0 = null;

		Token ASSIGN134=null;
		ParserRuleReturnScope variableDeclaratorId133 =null;
		ParserRuleReturnScope variableInitializer135 =null;

		CommonTree ASSIGN134_tree=null;
		RewriteRuleTokenStream stream_ASSIGN=new RewriteRuleTokenStream(adaptor,"token ASSIGN");
		RewriteRuleSubtreeStream stream_variableDeclaratorId=new RewriteRuleSubtreeStream(adaptor,"rule variableDeclaratorId");
		RewriteRuleSubtreeStream stream_variableInitializer=new RewriteRuleSubtreeStream(adaptor,"rule variableInitializer");

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 30) ) { return retval; }

			// Java.g:499:5: ( variableDeclaratorId ASSIGN variableInitializer -> ^( VAR_DECLARATOR variableDeclaratorId variableInitializer ) )
			// Java.g:499:9: variableDeclaratorId ASSIGN variableInitializer
			{
			pushFollow(FOLLOW_variableDeclaratorId_in_interfaceFieldDeclarator6465);
			variableDeclaratorId133=variableDeclaratorId();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) stream_variableDeclaratorId.add(variableDeclaratorId133.getTree());
			ASSIGN134=(Token)match(input,ASSIGN,FOLLOW_ASSIGN_in_interfaceFieldDeclarator6467); if (state.failed) return retval; 
			if ( state.backtracking==0 ) stream_ASSIGN.add(ASSIGN134);

			pushFollow(FOLLOW_variableInitializer_in_interfaceFieldDeclarator6469);
			variableInitializer135=variableInitializer();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) stream_variableInitializer.add(variableInitializer135.getTree());
			// AST REWRITE
			// elements: variableDeclaratorId, variableInitializer
			// token labels: 
			// rule labels: retval
			// token list labels: 
			// rule list labels: 
			// wildcard labels: 
			if ( state.backtracking==0 ) {

			retval.tree = root_0;
			RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

			root_0 = (CommonTree)adaptor.nil();
			// 500:9: -> ^( VAR_DECLARATOR variableDeclaratorId variableInitializer )
			{
				// Java.g:500:13: ^( VAR_DECLARATOR variableDeclaratorId variableInitializer )
				{
				CommonTree root_1 = (CommonTree)adaptor.nil();
				root_1 = (CommonTree)adaptor.becomeRoot(
				(CommonTree)adaptor.create(VAR_DECLARATOR, "VAR_DECLARATOR")
				, root_1);

				adaptor.addChild(root_1, stream_variableDeclaratorId.nextTree());

				adaptor.addChild(root_1, stream_variableInitializer.nextTree());

				adaptor.addChild(root_0, root_1);
				}

			}


			retval.tree = root_0;
			}

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 30, interfaceFieldDeclarator_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "interfaceFieldDeclarator"


	public static class variableDeclaratorId_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "variableDeclaratorId"
	// Java.g:503:1: variableDeclaratorId : IDENT ^ ( arrayDeclaratorList )? ;
	public final JavaParser.variableDeclaratorId_return variableDeclaratorId() throws RecognitionException {
		JavaParser.variableDeclaratorId_return retval = new JavaParser.variableDeclaratorId_return();
		retval.start = input.LT(1);
		int variableDeclaratorId_StartIndex = input.index();

		CommonTree root_0 = null;

		Token IDENT136=null;
		ParserRuleReturnScope arrayDeclaratorList137 =null;

		CommonTree IDENT136_tree=null;

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 31) ) { return retval; }

			// Java.g:504:5: ( IDENT ^ ( arrayDeclaratorList )? )
			// Java.g:504:9: IDENT ^ ( arrayDeclaratorList )?
			{
			root_0 = (CommonTree)adaptor.nil();


			IDENT136=(Token)match(input,IDENT,FOLLOW_IDENT_in_variableDeclaratorId6511); if (state.failed) return retval;
			if ( state.backtracking==0 ) {
			IDENT136_tree = 
			(CommonTree)adaptor.create(IDENT136)
			;
			root_0 = (CommonTree)adaptor.becomeRoot(IDENT136_tree, root_0);
			}

			// Java.g:504:16: ( arrayDeclaratorList )?
			int alt47=2;
			int LA47_0 = input.LA(1);
			if ( (LA47_0==LBRACK) ) {
				alt47=1;
			}
			switch (alt47) {
				case 1 :
					// Java.g:504:16: arrayDeclaratorList
					{
					pushFollow(FOLLOW_arrayDeclaratorList_in_variableDeclaratorId6514);
					arrayDeclaratorList137=arrayDeclaratorList();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) adaptor.addChild(root_0, arrayDeclaratorList137.getTree());

					}
					break;

			}

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 31, variableDeclaratorId_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "variableDeclaratorId"


	public static class variableInitializer_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "variableInitializer"
	// Java.g:507:1: variableInitializer : ( arrayInitializer | expression );
	public final JavaParser.variableInitializer_return variableInitializer() throws RecognitionException {
		JavaParser.variableInitializer_return retval = new JavaParser.variableInitializer_return();
		retval.start = input.LT(1);
		int variableInitializer_StartIndex = input.index();

		CommonTree root_0 = null;

		ParserRuleReturnScope arrayInitializer138 =null;
		ParserRuleReturnScope expression139 =null;


		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 32) ) { return retval; }

			// Java.g:508:5: ( arrayInitializer | expression )
			int alt48=2;
			int LA48_0 = input.LA(1);
			if ( (LA48_0==LCURLY) ) {
				alt48=1;
			}
			else if ( (LA48_0==BOOLEAN||LA48_0==BYTE||(LA48_0 >= CHAR && LA48_0 <= CHARACTER_LITERAL)||(LA48_0 >= DEC && LA48_0 <= DECIMAL_LITERAL)||LA48_0==DOUBLE||LA48_0==FALSE||(LA48_0 >= FLOAT && LA48_0 <= FLOATING_POINT_LITERAL)||(LA48_0 >= HEX_LITERAL && LA48_0 <= IDENT)||LA48_0==INC||LA48_0==INT||LA48_0==LESS_THAN||LA48_0==LOGICAL_NOT||(LA48_0 >= LONG && LA48_0 <= LPAREN)||LA48_0==MINUS||(LA48_0 >= NEW && LA48_0 <= NOT)||LA48_0==NULL||LA48_0==OCTAL_LITERAL||LA48_0==PLUS||LA48_0==SHORT||(LA48_0 >= STRING_LITERAL && LA48_0 <= SUPER)||LA48_0==THIS||LA48_0==TRUE||LA48_0==VOID) ) {
				alt48=2;
			}
			else {
				if (state.backtracking>0) {state.failed=true; return retval;}
				NoViableAltException nvae =
					new NoViableAltException("", 48, 0, input);
				throw nvae;
			}
			switch (alt48) {
				case 1 :
					// Java.g:508:9: arrayInitializer
					{
					root_0 = (CommonTree)adaptor.nil();


					pushFollow(FOLLOW_arrayInitializer_in_variableInitializer6534);
					arrayInitializer138=arrayInitializer();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) adaptor.addChild(root_0, arrayInitializer138.getTree());

					}
					break;
				case 2 :
					// Java.g:509:9: expression
					{
					root_0 = (CommonTree)adaptor.nil();


					pushFollow(FOLLOW_expression_in_variableInitializer6544);
					expression139=expression();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) adaptor.addChild(root_0, expression139.getTree());

					}
					break;

			}
			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 32, variableInitializer_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "variableInitializer"


	public static class arrayDeclarator_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "arrayDeclarator"
	// Java.g:512:1: arrayDeclarator : LBRACK RBRACK -> ^( ARRAY_DECLARATOR ) ;
	public final JavaParser.arrayDeclarator_return arrayDeclarator() throws RecognitionException {
		JavaParser.arrayDeclarator_return retval = new JavaParser.arrayDeclarator_return();
		retval.start = input.LT(1);
		int arrayDeclarator_StartIndex = input.index();

		CommonTree root_0 = null;

		Token LBRACK140=null;
		Token RBRACK141=null;

		CommonTree LBRACK140_tree=null;
		CommonTree RBRACK141_tree=null;
		RewriteRuleTokenStream stream_RBRACK=new RewriteRuleTokenStream(adaptor,"token RBRACK");
		RewriteRuleTokenStream stream_LBRACK=new RewriteRuleTokenStream(adaptor,"token LBRACK");

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 33) ) { return retval; }

			// Java.g:513:5: ( LBRACK RBRACK -> ^( ARRAY_DECLARATOR ) )
			// Java.g:513:9: LBRACK RBRACK
			{
			LBRACK140=(Token)match(input,LBRACK,FOLLOW_LBRACK_in_arrayDeclarator6563); if (state.failed) return retval; 
			if ( state.backtracking==0 ) stream_LBRACK.add(LBRACK140);

			RBRACK141=(Token)match(input,RBRACK,FOLLOW_RBRACK_in_arrayDeclarator6565); if (state.failed) return retval; 
			if ( state.backtracking==0 ) stream_RBRACK.add(RBRACK141);

			// AST REWRITE
			// elements: 
			// token labels: 
			// rule labels: retval
			// token list labels: 
			// rule list labels: 
			// wildcard labels: 
			if ( state.backtracking==0 ) {

			retval.tree = root_0;
			RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

			root_0 = (CommonTree)adaptor.nil();
			// 514:9: -> ^( ARRAY_DECLARATOR )
			{
				// Java.g:514:13: ^( ARRAY_DECLARATOR )
				{
				CommonTree root_1 = (CommonTree)adaptor.nil();
				root_1 = (CommonTree)adaptor.becomeRoot(
				(CommonTree)adaptor.create(ARRAY_DECLARATOR, "ARRAY_DECLARATOR")
				, root_1);

				adaptor.addChild(root_0, root_1);
				}

			}


			retval.tree = root_0;
			}

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 33, arrayDeclarator_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "arrayDeclarator"


	public static class arrayDeclaratorList_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "arrayDeclaratorList"
	// Java.g:517:1: arrayDeclaratorList : ( arrayDeclarator )+ -> ^( ARRAY_DECLARATOR_LIST ( arrayDeclarator )+ ) ;
	public final JavaParser.arrayDeclaratorList_return arrayDeclaratorList() throws RecognitionException {
		JavaParser.arrayDeclaratorList_return retval = new JavaParser.arrayDeclaratorList_return();
		retval.start = input.LT(1);
		int arrayDeclaratorList_StartIndex = input.index();

		CommonTree root_0 = null;

		ParserRuleReturnScope arrayDeclarator142 =null;

		RewriteRuleSubtreeStream stream_arrayDeclarator=new RewriteRuleSubtreeStream(adaptor,"rule arrayDeclarator");

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 34) ) { return retval; }

			// Java.g:518:5: ( ( arrayDeclarator )+ -> ^( ARRAY_DECLARATOR_LIST ( arrayDeclarator )+ ) )
			// Java.g:518:9: ( arrayDeclarator )+
			{
			// Java.g:518:9: ( arrayDeclarator )+
			int cnt49=0;
			loop49:
			do {
				int alt49=2;
				int LA49_0 = input.LA(1);
				if ( (LA49_0==LBRACK) ) {
					int LA49_2 = input.LA(2);
					if ( (synpred58_Java()) ) {
						alt49=1;
					}

				}

				switch (alt49) {
				case 1 :
					// Java.g:518:9: arrayDeclarator
					{
					pushFollow(FOLLOW_arrayDeclarator_in_arrayDeclaratorList6599);
					arrayDeclarator142=arrayDeclarator();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_arrayDeclarator.add(arrayDeclarator142.getTree());
					}
					break;

				default :
					if ( cnt49 >= 1 ) break loop49;
					if (state.backtracking>0) {state.failed=true; return retval;}
						EarlyExitException eee =
							new EarlyExitException(49, input);
						throw eee;
				}
				cnt49++;
			} while (true);

			// AST REWRITE
			// elements: arrayDeclarator
			// token labels: 
			// rule labels: retval
			// token list labels: 
			// rule list labels: 
			// wildcard labels: 
			if ( state.backtracking==0 ) {

			retval.tree = root_0;
			RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

			root_0 = (CommonTree)adaptor.nil();
			// 519:9: -> ^( ARRAY_DECLARATOR_LIST ( arrayDeclarator )+ )
			{
				// Java.g:519:13: ^( ARRAY_DECLARATOR_LIST ( arrayDeclarator )+ )
				{
				CommonTree root_1 = (CommonTree)adaptor.nil();
				root_1 = (CommonTree)adaptor.becomeRoot(
				(CommonTree)adaptor.create(ARRAY_DECLARATOR_LIST, "ARRAY_DECLARATOR_LIST")
				, root_1);

				if ( !(stream_arrayDeclarator.hasNext()) ) {
					throw new RewriteEarlyExitException();
				}
				while ( stream_arrayDeclarator.hasNext() ) {
					adaptor.addChild(root_1, stream_arrayDeclarator.nextTree());

				}
				stream_arrayDeclarator.reset();

				adaptor.addChild(root_0, root_1);
				}

			}


			retval.tree = root_0;
			}

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 34, arrayDeclaratorList_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "arrayDeclaratorList"


	public static class arrayInitializer_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "arrayInitializer"
	// Java.g:522:1: arrayInitializer : LCURLY ( variableInitializer ( COMMA variableInitializer )* ( COMMA )? )? RCURLY -> ^( ARRAY_INITIALIZER[$LCURLY, \"ARRAY_INITIALIZER\"] ( variableInitializer )* ) ;
	public final JavaParser.arrayInitializer_return arrayInitializer() throws RecognitionException {
		JavaParser.arrayInitializer_return retval = new JavaParser.arrayInitializer_return();
		retval.start = input.LT(1);
		int arrayInitializer_StartIndex = input.index();

		CommonTree root_0 = null;

		Token LCURLY143=null;
		Token COMMA145=null;
		Token COMMA147=null;
		Token RCURLY148=null;
		ParserRuleReturnScope variableInitializer144 =null;
		ParserRuleReturnScope variableInitializer146 =null;

		CommonTree LCURLY143_tree=null;
		CommonTree COMMA145_tree=null;
		CommonTree COMMA147_tree=null;
		CommonTree RCURLY148_tree=null;
		RewriteRuleTokenStream stream_LCURLY=new RewriteRuleTokenStream(adaptor,"token LCURLY");
		RewriteRuleTokenStream stream_COMMA=new RewriteRuleTokenStream(adaptor,"token COMMA");
		RewriteRuleTokenStream stream_RCURLY=new RewriteRuleTokenStream(adaptor,"token RCURLY");
		RewriteRuleSubtreeStream stream_variableInitializer=new RewriteRuleSubtreeStream(adaptor,"rule variableInitializer");

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 35) ) { return retval; }

			// Java.g:523:5: ( LCURLY ( variableInitializer ( COMMA variableInitializer )* ( COMMA )? )? RCURLY -> ^( ARRAY_INITIALIZER[$LCURLY, \"ARRAY_INITIALIZER\"] ( variableInitializer )* ) )
			// Java.g:523:9: LCURLY ( variableInitializer ( COMMA variableInitializer )* ( COMMA )? )? RCURLY
			{
			LCURLY143=(Token)match(input,LCURLY,FOLLOW_LCURLY_in_arrayInitializer6644); if (state.failed) return retval; 
			if ( state.backtracking==0 ) stream_LCURLY.add(LCURLY143);

			// Java.g:523:16: ( variableInitializer ( COMMA variableInitializer )* ( COMMA )? )?
			int alt52=2;
			int LA52_0 = input.LA(1);
			if ( (LA52_0==BOOLEAN||LA52_0==BYTE||(LA52_0 >= CHAR && LA52_0 <= CHARACTER_LITERAL)||(LA52_0 >= DEC && LA52_0 <= DECIMAL_LITERAL)||LA52_0==DOUBLE||LA52_0==FALSE||(LA52_0 >= FLOAT && LA52_0 <= FLOATING_POINT_LITERAL)||(LA52_0 >= HEX_LITERAL && LA52_0 <= IDENT)||LA52_0==INC||LA52_0==INT||LA52_0==LCURLY||LA52_0==LESS_THAN||LA52_0==LOGICAL_NOT||(LA52_0 >= LONG && LA52_0 <= LPAREN)||LA52_0==MINUS||(LA52_0 >= NEW && LA52_0 <= NOT)||LA52_0==NULL||LA52_0==OCTAL_LITERAL||LA52_0==PLUS||LA52_0==SHORT||(LA52_0 >= STRING_LITERAL && LA52_0 <= SUPER)||LA52_0==THIS||LA52_0==TRUE||LA52_0==VOID) ) {
				alt52=1;
			}
			switch (alt52) {
				case 1 :
					// Java.g:523:17: variableInitializer ( COMMA variableInitializer )* ( COMMA )?
					{
					pushFollow(FOLLOW_variableInitializer_in_arrayInitializer6647);
					variableInitializer144=variableInitializer();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_variableInitializer.add(variableInitializer144.getTree());
					// Java.g:523:37: ( COMMA variableInitializer )*
					loop50:
					do {
						int alt50=2;
						int LA50_0 = input.LA(1);
						if ( (LA50_0==COMMA) ) {
							int LA50_1 = input.LA(2);
							if ( (LA50_1==BOOLEAN||LA50_1==BYTE||(LA50_1 >= CHAR && LA50_1 <= CHARACTER_LITERAL)||(LA50_1 >= DEC && LA50_1 <= DECIMAL_LITERAL)||LA50_1==DOUBLE||LA50_1==FALSE||(LA50_1 >= FLOAT && LA50_1 <= FLOATING_POINT_LITERAL)||(LA50_1 >= HEX_LITERAL && LA50_1 <= IDENT)||LA50_1==INC||LA50_1==INT||LA50_1==LCURLY||LA50_1==LESS_THAN||LA50_1==LOGICAL_NOT||(LA50_1 >= LONG && LA50_1 <= LPAREN)||LA50_1==MINUS||(LA50_1 >= NEW && LA50_1 <= NOT)||LA50_1==NULL||LA50_1==OCTAL_LITERAL||LA50_1==PLUS||LA50_1==SHORT||(LA50_1 >= STRING_LITERAL && LA50_1 <= SUPER)||LA50_1==THIS||LA50_1==TRUE||LA50_1==VOID) ) {
								alt50=1;
							}

						}

						switch (alt50) {
						case 1 :
							// Java.g:523:38: COMMA variableInitializer
							{
							COMMA145=(Token)match(input,COMMA,FOLLOW_COMMA_in_arrayInitializer6650); if (state.failed) return retval; 
							if ( state.backtracking==0 ) stream_COMMA.add(COMMA145);

							pushFollow(FOLLOW_variableInitializer_in_arrayInitializer6652);
							variableInitializer146=variableInitializer();
							state._fsp--;
							if (state.failed) return retval;
							if ( state.backtracking==0 ) stream_variableInitializer.add(variableInitializer146.getTree());
							}
							break;

						default :
							break loop50;
						}
					} while (true);

					// Java.g:523:66: ( COMMA )?
					int alt51=2;
					int LA51_0 = input.LA(1);
					if ( (LA51_0==COMMA) ) {
						alt51=1;
					}
					switch (alt51) {
						case 1 :
							// Java.g:523:66: COMMA
							{
							COMMA147=(Token)match(input,COMMA,FOLLOW_COMMA_in_arrayInitializer6656); if (state.failed) return retval; 
							if ( state.backtracking==0 ) stream_COMMA.add(COMMA147);

							}
							break;

					}

					}
					break;

			}

			RCURLY148=(Token)match(input,RCURLY,FOLLOW_RCURLY_in_arrayInitializer6661); if (state.failed) return retval; 
			if ( state.backtracking==0 ) stream_RCURLY.add(RCURLY148);

			// AST REWRITE
			// elements: variableInitializer
			// token labels: 
			// rule labels: retval
			// token list labels: 
			// rule list labels: 
			// wildcard labels: 
			if ( state.backtracking==0 ) {

			retval.tree = root_0;
			RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

			root_0 = (CommonTree)adaptor.nil();
			// 524:9: -> ^( ARRAY_INITIALIZER[$LCURLY, \"ARRAY_INITIALIZER\"] ( variableInitializer )* )
			{
				// Java.g:524:13: ^( ARRAY_INITIALIZER[$LCURLY, \"ARRAY_INITIALIZER\"] ( variableInitializer )* )
				{
				CommonTree root_1 = (CommonTree)adaptor.nil();
				root_1 = (CommonTree)adaptor.becomeRoot(
				(CommonTree)adaptor.create(ARRAY_INITIALIZER, LCURLY143, "ARRAY_INITIALIZER")
				, root_1);

				// Java.g:524:63: ( variableInitializer )*
				while ( stream_variableInitializer.hasNext() ) {
					adaptor.addChild(root_1, stream_variableInitializer.nextTree());

				}
				stream_variableInitializer.reset();

				adaptor.addChild(root_0, root_1);
				}

			}


			retval.tree = root_0;
			}

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 35, arrayInitializer_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "arrayInitializer"


	public static class throwsClause_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "throwsClause"
	// Java.g:527:1: throwsClause : THROWS qualifiedIdentList -> ^( THROWS_CLAUSE[$THROWS, \"THROWS_CLAUSE\"] qualifiedIdentList ) ;
	public final JavaParser.throwsClause_return throwsClause() throws RecognitionException {
		JavaParser.throwsClause_return retval = new JavaParser.throwsClause_return();
		retval.start = input.LT(1);
		int throwsClause_StartIndex = input.index();

		CommonTree root_0 = null;

		Token THROWS149=null;
		ParserRuleReturnScope qualifiedIdentList150 =null;

		CommonTree THROWS149_tree=null;
		RewriteRuleTokenStream stream_THROWS=new RewriteRuleTokenStream(adaptor,"token THROWS");
		RewriteRuleSubtreeStream stream_qualifiedIdentList=new RewriteRuleSubtreeStream(adaptor,"rule qualifiedIdentList");

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 36) ) { return retval; }

			// Java.g:528:5: ( THROWS qualifiedIdentList -> ^( THROWS_CLAUSE[$THROWS, \"THROWS_CLAUSE\"] qualifiedIdentList ) )
			// Java.g:528:9: THROWS qualifiedIdentList
			{
			THROWS149=(Token)match(input,THROWS,FOLLOW_THROWS_in_throwsClause6699); if (state.failed) return retval; 
			if ( state.backtracking==0 ) stream_THROWS.add(THROWS149);

			pushFollow(FOLLOW_qualifiedIdentList_in_throwsClause6701);
			qualifiedIdentList150=qualifiedIdentList();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) stream_qualifiedIdentList.add(qualifiedIdentList150.getTree());
			// AST REWRITE
			// elements: qualifiedIdentList
			// token labels: 
			// rule labels: retval
			// token list labels: 
			// rule list labels: 
			// wildcard labels: 
			if ( state.backtracking==0 ) {

			retval.tree = root_0;
			RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

			root_0 = (CommonTree)adaptor.nil();
			// 529:9: -> ^( THROWS_CLAUSE[$THROWS, \"THROWS_CLAUSE\"] qualifiedIdentList )
			{
				// Java.g:529:13: ^( THROWS_CLAUSE[$THROWS, \"THROWS_CLAUSE\"] qualifiedIdentList )
				{
				CommonTree root_1 = (CommonTree)adaptor.nil();
				root_1 = (CommonTree)adaptor.becomeRoot(
				(CommonTree)adaptor.create(THROWS_CLAUSE, THROWS149, "THROWS_CLAUSE")
				, root_1);

				adaptor.addChild(root_1, stream_qualifiedIdentList.nextTree());

				adaptor.addChild(root_0, root_1);
				}

			}


			retval.tree = root_0;
			}

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 36, throwsClause_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "throwsClause"


	public static class modifierList_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "modifierList"
	// Java.g:532:1: modifierList : ( modifier )* -> ^( MODIFIER_LIST ( modifier )* ) ;
	public final JavaParser.modifierList_return modifierList() throws RecognitionException {
		JavaParser.modifierList_return retval = new JavaParser.modifierList_return();
		retval.start = input.LT(1);
		int modifierList_StartIndex = input.index();

		CommonTree root_0 = null;

		ParserRuleReturnScope modifier151 =null;

		RewriteRuleSubtreeStream stream_modifier=new RewriteRuleSubtreeStream(adaptor,"rule modifier");

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 37) ) { return retval; }

			// Java.g:533:5: ( ( modifier )* -> ^( MODIFIER_LIST ( modifier )* ) )
			// Java.g:533:9: ( modifier )*
			{
			// Java.g:533:9: ( modifier )*
			loop53:
			do {
				int alt53=2;
				int LA53_0 = input.LA(1);
				if ( (LA53_0==AT) ) {
					int LA53_2 = input.LA(2);
					if ( (LA53_2==IDENT) ) {
						alt53=1;
					}

				}
				else if ( (LA53_0==ABSTRACT||LA53_0==FINAL||LA53_0==NATIVE||(LA53_0 >= PRIVATE && LA53_0 <= PUBLIC)||LA53_0==STATIC||LA53_0==STRICTFP||LA53_0==SYNCHRONIZED||LA53_0==TRANSIENT||LA53_0==VOLATILE) ) {
					alt53=1;
				}

				switch (alt53) {
				case 1 :
					// Java.g:533:9: modifier
					{
					pushFollow(FOLLOW_modifier_in_modifierList6738);
					modifier151=modifier();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_modifier.add(modifier151.getTree());
					}
					break;

				default :
					break loop53;
				}
			} while (true);

			// AST REWRITE
			// elements: modifier
			// token labels: 
			// rule labels: retval
			// token list labels: 
			// rule list labels: 
			// wildcard labels: 
			if ( state.backtracking==0 ) {

			retval.tree = root_0;
			RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

			root_0 = (CommonTree)adaptor.nil();
			// 534:9: -> ^( MODIFIER_LIST ( modifier )* )
			{
				// Java.g:534:13: ^( MODIFIER_LIST ( modifier )* )
				{
				CommonTree root_1 = (CommonTree)adaptor.nil();
				root_1 = (CommonTree)adaptor.becomeRoot(
				(CommonTree)adaptor.create(MODIFIER_LIST, "MODIFIER_LIST")
				, root_1);

				// Java.g:534:29: ( modifier )*
				while ( stream_modifier.hasNext() ) {
					adaptor.addChild(root_1, stream_modifier.nextTree());

				}
				stream_modifier.reset();

				adaptor.addChild(root_0, root_1);
				}

			}


			retval.tree = root_0;
			}

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 37, modifierList_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "modifierList"


	public static class modifier_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "modifier"
	// Java.g:537:1: modifier : ( PUBLIC | PROTECTED | PRIVATE | STATIC | ABSTRACT | NATIVE | SYNCHRONIZED | TRANSIENT | VOLATILE | STRICTFP | localModifier );
	public final JavaParser.modifier_return modifier() throws RecognitionException {
		JavaParser.modifier_return retval = new JavaParser.modifier_return();
		retval.start = input.LT(1);
		int modifier_StartIndex = input.index();

		CommonTree root_0 = null;

		Token PUBLIC152=null;
		Token PROTECTED153=null;
		Token PRIVATE154=null;
		Token STATIC155=null;
		Token ABSTRACT156=null;
		Token NATIVE157=null;
		Token SYNCHRONIZED158=null;
		Token TRANSIENT159=null;
		Token VOLATILE160=null;
		Token STRICTFP161=null;
		ParserRuleReturnScope localModifier162 =null;

		CommonTree PUBLIC152_tree=null;
		CommonTree PROTECTED153_tree=null;
		CommonTree PRIVATE154_tree=null;
		CommonTree STATIC155_tree=null;
		CommonTree ABSTRACT156_tree=null;
		CommonTree NATIVE157_tree=null;
		CommonTree SYNCHRONIZED158_tree=null;
		CommonTree TRANSIENT159_tree=null;
		CommonTree VOLATILE160_tree=null;
		CommonTree STRICTFP161_tree=null;

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 38) ) { return retval; }

			// Java.g:538:5: ( PUBLIC | PROTECTED | PRIVATE | STATIC | ABSTRACT | NATIVE | SYNCHRONIZED | TRANSIENT | VOLATILE | STRICTFP | localModifier )
			int alt54=11;
			switch ( input.LA(1) ) {
			case PUBLIC:
				{
				alt54=1;
				}
				break;
			case PROTECTED:
				{
				alt54=2;
				}
				break;
			case PRIVATE:
				{
				alt54=3;
				}
				break;
			case STATIC:
				{
				alt54=4;
				}
				break;
			case ABSTRACT:
				{
				alt54=5;
				}
				break;
			case NATIVE:
				{
				alt54=6;
				}
				break;
			case SYNCHRONIZED:
				{
				alt54=7;
				}
				break;
			case TRANSIENT:
				{
				alt54=8;
				}
				break;
			case VOLATILE:
				{
				alt54=9;
				}
				break;
			case STRICTFP:
				{
				alt54=10;
				}
				break;
			case AT:
			case FINAL:
				{
				alt54=11;
				}
				break;
			default:
				if (state.backtracking>0) {state.failed=true; return retval;}
				NoViableAltException nvae =
					new NoViableAltException("", 54, 0, input);
				throw nvae;
			}
			switch (alt54) {
				case 1 :
					// Java.g:538:9: PUBLIC
					{
					root_0 = (CommonTree)adaptor.nil();


					PUBLIC152=(Token)match(input,PUBLIC,FOLLOW_PUBLIC_in_modifier6779); if (state.failed) return retval;
					if ( state.backtracking==0 ) {
					PUBLIC152_tree = 
					(CommonTree)adaptor.create(PUBLIC152)
					;
					adaptor.addChild(root_0, PUBLIC152_tree);
					}

					}
					break;
				case 2 :
					// Java.g:539:9: PROTECTED
					{
					root_0 = (CommonTree)adaptor.nil();


					PROTECTED153=(Token)match(input,PROTECTED,FOLLOW_PROTECTED_in_modifier6789); if (state.failed) return retval;
					if ( state.backtracking==0 ) {
					PROTECTED153_tree = 
					(CommonTree)adaptor.create(PROTECTED153)
					;
					adaptor.addChild(root_0, PROTECTED153_tree);
					}

					}
					break;
				case 3 :
					// Java.g:540:9: PRIVATE
					{
					root_0 = (CommonTree)adaptor.nil();


					PRIVATE154=(Token)match(input,PRIVATE,FOLLOW_PRIVATE_in_modifier6799); if (state.failed) return retval;
					if ( state.backtracking==0 ) {
					PRIVATE154_tree = 
					(CommonTree)adaptor.create(PRIVATE154)
					;
					adaptor.addChild(root_0, PRIVATE154_tree);
					}

					}
					break;
				case 4 :
					// Java.g:541:9: STATIC
					{
					root_0 = (CommonTree)adaptor.nil();


					STATIC155=(Token)match(input,STATIC,FOLLOW_STATIC_in_modifier6809); if (state.failed) return retval;
					if ( state.backtracking==0 ) {
					STATIC155_tree = 
					(CommonTree)adaptor.create(STATIC155)
					;
					adaptor.addChild(root_0, STATIC155_tree);
					}

					}
					break;
				case 5 :
					// Java.g:542:9: ABSTRACT
					{
					root_0 = (CommonTree)adaptor.nil();


					ABSTRACT156=(Token)match(input,ABSTRACT,FOLLOW_ABSTRACT_in_modifier6819); if (state.failed) return retval;
					if ( state.backtracking==0 ) {
					ABSTRACT156_tree = 
					(CommonTree)adaptor.create(ABSTRACT156)
					;
					adaptor.addChild(root_0, ABSTRACT156_tree);
					}

					}
					break;
				case 6 :
					// Java.g:543:9: NATIVE
					{
					root_0 = (CommonTree)adaptor.nil();


					NATIVE157=(Token)match(input,NATIVE,FOLLOW_NATIVE_in_modifier6829); if (state.failed) return retval;
					if ( state.backtracking==0 ) {
					NATIVE157_tree = 
					(CommonTree)adaptor.create(NATIVE157)
					;
					adaptor.addChild(root_0, NATIVE157_tree);
					}

					}
					break;
				case 7 :
					// Java.g:544:9: SYNCHRONIZED
					{
					root_0 = (CommonTree)adaptor.nil();


					SYNCHRONIZED158=(Token)match(input,SYNCHRONIZED,FOLLOW_SYNCHRONIZED_in_modifier6839); if (state.failed) return retval;
					if ( state.backtracking==0 ) {
					SYNCHRONIZED158_tree = 
					(CommonTree)adaptor.create(SYNCHRONIZED158)
					;
					adaptor.addChild(root_0, SYNCHRONIZED158_tree);
					}

					}
					break;
				case 8 :
					// Java.g:545:9: TRANSIENT
					{
					root_0 = (CommonTree)adaptor.nil();


					TRANSIENT159=(Token)match(input,TRANSIENT,FOLLOW_TRANSIENT_in_modifier6849); if (state.failed) return retval;
					if ( state.backtracking==0 ) {
					TRANSIENT159_tree = 
					(CommonTree)adaptor.create(TRANSIENT159)
					;
					adaptor.addChild(root_0, TRANSIENT159_tree);
					}

					}
					break;
				case 9 :
					// Java.g:546:9: VOLATILE
					{
					root_0 = (CommonTree)adaptor.nil();


					VOLATILE160=(Token)match(input,VOLATILE,FOLLOW_VOLATILE_in_modifier6859); if (state.failed) return retval;
					if ( state.backtracking==0 ) {
					VOLATILE160_tree = 
					(CommonTree)adaptor.create(VOLATILE160)
					;
					adaptor.addChild(root_0, VOLATILE160_tree);
					}

					}
					break;
				case 10 :
					// Java.g:547:9: STRICTFP
					{
					root_0 = (CommonTree)adaptor.nil();


					STRICTFP161=(Token)match(input,STRICTFP,FOLLOW_STRICTFP_in_modifier6869); if (state.failed) return retval;
					if ( state.backtracking==0 ) {
					STRICTFP161_tree = 
					(CommonTree)adaptor.create(STRICTFP161)
					;
					adaptor.addChild(root_0, STRICTFP161_tree);
					}

					}
					break;
				case 11 :
					// Java.g:548:9: localModifier
					{
					root_0 = (CommonTree)adaptor.nil();


					pushFollow(FOLLOW_localModifier_in_modifier6879);
					localModifier162=localModifier();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) adaptor.addChild(root_0, localModifier162.getTree());

					}
					break;

			}
			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 38, modifier_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "modifier"


	public static class localModifierList_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "localModifierList"
	// Java.g:551:1: localModifierList : ( localModifier )* -> ^( LOCAL_MODIFIER_LIST ( localModifier )* ) ;
	public final JavaParser.localModifierList_return localModifierList() throws RecognitionException {
		JavaParser.localModifierList_return retval = new JavaParser.localModifierList_return();
		retval.start = input.LT(1);
		int localModifierList_StartIndex = input.index();

		CommonTree root_0 = null;

		ParserRuleReturnScope localModifier163 =null;

		RewriteRuleSubtreeStream stream_localModifier=new RewriteRuleSubtreeStream(adaptor,"rule localModifier");

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 39) ) { return retval; }

			// Java.g:552:5: ( ( localModifier )* -> ^( LOCAL_MODIFIER_LIST ( localModifier )* ) )
			// Java.g:552:9: ( localModifier )*
			{
			// Java.g:552:9: ( localModifier )*
			loop55:
			do {
				int alt55=2;
				int LA55_0 = input.LA(1);
				if ( (LA55_0==AT||LA55_0==FINAL) ) {
					alt55=1;
				}

				switch (alt55) {
				case 1 :
					// Java.g:552:9: localModifier
					{
					pushFollow(FOLLOW_localModifier_in_localModifierList6898);
					localModifier163=localModifier();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_localModifier.add(localModifier163.getTree());
					}
					break;

				default :
					break loop55;
				}
			} while (true);

			// AST REWRITE
			// elements: localModifier
			// token labels: 
			// rule labels: retval
			// token list labels: 
			// rule list labels: 
			// wildcard labels: 
			if ( state.backtracking==0 ) {

			retval.tree = root_0;
			RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

			root_0 = (CommonTree)adaptor.nil();
			// 553:9: -> ^( LOCAL_MODIFIER_LIST ( localModifier )* )
			{
				// Java.g:553:12: ^( LOCAL_MODIFIER_LIST ( localModifier )* )
				{
				CommonTree root_1 = (CommonTree)adaptor.nil();
				root_1 = (CommonTree)adaptor.becomeRoot(
				(CommonTree)adaptor.create(LOCAL_MODIFIER_LIST, "LOCAL_MODIFIER_LIST")
				, root_1);

				// Java.g:553:34: ( localModifier )*
				while ( stream_localModifier.hasNext() ) {
					adaptor.addChild(root_1, stream_localModifier.nextTree());

				}
				stream_localModifier.reset();

				adaptor.addChild(root_0, root_1);
				}

			}


			retval.tree = root_0;
			}

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 39, localModifierList_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "localModifierList"


	public static class localModifier_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "localModifier"
	// Java.g:556:1: localModifier : ( FINAL | annotation );
	public final JavaParser.localModifier_return localModifier() throws RecognitionException {
		JavaParser.localModifier_return retval = new JavaParser.localModifier_return();
		retval.start = input.LT(1);
		int localModifier_StartIndex = input.index();

		CommonTree root_0 = null;

		Token FINAL164=null;
		ParserRuleReturnScope annotation165 =null;

		CommonTree FINAL164_tree=null;

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 40) ) { return retval; }

			// Java.g:557:5: ( FINAL | annotation )
			int alt56=2;
			int LA56_0 = input.LA(1);
			if ( (LA56_0==FINAL) ) {
				alt56=1;
			}
			else if ( (LA56_0==AT) ) {
				alt56=2;
			}
			else {
				if (state.backtracking>0) {state.failed=true; return retval;}
				NoViableAltException nvae =
					new NoViableAltException("", 56, 0, input);
				throw nvae;
			}
			switch (alt56) {
				case 1 :
					// Java.g:557:9: FINAL
					{
					root_0 = (CommonTree)adaptor.nil();


					FINAL164=(Token)match(input,FINAL,FOLLOW_FINAL_in_localModifier6939); if (state.failed) return retval;
					if ( state.backtracking==0 ) {
					FINAL164_tree = 
					(CommonTree)adaptor.create(FINAL164)
					;
					adaptor.addChild(root_0, FINAL164_tree);
					}

					}
					break;
				case 2 :
					// Java.g:558:9: annotation
					{
					root_0 = (CommonTree)adaptor.nil();


					pushFollow(FOLLOW_annotation_in_localModifier6949);
					annotation165=annotation();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) adaptor.addChild(root_0, annotation165.getTree());

					}
					break;

			}
			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 40, localModifier_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "localModifier"


	public static class type_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "type"
	// Java.g:561:1: type : ( simpleType | objectType );
	public final JavaParser.type_return type() throws RecognitionException {
		JavaParser.type_return retval = new JavaParser.type_return();
		retval.start = input.LT(1);
		int type_StartIndex = input.index();

		CommonTree root_0 = null;

		ParserRuleReturnScope simpleType166 =null;
		ParserRuleReturnScope objectType167 =null;


		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 41) ) { return retval; }

			// Java.g:562:5: ( simpleType | objectType )
			int alt57=2;
			int LA57_0 = input.LA(1);
			if ( (LA57_0==BOOLEAN||LA57_0==BYTE||LA57_0==CHAR||LA57_0==DOUBLE||LA57_0==FLOAT||LA57_0==INT||LA57_0==LONG||LA57_0==SHORT) ) {
				alt57=1;
			}
			else if ( (LA57_0==IDENT) ) {
				alt57=2;
			}
			else {
				if (state.backtracking>0) {state.failed=true; return retval;}
				NoViableAltException nvae =
					new NoViableAltException("", 57, 0, input);
				throw nvae;
			}
			switch (alt57) {
				case 1 :
					// Java.g:562:9: simpleType
					{
					root_0 = (CommonTree)adaptor.nil();


					pushFollow(FOLLOW_simpleType_in_type6968);
					simpleType166=simpleType();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) adaptor.addChild(root_0, simpleType166.getTree());

					}
					break;
				case 2 :
					// Java.g:563:9: objectType
					{
					root_0 = (CommonTree)adaptor.nil();


					pushFollow(FOLLOW_objectType_in_type6978);
					objectType167=objectType();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) adaptor.addChild(root_0, objectType167.getTree());

					}
					break;

			}
			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 41, type_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "type"


	public static class simpleType_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "simpleType"
	// Java.g:566:1: simpleType : primitiveType ( arrayDeclaratorList )? -> ^( TYPE primitiveType ( arrayDeclaratorList )? ) ;
	public final JavaParser.simpleType_return simpleType() throws RecognitionException {
		JavaParser.simpleType_return retval = new JavaParser.simpleType_return();
		retval.start = input.LT(1);
		int simpleType_StartIndex = input.index();

		CommonTree root_0 = null;

		ParserRuleReturnScope primitiveType168 =null;
		ParserRuleReturnScope arrayDeclaratorList169 =null;

		RewriteRuleSubtreeStream stream_arrayDeclaratorList=new RewriteRuleSubtreeStream(adaptor,"rule arrayDeclaratorList");
		RewriteRuleSubtreeStream stream_primitiveType=new RewriteRuleSubtreeStream(adaptor,"rule primitiveType");

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 42) ) { return retval; }

			// Java.g:567:5: ( primitiveType ( arrayDeclaratorList )? -> ^( TYPE primitiveType ( arrayDeclaratorList )? ) )
			// Java.g:567:9: primitiveType ( arrayDeclaratorList )?
			{
			pushFollow(FOLLOW_primitiveType_in_simpleType6998);
			primitiveType168=primitiveType();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) stream_primitiveType.add(primitiveType168.getTree());
			// Java.g:567:23: ( arrayDeclaratorList )?
			int alt58=2;
			int LA58_0 = input.LA(1);
			if ( (LA58_0==LBRACK) ) {
				int LA58_1 = input.LA(2);
				if ( (LA58_1==RBRACK) ) {
					int LA58_3 = input.LA(3);
					if ( (synpred76_Java()) ) {
						alt58=1;
					}
				}
			}
			switch (alt58) {
				case 1 :
					// Java.g:567:23: arrayDeclaratorList
					{
					pushFollow(FOLLOW_arrayDeclaratorList_in_simpleType7000);
					arrayDeclaratorList169=arrayDeclaratorList();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_arrayDeclaratorList.add(arrayDeclaratorList169.getTree());
					}
					break;

			}

			// AST REWRITE
			// elements: arrayDeclaratorList, primitiveType
			// token labels: 
			// rule labels: retval
			// token list labels: 
			// rule list labels: 
			// wildcard labels: 
			if ( state.backtracking==0 ) {

			retval.tree = root_0;
			RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

			root_0 = (CommonTree)adaptor.nil();
			// 568:9: -> ^( TYPE primitiveType ( arrayDeclaratorList )? )
			{
				// Java.g:568:13: ^( TYPE primitiveType ( arrayDeclaratorList )? )
				{
				CommonTree root_1 = (CommonTree)adaptor.nil();
				root_1 = (CommonTree)adaptor.becomeRoot(
				(CommonTree)adaptor.create(TYPE, "TYPE")
				, root_1);

				adaptor.addChild(root_1, stream_primitiveType.nextTree());

				// Java.g:568:34: ( arrayDeclaratorList )?
				if ( stream_arrayDeclaratorList.hasNext() ) {
					adaptor.addChild(root_1, stream_arrayDeclaratorList.nextTree());

				}
				stream_arrayDeclaratorList.reset();

				adaptor.addChild(root_0, root_1);
				}

			}


			retval.tree = root_0;
			}

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 42, simpleType_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "simpleType"


	public static class objectType_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "objectType"
	// Java.g:571:1: objectType : qualifiedTypeIdent ( arrayDeclaratorList )? -> ^( TYPE qualifiedTypeIdent ( arrayDeclaratorList )? ) ;
	public final JavaParser.objectType_return objectType() throws RecognitionException {
		JavaParser.objectType_return retval = new JavaParser.objectType_return();
		retval.start = input.LT(1);
		int objectType_StartIndex = input.index();

		CommonTree root_0 = null;

		ParserRuleReturnScope qualifiedTypeIdent170 =null;
		ParserRuleReturnScope arrayDeclaratorList171 =null;

		RewriteRuleSubtreeStream stream_arrayDeclaratorList=new RewriteRuleSubtreeStream(adaptor,"rule arrayDeclaratorList");
		RewriteRuleSubtreeStream stream_qualifiedTypeIdent=new RewriteRuleSubtreeStream(adaptor,"rule qualifiedTypeIdent");

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 43) ) { return retval; }

			// Java.g:572:5: ( qualifiedTypeIdent ( arrayDeclaratorList )? -> ^( TYPE qualifiedTypeIdent ( arrayDeclaratorList )? ) )
			// Java.g:572:9: qualifiedTypeIdent ( arrayDeclaratorList )?
			{
			pushFollow(FOLLOW_qualifiedTypeIdent_in_objectType7047);
			qualifiedTypeIdent170=qualifiedTypeIdent();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) stream_qualifiedTypeIdent.add(qualifiedTypeIdent170.getTree());
			// Java.g:572:28: ( arrayDeclaratorList )?
			int alt59=2;
			int LA59_0 = input.LA(1);
			if ( (LA59_0==LBRACK) ) {
				int LA59_1 = input.LA(2);
				if ( (synpred77_Java()) ) {
					alt59=1;
				}
			}
			switch (alt59) {
				case 1 :
					// Java.g:572:28: arrayDeclaratorList
					{
					pushFollow(FOLLOW_arrayDeclaratorList_in_objectType7049);
					arrayDeclaratorList171=arrayDeclaratorList();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_arrayDeclaratorList.add(arrayDeclaratorList171.getTree());
					}
					break;

			}

			// AST REWRITE
			// elements: qualifiedTypeIdent, arrayDeclaratorList
			// token labels: 
			// rule labels: retval
			// token list labels: 
			// rule list labels: 
			// wildcard labels: 
			if ( state.backtracking==0 ) {

			retval.tree = root_0;
			RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

			root_0 = (CommonTree)adaptor.nil();
			// 573:9: -> ^( TYPE qualifiedTypeIdent ( arrayDeclaratorList )? )
			{
				// Java.g:573:13: ^( TYPE qualifiedTypeIdent ( arrayDeclaratorList )? )
				{
				CommonTree root_1 = (CommonTree)adaptor.nil();
				root_1 = (CommonTree)adaptor.becomeRoot(
				(CommonTree)adaptor.create(TYPE, "TYPE")
				, root_1);

				adaptor.addChild(root_1, stream_qualifiedTypeIdent.nextTree());

				// Java.g:573:39: ( arrayDeclaratorList )?
				if ( stream_arrayDeclaratorList.hasNext() ) {
					adaptor.addChild(root_1, stream_arrayDeclaratorList.nextTree());

				}
				stream_arrayDeclaratorList.reset();

				adaptor.addChild(root_0, root_1);
				}

			}


			retval.tree = root_0;
			}

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 43, objectType_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "objectType"


	public static class objectTypeSimplified_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "objectTypeSimplified"
	// Java.g:576:1: objectTypeSimplified : qualifiedTypeIdentSimplified ( arrayDeclaratorList )? -> ^( TYPE qualifiedTypeIdentSimplified ( arrayDeclaratorList )? ) ;
	public final JavaParser.objectTypeSimplified_return objectTypeSimplified() throws RecognitionException {
		JavaParser.objectTypeSimplified_return retval = new JavaParser.objectTypeSimplified_return();
		retval.start = input.LT(1);
		int objectTypeSimplified_StartIndex = input.index();

		CommonTree root_0 = null;

		ParserRuleReturnScope qualifiedTypeIdentSimplified172 =null;
		ParserRuleReturnScope arrayDeclaratorList173 =null;

		RewriteRuleSubtreeStream stream_arrayDeclaratorList=new RewriteRuleSubtreeStream(adaptor,"rule arrayDeclaratorList");
		RewriteRuleSubtreeStream stream_qualifiedTypeIdentSimplified=new RewriteRuleSubtreeStream(adaptor,"rule qualifiedTypeIdentSimplified");

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 44) ) { return retval; }

			// Java.g:577:5: ( qualifiedTypeIdentSimplified ( arrayDeclaratorList )? -> ^( TYPE qualifiedTypeIdentSimplified ( arrayDeclaratorList )? ) )
			// Java.g:577:9: qualifiedTypeIdentSimplified ( arrayDeclaratorList )?
			{
			pushFollow(FOLLOW_qualifiedTypeIdentSimplified_in_objectTypeSimplified7089);
			qualifiedTypeIdentSimplified172=qualifiedTypeIdentSimplified();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) stream_qualifiedTypeIdentSimplified.add(qualifiedTypeIdentSimplified172.getTree());
			// Java.g:577:38: ( arrayDeclaratorList )?
			int alt60=2;
			int LA60_0 = input.LA(1);
			if ( (LA60_0==LBRACK) ) {
				alt60=1;
			}
			switch (alt60) {
				case 1 :
					// Java.g:577:38: arrayDeclaratorList
					{
					pushFollow(FOLLOW_arrayDeclaratorList_in_objectTypeSimplified7091);
					arrayDeclaratorList173=arrayDeclaratorList();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_arrayDeclaratorList.add(arrayDeclaratorList173.getTree());
					}
					break;

			}

			// AST REWRITE
			// elements: arrayDeclaratorList, qualifiedTypeIdentSimplified
			// token labels: 
			// rule labels: retval
			// token list labels: 
			// rule list labels: 
			// wildcard labels: 
			if ( state.backtracking==0 ) {

			retval.tree = root_0;
			RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

			root_0 = (CommonTree)adaptor.nil();
			// 578:9: -> ^( TYPE qualifiedTypeIdentSimplified ( arrayDeclaratorList )? )
			{
				// Java.g:578:13: ^( TYPE qualifiedTypeIdentSimplified ( arrayDeclaratorList )? )
				{
				CommonTree root_1 = (CommonTree)adaptor.nil();
				root_1 = (CommonTree)adaptor.becomeRoot(
				(CommonTree)adaptor.create(TYPE, "TYPE")
				, root_1);

				adaptor.addChild(root_1, stream_qualifiedTypeIdentSimplified.nextTree());

				// Java.g:578:49: ( arrayDeclaratorList )?
				if ( stream_arrayDeclaratorList.hasNext() ) {
					adaptor.addChild(root_1, stream_arrayDeclaratorList.nextTree());

				}
				stream_arrayDeclaratorList.reset();

				adaptor.addChild(root_0, root_1);
				}

			}


			retval.tree = root_0;
			}

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 44, objectTypeSimplified_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "objectTypeSimplified"


	public static class qualifiedTypeIdent_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "qualifiedTypeIdent"
	// Java.g:581:1: qualifiedTypeIdent : typeIdent ( DOT typeIdent )* -> ^( QUALIFIED_TYPE_IDENT ( typeIdent )+ ) ;
	public final JavaParser.qualifiedTypeIdent_return qualifiedTypeIdent() throws RecognitionException {
		JavaParser.qualifiedTypeIdent_return retval = new JavaParser.qualifiedTypeIdent_return();
		retval.start = input.LT(1);
		int qualifiedTypeIdent_StartIndex = input.index();

		CommonTree root_0 = null;

		Token DOT175=null;
		ParserRuleReturnScope typeIdent174 =null;
		ParserRuleReturnScope typeIdent176 =null;

		CommonTree DOT175_tree=null;
		RewriteRuleTokenStream stream_DOT=new RewriteRuleTokenStream(adaptor,"token DOT");
		RewriteRuleSubtreeStream stream_typeIdent=new RewriteRuleSubtreeStream(adaptor,"rule typeIdent");

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 45) ) { return retval; }

			// Java.g:582:5: ( typeIdent ( DOT typeIdent )* -> ^( QUALIFIED_TYPE_IDENT ( typeIdent )+ ) )
			// Java.g:582:9: typeIdent ( DOT typeIdent )*
			{
			pushFollow(FOLLOW_typeIdent_in_qualifiedTypeIdent7131);
			typeIdent174=typeIdent();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) stream_typeIdent.add(typeIdent174.getTree());
			// Java.g:582:19: ( DOT typeIdent )*
			loop61:
			do {
				int alt61=2;
				int LA61_0 = input.LA(1);
				if ( (LA61_0==DOT) ) {
					int LA61_2 = input.LA(2);
					if ( (synpred79_Java()) ) {
						alt61=1;
					}

				}

				switch (alt61) {
				case 1 :
					// Java.g:582:20: DOT typeIdent
					{
					DOT175=(Token)match(input,DOT,FOLLOW_DOT_in_qualifiedTypeIdent7134); if (state.failed) return retval; 
					if ( state.backtracking==0 ) stream_DOT.add(DOT175);

					pushFollow(FOLLOW_typeIdent_in_qualifiedTypeIdent7136);
					typeIdent176=typeIdent();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_typeIdent.add(typeIdent176.getTree());
					}
					break;

				default :
					break loop61;
				}
			} while (true);

			// AST REWRITE
			// elements: typeIdent
			// token labels: 
			// rule labels: retval
			// token list labels: 
			// rule list labels: 
			// wildcard labels: 
			if ( state.backtracking==0 ) {

			retval.tree = root_0;
			RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

			root_0 = (CommonTree)adaptor.nil();
			// 583:9: -> ^( QUALIFIED_TYPE_IDENT ( typeIdent )+ )
			{
				// Java.g:583:13: ^( QUALIFIED_TYPE_IDENT ( typeIdent )+ )
				{
				CommonTree root_1 = (CommonTree)adaptor.nil();
				root_1 = (CommonTree)adaptor.becomeRoot(
				(CommonTree)adaptor.create(QUALIFIED_TYPE_IDENT, "QUALIFIED_TYPE_IDENT")
				, root_1);

				if ( !(stream_typeIdent.hasNext()) ) {
					throw new RewriteEarlyExitException();
				}
				while ( stream_typeIdent.hasNext() ) {
					adaptor.addChild(root_1, stream_typeIdent.nextTree());

				}
				stream_typeIdent.reset();

				adaptor.addChild(root_0, root_1);
				}

			}


			retval.tree = root_0;
			}

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 45, qualifiedTypeIdent_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "qualifiedTypeIdent"


	public static class qualifiedTypeIdentSimplified_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "qualifiedTypeIdentSimplified"
	// Java.g:586:1: qualifiedTypeIdentSimplified : typeIdentSimplified ( DOT typeIdentSimplified )* -> ^( QUALIFIED_TYPE_IDENT ( typeIdentSimplified )+ ) ;
	public final JavaParser.qualifiedTypeIdentSimplified_return qualifiedTypeIdentSimplified() throws RecognitionException {
		JavaParser.qualifiedTypeIdentSimplified_return retval = new JavaParser.qualifiedTypeIdentSimplified_return();
		retval.start = input.LT(1);
		int qualifiedTypeIdentSimplified_StartIndex = input.index();

		CommonTree root_0 = null;

		Token DOT178=null;
		ParserRuleReturnScope typeIdentSimplified177 =null;
		ParserRuleReturnScope typeIdentSimplified179 =null;

		CommonTree DOT178_tree=null;
		RewriteRuleTokenStream stream_DOT=new RewriteRuleTokenStream(adaptor,"token DOT");
		RewriteRuleSubtreeStream stream_typeIdentSimplified=new RewriteRuleSubtreeStream(adaptor,"rule typeIdentSimplified");

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 46) ) { return retval; }

			// Java.g:587:5: ( typeIdentSimplified ( DOT typeIdentSimplified )* -> ^( QUALIFIED_TYPE_IDENT ( typeIdentSimplified )+ ) )
			// Java.g:587:9: typeIdentSimplified ( DOT typeIdentSimplified )*
			{
			pushFollow(FOLLOW_typeIdentSimplified_in_qualifiedTypeIdentSimplified7176);
			typeIdentSimplified177=typeIdentSimplified();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) stream_typeIdentSimplified.add(typeIdentSimplified177.getTree());
			// Java.g:587:29: ( DOT typeIdentSimplified )*
			loop62:
			do {
				int alt62=2;
				int LA62_0 = input.LA(1);
				if ( (LA62_0==DOT) ) {
					alt62=1;
				}

				switch (alt62) {
				case 1 :
					// Java.g:587:30: DOT typeIdentSimplified
					{
					DOT178=(Token)match(input,DOT,FOLLOW_DOT_in_qualifiedTypeIdentSimplified7179); if (state.failed) return retval; 
					if ( state.backtracking==0 ) stream_DOT.add(DOT178);

					pushFollow(FOLLOW_typeIdentSimplified_in_qualifiedTypeIdentSimplified7181);
					typeIdentSimplified179=typeIdentSimplified();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_typeIdentSimplified.add(typeIdentSimplified179.getTree());
					}
					break;

				default :
					break loop62;
				}
			} while (true);

			// AST REWRITE
			// elements: typeIdentSimplified
			// token labels: 
			// rule labels: retval
			// token list labels: 
			// rule list labels: 
			// wildcard labels: 
			if ( state.backtracking==0 ) {

			retval.tree = root_0;
			RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

			root_0 = (CommonTree)adaptor.nil();
			// 588:9: -> ^( QUALIFIED_TYPE_IDENT ( typeIdentSimplified )+ )
			{
				// Java.g:588:13: ^( QUALIFIED_TYPE_IDENT ( typeIdentSimplified )+ )
				{
				CommonTree root_1 = (CommonTree)adaptor.nil();
				root_1 = (CommonTree)adaptor.becomeRoot(
				(CommonTree)adaptor.create(QUALIFIED_TYPE_IDENT, "QUALIFIED_TYPE_IDENT")
				, root_1);

				if ( !(stream_typeIdentSimplified.hasNext()) ) {
					throw new RewriteEarlyExitException();
				}
				while ( stream_typeIdentSimplified.hasNext() ) {
					adaptor.addChild(root_1, stream_typeIdentSimplified.nextTree());

				}
				stream_typeIdentSimplified.reset();

				adaptor.addChild(root_0, root_1);
				}

			}


			retval.tree = root_0;
			}

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 46, qualifiedTypeIdentSimplified_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "qualifiedTypeIdentSimplified"


	public static class typeIdent_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "typeIdent"
	// Java.g:591:1: typeIdent : IDENT ^ ( genericTypeArgumentList )? ;
	public final JavaParser.typeIdent_return typeIdent() throws RecognitionException {
		JavaParser.typeIdent_return retval = new JavaParser.typeIdent_return();
		retval.start = input.LT(1);
		int typeIdent_StartIndex = input.index();

		CommonTree root_0 = null;

		Token IDENT180=null;
		ParserRuleReturnScope genericTypeArgumentList181 =null;

		CommonTree IDENT180_tree=null;

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 47) ) { return retval; }

			// Java.g:592:5: ( IDENT ^ ( genericTypeArgumentList )? )
			// Java.g:592:9: IDENT ^ ( genericTypeArgumentList )?
			{
			root_0 = (CommonTree)adaptor.nil();


			IDENT180=(Token)match(input,IDENT,FOLLOW_IDENT_in_typeIdent7221); if (state.failed) return retval;
			if ( state.backtracking==0 ) {
			IDENT180_tree = 
			(CommonTree)adaptor.create(IDENT180)
			;
			root_0 = (CommonTree)adaptor.becomeRoot(IDENT180_tree, root_0);
			}

			// Java.g:592:16: ( genericTypeArgumentList )?
			int alt63=2;
			int LA63_0 = input.LA(1);
			if ( (LA63_0==LESS_THAN) ) {
				alt63=1;
			}
			switch (alt63) {
				case 1 :
					// Java.g:592:16: genericTypeArgumentList
					{
					pushFollow(FOLLOW_genericTypeArgumentList_in_typeIdent7224);
					genericTypeArgumentList181=genericTypeArgumentList();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) adaptor.addChild(root_0, genericTypeArgumentList181.getTree());

					}
					break;

			}

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 47, typeIdent_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "typeIdent"


	public static class typeIdentSimplified_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "typeIdentSimplified"
	// Java.g:595:1: typeIdentSimplified : IDENT ^ ( genericTypeArgumentListSimplified )? ;
	public final JavaParser.typeIdentSimplified_return typeIdentSimplified() throws RecognitionException {
		JavaParser.typeIdentSimplified_return retval = new JavaParser.typeIdentSimplified_return();
		retval.start = input.LT(1);
		int typeIdentSimplified_StartIndex = input.index();

		CommonTree root_0 = null;

		Token IDENT182=null;
		ParserRuleReturnScope genericTypeArgumentListSimplified183 =null;

		CommonTree IDENT182_tree=null;

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 48) ) { return retval; }

			// Java.g:596:5: ( IDENT ^ ( genericTypeArgumentListSimplified )? )
			// Java.g:596:9: IDENT ^ ( genericTypeArgumentListSimplified )?
			{
			root_0 = (CommonTree)adaptor.nil();


			IDENT182=(Token)match(input,IDENT,FOLLOW_IDENT_in_typeIdentSimplified7244); if (state.failed) return retval;
			if ( state.backtracking==0 ) {
			IDENT182_tree = 
			(CommonTree)adaptor.create(IDENT182)
			;
			root_0 = (CommonTree)adaptor.becomeRoot(IDENT182_tree, root_0);
			}

			// Java.g:596:16: ( genericTypeArgumentListSimplified )?
			int alt64=2;
			int LA64_0 = input.LA(1);
			if ( (LA64_0==LESS_THAN) ) {
				alt64=1;
			}
			switch (alt64) {
				case 1 :
					// Java.g:596:16: genericTypeArgumentListSimplified
					{
					pushFollow(FOLLOW_genericTypeArgumentListSimplified_in_typeIdentSimplified7247);
					genericTypeArgumentListSimplified183=genericTypeArgumentListSimplified();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) adaptor.addChild(root_0, genericTypeArgumentListSimplified183.getTree());

					}
					break;

			}

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 48, typeIdentSimplified_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "typeIdentSimplified"


	public static class primitiveType_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "primitiveType"
	// Java.g:599:1: primitiveType : ( BOOLEAN | CHAR | BYTE | SHORT | INT | LONG | FLOAT | DOUBLE );
	public final JavaParser.primitiveType_return primitiveType() throws RecognitionException {
		JavaParser.primitiveType_return retval = new JavaParser.primitiveType_return();
		retval.start = input.LT(1);
		int primitiveType_StartIndex = input.index();

		CommonTree root_0 = null;

		Token set184=null;

		CommonTree set184_tree=null;

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 49) ) { return retval; }

			// Java.g:600:5: ( BOOLEAN | CHAR | BYTE | SHORT | INT | LONG | FLOAT | DOUBLE )
			// Java.g:
			{
			root_0 = (CommonTree)adaptor.nil();


			set184=(Token)input.LT(1);
			if ( input.LA(1)==BOOLEAN||input.LA(1)==BYTE||input.LA(1)==CHAR||input.LA(1)==DOUBLE||input.LA(1)==FLOAT||input.LA(1)==INT||input.LA(1)==LONG||input.LA(1)==SHORT ) {
				input.consume();
				if ( state.backtracking==0 ) adaptor.addChild(root_0, 
				(CommonTree)adaptor.create(set184)
				);
				state.errorRecovery=false;
				state.failed=false;
			}
			else {
				if (state.backtracking>0) {state.failed=true; return retval;}
				MismatchedSetException mse = new MismatchedSetException(null,input);
				throw mse;
			}
			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 49, primitiveType_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "primitiveType"


	public static class genericTypeArgumentList_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "genericTypeArgumentList"
	// Java.g:610:1: genericTypeArgumentList : LESS_THAN genericTypeArgument ( COMMA genericTypeArgument )* genericTypeListClosing -> ^( GENERIC_TYPE_ARG_LIST[$LESS_THAN, \"GENERIC_TYPE_ARG_LIST\"] ( genericTypeArgument )+ ) ;
	public final JavaParser.genericTypeArgumentList_return genericTypeArgumentList() throws RecognitionException {
		JavaParser.genericTypeArgumentList_return retval = new JavaParser.genericTypeArgumentList_return();
		retval.start = input.LT(1);
		int genericTypeArgumentList_StartIndex = input.index();

		CommonTree root_0 = null;

		Token LESS_THAN185=null;
		Token COMMA187=null;
		ParserRuleReturnScope genericTypeArgument186 =null;
		ParserRuleReturnScope genericTypeArgument188 =null;
		ParserRuleReturnScope genericTypeListClosing189 =null;

		CommonTree LESS_THAN185_tree=null;
		CommonTree COMMA187_tree=null;
		RewriteRuleTokenStream stream_COMMA=new RewriteRuleTokenStream(adaptor,"token COMMA");
		RewriteRuleTokenStream stream_LESS_THAN=new RewriteRuleTokenStream(adaptor,"token LESS_THAN");
		RewriteRuleSubtreeStream stream_genericTypeArgument=new RewriteRuleSubtreeStream(adaptor,"rule genericTypeArgument");
		RewriteRuleSubtreeStream stream_genericTypeListClosing=new RewriteRuleSubtreeStream(adaptor,"rule genericTypeListClosing");

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 50) ) { return retval; }

			// Java.g:611:5: ( LESS_THAN genericTypeArgument ( COMMA genericTypeArgument )* genericTypeListClosing -> ^( GENERIC_TYPE_ARG_LIST[$LESS_THAN, \"GENERIC_TYPE_ARG_LIST\"] ( genericTypeArgument )+ ) )
			// Java.g:611:9: LESS_THAN genericTypeArgument ( COMMA genericTypeArgument )* genericTypeListClosing
			{
			LESS_THAN185=(Token)match(input,LESS_THAN,FOLLOW_LESS_THAN_in_genericTypeArgumentList7356); if (state.failed) return retval; 
			if ( state.backtracking==0 ) stream_LESS_THAN.add(LESS_THAN185);

			pushFollow(FOLLOW_genericTypeArgument_in_genericTypeArgumentList7358);
			genericTypeArgument186=genericTypeArgument();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) stream_genericTypeArgument.add(genericTypeArgument186.getTree());
			// Java.g:611:39: ( COMMA genericTypeArgument )*
			loop65:
			do {
				int alt65=2;
				int LA65_0 = input.LA(1);
				if ( (LA65_0==COMMA) ) {
					int LA65_2 = input.LA(2);
					if ( (synpred90_Java()) ) {
						alt65=1;
					}

				}

				switch (alt65) {
				case 1 :
					// Java.g:611:40: COMMA genericTypeArgument
					{
					COMMA187=(Token)match(input,COMMA,FOLLOW_COMMA_in_genericTypeArgumentList7361); if (state.failed) return retval; 
					if ( state.backtracking==0 ) stream_COMMA.add(COMMA187);

					pushFollow(FOLLOW_genericTypeArgument_in_genericTypeArgumentList7363);
					genericTypeArgument188=genericTypeArgument();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_genericTypeArgument.add(genericTypeArgument188.getTree());
					}
					break;

				default :
					break loop65;
				}
			} while (true);

			pushFollow(FOLLOW_genericTypeListClosing_in_genericTypeArgumentList7367);
			genericTypeListClosing189=genericTypeListClosing();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) stream_genericTypeListClosing.add(genericTypeListClosing189.getTree());
			// AST REWRITE
			// elements: genericTypeArgument
			// token labels: 
			// rule labels: retval
			// token list labels: 
			// rule list labels: 
			// wildcard labels: 
			if ( state.backtracking==0 ) {

			retval.tree = root_0;
			RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

			root_0 = (CommonTree)adaptor.nil();
			// 612:9: -> ^( GENERIC_TYPE_ARG_LIST[$LESS_THAN, \"GENERIC_TYPE_ARG_LIST\"] ( genericTypeArgument )+ )
			{
				// Java.g:612:13: ^( GENERIC_TYPE_ARG_LIST[$LESS_THAN, \"GENERIC_TYPE_ARG_LIST\"] ( genericTypeArgument )+ )
				{
				CommonTree root_1 = (CommonTree)adaptor.nil();
				root_1 = (CommonTree)adaptor.becomeRoot(
				(CommonTree)adaptor.create(GENERIC_TYPE_ARG_LIST, LESS_THAN185, "GENERIC_TYPE_ARG_LIST")
				, root_1);

				if ( !(stream_genericTypeArgument.hasNext()) ) {
					throw new RewriteEarlyExitException();
				}
				while ( stream_genericTypeArgument.hasNext() ) {
					adaptor.addChild(root_1, stream_genericTypeArgument.nextTree());

				}
				stream_genericTypeArgument.reset();

				adaptor.addChild(root_0, root_1);
				}

			}


			retval.tree = root_0;
			}

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 50, genericTypeArgumentList_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "genericTypeArgumentList"


	public static class genericTypeArgument_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "genericTypeArgument"
	// Java.g:615:1: genericTypeArgument : ( type | QUESTION ( genericWildcardBoundType )? -> ^( QUESTION ( genericWildcardBoundType )? ) );
	public final JavaParser.genericTypeArgument_return genericTypeArgument() throws RecognitionException {
		JavaParser.genericTypeArgument_return retval = new JavaParser.genericTypeArgument_return();
		retval.start = input.LT(1);
		int genericTypeArgument_StartIndex = input.index();

		CommonTree root_0 = null;

		Token QUESTION191=null;
		ParserRuleReturnScope type190 =null;
		ParserRuleReturnScope genericWildcardBoundType192 =null;

		CommonTree QUESTION191_tree=null;
		RewriteRuleTokenStream stream_QUESTION=new RewriteRuleTokenStream(adaptor,"token QUESTION");
		RewriteRuleSubtreeStream stream_genericWildcardBoundType=new RewriteRuleSubtreeStream(adaptor,"rule genericWildcardBoundType");

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 51) ) { return retval; }

			// Java.g:616:5: ( type | QUESTION ( genericWildcardBoundType )? -> ^( QUESTION ( genericWildcardBoundType )? ) )
			int alt67=2;
			int LA67_0 = input.LA(1);
			if ( (LA67_0==BOOLEAN||LA67_0==BYTE||LA67_0==CHAR||LA67_0==DOUBLE||LA67_0==FLOAT||LA67_0==IDENT||LA67_0==INT||LA67_0==LONG||LA67_0==SHORT) ) {
				alt67=1;
			}
			else if ( (LA67_0==QUESTION) ) {
				alt67=2;
			}
			else {
				if (state.backtracking>0) {state.failed=true; return retval;}
				NoViableAltException nvae =
					new NoViableAltException("", 67, 0, input);
				throw nvae;
			}
			switch (alt67) {
				case 1 :
					// Java.g:616:9: type
					{
					root_0 = (CommonTree)adaptor.nil();


					pushFollow(FOLLOW_type_in_genericTypeArgument7405);
					type190=type();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) adaptor.addChild(root_0, type190.getTree());

					}
					break;
				case 2 :
					// Java.g:617:9: QUESTION ( genericWildcardBoundType )?
					{
					QUESTION191=(Token)match(input,QUESTION,FOLLOW_QUESTION_in_genericTypeArgument7415); if (state.failed) return retval; 
					if ( state.backtracking==0 ) stream_QUESTION.add(QUESTION191);

					// Java.g:617:18: ( genericWildcardBoundType )?
					int alt66=2;
					int LA66_0 = input.LA(1);
					if ( (LA66_0==EXTENDS) ) {
						int LA66_1 = input.LA(2);
						if ( (LA66_1==BOOLEAN||LA66_1==BYTE||LA66_1==CHAR||LA66_1==DOUBLE||LA66_1==FLOAT||LA66_1==INT||LA66_1==LONG||LA66_1==SHORT) ) {
							int LA66_4 = input.LA(3);
							if ( (synpred92_Java()) ) {
								alt66=1;
							}
						}
						else if ( (LA66_1==IDENT) ) {
							int LA66_5 = input.LA(3);
							if ( (synpred92_Java()) ) {
								alt66=1;
							}
						}
					}
					else if ( (LA66_0==SUPER) ) {
						int LA66_3 = input.LA(2);
						if ( (LA66_3==BOOLEAN||LA66_3==BYTE||LA66_3==CHAR||LA66_3==DOUBLE||LA66_3==FLOAT||LA66_3==IDENT||LA66_3==INT||LA66_3==LONG||LA66_3==SHORT) ) {
							alt66=1;
						}
					}
					switch (alt66) {
						case 1 :
							// Java.g:617:18: genericWildcardBoundType
							{
							pushFollow(FOLLOW_genericWildcardBoundType_in_genericTypeArgument7417);
							genericWildcardBoundType192=genericWildcardBoundType();
							state._fsp--;
							if (state.failed) return retval;
							if ( state.backtracking==0 ) stream_genericWildcardBoundType.add(genericWildcardBoundType192.getTree());
							}
							break;

					}

					// AST REWRITE
					// elements: genericWildcardBoundType, QUESTION
					// token labels: 
					// rule labels: retval
					// token list labels: 
					// rule list labels: 
					// wildcard labels: 
					if ( state.backtracking==0 ) {

					retval.tree = root_0;
					RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

					root_0 = (CommonTree)adaptor.nil();
					// 618:9: -> ^( QUESTION ( genericWildcardBoundType )? )
					{
						// Java.g:618:13: ^( QUESTION ( genericWildcardBoundType )? )
						{
						CommonTree root_1 = (CommonTree)adaptor.nil();
						root_1 = (CommonTree)adaptor.becomeRoot(
						stream_QUESTION.nextNode()
						, root_1);

						// Java.g:618:24: ( genericWildcardBoundType )?
						if ( stream_genericWildcardBoundType.hasNext() ) {
							adaptor.addChild(root_1, stream_genericWildcardBoundType.nextTree());

						}
						stream_genericWildcardBoundType.reset();

						adaptor.addChild(root_0, root_1);
						}

					}


					retval.tree = root_0;
					}

					}
					break;

			}
			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 51, genericTypeArgument_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "genericTypeArgument"


	public static class genericWildcardBoundType_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "genericWildcardBoundType"
	// Java.g:621:1: genericWildcardBoundType : ( EXTENDS | SUPER ) ^ type ;
	public final JavaParser.genericWildcardBoundType_return genericWildcardBoundType() throws RecognitionException {
		JavaParser.genericWildcardBoundType_return retval = new JavaParser.genericWildcardBoundType_return();
		retval.start = input.LT(1);
		int genericWildcardBoundType_StartIndex = input.index();

		CommonTree root_0 = null;

		Token set193=null;
		ParserRuleReturnScope type194 =null;

		CommonTree set193_tree=null;

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 52) ) { return retval; }

			// Java.g:622:5: ( ( EXTENDS | SUPER ) ^ type )
			// Java.g:622:9: ( EXTENDS | SUPER ) ^ type
			{
			root_0 = (CommonTree)adaptor.nil();


			set193=(Token)input.LT(1);
			set193=(Token)input.LT(1);
			if ( input.LA(1)==EXTENDS||input.LA(1)==SUPER ) {
				input.consume();
				if ( state.backtracking==0 ) root_0 = (CommonTree)adaptor.becomeRoot(
				(CommonTree)adaptor.create(set193)
				, root_0);
				state.errorRecovery=false;
				state.failed=false;
			}
			else {
				if (state.backtracking>0) {state.failed=true; return retval;}
				MismatchedSetException mse = new MismatchedSetException(null,input);
				throw mse;
			}
			pushFollow(FOLLOW_type_in_genericWildcardBoundType7468);
			type194=type();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) adaptor.addChild(root_0, type194.getTree());

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 52, genericWildcardBoundType_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "genericWildcardBoundType"


	public static class genericTypeArgumentListSimplified_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "genericTypeArgumentListSimplified"
	// Java.g:625:1: genericTypeArgumentListSimplified : LESS_THAN genericTypeArgumentSimplified ( COMMA genericTypeArgumentSimplified )* genericTypeListClosing -> ^( GENERIC_TYPE_ARG_LIST[$LESS_THAN, \"GENERIC_TYPE_ARG_LIST\"] ( genericTypeArgumentSimplified )+ ) ;
	public final JavaParser.genericTypeArgumentListSimplified_return genericTypeArgumentListSimplified() throws RecognitionException {
		JavaParser.genericTypeArgumentListSimplified_return retval = new JavaParser.genericTypeArgumentListSimplified_return();
		retval.start = input.LT(1);
		int genericTypeArgumentListSimplified_StartIndex = input.index();

		CommonTree root_0 = null;

		Token LESS_THAN195=null;
		Token COMMA197=null;
		ParserRuleReturnScope genericTypeArgumentSimplified196 =null;
		ParserRuleReturnScope genericTypeArgumentSimplified198 =null;
		ParserRuleReturnScope genericTypeListClosing199 =null;

		CommonTree LESS_THAN195_tree=null;
		CommonTree COMMA197_tree=null;
		RewriteRuleTokenStream stream_COMMA=new RewriteRuleTokenStream(adaptor,"token COMMA");
		RewriteRuleTokenStream stream_LESS_THAN=new RewriteRuleTokenStream(adaptor,"token LESS_THAN");
		RewriteRuleSubtreeStream stream_genericTypeArgumentSimplified=new RewriteRuleSubtreeStream(adaptor,"rule genericTypeArgumentSimplified");
		RewriteRuleSubtreeStream stream_genericTypeListClosing=new RewriteRuleSubtreeStream(adaptor,"rule genericTypeListClosing");

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 53) ) { return retval; }

			// Java.g:626:5: ( LESS_THAN genericTypeArgumentSimplified ( COMMA genericTypeArgumentSimplified )* genericTypeListClosing -> ^( GENERIC_TYPE_ARG_LIST[$LESS_THAN, \"GENERIC_TYPE_ARG_LIST\"] ( genericTypeArgumentSimplified )+ ) )
			// Java.g:626:9: LESS_THAN genericTypeArgumentSimplified ( COMMA genericTypeArgumentSimplified )* genericTypeListClosing
			{
			LESS_THAN195=(Token)match(input,LESS_THAN,FOLLOW_LESS_THAN_in_genericTypeArgumentListSimplified7487); if (state.failed) return retval; 
			if ( state.backtracking==0 ) stream_LESS_THAN.add(LESS_THAN195);

			pushFollow(FOLLOW_genericTypeArgumentSimplified_in_genericTypeArgumentListSimplified7489);
			genericTypeArgumentSimplified196=genericTypeArgumentSimplified();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) stream_genericTypeArgumentSimplified.add(genericTypeArgumentSimplified196.getTree());
			// Java.g:626:49: ( COMMA genericTypeArgumentSimplified )*
			loop68:
			do {
				int alt68=2;
				int LA68_0 = input.LA(1);
				if ( (LA68_0==COMMA) ) {
					alt68=1;
				}

				switch (alt68) {
				case 1 :
					// Java.g:626:50: COMMA genericTypeArgumentSimplified
					{
					COMMA197=(Token)match(input,COMMA,FOLLOW_COMMA_in_genericTypeArgumentListSimplified7492); if (state.failed) return retval; 
					if ( state.backtracking==0 ) stream_COMMA.add(COMMA197);

					pushFollow(FOLLOW_genericTypeArgumentSimplified_in_genericTypeArgumentListSimplified7494);
					genericTypeArgumentSimplified198=genericTypeArgumentSimplified();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_genericTypeArgumentSimplified.add(genericTypeArgumentSimplified198.getTree());
					}
					break;

				default :
					break loop68;
				}
			} while (true);

			pushFollow(FOLLOW_genericTypeListClosing_in_genericTypeArgumentListSimplified7498);
			genericTypeListClosing199=genericTypeListClosing();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) stream_genericTypeListClosing.add(genericTypeListClosing199.getTree());
			// AST REWRITE
			// elements: genericTypeArgumentSimplified
			// token labels: 
			// rule labels: retval
			// token list labels: 
			// rule list labels: 
			// wildcard labels: 
			if ( state.backtracking==0 ) {

			retval.tree = root_0;
			RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

			root_0 = (CommonTree)adaptor.nil();
			// 627:9: -> ^( GENERIC_TYPE_ARG_LIST[$LESS_THAN, \"GENERIC_TYPE_ARG_LIST\"] ( genericTypeArgumentSimplified )+ )
			{
				// Java.g:627:13: ^( GENERIC_TYPE_ARG_LIST[$LESS_THAN, \"GENERIC_TYPE_ARG_LIST\"] ( genericTypeArgumentSimplified )+ )
				{
				CommonTree root_1 = (CommonTree)adaptor.nil();
				root_1 = (CommonTree)adaptor.becomeRoot(
				(CommonTree)adaptor.create(GENERIC_TYPE_ARG_LIST, LESS_THAN195, "GENERIC_TYPE_ARG_LIST")
				, root_1);

				if ( !(stream_genericTypeArgumentSimplified.hasNext()) ) {
					throw new RewriteEarlyExitException();
				}
				while ( stream_genericTypeArgumentSimplified.hasNext() ) {
					adaptor.addChild(root_1, stream_genericTypeArgumentSimplified.nextTree());

				}
				stream_genericTypeArgumentSimplified.reset();

				adaptor.addChild(root_0, root_1);
				}

			}


			retval.tree = root_0;
			}

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 53, genericTypeArgumentListSimplified_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "genericTypeArgumentListSimplified"


	public static class genericTypeArgumentSimplified_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "genericTypeArgumentSimplified"
	// Java.g:630:1: genericTypeArgumentSimplified : ( type | QUESTION );
	public final JavaParser.genericTypeArgumentSimplified_return genericTypeArgumentSimplified() throws RecognitionException {
		JavaParser.genericTypeArgumentSimplified_return retval = new JavaParser.genericTypeArgumentSimplified_return();
		retval.start = input.LT(1);
		int genericTypeArgumentSimplified_StartIndex = input.index();

		CommonTree root_0 = null;

		Token QUESTION201=null;
		ParserRuleReturnScope type200 =null;

		CommonTree QUESTION201_tree=null;

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 54) ) { return retval; }

			// Java.g:631:5: ( type | QUESTION )
			int alt69=2;
			int LA69_0 = input.LA(1);
			if ( (LA69_0==BOOLEAN||LA69_0==BYTE||LA69_0==CHAR||LA69_0==DOUBLE||LA69_0==FLOAT||LA69_0==IDENT||LA69_0==INT||LA69_0==LONG||LA69_0==SHORT) ) {
				alt69=1;
			}
			else if ( (LA69_0==QUESTION) ) {
				alt69=2;
			}
			else {
				if (state.backtracking>0) {state.failed=true; return retval;}
				NoViableAltException nvae =
					new NoViableAltException("", 69, 0, input);
				throw nvae;
			}
			switch (alt69) {
				case 1 :
					// Java.g:631:9: type
					{
					root_0 = (CommonTree)adaptor.nil();


					pushFollow(FOLLOW_type_in_genericTypeArgumentSimplified7540);
					type200=type();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) adaptor.addChild(root_0, type200.getTree());

					}
					break;
				case 2 :
					// Java.g:632:9: QUESTION
					{
					root_0 = (CommonTree)adaptor.nil();


					QUESTION201=(Token)match(input,QUESTION,FOLLOW_QUESTION_in_genericTypeArgumentSimplified7550); if (state.failed) return retval;
					if ( state.backtracking==0 ) {
					QUESTION201_tree = 
					(CommonTree)adaptor.create(QUESTION201)
					;
					adaptor.addChild(root_0, QUESTION201_tree);
					}

					}
					break;

			}
			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 54, genericTypeArgumentSimplified_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "genericTypeArgumentSimplified"


	public static class qualifiedIdentList_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "qualifiedIdentList"
	// Java.g:635:1: qualifiedIdentList : qualifiedIdentifier ( COMMA ! qualifiedIdentifier )* ;
	public final JavaParser.qualifiedIdentList_return qualifiedIdentList() throws RecognitionException {
		JavaParser.qualifiedIdentList_return retval = new JavaParser.qualifiedIdentList_return();
		retval.start = input.LT(1);
		int qualifiedIdentList_StartIndex = input.index();

		CommonTree root_0 = null;

		Token COMMA203=null;
		ParserRuleReturnScope qualifiedIdentifier202 =null;
		ParserRuleReturnScope qualifiedIdentifier204 =null;

		CommonTree COMMA203_tree=null;

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 55) ) { return retval; }

			// Java.g:636:5: ( qualifiedIdentifier ( COMMA ! qualifiedIdentifier )* )
			// Java.g:636:9: qualifiedIdentifier ( COMMA ! qualifiedIdentifier )*
			{
			root_0 = (CommonTree)adaptor.nil();


			pushFollow(FOLLOW_qualifiedIdentifier_in_qualifiedIdentList7573);
			qualifiedIdentifier202=qualifiedIdentifier();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) adaptor.addChild(root_0, qualifiedIdentifier202.getTree());

			// Java.g:636:29: ( COMMA ! qualifiedIdentifier )*
			loop70:
			do {
				int alt70=2;
				int LA70_0 = input.LA(1);
				if ( (LA70_0==COMMA) ) {
					alt70=1;
				}

				switch (alt70) {
				case 1 :
					// Java.g:636:30: COMMA ! qualifiedIdentifier
					{
					COMMA203=(Token)match(input,COMMA,FOLLOW_COMMA_in_qualifiedIdentList7576); if (state.failed) return retval;
					pushFollow(FOLLOW_qualifiedIdentifier_in_qualifiedIdentList7579);
					qualifiedIdentifier204=qualifiedIdentifier();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) adaptor.addChild(root_0, qualifiedIdentifier204.getTree());

					}
					break;

				default :
					break loop70;
				}
			} while (true);

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 55, qualifiedIdentList_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "qualifiedIdentList"


	public static class formalParameterList_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "formalParameterList"
	// Java.g:639:1: formalParameterList : LPAREN ( formalParameterStandardDecl ( COMMA formalParameterStandardDecl )* ( COMMA formalParameterVarArgDecl )? -> ^( FORMAL_PARAM_LIST[$LPAREN, \"FORMAL_PARAM_LIST\"] ( formalParameterStandardDecl )+ ( formalParameterVarArgDecl )? ) | formalParameterVarArgDecl -> ^( FORMAL_PARAM_LIST[$LPAREN, \"FORMAL_PARAM_LIST\"] formalParameterVarArgDecl ) | -> ^( FORMAL_PARAM_LIST[$LPAREN, \"FORMAL_PARAM_LIST\"] ) ) RPAREN ;
	public final JavaParser.formalParameterList_return formalParameterList() throws RecognitionException {
		JavaParser.formalParameterList_return retval = new JavaParser.formalParameterList_return();
		retval.start = input.LT(1);
		int formalParameterList_StartIndex = input.index();

		CommonTree root_0 = null;

		Token LPAREN205=null;
		Token COMMA207=null;
		Token COMMA209=null;
		Token RPAREN212=null;
		ParserRuleReturnScope formalParameterStandardDecl206 =null;
		ParserRuleReturnScope formalParameterStandardDecl208 =null;
		ParserRuleReturnScope formalParameterVarArgDecl210 =null;
		ParserRuleReturnScope formalParameterVarArgDecl211 =null;

		CommonTree LPAREN205_tree=null;
		CommonTree COMMA207_tree=null;
		CommonTree COMMA209_tree=null;
		CommonTree RPAREN212_tree=null;
		RewriteRuleTokenStream stream_RPAREN=new RewriteRuleTokenStream(adaptor,"token RPAREN");
		RewriteRuleTokenStream stream_COMMA=new RewriteRuleTokenStream(adaptor,"token COMMA");
		RewriteRuleTokenStream stream_LPAREN=new RewriteRuleTokenStream(adaptor,"token LPAREN");
		RewriteRuleSubtreeStream stream_formalParameterVarArgDecl=new RewriteRuleSubtreeStream(adaptor,"rule formalParameterVarArgDecl");
		RewriteRuleSubtreeStream stream_formalParameterStandardDecl=new RewriteRuleSubtreeStream(adaptor,"rule formalParameterStandardDecl");

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 56) ) { return retval; }

			// Java.g:640:5: ( LPAREN ( formalParameterStandardDecl ( COMMA formalParameterStandardDecl )* ( COMMA formalParameterVarArgDecl )? -> ^( FORMAL_PARAM_LIST[$LPAREN, \"FORMAL_PARAM_LIST\"] ( formalParameterStandardDecl )+ ( formalParameterVarArgDecl )? ) | formalParameterVarArgDecl -> ^( FORMAL_PARAM_LIST[$LPAREN, \"FORMAL_PARAM_LIST\"] formalParameterVarArgDecl ) | -> ^( FORMAL_PARAM_LIST[$LPAREN, \"FORMAL_PARAM_LIST\"] ) ) RPAREN )
			// Java.g:640:9: LPAREN ( formalParameterStandardDecl ( COMMA formalParameterStandardDecl )* ( COMMA formalParameterVarArgDecl )? -> ^( FORMAL_PARAM_LIST[$LPAREN, \"FORMAL_PARAM_LIST\"] ( formalParameterStandardDecl )+ ( formalParameterVarArgDecl )? ) | formalParameterVarArgDecl -> ^( FORMAL_PARAM_LIST[$LPAREN, \"FORMAL_PARAM_LIST\"] formalParameterVarArgDecl ) | -> ^( FORMAL_PARAM_LIST[$LPAREN, \"FORMAL_PARAM_LIST\"] ) ) RPAREN
			{
			LPAREN205=(Token)match(input,LPAREN,FOLLOW_LPAREN_in_formalParameterList7604); if (state.failed) return retval; 
			if ( state.backtracking==0 ) stream_LPAREN.add(LPAREN205);

			// Java.g:641:9: ( formalParameterStandardDecl ( COMMA formalParameterStandardDecl )* ( COMMA formalParameterVarArgDecl )? -> ^( FORMAL_PARAM_LIST[$LPAREN, \"FORMAL_PARAM_LIST\"] ( formalParameterStandardDecl )+ ( formalParameterVarArgDecl )? ) | formalParameterVarArgDecl -> ^( FORMAL_PARAM_LIST[$LPAREN, \"FORMAL_PARAM_LIST\"] formalParameterVarArgDecl ) | -> ^( FORMAL_PARAM_LIST[$LPAREN, \"FORMAL_PARAM_LIST\"] ) )
			int alt73=3;
			switch ( input.LA(1) ) {
			case FINAL:
				{
				int LA73_1 = input.LA(2);
				if ( (synpred99_Java()) ) {
					alt73=1;
				}
				else if ( (synpred100_Java()) ) {
					alt73=2;
				}
				else {
					if (state.backtracking>0) {state.failed=true; return retval;}
					int nvaeMark = input.mark();
					try {
						input.consume();
						NoViableAltException nvae =
							new NoViableAltException("", 73, 1, input);
						throw nvae;
					} finally {
						input.rewind(nvaeMark);
					}
				}
				}
				break;
			case AT:
				{
				int LA73_2 = input.LA(2);
				if ( (synpred99_Java()) ) {
					alt73=1;
				}
				else if ( (synpred100_Java()) ) {
					alt73=2;
				}
				else {
					if (state.backtracking>0) {state.failed=true; return retval;}
					int nvaeMark = input.mark();
					try {
						input.consume();
						NoViableAltException nvae =
							new NoViableAltException("", 73, 2, input);
						throw nvae;
					} finally {
						input.rewind(nvaeMark);
					}
				}
				}
				break;
			case BOOLEAN:
			case BYTE:
			case CHAR:
			case DOUBLE:
			case FLOAT:
			case INT:
			case LONG:
			case SHORT:
				{
				int LA73_3 = input.LA(2);
				if ( (synpred99_Java()) ) {
					alt73=1;
				}
				else if ( (synpred100_Java()) ) {
					alt73=2;
				}
				else {
					if (state.backtracking>0) {state.failed=true; return retval;}
					int nvaeMark = input.mark();
					try {
						input.consume();
						NoViableAltException nvae =
							new NoViableAltException("", 73, 3, input);
						throw nvae;
					} finally {
						input.rewind(nvaeMark);
					}
				}
				}
				break;
			case IDENT:
				{
				int LA73_4 = input.LA(2);
				if ( (synpred99_Java()) ) {
					alt73=1;
				}
				else if ( (synpred100_Java()) ) {
					alt73=2;
				}
				else {
					if (state.backtracking>0) {state.failed=true; return retval;}
					int nvaeMark = input.mark();
					try {
						input.consume();
						NoViableAltException nvae =
							new NoViableAltException("", 73, 4, input);
						throw nvae;
					} finally {
						input.rewind(nvaeMark);
					}
				}
				}
				break;
			case RPAREN:
				{
				alt73=3;
				}
				break;
			default:
				if (state.backtracking>0) {state.failed=true; return retval;}
				NoViableAltException nvae =
					new NoViableAltException("", 73, 0, input);
				throw nvae;
			}
			switch (alt73) {
				case 1 :
					// Java.g:642:13: formalParameterStandardDecl ( COMMA formalParameterStandardDecl )* ( COMMA formalParameterVarArgDecl )?
					{
					pushFollow(FOLLOW_formalParameterStandardDecl_in_formalParameterList7632);
					formalParameterStandardDecl206=formalParameterStandardDecl();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_formalParameterStandardDecl.add(formalParameterStandardDecl206.getTree());
					// Java.g:642:41: ( COMMA formalParameterStandardDecl )*
					loop71:
					do {
						int alt71=2;
						int LA71_0 = input.LA(1);
						if ( (LA71_0==COMMA) ) {
							int LA71_1 = input.LA(2);
							if ( (synpred97_Java()) ) {
								alt71=1;
							}

						}

						switch (alt71) {
						case 1 :
							// Java.g:642:42: COMMA formalParameterStandardDecl
							{
							COMMA207=(Token)match(input,COMMA,FOLLOW_COMMA_in_formalParameterList7635); if (state.failed) return retval; 
							if ( state.backtracking==0 ) stream_COMMA.add(COMMA207);

							pushFollow(FOLLOW_formalParameterStandardDecl_in_formalParameterList7637);
							formalParameterStandardDecl208=formalParameterStandardDecl();
							state._fsp--;
							if (state.failed) return retval;
							if ( state.backtracking==0 ) stream_formalParameterStandardDecl.add(formalParameterStandardDecl208.getTree());
							}
							break;

						default :
							break loop71;
						}
					} while (true);

					// Java.g:642:78: ( COMMA formalParameterVarArgDecl )?
					int alt72=2;
					int LA72_0 = input.LA(1);
					if ( (LA72_0==COMMA) ) {
						alt72=1;
					}
					switch (alt72) {
						case 1 :
							// Java.g:642:79: COMMA formalParameterVarArgDecl
							{
							COMMA209=(Token)match(input,COMMA,FOLLOW_COMMA_in_formalParameterList7642); if (state.failed) return retval; 
							if ( state.backtracking==0 ) stream_COMMA.add(COMMA209);

							pushFollow(FOLLOW_formalParameterVarArgDecl_in_formalParameterList7644);
							formalParameterVarArgDecl210=formalParameterVarArgDecl();
							state._fsp--;
							if (state.failed) return retval;
							if ( state.backtracking==0 ) stream_formalParameterVarArgDecl.add(formalParameterVarArgDecl210.getTree());
							}
							break;

					}

					// AST REWRITE
					// elements: formalParameterStandardDecl, formalParameterVarArgDecl
					// token labels: 
					// rule labels: retval
					// token list labels: 
					// rule list labels: 
					// wildcard labels: 
					if ( state.backtracking==0 ) {

					retval.tree = root_0;
					RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

					root_0 = (CommonTree)adaptor.nil();
					// 643:13: -> ^( FORMAL_PARAM_LIST[$LPAREN, \"FORMAL_PARAM_LIST\"] ( formalParameterStandardDecl )+ ( formalParameterVarArgDecl )? )
					{
						// Java.g:643:17: ^( FORMAL_PARAM_LIST[$LPAREN, \"FORMAL_PARAM_LIST\"] ( formalParameterStandardDecl )+ ( formalParameterVarArgDecl )? )
						{
						CommonTree root_1 = (CommonTree)adaptor.nil();
						root_1 = (CommonTree)adaptor.becomeRoot(
						(CommonTree)adaptor.create(FORMAL_PARAM_LIST, LPAREN205, "FORMAL_PARAM_LIST")
						, root_1);

						if ( !(stream_formalParameterStandardDecl.hasNext()) ) {
							throw new RewriteEarlyExitException();
						}
						while ( stream_formalParameterStandardDecl.hasNext() ) {
							adaptor.addChild(root_1, stream_formalParameterStandardDecl.nextTree());

						}
						stream_formalParameterStandardDecl.reset();

						// Java.g:643:96: ( formalParameterVarArgDecl )?
						if ( stream_formalParameterVarArgDecl.hasNext() ) {
							adaptor.addChild(root_1, stream_formalParameterVarArgDecl.nextTree());

						}
						stream_formalParameterVarArgDecl.reset();

						adaptor.addChild(root_0, root_1);
						}

					}


					retval.tree = root_0;
					}

					}
					break;
				case 2 :
					// Java.g:645:13: formalParameterVarArgDecl
					{
					pushFollow(FOLLOW_formalParameterVarArgDecl_in_formalParameterList7701);
					formalParameterVarArgDecl211=formalParameterVarArgDecl();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_formalParameterVarArgDecl.add(formalParameterVarArgDecl211.getTree());
					// AST REWRITE
					// elements: formalParameterVarArgDecl
					// token labels: 
					// rule labels: retval
					// token list labels: 
					// rule list labels: 
					// wildcard labels: 
					if ( state.backtracking==0 ) {

					retval.tree = root_0;
					RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

					root_0 = (CommonTree)adaptor.nil();
					// 646:13: -> ^( FORMAL_PARAM_LIST[$LPAREN, \"FORMAL_PARAM_LIST\"] formalParameterVarArgDecl )
					{
						// Java.g:646:17: ^( FORMAL_PARAM_LIST[$LPAREN, \"FORMAL_PARAM_LIST\"] formalParameterVarArgDecl )
						{
						CommonTree root_1 = (CommonTree)adaptor.nil();
						root_1 = (CommonTree)adaptor.becomeRoot(
						(CommonTree)adaptor.create(FORMAL_PARAM_LIST, LPAREN205, "FORMAL_PARAM_LIST")
						, root_1);

						adaptor.addChild(root_1, stream_formalParameterVarArgDecl.nextTree());

						adaptor.addChild(root_0, root_1);
						}

					}


					retval.tree = root_0;
					}

					}
					break;
				case 3 :
					// Java.g:648:13: 
					{
					// AST REWRITE
					// elements: 
					// token labels: 
					// rule labels: retval
					// token list labels: 
					// rule list labels: 
					// wildcard labels: 
					if ( state.backtracking==0 ) {

					retval.tree = root_0;
					RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

					root_0 = (CommonTree)adaptor.nil();
					// 648:13: -> ^( FORMAL_PARAM_LIST[$LPAREN, \"FORMAL_PARAM_LIST\"] )
					{
						// Java.g:648:17: ^( FORMAL_PARAM_LIST[$LPAREN, \"FORMAL_PARAM_LIST\"] )
						{
						CommonTree root_1 = (CommonTree)adaptor.nil();
						root_1 = (CommonTree)adaptor.becomeRoot(
						(CommonTree)adaptor.create(FORMAL_PARAM_LIST, LPAREN205, "FORMAL_PARAM_LIST")
						, root_1);

						adaptor.addChild(root_0, root_1);
						}

					}


					retval.tree = root_0;
					}

					}
					break;

			}

			RPAREN212=(Token)match(input,RPAREN,FOLLOW_RPAREN_in_formalParameterList7778); if (state.failed) return retval; 
			if ( state.backtracking==0 ) stream_RPAREN.add(RPAREN212);

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 56, formalParameterList_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "formalParameterList"


	public static class formalParameterStandardDecl_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "formalParameterStandardDecl"
	// Java.g:653:1: formalParameterStandardDecl : localModifierList type variableDeclaratorId -> ^( FORMAL_PARAM_STD_DECL localModifierList type variableDeclaratorId ) ;
	public final JavaParser.formalParameterStandardDecl_return formalParameterStandardDecl() throws RecognitionException {
		JavaParser.formalParameterStandardDecl_return retval = new JavaParser.formalParameterStandardDecl_return();
		retval.start = input.LT(1);
		int formalParameterStandardDecl_StartIndex = input.index();

		CommonTree root_0 = null;

		ParserRuleReturnScope localModifierList213 =null;
		ParserRuleReturnScope type214 =null;
		ParserRuleReturnScope variableDeclaratorId215 =null;

		RewriteRuleSubtreeStream stream_variableDeclaratorId=new RewriteRuleSubtreeStream(adaptor,"rule variableDeclaratorId");
		RewriteRuleSubtreeStream stream_localModifierList=new RewriteRuleSubtreeStream(adaptor,"rule localModifierList");
		RewriteRuleSubtreeStream stream_type=new RewriteRuleSubtreeStream(adaptor,"rule type");

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 57) ) { return retval; }

			// Java.g:654:5: ( localModifierList type variableDeclaratorId -> ^( FORMAL_PARAM_STD_DECL localModifierList type variableDeclaratorId ) )
			// Java.g:654:9: localModifierList type variableDeclaratorId
			{
			pushFollow(FOLLOW_localModifierList_in_formalParameterStandardDecl7801);
			localModifierList213=localModifierList();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) stream_localModifierList.add(localModifierList213.getTree());
			pushFollow(FOLLOW_type_in_formalParameterStandardDecl7803);
			type214=type();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) stream_type.add(type214.getTree());
			pushFollow(FOLLOW_variableDeclaratorId_in_formalParameterStandardDecl7805);
			variableDeclaratorId215=variableDeclaratorId();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) stream_variableDeclaratorId.add(variableDeclaratorId215.getTree());
			// AST REWRITE
			// elements: localModifierList, variableDeclaratorId, type
			// token labels: 
			// rule labels: retval
			// token list labels: 
			// rule list labels: 
			// wildcard labels: 
			if ( state.backtracking==0 ) {

			retval.tree = root_0;
			RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

			root_0 = (CommonTree)adaptor.nil();
			// 655:9: -> ^( FORMAL_PARAM_STD_DECL localModifierList type variableDeclaratorId )
			{
				// Java.g:655:13: ^( FORMAL_PARAM_STD_DECL localModifierList type variableDeclaratorId )
				{
				CommonTree root_1 = (CommonTree)adaptor.nil();
				root_1 = (CommonTree)adaptor.becomeRoot(
				(CommonTree)adaptor.create(FORMAL_PARAM_STD_DECL, "FORMAL_PARAM_STD_DECL")
				, root_1);

				adaptor.addChild(root_1, stream_localModifierList.nextTree());

				adaptor.addChild(root_1, stream_type.nextTree());

				adaptor.addChild(root_1, stream_variableDeclaratorId.nextTree());

				adaptor.addChild(root_0, root_1);
				}

			}


			retval.tree = root_0;
			}

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 57, formalParameterStandardDecl_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "formalParameterStandardDecl"


	public static class formalParameterVarArgDecl_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "formalParameterVarArgDecl"
	// Java.g:658:1: formalParameterVarArgDecl : localModifierList type ELLIPSIS variableDeclaratorId -> ^( FORMAL_PARAM_VARARG_DECL localModifierList type variableDeclaratorId ) ;
	public final JavaParser.formalParameterVarArgDecl_return formalParameterVarArgDecl() throws RecognitionException {
		JavaParser.formalParameterVarArgDecl_return retval = new JavaParser.formalParameterVarArgDecl_return();
		retval.start = input.LT(1);
		int formalParameterVarArgDecl_StartIndex = input.index();

		CommonTree root_0 = null;

		Token ELLIPSIS218=null;
		ParserRuleReturnScope localModifierList216 =null;
		ParserRuleReturnScope type217 =null;
		ParserRuleReturnScope variableDeclaratorId219 =null;

		CommonTree ELLIPSIS218_tree=null;
		RewriteRuleTokenStream stream_ELLIPSIS=new RewriteRuleTokenStream(adaptor,"token ELLIPSIS");
		RewriteRuleSubtreeStream stream_variableDeclaratorId=new RewriteRuleSubtreeStream(adaptor,"rule variableDeclaratorId");
		RewriteRuleSubtreeStream stream_localModifierList=new RewriteRuleSubtreeStream(adaptor,"rule localModifierList");
		RewriteRuleSubtreeStream stream_type=new RewriteRuleSubtreeStream(adaptor,"rule type");

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 58) ) { return retval; }

			// Java.g:659:5: ( localModifierList type ELLIPSIS variableDeclaratorId -> ^( FORMAL_PARAM_VARARG_DECL localModifierList type variableDeclaratorId ) )
			// Java.g:659:9: localModifierList type ELLIPSIS variableDeclaratorId
			{
			pushFollow(FOLLOW_localModifierList_in_formalParameterVarArgDecl7849);
			localModifierList216=localModifierList();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) stream_localModifierList.add(localModifierList216.getTree());
			pushFollow(FOLLOW_type_in_formalParameterVarArgDecl7851);
			type217=type();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) stream_type.add(type217.getTree());
			ELLIPSIS218=(Token)match(input,ELLIPSIS,FOLLOW_ELLIPSIS_in_formalParameterVarArgDecl7853); if (state.failed) return retval; 
			if ( state.backtracking==0 ) stream_ELLIPSIS.add(ELLIPSIS218);

			pushFollow(FOLLOW_variableDeclaratorId_in_formalParameterVarArgDecl7855);
			variableDeclaratorId219=variableDeclaratorId();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) stream_variableDeclaratorId.add(variableDeclaratorId219.getTree());
			// AST REWRITE
			// elements: localModifierList, type, variableDeclaratorId
			// token labels: 
			// rule labels: retval
			// token list labels: 
			// rule list labels: 
			// wildcard labels: 
			if ( state.backtracking==0 ) {

			retval.tree = root_0;
			RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

			root_0 = (CommonTree)adaptor.nil();
			// 660:9: -> ^( FORMAL_PARAM_VARARG_DECL localModifierList type variableDeclaratorId )
			{
				// Java.g:660:13: ^( FORMAL_PARAM_VARARG_DECL localModifierList type variableDeclaratorId )
				{
				CommonTree root_1 = (CommonTree)adaptor.nil();
				root_1 = (CommonTree)adaptor.becomeRoot(
				(CommonTree)adaptor.create(FORMAL_PARAM_VARARG_DECL, "FORMAL_PARAM_VARARG_DECL")
				, root_1);

				adaptor.addChild(root_1, stream_localModifierList.nextTree());

				adaptor.addChild(root_1, stream_type.nextTree());

				adaptor.addChild(root_1, stream_variableDeclaratorId.nextTree());

				adaptor.addChild(root_0, root_1);
				}

			}


			retval.tree = root_0;
			}

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 58, formalParameterVarArgDecl_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "formalParameterVarArgDecl"


	public static class qualifiedIdentifier_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "qualifiedIdentifier"
	// Java.g:663:1: qualifiedIdentifier : ( IDENT -> IDENT ) ( DOT ident= IDENT -> ^( DOT $qualifiedIdentifier $ident) )* ;
	public final JavaParser.qualifiedIdentifier_return qualifiedIdentifier() throws RecognitionException {
		JavaParser.qualifiedIdentifier_return retval = new JavaParser.qualifiedIdentifier_return();
		retval.start = input.LT(1);
		int qualifiedIdentifier_StartIndex = input.index();

		CommonTree root_0 = null;

		Token ident=null;
		Token IDENT220=null;
		Token DOT221=null;

		CommonTree ident_tree=null;
		CommonTree IDENT220_tree=null;
		CommonTree DOT221_tree=null;
		RewriteRuleTokenStream stream_IDENT=new RewriteRuleTokenStream(adaptor,"token IDENT");
		RewriteRuleTokenStream stream_DOT=new RewriteRuleTokenStream(adaptor,"token DOT");

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 59) ) { return retval; }

			// Java.g:664:5: ( ( IDENT -> IDENT ) ( DOT ident= IDENT -> ^( DOT $qualifiedIdentifier $ident) )* )
			// Java.g:664:9: ( IDENT -> IDENT ) ( DOT ident= IDENT -> ^( DOT $qualifiedIdentifier $ident) )*
			{
			// Java.g:664:9: ( IDENT -> IDENT )
			// Java.g:664:13: IDENT
			{
			IDENT220=(Token)match(input,IDENT,FOLLOW_IDENT_in_qualifiedIdentifier7903); if (state.failed) return retval; 
			if ( state.backtracking==0 ) stream_IDENT.add(IDENT220);

			// AST REWRITE
			// elements: IDENT
			// token labels: 
			// rule labels: retval
			// token list labels: 
			// rule list labels: 
			// wildcard labels: 
			if ( state.backtracking==0 ) {

			retval.tree = root_0;
			RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

			root_0 = (CommonTree)adaptor.nil();
			// 664:33: -> IDENT
			{
				adaptor.addChild(root_0, 
				stream_IDENT.nextNode()
				);

			}


			retval.tree = root_0;
			}

			}

			// Java.g:666:9: ( DOT ident= IDENT -> ^( DOT $qualifiedIdentifier $ident) )*
			loop74:
			do {
				int alt74=2;
				int LA74_0 = input.LA(1);
				if ( (LA74_0==DOT) ) {
					int LA74_2 = input.LA(2);
					if ( (LA74_2==IDENT) ) {
						int LA74_3 = input.LA(3);
						if ( (synpred101_Java()) ) {
							alt74=1;
						}

					}

				}

				switch (alt74) {
				case 1 :
					// Java.g:666:13: DOT ident= IDENT
					{
					DOT221=(Token)match(input,DOT,FOLLOW_DOT_in_qualifiedIdentifier7946); if (state.failed) return retval; 
					if ( state.backtracking==0 ) stream_DOT.add(DOT221);

					ident=(Token)match(input,IDENT,FOLLOW_IDENT_in_qualifiedIdentifier7950); if (state.failed) return retval; 
					if ( state.backtracking==0 ) stream_IDENT.add(ident);

					// AST REWRITE
					// elements: DOT, ident, qualifiedIdentifier
					// token labels: ident
					// rule labels: retval
					// token list labels: 
					// rule list labels: 
					// wildcard labels: 
					if ( state.backtracking==0 ) {

					retval.tree = root_0;
					RewriteRuleTokenStream stream_ident=new RewriteRuleTokenStream(adaptor,"token ident",ident);
					RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

					root_0 = (CommonTree)adaptor.nil();
					// 666:33: -> ^( DOT $qualifiedIdentifier $ident)
					{
						// Java.g:666:37: ^( DOT $qualifiedIdentifier $ident)
						{
						CommonTree root_1 = (CommonTree)adaptor.nil();
						root_1 = (CommonTree)adaptor.becomeRoot(
						stream_DOT.nextNode()
						, root_1);

						adaptor.addChild(root_1, stream_retval.nextTree());

						adaptor.addChild(root_1, stream_ident.nextNode());

						adaptor.addChild(root_0, root_1);
						}

					}


					retval.tree = root_0;
					}

					}
					break;

				default :
					break loop74;
				}
			} while (true);

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 59, qualifiedIdentifier_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "qualifiedIdentifier"


	public static class annotationList_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "annotationList"
	// Java.g:672:1: annotationList : ( annotation )* -> ^( ANNOTATION_LIST ( annotation )* ) ;
	public final JavaParser.annotationList_return annotationList() throws RecognitionException {
		JavaParser.annotationList_return retval = new JavaParser.annotationList_return();
		retval.start = input.LT(1);
		int annotationList_StartIndex = input.index();

		CommonTree root_0 = null;

		ParserRuleReturnScope annotation222 =null;

		RewriteRuleSubtreeStream stream_annotation=new RewriteRuleSubtreeStream(adaptor,"rule annotation");

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 60) ) { return retval; }

			// Java.g:673:5: ( ( annotation )* -> ^( ANNOTATION_LIST ( annotation )* ) )
			// Java.g:673:9: ( annotation )*
			{
			// Java.g:673:9: ( annotation )*
			loop75:
			do {
				int alt75=2;
				int LA75_0 = input.LA(1);
				if ( (LA75_0==AT) ) {
					int LA75_2 = input.LA(2);
					if ( (LA75_2==IDENT) ) {
						int LA75_3 = input.LA(3);
						if ( (synpred102_Java()) ) {
							alt75=1;
						}

					}

				}

				switch (alt75) {
				case 1 :
					// Java.g:673:9: annotation
					{
					pushFollow(FOLLOW_annotation_in_annotationList8003);
					annotation222=annotation();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_annotation.add(annotation222.getTree());
					}
					break;

				default :
					break loop75;
				}
			} while (true);

			// AST REWRITE
			// elements: annotation
			// token labels: 
			// rule labels: retval
			// token list labels: 
			// rule list labels: 
			// wildcard labels: 
			if ( state.backtracking==0 ) {

			retval.tree = root_0;
			RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

			root_0 = (CommonTree)adaptor.nil();
			// 674:9: -> ^( ANNOTATION_LIST ( annotation )* )
			{
				// Java.g:674:13: ^( ANNOTATION_LIST ( annotation )* )
				{
				CommonTree root_1 = (CommonTree)adaptor.nil();
				root_1 = (CommonTree)adaptor.becomeRoot(
				(CommonTree)adaptor.create(ANNOTATION_LIST, "ANNOTATION_LIST")
				, root_1);

				// Java.g:674:31: ( annotation )*
				while ( stream_annotation.hasNext() ) {
					adaptor.addChild(root_1, stream_annotation.nextTree());

				}
				stream_annotation.reset();

				adaptor.addChild(root_0, root_1);
				}

			}


			retval.tree = root_0;
			}

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 60, annotationList_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "annotationList"


	public static class annotation_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "annotation"
	// Java.g:677:1: annotation : AT ^ qualifiedIdentifier ( annotationInit )? ;
	public final JavaParser.annotation_return annotation() throws RecognitionException {
		JavaParser.annotation_return retval = new JavaParser.annotation_return();
		retval.start = input.LT(1);
		int annotation_StartIndex = input.index();

		CommonTree root_0 = null;

		Token AT223=null;
		ParserRuleReturnScope qualifiedIdentifier224 =null;
		ParserRuleReturnScope annotationInit225 =null;

		CommonTree AT223_tree=null;

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 61) ) { return retval; }

			// Java.g:678:5: ( AT ^ qualifiedIdentifier ( annotationInit )? )
			// Java.g:678:9: AT ^ qualifiedIdentifier ( annotationInit )?
			{
			root_0 = (CommonTree)adaptor.nil();


			AT223=(Token)match(input,AT,FOLLOW_AT_in_annotation8041); if (state.failed) return retval;
			if ( state.backtracking==0 ) {
			AT223_tree = 
			(CommonTree)adaptor.create(AT223)
			;
			root_0 = (CommonTree)adaptor.becomeRoot(AT223_tree, root_0);
			}

			pushFollow(FOLLOW_qualifiedIdentifier_in_annotation8044);
			qualifiedIdentifier224=qualifiedIdentifier();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) adaptor.addChild(root_0, qualifiedIdentifier224.getTree());

			// Java.g:678:33: ( annotationInit )?
			int alt76=2;
			int LA76_0 = input.LA(1);
			if ( (LA76_0==LPAREN) ) {
				alt76=1;
			}
			switch (alt76) {
				case 1 :
					// Java.g:678:33: annotationInit
					{
					pushFollow(FOLLOW_annotationInit_in_annotation8046);
					annotationInit225=annotationInit();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) adaptor.addChild(root_0, annotationInit225.getTree());

					}
					break;

			}

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 61, annotation_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "annotation"


	public static class annotationInit_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "annotationInit"
	// Java.g:681:1: annotationInit : LPAREN annotationInitializers RPAREN -> ^( ANNOTATION_INIT_BLOCK[$LPAREN, \"ANNOTATION_INIT_BLOCK\"] annotationInitializers ) ;
	public final JavaParser.annotationInit_return annotationInit() throws RecognitionException {
		JavaParser.annotationInit_return retval = new JavaParser.annotationInit_return();
		retval.start = input.LT(1);
		int annotationInit_StartIndex = input.index();

		CommonTree root_0 = null;

		Token LPAREN226=null;
		Token RPAREN228=null;
		ParserRuleReturnScope annotationInitializers227 =null;

		CommonTree LPAREN226_tree=null;
		CommonTree RPAREN228_tree=null;
		RewriteRuleTokenStream stream_RPAREN=new RewriteRuleTokenStream(adaptor,"token RPAREN");
		RewriteRuleTokenStream stream_LPAREN=new RewriteRuleTokenStream(adaptor,"token LPAREN");
		RewriteRuleSubtreeStream stream_annotationInitializers=new RewriteRuleSubtreeStream(adaptor,"rule annotationInitializers");

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 62) ) { return retval; }

			// Java.g:682:5: ( LPAREN annotationInitializers RPAREN -> ^( ANNOTATION_INIT_BLOCK[$LPAREN, \"ANNOTATION_INIT_BLOCK\"] annotationInitializers ) )
			// Java.g:682:9: LPAREN annotationInitializers RPAREN
			{
			LPAREN226=(Token)match(input,LPAREN,FOLLOW_LPAREN_in_annotationInit8070); if (state.failed) return retval; 
			if ( state.backtracking==0 ) stream_LPAREN.add(LPAREN226);

			pushFollow(FOLLOW_annotationInitializers_in_annotationInit8072);
			annotationInitializers227=annotationInitializers();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) stream_annotationInitializers.add(annotationInitializers227.getTree());
			RPAREN228=(Token)match(input,RPAREN,FOLLOW_RPAREN_in_annotationInit8074); if (state.failed) return retval; 
			if ( state.backtracking==0 ) stream_RPAREN.add(RPAREN228);

			// AST REWRITE
			// elements: annotationInitializers
			// token labels: 
			// rule labels: retval
			// token list labels: 
			// rule list labels: 
			// wildcard labels: 
			if ( state.backtracking==0 ) {

			retval.tree = root_0;
			RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

			root_0 = (CommonTree)adaptor.nil();
			// 683:9: -> ^( ANNOTATION_INIT_BLOCK[$LPAREN, \"ANNOTATION_INIT_BLOCK\"] annotationInitializers )
			{
				// Java.g:683:13: ^( ANNOTATION_INIT_BLOCK[$LPAREN, \"ANNOTATION_INIT_BLOCK\"] annotationInitializers )
				{
				CommonTree root_1 = (CommonTree)adaptor.nil();
				root_1 = (CommonTree)adaptor.becomeRoot(
				(CommonTree)adaptor.create(ANNOTATION_INIT_BLOCK, LPAREN226, "ANNOTATION_INIT_BLOCK")
				, root_1);

				adaptor.addChild(root_1, stream_annotationInitializers.nextTree());

				adaptor.addChild(root_0, root_1);
				}

			}


			retval.tree = root_0;
			}

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 62, annotationInit_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "annotationInit"


	public static class annotationInitializers_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "annotationInitializers"
	// Java.g:686:1: annotationInitializers : ( annotationInitializer ( COMMA annotationInitializer )* -> ^( ANNOTATION_INIT_KEY_LIST ( annotationInitializer )+ ) | annotationElementValue -> ^( ANNOTATION_INIT_DEFAULT_KEY annotationElementValue ) );
	public final JavaParser.annotationInitializers_return annotationInitializers() throws RecognitionException {
		JavaParser.annotationInitializers_return retval = new JavaParser.annotationInitializers_return();
		retval.start = input.LT(1);
		int annotationInitializers_StartIndex = input.index();

		CommonTree root_0 = null;

		Token COMMA230=null;
		ParserRuleReturnScope annotationInitializer229 =null;
		ParserRuleReturnScope annotationInitializer231 =null;
		ParserRuleReturnScope annotationElementValue232 =null;

		CommonTree COMMA230_tree=null;
		RewriteRuleTokenStream stream_COMMA=new RewriteRuleTokenStream(adaptor,"token COMMA");
		RewriteRuleSubtreeStream stream_annotationElementValue=new RewriteRuleSubtreeStream(adaptor,"rule annotationElementValue");
		RewriteRuleSubtreeStream stream_annotationInitializer=new RewriteRuleSubtreeStream(adaptor,"rule annotationInitializer");

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 63) ) { return retval; }

			// Java.g:687:5: ( annotationInitializer ( COMMA annotationInitializer )* -> ^( ANNOTATION_INIT_KEY_LIST ( annotationInitializer )+ ) | annotationElementValue -> ^( ANNOTATION_INIT_DEFAULT_KEY annotationElementValue ) )
			int alt78=2;
			int LA78_0 = input.LA(1);
			if ( (LA78_0==IDENT) ) {
				int LA78_1 = input.LA(2);
				if ( (LA78_1==ASSIGN) ) {
					alt78=1;
				}
				else if ( (LA78_1==AND||LA78_1==BIT_SHIFT_RIGHT||LA78_1==DEC||LA78_1==DIV||LA78_1==DOT||LA78_1==EQUAL||(LA78_1 >= GREATER_OR_EQUAL && LA78_1 <= GREATER_THAN)||(LA78_1 >= INC && LA78_1 <= INSTANCEOF)||LA78_1==LBRACK||(LA78_1 >= LESS_OR_EQUAL && LA78_1 <= LESS_THAN)||LA78_1==LOGICAL_AND||LA78_1==LOGICAL_OR||LA78_1==LPAREN||LA78_1==MINUS||LA78_1==MOD||LA78_1==NOT_EQUAL||LA78_1==OR||LA78_1==PLUS||LA78_1==QUESTION||LA78_1==RPAREN||LA78_1==SHIFT_LEFT||LA78_1==SHIFT_RIGHT||LA78_1==STAR||LA78_1==XOR) ) {
					alt78=2;
				}
				else {
					if (state.backtracking>0) {state.failed=true; return retval;}
					int nvaeMark = input.mark();
					try {
						input.consume();
						NoViableAltException nvae =
							new NoViableAltException("", 78, 1, input);
						throw nvae;
					} finally {
						input.rewind(nvaeMark);
					}
				}
			}
			else if ( (LA78_0==AT||LA78_0==BOOLEAN||LA78_0==BYTE||(LA78_0 >= CHAR && LA78_0 <= CHARACTER_LITERAL)||(LA78_0 >= DEC && LA78_0 <= DECIMAL_LITERAL)||LA78_0==DOUBLE||LA78_0==FALSE||(LA78_0 >= FLOAT && LA78_0 <= FLOATING_POINT_LITERAL)||LA78_0==HEX_LITERAL||LA78_0==INC||LA78_0==INT||LA78_0==LCURLY||LA78_0==LESS_THAN||LA78_0==LOGICAL_NOT||(LA78_0 >= LONG && LA78_0 <= LPAREN)||LA78_0==MINUS||(LA78_0 >= NEW && LA78_0 <= NOT)||LA78_0==NULL||LA78_0==OCTAL_LITERAL||LA78_0==PLUS||LA78_0==SHORT||(LA78_0 >= STRING_LITERAL && LA78_0 <= SUPER)||LA78_0==THIS||LA78_0==TRUE||LA78_0==VOID) ) {
				alt78=2;
			}
			else {
				if (state.backtracking>0) {state.failed=true; return retval;}
				NoViableAltException nvae =
					new NoViableAltException("", 78, 0, input);
				throw nvae;
			}
			switch (alt78) {
				case 1 :
					// Java.g:687:9: annotationInitializer ( COMMA annotationInitializer )*
					{
					pushFollow(FOLLOW_annotationInitializer_in_annotationInitializers8111);
					annotationInitializer229=annotationInitializer();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_annotationInitializer.add(annotationInitializer229.getTree());
					// Java.g:687:31: ( COMMA annotationInitializer )*
					loop77:
					do {
						int alt77=2;
						int LA77_0 = input.LA(1);
						if ( (LA77_0==COMMA) ) {
							alt77=1;
						}

						switch (alt77) {
						case 1 :
							// Java.g:687:32: COMMA annotationInitializer
							{
							COMMA230=(Token)match(input,COMMA,FOLLOW_COMMA_in_annotationInitializers8114); if (state.failed) return retval; 
							if ( state.backtracking==0 ) stream_COMMA.add(COMMA230);

							pushFollow(FOLLOW_annotationInitializer_in_annotationInitializers8116);
							annotationInitializer231=annotationInitializer();
							state._fsp--;
							if (state.failed) return retval;
							if ( state.backtracking==0 ) stream_annotationInitializer.add(annotationInitializer231.getTree());
							}
							break;

						default :
							break loop77;
						}
					} while (true);

					// AST REWRITE
					// elements: annotationInitializer
					// token labels: 
					// rule labels: retval
					// token list labels: 
					// rule list labels: 
					// wildcard labels: 
					if ( state.backtracking==0 ) {

					retval.tree = root_0;
					RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

					root_0 = (CommonTree)adaptor.nil();
					// 688:9: -> ^( ANNOTATION_INIT_KEY_LIST ( annotationInitializer )+ )
					{
						// Java.g:688:13: ^( ANNOTATION_INIT_KEY_LIST ( annotationInitializer )+ )
						{
						CommonTree root_1 = (CommonTree)adaptor.nil();
						root_1 = (CommonTree)adaptor.becomeRoot(
						(CommonTree)adaptor.create(ANNOTATION_INIT_KEY_LIST, "ANNOTATION_INIT_KEY_LIST")
						, root_1);

						if ( !(stream_annotationInitializer.hasNext()) ) {
							throw new RewriteEarlyExitException();
						}
						while ( stream_annotationInitializer.hasNext() ) {
							adaptor.addChild(root_1, stream_annotationInitializer.nextTree());

						}
						stream_annotationInitializer.reset();

						adaptor.addChild(root_0, root_1);
						}

					}


					retval.tree = root_0;
					}

					}
					break;
				case 2 :
					// Java.g:689:9: annotationElementValue
					{
					pushFollow(FOLLOW_annotationElementValue_in_annotationInitializers8146);
					annotationElementValue232=annotationElementValue();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_annotationElementValue.add(annotationElementValue232.getTree());
					// AST REWRITE
					// elements: annotationElementValue
					// token labels: 
					// rule labels: retval
					// token list labels: 
					// rule list labels: 
					// wildcard labels: 
					if ( state.backtracking==0 ) {

					retval.tree = root_0;
					RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

					root_0 = (CommonTree)adaptor.nil();
					// 690:9: -> ^( ANNOTATION_INIT_DEFAULT_KEY annotationElementValue )
					{
						// Java.g:690:13: ^( ANNOTATION_INIT_DEFAULT_KEY annotationElementValue )
						{
						CommonTree root_1 = (CommonTree)adaptor.nil();
						root_1 = (CommonTree)adaptor.becomeRoot(
						(CommonTree)adaptor.create(ANNOTATION_INIT_DEFAULT_KEY, "ANNOTATION_INIT_DEFAULT_KEY")
						, root_1);

						adaptor.addChild(root_1, stream_annotationElementValue.nextTree());

						adaptor.addChild(root_0, root_1);
						}

					}


					retval.tree = root_0;
					}

					}
					break;

			}
			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 63, annotationInitializers_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "annotationInitializers"


	public static class annotationInitializer_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "annotationInitializer"
	// Java.g:693:1: annotationInitializer : IDENT ^ ASSIGN ! annotationElementValue ;
	public final JavaParser.annotationInitializer_return annotationInitializer() throws RecognitionException {
		JavaParser.annotationInitializer_return retval = new JavaParser.annotationInitializer_return();
		retval.start = input.LT(1);
		int annotationInitializer_StartIndex = input.index();

		CommonTree root_0 = null;

		Token IDENT233=null;
		Token ASSIGN234=null;
		ParserRuleReturnScope annotationElementValue235 =null;

		CommonTree IDENT233_tree=null;
		CommonTree ASSIGN234_tree=null;

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 64) ) { return retval; }

			// Java.g:694:5: ( IDENT ^ ASSIGN ! annotationElementValue )
			// Java.g:694:9: IDENT ^ ASSIGN ! annotationElementValue
			{
			root_0 = (CommonTree)adaptor.nil();


			IDENT233=(Token)match(input,IDENT,FOLLOW_IDENT_in_annotationInitializer8187); if (state.failed) return retval;
			if ( state.backtracking==0 ) {
			IDENT233_tree = 
			(CommonTree)adaptor.create(IDENT233)
			;
			root_0 = (CommonTree)adaptor.becomeRoot(IDENT233_tree, root_0);
			}

			ASSIGN234=(Token)match(input,ASSIGN,FOLLOW_ASSIGN_in_annotationInitializer8190); if (state.failed) return retval;
			pushFollow(FOLLOW_annotationElementValue_in_annotationInitializer8193);
			annotationElementValue235=annotationElementValue();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) adaptor.addChild(root_0, annotationElementValue235.getTree());

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 64, annotationInitializer_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "annotationInitializer"


	public static class annotationElementValue_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "annotationElementValue"
	// Java.g:697:1: annotationElementValue : ( annotationElementValueExpression | annotation | annotationElementValueArrayInitializer );
	public final JavaParser.annotationElementValue_return annotationElementValue() throws RecognitionException {
		JavaParser.annotationElementValue_return retval = new JavaParser.annotationElementValue_return();
		retval.start = input.LT(1);
		int annotationElementValue_StartIndex = input.index();

		CommonTree root_0 = null;

		ParserRuleReturnScope annotationElementValueExpression236 =null;
		ParserRuleReturnScope annotation237 =null;
		ParserRuleReturnScope annotationElementValueArrayInitializer238 =null;


		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 65) ) { return retval; }

			// Java.g:698:5: ( annotationElementValueExpression | annotation | annotationElementValueArrayInitializer )
			int alt79=3;
			switch ( input.LA(1) ) {
			case BOOLEAN:
			case BYTE:
			case CHAR:
			case CHARACTER_LITERAL:
			case DEC:
			case DECIMAL_LITERAL:
			case DOUBLE:
			case FALSE:
			case FLOAT:
			case FLOATING_POINT_LITERAL:
			case HEX_LITERAL:
			case IDENT:
			case INC:
			case INT:
			case LESS_THAN:
			case LOGICAL_NOT:
			case LONG:
			case LPAREN:
			case MINUS:
			case NEW:
			case NOT:
			case NULL:
			case OCTAL_LITERAL:
			case PLUS:
			case SHORT:
			case STRING_LITERAL:
			case SUPER:
			case THIS:
			case TRUE:
			case VOID:
				{
				alt79=1;
				}
				break;
			case AT:
				{
				alt79=2;
				}
				break;
			case LCURLY:
				{
				alt79=3;
				}
				break;
			default:
				if (state.backtracking>0) {state.failed=true; return retval;}
				NoViableAltException nvae =
					new NoViableAltException("", 79, 0, input);
				throw nvae;
			}
			switch (alt79) {
				case 1 :
					// Java.g:698:9: annotationElementValueExpression
					{
					root_0 = (CommonTree)adaptor.nil();


					pushFollow(FOLLOW_annotationElementValueExpression_in_annotationElementValue8216);
					annotationElementValueExpression236=annotationElementValueExpression();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) adaptor.addChild(root_0, annotationElementValueExpression236.getTree());

					}
					break;
				case 2 :
					// Java.g:699:9: annotation
					{
					root_0 = (CommonTree)adaptor.nil();


					pushFollow(FOLLOW_annotation_in_annotationElementValue8226);
					annotation237=annotation();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) adaptor.addChild(root_0, annotation237.getTree());

					}
					break;
				case 3 :
					// Java.g:700:9: annotationElementValueArrayInitializer
					{
					root_0 = (CommonTree)adaptor.nil();


					pushFollow(FOLLOW_annotationElementValueArrayInitializer_in_annotationElementValue8236);
					annotationElementValueArrayInitializer238=annotationElementValueArrayInitializer();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) adaptor.addChild(root_0, annotationElementValueArrayInitializer238.getTree());

					}
					break;

			}
			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 65, annotationElementValue_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "annotationElementValue"


	public static class annotationElementValueExpression_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "annotationElementValueExpression"
	// Java.g:703:1: annotationElementValueExpression : conditionalExpression -> ^( EXPR conditionalExpression ) ;
	public final JavaParser.annotationElementValueExpression_return annotationElementValueExpression() throws RecognitionException {
		JavaParser.annotationElementValueExpression_return retval = new JavaParser.annotationElementValueExpression_return();
		retval.start = input.LT(1);
		int annotationElementValueExpression_StartIndex = input.index();

		CommonTree root_0 = null;

		ParserRuleReturnScope conditionalExpression239 =null;

		RewriteRuleSubtreeStream stream_conditionalExpression=new RewriteRuleSubtreeStream(adaptor,"rule conditionalExpression");

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 66) ) { return retval; }

			// Java.g:704:5: ( conditionalExpression -> ^( EXPR conditionalExpression ) )
			// Java.g:704:9: conditionalExpression
			{
			pushFollow(FOLLOW_conditionalExpression_in_annotationElementValueExpression8259);
			conditionalExpression239=conditionalExpression();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) stream_conditionalExpression.add(conditionalExpression239.getTree());
			// AST REWRITE
			// elements: conditionalExpression
			// token labels: 
			// rule labels: retval
			// token list labels: 
			// rule list labels: 
			// wildcard labels: 
			if ( state.backtracking==0 ) {

			retval.tree = root_0;
			RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

			root_0 = (CommonTree)adaptor.nil();
			// 705:9: -> ^( EXPR conditionalExpression )
			{
				// Java.g:705:13: ^( EXPR conditionalExpression )
				{
				CommonTree root_1 = (CommonTree)adaptor.nil();
				root_1 = (CommonTree)adaptor.becomeRoot(
				(CommonTree)adaptor.create(EXPR, "EXPR")
				, root_1);

				adaptor.addChild(root_1, stream_conditionalExpression.nextTree());

				adaptor.addChild(root_0, root_1);
				}

			}


			retval.tree = root_0;
			}

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 66, annotationElementValueExpression_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "annotationElementValueExpression"


	public static class annotationElementValueArrayInitializer_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "annotationElementValueArrayInitializer"
	// Java.g:708:1: annotationElementValueArrayInitializer : LCURLY ( annotationElementValue ( COMMA annotationElementValue )* )? ( COMMA )? RCURLY -> ^( ANNOTATION_INIT_ARRAY_ELEMENT[$LCURLY, \"ANNOTATION_ELEM_VALUE_ARRAY_INIT\"] ( annotationElementValue )* ) ;
	public final JavaParser.annotationElementValueArrayInitializer_return annotationElementValueArrayInitializer() throws RecognitionException {
		JavaParser.annotationElementValueArrayInitializer_return retval = new JavaParser.annotationElementValueArrayInitializer_return();
		retval.start = input.LT(1);
		int annotationElementValueArrayInitializer_StartIndex = input.index();

		CommonTree root_0 = null;

		Token LCURLY240=null;
		Token COMMA242=null;
		Token COMMA244=null;
		Token RCURLY245=null;
		ParserRuleReturnScope annotationElementValue241 =null;
		ParserRuleReturnScope annotationElementValue243 =null;

		CommonTree LCURLY240_tree=null;
		CommonTree COMMA242_tree=null;
		CommonTree COMMA244_tree=null;
		CommonTree RCURLY245_tree=null;
		RewriteRuleTokenStream stream_LCURLY=new RewriteRuleTokenStream(adaptor,"token LCURLY");
		RewriteRuleTokenStream stream_COMMA=new RewriteRuleTokenStream(adaptor,"token COMMA");
		RewriteRuleTokenStream stream_RCURLY=new RewriteRuleTokenStream(adaptor,"token RCURLY");
		RewriteRuleSubtreeStream stream_annotationElementValue=new RewriteRuleSubtreeStream(adaptor,"rule annotationElementValue");

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 67) ) { return retval; }

			// Java.g:709:5: ( LCURLY ( annotationElementValue ( COMMA annotationElementValue )* )? ( COMMA )? RCURLY -> ^( ANNOTATION_INIT_ARRAY_ELEMENT[$LCURLY, \"ANNOTATION_ELEM_VALUE_ARRAY_INIT\"] ( annotationElementValue )* ) )
			// Java.g:709:9: LCURLY ( annotationElementValue ( COMMA annotationElementValue )* )? ( COMMA )? RCURLY
			{
			LCURLY240=(Token)match(input,LCURLY,FOLLOW_LCURLY_in_annotationElementValueArrayInitializer8299); if (state.failed) return retval; 
			if ( state.backtracking==0 ) stream_LCURLY.add(LCURLY240);

			// Java.g:709:16: ( annotationElementValue ( COMMA annotationElementValue )* )?
			int alt81=2;
			int LA81_0 = input.LA(1);
			if ( (LA81_0==AT||LA81_0==BOOLEAN||LA81_0==BYTE||(LA81_0 >= CHAR && LA81_0 <= CHARACTER_LITERAL)||(LA81_0 >= DEC && LA81_0 <= DECIMAL_LITERAL)||LA81_0==DOUBLE||LA81_0==FALSE||(LA81_0 >= FLOAT && LA81_0 <= FLOATING_POINT_LITERAL)||(LA81_0 >= HEX_LITERAL && LA81_0 <= IDENT)||LA81_0==INC||LA81_0==INT||LA81_0==LCURLY||LA81_0==LESS_THAN||LA81_0==LOGICAL_NOT||(LA81_0 >= LONG && LA81_0 <= LPAREN)||LA81_0==MINUS||(LA81_0 >= NEW && LA81_0 <= NOT)||LA81_0==NULL||LA81_0==OCTAL_LITERAL||LA81_0==PLUS||LA81_0==SHORT||(LA81_0 >= STRING_LITERAL && LA81_0 <= SUPER)||LA81_0==THIS||LA81_0==TRUE||LA81_0==VOID) ) {
				alt81=1;
			}
			switch (alt81) {
				case 1 :
					// Java.g:709:17: annotationElementValue ( COMMA annotationElementValue )*
					{
					pushFollow(FOLLOW_annotationElementValue_in_annotationElementValueArrayInitializer8302);
					annotationElementValue241=annotationElementValue();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_annotationElementValue.add(annotationElementValue241.getTree());
					// Java.g:709:40: ( COMMA annotationElementValue )*
					loop80:
					do {
						int alt80=2;
						int LA80_0 = input.LA(1);
						if ( (LA80_0==COMMA) ) {
							int LA80_1 = input.LA(2);
							if ( (LA80_1==AT||LA80_1==BOOLEAN||LA80_1==BYTE||(LA80_1 >= CHAR && LA80_1 <= CHARACTER_LITERAL)||(LA80_1 >= DEC && LA80_1 <= DECIMAL_LITERAL)||LA80_1==DOUBLE||LA80_1==FALSE||(LA80_1 >= FLOAT && LA80_1 <= FLOATING_POINT_LITERAL)||(LA80_1 >= HEX_LITERAL && LA80_1 <= IDENT)||LA80_1==INC||LA80_1==INT||LA80_1==LCURLY||LA80_1==LESS_THAN||LA80_1==LOGICAL_NOT||(LA80_1 >= LONG && LA80_1 <= LPAREN)||LA80_1==MINUS||(LA80_1 >= NEW && LA80_1 <= NOT)||LA80_1==NULL||LA80_1==OCTAL_LITERAL||LA80_1==PLUS||LA80_1==SHORT||(LA80_1 >= STRING_LITERAL && LA80_1 <= SUPER)||LA80_1==THIS||LA80_1==TRUE||LA80_1==VOID) ) {
								alt80=1;
							}

						}

						switch (alt80) {
						case 1 :
							// Java.g:709:41: COMMA annotationElementValue
							{
							COMMA242=(Token)match(input,COMMA,FOLLOW_COMMA_in_annotationElementValueArrayInitializer8305); if (state.failed) return retval; 
							if ( state.backtracking==0 ) stream_COMMA.add(COMMA242);

							pushFollow(FOLLOW_annotationElementValue_in_annotationElementValueArrayInitializer8307);
							annotationElementValue243=annotationElementValue();
							state._fsp--;
							if (state.failed) return retval;
							if ( state.backtracking==0 ) stream_annotationElementValue.add(annotationElementValue243.getTree());
							}
							break;

						default :
							break loop80;
						}
					} while (true);

					}
					break;

			}

			// Java.g:709:74: ( COMMA )?
			int alt82=2;
			int LA82_0 = input.LA(1);
			if ( (LA82_0==COMMA) ) {
				alt82=1;
			}
			switch (alt82) {
				case 1 :
					// Java.g:709:75: COMMA
					{
					COMMA244=(Token)match(input,COMMA,FOLLOW_COMMA_in_annotationElementValueArrayInitializer8314); if (state.failed) return retval; 
					if ( state.backtracking==0 ) stream_COMMA.add(COMMA244);

					}
					break;

			}

			RCURLY245=(Token)match(input,RCURLY,FOLLOW_RCURLY_in_annotationElementValueArrayInitializer8318); if (state.failed) return retval; 
			if ( state.backtracking==0 ) stream_RCURLY.add(RCURLY245);

			// AST REWRITE
			// elements: annotationElementValue
			// token labels: 
			// rule labels: retval
			// token list labels: 
			// rule list labels: 
			// wildcard labels: 
			if ( state.backtracking==0 ) {

			retval.tree = root_0;
			RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

			root_0 = (CommonTree)adaptor.nil();
			// 710:9: -> ^( ANNOTATION_INIT_ARRAY_ELEMENT[$LCURLY, \"ANNOTATION_ELEM_VALUE_ARRAY_INIT\"] ( annotationElementValue )* )
			{
				// Java.g:710:13: ^( ANNOTATION_INIT_ARRAY_ELEMENT[$LCURLY, \"ANNOTATION_ELEM_VALUE_ARRAY_INIT\"] ( annotationElementValue )* )
				{
				CommonTree root_1 = (CommonTree)adaptor.nil();
				root_1 = (CommonTree)adaptor.becomeRoot(
				(CommonTree)adaptor.create(ANNOTATION_INIT_ARRAY_ELEMENT, LCURLY240, "ANNOTATION_ELEM_VALUE_ARRAY_INIT")
				, root_1);

				// Java.g:710:90: ( annotationElementValue )*
				while ( stream_annotationElementValue.hasNext() ) {
					adaptor.addChild(root_1, stream_annotationElementValue.nextTree());

				}
				stream_annotationElementValue.reset();

				adaptor.addChild(root_0, root_1);
				}

			}


			retval.tree = root_0;
			}

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 67, annotationElementValueArrayInitializer_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "annotationElementValueArrayInitializer"


	public static class annotationTypeDeclaration_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "annotationTypeDeclaration"
	// Java.g:713:1: annotationTypeDeclaration[CommonTree modifiers] : AT INTERFACE IDENT annotationBody -> ^( AT IDENT annotationBody ) ;
	public final JavaParser.annotationTypeDeclaration_return annotationTypeDeclaration(CommonTree modifiers) throws RecognitionException {
		JavaParser.annotationTypeDeclaration_return retval = new JavaParser.annotationTypeDeclaration_return();
		retval.start = input.LT(1);
		int annotationTypeDeclaration_StartIndex = input.index();

		CommonTree root_0 = null;

		Token AT246=null;
		Token INTERFACE247=null;
		Token IDENT248=null;
		ParserRuleReturnScope annotationBody249 =null;

		CommonTree AT246_tree=null;
		CommonTree INTERFACE247_tree=null;
		CommonTree IDENT248_tree=null;
		RewriteRuleTokenStream stream_AT=new RewriteRuleTokenStream(adaptor,"token AT");
		RewriteRuleTokenStream stream_IDENT=new RewriteRuleTokenStream(adaptor,"token IDENT");
		RewriteRuleTokenStream stream_INTERFACE=new RewriteRuleTokenStream(adaptor,"token INTERFACE");
		RewriteRuleSubtreeStream stream_annotationBody=new RewriteRuleSubtreeStream(adaptor,"rule annotationBody");

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 68) ) { return retval; }

			// Java.g:714:5: ( AT INTERFACE IDENT annotationBody -> ^( AT IDENT annotationBody ) )
			// Java.g:714:9: AT INTERFACE IDENT annotationBody
			{
			AT246=(Token)match(input,AT,FOLLOW_AT_in_annotationTypeDeclaration8361); if (state.failed) return retval; 
			if ( state.backtracking==0 ) stream_AT.add(AT246);

			INTERFACE247=(Token)match(input,INTERFACE,FOLLOW_INTERFACE_in_annotationTypeDeclaration8363); if (state.failed) return retval; 
			if ( state.backtracking==0 ) stream_INTERFACE.add(INTERFACE247);

			IDENT248=(Token)match(input,IDENT,FOLLOW_IDENT_in_annotationTypeDeclaration8365); if (state.failed) return retval; 
			if ( state.backtracking==0 ) stream_IDENT.add(IDENT248);

			pushFollow(FOLLOW_annotationBody_in_annotationTypeDeclaration8367);
			annotationBody249=annotationBody();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) stream_annotationBody.add(annotationBody249.getTree());
			// AST REWRITE
			// elements: annotationBody, IDENT, AT
			// token labels: 
			// rule labels: retval
			// token list labels: 
			// rule list labels: 
			// wildcard labels: 
			if ( state.backtracking==0 ) {

			retval.tree = root_0;
			RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

			root_0 = (CommonTree)adaptor.nil();
			// 715:9: -> ^( AT IDENT annotationBody )
			{
				// Java.g:715:12: ^( AT IDENT annotationBody )
				{
				CommonTree root_1 = (CommonTree)adaptor.nil();
				root_1 = (CommonTree)adaptor.becomeRoot(
				stream_AT.nextNode()
				, root_1);

				adaptor.addChild(root_1, modifiers);

				adaptor.addChild(root_1, 
				stream_IDENT.nextNode()
				);

				adaptor.addChild(root_1, stream_annotationBody.nextTree());

				adaptor.addChild(root_0, root_1);
				}

			}


			retval.tree = root_0;
			}

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 68, annotationTypeDeclaration_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "annotationTypeDeclaration"


	public static class annotationBody_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "annotationBody"
	// Java.g:718:1: annotationBody : LCURLY ( annotationScopeDeclarations )* RCURLY -> ^( ANNOTATION_TOP_LEVEL_SCOPE[$LCURLY, \"CLASS_TOP_LEVEL_SCOPE\"] ( annotationScopeDeclarations )* ) ;
	public final JavaParser.annotationBody_return annotationBody() throws RecognitionException {
		JavaParser.annotationBody_return retval = new JavaParser.annotationBody_return();
		retval.start = input.LT(1);
		int annotationBody_StartIndex = input.index();

		CommonTree root_0 = null;

		Token LCURLY250=null;
		Token RCURLY252=null;
		ParserRuleReturnScope annotationScopeDeclarations251 =null;

		CommonTree LCURLY250_tree=null;
		CommonTree RCURLY252_tree=null;
		RewriteRuleTokenStream stream_LCURLY=new RewriteRuleTokenStream(adaptor,"token LCURLY");
		RewriteRuleTokenStream stream_RCURLY=new RewriteRuleTokenStream(adaptor,"token RCURLY");
		RewriteRuleSubtreeStream stream_annotationScopeDeclarations=new RewriteRuleSubtreeStream(adaptor,"rule annotationScopeDeclarations");

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 69) ) { return retval; }

			// Java.g:719:5: ( LCURLY ( annotationScopeDeclarations )* RCURLY -> ^( ANNOTATION_TOP_LEVEL_SCOPE[$LCURLY, \"CLASS_TOP_LEVEL_SCOPE\"] ( annotationScopeDeclarations )* ) )
			// Java.g:719:9: LCURLY ( annotationScopeDeclarations )* RCURLY
			{
			LCURLY250=(Token)match(input,LCURLY,FOLLOW_LCURLY_in_annotationBody8410); if (state.failed) return retval; 
			if ( state.backtracking==0 ) stream_LCURLY.add(LCURLY250);

			// Java.g:719:16: ( annotationScopeDeclarations )*
			loop83:
			do {
				int alt83=2;
				int LA83_0 = input.LA(1);
				if ( (LA83_0==ABSTRACT||LA83_0==AT||LA83_0==BOOLEAN||LA83_0==BYTE||LA83_0==CHAR||LA83_0==CLASS||LA83_0==DOUBLE||LA83_0==ENUM||LA83_0==FINAL||LA83_0==FLOAT||LA83_0==IDENT||LA83_0==INT||LA83_0==INTERFACE||LA83_0==LESS_THAN||LA83_0==LONG||LA83_0==NATIVE||(LA83_0 >= PRIVATE && LA83_0 <= PUBLIC)||LA83_0==SHORT||LA83_0==STATIC||LA83_0==STRICTFP||LA83_0==SYNCHRONIZED||LA83_0==TRANSIENT||LA83_0==VOID||LA83_0==VOLATILE) ) {
					alt83=1;
				}

				switch (alt83) {
				case 1 :
					// Java.g:719:16: annotationScopeDeclarations
					{
					pushFollow(FOLLOW_annotationScopeDeclarations_in_annotationBody8412);
					annotationScopeDeclarations251=annotationScopeDeclarations();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_annotationScopeDeclarations.add(annotationScopeDeclarations251.getTree());
					}
					break;

				default :
					break loop83;
				}
			} while (true);

			RCURLY252=(Token)match(input,RCURLY,FOLLOW_RCURLY_in_annotationBody8415); if (state.failed) return retval; 
			if ( state.backtracking==0 ) stream_RCURLY.add(RCURLY252);

			// AST REWRITE
			// elements: annotationScopeDeclarations
			// token labels: 
			// rule labels: retval
			// token list labels: 
			// rule list labels: 
			// wildcard labels: 
			if ( state.backtracking==0 ) {

			retval.tree = root_0;
			RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

			root_0 = (CommonTree)adaptor.nil();
			// 720:9: -> ^( ANNOTATION_TOP_LEVEL_SCOPE[$LCURLY, \"CLASS_TOP_LEVEL_SCOPE\"] ( annotationScopeDeclarations )* )
			{
				// Java.g:720:13: ^( ANNOTATION_TOP_LEVEL_SCOPE[$LCURLY, \"CLASS_TOP_LEVEL_SCOPE\"] ( annotationScopeDeclarations )* )
				{
				CommonTree root_1 = (CommonTree)adaptor.nil();
				root_1 = (CommonTree)adaptor.becomeRoot(
				(CommonTree)adaptor.create(ANNOTATION_TOP_LEVEL_SCOPE, LCURLY250, "CLASS_TOP_LEVEL_SCOPE")
				, root_1);

				// Java.g:720:76: ( annotationScopeDeclarations )*
				while ( stream_annotationScopeDeclarations.hasNext() ) {
					adaptor.addChild(root_1, stream_annotationScopeDeclarations.nextTree());

				}
				stream_annotationScopeDeclarations.reset();

				adaptor.addChild(root_0, root_1);
				}

			}


			retval.tree = root_0;
			}

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 69, annotationBody_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "annotationBody"


	public static class annotationScopeDeclarations_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "annotationScopeDeclarations"
	// Java.g:723:1: annotationScopeDeclarations : ( modifierList type ( IDENT LPAREN RPAREN ( annotationDefaultValue )? SEMI -> ^( ANNOTATION_METHOD_DECL modifierList type IDENT ( annotationDefaultValue )? ) | classFieldDeclaratorList SEMI -> ^( VAR_DECLARATION modifierList type classFieldDeclaratorList ) ) | typeDeclaration );
	public final JavaParser.annotationScopeDeclarations_return annotationScopeDeclarations() throws RecognitionException {
		JavaParser.annotationScopeDeclarations_return retval = new JavaParser.annotationScopeDeclarations_return();
		retval.start = input.LT(1);
		int annotationScopeDeclarations_StartIndex = input.index();

		CommonTree root_0 = null;

		Token IDENT255=null;
		Token LPAREN256=null;
		Token RPAREN257=null;
		Token SEMI259=null;
		Token SEMI261=null;
		ParserRuleReturnScope modifierList253 =null;
		ParserRuleReturnScope type254 =null;
		ParserRuleReturnScope annotationDefaultValue258 =null;
		ParserRuleReturnScope classFieldDeclaratorList260 =null;
		ParserRuleReturnScope typeDeclaration262 =null;

		CommonTree IDENT255_tree=null;
		CommonTree LPAREN256_tree=null;
		CommonTree RPAREN257_tree=null;
		CommonTree SEMI259_tree=null;
		CommonTree SEMI261_tree=null;
		RewriteRuleTokenStream stream_IDENT=new RewriteRuleTokenStream(adaptor,"token IDENT");
		RewriteRuleTokenStream stream_RPAREN=new RewriteRuleTokenStream(adaptor,"token RPAREN");
		RewriteRuleTokenStream stream_SEMI=new RewriteRuleTokenStream(adaptor,"token SEMI");
		RewriteRuleTokenStream stream_LPAREN=new RewriteRuleTokenStream(adaptor,"token LPAREN");
		RewriteRuleSubtreeStream stream_modifierList=new RewriteRuleSubtreeStream(adaptor,"rule modifierList");
		RewriteRuleSubtreeStream stream_annotationDefaultValue=new RewriteRuleSubtreeStream(adaptor,"rule annotationDefaultValue");
		RewriteRuleSubtreeStream stream_type=new RewriteRuleSubtreeStream(adaptor,"rule type");
		RewriteRuleSubtreeStream stream_classFieldDeclaratorList=new RewriteRuleSubtreeStream(adaptor,"rule classFieldDeclaratorList");

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 70) ) { return retval; }

			// Java.g:724:5: ( modifierList type ( IDENT LPAREN RPAREN ( annotationDefaultValue )? SEMI -> ^( ANNOTATION_METHOD_DECL modifierList type IDENT ( annotationDefaultValue )? ) | classFieldDeclaratorList SEMI -> ^( VAR_DECLARATION modifierList type classFieldDeclaratorList ) ) | typeDeclaration )
			int alt86=2;
			switch ( input.LA(1) ) {
			case PUBLIC:
				{
				int LA86_1 = input.LA(2);
				if ( (synpred114_Java()) ) {
					alt86=1;
				}
				else if ( (true) ) {
					alt86=2;
				}
				else {
					if (state.backtracking>0) {state.failed=true; return retval;}
					int nvaeMark = input.mark();
					try {
						input.consume();
						NoViableAltException nvae =
							new NoViableAltException("", 86, 1, input);
						throw nvae;
					} finally {
						input.rewind(nvaeMark);
					}
				}
				}
				break;
			case PROTECTED:
				{
				int LA86_2 = input.LA(2);
				if ( (synpred114_Java()) ) {
					alt86=1;
				}
				else if ( (true) ) {
					alt86=2;
				}
				else {
					if (state.backtracking>0) {state.failed=true; return retval;}
					int nvaeMark = input.mark();
					try {
						input.consume();
						NoViableAltException nvae =
							new NoViableAltException("", 86, 2, input);
						throw nvae;
					} finally {
						input.rewind(nvaeMark);
					}
				}
				}
				break;
			case PRIVATE:
				{
				int LA86_3 = input.LA(2);
				if ( (synpred114_Java()) ) {
					alt86=1;
				}
				else if ( (true) ) {
					alt86=2;
				}
				else {
					if (state.backtracking>0) {state.failed=true; return retval;}
					int nvaeMark = input.mark();
					try {
						input.consume();
						NoViableAltException nvae =
							new NoViableAltException("", 86, 3, input);
						throw nvae;
					} finally {
						input.rewind(nvaeMark);
					}
				}
				}
				break;
			case STATIC:
				{
				int LA86_4 = input.LA(2);
				if ( (synpred114_Java()) ) {
					alt86=1;
				}
				else if ( (true) ) {
					alt86=2;
				}
				else {
					if (state.backtracking>0) {state.failed=true; return retval;}
					int nvaeMark = input.mark();
					try {
						input.consume();
						NoViableAltException nvae =
							new NoViableAltException("", 86, 4, input);
						throw nvae;
					} finally {
						input.rewind(nvaeMark);
					}
				}
				}
				break;
			case ABSTRACT:
				{
				int LA86_5 = input.LA(2);
				if ( (synpred114_Java()) ) {
					alt86=1;
				}
				else if ( (true) ) {
					alt86=2;
				}
				else {
					if (state.backtracking>0) {state.failed=true; return retval;}
					int nvaeMark = input.mark();
					try {
						input.consume();
						NoViableAltException nvae =
							new NoViableAltException("", 86, 5, input);
						throw nvae;
					} finally {
						input.rewind(nvaeMark);
					}
				}
				}
				break;
			case NATIVE:
				{
				int LA86_6 = input.LA(2);
				if ( (synpred114_Java()) ) {
					alt86=1;
				}
				else if ( (true) ) {
					alt86=2;
				}
				else {
					if (state.backtracking>0) {state.failed=true; return retval;}
					int nvaeMark = input.mark();
					try {
						input.consume();
						NoViableAltException nvae =
							new NoViableAltException("", 86, 6, input);
						throw nvae;
					} finally {
						input.rewind(nvaeMark);
					}
				}
				}
				break;
			case SYNCHRONIZED:
				{
				int LA86_7 = input.LA(2);
				if ( (synpred114_Java()) ) {
					alt86=1;
				}
				else if ( (true) ) {
					alt86=2;
				}
				else {
					if (state.backtracking>0) {state.failed=true; return retval;}
					int nvaeMark = input.mark();
					try {
						input.consume();
						NoViableAltException nvae =
							new NoViableAltException("", 86, 7, input);
						throw nvae;
					} finally {
						input.rewind(nvaeMark);
					}
				}
				}
				break;
			case TRANSIENT:
				{
				int LA86_8 = input.LA(2);
				if ( (synpred114_Java()) ) {
					alt86=1;
				}
				else if ( (true) ) {
					alt86=2;
				}
				else {
					if (state.backtracking>0) {state.failed=true; return retval;}
					int nvaeMark = input.mark();
					try {
						input.consume();
						NoViableAltException nvae =
							new NoViableAltException("", 86, 8, input);
						throw nvae;
					} finally {
						input.rewind(nvaeMark);
					}
				}
				}
				break;
			case VOLATILE:
				{
				int LA86_9 = input.LA(2);
				if ( (synpred114_Java()) ) {
					alt86=1;
				}
				else if ( (true) ) {
					alt86=2;
				}
				else {
					if (state.backtracking>0) {state.failed=true; return retval;}
					int nvaeMark = input.mark();
					try {
						input.consume();
						NoViableAltException nvae =
							new NoViableAltException("", 86, 9, input);
						throw nvae;
					} finally {
						input.rewind(nvaeMark);
					}
				}
				}
				break;
			case STRICTFP:
				{
				int LA86_10 = input.LA(2);
				if ( (synpred114_Java()) ) {
					alt86=1;
				}
				else if ( (true) ) {
					alt86=2;
				}
				else {
					if (state.backtracking>0) {state.failed=true; return retval;}
					int nvaeMark = input.mark();
					try {
						input.consume();
						NoViableAltException nvae =
							new NoViableAltException("", 86, 10, input);
						throw nvae;
					} finally {
						input.rewind(nvaeMark);
					}
				}
				}
				break;
			case FINAL:
				{
				int LA86_11 = input.LA(2);
				if ( (synpred114_Java()) ) {
					alt86=1;
				}
				else if ( (true) ) {
					alt86=2;
				}
				else {
					if (state.backtracking>0) {state.failed=true; return retval;}
					int nvaeMark = input.mark();
					try {
						input.consume();
						NoViableAltException nvae =
							new NoViableAltException("", 86, 11, input);
						throw nvae;
					} finally {
						input.rewind(nvaeMark);
					}
				}
				}
				break;
			case AT:
				{
				int LA86_12 = input.LA(2);
				if ( (synpred114_Java()) ) {
					alt86=1;
				}
				else if ( (true) ) {
					alt86=2;
				}
				else {
					if (state.backtracking>0) {state.failed=true; return retval;}
					int nvaeMark = input.mark();
					try {
						input.consume();
						NoViableAltException nvae =
							new NoViableAltException("", 86, 12, input);
						throw nvae;
					} finally {
						input.rewind(nvaeMark);
					}
				}
				}
				break;
			case BOOLEAN:
			case BYTE:
			case CHAR:
			case DOUBLE:
			case FLOAT:
			case IDENT:
			case INT:
			case LONG:
			case SHORT:
				{
				alt86=1;
				}
				break;
			case CLASS:
			case ENUM:
			case INTERFACE:
				{
				alt86=2;
				}
				break;
			default:
				if (state.backtracking>0) {state.failed=true; return retval;}
				NoViableAltException nvae =
					new NoViableAltException("", 86, 0, input);
				throw nvae;
			}
			switch (alt86) {
				case 1 :
					// Java.g:724:9: modifierList type ( IDENT LPAREN RPAREN ( annotationDefaultValue )? SEMI -> ^( ANNOTATION_METHOD_DECL modifierList type IDENT ( annotationDefaultValue )? ) | classFieldDeclaratorList SEMI -> ^( VAR_DECLARATION modifierList type classFieldDeclaratorList ) )
					{
					pushFollow(FOLLOW_modifierList_in_annotationScopeDeclarations8457);
					modifierList253=modifierList();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_modifierList.add(modifierList253.getTree());
					pushFollow(FOLLOW_type_in_annotationScopeDeclarations8459);
					type254=type();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_type.add(type254.getTree());
					// Java.g:725:9: ( IDENT LPAREN RPAREN ( annotationDefaultValue )? SEMI -> ^( ANNOTATION_METHOD_DECL modifierList type IDENT ( annotationDefaultValue )? ) | classFieldDeclaratorList SEMI -> ^( VAR_DECLARATION modifierList type classFieldDeclaratorList ) )
					int alt85=2;
					int LA85_0 = input.LA(1);
					if ( (LA85_0==IDENT) ) {
						int LA85_1 = input.LA(2);
						if ( (LA85_1==LPAREN) ) {
							alt85=1;
						}
						else if ( (LA85_1==ASSIGN||LA85_1==COMMA||LA85_1==LBRACK||LA85_1==SEMI) ) {
							alt85=2;
						}
						else {
							if (state.backtracking>0) {state.failed=true; return retval;}
							int nvaeMark = input.mark();
							try {
								input.consume();
								NoViableAltException nvae =
									new NoViableAltException("", 85, 1, input);
								throw nvae;
							} finally {
								input.rewind(nvaeMark);
							}
						}
					}
					else {
						if (state.backtracking>0) {state.failed=true; return retval;}
						NoViableAltException nvae =
							new NoViableAltException("", 85, 0, input);
						throw nvae;
					}
					switch (alt85) {
						case 1 :
							// Java.g:725:13: IDENT LPAREN RPAREN ( annotationDefaultValue )? SEMI
							{
							IDENT255=(Token)match(input,IDENT,FOLLOW_IDENT_in_annotationScopeDeclarations8473); if (state.failed) return retval; 
							if ( state.backtracking==0 ) stream_IDENT.add(IDENT255);

							LPAREN256=(Token)match(input,LPAREN,FOLLOW_LPAREN_in_annotationScopeDeclarations8475); if (state.failed) return retval; 
							if ( state.backtracking==0 ) stream_LPAREN.add(LPAREN256);

							RPAREN257=(Token)match(input,RPAREN,FOLLOW_RPAREN_in_annotationScopeDeclarations8477); if (state.failed) return retval; 
							if ( state.backtracking==0 ) stream_RPAREN.add(RPAREN257);

							// Java.g:725:33: ( annotationDefaultValue )?
							int alt84=2;
							int LA84_0 = input.LA(1);
							if ( (LA84_0==DEFAULT) ) {
								alt84=1;
							}
							switch (alt84) {
								case 1 :
									// Java.g:725:33: annotationDefaultValue
									{
									pushFollow(FOLLOW_annotationDefaultValue_in_annotationScopeDeclarations8479);
									annotationDefaultValue258=annotationDefaultValue();
									state._fsp--;
									if (state.failed) return retval;
									if ( state.backtracking==0 ) stream_annotationDefaultValue.add(annotationDefaultValue258.getTree());
									}
									break;

							}

							SEMI259=(Token)match(input,SEMI,FOLLOW_SEMI_in_annotationScopeDeclarations8482); if (state.failed) return retval; 
							if ( state.backtracking==0 ) stream_SEMI.add(SEMI259);

							// AST REWRITE
							// elements: annotationDefaultValue, IDENT, modifierList, type
							// token labels: 
							// rule labels: retval
							// token list labels: 
							// rule list labels: 
							// wildcard labels: 
							if ( state.backtracking==0 ) {

							retval.tree = root_0;
							RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

							root_0 = (CommonTree)adaptor.nil();
							// 726:13: -> ^( ANNOTATION_METHOD_DECL modifierList type IDENT ( annotationDefaultValue )? )
							{
								// Java.g:726:17: ^( ANNOTATION_METHOD_DECL modifierList type IDENT ( annotationDefaultValue )? )
								{
								CommonTree root_1 = (CommonTree)adaptor.nil();
								root_1 = (CommonTree)adaptor.becomeRoot(
								(CommonTree)adaptor.create(ANNOTATION_METHOD_DECL, "ANNOTATION_METHOD_DECL")
								, root_1);

								adaptor.addChild(root_1, stream_modifierList.nextTree());

								adaptor.addChild(root_1, stream_type.nextTree());

								adaptor.addChild(root_1, 
								stream_IDENT.nextNode()
								);

								// Java.g:726:66: ( annotationDefaultValue )?
								if ( stream_annotationDefaultValue.hasNext() ) {
									adaptor.addChild(root_1, stream_annotationDefaultValue.nextTree());

								}
								stream_annotationDefaultValue.reset();

								adaptor.addChild(root_0, root_1);
								}

							}


							retval.tree = root_0;
							}

							}
							break;
						case 2 :
							// Java.g:727:13: classFieldDeclaratorList SEMI
							{
							pushFollow(FOLLOW_classFieldDeclaratorList_in_annotationScopeDeclarations8524);
							classFieldDeclaratorList260=classFieldDeclaratorList();
							state._fsp--;
							if (state.failed) return retval;
							if ( state.backtracking==0 ) stream_classFieldDeclaratorList.add(classFieldDeclaratorList260.getTree());
							SEMI261=(Token)match(input,SEMI,FOLLOW_SEMI_in_annotationScopeDeclarations8526); if (state.failed) return retval; 
							if ( state.backtracking==0 ) stream_SEMI.add(SEMI261);

							// AST REWRITE
							// elements: type, modifierList, classFieldDeclaratorList
							// token labels: 
							// rule labels: retval
							// token list labels: 
							// rule list labels: 
							// wildcard labels: 
							if ( state.backtracking==0 ) {

							retval.tree = root_0;
							RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

							root_0 = (CommonTree)adaptor.nil();
							// 728:13: -> ^( VAR_DECLARATION modifierList type classFieldDeclaratorList )
							{
								// Java.g:728:17: ^( VAR_DECLARATION modifierList type classFieldDeclaratorList )
								{
								CommonTree root_1 = (CommonTree)adaptor.nil();
								root_1 = (CommonTree)adaptor.becomeRoot(
								(CommonTree)adaptor.create(VAR_DECLARATION, "VAR_DECLARATION")
								, root_1);

								adaptor.addChild(root_1, stream_modifierList.nextTree());

								adaptor.addChild(root_1, stream_type.nextTree());

								adaptor.addChild(root_1, stream_classFieldDeclaratorList.nextTree());

								adaptor.addChild(root_0, root_1);
								}

							}


							retval.tree = root_0;
							}

							}
							break;

					}

					}
					break;
				case 2 :
					// Java.g:730:9: typeDeclaration
					{
					root_0 = (CommonTree)adaptor.nil();


					pushFollow(FOLLOW_typeDeclaration_in_annotationScopeDeclarations8571);
					typeDeclaration262=typeDeclaration();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) adaptor.addChild(root_0, typeDeclaration262.getTree());

					}
					break;

			}
			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 70, annotationScopeDeclarations_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "annotationScopeDeclarations"


	public static class annotationDefaultValue_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "annotationDefaultValue"
	// Java.g:733:1: annotationDefaultValue : DEFAULT ^ annotationElementValue ;
	public final JavaParser.annotationDefaultValue_return annotationDefaultValue() throws RecognitionException {
		JavaParser.annotationDefaultValue_return retval = new JavaParser.annotationDefaultValue_return();
		retval.start = input.LT(1);
		int annotationDefaultValue_StartIndex = input.index();

		CommonTree root_0 = null;

		Token DEFAULT263=null;
		ParserRuleReturnScope annotationElementValue264 =null;

		CommonTree DEFAULT263_tree=null;

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 71) ) { return retval; }

			// Java.g:734:5: ( DEFAULT ^ annotationElementValue )
			// Java.g:734:9: DEFAULT ^ annotationElementValue
			{
			root_0 = (CommonTree)adaptor.nil();


			DEFAULT263=(Token)match(input,DEFAULT,FOLLOW_DEFAULT_in_annotationDefaultValue8594); if (state.failed) return retval;
			if ( state.backtracking==0 ) {
			DEFAULT263_tree = 
			(CommonTree)adaptor.create(DEFAULT263)
			;
			root_0 = (CommonTree)adaptor.becomeRoot(DEFAULT263_tree, root_0);
			}

			pushFollow(FOLLOW_annotationElementValue_in_annotationDefaultValue8597);
			annotationElementValue264=annotationElementValue();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) adaptor.addChild(root_0, annotationElementValue264.getTree());

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 71, annotationDefaultValue_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "annotationDefaultValue"


	public static class block_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "block"
	// Java.g:739:1: block : LCURLY ( blockStatement )* RCURLY -> ^( BLOCK_SCOPE[$LCURLY, \"BLOCK_SCOPE\"] ( blockStatement )* ) ;
	public final JavaParser.block_return block() throws RecognitionException {
		JavaParser.block_return retval = new JavaParser.block_return();
		retval.start = input.LT(1);
		int block_StartIndex = input.index();

		CommonTree root_0 = null;

		Token LCURLY265=null;
		Token RCURLY267=null;
		ParserRuleReturnScope blockStatement266 =null;

		CommonTree LCURLY265_tree=null;
		CommonTree RCURLY267_tree=null;
		RewriteRuleTokenStream stream_LCURLY=new RewriteRuleTokenStream(adaptor,"token LCURLY");
		RewriteRuleTokenStream stream_RCURLY=new RewriteRuleTokenStream(adaptor,"token RCURLY");
		RewriteRuleSubtreeStream stream_blockStatement=new RewriteRuleSubtreeStream(adaptor,"rule blockStatement");

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 72) ) { return retval; }

			// Java.g:740:5: ( LCURLY ( blockStatement )* RCURLY -> ^( BLOCK_SCOPE[$LCURLY, \"BLOCK_SCOPE\"] ( blockStatement )* ) )
			// Java.g:740:9: LCURLY ( blockStatement )* RCURLY
			{
			LCURLY265=(Token)match(input,LCURLY,FOLLOW_LCURLY_in_block8618); if (state.failed) return retval; 
			if ( state.backtracking==0 ) stream_LCURLY.add(LCURLY265);

			// Java.g:740:16: ( blockStatement )*
			loop87:
			do {
				int alt87=2;
				int LA87_0 = input.LA(1);
				if ( (LA87_0==ABSTRACT||LA87_0==ASSERT||LA87_0==AT||(LA87_0 >= BOOLEAN && LA87_0 <= BYTE)||(LA87_0 >= CHAR && LA87_0 <= CLASS)||(LA87_0 >= CONTINUE && LA87_0 <= DECIMAL_LITERAL)||LA87_0==DO||LA87_0==DOUBLE||LA87_0==ENUM||(LA87_0 >= FALSE && LA87_0 <= FINAL)||(LA87_0 >= FLOAT && LA87_0 <= FLOATING_POINT_LITERAL)||LA87_0==FOR||(LA87_0 >= HEX_LITERAL && LA87_0 <= IF)||LA87_0==INC||LA87_0==INT||LA87_0==INTERFACE||LA87_0==LCURLY||LA87_0==LESS_THAN||LA87_0==LOGICAL_NOT||(LA87_0 >= LONG && LA87_0 <= LPAREN)||LA87_0==MINUS||(LA87_0 >= NATIVE && LA87_0 <= NOT)||LA87_0==NULL||LA87_0==OCTAL_LITERAL||LA87_0==PLUS||(LA87_0 >= PRIVATE && LA87_0 <= PUBLIC)||LA87_0==RETURN||LA87_0==SEMI||LA87_0==SHORT||LA87_0==STATIC||(LA87_0 >= STRICTFP && LA87_0 <= SUPER)||LA87_0==SWITCH||(LA87_0 >= SYNCHRONIZED && LA87_0 <= THIS)||LA87_0==THROW||(LA87_0 >= TRANSIENT && LA87_0 <= TRY)||LA87_0==VOID||(LA87_0 >= VOLATILE && LA87_0 <= WHILE)) ) {
					alt87=1;
				}

				switch (alt87) {
				case 1 :
					// Java.g:740:16: blockStatement
					{
					pushFollow(FOLLOW_blockStatement_in_block8620);
					blockStatement266=blockStatement();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_blockStatement.add(blockStatement266.getTree());
					}
					break;

				default :
					break loop87;
				}
			} while (true);

			RCURLY267=(Token)match(input,RCURLY,FOLLOW_RCURLY_in_block8623); if (state.failed) return retval; 
			if ( state.backtracking==0 ) stream_RCURLY.add(RCURLY267);

			// AST REWRITE
			// elements: blockStatement
			// token labels: 
			// rule labels: retval
			// token list labels: 
			// rule list labels: 
			// wildcard labels: 
			if ( state.backtracking==0 ) {

			retval.tree = root_0;
			RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

			root_0 = (CommonTree)adaptor.nil();
			// 741:9: -> ^( BLOCK_SCOPE[$LCURLY, \"BLOCK_SCOPE\"] ( blockStatement )* )
			{
				// Java.g:741:13: ^( BLOCK_SCOPE[$LCURLY, \"BLOCK_SCOPE\"] ( blockStatement )* )
				{
				CommonTree root_1 = (CommonTree)adaptor.nil();
				root_1 = (CommonTree)adaptor.becomeRoot(
				(CommonTree)adaptor.create(BLOCK_SCOPE, LCURLY265, "BLOCK_SCOPE")
				, root_1);

				// Java.g:741:51: ( blockStatement )*
				while ( stream_blockStatement.hasNext() ) {
					adaptor.addChild(root_1, stream_blockStatement.nextTree());

				}
				stream_blockStatement.reset();

				adaptor.addChild(root_0, root_1);
				}

			}


			retval.tree = root_0;
			}

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 72, block_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "block"


	public static class blockStatement_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "blockStatement"
	// Java.g:744:1: blockStatement : ( localVariableDeclaration SEMI !| typeDeclaration | statement );
	public final JavaParser.blockStatement_return blockStatement() throws RecognitionException {
		JavaParser.blockStatement_return retval = new JavaParser.blockStatement_return();
		retval.start = input.LT(1);
		int blockStatement_StartIndex = input.index();

		CommonTree root_0 = null;

		Token SEMI269=null;
		ParserRuleReturnScope localVariableDeclaration268 =null;
		ParserRuleReturnScope typeDeclaration270 =null;
		ParserRuleReturnScope statement271 =null;

		CommonTree SEMI269_tree=null;

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 73) ) { return retval; }

			// Java.g:745:5: ( localVariableDeclaration SEMI !| typeDeclaration | statement )
			int alt88=3;
			switch ( input.LA(1) ) {
			case FINAL:
				{
				int LA88_1 = input.LA(2);
				if ( (synpred116_Java()) ) {
					alt88=1;
				}
				else if ( (synpred117_Java()) ) {
					alt88=2;
				}
				else {
					if (state.backtracking>0) {state.failed=true; return retval;}
					int nvaeMark = input.mark();
					try {
						input.consume();
						NoViableAltException nvae =
							new NoViableAltException("", 88, 1, input);
						throw nvae;
					} finally {
						input.rewind(nvaeMark);
					}
				}
				}
				break;
			case AT:
				{
				int LA88_2 = input.LA(2);
				if ( (synpred116_Java()) ) {
					alt88=1;
				}
				else if ( (synpred117_Java()) ) {
					alt88=2;
				}
				else {
					if (state.backtracking>0) {state.failed=true; return retval;}
					int nvaeMark = input.mark();
					try {
						input.consume();
						NoViableAltException nvae =
							new NoViableAltException("", 88, 2, input);
						throw nvae;
					} finally {
						input.rewind(nvaeMark);
					}
				}
				}
				break;
			case BOOLEAN:
			case BYTE:
			case CHAR:
			case DOUBLE:
			case FLOAT:
			case INT:
			case LONG:
			case SHORT:
				{
				int LA88_3 = input.LA(2);
				if ( (synpred116_Java()) ) {
					alt88=1;
				}
				else if ( (true) ) {
					alt88=3;
				}
				else {
					if (state.backtracking>0) {state.failed=true; return retval;}
					int nvaeMark = input.mark();
					try {
						input.consume();
						NoViableAltException nvae =
							new NoViableAltException("", 88, 3, input);
						throw nvae;
					} finally {
						input.rewind(nvaeMark);
					}
				}
				}
				break;
			case IDENT:
				{
				int LA88_4 = input.LA(2);
				if ( (synpred116_Java()) ) {
					alt88=1;
				}
				else if ( (true) ) {
					alt88=3;
				}
				else {
					if (state.backtracking>0) {state.failed=true; return retval;}
					int nvaeMark = input.mark();
					try {
						input.consume();
						NoViableAltException nvae =
							new NoViableAltException("", 88, 4, input);
						throw nvae;
					} finally {
						input.rewind(nvaeMark);
					}
				}
				}
				break;
			case ABSTRACT:
			case CLASS:
			case ENUM:
			case INTERFACE:
			case NATIVE:
			case PRIVATE:
			case PROTECTED:
			case PUBLIC:
			case STATIC:
			case STRICTFP:
			case TRANSIENT:
			case VOLATILE:
				{
				alt88=2;
				}
				break;
			case SYNCHRONIZED:
				{
				int LA88_11 = input.LA(2);
				if ( (synpred117_Java()) ) {
					alt88=2;
				}
				else if ( (true) ) {
					alt88=3;
				}
				else {
					if (state.backtracking>0) {state.failed=true; return retval;}
					int nvaeMark = input.mark();
					try {
						input.consume();
						NoViableAltException nvae =
							new NoViableAltException("", 88, 11, input);
						throw nvae;
					} finally {
						input.rewind(nvaeMark);
					}
				}
				}
				break;
			case ASSERT:
			case BREAK:
			case CHARACTER_LITERAL:
			case CONTINUE:
			case DEC:
			case DECIMAL_LITERAL:
			case DO:
			case FALSE:
			case FLOATING_POINT_LITERAL:
			case FOR:
			case HEX_LITERAL:
			case IF:
			case INC:
			case LCURLY:
			case LESS_THAN:
			case LOGICAL_NOT:
			case LPAREN:
			case MINUS:
			case NEW:
			case NOT:
			case NULL:
			case OCTAL_LITERAL:
			case PLUS:
			case RETURN:
			case SEMI:
			case STRING_LITERAL:
			case SUPER:
			case SWITCH:
			case THIS:
			case THROW:
			case TRUE:
			case TRY:
			case VOID:
			case WHILE:
				{
				alt88=3;
				}
				break;
			default:
				if (state.backtracking>0) {state.failed=true; return retval;}
				NoViableAltException nvae =
					new NoViableAltException("", 88, 0, input);
				throw nvae;
			}
			switch (alt88) {
				case 1 :
					// Java.g:745:9: localVariableDeclaration SEMI !
					{
					root_0 = (CommonTree)adaptor.nil();


					pushFollow(FOLLOW_localVariableDeclaration_in_blockStatement8661);
					localVariableDeclaration268=localVariableDeclaration();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) adaptor.addChild(root_0, localVariableDeclaration268.getTree());

					SEMI269=(Token)match(input,SEMI,FOLLOW_SEMI_in_blockStatement8663); if (state.failed) return retval;
					}
					break;
				case 2 :
					// Java.g:746:9: typeDeclaration
					{
					root_0 = (CommonTree)adaptor.nil();


					pushFollow(FOLLOW_typeDeclaration_in_blockStatement8674);
					typeDeclaration270=typeDeclaration();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) adaptor.addChild(root_0, typeDeclaration270.getTree());

					}
					break;
				case 3 :
					// Java.g:747:9: statement
					{
					root_0 = (CommonTree)adaptor.nil();


					pushFollow(FOLLOW_statement_in_blockStatement8684);
					statement271=statement();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) adaptor.addChild(root_0, statement271.getTree());

					}
					break;

			}
			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 73, blockStatement_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "blockStatement"


	public static class localVariableDeclaration_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "localVariableDeclaration"
	// Java.g:750:1: localVariableDeclaration : localModifierList type classFieldDeclaratorList -> ^( VAR_DECLARATION localModifierList type classFieldDeclaratorList ) ;
	public final JavaParser.localVariableDeclaration_return localVariableDeclaration() throws RecognitionException {
		JavaParser.localVariableDeclaration_return retval = new JavaParser.localVariableDeclaration_return();
		retval.start = input.LT(1);
		int localVariableDeclaration_StartIndex = input.index();

		CommonTree root_0 = null;

		ParserRuleReturnScope localModifierList272 =null;
		ParserRuleReturnScope type273 =null;
		ParserRuleReturnScope classFieldDeclaratorList274 =null;

		RewriteRuleSubtreeStream stream_localModifierList=new RewriteRuleSubtreeStream(adaptor,"rule localModifierList");
		RewriteRuleSubtreeStream stream_type=new RewriteRuleSubtreeStream(adaptor,"rule type");
		RewriteRuleSubtreeStream stream_classFieldDeclaratorList=new RewriteRuleSubtreeStream(adaptor,"rule classFieldDeclaratorList");

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 74) ) { return retval; }

			// Java.g:751:5: ( localModifierList type classFieldDeclaratorList -> ^( VAR_DECLARATION localModifierList type classFieldDeclaratorList ) )
			// Java.g:751:9: localModifierList type classFieldDeclaratorList
			{
			pushFollow(FOLLOW_localModifierList_in_localVariableDeclaration8707);
			localModifierList272=localModifierList();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) stream_localModifierList.add(localModifierList272.getTree());
			pushFollow(FOLLOW_type_in_localVariableDeclaration8709);
			type273=type();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) stream_type.add(type273.getTree());
			pushFollow(FOLLOW_classFieldDeclaratorList_in_localVariableDeclaration8711);
			classFieldDeclaratorList274=classFieldDeclaratorList();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) stream_classFieldDeclaratorList.add(classFieldDeclaratorList274.getTree());
			// AST REWRITE
			// elements: type, classFieldDeclaratorList, localModifierList
			// token labels: 
			// rule labels: retval
			// token list labels: 
			// rule list labels: 
			// wildcard labels: 
			if ( state.backtracking==0 ) {

			retval.tree = root_0;
			RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

			root_0 = (CommonTree)adaptor.nil();
			// 752:9: -> ^( VAR_DECLARATION localModifierList type classFieldDeclaratorList )
			{
				// Java.g:752:13: ^( VAR_DECLARATION localModifierList type classFieldDeclaratorList )
				{
				CommonTree root_1 = (CommonTree)adaptor.nil();
				root_1 = (CommonTree)adaptor.becomeRoot(
				(CommonTree)adaptor.create(VAR_DECLARATION, "VAR_DECLARATION")
				, root_1);

				adaptor.addChild(root_1, stream_localModifierList.nextTree());

				adaptor.addChild(root_1, stream_type.nextTree());

				adaptor.addChild(root_1, stream_classFieldDeclaratorList.nextTree());

				adaptor.addChild(root_0, root_1);
				}

			}


			retval.tree = root_0;
			}

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 74, localVariableDeclaration_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "localVariableDeclaration"


	public static class statement_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "statement"
	// Java.g:756:1: statement : ( block | ASSERT expr1= expression ( COLON expr2= expression SEMI -> ^( ASSERT $expr1 $expr2) | SEMI -> ^( ASSERT $expr1) ) | IF parenthesizedExpression ifStat= statement ( ELSE elseStat= statement -> ^( IF parenthesizedExpression $ifStat $elseStat) | -> ^( IF parenthesizedExpression $ifStat) ) | FOR LPAREN ( forInit SEMI forCondition SEMI forUpdater RPAREN statement -> ^( FOR forInit forCondition forUpdater statement ) | localModifierList type IDENT COLON expression RPAREN statement -> ^( FOR_EACH[$FOR, \"FOR_EACH\"] localModifierList type IDENT expression statement ) ) | WHILE parenthesizedExpression statement -> ^( WHILE parenthesizedExpression statement ) | DO statement WHILE parenthesizedExpression SEMI -> ^( DO statement parenthesizedExpression ) | TRY block ( catches ( finallyClause )? | finallyClause ) -> ^( TRY block ( catches )? ( finallyClause )? ) | SWITCH parenthesizedExpression LCURLY switchBlockLabels RCURLY -> ^( SWITCH parenthesizedExpression switchBlockLabels ) | SYNCHRONIZED parenthesizedExpression block -> ^( SYNCHRONIZED parenthesizedExpression block ) | RETURN ( expression )? SEMI -> ^( RETURN ( expression )? ) | THROW expression SEMI -> ^( THROW expression ) | BREAK ( IDENT )? SEMI -> ^( BREAK ( IDENT )? ) | CONTINUE ( IDENT )? SEMI -> ^( CONTINUE ( IDENT )? ) | IDENT COLON statement -> ^( LABELED_STATEMENT IDENT statement ) | expression SEMI !| SEMI );
	public final JavaParser.statement_return statement() throws RecognitionException {
		JavaParser.statement_return retval = new JavaParser.statement_return();
		retval.start = input.LT(1);
		int statement_StartIndex = input.index();

		CommonTree root_0 = null;

		Token ASSERT276=null;
		Token COLON277=null;
		Token SEMI278=null;
		Token SEMI279=null;
		Token IF280=null;
		Token ELSE282=null;
		Token FOR283=null;
		Token LPAREN284=null;
		Token SEMI286=null;
		Token SEMI288=null;
		Token RPAREN290=null;
		Token IDENT294=null;
		Token COLON295=null;
		Token RPAREN297=null;
		Token WHILE299=null;
		Token DO302=null;
		Token WHILE304=null;
		Token SEMI306=null;
		Token TRY307=null;
		Token SWITCH312=null;
		Token LCURLY314=null;
		Token RCURLY316=null;
		Token SYNCHRONIZED317=null;
		Token RETURN320=null;
		Token SEMI322=null;
		Token THROW323=null;
		Token SEMI325=null;
		Token BREAK326=null;
		Token IDENT327=null;
		Token SEMI328=null;
		Token CONTINUE329=null;
		Token IDENT330=null;
		Token SEMI331=null;
		Token IDENT332=null;
		Token COLON333=null;
		Token SEMI336=null;
		Token SEMI337=null;
		ParserRuleReturnScope expr1 =null;
		ParserRuleReturnScope expr2 =null;
		ParserRuleReturnScope ifStat =null;
		ParserRuleReturnScope elseStat =null;
		ParserRuleReturnScope block275 =null;
		ParserRuleReturnScope parenthesizedExpression281 =null;
		ParserRuleReturnScope forInit285 =null;
		ParserRuleReturnScope forCondition287 =null;
		ParserRuleReturnScope forUpdater289 =null;
		ParserRuleReturnScope statement291 =null;
		ParserRuleReturnScope localModifierList292 =null;
		ParserRuleReturnScope type293 =null;
		ParserRuleReturnScope expression296 =null;
		ParserRuleReturnScope statement298 =null;
		ParserRuleReturnScope parenthesizedExpression300 =null;
		ParserRuleReturnScope statement301 =null;
		ParserRuleReturnScope statement303 =null;
		ParserRuleReturnScope parenthesizedExpression305 =null;
		ParserRuleReturnScope block308 =null;
		ParserRuleReturnScope catches309 =null;
		ParserRuleReturnScope finallyClause310 =null;
		ParserRuleReturnScope finallyClause311 =null;
		ParserRuleReturnScope parenthesizedExpression313 =null;
		ParserRuleReturnScope switchBlockLabels315 =null;
		ParserRuleReturnScope parenthesizedExpression318 =null;
		ParserRuleReturnScope block319 =null;
		ParserRuleReturnScope expression321 =null;
		ParserRuleReturnScope expression324 =null;
		ParserRuleReturnScope statement334 =null;
		ParserRuleReturnScope expression335 =null;

		CommonTree ASSERT276_tree=null;
		CommonTree COLON277_tree=null;
		CommonTree SEMI278_tree=null;
		CommonTree SEMI279_tree=null;
		CommonTree IF280_tree=null;
		CommonTree ELSE282_tree=null;
		CommonTree FOR283_tree=null;
		CommonTree LPAREN284_tree=null;
		CommonTree SEMI286_tree=null;
		CommonTree SEMI288_tree=null;
		CommonTree RPAREN290_tree=null;
		CommonTree IDENT294_tree=null;
		CommonTree COLON295_tree=null;
		CommonTree RPAREN297_tree=null;
		CommonTree WHILE299_tree=null;
		CommonTree DO302_tree=null;
		CommonTree WHILE304_tree=null;
		CommonTree SEMI306_tree=null;
		CommonTree TRY307_tree=null;
		CommonTree SWITCH312_tree=null;
		CommonTree LCURLY314_tree=null;
		CommonTree RCURLY316_tree=null;
		CommonTree SYNCHRONIZED317_tree=null;
		CommonTree RETURN320_tree=null;
		CommonTree SEMI322_tree=null;
		CommonTree THROW323_tree=null;
		CommonTree SEMI325_tree=null;
		CommonTree BREAK326_tree=null;
		CommonTree IDENT327_tree=null;
		CommonTree SEMI328_tree=null;
		CommonTree CONTINUE329_tree=null;
		CommonTree IDENT330_tree=null;
		CommonTree SEMI331_tree=null;
		CommonTree IDENT332_tree=null;
		CommonTree COLON333_tree=null;
		CommonTree SEMI336_tree=null;
		CommonTree SEMI337_tree=null;
		RewriteRuleTokenStream stream_COLON=new RewriteRuleTokenStream(adaptor,"token COLON");
		RewriteRuleTokenStream stream_RPAREN=new RewriteRuleTokenStream(adaptor,"token RPAREN");
		RewriteRuleTokenStream stream_SYNCHRONIZED=new RewriteRuleTokenStream(adaptor,"token SYNCHRONIZED");
		RewriteRuleTokenStream stream_WHILE=new RewriteRuleTokenStream(adaptor,"token WHILE");
		RewriteRuleTokenStream stream_CONTINUE=new RewriteRuleTokenStream(adaptor,"token CONTINUE");
		RewriteRuleTokenStream stream_SWITCH=new RewriteRuleTokenStream(adaptor,"token SWITCH");
		RewriteRuleTokenStream stream_RCURLY=new RewriteRuleTokenStream(adaptor,"token RCURLY");
		RewriteRuleTokenStream stream_ELSE=new RewriteRuleTokenStream(adaptor,"token ELSE");
		RewriteRuleTokenStream stream_RETURN=new RewriteRuleTokenStream(adaptor,"token RETURN");
		RewriteRuleTokenStream stream_IDENT=new RewriteRuleTokenStream(adaptor,"token IDENT");
		RewriteRuleTokenStream stream_FOR=new RewriteRuleTokenStream(adaptor,"token FOR");
		RewriteRuleTokenStream stream_DO=new RewriteRuleTokenStream(adaptor,"token DO");
		RewriteRuleTokenStream stream_LCURLY=new RewriteRuleTokenStream(adaptor,"token LCURLY");
		RewriteRuleTokenStream stream_SEMI=new RewriteRuleTokenStream(adaptor,"token SEMI");
		RewriteRuleTokenStream stream_ASSERT=new RewriteRuleTokenStream(adaptor,"token ASSERT");
		RewriteRuleTokenStream stream_BREAK=new RewriteRuleTokenStream(adaptor,"token BREAK");
		RewriteRuleTokenStream stream_THROW=new RewriteRuleTokenStream(adaptor,"token THROW");
		RewriteRuleTokenStream stream_TRY=new RewriteRuleTokenStream(adaptor,"token TRY");
		RewriteRuleTokenStream stream_LPAREN=new RewriteRuleTokenStream(adaptor,"token LPAREN");
		RewriteRuleTokenStream stream_IF=new RewriteRuleTokenStream(adaptor,"token IF");
		RewriteRuleSubtreeStream stream_statement=new RewriteRuleSubtreeStream(adaptor,"rule statement");
		RewriteRuleSubtreeStream stream_expression=new RewriteRuleSubtreeStream(adaptor,"rule expression");
		RewriteRuleSubtreeStream stream_finallyClause=new RewriteRuleSubtreeStream(adaptor,"rule finallyClause");
		RewriteRuleSubtreeStream stream_catches=new RewriteRuleSubtreeStream(adaptor,"rule catches");
		RewriteRuleSubtreeStream stream_forUpdater=new RewriteRuleSubtreeStream(adaptor,"rule forUpdater");
		RewriteRuleSubtreeStream stream_block=new RewriteRuleSubtreeStream(adaptor,"rule block");
		RewriteRuleSubtreeStream stream_forCondition=new RewriteRuleSubtreeStream(adaptor,"rule forCondition");
		RewriteRuleSubtreeStream stream_localModifierList=new RewriteRuleSubtreeStream(adaptor,"rule localModifierList");
		RewriteRuleSubtreeStream stream_forInit=new RewriteRuleSubtreeStream(adaptor,"rule forInit");
		RewriteRuleSubtreeStream stream_type=new RewriteRuleSubtreeStream(adaptor,"rule type");
		RewriteRuleSubtreeStream stream_switchBlockLabels=new RewriteRuleSubtreeStream(adaptor,"rule switchBlockLabels");
		RewriteRuleSubtreeStream stream_parenthesizedExpression=new RewriteRuleSubtreeStream(adaptor,"rule parenthesizedExpression");

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 75) ) { return retval; }

			// Java.g:757:5: ( block | ASSERT expr1= expression ( COLON expr2= expression SEMI -> ^( ASSERT $expr1 $expr2) | SEMI -> ^( ASSERT $expr1) ) | IF parenthesizedExpression ifStat= statement ( ELSE elseStat= statement -> ^( IF parenthesizedExpression $ifStat $elseStat) | -> ^( IF parenthesizedExpression $ifStat) ) | FOR LPAREN ( forInit SEMI forCondition SEMI forUpdater RPAREN statement -> ^( FOR forInit forCondition forUpdater statement ) | localModifierList type IDENT COLON expression RPAREN statement -> ^( FOR_EACH[$FOR, \"FOR_EACH\"] localModifierList type IDENT expression statement ) ) | WHILE parenthesizedExpression statement -> ^( WHILE parenthesizedExpression statement ) | DO statement WHILE parenthesizedExpression SEMI -> ^( DO statement parenthesizedExpression ) | TRY block ( catches ( finallyClause )? | finallyClause ) -> ^( TRY block ( catches )? ( finallyClause )? ) | SWITCH parenthesizedExpression LCURLY switchBlockLabels RCURLY -> ^( SWITCH parenthesizedExpression switchBlockLabels ) | SYNCHRONIZED parenthesizedExpression block -> ^( SYNCHRONIZED parenthesizedExpression block ) | RETURN ( expression )? SEMI -> ^( RETURN ( expression )? ) | THROW expression SEMI -> ^( THROW expression ) | BREAK ( IDENT )? SEMI -> ^( BREAK ( IDENT )? ) | CONTINUE ( IDENT )? SEMI -> ^( CONTINUE ( IDENT )? ) | IDENT COLON statement -> ^( LABELED_STATEMENT IDENT statement ) | expression SEMI !| SEMI )
			int alt97=16;
			switch ( input.LA(1) ) {
			case LCURLY:
				{
				alt97=1;
				}
				break;
			case ASSERT:
				{
				alt97=2;
				}
				break;
			case IF:
				{
				alt97=3;
				}
				break;
			case FOR:
				{
				alt97=4;
				}
				break;
			case WHILE:
				{
				alt97=5;
				}
				break;
			case DO:
				{
				alt97=6;
				}
				break;
			case TRY:
				{
				alt97=7;
				}
				break;
			case SWITCH:
				{
				alt97=8;
				}
				break;
			case SYNCHRONIZED:
				{
				alt97=9;
				}
				break;
			case RETURN:
				{
				alt97=10;
				}
				break;
			case THROW:
				{
				alt97=11;
				}
				break;
			case BREAK:
				{
				alt97=12;
				}
				break;
			case CONTINUE:
				{
				alt97=13;
				}
				break;
			case IDENT:
				{
				int LA97_14 = input.LA(2);
				if ( (LA97_14==COLON) ) {
					alt97=14;
				}
				else if ( ((LA97_14 >= AND && LA97_14 <= AND_ASSIGN)||LA97_14==ASSIGN||(LA97_14 >= BIT_SHIFT_RIGHT && LA97_14 <= BIT_SHIFT_RIGHT_ASSIGN)||LA97_14==DEC||(LA97_14 >= DIV && LA97_14 <= DIV_ASSIGN)||LA97_14==DOT||LA97_14==EQUAL||(LA97_14 >= GREATER_OR_EQUAL && LA97_14 <= GREATER_THAN)||(LA97_14 >= INC && LA97_14 <= INSTANCEOF)||LA97_14==LBRACK||(LA97_14 >= LESS_OR_EQUAL && LA97_14 <= LESS_THAN)||LA97_14==LOGICAL_AND||LA97_14==LOGICAL_OR||LA97_14==LPAREN||(LA97_14 >= MINUS && LA97_14 <= MOD)||LA97_14==MOD_ASSIGN||LA97_14==NOT_EQUAL||(LA97_14 >= OR && LA97_14 <= OR_ASSIGN)||(LA97_14 >= PLUS && LA97_14 <= PLUS_ASSIGN)||LA97_14==QUESTION||(LA97_14 >= SEMI && LA97_14 <= SHIFT_RIGHT_ASSIGN)||(LA97_14 >= STAR && LA97_14 <= STAR_ASSIGN)||(LA97_14 >= XOR && LA97_14 <= XOR_ASSIGN)) ) {
					alt97=15;
				}
				else {
					if (state.backtracking>0) {state.failed=true; return retval;}
					int nvaeMark = input.mark();
					try {
						input.consume();
						NoViableAltException nvae =
							new NoViableAltException("", 97, 14, input);
						throw nvae;
					} finally {
						input.rewind(nvaeMark);
					}
				}
				}
				break;
			case BOOLEAN:
			case BYTE:
			case CHAR:
			case CHARACTER_LITERAL:
			case DEC:
			case DECIMAL_LITERAL:
			case DOUBLE:
			case FALSE:
			case FLOAT:
			case FLOATING_POINT_LITERAL:
			case HEX_LITERAL:
			case INC:
			case INT:
			case LESS_THAN:
			case LOGICAL_NOT:
			case LONG:
			case LPAREN:
			case MINUS:
			case NEW:
			case NOT:
			case NULL:
			case OCTAL_LITERAL:
			case PLUS:
			case SHORT:
			case STRING_LITERAL:
			case SUPER:
			case THIS:
			case TRUE:
			case VOID:
				{
				alt97=15;
				}
				break;
			case SEMI:
				{
				alt97=16;
				}
				break;
			default:
				if (state.backtracking>0) {state.failed=true; return retval;}
				NoViableAltException nvae =
					new NoViableAltException("", 97, 0, input);
				throw nvae;
			}
			switch (alt97) {
				case 1 :
					// Java.g:757:9: block
					{
					root_0 = (CommonTree)adaptor.nil();


					pushFollow(FOLLOW_block_in_statement8764);
					block275=block();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) adaptor.addChild(root_0, block275.getTree());

					}
					break;
				case 2 :
					// Java.g:758:9: ASSERT expr1= expression ( COLON expr2= expression SEMI -> ^( ASSERT $expr1 $expr2) | SEMI -> ^( ASSERT $expr1) )
					{
					ASSERT276=(Token)match(input,ASSERT,FOLLOW_ASSERT_in_statement8774); if (state.failed) return retval; 
					if ( state.backtracking==0 ) stream_ASSERT.add(ASSERT276);

					pushFollow(FOLLOW_expression_in_statement8778);
					expr1=expression();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_expression.add(expr1.getTree());
					// Java.g:759:9: ( COLON expr2= expression SEMI -> ^( ASSERT $expr1 $expr2) | SEMI -> ^( ASSERT $expr1) )
					int alt89=2;
					int LA89_0 = input.LA(1);
					if ( (LA89_0==COLON) ) {
						alt89=1;
					}
					else if ( (LA89_0==SEMI) ) {
						alt89=2;
					}
					else {
						if (state.backtracking>0) {state.failed=true; return retval;}
						NoViableAltException nvae =
							new NoViableAltException("", 89, 0, input);
						throw nvae;
					}
					switch (alt89) {
						case 1 :
							// Java.g:759:13: COLON expr2= expression SEMI
							{
							COLON277=(Token)match(input,COLON,FOLLOW_COLON_in_statement8793); if (state.failed) return retval; 
							if ( state.backtracking==0 ) stream_COLON.add(COLON277);

							pushFollow(FOLLOW_expression_in_statement8797);
							expr2=expression();
							state._fsp--;
							if (state.failed) return retval;
							if ( state.backtracking==0 ) stream_expression.add(expr2.getTree());
							SEMI278=(Token)match(input,SEMI,FOLLOW_SEMI_in_statement8799); if (state.failed) return retval; 
							if ( state.backtracking==0 ) stream_SEMI.add(SEMI278);

							// AST REWRITE
							// elements: expr2, ASSERT, expr1
							// token labels: 
							// rule labels: retval, expr1, expr2
							// token list labels: 
							// rule list labels: 
							// wildcard labels: 
							if ( state.backtracking==0 ) {

							retval.tree = root_0;
							RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);
							RewriteRuleSubtreeStream stream_expr1=new RewriteRuleSubtreeStream(adaptor,"rule expr1",expr1!=null?expr1.getTree():null);
							RewriteRuleSubtreeStream stream_expr2=new RewriteRuleSubtreeStream(adaptor,"rule expr2",expr2!=null?expr2.getTree():null);

							root_0 = (CommonTree)adaptor.nil();
							// 759:77: -> ^( ASSERT $expr1 $expr2)
							{
								// Java.g:759:81: ^( ASSERT $expr1 $expr2)
								{
								CommonTree root_1 = (CommonTree)adaptor.nil();
								root_1 = (CommonTree)adaptor.becomeRoot(
								stream_ASSERT.nextNode()
								, root_1);

								adaptor.addChild(root_1, stream_expr1.nextTree());

								adaptor.addChild(root_1, stream_expr2.nextTree());

								adaptor.addChild(root_0, root_1);
								}

							}


							retval.tree = root_0;
							}

							}
							break;
						case 2 :
							// Java.g:760:13: SEMI
							{
							SEMI279=(Token)match(input,SEMI,FOLLOW_SEMI_in_statement8862); if (state.failed) return retval; 
							if ( state.backtracking==0 ) stream_SEMI.add(SEMI279);

							// AST REWRITE
							// elements: expr1, ASSERT
							// token labels: 
							// rule labels: retval, expr1
							// token list labels: 
							// rule list labels: 
							// wildcard labels: 
							if ( state.backtracking==0 ) {

							retval.tree = root_0;
							RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);
							RewriteRuleSubtreeStream stream_expr1=new RewriteRuleSubtreeStream(adaptor,"rule expr1",expr1!=null?expr1.getTree():null);

							root_0 = (CommonTree)adaptor.nil();
							// 760:77: -> ^( ASSERT $expr1)
							{
								// Java.g:760:81: ^( ASSERT $expr1)
								{
								CommonTree root_1 = (CommonTree)adaptor.nil();
								root_1 = (CommonTree)adaptor.becomeRoot(
								stream_ASSERT.nextNode()
								, root_1);

								adaptor.addChild(root_1, stream_expr1.nextTree());

								adaptor.addChild(root_0, root_1);
								}

							}


							retval.tree = root_0;
							}

							}
							break;

					}

					}
					break;
				case 3 :
					// Java.g:762:9: IF parenthesizedExpression ifStat= statement ( ELSE elseStat= statement -> ^( IF parenthesizedExpression $ifStat $elseStat) | -> ^( IF parenthesizedExpression $ifStat) )
					{
					IF280=(Token)match(input,IF,FOLLOW_IF_in_statement8951); if (state.failed) return retval; 
					if ( state.backtracking==0 ) stream_IF.add(IF280);

					pushFollow(FOLLOW_parenthesizedExpression_in_statement8953);
					parenthesizedExpression281=parenthesizedExpression();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_parenthesizedExpression.add(parenthesizedExpression281.getTree());
					pushFollow(FOLLOW_statement_in_statement8957);
					ifStat=statement();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_statement.add(ifStat.getTree());
					// Java.g:763:9: ( ELSE elseStat= statement -> ^( IF parenthesizedExpression $ifStat $elseStat) | -> ^( IF parenthesizedExpression $ifStat) )
					int alt90=2;
					int LA90_0 = input.LA(1);
					if ( (LA90_0==ELSE) ) {
						int LA90_1 = input.LA(2);
						if ( (synpred121_Java()) ) {
							alt90=1;
						}
						else if ( (true) ) {
							alt90=2;
						}
						else {
							if (state.backtracking>0) {state.failed=true; return retval;}
							int nvaeMark = input.mark();
							try {
								input.consume();
								NoViableAltException nvae =
									new NoViableAltException("", 90, 1, input);
								throw nvae;
							} finally {
								input.rewind(nvaeMark);
							}
						}
					}
					else if ( (LA90_0==EOF||LA90_0==ABSTRACT||LA90_0==ASSERT||LA90_0==AT||(LA90_0 >= BOOLEAN && LA90_0 <= CASE)||(LA90_0 >= CHAR && LA90_0 <= CLASS)||(LA90_0 >= CONTINUE && LA90_0 <= DEFAULT)||LA90_0==DO||LA90_0==DOUBLE||LA90_0==ENUM||(LA90_0 >= FALSE && LA90_0 <= FINAL)||(LA90_0 >= FLOAT && LA90_0 <= FLOATING_POINT_LITERAL)||LA90_0==FOR||(LA90_0 >= HEX_LITERAL && LA90_0 <= IF)||LA90_0==INC||LA90_0==INT||LA90_0==INTERFACE||LA90_0==LCURLY||LA90_0==LESS_THAN||LA90_0==LOGICAL_NOT||(LA90_0 >= LONG && LA90_0 <= LPAREN)||LA90_0==MINUS||(LA90_0 >= NATIVE && LA90_0 <= NOT)||LA90_0==NULL||LA90_0==OCTAL_LITERAL||LA90_0==PLUS||(LA90_0 >= PRIVATE && LA90_0 <= PUBLIC)||(LA90_0 >= RCURLY && LA90_0 <= RETURN)||LA90_0==SEMI||LA90_0==SHORT||LA90_0==STATIC||(LA90_0 >= STRICTFP && LA90_0 <= SUPER)||LA90_0==SWITCH||(LA90_0 >= SYNCHRONIZED && LA90_0 <= THIS)||LA90_0==THROW||(LA90_0 >= TRANSIENT && LA90_0 <= TRY)||LA90_0==VOID||(LA90_0 >= VOLATILE && LA90_0 <= WHILE)) ) {
						alt90=2;
					}
					else {
						if (state.backtracking>0) {state.failed=true; return retval;}
						NoViableAltException nvae =
							new NoViableAltException("", 90, 0, input);
						throw nvae;
					}
					switch (alt90) {
						case 1 :
							// Java.g:763:13: ELSE elseStat= statement
							{
							ELSE282=(Token)match(input,ELSE,FOLLOW_ELSE_in_statement8972); if (state.failed) return retval; 
							if ( state.backtracking==0 ) stream_ELSE.add(ELSE282);

							pushFollow(FOLLOW_statement_in_statement8976);
							elseStat=statement();
							state._fsp--;
							if (state.failed) return retval;
							if ( state.backtracking==0 ) stream_statement.add(elseStat.getTree());
							// AST REWRITE
							// elements: parenthesizedExpression, elseStat, ifStat, IF
							// token labels: 
							// rule labels: retval, ifStat, elseStat
							// token list labels: 
							// rule list labels: 
							// wildcard labels: 
							if ( state.backtracking==0 ) {

							retval.tree = root_0;
							RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);
							RewriteRuleSubtreeStream stream_ifStat=new RewriteRuleSubtreeStream(adaptor,"rule ifStat",ifStat!=null?ifStat.getTree():null);
							RewriteRuleSubtreeStream stream_elseStat=new RewriteRuleSubtreeStream(adaptor,"rule elseStat",elseStat!=null?elseStat.getTree():null);

							root_0 = (CommonTree)adaptor.nil();
							// 763:77: -> ^( IF parenthesizedExpression $ifStat $elseStat)
							{
								// Java.g:763:81: ^( IF parenthesizedExpression $ifStat $elseStat)
								{
								CommonTree root_1 = (CommonTree)adaptor.nil();
								root_1 = (CommonTree)adaptor.becomeRoot(
								stream_IF.nextNode()
								, root_1);

								adaptor.addChild(root_1, stream_parenthesizedExpression.nextTree());

								adaptor.addChild(root_1, stream_ifStat.nextTree());

								adaptor.addChild(root_1, stream_elseStat.nextTree());

								adaptor.addChild(root_0, root_1);
								}

							}


							retval.tree = root_0;
							}

							}
							break;
						case 2 :
							// Java.g:764:77: 
							{
							// AST REWRITE
							// elements: IF, ifStat, parenthesizedExpression
							// token labels: 
							// rule labels: retval, ifStat
							// token list labels: 
							// rule list labels: 
							// wildcard labels: 
							if ( state.backtracking==0 ) {

							retval.tree = root_0;
							RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);
							RewriteRuleSubtreeStream stream_ifStat=new RewriteRuleSubtreeStream(adaptor,"rule ifStat",ifStat!=null?ifStat.getTree():null);

							root_0 = (CommonTree)adaptor.nil();
							// 764:77: -> ^( IF parenthesizedExpression $ifStat)
							{
								// Java.g:764:81: ^( IF parenthesizedExpression $ifStat)
								{
								CommonTree root_1 = (CommonTree)adaptor.nil();
								root_1 = (CommonTree)adaptor.becomeRoot(
								stream_IF.nextNode()
								, root_1);

								adaptor.addChild(root_1, stream_parenthesizedExpression.nextTree());

								adaptor.addChild(root_1, stream_ifStat.nextTree());

								adaptor.addChild(root_0, root_1);
								}

							}


							retval.tree = root_0;
							}

							}
							break;

					}

					}
					break;
				case 4 :
					// Java.g:766:9: FOR LPAREN ( forInit SEMI forCondition SEMI forUpdater RPAREN statement -> ^( FOR forInit forCondition forUpdater statement ) | localModifierList type IDENT COLON expression RPAREN statement -> ^( FOR_EACH[$FOR, \"FOR_EACH\"] localModifierList type IDENT expression statement ) )
					{
					FOR283=(Token)match(input,FOR,FOLLOW_FOR_in_statement9142); if (state.failed) return retval; 
					if ( state.backtracking==0 ) stream_FOR.add(FOR283);

					LPAREN284=(Token)match(input,LPAREN,FOLLOW_LPAREN_in_statement9144); if (state.failed) return retval; 
					if ( state.backtracking==0 ) stream_LPAREN.add(LPAREN284);

					// Java.g:767:9: ( forInit SEMI forCondition SEMI forUpdater RPAREN statement -> ^( FOR forInit forCondition forUpdater statement ) | localModifierList type IDENT COLON expression RPAREN statement -> ^( FOR_EACH[$FOR, \"FOR_EACH\"] localModifierList type IDENT expression statement ) )
					int alt91=2;
					switch ( input.LA(1) ) {
					case FINAL:
						{
						int LA91_1 = input.LA(2);
						if ( (synpred123_Java()) ) {
							alt91=1;
						}
						else if ( (true) ) {
							alt91=2;
						}
						else {
							if (state.backtracking>0) {state.failed=true; return retval;}
							int nvaeMark = input.mark();
							try {
								input.consume();
								NoViableAltException nvae =
									new NoViableAltException("", 91, 1, input);
								throw nvae;
							} finally {
								input.rewind(nvaeMark);
							}
						}
						}
						break;
					case AT:
						{
						int LA91_2 = input.LA(2);
						if ( (synpred123_Java()) ) {
							alt91=1;
						}
						else if ( (true) ) {
							alt91=2;
						}
						else {
							if (state.backtracking>0) {state.failed=true; return retval;}
							int nvaeMark = input.mark();
							try {
								input.consume();
								NoViableAltException nvae =
									new NoViableAltException("", 91, 2, input);
								throw nvae;
							} finally {
								input.rewind(nvaeMark);
							}
						}
						}
						break;
					case BOOLEAN:
					case BYTE:
					case CHAR:
					case DOUBLE:
					case FLOAT:
					case INT:
					case LONG:
					case SHORT:
						{
						int LA91_3 = input.LA(2);
						if ( (synpred123_Java()) ) {
							alt91=1;
						}
						else if ( (true) ) {
							alt91=2;
						}
						else {
							if (state.backtracking>0) {state.failed=true; return retval;}
							int nvaeMark = input.mark();
							try {
								input.consume();
								NoViableAltException nvae =
									new NoViableAltException("", 91, 3, input);
								throw nvae;
							} finally {
								input.rewind(nvaeMark);
							}
						}
						}
						break;
					case IDENT:
						{
						int LA91_4 = input.LA(2);
						if ( (synpred123_Java()) ) {
							alt91=1;
						}
						else if ( (true) ) {
							alt91=2;
						}
						else {
							if (state.backtracking>0) {state.failed=true; return retval;}
							int nvaeMark = input.mark();
							try {
								input.consume();
								NoViableAltException nvae =
									new NoViableAltException("", 91, 4, input);
								throw nvae;
							} finally {
								input.rewind(nvaeMark);
							}
						}
						}
						break;
					case CHARACTER_LITERAL:
					case DEC:
					case DECIMAL_LITERAL:
					case FALSE:
					case FLOATING_POINT_LITERAL:
					case HEX_LITERAL:
					case INC:
					case LESS_THAN:
					case LOGICAL_NOT:
					case LPAREN:
					case MINUS:
					case NEW:
					case NOT:
					case NULL:
					case OCTAL_LITERAL:
					case PLUS:
					case SEMI:
					case STRING_LITERAL:
					case SUPER:
					case THIS:
					case TRUE:
					case VOID:
						{
						alt91=1;
						}
						break;
					default:
						if (state.backtracking>0) {state.failed=true; return retval;}
						NoViableAltException nvae =
							new NoViableAltException("", 91, 0, input);
						throw nvae;
					}
					switch (alt91) {
						case 1 :
							// Java.g:767:13: forInit SEMI forCondition SEMI forUpdater RPAREN statement
							{
							pushFollow(FOLLOW_forInit_in_statement9159);
							forInit285=forInit();
							state._fsp--;
							if (state.failed) return retval;
							if ( state.backtracking==0 ) stream_forInit.add(forInit285.getTree());
							SEMI286=(Token)match(input,SEMI,FOLLOW_SEMI_in_statement9161); if (state.failed) return retval; 
							if ( state.backtracking==0 ) stream_SEMI.add(SEMI286);

							pushFollow(FOLLOW_forCondition_in_statement9163);
							forCondition287=forCondition();
							state._fsp--;
							if (state.failed) return retval;
							if ( state.backtracking==0 ) stream_forCondition.add(forCondition287.getTree());
							SEMI288=(Token)match(input,SEMI,FOLLOW_SEMI_in_statement9165); if (state.failed) return retval; 
							if ( state.backtracking==0 ) stream_SEMI.add(SEMI288);

							pushFollow(FOLLOW_forUpdater_in_statement9167);
							forUpdater289=forUpdater();
							state._fsp--;
							if (state.failed) return retval;
							if ( state.backtracking==0 ) stream_forUpdater.add(forUpdater289.getTree());
							RPAREN290=(Token)match(input,RPAREN,FOLLOW_RPAREN_in_statement9169); if (state.failed) return retval; 
							if ( state.backtracking==0 ) stream_RPAREN.add(RPAREN290);

							pushFollow(FOLLOW_statement_in_statement9171);
							statement291=statement();
							state._fsp--;
							if (state.failed) return retval;
							if ( state.backtracking==0 ) stream_statement.add(statement291.getTree());
							// AST REWRITE
							// elements: statement, forUpdater, FOR, forCondition, forInit
							// token labels: 
							// rule labels: retval
							// token list labels: 
							// rule list labels: 
							// wildcard labels: 
							if ( state.backtracking==0 ) {

							retval.tree = root_0;
							RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

							root_0 = (CommonTree)adaptor.nil();
							// 767:77: -> ^( FOR forInit forCondition forUpdater statement )
							{
								// Java.g:767:81: ^( FOR forInit forCondition forUpdater statement )
								{
								CommonTree root_1 = (CommonTree)adaptor.nil();
								root_1 = (CommonTree)adaptor.becomeRoot(
								stream_FOR.nextNode()
								, root_1);

								adaptor.addChild(root_1, stream_forInit.nextTree());

								adaptor.addChild(root_1, stream_forCondition.nextTree());

								adaptor.addChild(root_1, stream_forUpdater.nextTree());

								adaptor.addChild(root_1, stream_statement.nextTree());

								adaptor.addChild(root_0, root_1);
								}

							}


							retval.tree = root_0;
							}

							}
							break;
						case 2 :
							// Java.g:768:13: localModifierList type IDENT COLON expression RPAREN statement
							{
							pushFollow(FOLLOW_localModifierList_in_statement9206);
							localModifierList292=localModifierList();
							state._fsp--;
							if (state.failed) return retval;
							if ( state.backtracking==0 ) stream_localModifierList.add(localModifierList292.getTree());
							pushFollow(FOLLOW_type_in_statement9208);
							type293=type();
							state._fsp--;
							if (state.failed) return retval;
							if ( state.backtracking==0 ) stream_type.add(type293.getTree());
							IDENT294=(Token)match(input,IDENT,FOLLOW_IDENT_in_statement9210); if (state.failed) return retval; 
							if ( state.backtracking==0 ) stream_IDENT.add(IDENT294);

							COLON295=(Token)match(input,COLON,FOLLOW_COLON_in_statement9212); if (state.failed) return retval; 
							if ( state.backtracking==0 ) stream_COLON.add(COLON295);

							pushFollow(FOLLOW_expression_in_statement9214);
							expression296=expression();
							state._fsp--;
							if (state.failed) return retval;
							if ( state.backtracking==0 ) stream_expression.add(expression296.getTree());
							RPAREN297=(Token)match(input,RPAREN,FOLLOW_RPAREN_in_statement9216); if (state.failed) return retval; 
							if ( state.backtracking==0 ) stream_RPAREN.add(RPAREN297);

							pushFollow(FOLLOW_statement_in_statement9218);
							statement298=statement();
							state._fsp--;
							if (state.failed) return retval;
							if ( state.backtracking==0 ) stream_statement.add(statement298.getTree());
							// AST REWRITE
							// elements: statement, IDENT, expression, type, localModifierList
							// token labels: 
							// rule labels: retval
							// token list labels: 
							// rule list labels: 
							// wildcard labels: 
							if ( state.backtracking==0 ) {

							retval.tree = root_0;
							RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

							root_0 = (CommonTree)adaptor.nil();
							// 769:77: -> ^( FOR_EACH[$FOR, \"FOR_EACH\"] localModifierList type IDENT expression statement )
							{
								// Java.g:769:81: ^( FOR_EACH[$FOR, \"FOR_EACH\"] localModifierList type IDENT expression statement )
								{
								CommonTree root_1 = (CommonTree)adaptor.nil();
								root_1 = (CommonTree)adaptor.becomeRoot(
								(CommonTree)adaptor.create(FOR_EACH, FOR283, "FOR_EACH")
								, root_1);

								adaptor.addChild(root_1, stream_localModifierList.nextTree());

								adaptor.addChild(root_1, stream_type.nextTree());

								adaptor.addChild(root_1, 
								stream_IDENT.nextNode()
								);

								adaptor.addChild(root_1, stream_expression.nextTree());

								adaptor.addChild(root_1, stream_statement.nextTree());

								adaptor.addChild(root_0, root_1);
								}

							}


							retval.tree = root_0;
							}

							}
							break;

					}

					}
					break;
				case 5 :
					// Java.g:771:9: WHILE parenthesizedExpression statement
					{
					WHILE299=(Token)match(input,WHILE,FOLLOW_WHILE_in_statement9333); if (state.failed) return retval; 
					if ( state.backtracking==0 ) stream_WHILE.add(WHILE299);

					pushFollow(FOLLOW_parenthesizedExpression_in_statement9335);
					parenthesizedExpression300=parenthesizedExpression();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_parenthesizedExpression.add(parenthesizedExpression300.getTree());
					pushFollow(FOLLOW_statement_in_statement9337);
					statement301=statement();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_statement.add(statement301.getTree());
					// AST REWRITE
					// elements: WHILE, statement, parenthesizedExpression
					// token labels: 
					// rule labels: retval
					// token list labels: 
					// rule list labels: 
					// wildcard labels: 
					if ( state.backtracking==0 ) {

					retval.tree = root_0;
					RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

					root_0 = (CommonTree)adaptor.nil();
					// 771:77: -> ^( WHILE parenthesizedExpression statement )
					{
						// Java.g:771:81: ^( WHILE parenthesizedExpression statement )
						{
						CommonTree root_1 = (CommonTree)adaptor.nil();
						root_1 = (CommonTree)adaptor.becomeRoot(
						stream_WHILE.nextNode()
						, root_1);

						adaptor.addChild(root_1, stream_parenthesizedExpression.nextTree());

						adaptor.addChild(root_1, stream_statement.nextTree());

						adaptor.addChild(root_0, root_1);
						}

					}


					retval.tree = root_0;
					}

					}
					break;
				case 6 :
					// Java.g:772:9: DO statement WHILE parenthesizedExpression SEMI
					{
					DO302=(Token)match(input,DO,FOLLOW_DO_in_statement9386); if (state.failed) return retval; 
					if ( state.backtracking==0 ) stream_DO.add(DO302);

					pushFollow(FOLLOW_statement_in_statement9388);
					statement303=statement();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_statement.add(statement303.getTree());
					WHILE304=(Token)match(input,WHILE,FOLLOW_WHILE_in_statement9390); if (state.failed) return retval; 
					if ( state.backtracking==0 ) stream_WHILE.add(WHILE304);

					pushFollow(FOLLOW_parenthesizedExpression_in_statement9392);
					parenthesizedExpression305=parenthesizedExpression();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_parenthesizedExpression.add(parenthesizedExpression305.getTree());
					SEMI306=(Token)match(input,SEMI,FOLLOW_SEMI_in_statement9394); if (state.failed) return retval; 
					if ( state.backtracking==0 ) stream_SEMI.add(SEMI306);

					// AST REWRITE
					// elements: parenthesizedExpression, DO, statement
					// token labels: 
					// rule labels: retval
					// token list labels: 
					// rule list labels: 
					// wildcard labels: 
					if ( state.backtracking==0 ) {

					retval.tree = root_0;
					RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

					root_0 = (CommonTree)adaptor.nil();
					// 772:77: -> ^( DO statement parenthesizedExpression )
					{
						// Java.g:772:81: ^( DO statement parenthesizedExpression )
						{
						CommonTree root_1 = (CommonTree)adaptor.nil();
						root_1 = (CommonTree)adaptor.becomeRoot(
						stream_DO.nextNode()
						, root_1);

						adaptor.addChild(root_1, stream_statement.nextTree());

						adaptor.addChild(root_1, stream_parenthesizedExpression.nextTree());

						adaptor.addChild(root_0, root_1);
						}

					}


					retval.tree = root_0;
					}

					}
					break;
				case 7 :
					// Java.g:773:9: TRY block ( catches ( finallyClause )? | finallyClause )
					{
					TRY307=(Token)match(input,TRY,FOLLOW_TRY_in_statement9435); if (state.failed) return retval; 
					if ( state.backtracking==0 ) stream_TRY.add(TRY307);

					pushFollow(FOLLOW_block_in_statement9437);
					block308=block();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_block.add(block308.getTree());
					// Java.g:773:19: ( catches ( finallyClause )? | finallyClause )
					int alt93=2;
					int LA93_0 = input.LA(1);
					if ( (LA93_0==CATCH) ) {
						alt93=1;
					}
					else if ( (LA93_0==FINALLY) ) {
						alt93=2;
					}
					else {
						if (state.backtracking>0) {state.failed=true; return retval;}
						NoViableAltException nvae =
							new NoViableAltException("", 93, 0, input);
						throw nvae;
					}
					switch (alt93) {
						case 1 :
							// Java.g:773:20: catches ( finallyClause )?
							{
							pushFollow(FOLLOW_catches_in_statement9440);
							catches309=catches();
							state._fsp--;
							if (state.failed) return retval;
							if ( state.backtracking==0 ) stream_catches.add(catches309.getTree());
							// Java.g:773:28: ( finallyClause )?
							int alt92=2;
							int LA92_0 = input.LA(1);
							if ( (LA92_0==FINALLY) ) {
								alt92=1;
							}
							switch (alt92) {
								case 1 :
									// Java.g:773:28: finallyClause
									{
									pushFollow(FOLLOW_finallyClause_in_statement9442);
									finallyClause310=finallyClause();
									state._fsp--;
									if (state.failed) return retval;
									if ( state.backtracking==0 ) stream_finallyClause.add(finallyClause310.getTree());
									}
									break;

							}

							}
							break;
						case 2 :
							// Java.g:773:45: finallyClause
							{
							pushFollow(FOLLOW_finallyClause_in_statement9447);
							finallyClause311=finallyClause();
							state._fsp--;
							if (state.failed) return retval;
							if ( state.backtracking==0 ) stream_finallyClause.add(finallyClause311.getTree());
							}
							break;

					}

					// AST REWRITE
					// elements: finallyClause, catches, block, TRY
					// token labels: 
					// rule labels: retval
					// token list labels: 
					// rule list labels: 
					// wildcard labels: 
					if ( state.backtracking==0 ) {

					retval.tree = root_0;
					RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

					root_0 = (CommonTree)adaptor.nil();
					// 773:77: -> ^( TRY block ( catches )? ( finallyClause )? )
					{
						// Java.g:773:81: ^( TRY block ( catches )? ( finallyClause )? )
						{
						CommonTree root_1 = (CommonTree)adaptor.nil();
						root_1 = (CommonTree)adaptor.becomeRoot(
						stream_TRY.nextNode()
						, root_1);

						adaptor.addChild(root_1, stream_block.nextTree());

						// Java.g:773:93: ( catches )?
						if ( stream_catches.hasNext() ) {
							adaptor.addChild(root_1, stream_catches.nextTree());

						}
						stream_catches.reset();

						// Java.g:773:102: ( finallyClause )?
						if ( stream_finallyClause.hasNext() ) {
							adaptor.addChild(root_1, stream_finallyClause.nextTree());

						}
						stream_finallyClause.reset();

						adaptor.addChild(root_0, root_1);
						}

					}


					retval.tree = root_0;
					}

					}
					break;
				case 8 :
					// Java.g:774:9: SWITCH parenthesizedExpression LCURLY switchBlockLabels RCURLY
					{
					SWITCH312=(Token)match(input,SWITCH,FOLLOW_SWITCH_in_statement9490); if (state.failed) return retval; 
					if ( state.backtracking==0 ) stream_SWITCH.add(SWITCH312);

					pushFollow(FOLLOW_parenthesizedExpression_in_statement9492);
					parenthesizedExpression313=parenthesizedExpression();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_parenthesizedExpression.add(parenthesizedExpression313.getTree());
					LCURLY314=(Token)match(input,LCURLY,FOLLOW_LCURLY_in_statement9494); if (state.failed) return retval; 
					if ( state.backtracking==0 ) stream_LCURLY.add(LCURLY314);

					pushFollow(FOLLOW_switchBlockLabels_in_statement9496);
					switchBlockLabels315=switchBlockLabels();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_switchBlockLabels.add(switchBlockLabels315.getTree());
					RCURLY316=(Token)match(input,RCURLY,FOLLOW_RCURLY_in_statement9498); if (state.failed) return retval; 
					if ( state.backtracking==0 ) stream_RCURLY.add(RCURLY316);

					// AST REWRITE
					// elements: parenthesizedExpression, SWITCH, switchBlockLabels
					// token labels: 
					// rule labels: retval
					// token list labels: 
					// rule list labels: 
					// wildcard labels: 
					if ( state.backtracking==0 ) {

					retval.tree = root_0;
					RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

					root_0 = (CommonTree)adaptor.nil();
					// 774:77: -> ^( SWITCH parenthesizedExpression switchBlockLabels )
					{
						// Java.g:774:81: ^( SWITCH parenthesizedExpression switchBlockLabels )
						{
						CommonTree root_1 = (CommonTree)adaptor.nil();
						root_1 = (CommonTree)adaptor.becomeRoot(
						stream_SWITCH.nextNode()
						, root_1);

						adaptor.addChild(root_1, stream_parenthesizedExpression.nextTree());

						adaptor.addChild(root_1, stream_switchBlockLabels.nextTree());

						adaptor.addChild(root_0, root_1);
						}

					}


					retval.tree = root_0;
					}

					}
					break;
				case 9 :
					// Java.g:775:9: SYNCHRONIZED parenthesizedExpression block
					{
					SYNCHRONIZED317=(Token)match(input,SYNCHRONIZED,FOLLOW_SYNCHRONIZED_in_statement9524); if (state.failed) return retval; 
					if ( state.backtracking==0 ) stream_SYNCHRONIZED.add(SYNCHRONIZED317);

					pushFollow(FOLLOW_parenthesizedExpression_in_statement9526);
					parenthesizedExpression318=parenthesizedExpression();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_parenthesizedExpression.add(parenthesizedExpression318.getTree());
					pushFollow(FOLLOW_block_in_statement9528);
					block319=block();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_block.add(block319.getTree());
					// AST REWRITE
					// elements: SYNCHRONIZED, parenthesizedExpression, block
					// token labels: 
					// rule labels: retval
					// token list labels: 
					// rule list labels: 
					// wildcard labels: 
					if ( state.backtracking==0 ) {

					retval.tree = root_0;
					RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

					root_0 = (CommonTree)adaptor.nil();
					// 775:77: -> ^( SYNCHRONIZED parenthesizedExpression block )
					{
						// Java.g:775:81: ^( SYNCHRONIZED parenthesizedExpression block )
						{
						CommonTree root_1 = (CommonTree)adaptor.nil();
						root_1 = (CommonTree)adaptor.becomeRoot(
						stream_SYNCHRONIZED.nextNode()
						, root_1);

						adaptor.addChild(root_1, stream_parenthesizedExpression.nextTree());

						adaptor.addChild(root_1, stream_block.nextTree());

						adaptor.addChild(root_0, root_1);
						}

					}


					retval.tree = root_0;
					}

					}
					break;
				case 10 :
					// Java.g:776:9: RETURN ( expression )? SEMI
					{
					RETURN320=(Token)match(input,RETURN,FOLLOW_RETURN_in_statement9574); if (state.failed) return retval; 
					if ( state.backtracking==0 ) stream_RETURN.add(RETURN320);

					// Java.g:776:16: ( expression )?
					int alt94=2;
					int LA94_0 = input.LA(1);
					if ( (LA94_0==BOOLEAN||LA94_0==BYTE||(LA94_0 >= CHAR && LA94_0 <= CHARACTER_LITERAL)||(LA94_0 >= DEC && LA94_0 <= DECIMAL_LITERAL)||LA94_0==DOUBLE||LA94_0==FALSE||(LA94_0 >= FLOAT && LA94_0 <= FLOATING_POINT_LITERAL)||(LA94_0 >= HEX_LITERAL && LA94_0 <= IDENT)||LA94_0==INC||LA94_0==INT||LA94_0==LESS_THAN||LA94_0==LOGICAL_NOT||(LA94_0 >= LONG && LA94_0 <= LPAREN)||LA94_0==MINUS||(LA94_0 >= NEW && LA94_0 <= NOT)||LA94_0==NULL||LA94_0==OCTAL_LITERAL||LA94_0==PLUS||LA94_0==SHORT||(LA94_0 >= STRING_LITERAL && LA94_0 <= SUPER)||LA94_0==THIS||LA94_0==TRUE||LA94_0==VOID) ) {
						alt94=1;
					}
					switch (alt94) {
						case 1 :
							// Java.g:776:16: expression
							{
							pushFollow(FOLLOW_expression_in_statement9576);
							expression321=expression();
							state._fsp--;
							if (state.failed) return retval;
							if ( state.backtracking==0 ) stream_expression.add(expression321.getTree());
							}
							break;

					}

					SEMI322=(Token)match(input,SEMI,FOLLOW_SEMI_in_statement9579); if (state.failed) return retval; 
					if ( state.backtracking==0 ) stream_SEMI.add(SEMI322);

					// AST REWRITE
					// elements: expression, RETURN
					// token labels: 
					// rule labels: retval
					// token list labels: 
					// rule list labels: 
					// wildcard labels: 
					if ( state.backtracking==0 ) {

					retval.tree = root_0;
					RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

					root_0 = (CommonTree)adaptor.nil();
					// 776:77: -> ^( RETURN ( expression )? )
					{
						// Java.g:776:81: ^( RETURN ( expression )? )
						{
						CommonTree root_1 = (CommonTree)adaptor.nil();
						root_1 = (CommonTree)adaptor.becomeRoot(
						stream_RETURN.nextNode()
						, root_1);

						// Java.g:776:90: ( expression )?
						if ( stream_expression.hasNext() ) {
							adaptor.addChild(root_1, stream_expression.nextTree());

						}
						stream_expression.reset();

						adaptor.addChild(root_0, root_1);
						}

					}


					retval.tree = root_0;
					}

					}
					break;
				case 11 :
					// Java.g:777:9: THROW expression SEMI
					{
					THROW323=(Token)match(input,THROW,FOLLOW_THROW_in_statement9643); if (state.failed) return retval; 
					if ( state.backtracking==0 ) stream_THROW.add(THROW323);

					pushFollow(FOLLOW_expression_in_statement9645);
					expression324=expression();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_expression.add(expression324.getTree());
					SEMI325=(Token)match(input,SEMI,FOLLOW_SEMI_in_statement9647); if (state.failed) return retval; 
					if ( state.backtracking==0 ) stream_SEMI.add(SEMI325);

					// AST REWRITE
					// elements: expression, THROW
					// token labels: 
					// rule labels: retval
					// token list labels: 
					// rule list labels: 
					// wildcard labels: 
					if ( state.backtracking==0 ) {

					retval.tree = root_0;
					RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

					root_0 = (CommonTree)adaptor.nil();
					// 777:77: -> ^( THROW expression )
					{
						// Java.g:777:81: ^( THROW expression )
						{
						CommonTree root_1 = (CommonTree)adaptor.nil();
						root_1 = (CommonTree)adaptor.becomeRoot(
						stream_THROW.nextNode()
						, root_1);

						adaptor.addChild(root_1, stream_expression.nextTree());

						adaptor.addChild(root_0, root_1);
						}

					}


					retval.tree = root_0;
					}

					}
					break;
				case 12 :
					// Java.g:778:9: BREAK ( IDENT )? SEMI
					{
					BREAK326=(Token)match(input,BREAK,FOLLOW_BREAK_in_statement9712); if (state.failed) return retval; 
					if ( state.backtracking==0 ) stream_BREAK.add(BREAK326);

					// Java.g:778:15: ( IDENT )?
					int alt95=2;
					int LA95_0 = input.LA(1);
					if ( (LA95_0==IDENT) ) {
						alt95=1;
					}
					switch (alt95) {
						case 1 :
							// Java.g:778:15: IDENT
							{
							IDENT327=(Token)match(input,IDENT,FOLLOW_IDENT_in_statement9714); if (state.failed) return retval; 
							if ( state.backtracking==0 ) stream_IDENT.add(IDENT327);

							}
							break;

					}

					SEMI328=(Token)match(input,SEMI,FOLLOW_SEMI_in_statement9717); if (state.failed) return retval; 
					if ( state.backtracking==0 ) stream_SEMI.add(SEMI328);

					// AST REWRITE
					// elements: BREAK, IDENT
					// token labels: 
					// rule labels: retval
					// token list labels: 
					// rule list labels: 
					// wildcard labels: 
					if ( state.backtracking==0 ) {

					retval.tree = root_0;
					RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

					root_0 = (CommonTree)adaptor.nil();
					// 778:77: -> ^( BREAK ( IDENT )? )
					{
						// Java.g:778:81: ^( BREAK ( IDENT )? )
						{
						CommonTree root_1 = (CommonTree)adaptor.nil();
						root_1 = (CommonTree)adaptor.becomeRoot(
						stream_BREAK.nextNode()
						, root_1);

						// Java.g:778:89: ( IDENT )?
						if ( stream_IDENT.hasNext() ) {
							adaptor.addChild(root_1, 
							stream_IDENT.nextNode()
							);

						}
						stream_IDENT.reset();

						adaptor.addChild(root_0, root_1);
						}

					}


					retval.tree = root_0;
					}

					}
					break;
				case 13 :
					// Java.g:779:9: CONTINUE ( IDENT )? SEMI
					{
					CONTINUE329=(Token)match(input,CONTINUE,FOLLOW_CONTINUE_in_statement9787); if (state.failed) return retval; 
					if ( state.backtracking==0 ) stream_CONTINUE.add(CONTINUE329);

					// Java.g:779:18: ( IDENT )?
					int alt96=2;
					int LA96_0 = input.LA(1);
					if ( (LA96_0==IDENT) ) {
						alt96=1;
					}
					switch (alt96) {
						case 1 :
							// Java.g:779:18: IDENT
							{
							IDENT330=(Token)match(input,IDENT,FOLLOW_IDENT_in_statement9789); if (state.failed) return retval; 
							if ( state.backtracking==0 ) stream_IDENT.add(IDENT330);

							}
							break;

					}

					SEMI331=(Token)match(input,SEMI,FOLLOW_SEMI_in_statement9792); if (state.failed) return retval; 
					if ( state.backtracking==0 ) stream_SEMI.add(SEMI331);

					// AST REWRITE
					// elements: CONTINUE, IDENT
					// token labels: 
					// rule labels: retval
					// token list labels: 
					// rule list labels: 
					// wildcard labels: 
					if ( state.backtracking==0 ) {

					retval.tree = root_0;
					RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

					root_0 = (CommonTree)adaptor.nil();
					// 779:77: -> ^( CONTINUE ( IDENT )? )
					{
						// Java.g:779:81: ^( CONTINUE ( IDENT )? )
						{
						CommonTree root_1 = (CommonTree)adaptor.nil();
						root_1 = (CommonTree)adaptor.becomeRoot(
						stream_CONTINUE.nextNode()
						, root_1);

						// Java.g:779:92: ( IDENT )?
						if ( stream_IDENT.hasNext() ) {
							adaptor.addChild(root_1, 
							stream_IDENT.nextNode()
							);

						}
						stream_IDENT.reset();

						adaptor.addChild(root_0, root_1);
						}

					}


					retval.tree = root_0;
					}

					}
					break;
				case 14 :
					// Java.g:780:9: IDENT COLON statement
					{
					IDENT332=(Token)match(input,IDENT,FOLLOW_IDENT_in_statement9859); if (state.failed) return retval; 
					if ( state.backtracking==0 ) stream_IDENT.add(IDENT332);

					COLON333=(Token)match(input,COLON,FOLLOW_COLON_in_statement9861); if (state.failed) return retval; 
					if ( state.backtracking==0 ) stream_COLON.add(COLON333);

					pushFollow(FOLLOW_statement_in_statement9863);
					statement334=statement();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_statement.add(statement334.getTree());
					// AST REWRITE
					// elements: statement, IDENT
					// token labels: 
					// rule labels: retval
					// token list labels: 
					// rule list labels: 
					// wildcard labels: 
					if ( state.backtracking==0 ) {

					retval.tree = root_0;
					RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

					root_0 = (CommonTree)adaptor.nil();
					// 780:77: -> ^( LABELED_STATEMENT IDENT statement )
					{
						// Java.g:780:81: ^( LABELED_STATEMENT IDENT statement )
						{
						CommonTree root_1 = (CommonTree)adaptor.nil();
						root_1 = (CommonTree)adaptor.becomeRoot(
						(CommonTree)adaptor.create(LABELED_STATEMENT, "LABELED_STATEMENT")
						, root_1);

						adaptor.addChild(root_1, 
						stream_IDENT.nextNode()
						);

						adaptor.addChild(root_1, stream_statement.nextTree());

						adaptor.addChild(root_0, root_1);
						}

					}


					retval.tree = root_0;
					}

					}
					break;
				case 15 :
					// Java.g:781:9: expression SEMI !
					{
					root_0 = (CommonTree)adaptor.nil();


					pushFollow(FOLLOW_expression_in_statement9930);
					expression335=expression();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) adaptor.addChild(root_0, expression335.getTree());

					SEMI336=(Token)match(input,SEMI,FOLLOW_SEMI_in_statement9932); if (state.failed) return retval;
					}
					break;
				case 16 :
					// Java.g:782:9: SEMI
					{
					root_0 = (CommonTree)adaptor.nil();


					SEMI337=(Token)match(input,SEMI,FOLLOW_SEMI_in_statement9943); if (state.failed) return retval;
					if ( state.backtracking==0 ) {
					SEMI337_tree = 
					(CommonTree)adaptor.create(SEMI337)
					;
					adaptor.addChild(root_0, SEMI337_tree);
					}

					}
					break;

			}
			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 75, statement_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "statement"


	public static class catches_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "catches"
	// Java.g:785:1: catches : ( catchClause )+ -> ^( CATCH_CLAUSE_LIST ( catchClause )+ ) ;
	public final JavaParser.catches_return catches() throws RecognitionException {
		JavaParser.catches_return retval = new JavaParser.catches_return();
		retval.start = input.LT(1);
		int catches_StartIndex = input.index();

		CommonTree root_0 = null;

		ParserRuleReturnScope catchClause338 =null;

		RewriteRuleSubtreeStream stream_catchClause=new RewriteRuleSubtreeStream(adaptor,"rule catchClause");

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 76) ) { return retval; }

			// Java.g:786:5: ( ( catchClause )+ -> ^( CATCH_CLAUSE_LIST ( catchClause )+ ) )
			// Java.g:786:9: ( catchClause )+
			{
			// Java.g:786:9: ( catchClause )+
			int cnt98=0;
			loop98:
			do {
				int alt98=2;
				int LA98_0 = input.LA(1);
				if ( (LA98_0==CATCH) ) {
					alt98=1;
				}

				switch (alt98) {
				case 1 :
					// Java.g:786:9: catchClause
					{
					pushFollow(FOLLOW_catchClause_in_catches9982);
					catchClause338=catchClause();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_catchClause.add(catchClause338.getTree());
					}
					break;

				default :
					if ( cnt98 >= 1 ) break loop98;
					if (state.backtracking>0) {state.failed=true; return retval;}
						EarlyExitException eee =
							new EarlyExitException(98, input);
						throw eee;
				}
				cnt98++;
			} while (true);

			// AST REWRITE
			// elements: catchClause
			// token labels: 
			// rule labels: retval
			// token list labels: 
			// rule list labels: 
			// wildcard labels: 
			if ( state.backtracking==0 ) {

			retval.tree = root_0;
			RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

			root_0 = (CommonTree)adaptor.nil();
			// 787:9: -> ^( CATCH_CLAUSE_LIST ( catchClause )+ )
			{
				// Java.g:787:13: ^( CATCH_CLAUSE_LIST ( catchClause )+ )
				{
				CommonTree root_1 = (CommonTree)adaptor.nil();
				root_1 = (CommonTree)adaptor.becomeRoot(
				(CommonTree)adaptor.create(CATCH_CLAUSE_LIST, "CATCH_CLAUSE_LIST")
				, root_1);

				if ( !(stream_catchClause.hasNext()) ) {
					throw new RewriteEarlyExitException();
				}
				while ( stream_catchClause.hasNext() ) {
					adaptor.addChild(root_1, stream_catchClause.nextTree());

				}
				stream_catchClause.reset();

				adaptor.addChild(root_0, root_1);
				}

			}


			retval.tree = root_0;
			}

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 76, catches_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "catches"


	public static class catchClause_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "catchClause"
	// Java.g:790:1: catchClause : CATCH ^ LPAREN ! formalParameterStandardDecl RPAREN ! block ;
	public final JavaParser.catchClause_return catchClause() throws RecognitionException {
		JavaParser.catchClause_return retval = new JavaParser.catchClause_return();
		retval.start = input.LT(1);
		int catchClause_StartIndex = input.index();

		CommonTree root_0 = null;

		Token CATCH339=null;
		Token LPAREN340=null;
		Token RPAREN342=null;
		ParserRuleReturnScope formalParameterStandardDecl341 =null;
		ParserRuleReturnScope block343 =null;

		CommonTree CATCH339_tree=null;
		CommonTree LPAREN340_tree=null;
		CommonTree RPAREN342_tree=null;

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 77) ) { return retval; }

			// Java.g:791:5: ( CATCH ^ LPAREN ! formalParameterStandardDecl RPAREN ! block )
			// Java.g:791:9: CATCH ^ LPAREN ! formalParameterStandardDecl RPAREN ! block
			{
			root_0 = (CommonTree)adaptor.nil();


			CATCH339=(Token)match(input,CATCH,FOLLOW_CATCH_in_catchClause10024); if (state.failed) return retval;
			if ( state.backtracking==0 ) {
			CATCH339_tree = 
			(CommonTree)adaptor.create(CATCH339)
			;
			root_0 = (CommonTree)adaptor.becomeRoot(CATCH339_tree, root_0);
			}

			LPAREN340=(Token)match(input,LPAREN,FOLLOW_LPAREN_in_catchClause10027); if (state.failed) return retval;
			pushFollow(FOLLOW_formalParameterStandardDecl_in_catchClause10030);
			formalParameterStandardDecl341=formalParameterStandardDecl();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) adaptor.addChild(root_0, formalParameterStandardDecl341.getTree());

			RPAREN342=(Token)match(input,RPAREN,FOLLOW_RPAREN_in_catchClause10032); if (state.failed) return retval;
			pushFollow(FOLLOW_block_in_catchClause10035);
			block343=block();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) adaptor.addChild(root_0, block343.getTree());

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 77, catchClause_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "catchClause"


	public static class finallyClause_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "finallyClause"
	// Java.g:794:1: finallyClause : FINALLY block -> block ;
	public final JavaParser.finallyClause_return finallyClause() throws RecognitionException {
		JavaParser.finallyClause_return retval = new JavaParser.finallyClause_return();
		retval.start = input.LT(1);
		int finallyClause_StartIndex = input.index();

		CommonTree root_0 = null;

		Token FINALLY344=null;
		ParserRuleReturnScope block345 =null;

		CommonTree FINALLY344_tree=null;
		RewriteRuleTokenStream stream_FINALLY=new RewriteRuleTokenStream(adaptor,"token FINALLY");
		RewriteRuleSubtreeStream stream_block=new RewriteRuleSubtreeStream(adaptor,"rule block");

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 78) ) { return retval; }

			// Java.g:795:5: ( FINALLY block -> block )
			// Java.g:795:9: FINALLY block
			{
			FINALLY344=(Token)match(input,FINALLY,FOLLOW_FINALLY_in_finallyClause10054); if (state.failed) return retval; 
			if ( state.backtracking==0 ) stream_FINALLY.add(FINALLY344);

			pushFollow(FOLLOW_block_in_finallyClause10056);
			block345=block();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) stream_block.add(block345.getTree());
			// AST REWRITE
			// elements: block
			// token labels: 
			// rule labels: retval
			// token list labels: 
			// rule list labels: 
			// wildcard labels: 
			if ( state.backtracking==0 ) {

			retval.tree = root_0;
			RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

			root_0 = (CommonTree)adaptor.nil();
			// 796:9: -> block
			{
				adaptor.addChild(root_0, stream_block.nextTree());

			}


			retval.tree = root_0;
			}

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 78, finallyClause_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "finallyClause"


	public static class switchBlockLabels_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "switchBlockLabels"
	// Java.g:799:1: switchBlockLabels : switchCaseLabels ( switchDefaultLabel )? switchCaseLabels -> ^( SWITCH_BLOCK_LABEL_LIST switchCaseLabels ( switchDefaultLabel )? switchCaseLabels ) ;
	public final JavaParser.switchBlockLabels_return switchBlockLabels() throws RecognitionException {
		JavaParser.switchBlockLabels_return retval = new JavaParser.switchBlockLabels_return();
		retval.start = input.LT(1);
		int switchBlockLabels_StartIndex = input.index();

		CommonTree root_0 = null;

		ParserRuleReturnScope switchCaseLabels346 =null;
		ParserRuleReturnScope switchDefaultLabel347 =null;
		ParserRuleReturnScope switchCaseLabels348 =null;

		RewriteRuleSubtreeStream stream_switchDefaultLabel=new RewriteRuleSubtreeStream(adaptor,"rule switchDefaultLabel");
		RewriteRuleSubtreeStream stream_switchCaseLabels=new RewriteRuleSubtreeStream(adaptor,"rule switchCaseLabels");

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 79) ) { return retval; }

			// Java.g:800:5: ( switchCaseLabels ( switchDefaultLabel )? switchCaseLabels -> ^( SWITCH_BLOCK_LABEL_LIST switchCaseLabels ( switchDefaultLabel )? switchCaseLabels ) )
			// Java.g:800:9: switchCaseLabels ( switchDefaultLabel )? switchCaseLabels
			{
			pushFollow(FOLLOW_switchCaseLabels_in_switchBlockLabels10088);
			switchCaseLabels346=switchCaseLabels();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) stream_switchCaseLabels.add(switchCaseLabels346.getTree());
			// Java.g:800:26: ( switchDefaultLabel )?
			int alt99=2;
			int LA99_0 = input.LA(1);
			if ( (LA99_0==DEFAULT) ) {
				alt99=1;
			}
			switch (alt99) {
				case 1 :
					// Java.g:800:26: switchDefaultLabel
					{
					pushFollow(FOLLOW_switchDefaultLabel_in_switchBlockLabels10090);
					switchDefaultLabel347=switchDefaultLabel();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_switchDefaultLabel.add(switchDefaultLabel347.getTree());
					}
					break;

			}

			pushFollow(FOLLOW_switchCaseLabels_in_switchBlockLabels10093);
			switchCaseLabels348=switchCaseLabels();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) stream_switchCaseLabels.add(switchCaseLabels348.getTree());
			// AST REWRITE
			// elements: switchCaseLabels, switchCaseLabels, switchDefaultLabel
			// token labels: 
			// rule labels: retval
			// token list labels: 
			// rule list labels: 
			// wildcard labels: 
			if ( state.backtracking==0 ) {

			retval.tree = root_0;
			RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

			root_0 = (CommonTree)adaptor.nil();
			// 801:9: -> ^( SWITCH_BLOCK_LABEL_LIST switchCaseLabels ( switchDefaultLabel )? switchCaseLabels )
			{
				// Java.g:801:13: ^( SWITCH_BLOCK_LABEL_LIST switchCaseLabels ( switchDefaultLabel )? switchCaseLabels )
				{
				CommonTree root_1 = (CommonTree)adaptor.nil();
				root_1 = (CommonTree)adaptor.becomeRoot(
				(CommonTree)adaptor.create(SWITCH_BLOCK_LABEL_LIST, "SWITCH_BLOCK_LABEL_LIST")
				, root_1);

				adaptor.addChild(root_1, stream_switchCaseLabels.nextTree());

				// Java.g:801:56: ( switchDefaultLabel )?
				if ( stream_switchDefaultLabel.hasNext() ) {
					adaptor.addChild(root_1, stream_switchDefaultLabel.nextTree());

				}
				stream_switchDefaultLabel.reset();

				adaptor.addChild(root_1, stream_switchCaseLabels.nextTree());

				adaptor.addChild(root_0, root_1);
				}

			}


			retval.tree = root_0;
			}

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 79, switchBlockLabels_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "switchBlockLabels"


	public static class switchCaseLabels_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "switchCaseLabels"
	// Java.g:804:1: switchCaseLabels : ( switchCaseLabel )* ;
	public final JavaParser.switchCaseLabels_return switchCaseLabels() throws RecognitionException {
		JavaParser.switchCaseLabels_return retval = new JavaParser.switchCaseLabels_return();
		retval.start = input.LT(1);
		int switchCaseLabels_StartIndex = input.index();

		CommonTree root_0 = null;

		ParserRuleReturnScope switchCaseLabel349 =null;


		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 80) ) { return retval; }

			// Java.g:805:5: ( ( switchCaseLabel )* )
			// Java.g:805:9: ( switchCaseLabel )*
			{
			root_0 = (CommonTree)adaptor.nil();


			// Java.g:805:9: ( switchCaseLabel )*
			loop100:
			do {
				int alt100=2;
				int LA100_0 = input.LA(1);
				if ( (LA100_0==CASE) ) {
					int LA100_2 = input.LA(2);
					if ( (synpred143_Java()) ) {
						alt100=1;
					}

				}

				switch (alt100) {
				case 1 :
					// Java.g:805:9: switchCaseLabel
					{
					pushFollow(FOLLOW_switchCaseLabel_in_switchCaseLabels10138);
					switchCaseLabel349=switchCaseLabel();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) adaptor.addChild(root_0, switchCaseLabel349.getTree());

					}
					break;

				default :
					break loop100;
				}
			} while (true);

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 80, switchCaseLabels_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "switchCaseLabels"


	public static class switchCaseLabel_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "switchCaseLabel"
	// Java.g:808:1: switchCaseLabel : CASE ^ expression COLON ! ( blockStatement )* ;
	public final JavaParser.switchCaseLabel_return switchCaseLabel() throws RecognitionException {
		JavaParser.switchCaseLabel_return retval = new JavaParser.switchCaseLabel_return();
		retval.start = input.LT(1);
		int switchCaseLabel_StartIndex = input.index();

		CommonTree root_0 = null;

		Token CASE350=null;
		Token COLON352=null;
		ParserRuleReturnScope expression351 =null;
		ParserRuleReturnScope blockStatement353 =null;

		CommonTree CASE350_tree=null;
		CommonTree COLON352_tree=null;

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 81) ) { return retval; }

			// Java.g:809:5: ( CASE ^ expression COLON ! ( blockStatement )* )
			// Java.g:809:9: CASE ^ expression COLON ! ( blockStatement )*
			{
			root_0 = (CommonTree)adaptor.nil();


			CASE350=(Token)match(input,CASE,FOLLOW_CASE_in_switchCaseLabel10166); if (state.failed) return retval;
			if ( state.backtracking==0 ) {
			CASE350_tree = 
			(CommonTree)adaptor.create(CASE350)
			;
			root_0 = (CommonTree)adaptor.becomeRoot(CASE350_tree, root_0);
			}

			pushFollow(FOLLOW_expression_in_switchCaseLabel10169);
			expression351=expression();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) adaptor.addChild(root_0, expression351.getTree());

			COLON352=(Token)match(input,COLON,FOLLOW_COLON_in_switchCaseLabel10171); if (state.failed) return retval;
			// Java.g:809:33: ( blockStatement )*
			loop101:
			do {
				int alt101=2;
				int LA101_0 = input.LA(1);
				if ( (LA101_0==ABSTRACT||LA101_0==ASSERT||LA101_0==AT||(LA101_0 >= BOOLEAN && LA101_0 <= BYTE)||(LA101_0 >= CHAR && LA101_0 <= CLASS)||(LA101_0 >= CONTINUE && LA101_0 <= DECIMAL_LITERAL)||LA101_0==DO||LA101_0==DOUBLE||LA101_0==ENUM||(LA101_0 >= FALSE && LA101_0 <= FINAL)||(LA101_0 >= FLOAT && LA101_0 <= FLOATING_POINT_LITERAL)||LA101_0==FOR||(LA101_0 >= HEX_LITERAL && LA101_0 <= IF)||LA101_0==INC||LA101_0==INT||LA101_0==INTERFACE||LA101_0==LCURLY||LA101_0==LESS_THAN||LA101_0==LOGICAL_NOT||(LA101_0 >= LONG && LA101_0 <= LPAREN)||LA101_0==MINUS||(LA101_0 >= NATIVE && LA101_0 <= NOT)||LA101_0==NULL||LA101_0==OCTAL_LITERAL||LA101_0==PLUS||(LA101_0 >= PRIVATE && LA101_0 <= PUBLIC)||LA101_0==RETURN||LA101_0==SEMI||LA101_0==SHORT||LA101_0==STATIC||(LA101_0 >= STRICTFP && LA101_0 <= SUPER)||LA101_0==SWITCH||(LA101_0 >= SYNCHRONIZED && LA101_0 <= THIS)||LA101_0==THROW||(LA101_0 >= TRANSIENT && LA101_0 <= TRY)||LA101_0==VOID||(LA101_0 >= VOLATILE && LA101_0 <= WHILE)) ) {
					alt101=1;
				}

				switch (alt101) {
				case 1 :
					// Java.g:809:33: blockStatement
					{
					pushFollow(FOLLOW_blockStatement_in_switchCaseLabel10174);
					blockStatement353=blockStatement();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) adaptor.addChild(root_0, blockStatement353.getTree());

					}
					break;

				default :
					break loop101;
				}
			} while (true);

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 81, switchCaseLabel_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "switchCaseLabel"


	public static class switchDefaultLabel_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "switchDefaultLabel"
	// Java.g:812:1: switchDefaultLabel : DEFAULT ^ COLON ! ( blockStatement )* ;
	public final JavaParser.switchDefaultLabel_return switchDefaultLabel() throws RecognitionException {
		JavaParser.switchDefaultLabel_return retval = new JavaParser.switchDefaultLabel_return();
		retval.start = input.LT(1);
		int switchDefaultLabel_StartIndex = input.index();

		CommonTree root_0 = null;

		Token DEFAULT354=null;
		Token COLON355=null;
		ParserRuleReturnScope blockStatement356 =null;

		CommonTree DEFAULT354_tree=null;
		CommonTree COLON355_tree=null;

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 82) ) { return retval; }

			// Java.g:813:5: ( DEFAULT ^ COLON ! ( blockStatement )* )
			// Java.g:813:9: DEFAULT ^ COLON ! ( blockStatement )*
			{
			root_0 = (CommonTree)adaptor.nil();


			DEFAULT354=(Token)match(input,DEFAULT,FOLLOW_DEFAULT_in_switchDefaultLabel10198); if (state.failed) return retval;
			if ( state.backtracking==0 ) {
			DEFAULT354_tree = 
			(CommonTree)adaptor.create(DEFAULT354)
			;
			root_0 = (CommonTree)adaptor.becomeRoot(DEFAULT354_tree, root_0);
			}

			COLON355=(Token)match(input,COLON,FOLLOW_COLON_in_switchDefaultLabel10201); if (state.failed) return retval;
			// Java.g:813:25: ( blockStatement )*
			loop102:
			do {
				int alt102=2;
				int LA102_0 = input.LA(1);
				if ( (LA102_0==ABSTRACT||LA102_0==ASSERT||LA102_0==AT||(LA102_0 >= BOOLEAN && LA102_0 <= BYTE)||(LA102_0 >= CHAR && LA102_0 <= CLASS)||(LA102_0 >= CONTINUE && LA102_0 <= DECIMAL_LITERAL)||LA102_0==DO||LA102_0==DOUBLE||LA102_0==ENUM||(LA102_0 >= FALSE && LA102_0 <= FINAL)||(LA102_0 >= FLOAT && LA102_0 <= FLOATING_POINT_LITERAL)||LA102_0==FOR||(LA102_0 >= HEX_LITERAL && LA102_0 <= IF)||LA102_0==INC||LA102_0==INT||LA102_0==INTERFACE||LA102_0==LCURLY||LA102_0==LESS_THAN||LA102_0==LOGICAL_NOT||(LA102_0 >= LONG && LA102_0 <= LPAREN)||LA102_0==MINUS||(LA102_0 >= NATIVE && LA102_0 <= NOT)||LA102_0==NULL||LA102_0==OCTAL_LITERAL||LA102_0==PLUS||(LA102_0 >= PRIVATE && LA102_0 <= PUBLIC)||LA102_0==RETURN||LA102_0==SEMI||LA102_0==SHORT||LA102_0==STATIC||(LA102_0 >= STRICTFP && LA102_0 <= SUPER)||LA102_0==SWITCH||(LA102_0 >= SYNCHRONIZED && LA102_0 <= THIS)||LA102_0==THROW||(LA102_0 >= TRANSIENT && LA102_0 <= TRY)||LA102_0==VOID||(LA102_0 >= VOLATILE && LA102_0 <= WHILE)) ) {
					alt102=1;
				}

				switch (alt102) {
				case 1 :
					// Java.g:813:25: blockStatement
					{
					pushFollow(FOLLOW_blockStatement_in_switchDefaultLabel10204);
					blockStatement356=blockStatement();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) adaptor.addChild(root_0, blockStatement356.getTree());

					}
					break;

				default :
					break loop102;
				}
			} while (true);

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 82, switchDefaultLabel_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "switchDefaultLabel"


	public static class forInit_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "forInit"
	// Java.g:816:1: forInit : ( localVariableDeclaration -> ^( FOR_INIT localVariableDeclaration ) | expressionList -> ^( FOR_INIT expressionList ) | -> ^( FOR_INIT ) );
	public final JavaParser.forInit_return forInit() throws RecognitionException {
		JavaParser.forInit_return retval = new JavaParser.forInit_return();
		retval.start = input.LT(1);
		int forInit_StartIndex = input.index();

		CommonTree root_0 = null;

		ParserRuleReturnScope localVariableDeclaration357 =null;
		ParserRuleReturnScope expressionList358 =null;

		RewriteRuleSubtreeStream stream_expressionList=new RewriteRuleSubtreeStream(adaptor,"rule expressionList");
		RewriteRuleSubtreeStream stream_localVariableDeclaration=new RewriteRuleSubtreeStream(adaptor,"rule localVariableDeclaration");

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 83) ) { return retval; }

			// Java.g:817:5: ( localVariableDeclaration -> ^( FOR_INIT localVariableDeclaration ) | expressionList -> ^( FOR_INIT expressionList ) | -> ^( FOR_INIT ) )
			int alt103=3;
			switch ( input.LA(1) ) {
			case AT:
			case FINAL:
				{
				alt103=1;
				}
				break;
			case BOOLEAN:
			case BYTE:
			case CHAR:
			case DOUBLE:
			case FLOAT:
			case INT:
			case LONG:
			case SHORT:
				{
				int LA103_3 = input.LA(2);
				if ( (synpred146_Java()) ) {
					alt103=1;
				}
				else if ( (synpred147_Java()) ) {
					alt103=2;
				}
				else {
					if (state.backtracking>0) {state.failed=true; return retval;}
					int nvaeMark = input.mark();
					try {
						input.consume();
						NoViableAltException nvae =
							new NoViableAltException("", 103, 3, input);
						throw nvae;
					} finally {
						input.rewind(nvaeMark);
					}
				}
				}
				break;
			case IDENT:
				{
				int LA103_4 = input.LA(2);
				if ( (synpred146_Java()) ) {
					alt103=1;
				}
				else if ( (synpred147_Java()) ) {
					alt103=2;
				}
				else {
					if (state.backtracking>0) {state.failed=true; return retval;}
					int nvaeMark = input.mark();
					try {
						input.consume();
						NoViableAltException nvae =
							new NoViableAltException("", 103, 4, input);
						throw nvae;
					} finally {
						input.rewind(nvaeMark);
					}
				}
				}
				break;
			case CHARACTER_LITERAL:
			case DEC:
			case DECIMAL_LITERAL:
			case FALSE:
			case FLOATING_POINT_LITERAL:
			case HEX_LITERAL:
			case INC:
			case LESS_THAN:
			case LOGICAL_NOT:
			case LPAREN:
			case MINUS:
			case NEW:
			case NOT:
			case NULL:
			case OCTAL_LITERAL:
			case PLUS:
			case STRING_LITERAL:
			case SUPER:
			case THIS:
			case TRUE:
			case VOID:
				{
				alt103=2;
				}
				break;
			case SEMI:
				{
				alt103=3;
				}
				break;
			default:
				if (state.backtracking>0) {state.failed=true; return retval;}
				NoViableAltException nvae =
					new NoViableAltException("", 103, 0, input);
				throw nvae;
			}
			switch (alt103) {
				case 1 :
					// Java.g:817:9: localVariableDeclaration
					{
					pushFollow(FOLLOW_localVariableDeclaration_in_forInit10228);
					localVariableDeclaration357=localVariableDeclaration();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_localVariableDeclaration.add(localVariableDeclaration357.getTree());
					// AST REWRITE
					// elements: localVariableDeclaration
					// token labels: 
					// rule labels: retval
					// token list labels: 
					// rule list labels: 
					// wildcard labels: 
					if ( state.backtracking==0 ) {

					retval.tree = root_0;
					RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

					root_0 = (CommonTree)adaptor.nil();
					// 817:37: -> ^( FOR_INIT localVariableDeclaration )
					{
						// Java.g:817:41: ^( FOR_INIT localVariableDeclaration )
						{
						CommonTree root_1 = (CommonTree)adaptor.nil();
						root_1 = (CommonTree)adaptor.becomeRoot(
						(CommonTree)adaptor.create(FOR_INIT, "FOR_INIT")
						, root_1);

						adaptor.addChild(root_1, stream_localVariableDeclaration.nextTree());

						adaptor.addChild(root_0, root_1);
						}

					}


					retval.tree = root_0;
					}

					}
					break;
				case 2 :
					// Java.g:818:9: expressionList
					{
					pushFollow(FOLLOW_expressionList_in_forInit10250);
					expressionList358=expressionList();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_expressionList.add(expressionList358.getTree());
					// AST REWRITE
					// elements: expressionList
					// token labels: 
					// rule labels: retval
					// token list labels: 
					// rule list labels: 
					// wildcard labels: 
					if ( state.backtracking==0 ) {

					retval.tree = root_0;
					RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

					root_0 = (CommonTree)adaptor.nil();
					// 818:37: -> ^( FOR_INIT expressionList )
					{
						// Java.g:818:41: ^( FOR_INIT expressionList )
						{
						CommonTree root_1 = (CommonTree)adaptor.nil();
						root_1 = (CommonTree)adaptor.becomeRoot(
						(CommonTree)adaptor.create(FOR_INIT, "FOR_INIT")
						, root_1);

						adaptor.addChild(root_1, stream_expressionList.nextTree());

						adaptor.addChild(root_0, root_1);
						}

					}


					retval.tree = root_0;
					}

					}
					break;
				case 3 :
					// Java.g:819:37: 
					{
					// AST REWRITE
					// elements: 
					// token labels: 
					// rule labels: retval
					// token list labels: 
					// rule list labels: 
					// wildcard labels: 
					if ( state.backtracking==0 ) {

					retval.tree = root_0;
					RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

					root_0 = (CommonTree)adaptor.nil();
					// 819:37: -> ^( FOR_INIT )
					{
						// Java.g:819:41: ^( FOR_INIT )
						{
						CommonTree root_1 = (CommonTree)adaptor.nil();
						root_1 = (CommonTree)adaptor.becomeRoot(
						(CommonTree)adaptor.create(FOR_INIT, "FOR_INIT")
						, root_1);

						adaptor.addChild(root_0, root_1);
						}

					}


					retval.tree = root_0;
					}

					}
					break;

			}
			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 83, forInit_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "forInit"


	public static class forCondition_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "forCondition"
	// Java.g:822:1: forCondition : ( expression )? -> ^( FOR_CONDITION ( expression )? ) ;
	public final JavaParser.forCondition_return forCondition() throws RecognitionException {
		JavaParser.forCondition_return retval = new JavaParser.forCondition_return();
		retval.start = input.LT(1);
		int forCondition_StartIndex = input.index();

		CommonTree root_0 = null;

		ParserRuleReturnScope expression359 =null;

		RewriteRuleSubtreeStream stream_expression=new RewriteRuleSubtreeStream(adaptor,"rule expression");

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 84) ) { return retval; }

			// Java.g:823:5: ( ( expression )? -> ^( FOR_CONDITION ( expression )? ) )
			// Java.g:823:9: ( expression )?
			{
			// Java.g:823:9: ( expression )?
			int alt104=2;
			int LA104_0 = input.LA(1);
			if ( (LA104_0==BOOLEAN||LA104_0==BYTE||(LA104_0 >= CHAR && LA104_0 <= CHARACTER_LITERAL)||(LA104_0 >= DEC && LA104_0 <= DECIMAL_LITERAL)||LA104_0==DOUBLE||LA104_0==FALSE||(LA104_0 >= FLOAT && LA104_0 <= FLOATING_POINT_LITERAL)||(LA104_0 >= HEX_LITERAL && LA104_0 <= IDENT)||LA104_0==INC||LA104_0==INT||LA104_0==LESS_THAN||LA104_0==LOGICAL_NOT||(LA104_0 >= LONG && LA104_0 <= LPAREN)||LA104_0==MINUS||(LA104_0 >= NEW && LA104_0 <= NOT)||LA104_0==NULL||LA104_0==OCTAL_LITERAL||LA104_0==PLUS||LA104_0==SHORT||(LA104_0 >= STRING_LITERAL && LA104_0 <= SUPER)||LA104_0==THIS||LA104_0==TRUE||LA104_0==VOID) ) {
				alt104=1;
			}
			switch (alt104) {
				case 1 :
					// Java.g:823:9: expression
					{
					pushFollow(FOLLOW_expression_in_forCondition10338);
					expression359=expression();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_expression.add(expression359.getTree());
					}
					break;

			}

			// AST REWRITE
			// elements: expression
			// token labels: 
			// rule labels: retval
			// token list labels: 
			// rule list labels: 
			// wildcard labels: 
			if ( state.backtracking==0 ) {

			retval.tree = root_0;
			RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

			root_0 = (CommonTree)adaptor.nil();
			// 824:9: -> ^( FOR_CONDITION ( expression )? )
			{
				// Java.g:824:13: ^( FOR_CONDITION ( expression )? )
				{
				CommonTree root_1 = (CommonTree)adaptor.nil();
				root_1 = (CommonTree)adaptor.becomeRoot(
				(CommonTree)adaptor.create(FOR_CONDITION, "FOR_CONDITION")
				, root_1);

				// Java.g:824:29: ( expression )?
				if ( stream_expression.hasNext() ) {
					adaptor.addChild(root_1, stream_expression.nextTree());

				}
				stream_expression.reset();

				adaptor.addChild(root_0, root_1);
				}

			}


			retval.tree = root_0;
			}

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 84, forCondition_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "forCondition"


	public static class forUpdater_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "forUpdater"
	// Java.g:827:1: forUpdater : ( expressionList )? -> ^( FOR_UPDATE ( expressionList )? ) ;
	public final JavaParser.forUpdater_return forUpdater() throws RecognitionException {
		JavaParser.forUpdater_return retval = new JavaParser.forUpdater_return();
		retval.start = input.LT(1);
		int forUpdater_StartIndex = input.index();

		CommonTree root_0 = null;

		ParserRuleReturnScope expressionList360 =null;

		RewriteRuleSubtreeStream stream_expressionList=new RewriteRuleSubtreeStream(adaptor,"rule expressionList");

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 85) ) { return retval; }

			// Java.g:828:5: ( ( expressionList )? -> ^( FOR_UPDATE ( expressionList )? ) )
			// Java.g:828:9: ( expressionList )?
			{
			// Java.g:828:9: ( expressionList )?
			int alt105=2;
			int LA105_0 = input.LA(1);
			if ( (LA105_0==BOOLEAN||LA105_0==BYTE||(LA105_0 >= CHAR && LA105_0 <= CHARACTER_LITERAL)||(LA105_0 >= DEC && LA105_0 <= DECIMAL_LITERAL)||LA105_0==DOUBLE||LA105_0==FALSE||(LA105_0 >= FLOAT && LA105_0 <= FLOATING_POINT_LITERAL)||(LA105_0 >= HEX_LITERAL && LA105_0 <= IDENT)||LA105_0==INC||LA105_0==INT||LA105_0==LESS_THAN||LA105_0==LOGICAL_NOT||(LA105_0 >= LONG && LA105_0 <= LPAREN)||LA105_0==MINUS||(LA105_0 >= NEW && LA105_0 <= NOT)||LA105_0==NULL||LA105_0==OCTAL_LITERAL||LA105_0==PLUS||LA105_0==SHORT||(LA105_0 >= STRING_LITERAL && LA105_0 <= SUPER)||LA105_0==THIS||LA105_0==TRUE||LA105_0==VOID) ) {
				alt105=1;
			}
			switch (alt105) {
				case 1 :
					// Java.g:828:9: expressionList
					{
					pushFollow(FOLLOW_expressionList_in_forUpdater10380);
					expressionList360=expressionList();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_expressionList.add(expressionList360.getTree());
					}
					break;

			}

			// AST REWRITE
			// elements: expressionList
			// token labels: 
			// rule labels: retval
			// token list labels: 
			// rule list labels: 
			// wildcard labels: 
			if ( state.backtracking==0 ) {

			retval.tree = root_0;
			RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

			root_0 = (CommonTree)adaptor.nil();
			// 829:9: -> ^( FOR_UPDATE ( expressionList )? )
			{
				// Java.g:829:13: ^( FOR_UPDATE ( expressionList )? )
				{
				CommonTree root_1 = (CommonTree)adaptor.nil();
				root_1 = (CommonTree)adaptor.becomeRoot(
				(CommonTree)adaptor.create(FOR_UPDATE, "FOR_UPDATE")
				, root_1);

				// Java.g:829:26: ( expressionList )?
				if ( stream_expressionList.hasNext() ) {
					adaptor.addChild(root_1, stream_expressionList.nextTree());

				}
				stream_expressionList.reset();

				adaptor.addChild(root_0, root_1);
				}

			}


			retval.tree = root_0;
			}

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 85, forUpdater_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "forUpdater"


	public static class parenthesizedExpression_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "parenthesizedExpression"
	// Java.g:834:1: parenthesizedExpression : LPAREN expression RPAREN -> ^( PARENTESIZED_EXPR[$LPAREN, \"PARENTESIZED_EXPR\"] expression ) ;
	public final JavaParser.parenthesizedExpression_return parenthesizedExpression() throws RecognitionException {
		JavaParser.parenthesizedExpression_return retval = new JavaParser.parenthesizedExpression_return();
		retval.start = input.LT(1);
		int parenthesizedExpression_StartIndex = input.index();

		CommonTree root_0 = null;

		Token LPAREN361=null;
		Token RPAREN363=null;
		ParserRuleReturnScope expression362 =null;

		CommonTree LPAREN361_tree=null;
		CommonTree RPAREN363_tree=null;
		RewriteRuleTokenStream stream_RPAREN=new RewriteRuleTokenStream(adaptor,"token RPAREN");
		RewriteRuleTokenStream stream_LPAREN=new RewriteRuleTokenStream(adaptor,"token LPAREN");
		RewriteRuleSubtreeStream stream_expression=new RewriteRuleSubtreeStream(adaptor,"rule expression");

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 86) ) { return retval; }

			// Java.g:835:5: ( LPAREN expression RPAREN -> ^( PARENTESIZED_EXPR[$LPAREN, \"PARENTESIZED_EXPR\"] expression ) )
			// Java.g:835:9: LPAREN expression RPAREN
			{
			LPAREN361=(Token)match(input,LPAREN,FOLLOW_LPAREN_in_parenthesizedExpression10420); if (state.failed) return retval; 
			if ( state.backtracking==0 ) stream_LPAREN.add(LPAREN361);

			pushFollow(FOLLOW_expression_in_parenthesizedExpression10422);
			expression362=expression();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) stream_expression.add(expression362.getTree());
			RPAREN363=(Token)match(input,RPAREN,FOLLOW_RPAREN_in_parenthesizedExpression10424); if (state.failed) return retval; 
			if ( state.backtracking==0 ) stream_RPAREN.add(RPAREN363);

			// AST REWRITE
			// elements: expression
			// token labels: 
			// rule labels: retval
			// token list labels: 
			// rule list labels: 
			// wildcard labels: 
			if ( state.backtracking==0 ) {

			retval.tree = root_0;
			RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

			root_0 = (CommonTree)adaptor.nil();
			// 836:9: -> ^( PARENTESIZED_EXPR[$LPAREN, \"PARENTESIZED_EXPR\"] expression )
			{
				// Java.g:836:13: ^( PARENTESIZED_EXPR[$LPAREN, \"PARENTESIZED_EXPR\"] expression )
				{
				CommonTree root_1 = (CommonTree)adaptor.nil();
				root_1 = (CommonTree)adaptor.becomeRoot(
				(CommonTree)adaptor.create(PARENTESIZED_EXPR, LPAREN361, "PARENTESIZED_EXPR")
				, root_1);

				adaptor.addChild(root_1, stream_expression.nextTree());

				adaptor.addChild(root_0, root_1);
				}

			}


			retval.tree = root_0;
			}

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 86, parenthesizedExpression_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "parenthesizedExpression"


	public static class expressionList_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "expressionList"
	// Java.g:839:1: expressionList : expression ( COMMA ! expression )* ;
	public final JavaParser.expressionList_return expressionList() throws RecognitionException {
		JavaParser.expressionList_return retval = new JavaParser.expressionList_return();
		retval.start = input.LT(1);
		int expressionList_StartIndex = input.index();

		CommonTree root_0 = null;

		Token COMMA365=null;
		ParserRuleReturnScope expression364 =null;
		ParserRuleReturnScope expression366 =null;

		CommonTree COMMA365_tree=null;

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 87) ) { return retval; }

			// Java.g:840:5: ( expression ( COMMA ! expression )* )
			// Java.g:840:9: expression ( COMMA ! expression )*
			{
			root_0 = (CommonTree)adaptor.nil();


			pushFollow(FOLLOW_expression_in_expressionList10465);
			expression364=expression();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) adaptor.addChild(root_0, expression364.getTree());

			// Java.g:840:20: ( COMMA ! expression )*
			loop106:
			do {
				int alt106=2;
				int LA106_0 = input.LA(1);
				if ( (LA106_0==COMMA) ) {
					alt106=1;
				}

				switch (alt106) {
				case 1 :
					// Java.g:840:21: COMMA ! expression
					{
					COMMA365=(Token)match(input,COMMA,FOLLOW_COMMA_in_expressionList10468); if (state.failed) return retval;
					pushFollow(FOLLOW_expression_in_expressionList10471);
					expression366=expression();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) adaptor.addChild(root_0, expression366.getTree());

					}
					break;

				default :
					break loop106;
				}
			} while (true);

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 87, expressionList_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "expressionList"


	public static class expression_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "expression"
	// Java.g:843:1: expression : assignmentExpression -> ^( EXPR assignmentExpression ) ;
	public final JavaParser.expression_return expression() throws RecognitionException {
		JavaParser.expression_return retval = new JavaParser.expression_return();
		retval.start = input.LT(1);
		int expression_StartIndex = input.index();

		CommonTree root_0 = null;

		ParserRuleReturnScope assignmentExpression367 =null;

		RewriteRuleSubtreeStream stream_assignmentExpression=new RewriteRuleSubtreeStream(adaptor,"rule assignmentExpression");

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 88) ) { return retval; }

			// Java.g:844:5: ( assignmentExpression -> ^( EXPR assignmentExpression ) )
			// Java.g:844:9: assignmentExpression
			{
			pushFollow(FOLLOW_assignmentExpression_in_expression10492);
			assignmentExpression367=assignmentExpression();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) stream_assignmentExpression.add(assignmentExpression367.getTree());
			// AST REWRITE
			// elements: assignmentExpression
			// token labels: 
			// rule labels: retval
			// token list labels: 
			// rule list labels: 
			// wildcard labels: 
			if ( state.backtracking==0 ) {

			retval.tree = root_0;
			RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

			root_0 = (CommonTree)adaptor.nil();
			// 845:9: -> ^( EXPR assignmentExpression )
			{
				// Java.g:845:13: ^( EXPR assignmentExpression )
				{
				CommonTree root_1 = (CommonTree)adaptor.nil();
				root_1 = (CommonTree)adaptor.becomeRoot(
				(CommonTree)adaptor.create(EXPR, "EXPR")
				, root_1);

				adaptor.addChild(root_1, stream_assignmentExpression.nextTree());

				adaptor.addChild(root_0, root_1);
				}

			}


			retval.tree = root_0;
			}

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 88, expression_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "expression"


	public static class assignmentExpression_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "assignmentExpression"
	// Java.g:848:1: assignmentExpression : conditionalExpression ( ( ASSIGN ^| PLUS_ASSIGN ^| MINUS_ASSIGN ^| STAR_ASSIGN ^| DIV_ASSIGN ^| AND_ASSIGN ^| OR_ASSIGN ^| XOR_ASSIGN ^| MOD_ASSIGN ^| SHIFT_LEFT_ASSIGN ^| SHIFT_RIGHT_ASSIGN ^| BIT_SHIFT_RIGHT_ASSIGN ^) assignmentExpression )? ;
	public final JavaParser.assignmentExpression_return assignmentExpression() throws RecognitionException {
		JavaParser.assignmentExpression_return retval = new JavaParser.assignmentExpression_return();
		retval.start = input.LT(1);
		int assignmentExpression_StartIndex = input.index();

		CommonTree root_0 = null;

		Token ASSIGN369=null;
		Token PLUS_ASSIGN370=null;
		Token MINUS_ASSIGN371=null;
		Token STAR_ASSIGN372=null;
		Token DIV_ASSIGN373=null;
		Token AND_ASSIGN374=null;
		Token OR_ASSIGN375=null;
		Token XOR_ASSIGN376=null;
		Token MOD_ASSIGN377=null;
		Token SHIFT_LEFT_ASSIGN378=null;
		Token SHIFT_RIGHT_ASSIGN379=null;
		Token BIT_SHIFT_RIGHT_ASSIGN380=null;
		ParserRuleReturnScope conditionalExpression368 =null;
		ParserRuleReturnScope assignmentExpression381 =null;

		CommonTree ASSIGN369_tree=null;
		CommonTree PLUS_ASSIGN370_tree=null;
		CommonTree MINUS_ASSIGN371_tree=null;
		CommonTree STAR_ASSIGN372_tree=null;
		CommonTree DIV_ASSIGN373_tree=null;
		CommonTree AND_ASSIGN374_tree=null;
		CommonTree OR_ASSIGN375_tree=null;
		CommonTree XOR_ASSIGN376_tree=null;
		CommonTree MOD_ASSIGN377_tree=null;
		CommonTree SHIFT_LEFT_ASSIGN378_tree=null;
		CommonTree SHIFT_RIGHT_ASSIGN379_tree=null;
		CommonTree BIT_SHIFT_RIGHT_ASSIGN380_tree=null;

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 89) ) { return retval; }

			// Java.g:849:5: ( conditionalExpression ( ( ASSIGN ^| PLUS_ASSIGN ^| MINUS_ASSIGN ^| STAR_ASSIGN ^| DIV_ASSIGN ^| AND_ASSIGN ^| OR_ASSIGN ^| XOR_ASSIGN ^| MOD_ASSIGN ^| SHIFT_LEFT_ASSIGN ^| SHIFT_RIGHT_ASSIGN ^| BIT_SHIFT_RIGHT_ASSIGN ^) assignmentExpression )? )
			// Java.g:849:9: conditionalExpression ( ( ASSIGN ^| PLUS_ASSIGN ^| MINUS_ASSIGN ^| STAR_ASSIGN ^| DIV_ASSIGN ^| AND_ASSIGN ^| OR_ASSIGN ^| XOR_ASSIGN ^| MOD_ASSIGN ^| SHIFT_LEFT_ASSIGN ^| SHIFT_RIGHT_ASSIGN ^| BIT_SHIFT_RIGHT_ASSIGN ^) assignmentExpression )?
			{
			root_0 = (CommonTree)adaptor.nil();


			pushFollow(FOLLOW_conditionalExpression_in_assignmentExpression10528);
			conditionalExpression368=conditionalExpression();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) adaptor.addChild(root_0, conditionalExpression368.getTree());

			// Java.g:850:9: ( ( ASSIGN ^| PLUS_ASSIGN ^| MINUS_ASSIGN ^| STAR_ASSIGN ^| DIV_ASSIGN ^| AND_ASSIGN ^| OR_ASSIGN ^| XOR_ASSIGN ^| MOD_ASSIGN ^| SHIFT_LEFT_ASSIGN ^| SHIFT_RIGHT_ASSIGN ^| BIT_SHIFT_RIGHT_ASSIGN ^) assignmentExpression )?
			int alt108=2;
			int LA108_0 = input.LA(1);
			if ( (LA108_0==AND_ASSIGN||LA108_0==ASSIGN||LA108_0==BIT_SHIFT_RIGHT_ASSIGN||LA108_0==DIV_ASSIGN||LA108_0==MINUS_ASSIGN||LA108_0==MOD_ASSIGN||LA108_0==OR_ASSIGN||LA108_0==PLUS_ASSIGN||LA108_0==SHIFT_LEFT_ASSIGN||LA108_0==SHIFT_RIGHT_ASSIGN||LA108_0==STAR_ASSIGN||LA108_0==XOR_ASSIGN) ) {
				alt108=1;
			}
			switch (alt108) {
				case 1 :
					// Java.g:850:13: ( ASSIGN ^| PLUS_ASSIGN ^| MINUS_ASSIGN ^| STAR_ASSIGN ^| DIV_ASSIGN ^| AND_ASSIGN ^| OR_ASSIGN ^| XOR_ASSIGN ^| MOD_ASSIGN ^| SHIFT_LEFT_ASSIGN ^| SHIFT_RIGHT_ASSIGN ^| BIT_SHIFT_RIGHT_ASSIGN ^) assignmentExpression
					{
					// Java.g:850:13: ( ASSIGN ^| PLUS_ASSIGN ^| MINUS_ASSIGN ^| STAR_ASSIGN ^| DIV_ASSIGN ^| AND_ASSIGN ^| OR_ASSIGN ^| XOR_ASSIGN ^| MOD_ASSIGN ^| SHIFT_LEFT_ASSIGN ^| SHIFT_RIGHT_ASSIGN ^| BIT_SHIFT_RIGHT_ASSIGN ^)
					int alt107=12;
					switch ( input.LA(1) ) {
					case ASSIGN:
						{
						alt107=1;
						}
						break;
					case PLUS_ASSIGN:
						{
						alt107=2;
						}
						break;
					case MINUS_ASSIGN:
						{
						alt107=3;
						}
						break;
					case STAR_ASSIGN:
						{
						alt107=4;
						}
						break;
					case DIV_ASSIGN:
						{
						alt107=5;
						}
						break;
					case AND_ASSIGN:
						{
						alt107=6;
						}
						break;
					case OR_ASSIGN:
						{
						alt107=7;
						}
						break;
					case XOR_ASSIGN:
						{
						alt107=8;
						}
						break;
					case MOD_ASSIGN:
						{
						alt107=9;
						}
						break;
					case SHIFT_LEFT_ASSIGN:
						{
						alt107=10;
						}
						break;
					case SHIFT_RIGHT_ASSIGN:
						{
						alt107=11;
						}
						break;
					case BIT_SHIFT_RIGHT_ASSIGN:
						{
						alt107=12;
						}
						break;
					default:
						if (state.backtracking>0) {state.failed=true; return retval;}
						NoViableAltException nvae =
							new NoViableAltException("", 107, 0, input);
						throw nvae;
					}
					switch (alt107) {
						case 1 :
							// Java.g:850:17: ASSIGN ^
							{
							ASSIGN369=(Token)match(input,ASSIGN,FOLLOW_ASSIGN_in_assignmentExpression10547); if (state.failed) return retval;
							if ( state.backtracking==0 ) {
							ASSIGN369_tree = 
							(CommonTree)adaptor.create(ASSIGN369)
							;
							root_0 = (CommonTree)adaptor.becomeRoot(ASSIGN369_tree, root_0);
							}

							}
							break;
						case 2 :
							// Java.g:851:17: PLUS_ASSIGN ^
							{
							PLUS_ASSIGN370=(Token)match(input,PLUS_ASSIGN,FOLLOW_PLUS_ASSIGN_in_assignmentExpression10566); if (state.failed) return retval;
							if ( state.backtracking==0 ) {
							PLUS_ASSIGN370_tree = 
							(CommonTree)adaptor.create(PLUS_ASSIGN370)
							;
							root_0 = (CommonTree)adaptor.becomeRoot(PLUS_ASSIGN370_tree, root_0);
							}

							}
							break;
						case 3 :
							// Java.g:852:17: MINUS_ASSIGN ^
							{
							MINUS_ASSIGN371=(Token)match(input,MINUS_ASSIGN,FOLLOW_MINUS_ASSIGN_in_assignmentExpression10585); if (state.failed) return retval;
							if ( state.backtracking==0 ) {
							MINUS_ASSIGN371_tree = 
							(CommonTree)adaptor.create(MINUS_ASSIGN371)
							;
							root_0 = (CommonTree)adaptor.becomeRoot(MINUS_ASSIGN371_tree, root_0);
							}

							}
							break;
						case 4 :
							// Java.g:853:17: STAR_ASSIGN ^
							{
							STAR_ASSIGN372=(Token)match(input,STAR_ASSIGN,FOLLOW_STAR_ASSIGN_in_assignmentExpression10604); if (state.failed) return retval;
							if ( state.backtracking==0 ) {
							STAR_ASSIGN372_tree = 
							(CommonTree)adaptor.create(STAR_ASSIGN372)
							;
							root_0 = (CommonTree)adaptor.becomeRoot(STAR_ASSIGN372_tree, root_0);
							}

							}
							break;
						case 5 :
							// Java.g:854:17: DIV_ASSIGN ^
							{
							DIV_ASSIGN373=(Token)match(input,DIV_ASSIGN,FOLLOW_DIV_ASSIGN_in_assignmentExpression10623); if (state.failed) return retval;
							if ( state.backtracking==0 ) {
							DIV_ASSIGN373_tree = 
							(CommonTree)adaptor.create(DIV_ASSIGN373)
							;
							root_0 = (CommonTree)adaptor.becomeRoot(DIV_ASSIGN373_tree, root_0);
							}

							}
							break;
						case 6 :
							// Java.g:855:17: AND_ASSIGN ^
							{
							AND_ASSIGN374=(Token)match(input,AND_ASSIGN,FOLLOW_AND_ASSIGN_in_assignmentExpression10642); if (state.failed) return retval;
							if ( state.backtracking==0 ) {
							AND_ASSIGN374_tree = 
							(CommonTree)adaptor.create(AND_ASSIGN374)
							;
							root_0 = (CommonTree)adaptor.becomeRoot(AND_ASSIGN374_tree, root_0);
							}

							}
							break;
						case 7 :
							// Java.g:856:17: OR_ASSIGN ^
							{
							OR_ASSIGN375=(Token)match(input,OR_ASSIGN,FOLLOW_OR_ASSIGN_in_assignmentExpression10661); if (state.failed) return retval;
							if ( state.backtracking==0 ) {
							OR_ASSIGN375_tree = 
							(CommonTree)adaptor.create(OR_ASSIGN375)
							;
							root_0 = (CommonTree)adaptor.becomeRoot(OR_ASSIGN375_tree, root_0);
							}

							}
							break;
						case 8 :
							// Java.g:857:17: XOR_ASSIGN ^
							{
							XOR_ASSIGN376=(Token)match(input,XOR_ASSIGN,FOLLOW_XOR_ASSIGN_in_assignmentExpression10680); if (state.failed) return retval;
							if ( state.backtracking==0 ) {
							XOR_ASSIGN376_tree = 
							(CommonTree)adaptor.create(XOR_ASSIGN376)
							;
							root_0 = (CommonTree)adaptor.becomeRoot(XOR_ASSIGN376_tree, root_0);
							}

							}
							break;
						case 9 :
							// Java.g:858:17: MOD_ASSIGN ^
							{
							MOD_ASSIGN377=(Token)match(input,MOD_ASSIGN,FOLLOW_MOD_ASSIGN_in_assignmentExpression10699); if (state.failed) return retval;
							if ( state.backtracking==0 ) {
							MOD_ASSIGN377_tree = 
							(CommonTree)adaptor.create(MOD_ASSIGN377)
							;
							root_0 = (CommonTree)adaptor.becomeRoot(MOD_ASSIGN377_tree, root_0);
							}

							}
							break;
						case 10 :
							// Java.g:859:17: SHIFT_LEFT_ASSIGN ^
							{
							SHIFT_LEFT_ASSIGN378=(Token)match(input,SHIFT_LEFT_ASSIGN,FOLLOW_SHIFT_LEFT_ASSIGN_in_assignmentExpression10718); if (state.failed) return retval;
							if ( state.backtracking==0 ) {
							SHIFT_LEFT_ASSIGN378_tree = 
							(CommonTree)adaptor.create(SHIFT_LEFT_ASSIGN378)
							;
							root_0 = (CommonTree)adaptor.becomeRoot(SHIFT_LEFT_ASSIGN378_tree, root_0);
							}

							}
							break;
						case 11 :
							// Java.g:860:17: SHIFT_RIGHT_ASSIGN ^
							{
							SHIFT_RIGHT_ASSIGN379=(Token)match(input,SHIFT_RIGHT_ASSIGN,FOLLOW_SHIFT_RIGHT_ASSIGN_in_assignmentExpression10737); if (state.failed) return retval;
							if ( state.backtracking==0 ) {
							SHIFT_RIGHT_ASSIGN379_tree = 
							(CommonTree)adaptor.create(SHIFT_RIGHT_ASSIGN379)
							;
							root_0 = (CommonTree)adaptor.becomeRoot(SHIFT_RIGHT_ASSIGN379_tree, root_0);
							}

							}
							break;
						case 12 :
							// Java.g:861:17: BIT_SHIFT_RIGHT_ASSIGN ^
							{
							BIT_SHIFT_RIGHT_ASSIGN380=(Token)match(input,BIT_SHIFT_RIGHT_ASSIGN,FOLLOW_BIT_SHIFT_RIGHT_ASSIGN_in_assignmentExpression10756); if (state.failed) return retval;
							if ( state.backtracking==0 ) {
							BIT_SHIFT_RIGHT_ASSIGN380_tree = 
							(CommonTree)adaptor.create(BIT_SHIFT_RIGHT_ASSIGN380)
							;
							root_0 = (CommonTree)adaptor.becomeRoot(BIT_SHIFT_RIGHT_ASSIGN380_tree, root_0);
							}

							}
							break;

					}

					pushFollow(FOLLOW_assignmentExpression_in_assignmentExpression10778);
					assignmentExpression381=assignmentExpression();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) adaptor.addChild(root_0, assignmentExpression381.getTree());

					}
					break;

			}

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 89, assignmentExpression_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "assignmentExpression"


	public static class conditionalExpression_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "conditionalExpression"
	// Java.g:866:1: conditionalExpression : logicalOrExpression ( QUESTION ^ assignmentExpression COLON ! conditionalExpression )? ;
	public final JavaParser.conditionalExpression_return conditionalExpression() throws RecognitionException {
		JavaParser.conditionalExpression_return retval = new JavaParser.conditionalExpression_return();
		retval.start = input.LT(1);
		int conditionalExpression_StartIndex = input.index();

		CommonTree root_0 = null;

		Token QUESTION383=null;
		Token COLON385=null;
		ParserRuleReturnScope logicalOrExpression382 =null;
		ParserRuleReturnScope assignmentExpression384 =null;
		ParserRuleReturnScope conditionalExpression386 =null;

		CommonTree QUESTION383_tree=null;
		CommonTree COLON385_tree=null;

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 90) ) { return retval; }

			// Java.g:867:5: ( logicalOrExpression ( QUESTION ^ assignmentExpression COLON ! conditionalExpression )? )
			// Java.g:867:9: logicalOrExpression ( QUESTION ^ assignmentExpression COLON ! conditionalExpression )?
			{
			root_0 = (CommonTree)adaptor.nil();


			pushFollow(FOLLOW_logicalOrExpression_in_conditionalExpression10803);
			logicalOrExpression382=logicalOrExpression();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) adaptor.addChild(root_0, logicalOrExpression382.getTree());

			// Java.g:867:29: ( QUESTION ^ assignmentExpression COLON ! conditionalExpression )?
			int alt109=2;
			int LA109_0 = input.LA(1);
			if ( (LA109_0==QUESTION) ) {
				alt109=1;
			}
			switch (alt109) {
				case 1 :
					// Java.g:867:30: QUESTION ^ assignmentExpression COLON ! conditionalExpression
					{
					QUESTION383=(Token)match(input,QUESTION,FOLLOW_QUESTION_in_conditionalExpression10806); if (state.failed) return retval;
					if ( state.backtracking==0 ) {
					QUESTION383_tree = 
					(CommonTree)adaptor.create(QUESTION383)
					;
					root_0 = (CommonTree)adaptor.becomeRoot(QUESTION383_tree, root_0);
					}

					pushFollow(FOLLOW_assignmentExpression_in_conditionalExpression10809);
					assignmentExpression384=assignmentExpression();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) adaptor.addChild(root_0, assignmentExpression384.getTree());

					COLON385=(Token)match(input,COLON,FOLLOW_COLON_in_conditionalExpression10811); if (state.failed) return retval;
					pushFollow(FOLLOW_conditionalExpression_in_conditionalExpression10814);
					conditionalExpression386=conditionalExpression();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) adaptor.addChild(root_0, conditionalExpression386.getTree());

					}
					break;

			}

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 90, conditionalExpression_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "conditionalExpression"


	public static class logicalOrExpression_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "logicalOrExpression"
	// Java.g:870:1: logicalOrExpression : logicalAndExpression ( LOGICAL_OR ^ logicalAndExpression )* ;
	public final JavaParser.logicalOrExpression_return logicalOrExpression() throws RecognitionException {
		JavaParser.logicalOrExpression_return retval = new JavaParser.logicalOrExpression_return();
		retval.start = input.LT(1);
		int logicalOrExpression_StartIndex = input.index();

		CommonTree root_0 = null;

		Token LOGICAL_OR388=null;
		ParserRuleReturnScope logicalAndExpression387 =null;
		ParserRuleReturnScope logicalAndExpression389 =null;

		CommonTree LOGICAL_OR388_tree=null;

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 91) ) { return retval; }

			// Java.g:871:5: ( logicalAndExpression ( LOGICAL_OR ^ logicalAndExpression )* )
			// Java.g:871:9: logicalAndExpression ( LOGICAL_OR ^ logicalAndExpression )*
			{
			root_0 = (CommonTree)adaptor.nil();


			pushFollow(FOLLOW_logicalAndExpression_in_logicalOrExpression10835);
			logicalAndExpression387=logicalAndExpression();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) adaptor.addChild(root_0, logicalAndExpression387.getTree());

			// Java.g:871:30: ( LOGICAL_OR ^ logicalAndExpression )*
			loop110:
			do {
				int alt110=2;
				int LA110_0 = input.LA(1);
				if ( (LA110_0==LOGICAL_OR) ) {
					alt110=1;
				}

				switch (alt110) {
				case 1 :
					// Java.g:871:31: LOGICAL_OR ^ logicalAndExpression
					{
					LOGICAL_OR388=(Token)match(input,LOGICAL_OR,FOLLOW_LOGICAL_OR_in_logicalOrExpression10838); if (state.failed) return retval;
					if ( state.backtracking==0 ) {
					LOGICAL_OR388_tree = 
					(CommonTree)adaptor.create(LOGICAL_OR388)
					;
					root_0 = (CommonTree)adaptor.becomeRoot(LOGICAL_OR388_tree, root_0);
					}

					pushFollow(FOLLOW_logicalAndExpression_in_logicalOrExpression10841);
					logicalAndExpression389=logicalAndExpression();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) adaptor.addChild(root_0, logicalAndExpression389.getTree());

					}
					break;

				default :
					break loop110;
				}
			} while (true);

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 91, logicalOrExpression_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "logicalOrExpression"


	public static class logicalAndExpression_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "logicalAndExpression"
	// Java.g:874:1: logicalAndExpression : inclusiveOrExpression ( LOGICAL_AND ^ inclusiveOrExpression )* ;
	public final JavaParser.logicalAndExpression_return logicalAndExpression() throws RecognitionException {
		JavaParser.logicalAndExpression_return retval = new JavaParser.logicalAndExpression_return();
		retval.start = input.LT(1);
		int logicalAndExpression_StartIndex = input.index();

		CommonTree root_0 = null;

		Token LOGICAL_AND391=null;
		ParserRuleReturnScope inclusiveOrExpression390 =null;
		ParserRuleReturnScope inclusiveOrExpression392 =null;

		CommonTree LOGICAL_AND391_tree=null;

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 92) ) { return retval; }

			// Java.g:875:5: ( inclusiveOrExpression ( LOGICAL_AND ^ inclusiveOrExpression )* )
			// Java.g:875:9: inclusiveOrExpression ( LOGICAL_AND ^ inclusiveOrExpression )*
			{
			root_0 = (CommonTree)adaptor.nil();


			pushFollow(FOLLOW_inclusiveOrExpression_in_logicalAndExpression10862);
			inclusiveOrExpression390=inclusiveOrExpression();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) adaptor.addChild(root_0, inclusiveOrExpression390.getTree());

			// Java.g:875:31: ( LOGICAL_AND ^ inclusiveOrExpression )*
			loop111:
			do {
				int alt111=2;
				int LA111_0 = input.LA(1);
				if ( (LA111_0==LOGICAL_AND) ) {
					alt111=1;
				}

				switch (alt111) {
				case 1 :
					// Java.g:875:32: LOGICAL_AND ^ inclusiveOrExpression
					{
					LOGICAL_AND391=(Token)match(input,LOGICAL_AND,FOLLOW_LOGICAL_AND_in_logicalAndExpression10865); if (state.failed) return retval;
					if ( state.backtracking==0 ) {
					LOGICAL_AND391_tree = 
					(CommonTree)adaptor.create(LOGICAL_AND391)
					;
					root_0 = (CommonTree)adaptor.becomeRoot(LOGICAL_AND391_tree, root_0);
					}

					pushFollow(FOLLOW_inclusiveOrExpression_in_logicalAndExpression10868);
					inclusiveOrExpression392=inclusiveOrExpression();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) adaptor.addChild(root_0, inclusiveOrExpression392.getTree());

					}
					break;

				default :
					break loop111;
				}
			} while (true);

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 92, logicalAndExpression_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "logicalAndExpression"


	public static class inclusiveOrExpression_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "inclusiveOrExpression"
	// Java.g:878:1: inclusiveOrExpression : exclusiveOrExpression ( OR ^ exclusiveOrExpression )* ;
	public final JavaParser.inclusiveOrExpression_return inclusiveOrExpression() throws RecognitionException {
		JavaParser.inclusiveOrExpression_return retval = new JavaParser.inclusiveOrExpression_return();
		retval.start = input.LT(1);
		int inclusiveOrExpression_StartIndex = input.index();

		CommonTree root_0 = null;

		Token OR394=null;
		ParserRuleReturnScope exclusiveOrExpression393 =null;
		ParserRuleReturnScope exclusiveOrExpression395 =null;

		CommonTree OR394_tree=null;

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 93) ) { return retval; }

			// Java.g:879:5: ( exclusiveOrExpression ( OR ^ exclusiveOrExpression )* )
			// Java.g:879:9: exclusiveOrExpression ( OR ^ exclusiveOrExpression )*
			{
			root_0 = (CommonTree)adaptor.nil();


			pushFollow(FOLLOW_exclusiveOrExpression_in_inclusiveOrExpression10889);
			exclusiveOrExpression393=exclusiveOrExpression();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) adaptor.addChild(root_0, exclusiveOrExpression393.getTree());

			// Java.g:879:31: ( OR ^ exclusiveOrExpression )*
			loop112:
			do {
				int alt112=2;
				int LA112_0 = input.LA(1);
				if ( (LA112_0==OR) ) {
					alt112=1;
				}

				switch (alt112) {
				case 1 :
					// Java.g:879:32: OR ^ exclusiveOrExpression
					{
					OR394=(Token)match(input,OR,FOLLOW_OR_in_inclusiveOrExpression10892); if (state.failed) return retval;
					if ( state.backtracking==0 ) {
					OR394_tree = 
					(CommonTree)adaptor.create(OR394)
					;
					root_0 = (CommonTree)adaptor.becomeRoot(OR394_tree, root_0);
					}

					pushFollow(FOLLOW_exclusiveOrExpression_in_inclusiveOrExpression10895);
					exclusiveOrExpression395=exclusiveOrExpression();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) adaptor.addChild(root_0, exclusiveOrExpression395.getTree());

					}
					break;

				default :
					break loop112;
				}
			} while (true);

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 93, inclusiveOrExpression_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "inclusiveOrExpression"


	public static class exclusiveOrExpression_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "exclusiveOrExpression"
	// Java.g:882:1: exclusiveOrExpression : andExpression ( XOR ^ andExpression )* ;
	public final JavaParser.exclusiveOrExpression_return exclusiveOrExpression() throws RecognitionException {
		JavaParser.exclusiveOrExpression_return retval = new JavaParser.exclusiveOrExpression_return();
		retval.start = input.LT(1);
		int exclusiveOrExpression_StartIndex = input.index();

		CommonTree root_0 = null;

		Token XOR397=null;
		ParserRuleReturnScope andExpression396 =null;
		ParserRuleReturnScope andExpression398 =null;

		CommonTree XOR397_tree=null;

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 94) ) { return retval; }

			// Java.g:883:5: ( andExpression ( XOR ^ andExpression )* )
			// Java.g:883:9: andExpression ( XOR ^ andExpression )*
			{
			root_0 = (CommonTree)adaptor.nil();


			pushFollow(FOLLOW_andExpression_in_exclusiveOrExpression10916);
			andExpression396=andExpression();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) adaptor.addChild(root_0, andExpression396.getTree());

			// Java.g:883:23: ( XOR ^ andExpression )*
			loop113:
			do {
				int alt113=2;
				int LA113_0 = input.LA(1);
				if ( (LA113_0==XOR) ) {
					alt113=1;
				}

				switch (alt113) {
				case 1 :
					// Java.g:883:24: XOR ^ andExpression
					{
					XOR397=(Token)match(input,XOR,FOLLOW_XOR_in_exclusiveOrExpression10919); if (state.failed) return retval;
					if ( state.backtracking==0 ) {
					XOR397_tree = 
					(CommonTree)adaptor.create(XOR397)
					;
					root_0 = (CommonTree)adaptor.becomeRoot(XOR397_tree, root_0);
					}

					pushFollow(FOLLOW_andExpression_in_exclusiveOrExpression10922);
					andExpression398=andExpression();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) adaptor.addChild(root_0, andExpression398.getTree());

					}
					break;

				default :
					break loop113;
				}
			} while (true);

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 94, exclusiveOrExpression_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "exclusiveOrExpression"


	public static class andExpression_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "andExpression"
	// Java.g:886:1: andExpression : equalityExpression ( AND ^ equalityExpression )* ;
	public final JavaParser.andExpression_return andExpression() throws RecognitionException {
		JavaParser.andExpression_return retval = new JavaParser.andExpression_return();
		retval.start = input.LT(1);
		int andExpression_StartIndex = input.index();

		CommonTree root_0 = null;

		Token AND400=null;
		ParserRuleReturnScope equalityExpression399 =null;
		ParserRuleReturnScope equalityExpression401 =null;

		CommonTree AND400_tree=null;

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 95) ) { return retval; }

			// Java.g:887:5: ( equalityExpression ( AND ^ equalityExpression )* )
			// Java.g:887:9: equalityExpression ( AND ^ equalityExpression )*
			{
			root_0 = (CommonTree)adaptor.nil();


			pushFollow(FOLLOW_equalityExpression_in_andExpression10943);
			equalityExpression399=equalityExpression();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) adaptor.addChild(root_0, equalityExpression399.getTree());

			// Java.g:887:28: ( AND ^ equalityExpression )*
			loop114:
			do {
				int alt114=2;
				int LA114_0 = input.LA(1);
				if ( (LA114_0==AND) ) {
					alt114=1;
				}

				switch (alt114) {
				case 1 :
					// Java.g:887:29: AND ^ equalityExpression
					{
					AND400=(Token)match(input,AND,FOLLOW_AND_in_andExpression10946); if (state.failed) return retval;
					if ( state.backtracking==0 ) {
					AND400_tree = 
					(CommonTree)adaptor.create(AND400)
					;
					root_0 = (CommonTree)adaptor.becomeRoot(AND400_tree, root_0);
					}

					pushFollow(FOLLOW_equalityExpression_in_andExpression10949);
					equalityExpression401=equalityExpression();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) adaptor.addChild(root_0, equalityExpression401.getTree());

					}
					break;

				default :
					break loop114;
				}
			} while (true);

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 95, andExpression_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "andExpression"


	public static class equalityExpression_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "equalityExpression"
	// Java.g:890:1: equalityExpression : instanceOfExpression ( ( EQUAL ^| NOT_EQUAL ^) instanceOfExpression )* ;
	public final JavaParser.equalityExpression_return equalityExpression() throws RecognitionException {
		JavaParser.equalityExpression_return retval = new JavaParser.equalityExpression_return();
		retval.start = input.LT(1);
		int equalityExpression_StartIndex = input.index();

		CommonTree root_0 = null;

		Token EQUAL403=null;
		Token NOT_EQUAL404=null;
		ParserRuleReturnScope instanceOfExpression402 =null;
		ParserRuleReturnScope instanceOfExpression405 =null;

		CommonTree EQUAL403_tree=null;
		CommonTree NOT_EQUAL404_tree=null;

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 96) ) { return retval; }

			// Java.g:891:5: ( instanceOfExpression ( ( EQUAL ^| NOT_EQUAL ^) instanceOfExpression )* )
			// Java.g:891:9: instanceOfExpression ( ( EQUAL ^| NOT_EQUAL ^) instanceOfExpression )*
			{
			root_0 = (CommonTree)adaptor.nil();


			pushFollow(FOLLOW_instanceOfExpression_in_equalityExpression10970);
			instanceOfExpression402=instanceOfExpression();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) adaptor.addChild(root_0, instanceOfExpression402.getTree());

			// Java.g:892:9: ( ( EQUAL ^| NOT_EQUAL ^) instanceOfExpression )*
			loop116:
			do {
				int alt116=2;
				int LA116_0 = input.LA(1);
				if ( (LA116_0==EQUAL||LA116_0==NOT_EQUAL) ) {
					alt116=1;
				}

				switch (alt116) {
				case 1 :
					// Java.g:892:13: ( EQUAL ^| NOT_EQUAL ^) instanceOfExpression
					{
					// Java.g:892:13: ( EQUAL ^| NOT_EQUAL ^)
					int alt115=2;
					int LA115_0 = input.LA(1);
					if ( (LA115_0==EQUAL) ) {
						alt115=1;
					}
					else if ( (LA115_0==NOT_EQUAL) ) {
						alt115=2;
					}
					else {
						if (state.backtracking>0) {state.failed=true; return retval;}
						NoViableAltException nvae =
							new NoViableAltException("", 115, 0, input);
						throw nvae;
					}
					switch (alt115) {
						case 1 :
							// Java.g:892:17: EQUAL ^
							{
							EQUAL403=(Token)match(input,EQUAL,FOLLOW_EQUAL_in_equalityExpression10989); if (state.failed) return retval;
							if ( state.backtracking==0 ) {
							EQUAL403_tree = 
							(CommonTree)adaptor.create(EQUAL403)
							;
							root_0 = (CommonTree)adaptor.becomeRoot(EQUAL403_tree, root_0);
							}

							}
							break;
						case 2 :
							// Java.g:893:17: NOT_EQUAL ^
							{
							NOT_EQUAL404=(Token)match(input,NOT_EQUAL,FOLLOW_NOT_EQUAL_in_equalityExpression11008); if (state.failed) return retval;
							if ( state.backtracking==0 ) {
							NOT_EQUAL404_tree = 
							(CommonTree)adaptor.create(NOT_EQUAL404)
							;
							root_0 = (CommonTree)adaptor.becomeRoot(NOT_EQUAL404_tree, root_0);
							}

							}
							break;

					}

					pushFollow(FOLLOW_instanceOfExpression_in_equalityExpression11038);
					instanceOfExpression405=instanceOfExpression();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) adaptor.addChild(root_0, instanceOfExpression405.getTree());

					}
					break;

				default :
					break loop116;
				}
			} while (true);

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 96, equalityExpression_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "equalityExpression"


	public static class instanceOfExpression_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "instanceOfExpression"
	// Java.g:899:1: instanceOfExpression : relationalExpression ( INSTANCEOF ^ type )? ;
	public final JavaParser.instanceOfExpression_return instanceOfExpression() throws RecognitionException {
		JavaParser.instanceOfExpression_return retval = new JavaParser.instanceOfExpression_return();
		retval.start = input.LT(1);
		int instanceOfExpression_StartIndex = input.index();

		CommonTree root_0 = null;

		Token INSTANCEOF407=null;
		ParserRuleReturnScope relationalExpression406 =null;
		ParserRuleReturnScope type408 =null;

		CommonTree INSTANCEOF407_tree=null;

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 97) ) { return retval; }

			// Java.g:900:5: ( relationalExpression ( INSTANCEOF ^ type )? )
			// Java.g:900:9: relationalExpression ( INSTANCEOF ^ type )?
			{
			root_0 = (CommonTree)adaptor.nil();


			pushFollow(FOLLOW_relationalExpression_in_instanceOfExpression11068);
			relationalExpression406=relationalExpression();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) adaptor.addChild(root_0, relationalExpression406.getTree());

			// Java.g:900:30: ( INSTANCEOF ^ type )?
			int alt117=2;
			int LA117_0 = input.LA(1);
			if ( (LA117_0==INSTANCEOF) ) {
				alt117=1;
			}
			switch (alt117) {
				case 1 :
					// Java.g:900:31: INSTANCEOF ^ type
					{
					INSTANCEOF407=(Token)match(input,INSTANCEOF,FOLLOW_INSTANCEOF_in_instanceOfExpression11071); if (state.failed) return retval;
					if ( state.backtracking==0 ) {
					INSTANCEOF407_tree = 
					(CommonTree)adaptor.create(INSTANCEOF407)
					;
					root_0 = (CommonTree)adaptor.becomeRoot(INSTANCEOF407_tree, root_0);
					}

					pushFollow(FOLLOW_type_in_instanceOfExpression11074);
					type408=type();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) adaptor.addChild(root_0, type408.getTree());

					}
					break;

			}

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 97, instanceOfExpression_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "instanceOfExpression"


	public static class relationalExpression_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "relationalExpression"
	// Java.g:903:1: relationalExpression : shiftExpression ( ( LESS_OR_EQUAL ^| GREATER_OR_EQUAL ^| LESS_THAN ^| GREATER_THAN ^) shiftExpression )* ;
	public final JavaParser.relationalExpression_return relationalExpression() throws RecognitionException {
		JavaParser.relationalExpression_return retval = new JavaParser.relationalExpression_return();
		retval.start = input.LT(1);
		int relationalExpression_StartIndex = input.index();

		CommonTree root_0 = null;

		Token LESS_OR_EQUAL410=null;
		Token GREATER_OR_EQUAL411=null;
		Token LESS_THAN412=null;
		Token GREATER_THAN413=null;
		ParserRuleReturnScope shiftExpression409 =null;
		ParserRuleReturnScope shiftExpression414 =null;

		CommonTree LESS_OR_EQUAL410_tree=null;
		CommonTree GREATER_OR_EQUAL411_tree=null;
		CommonTree LESS_THAN412_tree=null;
		CommonTree GREATER_THAN413_tree=null;

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 98) ) { return retval; }

			// Java.g:904:5: ( shiftExpression ( ( LESS_OR_EQUAL ^| GREATER_OR_EQUAL ^| LESS_THAN ^| GREATER_THAN ^) shiftExpression )* )
			// Java.g:904:9: shiftExpression ( ( LESS_OR_EQUAL ^| GREATER_OR_EQUAL ^| LESS_THAN ^| GREATER_THAN ^) shiftExpression )*
			{
			root_0 = (CommonTree)adaptor.nil();


			pushFollow(FOLLOW_shiftExpression_in_relationalExpression11095);
			shiftExpression409=shiftExpression();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) adaptor.addChild(root_0, shiftExpression409.getTree());

			// Java.g:905:9: ( ( LESS_OR_EQUAL ^| GREATER_OR_EQUAL ^| LESS_THAN ^| GREATER_THAN ^) shiftExpression )*
			loop119:
			do {
				int alt119=2;
				int LA119_0 = input.LA(1);
				if ( ((LA119_0 >= GREATER_OR_EQUAL && LA119_0 <= GREATER_THAN)||(LA119_0 >= LESS_OR_EQUAL && LA119_0 <= LESS_THAN)) ) {
					alt119=1;
				}

				switch (alt119) {
				case 1 :
					// Java.g:905:13: ( LESS_OR_EQUAL ^| GREATER_OR_EQUAL ^| LESS_THAN ^| GREATER_THAN ^) shiftExpression
					{
					// Java.g:905:13: ( LESS_OR_EQUAL ^| GREATER_OR_EQUAL ^| LESS_THAN ^| GREATER_THAN ^)
					int alt118=4;
					switch ( input.LA(1) ) {
					case LESS_OR_EQUAL:
						{
						alt118=1;
						}
						break;
					case GREATER_OR_EQUAL:
						{
						alt118=2;
						}
						break;
					case LESS_THAN:
						{
						alt118=3;
						}
						break;
					case GREATER_THAN:
						{
						alt118=4;
						}
						break;
					default:
						if (state.backtracking>0) {state.failed=true; return retval;}
						NoViableAltException nvae =
							new NoViableAltException("", 118, 0, input);
						throw nvae;
					}
					switch (alt118) {
						case 1 :
							// Java.g:905:17: LESS_OR_EQUAL ^
							{
							LESS_OR_EQUAL410=(Token)match(input,LESS_OR_EQUAL,FOLLOW_LESS_OR_EQUAL_in_relationalExpression11114); if (state.failed) return retval;
							if ( state.backtracking==0 ) {
							LESS_OR_EQUAL410_tree = 
							(CommonTree)adaptor.create(LESS_OR_EQUAL410)
							;
							root_0 = (CommonTree)adaptor.becomeRoot(LESS_OR_EQUAL410_tree, root_0);
							}

							}
							break;
						case 2 :
							// Java.g:906:17: GREATER_OR_EQUAL ^
							{
							GREATER_OR_EQUAL411=(Token)match(input,GREATER_OR_EQUAL,FOLLOW_GREATER_OR_EQUAL_in_relationalExpression11133); if (state.failed) return retval;
							if ( state.backtracking==0 ) {
							GREATER_OR_EQUAL411_tree = 
							(CommonTree)adaptor.create(GREATER_OR_EQUAL411)
							;
							root_0 = (CommonTree)adaptor.becomeRoot(GREATER_OR_EQUAL411_tree, root_0);
							}

							}
							break;
						case 3 :
							// Java.g:907:17: LESS_THAN ^
							{
							LESS_THAN412=(Token)match(input,LESS_THAN,FOLLOW_LESS_THAN_in_relationalExpression11152); if (state.failed) return retval;
							if ( state.backtracking==0 ) {
							LESS_THAN412_tree = 
							(CommonTree)adaptor.create(LESS_THAN412)
							;
							root_0 = (CommonTree)adaptor.becomeRoot(LESS_THAN412_tree, root_0);
							}

							}
							break;
						case 4 :
							// Java.g:908:17: GREATER_THAN ^
							{
							GREATER_THAN413=(Token)match(input,GREATER_THAN,FOLLOW_GREATER_THAN_in_relationalExpression11171); if (state.failed) return retval;
							if ( state.backtracking==0 ) {
							GREATER_THAN413_tree = 
							(CommonTree)adaptor.create(GREATER_THAN413)
							;
							root_0 = (CommonTree)adaptor.becomeRoot(GREATER_THAN413_tree, root_0);
							}

							}
							break;

					}

					pushFollow(FOLLOW_shiftExpression_in_relationalExpression11200);
					shiftExpression414=shiftExpression();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) adaptor.addChild(root_0, shiftExpression414.getTree());

					}
					break;

				default :
					break loop119;
				}
			} while (true);

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 98, relationalExpression_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "relationalExpression"


	public static class shiftExpression_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "shiftExpression"
	// Java.g:914:1: shiftExpression : additiveExpression ( ( BIT_SHIFT_RIGHT ^| SHIFT_RIGHT ^| SHIFT_LEFT ^) additiveExpression )* ;
	public final JavaParser.shiftExpression_return shiftExpression() throws RecognitionException {
		JavaParser.shiftExpression_return retval = new JavaParser.shiftExpression_return();
		retval.start = input.LT(1);
		int shiftExpression_StartIndex = input.index();

		CommonTree root_0 = null;

		Token BIT_SHIFT_RIGHT416=null;
		Token SHIFT_RIGHT417=null;
		Token SHIFT_LEFT418=null;
		ParserRuleReturnScope additiveExpression415 =null;
		ParserRuleReturnScope additiveExpression419 =null;

		CommonTree BIT_SHIFT_RIGHT416_tree=null;
		CommonTree SHIFT_RIGHT417_tree=null;
		CommonTree SHIFT_LEFT418_tree=null;

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 99) ) { return retval; }

			// Java.g:915:5: ( additiveExpression ( ( BIT_SHIFT_RIGHT ^| SHIFT_RIGHT ^| SHIFT_LEFT ^) additiveExpression )* )
			// Java.g:915:9: additiveExpression ( ( BIT_SHIFT_RIGHT ^| SHIFT_RIGHT ^| SHIFT_LEFT ^) additiveExpression )*
			{
			root_0 = (CommonTree)adaptor.nil();


			pushFollow(FOLLOW_additiveExpression_in_shiftExpression11234);
			additiveExpression415=additiveExpression();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) adaptor.addChild(root_0, additiveExpression415.getTree());

			// Java.g:916:9: ( ( BIT_SHIFT_RIGHT ^| SHIFT_RIGHT ^| SHIFT_LEFT ^) additiveExpression )*
			loop121:
			do {
				int alt121=2;
				int LA121_0 = input.LA(1);
				if ( (LA121_0==BIT_SHIFT_RIGHT||LA121_0==SHIFT_LEFT||LA121_0==SHIFT_RIGHT) ) {
					alt121=1;
				}

				switch (alt121) {
				case 1 :
					// Java.g:916:13: ( BIT_SHIFT_RIGHT ^| SHIFT_RIGHT ^| SHIFT_LEFT ^) additiveExpression
					{
					// Java.g:916:13: ( BIT_SHIFT_RIGHT ^| SHIFT_RIGHT ^| SHIFT_LEFT ^)
					int alt120=3;
					switch ( input.LA(1) ) {
					case BIT_SHIFT_RIGHT:
						{
						alt120=1;
						}
						break;
					case SHIFT_RIGHT:
						{
						alt120=2;
						}
						break;
					case SHIFT_LEFT:
						{
						alt120=3;
						}
						break;
					default:
						if (state.backtracking>0) {state.failed=true; return retval;}
						NoViableAltException nvae =
							new NoViableAltException("", 120, 0, input);
						throw nvae;
					}
					switch (alt120) {
						case 1 :
							// Java.g:916:17: BIT_SHIFT_RIGHT ^
							{
							BIT_SHIFT_RIGHT416=(Token)match(input,BIT_SHIFT_RIGHT,FOLLOW_BIT_SHIFT_RIGHT_in_shiftExpression11252); if (state.failed) return retval;
							if ( state.backtracking==0 ) {
							BIT_SHIFT_RIGHT416_tree = 
							(CommonTree)adaptor.create(BIT_SHIFT_RIGHT416)
							;
							root_0 = (CommonTree)adaptor.becomeRoot(BIT_SHIFT_RIGHT416_tree, root_0);
							}

							}
							break;
						case 2 :
							// Java.g:917:17: SHIFT_RIGHT ^
							{
							SHIFT_RIGHT417=(Token)match(input,SHIFT_RIGHT,FOLLOW_SHIFT_RIGHT_in_shiftExpression11271); if (state.failed) return retval;
							if ( state.backtracking==0 ) {
							SHIFT_RIGHT417_tree = 
							(CommonTree)adaptor.create(SHIFT_RIGHT417)
							;
							root_0 = (CommonTree)adaptor.becomeRoot(SHIFT_RIGHT417_tree, root_0);
							}

							}
							break;
						case 3 :
							// Java.g:918:17: SHIFT_LEFT ^
							{
							SHIFT_LEFT418=(Token)match(input,SHIFT_LEFT,FOLLOW_SHIFT_LEFT_in_shiftExpression11290); if (state.failed) return retval;
							if ( state.backtracking==0 ) {
							SHIFT_LEFT418_tree = 
							(CommonTree)adaptor.create(SHIFT_LEFT418)
							;
							root_0 = (CommonTree)adaptor.becomeRoot(SHIFT_LEFT418_tree, root_0);
							}

							}
							break;

					}

					pushFollow(FOLLOW_additiveExpression_in_shiftExpression11319);
					additiveExpression419=additiveExpression();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) adaptor.addChild(root_0, additiveExpression419.getTree());

					}
					break;

				default :
					break loop121;
				}
			} while (true);

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 99, shiftExpression_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "shiftExpression"


	public static class additiveExpression_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "additiveExpression"
	// Java.g:924:1: additiveExpression : multiplicativeExpression ( ( PLUS ^| MINUS ^) multiplicativeExpression )* ;
	public final JavaParser.additiveExpression_return additiveExpression() throws RecognitionException {
		JavaParser.additiveExpression_return retval = new JavaParser.additiveExpression_return();
		retval.start = input.LT(1);
		int additiveExpression_StartIndex = input.index();

		CommonTree root_0 = null;

		Token PLUS421=null;
		Token MINUS422=null;
		ParserRuleReturnScope multiplicativeExpression420 =null;
		ParserRuleReturnScope multiplicativeExpression423 =null;

		CommonTree PLUS421_tree=null;
		CommonTree MINUS422_tree=null;

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 100) ) { return retval; }

			// Java.g:925:5: ( multiplicativeExpression ( ( PLUS ^| MINUS ^) multiplicativeExpression )* )
			// Java.g:925:9: multiplicativeExpression ( ( PLUS ^| MINUS ^) multiplicativeExpression )*
			{
			root_0 = (CommonTree)adaptor.nil();


			pushFollow(FOLLOW_multiplicativeExpression_in_additiveExpression11349);
			multiplicativeExpression420=multiplicativeExpression();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) adaptor.addChild(root_0, multiplicativeExpression420.getTree());

			// Java.g:926:9: ( ( PLUS ^| MINUS ^) multiplicativeExpression )*
			loop123:
			do {
				int alt123=2;
				int LA123_0 = input.LA(1);
				if ( (LA123_0==MINUS||LA123_0==PLUS) ) {
					alt123=1;
				}

				switch (alt123) {
				case 1 :
					// Java.g:926:13: ( PLUS ^| MINUS ^) multiplicativeExpression
					{
					// Java.g:926:13: ( PLUS ^| MINUS ^)
					int alt122=2;
					int LA122_0 = input.LA(1);
					if ( (LA122_0==PLUS) ) {
						alt122=1;
					}
					else if ( (LA122_0==MINUS) ) {
						alt122=2;
					}
					else {
						if (state.backtracking>0) {state.failed=true; return retval;}
						NoViableAltException nvae =
							new NoViableAltException("", 122, 0, input);
						throw nvae;
					}
					switch (alt122) {
						case 1 :
							// Java.g:926:17: PLUS ^
							{
							PLUS421=(Token)match(input,PLUS,FOLLOW_PLUS_in_additiveExpression11367); if (state.failed) return retval;
							if ( state.backtracking==0 ) {
							PLUS421_tree = 
							(CommonTree)adaptor.create(PLUS421)
							;
							root_0 = (CommonTree)adaptor.becomeRoot(PLUS421_tree, root_0);
							}

							}
							break;
						case 2 :
							// Java.g:927:17: MINUS ^
							{
							MINUS422=(Token)match(input,MINUS,FOLLOW_MINUS_in_additiveExpression11386); if (state.failed) return retval;
							if ( state.backtracking==0 ) {
							MINUS422_tree = 
							(CommonTree)adaptor.create(MINUS422)
							;
							root_0 = (CommonTree)adaptor.becomeRoot(MINUS422_tree, root_0);
							}

							}
							break;

					}

					pushFollow(FOLLOW_multiplicativeExpression_in_additiveExpression11415);
					multiplicativeExpression423=multiplicativeExpression();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) adaptor.addChild(root_0, multiplicativeExpression423.getTree());

					}
					break;

				default :
					break loop123;
				}
			} while (true);

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 100, additiveExpression_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "additiveExpression"


	public static class multiplicativeExpression_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "multiplicativeExpression"
	// Java.g:933:1: multiplicativeExpression : unaryExpression ( ( STAR ^| DIV ^| MOD ^) unaryExpression )* ;
	public final JavaParser.multiplicativeExpression_return multiplicativeExpression() throws RecognitionException {
		JavaParser.multiplicativeExpression_return retval = new JavaParser.multiplicativeExpression_return();
		retval.start = input.LT(1);
		int multiplicativeExpression_StartIndex = input.index();

		CommonTree root_0 = null;

		Token STAR425=null;
		Token DIV426=null;
		Token MOD427=null;
		ParserRuleReturnScope unaryExpression424 =null;
		ParserRuleReturnScope unaryExpression428 =null;

		CommonTree STAR425_tree=null;
		CommonTree DIV426_tree=null;
		CommonTree MOD427_tree=null;

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 101) ) { return retval; }

			// Java.g:934:5: ( unaryExpression ( ( STAR ^| DIV ^| MOD ^) unaryExpression )* )
			// Java.g:934:9: unaryExpression ( ( STAR ^| DIV ^| MOD ^) unaryExpression )*
			{
			root_0 = (CommonTree)adaptor.nil();


			pushFollow(FOLLOW_unaryExpression_in_multiplicativeExpression11445);
			unaryExpression424=unaryExpression();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) adaptor.addChild(root_0, unaryExpression424.getTree());

			// Java.g:935:9: ( ( STAR ^| DIV ^| MOD ^) unaryExpression )*
			loop125:
			do {
				int alt125=2;
				int LA125_0 = input.LA(1);
				if ( (LA125_0==DIV||LA125_0==MOD||LA125_0==STAR) ) {
					alt125=1;
				}

				switch (alt125) {
				case 1 :
					// Java.g:935:13: ( STAR ^| DIV ^| MOD ^) unaryExpression
					{
					// Java.g:935:13: ( STAR ^| DIV ^| MOD ^)
					int alt124=3;
					switch ( input.LA(1) ) {
					case STAR:
						{
						alt124=1;
						}
						break;
					case DIV:
						{
						alt124=2;
						}
						break;
					case MOD:
						{
						alt124=3;
						}
						break;
					default:
						if (state.backtracking>0) {state.failed=true; return retval;}
						NoViableAltException nvae =
							new NoViableAltException("", 124, 0, input);
						throw nvae;
					}
					switch (alt124) {
						case 1 :
							// Java.g:935:17: STAR ^
							{
							STAR425=(Token)match(input,STAR,FOLLOW_STAR_in_multiplicativeExpression11464); if (state.failed) return retval;
							if ( state.backtracking==0 ) {
							STAR425_tree = 
							(CommonTree)adaptor.create(STAR425)
							;
							root_0 = (CommonTree)adaptor.becomeRoot(STAR425_tree, root_0);
							}

							}
							break;
						case 2 :
							// Java.g:936:17: DIV ^
							{
							DIV426=(Token)match(input,DIV,FOLLOW_DIV_in_multiplicativeExpression11483); if (state.failed) return retval;
							if ( state.backtracking==0 ) {
							DIV426_tree = 
							(CommonTree)adaptor.create(DIV426)
							;
							root_0 = (CommonTree)adaptor.becomeRoot(DIV426_tree, root_0);
							}

							}
							break;
						case 3 :
							// Java.g:937:17: MOD ^
							{
							MOD427=(Token)match(input,MOD,FOLLOW_MOD_in_multiplicativeExpression11502); if (state.failed) return retval;
							if ( state.backtracking==0 ) {
							MOD427_tree = 
							(CommonTree)adaptor.create(MOD427)
							;
							root_0 = (CommonTree)adaptor.becomeRoot(MOD427_tree, root_0);
							}

							}
							break;

					}

					pushFollow(FOLLOW_unaryExpression_in_multiplicativeExpression11531);
					unaryExpression428=unaryExpression();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) adaptor.addChild(root_0, unaryExpression428.getTree());

					}
					break;

				default :
					break loop125;
				}
			} while (true);

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 101, multiplicativeExpression_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "multiplicativeExpression"


	public static class unaryExpression_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "unaryExpression"
	// Java.g:943:1: unaryExpression : ( PLUS unaryExpression -> ^( UNARY_PLUS[$PLUS, \"UNARY_PLUS\"] unaryExpression ) | MINUS unaryExpression -> ^( UNARY_MINUS[$MINUS, \"UNARY_MINUS\"] unaryExpression ) | INC postfixedExpression -> ^( PRE_INC[$INC, \"PRE_INC\"] postfixedExpression ) | DEC postfixedExpression -> ^( PRE_DEC[$DEC, \"PRE_DEC\"] postfixedExpression ) | unaryExpressionNotPlusMinus );
	public final JavaParser.unaryExpression_return unaryExpression() throws RecognitionException {
		JavaParser.unaryExpression_return retval = new JavaParser.unaryExpression_return();
		retval.start = input.LT(1);
		int unaryExpression_StartIndex = input.index();

		CommonTree root_0 = null;

		Token PLUS429=null;
		Token MINUS431=null;
		Token INC433=null;
		Token DEC435=null;
		ParserRuleReturnScope unaryExpression430 =null;
		ParserRuleReturnScope unaryExpression432 =null;
		ParserRuleReturnScope postfixedExpression434 =null;
		ParserRuleReturnScope postfixedExpression436 =null;
		ParserRuleReturnScope unaryExpressionNotPlusMinus437 =null;

		CommonTree PLUS429_tree=null;
		CommonTree MINUS431_tree=null;
		CommonTree INC433_tree=null;
		CommonTree DEC435_tree=null;
		RewriteRuleTokenStream stream_DEC=new RewriteRuleTokenStream(adaptor,"token DEC");
		RewriteRuleTokenStream stream_INC=new RewriteRuleTokenStream(adaptor,"token INC");
		RewriteRuleTokenStream stream_PLUS=new RewriteRuleTokenStream(adaptor,"token PLUS");
		RewriteRuleTokenStream stream_MINUS=new RewriteRuleTokenStream(adaptor,"token MINUS");
		RewriteRuleSubtreeStream stream_postfixedExpression=new RewriteRuleSubtreeStream(adaptor,"rule postfixedExpression");
		RewriteRuleSubtreeStream stream_unaryExpression=new RewriteRuleSubtreeStream(adaptor,"rule unaryExpression");

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 102) ) { return retval; }

			// Java.g:944:5: ( PLUS unaryExpression -> ^( UNARY_PLUS[$PLUS, \"UNARY_PLUS\"] unaryExpression ) | MINUS unaryExpression -> ^( UNARY_MINUS[$MINUS, \"UNARY_MINUS\"] unaryExpression ) | INC postfixedExpression -> ^( PRE_INC[$INC, \"PRE_INC\"] postfixedExpression ) | DEC postfixedExpression -> ^( PRE_DEC[$DEC, \"PRE_DEC\"] postfixedExpression ) | unaryExpressionNotPlusMinus )
			int alt126=5;
			switch ( input.LA(1) ) {
			case PLUS:
				{
				alt126=1;
				}
				break;
			case MINUS:
				{
				alt126=2;
				}
				break;
			case INC:
				{
				alt126=3;
				}
				break;
			case DEC:
				{
				alt126=4;
				}
				break;
			case BOOLEAN:
			case BYTE:
			case CHAR:
			case CHARACTER_LITERAL:
			case DECIMAL_LITERAL:
			case DOUBLE:
			case FALSE:
			case FLOAT:
			case FLOATING_POINT_LITERAL:
			case HEX_LITERAL:
			case IDENT:
			case INT:
			case LESS_THAN:
			case LOGICAL_NOT:
			case LONG:
			case LPAREN:
			case NEW:
			case NOT:
			case NULL:
			case OCTAL_LITERAL:
			case SHORT:
			case STRING_LITERAL:
			case SUPER:
			case THIS:
			case TRUE:
			case VOID:
				{
				alt126=5;
				}
				break;
			default:
				if (state.backtracking>0) {state.failed=true; return retval;}
				NoViableAltException nvae =
					new NoViableAltException("", 126, 0, input);
				throw nvae;
			}
			switch (alt126) {
				case 1 :
					// Java.g:944:9: PLUS unaryExpression
					{
					PLUS429=(Token)match(input,PLUS,FOLLOW_PLUS_in_unaryExpression11565); if (state.failed) return retval; 
					if ( state.backtracking==0 ) stream_PLUS.add(PLUS429);

					pushFollow(FOLLOW_unaryExpression_in_unaryExpression11567);
					unaryExpression430=unaryExpression();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_unaryExpression.add(unaryExpression430.getTree());
					// AST REWRITE
					// elements: unaryExpression
					// token labels: 
					// rule labels: retval
					// token list labels: 
					// rule list labels: 
					// wildcard labels: 
					if ( state.backtracking==0 ) {

					retval.tree = root_0;
					RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

					root_0 = (CommonTree)adaptor.nil();
					// 944:37: -> ^( UNARY_PLUS[$PLUS, \"UNARY_PLUS\"] unaryExpression )
					{
						// Java.g:944:41: ^( UNARY_PLUS[$PLUS, \"UNARY_PLUS\"] unaryExpression )
						{
						CommonTree root_1 = (CommonTree)adaptor.nil();
						root_1 = (CommonTree)adaptor.becomeRoot(
						(CommonTree)adaptor.create(UNARY_PLUS, PLUS429, "UNARY_PLUS")
						, root_1);

						adaptor.addChild(root_1, stream_unaryExpression.nextTree());

						adaptor.addChild(root_0, root_1);
						}

					}


					retval.tree = root_0;
					}

					}
					break;
				case 2 :
					// Java.g:945:9: MINUS unaryExpression
					{
					MINUS431=(Token)match(input,MINUS,FOLLOW_MINUS_in_unaryExpression11594); if (state.failed) return retval; 
					if ( state.backtracking==0 ) stream_MINUS.add(MINUS431);

					pushFollow(FOLLOW_unaryExpression_in_unaryExpression11596);
					unaryExpression432=unaryExpression();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_unaryExpression.add(unaryExpression432.getTree());
					// AST REWRITE
					// elements: unaryExpression
					// token labels: 
					// rule labels: retval
					// token list labels: 
					// rule list labels: 
					// wildcard labels: 
					if ( state.backtracking==0 ) {

					retval.tree = root_0;
					RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

					root_0 = (CommonTree)adaptor.nil();
					// 945:37: -> ^( UNARY_MINUS[$MINUS, \"UNARY_MINUS\"] unaryExpression )
					{
						// Java.g:945:41: ^( UNARY_MINUS[$MINUS, \"UNARY_MINUS\"] unaryExpression )
						{
						CommonTree root_1 = (CommonTree)adaptor.nil();
						root_1 = (CommonTree)adaptor.becomeRoot(
						(CommonTree)adaptor.create(UNARY_MINUS, MINUS431, "UNARY_MINUS")
						, root_1);

						adaptor.addChild(root_1, stream_unaryExpression.nextTree());

						adaptor.addChild(root_0, root_1);
						}

					}


					retval.tree = root_0;
					}

					}
					break;
				case 3 :
					// Java.g:946:9: INC postfixedExpression
					{
					INC433=(Token)match(input,INC,FOLLOW_INC_in_unaryExpression11622); if (state.failed) return retval; 
					if ( state.backtracking==0 ) stream_INC.add(INC433);

					pushFollow(FOLLOW_postfixedExpression_in_unaryExpression11624);
					postfixedExpression434=postfixedExpression();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_postfixedExpression.add(postfixedExpression434.getTree());
					// AST REWRITE
					// elements: postfixedExpression
					// token labels: 
					// rule labels: retval
					// token list labels: 
					// rule list labels: 
					// wildcard labels: 
					if ( state.backtracking==0 ) {

					retval.tree = root_0;
					RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

					root_0 = (CommonTree)adaptor.nil();
					// 946:37: -> ^( PRE_INC[$INC, \"PRE_INC\"] postfixedExpression )
					{
						// Java.g:946:41: ^( PRE_INC[$INC, \"PRE_INC\"] postfixedExpression )
						{
						CommonTree root_1 = (CommonTree)adaptor.nil();
						root_1 = (CommonTree)adaptor.becomeRoot(
						(CommonTree)adaptor.create(PRE_INC, INC433, "PRE_INC")
						, root_1);

						adaptor.addChild(root_1, stream_postfixedExpression.nextTree());

						adaptor.addChild(root_0, root_1);
						}

					}


					retval.tree = root_0;
					}

					}
					break;
				case 4 :
					// Java.g:947:9: DEC postfixedExpression
					{
					DEC435=(Token)match(input,DEC,FOLLOW_DEC_in_unaryExpression11648); if (state.failed) return retval; 
					if ( state.backtracking==0 ) stream_DEC.add(DEC435);

					pushFollow(FOLLOW_postfixedExpression_in_unaryExpression11650);
					postfixedExpression436=postfixedExpression();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_postfixedExpression.add(postfixedExpression436.getTree());
					// AST REWRITE
					// elements: postfixedExpression
					// token labels: 
					// rule labels: retval
					// token list labels: 
					// rule list labels: 
					// wildcard labels: 
					if ( state.backtracking==0 ) {

					retval.tree = root_0;
					RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

					root_0 = (CommonTree)adaptor.nil();
					// 947:37: -> ^( PRE_DEC[$DEC, \"PRE_DEC\"] postfixedExpression )
					{
						// Java.g:947:41: ^( PRE_DEC[$DEC, \"PRE_DEC\"] postfixedExpression )
						{
						CommonTree root_1 = (CommonTree)adaptor.nil();
						root_1 = (CommonTree)adaptor.becomeRoot(
						(CommonTree)adaptor.create(PRE_DEC, DEC435, "PRE_DEC")
						, root_1);

						adaptor.addChild(root_1, stream_postfixedExpression.nextTree());

						adaptor.addChild(root_0, root_1);
						}

					}


					retval.tree = root_0;
					}

					}
					break;
				case 5 :
					// Java.g:948:9: unaryExpressionNotPlusMinus
					{
					root_0 = (CommonTree)adaptor.nil();


					pushFollow(FOLLOW_unaryExpressionNotPlusMinus_in_unaryExpression11674);
					unaryExpressionNotPlusMinus437=unaryExpressionNotPlusMinus();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) adaptor.addChild(root_0, unaryExpressionNotPlusMinus437.getTree());

					}
					break;

			}
			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 102, unaryExpression_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "unaryExpression"


	public static class unaryExpressionNotPlusMinus_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "unaryExpressionNotPlusMinus"
	// Java.g:951:1: unaryExpressionNotPlusMinus : ( NOT unaryExpression -> ^( NOT unaryExpression ) | LOGICAL_NOT unaryExpression -> ^( LOGICAL_NOT unaryExpression ) | LPAREN type RPAREN unaryExpression -> ^( CAST_EXPR[$LPAREN, \"CAST_EXPR\"] type unaryExpression ) | postfixedExpression );
	public final JavaParser.unaryExpressionNotPlusMinus_return unaryExpressionNotPlusMinus() throws RecognitionException {
		JavaParser.unaryExpressionNotPlusMinus_return retval = new JavaParser.unaryExpressionNotPlusMinus_return();
		retval.start = input.LT(1);
		int unaryExpressionNotPlusMinus_StartIndex = input.index();

		CommonTree root_0 = null;

		Token NOT438=null;
		Token LOGICAL_NOT440=null;
		Token LPAREN442=null;
		Token RPAREN444=null;
		ParserRuleReturnScope unaryExpression439 =null;
		ParserRuleReturnScope unaryExpression441 =null;
		ParserRuleReturnScope type443 =null;
		ParserRuleReturnScope unaryExpression445 =null;
		ParserRuleReturnScope postfixedExpression446 =null;

		CommonTree NOT438_tree=null;
		CommonTree LOGICAL_NOT440_tree=null;
		CommonTree LPAREN442_tree=null;
		CommonTree RPAREN444_tree=null;
		RewriteRuleTokenStream stream_RPAREN=new RewriteRuleTokenStream(adaptor,"token RPAREN");
		RewriteRuleTokenStream stream_LOGICAL_NOT=new RewriteRuleTokenStream(adaptor,"token LOGICAL_NOT");
		RewriteRuleTokenStream stream_NOT=new RewriteRuleTokenStream(adaptor,"token NOT");
		RewriteRuleTokenStream stream_LPAREN=new RewriteRuleTokenStream(adaptor,"token LPAREN");
		RewriteRuleSubtreeStream stream_unaryExpression=new RewriteRuleSubtreeStream(adaptor,"rule unaryExpression");
		RewriteRuleSubtreeStream stream_type=new RewriteRuleSubtreeStream(adaptor,"rule type");

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 103) ) { return retval; }

			// Java.g:952:5: ( NOT unaryExpression -> ^( NOT unaryExpression ) | LOGICAL_NOT unaryExpression -> ^( LOGICAL_NOT unaryExpression ) | LPAREN type RPAREN unaryExpression -> ^( CAST_EXPR[$LPAREN, \"CAST_EXPR\"] type unaryExpression ) | postfixedExpression )
			int alt127=4;
			switch ( input.LA(1) ) {
			case NOT:
				{
				alt127=1;
				}
				break;
			case LOGICAL_NOT:
				{
				alt127=2;
				}
				break;
			case LPAREN:
				{
				int LA127_3 = input.LA(2);
				if ( (synpred190_Java()) ) {
					alt127=3;
				}
				else if ( (true) ) {
					alt127=4;
				}
				else {
					if (state.backtracking>0) {state.failed=true; return retval;}
					int nvaeMark = input.mark();
					try {
						input.consume();
						NoViableAltException nvae =
							new NoViableAltException("", 127, 3, input);
						throw nvae;
					} finally {
						input.rewind(nvaeMark);
					}
				}
				}
				break;
			case BOOLEAN:
			case BYTE:
			case CHAR:
			case CHARACTER_LITERAL:
			case DECIMAL_LITERAL:
			case DOUBLE:
			case FALSE:
			case FLOAT:
			case FLOATING_POINT_LITERAL:
			case HEX_LITERAL:
			case IDENT:
			case INT:
			case LESS_THAN:
			case LONG:
			case NEW:
			case NULL:
			case OCTAL_LITERAL:
			case SHORT:
			case STRING_LITERAL:
			case SUPER:
			case THIS:
			case TRUE:
			case VOID:
				{
				alt127=4;
				}
				break;
			default:
				if (state.backtracking>0) {state.failed=true; return retval;}
				NoViableAltException nvae =
					new NoViableAltException("", 127, 0, input);
				throw nvae;
			}
			switch (alt127) {
				case 1 :
					// Java.g:952:9: NOT unaryExpression
					{
					NOT438=(Token)match(input,NOT,FOLLOW_NOT_in_unaryExpressionNotPlusMinus11693); if (state.failed) return retval; 
					if ( state.backtracking==0 ) stream_NOT.add(NOT438);

					pushFollow(FOLLOW_unaryExpression_in_unaryExpressionNotPlusMinus11695);
					unaryExpression439=unaryExpression();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_unaryExpression.add(unaryExpression439.getTree());
					// AST REWRITE
					// elements: NOT, unaryExpression
					// token labels: 
					// rule labels: retval
					// token list labels: 
					// rule list labels: 
					// wildcard labels: 
					if ( state.backtracking==0 ) {

					retval.tree = root_0;
					RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

					root_0 = (CommonTree)adaptor.nil();
					// 952:57: -> ^( NOT unaryExpression )
					{
						// Java.g:952:61: ^( NOT unaryExpression )
						{
						CommonTree root_1 = (CommonTree)adaptor.nil();
						root_1 = (CommonTree)adaptor.becomeRoot(
						stream_NOT.nextNode()
						, root_1);

						adaptor.addChild(root_1, stream_unaryExpression.nextTree());

						adaptor.addChild(root_0, root_1);
						}

					}


					retval.tree = root_0;
					}

					}
					break;
				case 2 :
					// Java.g:953:9: LOGICAL_NOT unaryExpression
					{
					LOGICAL_NOT440=(Token)match(input,LOGICAL_NOT,FOLLOW_LOGICAL_NOT_in_unaryExpressionNotPlusMinus11742); if (state.failed) return retval; 
					if ( state.backtracking==0 ) stream_LOGICAL_NOT.add(LOGICAL_NOT440);

					pushFollow(FOLLOW_unaryExpression_in_unaryExpressionNotPlusMinus11744);
					unaryExpression441=unaryExpression();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_unaryExpression.add(unaryExpression441.getTree());
					// AST REWRITE
					// elements: LOGICAL_NOT, unaryExpression
					// token labels: 
					// rule labels: retval
					// token list labels: 
					// rule list labels: 
					// wildcard labels: 
					if ( state.backtracking==0 ) {

					retval.tree = root_0;
					RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

					root_0 = (CommonTree)adaptor.nil();
					// 953:57: -> ^( LOGICAL_NOT unaryExpression )
					{
						// Java.g:953:61: ^( LOGICAL_NOT unaryExpression )
						{
						CommonTree root_1 = (CommonTree)adaptor.nil();
						root_1 = (CommonTree)adaptor.becomeRoot(
						stream_LOGICAL_NOT.nextNode()
						, root_1);

						adaptor.addChild(root_1, stream_unaryExpression.nextTree());

						adaptor.addChild(root_0, root_1);
						}

					}


					retval.tree = root_0;
					}

					}
					break;
				case 3 :
					// Java.g:954:9: LPAREN type RPAREN unaryExpression
					{
					LPAREN442=(Token)match(input,LPAREN,FOLLOW_LPAREN_in_unaryExpressionNotPlusMinus11783); if (state.failed) return retval; 
					if ( state.backtracking==0 ) stream_LPAREN.add(LPAREN442);

					pushFollow(FOLLOW_type_in_unaryExpressionNotPlusMinus11785);
					type443=type();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_type.add(type443.getTree());
					RPAREN444=(Token)match(input,RPAREN,FOLLOW_RPAREN_in_unaryExpressionNotPlusMinus11787); if (state.failed) return retval; 
					if ( state.backtracking==0 ) stream_RPAREN.add(RPAREN444);

					pushFollow(FOLLOW_unaryExpression_in_unaryExpressionNotPlusMinus11789);
					unaryExpression445=unaryExpression();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_unaryExpression.add(unaryExpression445.getTree());
					// AST REWRITE
					// elements: type, unaryExpression
					// token labels: 
					// rule labels: retval
					// token list labels: 
					// rule list labels: 
					// wildcard labels: 
					if ( state.backtracking==0 ) {

					retval.tree = root_0;
					RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

					root_0 = (CommonTree)adaptor.nil();
					// 954:57: -> ^( CAST_EXPR[$LPAREN, \"CAST_EXPR\"] type unaryExpression )
					{
						// Java.g:954:61: ^( CAST_EXPR[$LPAREN, \"CAST_EXPR\"] type unaryExpression )
						{
						CommonTree root_1 = (CommonTree)adaptor.nil();
						root_1 = (CommonTree)adaptor.becomeRoot(
						(CommonTree)adaptor.create(CAST_EXPR, LPAREN442, "CAST_EXPR")
						, root_1);

						adaptor.addChild(root_1, stream_type.nextTree());

						adaptor.addChild(root_1, stream_unaryExpression.nextTree());

						adaptor.addChild(root_0, root_1);
						}

					}


					retval.tree = root_0;
					}

					}
					break;
				case 4 :
					// Java.g:955:9: postfixedExpression
					{
					root_0 = (CommonTree)adaptor.nil();


					pushFollow(FOLLOW_postfixedExpression_in_unaryExpressionNotPlusMinus11824);
					postfixedExpression446=postfixedExpression();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) adaptor.addChild(root_0, postfixedExpression446.getTree());

					}
					break;

			}
			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 103, unaryExpressionNotPlusMinus_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "unaryExpressionNotPlusMinus"


	public static class postfixedExpression_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "postfixedExpression"
	// Java.g:958:1: postfixedExpression : ( primaryExpression -> primaryExpression ) (outerDot= DOT ( ( ( genericTypeArgumentListSimplified )? IDENT -> ^( DOT $postfixedExpression IDENT ) ) ( arguments -> ^( METHOD_CALL $postfixedExpression ( genericTypeArgumentListSimplified )? arguments ) )? | THIS -> ^( DOT $postfixedExpression THIS ) |Super= SUPER arguments -> ^( SUPER_CONSTRUCTOR_CALL[$Super, \"SUPER_CONSTRUCTOR_CALL\"] $postfixedExpression arguments ) | ( SUPER innerDot= DOT IDENT -> ^( $innerDot ^( $outerDot $postfixedExpression SUPER ) IDENT ) ) ( arguments -> ^( METHOD_CALL $postfixedExpression arguments ) )? | innerNewExpression -> ^( DOT $postfixedExpression innerNewExpression ) ) | LBRACK expression RBRACK -> ^( ARRAY_ELEMENT_ACCESS $postfixedExpression expression ) )* ( INC -> ^( POST_INC[$INC, \"POST_INC\"] $postfixedExpression) | DEC -> ^( POST_DEC[$DEC, \"POST_DEC\"] $postfixedExpression) )? ;
	public final JavaParser.postfixedExpression_return postfixedExpression() throws RecognitionException {
		JavaParser.postfixedExpression_return retval = new JavaParser.postfixedExpression_return();
		retval.start = input.LT(1);
		int postfixedExpression_StartIndex = input.index();

		CommonTree root_0 = null;

		Token outerDot=null;
		Token Super=null;
		Token innerDot=null;
		Token IDENT449=null;
		Token THIS451=null;
		Token SUPER453=null;
		Token IDENT454=null;
		Token LBRACK457=null;
		Token RBRACK459=null;
		Token INC460=null;
		Token DEC461=null;
		ParserRuleReturnScope primaryExpression447 =null;
		ParserRuleReturnScope genericTypeArgumentListSimplified448 =null;
		ParserRuleReturnScope arguments450 =null;
		ParserRuleReturnScope arguments452 =null;
		ParserRuleReturnScope arguments455 =null;
		ParserRuleReturnScope innerNewExpression456 =null;
		ParserRuleReturnScope expression458 =null;

		CommonTree outerDot_tree=null;
		CommonTree Super_tree=null;
		CommonTree innerDot_tree=null;
		CommonTree IDENT449_tree=null;
		CommonTree THIS451_tree=null;
		CommonTree SUPER453_tree=null;
		CommonTree IDENT454_tree=null;
		CommonTree LBRACK457_tree=null;
		CommonTree RBRACK459_tree=null;
		CommonTree INC460_tree=null;
		CommonTree DEC461_tree=null;
		RewriteRuleTokenStream stream_RBRACK=new RewriteRuleTokenStream(adaptor,"token RBRACK");
		RewriteRuleTokenStream stream_IDENT=new RewriteRuleTokenStream(adaptor,"token IDENT");
		RewriteRuleTokenStream stream_INC=new RewriteRuleTokenStream(adaptor,"token INC");
		RewriteRuleTokenStream stream_DEC=new RewriteRuleTokenStream(adaptor,"token DEC");
		RewriteRuleTokenStream stream_LBRACK=new RewriteRuleTokenStream(adaptor,"token LBRACK");
		RewriteRuleTokenStream stream_SUPER=new RewriteRuleTokenStream(adaptor,"token SUPER");
		RewriteRuleTokenStream stream_DOT=new RewriteRuleTokenStream(adaptor,"token DOT");
		RewriteRuleTokenStream stream_THIS=new RewriteRuleTokenStream(adaptor,"token THIS");
		RewriteRuleSubtreeStream stream_expression=new RewriteRuleSubtreeStream(adaptor,"rule expression");
		RewriteRuleSubtreeStream stream_arguments=new RewriteRuleSubtreeStream(adaptor,"rule arguments");
		RewriteRuleSubtreeStream stream_primaryExpression=new RewriteRuleSubtreeStream(adaptor,"rule primaryExpression");
		RewriteRuleSubtreeStream stream_genericTypeArgumentListSimplified=new RewriteRuleSubtreeStream(adaptor,"rule genericTypeArgumentListSimplified");
		RewriteRuleSubtreeStream stream_innerNewExpression=new RewriteRuleSubtreeStream(adaptor,"rule innerNewExpression");

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 104) ) { return retval; }

			// Java.g:960:5: ( ( primaryExpression -> primaryExpression ) (outerDot= DOT ( ( ( genericTypeArgumentListSimplified )? IDENT -> ^( DOT $postfixedExpression IDENT ) ) ( arguments -> ^( METHOD_CALL $postfixedExpression ( genericTypeArgumentListSimplified )? arguments ) )? | THIS -> ^( DOT $postfixedExpression THIS ) |Super= SUPER arguments -> ^( SUPER_CONSTRUCTOR_CALL[$Super, \"SUPER_CONSTRUCTOR_CALL\"] $postfixedExpression arguments ) | ( SUPER innerDot= DOT IDENT -> ^( $innerDot ^( $outerDot $postfixedExpression SUPER ) IDENT ) ) ( arguments -> ^( METHOD_CALL $postfixedExpression arguments ) )? | innerNewExpression -> ^( DOT $postfixedExpression innerNewExpression ) ) | LBRACK expression RBRACK -> ^( ARRAY_ELEMENT_ACCESS $postfixedExpression expression ) )* ( INC -> ^( POST_INC[$INC, \"POST_INC\"] $postfixedExpression) | DEC -> ^( POST_DEC[$DEC, \"POST_DEC\"] $postfixedExpression) )? )
			// Java.g:960:9: ( primaryExpression -> primaryExpression ) (outerDot= DOT ( ( ( genericTypeArgumentListSimplified )? IDENT -> ^( DOT $postfixedExpression IDENT ) ) ( arguments -> ^( METHOD_CALL $postfixedExpression ( genericTypeArgumentListSimplified )? arguments ) )? | THIS -> ^( DOT $postfixedExpression THIS ) |Super= SUPER arguments -> ^( SUPER_CONSTRUCTOR_CALL[$Super, \"SUPER_CONSTRUCTOR_CALL\"] $postfixedExpression arguments ) | ( SUPER innerDot= DOT IDENT -> ^( $innerDot ^( $outerDot $postfixedExpression SUPER ) IDENT ) ) ( arguments -> ^( METHOD_CALL $postfixedExpression arguments ) )? | innerNewExpression -> ^( DOT $postfixedExpression innerNewExpression ) ) | LBRACK expression RBRACK -> ^( ARRAY_ELEMENT_ACCESS $postfixedExpression expression ) )* ( INC -> ^( POST_INC[$INC, \"POST_INC\"] $postfixedExpression) | DEC -> ^( POST_DEC[$DEC, \"POST_DEC\"] $postfixedExpression) )?
			{
			// Java.g:960:9: ( primaryExpression -> primaryExpression )
			// Java.g:960:13: primaryExpression
			{
			pushFollow(FOLLOW_primaryExpression_in_postfixedExpression11860);
			primaryExpression447=primaryExpression();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) stream_primaryExpression.add(primaryExpression447.getTree());
			// AST REWRITE
			// elements: primaryExpression
			// token labels: 
			// rule labels: retval
			// token list labels: 
			// rule list labels: 
			// wildcard labels: 
			if ( state.backtracking==0 ) {

			retval.tree = root_0;
			RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

			root_0 = (CommonTree)adaptor.nil();
			// 960:53: -> primaryExpression
			{
				adaptor.addChild(root_0, stream_primaryExpression.nextTree());

			}


			retval.tree = root_0;
			}

			}

			// Java.g:963:9: (outerDot= DOT ( ( ( genericTypeArgumentListSimplified )? IDENT -> ^( DOT $postfixedExpression IDENT ) ) ( arguments -> ^( METHOD_CALL $postfixedExpression ( genericTypeArgumentListSimplified )? arguments ) )? | THIS -> ^( DOT $postfixedExpression THIS ) |Super= SUPER arguments -> ^( SUPER_CONSTRUCTOR_CALL[$Super, \"SUPER_CONSTRUCTOR_CALL\"] $postfixedExpression arguments ) | ( SUPER innerDot= DOT IDENT -> ^( $innerDot ^( $outerDot $postfixedExpression SUPER ) IDENT ) ) ( arguments -> ^( METHOD_CALL $postfixedExpression arguments ) )? | innerNewExpression -> ^( DOT $postfixedExpression innerNewExpression ) ) | LBRACK expression RBRACK -> ^( ARRAY_ELEMENT_ACCESS $postfixedExpression expression ) )*
			loop132:
			do {
				int alt132=3;
				int LA132_0 = input.LA(1);
				if ( (LA132_0==DOT) ) {
					alt132=1;
				}
				else if ( (LA132_0==LBRACK) ) {
					alt132=2;
				}

				switch (alt132) {
				case 1 :
					// Java.g:963:13: outerDot= DOT ( ( ( genericTypeArgumentListSimplified )? IDENT -> ^( DOT $postfixedExpression IDENT ) ) ( arguments -> ^( METHOD_CALL $postfixedExpression ( genericTypeArgumentListSimplified )? arguments ) )? | THIS -> ^( DOT $postfixedExpression THIS ) |Super= SUPER arguments -> ^( SUPER_CONSTRUCTOR_CALL[$Super, \"SUPER_CONSTRUCTOR_CALL\"] $postfixedExpression arguments ) | ( SUPER innerDot= DOT IDENT -> ^( $innerDot ^( $outerDot $postfixedExpression SUPER ) IDENT ) ) ( arguments -> ^( METHOD_CALL $postfixedExpression arguments ) )? | innerNewExpression -> ^( DOT $postfixedExpression innerNewExpression ) )
					{
					outerDot=(Token)match(input,DOT,FOLLOW_DOT_in_postfixedExpression11922); if (state.failed) return retval; 
					if ( state.backtracking==0 ) stream_DOT.add(outerDot);

					// Java.g:964:13: ( ( ( genericTypeArgumentListSimplified )? IDENT -> ^( DOT $postfixedExpression IDENT ) ) ( arguments -> ^( METHOD_CALL $postfixedExpression ( genericTypeArgumentListSimplified )? arguments ) )? | THIS -> ^( DOT $postfixedExpression THIS ) |Super= SUPER arguments -> ^( SUPER_CONSTRUCTOR_CALL[$Super, \"SUPER_CONSTRUCTOR_CALL\"] $postfixedExpression arguments ) | ( SUPER innerDot= DOT IDENT -> ^( $innerDot ^( $outerDot $postfixedExpression SUPER ) IDENT ) ) ( arguments -> ^( METHOD_CALL $postfixedExpression arguments ) )? | innerNewExpression -> ^( DOT $postfixedExpression innerNewExpression ) )
					int alt131=5;
					switch ( input.LA(1) ) {
					case IDENT:
					case LESS_THAN:
						{
						alt131=1;
						}
						break;
					case THIS:
						{
						alt131=2;
						}
						break;
					case SUPER:
						{
						int LA131_3 = input.LA(2);
						if ( (LA131_3==DOT) ) {
							alt131=4;
						}
						else if ( (LA131_3==LPAREN) ) {
							alt131=3;
						}
						else {
							if (state.backtracking>0) {state.failed=true; return retval;}
							int nvaeMark = input.mark();
							try {
								input.consume();
								NoViableAltException nvae =
									new NoViableAltException("", 131, 3, input);
								throw nvae;
							} finally {
								input.rewind(nvaeMark);
							}
						}
						}
						break;
					case NEW:
						{
						alt131=5;
						}
						break;
					default:
						if (state.backtracking>0) {state.failed=true; return retval;}
						NoViableAltException nvae =
							new NoViableAltException("", 131, 0, input);
						throw nvae;
					}
					switch (alt131) {
						case 1 :
							// Java.g:964:17: ( ( genericTypeArgumentListSimplified )? IDENT -> ^( DOT $postfixedExpression IDENT ) ) ( arguments -> ^( METHOD_CALL $postfixedExpression ( genericTypeArgumentListSimplified )? arguments ) )?
							{
							// Java.g:964:17: ( ( genericTypeArgumentListSimplified )? IDENT -> ^( DOT $postfixedExpression IDENT ) )
							// Java.g:964:21: ( genericTypeArgumentListSimplified )? IDENT
							{
							// Java.g:964:21: ( genericTypeArgumentListSimplified )?
							int alt128=2;
							int LA128_0 = input.LA(1);
							if ( (LA128_0==LESS_THAN) ) {
								alt128=1;
							}
							switch (alt128) {
								case 1 :
									// Java.g:964:21: genericTypeArgumentListSimplified
									{
									pushFollow(FOLLOW_genericTypeArgumentListSimplified_in_postfixedExpression11972);
									genericTypeArgumentListSimplified448=genericTypeArgumentListSimplified();
									state._fsp--;
									if (state.failed) return retval;
									if ( state.backtracking==0 ) stream_genericTypeArgumentListSimplified.add(genericTypeArgumentListSimplified448.getTree());
									}
									break;

							}

							IDENT449=(Token)match(input,IDENT,FOLLOW_IDENT_in_postfixedExpression12054); if (state.failed) return retval; 
							if ( state.backtracking==0 ) stream_IDENT.add(IDENT449);

							// AST REWRITE
							// elements: DOT, IDENT, postfixedExpression
							// token labels: 
							// rule labels: retval
							// token list labels: 
							// rule list labels: 
							// wildcard labels: 
							if ( state.backtracking==0 ) {

							retval.tree = root_0;
							RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

							root_0 = (CommonTree)adaptor.nil();
							// 966:53: -> ^( DOT $postfixedExpression IDENT )
							{
								// Java.g:966:57: ^( DOT $postfixedExpression IDENT )
								{
								CommonTree root_1 = (CommonTree)adaptor.nil();
								root_1 = (CommonTree)adaptor.becomeRoot(
								stream_DOT.nextNode()
								, root_1);

								adaptor.addChild(root_1, stream_retval.nextTree());

								adaptor.addChild(root_1, 
								stream_IDENT.nextNode()
								);

								adaptor.addChild(root_0, root_1);
								}

							}


							retval.tree = root_0;
							}

							}

							// Java.g:968:17: ( arguments -> ^( METHOD_CALL $postfixedExpression ( genericTypeArgumentListSimplified )? arguments ) )?
							int alt129=2;
							int LA129_0 = input.LA(1);
							if ( (LA129_0==LPAREN) ) {
								alt129=1;
							}
							switch (alt129) {
								case 1 :
									// Java.g:968:21: arguments
									{
									pushFollow(FOLLOW_arguments_in_postfixedExpression12133);
									arguments450=arguments();
									state._fsp--;
									if (state.failed) return retval;
									if ( state.backtracking==0 ) stream_arguments.add(arguments450.getTree());
									// AST REWRITE
									// elements: genericTypeArgumentListSimplified, arguments, postfixedExpression
									// token labels: 
									// rule labels: retval
									// token list labels: 
									// rule list labels: 
									// wildcard labels: 
									if ( state.backtracking==0 ) {

									retval.tree = root_0;
									RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

									root_0 = (CommonTree)adaptor.nil();
									// 968:53: -> ^( METHOD_CALL $postfixedExpression ( genericTypeArgumentListSimplified )? arguments )
									{
										// Java.g:968:57: ^( METHOD_CALL $postfixedExpression ( genericTypeArgumentListSimplified )? arguments )
										{
										CommonTree root_1 = (CommonTree)adaptor.nil();
										root_1 = (CommonTree)adaptor.becomeRoot(
										(CommonTree)adaptor.create(METHOD_CALL, "METHOD_CALL")
										, root_1);

										adaptor.addChild(root_1, stream_retval.nextTree());

										// Java.g:968:92: ( genericTypeArgumentListSimplified )?
										if ( stream_genericTypeArgumentListSimplified.hasNext() ) {
											adaptor.addChild(root_1, stream_genericTypeArgumentListSimplified.nextTree());

										}
										stream_genericTypeArgumentListSimplified.reset();

										adaptor.addChild(root_1, stream_arguments.nextTree());

										adaptor.addChild(root_0, root_1);
										}

									}


									retval.tree = root_0;
									}

									}
									break;

							}

							}
							break;
						case 2 :
							// Java.g:970:17: THIS
							{
							THIS451=(Token)match(input,THIS,FOLLOW_THIS_in_postfixedExpression12207); if (state.failed) return retval; 
							if ( state.backtracking==0 ) stream_THIS.add(THIS451);

							// AST REWRITE
							// elements: THIS, postfixedExpression, DOT
							// token labels: 
							// rule labels: retval
							// token list labels: 
							// rule list labels: 
							// wildcard labels: 
							if ( state.backtracking==0 ) {

							retval.tree = root_0;
							RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

							root_0 = (CommonTree)adaptor.nil();
							// 970:53: -> ^( DOT $postfixedExpression THIS )
							{
								// Java.g:970:57: ^( DOT $postfixedExpression THIS )
								{
								CommonTree root_1 = (CommonTree)adaptor.nil();
								root_1 = (CommonTree)adaptor.becomeRoot(
								stream_DOT.nextNode()
								, root_1);

								adaptor.addChild(root_1, stream_retval.nextTree());

								adaptor.addChild(root_1, 
								stream_THIS.nextNode()
								);

								adaptor.addChild(root_0, root_1);
								}

							}


							retval.tree = root_0;
							}

							}
							break;
						case 3 :
							// Java.g:971:17: Super= SUPER arguments
							{
							Super=(Token)match(input,SUPER,FOLLOW_SUPER_in_postfixedExpression12270); if (state.failed) return retval; 
							if ( state.backtracking==0 ) stream_SUPER.add(Super);

							pushFollow(FOLLOW_arguments_in_postfixedExpression12272);
							arguments452=arguments();
							state._fsp--;
							if (state.failed) return retval;
							if ( state.backtracking==0 ) stream_arguments.add(arguments452.getTree());
							// AST REWRITE
							// elements: postfixedExpression, arguments
							// token labels: 
							// rule labels: retval
							// token list labels: 
							// rule list labels: 
							// wildcard labels: 
							if ( state.backtracking==0 ) {

							retval.tree = root_0;
							RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

							root_0 = (CommonTree)adaptor.nil();
							// 971:57: -> ^( SUPER_CONSTRUCTOR_CALL[$Super, \"SUPER_CONSTRUCTOR_CALL\"] $postfixedExpression arguments )
							{
								// Java.g:971:61: ^( SUPER_CONSTRUCTOR_CALL[$Super, \"SUPER_CONSTRUCTOR_CALL\"] $postfixedExpression arguments )
								{
								CommonTree root_1 = (CommonTree)adaptor.nil();
								root_1 = (CommonTree)adaptor.becomeRoot(
								(CommonTree)adaptor.create(SUPER_CONSTRUCTOR_CALL, Super, "SUPER_CONSTRUCTOR_CALL")
								, root_1);

								adaptor.addChild(root_1, stream_retval.nextTree());

								adaptor.addChild(root_1, stream_arguments.nextTree());

								adaptor.addChild(root_0, root_1);
								}

							}


							retval.tree = root_0;
							}

							}
							break;
						case 4 :
							// Java.g:972:17: ( SUPER innerDot= DOT IDENT -> ^( $innerDot ^( $outerDot $postfixedExpression SUPER ) IDENT ) ) ( arguments -> ^( METHOD_CALL $postfixedExpression arguments ) )?
							{
							// Java.g:972:17: ( SUPER innerDot= DOT IDENT -> ^( $innerDot ^( $outerDot $postfixedExpression SUPER ) IDENT ) )
							// Java.g:972:21: SUPER innerDot= DOT IDENT
							{
							SUPER453=(Token)match(input,SUPER,FOLLOW_SUPER_in_postfixedExpression12325); if (state.failed) return retval; 
							if ( state.backtracking==0 ) stream_SUPER.add(SUPER453);

							innerDot=(Token)match(input,DOT,FOLLOW_DOT_in_postfixedExpression12329); if (state.failed) return retval; 
							if ( state.backtracking==0 ) stream_DOT.add(innerDot);

							IDENT454=(Token)match(input,IDENT,FOLLOW_IDENT_in_postfixedExpression12331); if (state.failed) return retval; 
							if ( state.backtracking==0 ) stream_IDENT.add(IDENT454);

							// AST REWRITE
							// elements: IDENT, innerDot, SUPER, outerDot, postfixedExpression
							// token labels: outerDot, innerDot
							// rule labels: retval
							// token list labels: 
							// rule list labels: 
							// wildcard labels: 
							if ( state.backtracking==0 ) {

							retval.tree = root_0;
							RewriteRuleTokenStream stream_outerDot=new RewriteRuleTokenStream(adaptor,"token outerDot",outerDot);
							RewriteRuleTokenStream stream_innerDot=new RewriteRuleTokenStream(adaptor,"token innerDot",innerDot);
							RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

							root_0 = (CommonTree)adaptor.nil();
							// 972:53: -> ^( $innerDot ^( $outerDot $postfixedExpression SUPER ) IDENT )
							{
								// Java.g:972:57: ^( $innerDot ^( $outerDot $postfixedExpression SUPER ) IDENT )
								{
								CommonTree root_1 = (CommonTree)adaptor.nil();
								root_1 = (CommonTree)adaptor.becomeRoot(stream_innerDot.nextNode(), root_1);

								// Java.g:972:69: ^( $outerDot $postfixedExpression SUPER )
								{
								CommonTree root_2 = (CommonTree)adaptor.nil();
								root_2 = (CommonTree)adaptor.becomeRoot(stream_outerDot.nextNode(), root_2);

								adaptor.addChild(root_2, stream_retval.nextTree());

								adaptor.addChild(root_2, 
								stream_SUPER.nextNode()
								);

								adaptor.addChild(root_1, root_2);
								}

								adaptor.addChild(root_1, 
								stream_IDENT.nextNode()
								);

								adaptor.addChild(root_0, root_1);
								}

							}


							retval.tree = root_0;
							}

							}

							// Java.g:974:17: ( arguments -> ^( METHOD_CALL $postfixedExpression arguments ) )?
							int alt130=2;
							int LA130_0 = input.LA(1);
							if ( (LA130_0==LPAREN) ) {
								alt130=1;
							}
							switch (alt130) {
								case 1 :
									// Java.g:974:21: arguments
									{
									pushFollow(FOLLOW_arguments_in_postfixedExpression12398);
									arguments455=arguments();
									state._fsp--;
									if (state.failed) return retval;
									if ( state.backtracking==0 ) stream_arguments.add(arguments455.getTree());
									// AST REWRITE
									// elements: postfixedExpression, arguments
									// token labels: 
									// rule labels: retval
									// token list labels: 
									// rule list labels: 
									// wildcard labels: 
									if ( state.backtracking==0 ) {

									retval.tree = root_0;
									RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

									root_0 = (CommonTree)adaptor.nil();
									// 974:53: -> ^( METHOD_CALL $postfixedExpression arguments )
									{
										// Java.g:974:57: ^( METHOD_CALL $postfixedExpression arguments )
										{
										CommonTree root_1 = (CommonTree)adaptor.nil();
										root_1 = (CommonTree)adaptor.becomeRoot(
										(CommonTree)adaptor.create(METHOD_CALL, "METHOD_CALL")
										, root_1);

										adaptor.addChild(root_1, stream_retval.nextTree());

										adaptor.addChild(root_1, stream_arguments.nextTree());

										adaptor.addChild(root_0, root_1);
										}

									}


									retval.tree = root_0;
									}

									}
									break;

							}

							}
							break;
						case 5 :
							// Java.g:976:17: innerNewExpression
							{
							pushFollow(FOLLOW_innerNewExpression_in_postfixedExpression12469);
							innerNewExpression456=innerNewExpression();
							state._fsp--;
							if (state.failed) return retval;
							if ( state.backtracking==0 ) stream_innerNewExpression.add(innerNewExpression456.getTree());
							// AST REWRITE
							// elements: innerNewExpression, DOT, postfixedExpression
							// token labels: 
							// rule labels: retval
							// token list labels: 
							// rule list labels: 
							// wildcard labels: 
							if ( state.backtracking==0 ) {

							retval.tree = root_0;
							RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

							root_0 = (CommonTree)adaptor.nil();
							// 976:53: -> ^( DOT $postfixedExpression innerNewExpression )
							{
								// Java.g:976:57: ^( DOT $postfixedExpression innerNewExpression )
								{
								CommonTree root_1 = (CommonTree)adaptor.nil();
								root_1 = (CommonTree)adaptor.becomeRoot(
								stream_DOT.nextNode()
								, root_1);

								adaptor.addChild(root_1, stream_retval.nextTree());

								adaptor.addChild(root_1, stream_innerNewExpression.nextTree());

								adaptor.addChild(root_0, root_1);
								}

							}


							retval.tree = root_0;
							}

							}
							break;

					}

					}
					break;
				case 2 :
					// Java.g:978:13: LBRACK expression RBRACK
					{
					LBRACK457=(Token)match(input,LBRACK,FOLLOW_LBRACK_in_postfixedExpression12526); if (state.failed) return retval; 
					if ( state.backtracking==0 ) stream_LBRACK.add(LBRACK457);

					pushFollow(FOLLOW_expression_in_postfixedExpression12528);
					expression458=expression();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_expression.add(expression458.getTree());
					RBRACK459=(Token)match(input,RBRACK,FOLLOW_RBRACK_in_postfixedExpression12530); if (state.failed) return retval; 
					if ( state.backtracking==0 ) stream_RBRACK.add(RBRACK459);

					// AST REWRITE
					// elements: postfixedExpression, expression
					// token labels: 
					// rule labels: retval
					// token list labels: 
					// rule list labels: 
					// wildcard labels: 
					if ( state.backtracking==0 ) {

					retval.tree = root_0;
					RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

					root_0 = (CommonTree)adaptor.nil();
					// 978:53: -> ^( ARRAY_ELEMENT_ACCESS $postfixedExpression expression )
					{
						// Java.g:978:57: ^( ARRAY_ELEMENT_ACCESS $postfixedExpression expression )
						{
						CommonTree root_1 = (CommonTree)adaptor.nil();
						root_1 = (CommonTree)adaptor.becomeRoot(
						(CommonTree)adaptor.create(ARRAY_ELEMENT_ACCESS, "ARRAY_ELEMENT_ACCESS")
						, root_1);

						adaptor.addChild(root_1, stream_retval.nextTree());

						adaptor.addChild(root_1, stream_expression.nextTree());

						adaptor.addChild(root_0, root_1);
						}

					}


					retval.tree = root_0;
					}

					}
					break;

				default :
					break loop132;
				}
			} while (true);

			// Java.g:981:9: ( INC -> ^( POST_INC[$INC, \"POST_INC\"] $postfixedExpression) | DEC -> ^( POST_DEC[$DEC, \"POST_DEC\"] $postfixedExpression) )?
			int alt133=3;
			int LA133_0 = input.LA(1);
			if ( (LA133_0==INC) ) {
				alt133=1;
			}
			else if ( (LA133_0==DEC) ) {
				alt133=2;
			}
			switch (alt133) {
				case 1 :
					// Java.g:981:13: INC
					{
					INC460=(Token)match(input,INC,FOLLOW_INC_in_postfixedExpression12591); if (state.failed) return retval; 
					if ( state.backtracking==0 ) stream_INC.add(INC460);

					// AST REWRITE
					// elements: postfixedExpression
					// token labels: 
					// rule labels: retval
					// token list labels: 
					// rule list labels: 
					// wildcard labels: 
					if ( state.backtracking==0 ) {

					retval.tree = root_0;
					RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

					root_0 = (CommonTree)adaptor.nil();
					// 981:17: -> ^( POST_INC[$INC, \"POST_INC\"] $postfixedExpression)
					{
						// Java.g:981:20: ^( POST_INC[$INC, \"POST_INC\"] $postfixedExpression)
						{
						CommonTree root_1 = (CommonTree)adaptor.nil();
						root_1 = (CommonTree)adaptor.becomeRoot(
						(CommonTree)adaptor.create(POST_INC, INC460, "POST_INC")
						, root_1);

						adaptor.addChild(root_1, stream_retval.nextTree());

						adaptor.addChild(root_0, root_1);
						}

					}


					retval.tree = root_0;
					}

					}
					break;
				case 2 :
					// Java.g:982:13: DEC
					{
					DEC461=(Token)match(input,DEC,FOLLOW_DEC_in_postfixedExpression12615); if (state.failed) return retval; 
					if ( state.backtracking==0 ) stream_DEC.add(DEC461);

					// AST REWRITE
					// elements: postfixedExpression
					// token labels: 
					// rule labels: retval
					// token list labels: 
					// rule list labels: 
					// wildcard labels: 
					if ( state.backtracking==0 ) {

					retval.tree = root_0;
					RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

					root_0 = (CommonTree)adaptor.nil();
					// 982:17: -> ^( POST_DEC[$DEC, \"POST_DEC\"] $postfixedExpression)
					{
						// Java.g:982:20: ^( POST_DEC[$DEC, \"POST_DEC\"] $postfixedExpression)
						{
						CommonTree root_1 = (CommonTree)adaptor.nil();
						root_1 = (CommonTree)adaptor.becomeRoot(
						(CommonTree)adaptor.create(POST_DEC, DEC461, "POST_DEC")
						, root_1);

						adaptor.addChild(root_1, stream_retval.nextTree());

						adaptor.addChild(root_0, root_1);
						}

					}


					retval.tree = root_0;
					}

					}
					break;

			}

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 104, postfixedExpression_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "postfixedExpression"


	public static class primaryExpression_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "primaryExpression"
	// Java.g:986:1: primaryExpression : ( parenthesizedExpression | literal | newExpression | qualifiedIdentExpression | genericTypeArgumentListSimplified ( SUPER ( arguments -> ^( SUPER_CONSTRUCTOR_CALL[$SUPER, \"SUPER_CONSTRUCTOR_CALL\"] genericTypeArgumentListSimplified arguments ) | DOT IDENT arguments -> ^( METHOD_CALL ^( DOT SUPER IDENT ) genericTypeArgumentListSimplified arguments ) ) | IDENT arguments -> ^( METHOD_CALL IDENT genericTypeArgumentListSimplified arguments ) | THIS arguments -> ^( THIS_CONSTRUCTOR_CALL[$THIS, \"THIS_CONSTRUCTOR_CALL\"] genericTypeArgumentListSimplified arguments ) ) | ( THIS -> THIS ) ( arguments -> ^( THIS_CONSTRUCTOR_CALL[$THIS, \"THIS_CONSTRUCTOR_CALL\"] arguments ) )? | SUPER arguments -> ^( SUPER_CONSTRUCTOR_CALL[$SUPER, \"SUPER_CONSTRUCTOR_CALL\"] arguments ) | ( SUPER DOT IDENT ) ( arguments -> ^( METHOD_CALL ^( DOT SUPER IDENT ) arguments ) | -> ^( DOT SUPER IDENT ) ) | ( primitiveType -> primitiveType ) ( arrayDeclarator -> ^( arrayDeclarator $primaryExpression) )* DOT CLASS -> ^( DOT $primaryExpression CLASS ) | VOID DOT CLASS -> ^( DOT VOID CLASS ) );
	public final JavaParser.primaryExpression_return primaryExpression() throws RecognitionException {
		JavaParser.primaryExpression_return retval = new JavaParser.primaryExpression_return();
		retval.start = input.LT(1);
		int primaryExpression_StartIndex = input.index();

		CommonTree root_0 = null;

		Token SUPER467=null;
		Token DOT469=null;
		Token IDENT470=null;
		Token IDENT472=null;
		Token THIS474=null;
		Token THIS476=null;
		Token SUPER478=null;
		Token SUPER480=null;
		Token DOT481=null;
		Token IDENT482=null;
		Token DOT486=null;
		Token CLASS487=null;
		Token VOID488=null;
		Token DOT489=null;
		Token CLASS490=null;
		ParserRuleReturnScope parenthesizedExpression462 =null;
		ParserRuleReturnScope literal463 =null;
		ParserRuleReturnScope newExpression464 =null;
		ParserRuleReturnScope qualifiedIdentExpression465 =null;
		ParserRuleReturnScope genericTypeArgumentListSimplified466 =null;
		ParserRuleReturnScope arguments468 =null;
		ParserRuleReturnScope arguments471 =null;
		ParserRuleReturnScope arguments473 =null;
		ParserRuleReturnScope arguments475 =null;
		ParserRuleReturnScope arguments477 =null;
		ParserRuleReturnScope arguments479 =null;
		ParserRuleReturnScope arguments483 =null;
		ParserRuleReturnScope primitiveType484 =null;
		ParserRuleReturnScope arrayDeclarator485 =null;

		CommonTree SUPER467_tree=null;
		CommonTree DOT469_tree=null;
		CommonTree IDENT470_tree=null;
		CommonTree IDENT472_tree=null;
		CommonTree THIS474_tree=null;
		CommonTree THIS476_tree=null;
		CommonTree SUPER478_tree=null;
		CommonTree SUPER480_tree=null;
		CommonTree DOT481_tree=null;
		CommonTree IDENT482_tree=null;
		CommonTree DOT486_tree=null;
		CommonTree CLASS487_tree=null;
		CommonTree VOID488_tree=null;
		CommonTree DOT489_tree=null;
		CommonTree CLASS490_tree=null;
		RewriteRuleTokenStream stream_IDENT=new RewriteRuleTokenStream(adaptor,"token IDENT");
		RewriteRuleTokenStream stream_CLASS=new RewriteRuleTokenStream(adaptor,"token CLASS");
		RewriteRuleTokenStream stream_VOID=new RewriteRuleTokenStream(adaptor,"token VOID");
		RewriteRuleTokenStream stream_SUPER=new RewriteRuleTokenStream(adaptor,"token SUPER");
		RewriteRuleTokenStream stream_DOT=new RewriteRuleTokenStream(adaptor,"token DOT");
		RewriteRuleTokenStream stream_THIS=new RewriteRuleTokenStream(adaptor,"token THIS");
		RewriteRuleSubtreeStream stream_arrayDeclarator=new RewriteRuleSubtreeStream(adaptor,"rule arrayDeclarator");
		RewriteRuleSubtreeStream stream_arguments=new RewriteRuleSubtreeStream(adaptor,"rule arguments");
		RewriteRuleSubtreeStream stream_primitiveType=new RewriteRuleSubtreeStream(adaptor,"rule primitiveType");
		RewriteRuleSubtreeStream stream_genericTypeArgumentListSimplified=new RewriteRuleSubtreeStream(adaptor,"rule genericTypeArgumentListSimplified");

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 105) ) { return retval; }

			// Java.g:987:5: ( parenthesizedExpression | literal | newExpression | qualifiedIdentExpression | genericTypeArgumentListSimplified ( SUPER ( arguments -> ^( SUPER_CONSTRUCTOR_CALL[$SUPER, \"SUPER_CONSTRUCTOR_CALL\"] genericTypeArgumentListSimplified arguments ) | DOT IDENT arguments -> ^( METHOD_CALL ^( DOT SUPER IDENT ) genericTypeArgumentListSimplified arguments ) ) | IDENT arguments -> ^( METHOD_CALL IDENT genericTypeArgumentListSimplified arguments ) | THIS arguments -> ^( THIS_CONSTRUCTOR_CALL[$THIS, \"THIS_CONSTRUCTOR_CALL\"] genericTypeArgumentListSimplified arguments ) ) | ( THIS -> THIS ) ( arguments -> ^( THIS_CONSTRUCTOR_CALL[$THIS, \"THIS_CONSTRUCTOR_CALL\"] arguments ) )? | SUPER arguments -> ^( SUPER_CONSTRUCTOR_CALL[$SUPER, \"SUPER_CONSTRUCTOR_CALL\"] arguments ) | ( SUPER DOT IDENT ) ( arguments -> ^( METHOD_CALL ^( DOT SUPER IDENT ) arguments ) | -> ^( DOT SUPER IDENT ) ) | ( primitiveType -> primitiveType ) ( arrayDeclarator -> ^( arrayDeclarator $primaryExpression) )* DOT CLASS -> ^( DOT $primaryExpression CLASS ) | VOID DOT CLASS -> ^( DOT VOID CLASS ) )
			int alt139=10;
			switch ( input.LA(1) ) {
			case LPAREN:
				{
				alt139=1;
				}
				break;
			case CHARACTER_LITERAL:
			case DECIMAL_LITERAL:
			case FALSE:
			case FLOATING_POINT_LITERAL:
			case HEX_LITERAL:
			case NULL:
			case OCTAL_LITERAL:
			case STRING_LITERAL:
			case TRUE:
				{
				alt139=2;
				}
				break;
			case NEW:
				{
				alt139=3;
				}
				break;
			case IDENT:
				{
				alt139=4;
				}
				break;
			case LESS_THAN:
				{
				alt139=5;
				}
				break;
			case THIS:
				{
				alt139=6;
				}
				break;
			case SUPER:
				{
				int LA139_7 = input.LA(2);
				if ( (LA139_7==DOT) ) {
					alt139=8;
				}
				else if ( (LA139_7==LPAREN) ) {
					alt139=7;
				}
				else {
					if (state.backtracking>0) {state.failed=true; return retval;}
					int nvaeMark = input.mark();
					try {
						input.consume();
						NoViableAltException nvae =
							new NoViableAltException("", 139, 7, input);
						throw nvae;
					} finally {
						input.rewind(nvaeMark);
					}
				}
				}
				break;
			case BOOLEAN:
			case BYTE:
			case CHAR:
			case DOUBLE:
			case FLOAT:
			case INT:
			case LONG:
			case SHORT:
				{
				alt139=9;
				}
				break;
			case VOID:
				{
				alt139=10;
				}
				break;
			default:
				if (state.backtracking>0) {state.failed=true; return retval;}
				NoViableAltException nvae =
					new NoViableAltException("", 139, 0, input);
				throw nvae;
			}
			switch (alt139) {
				case 1 :
					// Java.g:987:9: parenthesizedExpression
					{
					root_0 = (CommonTree)adaptor.nil();


					pushFollow(FOLLOW_parenthesizedExpression_in_primaryExpression12663);
					parenthesizedExpression462=parenthesizedExpression();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) adaptor.addChild(root_0, parenthesizedExpression462.getTree());

					}
					break;
				case 2 :
					// Java.g:988:9: literal
					{
					root_0 = (CommonTree)adaptor.nil();


					pushFollow(FOLLOW_literal_in_primaryExpression12673);
					literal463=literal();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) adaptor.addChild(root_0, literal463.getTree());

					}
					break;
				case 3 :
					// Java.g:989:9: newExpression
					{
					root_0 = (CommonTree)adaptor.nil();


					pushFollow(FOLLOW_newExpression_in_primaryExpression12683);
					newExpression464=newExpression();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) adaptor.addChild(root_0, newExpression464.getTree());

					}
					break;
				case 4 :
					// Java.g:990:9: qualifiedIdentExpression
					{
					root_0 = (CommonTree)adaptor.nil();


					pushFollow(FOLLOW_qualifiedIdentExpression_in_primaryExpression12693);
					qualifiedIdentExpression465=qualifiedIdentExpression();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) adaptor.addChild(root_0, qualifiedIdentExpression465.getTree());

					}
					break;
				case 5 :
					// Java.g:991:9: genericTypeArgumentListSimplified ( SUPER ( arguments -> ^( SUPER_CONSTRUCTOR_CALL[$SUPER, \"SUPER_CONSTRUCTOR_CALL\"] genericTypeArgumentListSimplified arguments ) | DOT IDENT arguments -> ^( METHOD_CALL ^( DOT SUPER IDENT ) genericTypeArgumentListSimplified arguments ) ) | IDENT arguments -> ^( METHOD_CALL IDENT genericTypeArgumentListSimplified arguments ) | THIS arguments -> ^( THIS_CONSTRUCTOR_CALL[$THIS, \"THIS_CONSTRUCTOR_CALL\"] genericTypeArgumentListSimplified arguments ) )
					{
					pushFollow(FOLLOW_genericTypeArgumentListSimplified_in_primaryExpression12703);
					genericTypeArgumentListSimplified466=genericTypeArgumentListSimplified();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_genericTypeArgumentListSimplified.add(genericTypeArgumentListSimplified466.getTree());
					// Java.g:992:9: ( SUPER ( arguments -> ^( SUPER_CONSTRUCTOR_CALL[$SUPER, \"SUPER_CONSTRUCTOR_CALL\"] genericTypeArgumentListSimplified arguments ) | DOT IDENT arguments -> ^( METHOD_CALL ^( DOT SUPER IDENT ) genericTypeArgumentListSimplified arguments ) ) | IDENT arguments -> ^( METHOD_CALL IDENT genericTypeArgumentListSimplified arguments ) | THIS arguments -> ^( THIS_CONSTRUCTOR_CALL[$THIS, \"THIS_CONSTRUCTOR_CALL\"] genericTypeArgumentListSimplified arguments ) )
					int alt135=3;
					switch ( input.LA(1) ) {
					case SUPER:
						{
						alt135=1;
						}
						break;
					case IDENT:
						{
						alt135=2;
						}
						break;
					case THIS:
						{
						alt135=3;
						}
						break;
					default:
						if (state.backtracking>0) {state.failed=true; return retval;}
						NoViableAltException nvae =
							new NoViableAltException("", 135, 0, input);
						throw nvae;
					}
					switch (alt135) {
						case 1 :
							// Java.g:992:13: SUPER ( arguments -> ^( SUPER_CONSTRUCTOR_CALL[$SUPER, \"SUPER_CONSTRUCTOR_CALL\"] genericTypeArgumentListSimplified arguments ) | DOT IDENT arguments -> ^( METHOD_CALL ^( DOT SUPER IDENT ) genericTypeArgumentListSimplified arguments ) )
							{
							SUPER467=(Token)match(input,SUPER,FOLLOW_SUPER_in_primaryExpression12718); if (state.failed) return retval; 
							if ( state.backtracking==0 ) stream_SUPER.add(SUPER467);

							// Java.g:993:13: ( arguments -> ^( SUPER_CONSTRUCTOR_CALL[$SUPER, \"SUPER_CONSTRUCTOR_CALL\"] genericTypeArgumentListSimplified arguments ) | DOT IDENT arguments -> ^( METHOD_CALL ^( DOT SUPER IDENT ) genericTypeArgumentListSimplified arguments ) )
							int alt134=2;
							int LA134_0 = input.LA(1);
							if ( (LA134_0==LPAREN) ) {
								alt134=1;
							}
							else if ( (LA134_0==DOT) ) {
								alt134=2;
							}
							else {
								if (state.backtracking>0) {state.failed=true; return retval;}
								NoViableAltException nvae =
									new NoViableAltException("", 134, 0, input);
								throw nvae;
							}
							switch (alt134) {
								case 1 :
									// Java.g:993:17: arguments
									{
									pushFollow(FOLLOW_arguments_in_primaryExpression12736);
									arguments468=arguments();
									state._fsp--;
									if (state.failed) return retval;
									if ( state.backtracking==0 ) stream_arguments.add(arguments468.getTree());
									// AST REWRITE
									// elements: genericTypeArgumentListSimplified, arguments
									// token labels: 
									// rule labels: retval
									// token list labels: 
									// rule list labels: 
									// wildcard labels: 
									if ( state.backtracking==0 ) {

									retval.tree = root_0;
									RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

									root_0 = (CommonTree)adaptor.nil();
									// 993:57: -> ^( SUPER_CONSTRUCTOR_CALL[$SUPER, \"SUPER_CONSTRUCTOR_CALL\"] genericTypeArgumentListSimplified arguments )
									{
										// Java.g:993:61: ^( SUPER_CONSTRUCTOR_CALL[$SUPER, \"SUPER_CONSTRUCTOR_CALL\"] genericTypeArgumentListSimplified arguments )
										{
										CommonTree root_1 = (CommonTree)adaptor.nil();
										root_1 = (CommonTree)adaptor.becomeRoot(
										(CommonTree)adaptor.create(SUPER_CONSTRUCTOR_CALL, SUPER467, "SUPER_CONSTRUCTOR_CALL")
										, root_1);

										adaptor.addChild(root_1, stream_genericTypeArgumentListSimplified.nextTree());

										adaptor.addChild(root_1, stream_arguments.nextTree());

										adaptor.addChild(root_0, root_1);
										}

									}


									retval.tree = root_0;
									}

									}
									break;
								case 2 :
									// Java.g:994:17: DOT IDENT arguments
									{
									DOT469=(Token)match(input,DOT,FOLLOW_DOT_in_primaryExpression12796); if (state.failed) return retval; 
									if ( state.backtracking==0 ) stream_DOT.add(DOT469);

									IDENT470=(Token)match(input,IDENT,FOLLOW_IDENT_in_primaryExpression12798); if (state.failed) return retval; 
									if ( state.backtracking==0 ) stream_IDENT.add(IDENT470);

									pushFollow(FOLLOW_arguments_in_primaryExpression12800);
									arguments471=arguments();
									state._fsp--;
									if (state.failed) return retval;
									if ( state.backtracking==0 ) stream_arguments.add(arguments471.getTree());
									// AST REWRITE
									// elements: SUPER, IDENT, arguments, DOT, genericTypeArgumentListSimplified
									// token labels: 
									// rule labels: retval
									// token list labels: 
									// rule list labels: 
									// wildcard labels: 
									if ( state.backtracking==0 ) {

									retval.tree = root_0;
									RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

									root_0 = (CommonTree)adaptor.nil();
									// 994:57: -> ^( METHOD_CALL ^( DOT SUPER IDENT ) genericTypeArgumentListSimplified arguments )
									{
										// Java.g:994:61: ^( METHOD_CALL ^( DOT SUPER IDENT ) genericTypeArgumentListSimplified arguments )
										{
										CommonTree root_1 = (CommonTree)adaptor.nil();
										root_1 = (CommonTree)adaptor.becomeRoot(
										(CommonTree)adaptor.create(METHOD_CALL, "METHOD_CALL")
										, root_1);

										// Java.g:994:75: ^( DOT SUPER IDENT )
										{
										CommonTree root_2 = (CommonTree)adaptor.nil();
										root_2 = (CommonTree)adaptor.becomeRoot(
										stream_DOT.nextNode()
										, root_2);

										adaptor.addChild(root_2, 
										stream_SUPER.nextNode()
										);

										adaptor.addChild(root_2, 
										stream_IDENT.nextNode()
										);

										adaptor.addChild(root_1, root_2);
										}

										adaptor.addChild(root_1, stream_genericTypeArgumentListSimplified.nextTree());

										adaptor.addChild(root_1, stream_arguments.nextTree());

										adaptor.addChild(root_0, root_1);
										}

									}


									retval.tree = root_0;
									}

									}
									break;

							}

							}
							break;
						case 2 :
							// Java.g:996:13: IDENT arguments
							{
							IDENT472=(Token)match(input,IDENT,FOLLOW_IDENT_in_primaryExpression12867); if (state.failed) return retval; 
							if ( state.backtracking==0 ) stream_IDENT.add(IDENT472);

							pushFollow(FOLLOW_arguments_in_primaryExpression12869);
							arguments473=arguments();
							state._fsp--;
							if (state.failed) return retval;
							if ( state.backtracking==0 ) stream_arguments.add(arguments473.getTree());
							// AST REWRITE
							// elements: IDENT, genericTypeArgumentListSimplified, arguments
							// token labels: 
							// rule labels: retval
							// token list labels: 
							// rule list labels: 
							// wildcard labels: 
							if ( state.backtracking==0 ) {

							retval.tree = root_0;
							RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

							root_0 = (CommonTree)adaptor.nil();
							// 996:57: -> ^( METHOD_CALL IDENT genericTypeArgumentListSimplified arguments )
							{
								// Java.g:996:61: ^( METHOD_CALL IDENT genericTypeArgumentListSimplified arguments )
								{
								CommonTree root_1 = (CommonTree)adaptor.nil();
								root_1 = (CommonTree)adaptor.becomeRoot(
								(CommonTree)adaptor.create(METHOD_CALL, "METHOD_CALL")
								, root_1);

								adaptor.addChild(root_1, 
								stream_IDENT.nextNode()
								);

								adaptor.addChild(root_1, stream_genericTypeArgumentListSimplified.nextTree());

								adaptor.addChild(root_1, stream_arguments.nextTree());

								adaptor.addChild(root_0, root_1);
								}

							}


							retval.tree = root_0;
							}

							}
							break;
						case 3 :
							// Java.g:997:13: THIS arguments
							{
							THIS474=(Token)match(input,THIS,FOLLOW_THIS_in_primaryExpression12924); if (state.failed) return retval; 
							if ( state.backtracking==0 ) stream_THIS.add(THIS474);

							pushFollow(FOLLOW_arguments_in_primaryExpression12926);
							arguments475=arguments();
							state._fsp--;
							if (state.failed) return retval;
							if ( state.backtracking==0 ) stream_arguments.add(arguments475.getTree());
							// AST REWRITE
							// elements: arguments, genericTypeArgumentListSimplified
							// token labels: 
							// rule labels: retval
							// token list labels: 
							// rule list labels: 
							// wildcard labels: 
							if ( state.backtracking==0 ) {

							retval.tree = root_0;
							RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

							root_0 = (CommonTree)adaptor.nil();
							// 997:57: -> ^( THIS_CONSTRUCTOR_CALL[$THIS, \"THIS_CONSTRUCTOR_CALL\"] genericTypeArgumentListSimplified arguments )
							{
								// Java.g:997:61: ^( THIS_CONSTRUCTOR_CALL[$THIS, \"THIS_CONSTRUCTOR_CALL\"] genericTypeArgumentListSimplified arguments )
								{
								CommonTree root_1 = (CommonTree)adaptor.nil();
								root_1 = (CommonTree)adaptor.becomeRoot(
								(CommonTree)adaptor.create(THIS_CONSTRUCTOR_CALL, THIS474, "THIS_CONSTRUCTOR_CALL")
								, root_1);

								adaptor.addChild(root_1, stream_genericTypeArgumentListSimplified.nextTree());

								adaptor.addChild(root_1, stream_arguments.nextTree());

								adaptor.addChild(root_0, root_1);
								}

							}


							retval.tree = root_0;
							}

							}
							break;

					}

					}
					break;
				case 6 :
					// Java.g:999:9: ( THIS -> THIS ) ( arguments -> ^( THIS_CONSTRUCTOR_CALL[$THIS, \"THIS_CONSTRUCTOR_CALL\"] arguments ) )?
					{
					// Java.g:999:9: ( THIS -> THIS )
					// Java.g:999:13: THIS
					{
					THIS476=(Token)match(input,THIS,FOLLOW_THIS_in_primaryExpression12991); if (state.failed) return retval; 
					if ( state.backtracking==0 ) stream_THIS.add(THIS476);

					// AST REWRITE
					// elements: THIS
					// token labels: 
					// rule labels: retval
					// token list labels: 
					// rule list labels: 
					// wildcard labels: 
					if ( state.backtracking==0 ) {

					retval.tree = root_0;
					RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

					root_0 = (CommonTree)adaptor.nil();
					// 999:57: -> THIS
					{
						adaptor.addChild(root_0, 
						stream_THIS.nextNode()
						);

					}


					retval.tree = root_0;
					}

					}

					// Java.g:1001:9: ( arguments -> ^( THIS_CONSTRUCTOR_CALL[$THIS, \"THIS_CONSTRUCTOR_CALL\"] arguments ) )?
					int alt136=2;
					int LA136_0 = input.LA(1);
					if ( (LA136_0==LPAREN) ) {
						alt136=1;
					}
					switch (alt136) {
						case 1 :
							// Java.g:1001:13: arguments
							{
							pushFollow(FOLLOW_arguments_in_primaryExpression13059);
							arguments477=arguments();
							state._fsp--;
							if (state.failed) return retval;
							if ( state.backtracking==0 ) stream_arguments.add(arguments477.getTree());
							// AST REWRITE
							// elements: arguments
							// token labels: 
							// rule labels: retval
							// token list labels: 
							// rule list labels: 
							// wildcard labels: 
							if ( state.backtracking==0 ) {

							retval.tree = root_0;
							RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

							root_0 = (CommonTree)adaptor.nil();
							// 1001:57: -> ^( THIS_CONSTRUCTOR_CALL[$THIS, \"THIS_CONSTRUCTOR_CALL\"] arguments )
							{
								// Java.g:1001:61: ^( THIS_CONSTRUCTOR_CALL[$THIS, \"THIS_CONSTRUCTOR_CALL\"] arguments )
								{
								CommonTree root_1 = (CommonTree)adaptor.nil();
								root_1 = (CommonTree)adaptor.becomeRoot(
								(CommonTree)adaptor.create(THIS_CONSTRUCTOR_CALL, THIS476, "THIS_CONSTRUCTOR_CALL")
								, root_1);

								adaptor.addChild(root_1, stream_arguments.nextTree());

								adaptor.addChild(root_0, root_1);
								}

							}


							retval.tree = root_0;
							}

							}
							break;

					}

					}
					break;
				case 7 :
					// Java.g:1003:9: SUPER arguments
					{
					SUPER478=(Token)match(input,SUPER,FOLLOW_SUPER_in_primaryExpression13124); if (state.failed) return retval; 
					if ( state.backtracking==0 ) stream_SUPER.add(SUPER478);

					pushFollow(FOLLOW_arguments_in_primaryExpression13126);
					arguments479=arguments();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_arguments.add(arguments479.getTree());
					// AST REWRITE
					// elements: arguments
					// token labels: 
					// rule labels: retval
					// token list labels: 
					// rule list labels: 
					// wildcard labels: 
					if ( state.backtracking==0 ) {

					retval.tree = root_0;
					RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

					root_0 = (CommonTree)adaptor.nil();
					// 1003:57: -> ^( SUPER_CONSTRUCTOR_CALL[$SUPER, \"SUPER_CONSTRUCTOR_CALL\"] arguments )
					{
						// Java.g:1003:61: ^( SUPER_CONSTRUCTOR_CALL[$SUPER, \"SUPER_CONSTRUCTOR_CALL\"] arguments )
						{
						CommonTree root_1 = (CommonTree)adaptor.nil();
						root_1 = (CommonTree)adaptor.becomeRoot(
						(CommonTree)adaptor.create(SUPER_CONSTRUCTOR_CALL, SUPER478, "SUPER_CONSTRUCTOR_CALL")
						, root_1);

						adaptor.addChild(root_1, stream_arguments.nextTree());

						adaptor.addChild(root_0, root_1);
						}

					}


					retval.tree = root_0;
					}

					}
					break;
				case 8 :
					// Java.g:1004:9: ( SUPER DOT IDENT ) ( arguments -> ^( METHOD_CALL ^( DOT SUPER IDENT ) arguments ) | -> ^( DOT SUPER IDENT ) )
					{
					// Java.g:1004:9: ( SUPER DOT IDENT )
					// Java.g:1004:13: SUPER DOT IDENT
					{
					SUPER480=(Token)match(input,SUPER,FOLLOW_SUPER_in_primaryExpression13182); if (state.failed) return retval; 
					if ( state.backtracking==0 ) stream_SUPER.add(SUPER480);

					DOT481=(Token)match(input,DOT,FOLLOW_DOT_in_primaryExpression13184); if (state.failed) return retval; 
					if ( state.backtracking==0 ) stream_DOT.add(DOT481);

					IDENT482=(Token)match(input,IDENT,FOLLOW_IDENT_in_primaryExpression13186); if (state.failed) return retval; 
					if ( state.backtracking==0 ) stream_IDENT.add(IDENT482);

					}

					// Java.g:1006:9: ( arguments -> ^( METHOD_CALL ^( DOT SUPER IDENT ) arguments ) | -> ^( DOT SUPER IDENT ) )
					int alt137=2;
					int LA137_0 = input.LA(1);
					if ( (LA137_0==LPAREN) ) {
						alt137=1;
					}
					else if ( (LA137_0==EOF||(LA137_0 >= AND && LA137_0 <= AND_ASSIGN)||LA137_0==ASSIGN||(LA137_0 >= BIT_SHIFT_RIGHT && LA137_0 <= BIT_SHIFT_RIGHT_ASSIGN)||(LA137_0 >= COLON && LA137_0 <= COMMA)||LA137_0==DEC||(LA137_0 >= DIV && LA137_0 <= DIV_ASSIGN)||LA137_0==DOT||LA137_0==EQUAL||(LA137_0 >= GREATER_OR_EQUAL && LA137_0 <= GREATER_THAN)||(LA137_0 >= INC && LA137_0 <= INSTANCEOF)||LA137_0==LBRACK||(LA137_0 >= LESS_OR_EQUAL && LA137_0 <= LESS_THAN)||LA137_0==LOGICAL_AND||LA137_0==LOGICAL_OR||(LA137_0 >= MINUS && LA137_0 <= MOD)||LA137_0==MOD_ASSIGN||LA137_0==NOT_EQUAL||(LA137_0 >= OR && LA137_0 <= OR_ASSIGN)||(LA137_0 >= PLUS && LA137_0 <= PLUS_ASSIGN)||(LA137_0 >= QUESTION && LA137_0 <= RCURLY)||(LA137_0 >= RPAREN && LA137_0 <= SHIFT_RIGHT_ASSIGN)||(LA137_0 >= STAR && LA137_0 <= STAR_ASSIGN)||(LA137_0 >= XOR && LA137_0 <= XOR_ASSIGN)) ) {
						alt137=2;
					}
					else {
						if (state.backtracking>0) {state.failed=true; return retval;}
						NoViableAltException nvae =
							new NoViableAltException("", 137, 0, input);
						throw nvae;
					}
					switch (alt137) {
						case 1 :
							// Java.g:1006:13: arguments
							{
							pushFollow(FOLLOW_arguments_in_primaryExpression13210);
							arguments483=arguments();
							state._fsp--;
							if (state.failed) return retval;
							if ( state.backtracking==0 ) stream_arguments.add(arguments483.getTree());
							// AST REWRITE
							// elements: arguments, DOT, SUPER, IDENT
							// token labels: 
							// rule labels: retval
							// token list labels: 
							// rule list labels: 
							// wildcard labels: 
							if ( state.backtracking==0 ) {

							retval.tree = root_0;
							RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

							root_0 = (CommonTree)adaptor.nil();
							// 1006:57: -> ^( METHOD_CALL ^( DOT SUPER IDENT ) arguments )
							{
								// Java.g:1006:61: ^( METHOD_CALL ^( DOT SUPER IDENT ) arguments )
								{
								CommonTree root_1 = (CommonTree)adaptor.nil();
								root_1 = (CommonTree)adaptor.becomeRoot(
								(CommonTree)adaptor.create(METHOD_CALL, "METHOD_CALL")
								, root_1);

								// Java.g:1006:75: ^( DOT SUPER IDENT )
								{
								CommonTree root_2 = (CommonTree)adaptor.nil();
								root_2 = (CommonTree)adaptor.becomeRoot(
								stream_DOT.nextNode()
								, root_2);

								adaptor.addChild(root_2, 
								stream_SUPER.nextNode()
								);

								adaptor.addChild(root_2, 
								stream_IDENT.nextNode()
								);

								adaptor.addChild(root_1, root_2);
								}

								adaptor.addChild(root_1, stream_arguments.nextTree());

								adaptor.addChild(root_0, root_1);
								}

							}


							retval.tree = root_0;
							}

							}
							break;
						case 2 :
							// Java.g:1007:57: 
							{
							// AST REWRITE
							// elements: SUPER, DOT, IDENT
							// token labels: 
							// rule labels: retval
							// token list labels: 
							// rule list labels: 
							// wildcard labels: 
							if ( state.backtracking==0 ) {

							retval.tree = root_0;
							RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

							root_0 = (CommonTree)adaptor.nil();
							// 1007:57: -> ^( DOT SUPER IDENT )
							{
								// Java.g:1007:61: ^( DOT SUPER IDENT )
								{
								CommonTree root_1 = (CommonTree)adaptor.nil();
								root_1 = (CommonTree)adaptor.becomeRoot(
								stream_DOT.nextNode()
								, root_1);

								adaptor.addChild(root_1, 
								stream_SUPER.nextNode()
								);

								adaptor.addChild(root_1, 
								stream_IDENT.nextNode()
								);

								adaptor.addChild(root_0, root_1);
								}

							}


							retval.tree = root_0;
							}

							}
							break;

					}

					}
					break;
				case 9 :
					// Java.g:1009:9: ( primitiveType -> primitiveType ) ( arrayDeclarator -> ^( arrayDeclarator $primaryExpression) )* DOT CLASS
					{
					// Java.g:1009:9: ( primitiveType -> primitiveType )
					// Java.g:1009:13: primitiveType
					{
					pushFollow(FOLLOW_primitiveType_in_primaryExpression13352);
					primitiveType484=primitiveType();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_primitiveType.add(primitiveType484.getTree());
					// AST REWRITE
					// elements: primitiveType
					// token labels: 
					// rule labels: retval
					// token list labels: 
					// rule list labels: 
					// wildcard labels: 
					if ( state.backtracking==0 ) {

					retval.tree = root_0;
					RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

					root_0 = (CommonTree)adaptor.nil();
					// 1009:57: -> primitiveType
					{
						adaptor.addChild(root_0, stream_primitiveType.nextTree());

					}


					retval.tree = root_0;
					}

					}

					// Java.g:1011:9: ( arrayDeclarator -> ^( arrayDeclarator $primaryExpression) )*
					loop138:
					do {
						int alt138=2;
						int LA138_0 = input.LA(1);
						if ( (LA138_0==LBRACK) ) {
							alt138=1;
						}

						switch (alt138) {
						case 1 :
							// Java.g:1011:13: arrayDeclarator
							{
							pushFollow(FOLLOW_arrayDeclarator_in_primaryExpression13411);
							arrayDeclarator485=arrayDeclarator();
							state._fsp--;
							if (state.failed) return retval;
							if ( state.backtracking==0 ) stream_arrayDeclarator.add(arrayDeclarator485.getTree());
							// AST REWRITE
							// elements: arrayDeclarator, primaryExpression
							// token labels: 
							// rule labels: retval
							// token list labels: 
							// rule list labels: 
							// wildcard labels: 
							if ( state.backtracking==0 ) {

							retval.tree = root_0;
							RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

							root_0 = (CommonTree)adaptor.nil();
							// 1011:57: -> ^( arrayDeclarator $primaryExpression)
							{
								// Java.g:1011:61: ^( arrayDeclarator $primaryExpression)
								{
								CommonTree root_1 = (CommonTree)adaptor.nil();
								root_1 = (CommonTree)adaptor.becomeRoot(stream_arrayDeclarator.nextNode(), root_1);

								adaptor.addChild(root_1, stream_retval.nextTree());

								adaptor.addChild(root_0, root_1);
								}

							}


							retval.tree = root_0;
							}

							}
							break;

						default :
							break loop138;
						}
					} while (true);

					DOT486=(Token)match(input,DOT,FOLLOW_DOT_in_primaryExpression13474); if (state.failed) return retval; 
					if ( state.backtracking==0 ) stream_DOT.add(DOT486);

					CLASS487=(Token)match(input,CLASS,FOLLOW_CLASS_in_primaryExpression13476); if (state.failed) return retval; 
					if ( state.backtracking==0 ) stream_CLASS.add(CLASS487);

					// AST REWRITE
					// elements: CLASS, primaryExpression, DOT
					// token labels: 
					// rule labels: retval
					// token list labels: 
					// rule list labels: 
					// wildcard labels: 
					if ( state.backtracking==0 ) {

					retval.tree = root_0;
					RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

					root_0 = (CommonTree)adaptor.nil();
					// 1013:57: -> ^( DOT $primaryExpression CLASS )
					{
						// Java.g:1013:61: ^( DOT $primaryExpression CLASS )
						{
						CommonTree root_1 = (CommonTree)adaptor.nil();
						root_1 = (CommonTree)adaptor.becomeRoot(
						stream_DOT.nextNode()
						, root_1);

						adaptor.addChild(root_1, stream_retval.nextTree());

						adaptor.addChild(root_1, 
						stream_CLASS.nextNode()
						);

						adaptor.addChild(root_0, root_1);
						}

					}


					retval.tree = root_0;
					}

					}
					break;
				case 10 :
					// Java.g:1014:9: VOID DOT CLASS
					{
					VOID488=(Token)match(input,VOID,FOLLOW_VOID_in_primaryExpression13536); if (state.failed) return retval; 
					if ( state.backtracking==0 ) stream_VOID.add(VOID488);

					DOT489=(Token)match(input,DOT,FOLLOW_DOT_in_primaryExpression13538); if (state.failed) return retval; 
					if ( state.backtracking==0 ) stream_DOT.add(DOT489);

					CLASS490=(Token)match(input,CLASS,FOLLOW_CLASS_in_primaryExpression13540); if (state.failed) return retval; 
					if ( state.backtracking==0 ) stream_CLASS.add(CLASS490);

					// AST REWRITE
					// elements: DOT, VOID, CLASS
					// token labels: 
					// rule labels: retval
					// token list labels: 
					// rule list labels: 
					// wildcard labels: 
					if ( state.backtracking==0 ) {

					retval.tree = root_0;
					RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

					root_0 = (CommonTree)adaptor.nil();
					// 1014:57: -> ^( DOT VOID CLASS )
					{
						// Java.g:1014:61: ^( DOT VOID CLASS )
						{
						CommonTree root_1 = (CommonTree)adaptor.nil();
						root_1 = (CommonTree)adaptor.becomeRoot(
						stream_DOT.nextNode()
						, root_1);

						adaptor.addChild(root_1, 
						stream_VOID.nextNode()
						);

						adaptor.addChild(root_1, 
						stream_CLASS.nextNode()
						);

						adaptor.addChild(root_0, root_1);
						}

					}


					retval.tree = root_0;
					}

					}
					break;

			}
			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 105, primaryExpression_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "primaryExpression"


	public static class qualifiedIdentExpression_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "qualifiedIdentExpression"
	// Java.g:1017:1: qualifiedIdentExpression : ( qualifiedIdentifier -> qualifiedIdentifier ) ( ( arrayDeclarator -> ^( arrayDeclarator $qualifiedIdentExpression) )+ ( DOT CLASS -> ^( DOT $qualifiedIdentExpression CLASS ) ) | arguments -> ^( METHOD_CALL qualifiedIdentifier arguments ) |outerDot= DOT ( CLASS -> ^( DOT qualifiedIdentifier CLASS ) | genericTypeArgumentListSimplified (Super= SUPER arguments -> ^( SUPER_CONSTRUCTOR_CALL[$Super, \"SUPER_CONSTRUCTOR_CALL\"] qualifiedIdentifier genericTypeArgumentListSimplified arguments ) | SUPER innerDot= DOT IDENT arguments -> ^( METHOD_CALL ^( $innerDot ^( $outerDot qualifiedIdentifier SUPER ) IDENT ) genericTypeArgumentListSimplified arguments ) | IDENT arguments -> ^( METHOD_CALL ^( DOT qualifiedIdentifier IDENT ) genericTypeArgumentListSimplified arguments ) ) | THIS -> ^( DOT qualifiedIdentifier THIS ) |Super= SUPER arguments -> ^( SUPER_CONSTRUCTOR_CALL[$Super, \"SUPER_CONSTRUCTOR_CALL\"] qualifiedIdentifier arguments ) | innerNewExpression -> ^( DOT qualifiedIdentifier innerNewExpression ) ) )? ;
	public final JavaParser.qualifiedIdentExpression_return qualifiedIdentExpression() throws RecognitionException {
		JavaParser.qualifiedIdentExpression_return retval = new JavaParser.qualifiedIdentExpression_return();
		retval.start = input.LT(1);
		int qualifiedIdentExpression_StartIndex = input.index();

		CommonTree root_0 = null;

		Token outerDot=null;
		Token Super=null;
		Token innerDot=null;
		Token DOT493=null;
		Token CLASS494=null;
		Token CLASS496=null;
		Token SUPER499=null;
		Token IDENT500=null;
		Token IDENT502=null;
		Token THIS504=null;
		ParserRuleReturnScope qualifiedIdentifier491 =null;
		ParserRuleReturnScope arrayDeclarator492 =null;
		ParserRuleReturnScope arguments495 =null;
		ParserRuleReturnScope genericTypeArgumentListSimplified497 =null;
		ParserRuleReturnScope arguments498 =null;
		ParserRuleReturnScope arguments501 =null;
		ParserRuleReturnScope arguments503 =null;
		ParserRuleReturnScope arguments505 =null;
		ParserRuleReturnScope innerNewExpression506 =null;

		CommonTree outerDot_tree=null;
		CommonTree Super_tree=null;
		CommonTree innerDot_tree=null;
		CommonTree DOT493_tree=null;
		CommonTree CLASS494_tree=null;
		CommonTree CLASS496_tree=null;
		CommonTree SUPER499_tree=null;
		CommonTree IDENT500_tree=null;
		CommonTree IDENT502_tree=null;
		CommonTree THIS504_tree=null;
		RewriteRuleTokenStream stream_IDENT=new RewriteRuleTokenStream(adaptor,"token IDENT");
		RewriteRuleTokenStream stream_CLASS=new RewriteRuleTokenStream(adaptor,"token CLASS");
		RewriteRuleTokenStream stream_SUPER=new RewriteRuleTokenStream(adaptor,"token SUPER");
		RewriteRuleTokenStream stream_DOT=new RewriteRuleTokenStream(adaptor,"token DOT");
		RewriteRuleTokenStream stream_THIS=new RewriteRuleTokenStream(adaptor,"token THIS");
		RewriteRuleSubtreeStream stream_arrayDeclarator=new RewriteRuleSubtreeStream(adaptor,"rule arrayDeclarator");
		RewriteRuleSubtreeStream stream_arguments=new RewriteRuleSubtreeStream(adaptor,"rule arguments");
		RewriteRuleSubtreeStream stream_qualifiedIdentifier=new RewriteRuleSubtreeStream(adaptor,"rule qualifiedIdentifier");
		RewriteRuleSubtreeStream stream_genericTypeArgumentListSimplified=new RewriteRuleSubtreeStream(adaptor,"rule genericTypeArgumentListSimplified");
		RewriteRuleSubtreeStream stream_innerNewExpression=new RewriteRuleSubtreeStream(adaptor,"rule innerNewExpression");

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 106) ) { return retval; }

			// Java.g:1019:5: ( ( qualifiedIdentifier -> qualifiedIdentifier ) ( ( arrayDeclarator -> ^( arrayDeclarator $qualifiedIdentExpression) )+ ( DOT CLASS -> ^( DOT $qualifiedIdentExpression CLASS ) ) | arguments -> ^( METHOD_CALL qualifiedIdentifier arguments ) |outerDot= DOT ( CLASS -> ^( DOT qualifiedIdentifier CLASS ) | genericTypeArgumentListSimplified (Super= SUPER arguments -> ^( SUPER_CONSTRUCTOR_CALL[$Super, \"SUPER_CONSTRUCTOR_CALL\"] qualifiedIdentifier genericTypeArgumentListSimplified arguments ) | SUPER innerDot= DOT IDENT arguments -> ^( METHOD_CALL ^( $innerDot ^( $outerDot qualifiedIdentifier SUPER ) IDENT ) genericTypeArgumentListSimplified arguments ) | IDENT arguments -> ^( METHOD_CALL ^( DOT qualifiedIdentifier IDENT ) genericTypeArgumentListSimplified arguments ) ) | THIS -> ^( DOT qualifiedIdentifier THIS ) |Super= SUPER arguments -> ^( SUPER_CONSTRUCTOR_CALL[$Super, \"SUPER_CONSTRUCTOR_CALL\"] qualifiedIdentifier arguments ) | innerNewExpression -> ^( DOT qualifiedIdentifier innerNewExpression ) ) )? )
			// Java.g:1019:9: ( qualifiedIdentifier -> qualifiedIdentifier ) ( ( arrayDeclarator -> ^( arrayDeclarator $qualifiedIdentExpression) )+ ( DOT CLASS -> ^( DOT $qualifiedIdentExpression CLASS ) ) | arguments -> ^( METHOD_CALL qualifiedIdentifier arguments ) |outerDot= DOT ( CLASS -> ^( DOT qualifiedIdentifier CLASS ) | genericTypeArgumentListSimplified (Super= SUPER arguments -> ^( SUPER_CONSTRUCTOR_CALL[$Super, \"SUPER_CONSTRUCTOR_CALL\"] qualifiedIdentifier genericTypeArgumentListSimplified arguments ) | SUPER innerDot= DOT IDENT arguments -> ^( METHOD_CALL ^( $innerDot ^( $outerDot qualifiedIdentifier SUPER ) IDENT ) genericTypeArgumentListSimplified arguments ) | IDENT arguments -> ^( METHOD_CALL ^( DOT qualifiedIdentifier IDENT ) genericTypeArgumentListSimplified arguments ) ) | THIS -> ^( DOT qualifiedIdentifier THIS ) |Super= SUPER arguments -> ^( SUPER_CONSTRUCTOR_CALL[$Super, \"SUPER_CONSTRUCTOR_CALL\"] qualifiedIdentifier arguments ) | innerNewExpression -> ^( DOT qualifiedIdentifier innerNewExpression ) ) )?
			{
			// Java.g:1019:9: ( qualifiedIdentifier -> qualifiedIdentifier )
			// Java.g:1019:13: qualifiedIdentifier
			{
			pushFollow(FOLLOW_qualifiedIdentifier_in_qualifiedIdentExpression13620);
			qualifiedIdentifier491=qualifiedIdentifier();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) stream_qualifiedIdentifier.add(qualifiedIdentifier491.getTree());
			// AST REWRITE
			// elements: qualifiedIdentifier
			// token labels: 
			// rule labels: retval
			// token list labels: 
			// rule list labels: 
			// wildcard labels: 
			if ( state.backtracking==0 ) {

			retval.tree = root_0;
			RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

			root_0 = (CommonTree)adaptor.nil();
			// 1019:61: -> qualifiedIdentifier
			{
				adaptor.addChild(root_0, stream_qualifiedIdentifier.nextTree());

			}


			retval.tree = root_0;
			}

			}

			// Java.g:1022:9: ( ( arrayDeclarator -> ^( arrayDeclarator $qualifiedIdentExpression) )+ ( DOT CLASS -> ^( DOT $qualifiedIdentExpression CLASS ) ) | arguments -> ^( METHOD_CALL qualifiedIdentifier arguments ) |outerDot= DOT ( CLASS -> ^( DOT qualifiedIdentifier CLASS ) | genericTypeArgumentListSimplified (Super= SUPER arguments -> ^( SUPER_CONSTRUCTOR_CALL[$Super, \"SUPER_CONSTRUCTOR_CALL\"] qualifiedIdentifier genericTypeArgumentListSimplified arguments ) | SUPER innerDot= DOT IDENT arguments -> ^( METHOD_CALL ^( $innerDot ^( $outerDot qualifiedIdentifier SUPER ) IDENT ) genericTypeArgumentListSimplified arguments ) | IDENT arguments -> ^( METHOD_CALL ^( DOT qualifiedIdentifier IDENT ) genericTypeArgumentListSimplified arguments ) ) | THIS -> ^( DOT qualifiedIdentifier THIS ) |Super= SUPER arguments -> ^( SUPER_CONSTRUCTOR_CALL[$Super, \"SUPER_CONSTRUCTOR_CALL\"] qualifiedIdentifier arguments ) | innerNewExpression -> ^( DOT qualifiedIdentifier innerNewExpression ) ) )?
			int alt143=4;
			switch ( input.LA(1) ) {
				case LBRACK:
					{
					int LA143_1 = input.LA(2);
					if ( (synpred218_Java()) ) {
						alt143=1;
					}
					}
					break;
				case LPAREN:
					{
					alt143=2;
					}
					break;
				case DOT:
					{
					int LA143_3 = input.LA(2);
					if ( (synpred226_Java()) ) {
						alt143=3;
					}
					}
					break;
			}
			switch (alt143) {
				case 1 :
					// Java.g:1022:13: ( arrayDeclarator -> ^( arrayDeclarator $qualifiedIdentExpression) )+ ( DOT CLASS -> ^( DOT $qualifiedIdentExpression CLASS ) )
					{
					// Java.g:1022:13: ( arrayDeclarator -> ^( arrayDeclarator $qualifiedIdentExpression) )+
					int cnt140=0;
					loop140:
					do {
						int alt140=2;
						int LA140_0 = input.LA(1);
						if ( (LA140_0==LBRACK) ) {
							alt140=1;
						}

						switch (alt140) {
						case 1 :
							// Java.g:1022:17: arrayDeclarator
							{
							pushFollow(FOLLOW_arrayDeclarator_in_qualifiedIdentExpression13690);
							arrayDeclarator492=arrayDeclarator();
							state._fsp--;
							if (state.failed) return retval;
							if ( state.backtracking==0 ) stream_arrayDeclarator.add(arrayDeclarator492.getTree());
							// AST REWRITE
							// elements: arrayDeclarator, qualifiedIdentExpression
							// token labels: 
							// rule labels: retval
							// token list labels: 
							// rule list labels: 
							// wildcard labels: 
							if ( state.backtracking==0 ) {

							retval.tree = root_0;
							RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

							root_0 = (CommonTree)adaptor.nil();
							// 1022:57: -> ^( arrayDeclarator $qualifiedIdentExpression)
							{
								// Java.g:1022:61: ^( arrayDeclarator $qualifiedIdentExpression)
								{
								CommonTree root_1 = (CommonTree)adaptor.nil();
								root_1 = (CommonTree)adaptor.becomeRoot(stream_arrayDeclarator.nextNode(), root_1);

								adaptor.addChild(root_1, stream_retval.nextTree());

								adaptor.addChild(root_0, root_1);
								}

							}


							retval.tree = root_0;
							}

							}
							break;

						default :
							if ( cnt140 >= 1 ) break loop140;
							if (state.backtracking>0) {state.failed=true; return retval;}
								EarlyExitException eee =
									new EarlyExitException(140, input);
								throw eee;
						}
						cnt140++;
					} while (true);

					// Java.g:1024:13: ( DOT CLASS -> ^( DOT $qualifiedIdentExpression CLASS ) )
					// Java.g:1024:17: DOT CLASS
					{
					DOT493=(Token)match(input,DOT,FOLLOW_DOT_in_qualifiedIdentExpression13758); if (state.failed) return retval; 
					if ( state.backtracking==0 ) stream_DOT.add(DOT493);

					CLASS494=(Token)match(input,CLASS,FOLLOW_CLASS_in_qualifiedIdentExpression13760); if (state.failed) return retval; 
					if ( state.backtracking==0 ) stream_CLASS.add(CLASS494);

					// AST REWRITE
					// elements: DOT, qualifiedIdentExpression, CLASS
					// token labels: 
					// rule labels: retval
					// token list labels: 
					// rule list labels: 
					// wildcard labels: 
					if ( state.backtracking==0 ) {

					retval.tree = root_0;
					RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

					root_0 = (CommonTree)adaptor.nil();
					// 1024:57: -> ^( DOT $qualifiedIdentExpression CLASS )
					{
						// Java.g:1024:61: ^( DOT $qualifiedIdentExpression CLASS )
						{
						CommonTree root_1 = (CommonTree)adaptor.nil();
						root_1 = (CommonTree)adaptor.becomeRoot(
						stream_DOT.nextNode()
						, root_1);

						adaptor.addChild(root_1, stream_retval.nextTree());

						adaptor.addChild(root_1, 
						stream_CLASS.nextNode()
						);

						adaptor.addChild(root_0, root_1);
						}

					}


					retval.tree = root_0;
					}

					}

					}
					break;
				case 2 :
					// Java.g:1026:13: arguments
					{
					pushFollow(FOLLOW_arguments_in_qualifiedIdentExpression13830);
					arguments495=arguments();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_arguments.add(arguments495.getTree());
					// AST REWRITE
					// elements: qualifiedIdentifier, arguments
					// token labels: 
					// rule labels: retval
					// token list labels: 
					// rule list labels: 
					// wildcard labels: 
					if ( state.backtracking==0 ) {

					retval.tree = root_0;
					RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

					root_0 = (CommonTree)adaptor.nil();
					// 1026:57: -> ^( METHOD_CALL qualifiedIdentifier arguments )
					{
						// Java.g:1026:61: ^( METHOD_CALL qualifiedIdentifier arguments )
						{
						CommonTree root_1 = (CommonTree)adaptor.nil();
						root_1 = (CommonTree)adaptor.becomeRoot(
						(CommonTree)adaptor.create(METHOD_CALL, "METHOD_CALL")
						, root_1);

						adaptor.addChild(root_1, stream_qualifiedIdentifier.nextTree());

						adaptor.addChild(root_1, stream_arguments.nextTree());

						adaptor.addChild(root_0, root_1);
						}

					}


					retval.tree = root_0;
					}

					}
					break;
				case 3 :
					// Java.g:1027:13: outerDot= DOT ( CLASS -> ^( DOT qualifiedIdentifier CLASS ) | genericTypeArgumentListSimplified (Super= SUPER arguments -> ^( SUPER_CONSTRUCTOR_CALL[$Super, \"SUPER_CONSTRUCTOR_CALL\"] qualifiedIdentifier genericTypeArgumentListSimplified arguments ) | SUPER innerDot= DOT IDENT arguments -> ^( METHOD_CALL ^( $innerDot ^( $outerDot qualifiedIdentifier SUPER ) IDENT ) genericTypeArgumentListSimplified arguments ) | IDENT arguments -> ^( METHOD_CALL ^( DOT qualifiedIdentifier IDENT ) genericTypeArgumentListSimplified arguments ) ) | THIS -> ^( DOT qualifiedIdentifier THIS ) |Super= SUPER arguments -> ^( SUPER_CONSTRUCTOR_CALL[$Super, \"SUPER_CONSTRUCTOR_CALL\"] qualifiedIdentifier arguments ) | innerNewExpression -> ^( DOT qualifiedIdentifier innerNewExpression ) )
					{
					outerDot=(Token)match(input,DOT,FOLLOW_DOT_in_qualifiedIdentExpression13891); if (state.failed) return retval; 
					if ( state.backtracking==0 ) stream_DOT.add(outerDot);

					// Java.g:1028:13: ( CLASS -> ^( DOT qualifiedIdentifier CLASS ) | genericTypeArgumentListSimplified (Super= SUPER arguments -> ^( SUPER_CONSTRUCTOR_CALL[$Super, \"SUPER_CONSTRUCTOR_CALL\"] qualifiedIdentifier genericTypeArgumentListSimplified arguments ) | SUPER innerDot= DOT IDENT arguments -> ^( METHOD_CALL ^( $innerDot ^( $outerDot qualifiedIdentifier SUPER ) IDENT ) genericTypeArgumentListSimplified arguments ) | IDENT arguments -> ^( METHOD_CALL ^( DOT qualifiedIdentifier IDENT ) genericTypeArgumentListSimplified arguments ) ) | THIS -> ^( DOT qualifiedIdentifier THIS ) |Super= SUPER arguments -> ^( SUPER_CONSTRUCTOR_CALL[$Super, \"SUPER_CONSTRUCTOR_CALL\"] qualifiedIdentifier arguments ) | innerNewExpression -> ^( DOT qualifiedIdentifier innerNewExpression ) )
					int alt142=5;
					switch ( input.LA(1) ) {
					case CLASS:
						{
						alt142=1;
						}
						break;
					case LESS_THAN:
						{
						alt142=2;
						}
						break;
					case THIS:
						{
						alt142=3;
						}
						break;
					case SUPER:
						{
						alt142=4;
						}
						break;
					case NEW:
						{
						alt142=5;
						}
						break;
					default:
						if (state.backtracking>0) {state.failed=true; return retval;}
						NoViableAltException nvae =
							new NoViableAltException("", 142, 0, input);
						throw nvae;
					}
					switch (alt142) {
						case 1 :
							// Java.g:1028:17: CLASS
							{
							CLASS496=(Token)match(input,CLASS,FOLLOW_CLASS_in_qualifiedIdentExpression13909); if (state.failed) return retval; 
							if ( state.backtracking==0 ) stream_CLASS.add(CLASS496);

							// AST REWRITE
							// elements: CLASS, qualifiedIdentifier, DOT
							// token labels: 
							// rule labels: retval
							// token list labels: 
							// rule list labels: 
							// wildcard labels: 
							if ( state.backtracking==0 ) {

							retval.tree = root_0;
							RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

							root_0 = (CommonTree)adaptor.nil();
							// 1028:57: -> ^( DOT qualifiedIdentifier CLASS )
							{
								// Java.g:1028:61: ^( DOT qualifiedIdentifier CLASS )
								{
								CommonTree root_1 = (CommonTree)adaptor.nil();
								root_1 = (CommonTree)adaptor.becomeRoot(
								stream_DOT.nextNode()
								, root_1);

								adaptor.addChild(root_1, stream_qualifiedIdentifier.nextTree());

								adaptor.addChild(root_1, 
								stream_CLASS.nextNode()
								);

								adaptor.addChild(root_0, root_1);
								}

							}


							retval.tree = root_0;
							}

							}
							break;
						case 2 :
							// Java.g:1029:17: genericTypeArgumentListSimplified (Super= SUPER arguments -> ^( SUPER_CONSTRUCTOR_CALL[$Super, \"SUPER_CONSTRUCTOR_CALL\"] qualifiedIdentifier genericTypeArgumentListSimplified arguments ) | SUPER innerDot= DOT IDENT arguments -> ^( METHOD_CALL ^( $innerDot ^( $outerDot qualifiedIdentifier SUPER ) IDENT ) genericTypeArgumentListSimplified arguments ) | IDENT arguments -> ^( METHOD_CALL ^( DOT qualifiedIdentifier IDENT ) genericTypeArgumentListSimplified arguments ) )
							{
							pushFollow(FOLLOW_genericTypeArgumentListSimplified_in_qualifiedIdentExpression13972);
							genericTypeArgumentListSimplified497=genericTypeArgumentListSimplified();
							state._fsp--;
							if (state.failed) return retval;
							if ( state.backtracking==0 ) stream_genericTypeArgumentListSimplified.add(genericTypeArgumentListSimplified497.getTree());
							// Java.g:1030:17: (Super= SUPER arguments -> ^( SUPER_CONSTRUCTOR_CALL[$Super, \"SUPER_CONSTRUCTOR_CALL\"] qualifiedIdentifier genericTypeArgumentListSimplified arguments ) | SUPER innerDot= DOT IDENT arguments -> ^( METHOD_CALL ^( $innerDot ^( $outerDot qualifiedIdentifier SUPER ) IDENT ) genericTypeArgumentListSimplified arguments ) | IDENT arguments -> ^( METHOD_CALL ^( DOT qualifiedIdentifier IDENT ) genericTypeArgumentListSimplified arguments ) )
							int alt141=3;
							int LA141_0 = input.LA(1);
							if ( (LA141_0==SUPER) ) {
								int LA141_1 = input.LA(2);
								if ( (LA141_1==DOT) ) {
									alt141=2;
								}
								else if ( (LA141_1==LPAREN) ) {
									alt141=1;
								}
								else {
									if (state.backtracking>0) {state.failed=true; return retval;}
									int nvaeMark = input.mark();
									try {
										input.consume();
										NoViableAltException nvae =
											new NoViableAltException("", 141, 1, input);
										throw nvae;
									} finally {
										input.rewind(nvaeMark);
									}
								}
							}
							else if ( (LA141_0==IDENT) ) {
								alt141=3;
							}
							else {
								if (state.backtracking>0) {state.failed=true; return retval;}
								NoViableAltException nvae =
									new NoViableAltException("", 141, 0, input);
								throw nvae;
							}
							switch (alt141) {
								case 1 :
									// Java.g:1030:21: Super= SUPER arguments
									{
									Super=(Token)match(input,SUPER,FOLLOW_SUPER_in_qualifiedIdentExpression13997); if (state.failed) return retval; 
									if ( state.backtracking==0 ) stream_SUPER.add(Super);

									pushFollow(FOLLOW_arguments_in_qualifiedIdentExpression13999);
									arguments498=arguments();
									state._fsp--;
									if (state.failed) return retval;
									if ( state.backtracking==0 ) stream_arguments.add(arguments498.getTree());
									// AST REWRITE
									// elements: genericTypeArgumentListSimplified, arguments, qualifiedIdentifier
									// token labels: 
									// rule labels: retval
									// token list labels: 
									// rule list labels: 
									// wildcard labels: 
									if ( state.backtracking==0 ) {

									retval.tree = root_0;
									RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

									root_0 = (CommonTree)adaptor.nil();
									// 1030:57: -> ^( SUPER_CONSTRUCTOR_CALL[$Super, \"SUPER_CONSTRUCTOR_CALL\"] qualifiedIdentifier genericTypeArgumentListSimplified arguments )
									{
										// Java.g:1030:61: ^( SUPER_CONSTRUCTOR_CALL[$Super, \"SUPER_CONSTRUCTOR_CALL\"] qualifiedIdentifier genericTypeArgumentListSimplified arguments )
										{
										CommonTree root_1 = (CommonTree)adaptor.nil();
										root_1 = (CommonTree)adaptor.becomeRoot(
										(CommonTree)adaptor.create(SUPER_CONSTRUCTOR_CALL, Super, "SUPER_CONSTRUCTOR_CALL")
										, root_1);

										adaptor.addChild(root_1, stream_qualifiedIdentifier.nextTree());

										adaptor.addChild(root_1, stream_genericTypeArgumentListSimplified.nextTree());

										adaptor.addChild(root_1, stream_arguments.nextTree());

										adaptor.addChild(root_0, root_1);
										}

									}


									retval.tree = root_0;
									}

									}
									break;
								case 2 :
									// Java.g:1031:21: SUPER innerDot= DOT IDENT arguments
									{
									SUPER499=(Token)match(input,SUPER,FOLLOW_SUPER_in_qualifiedIdentExpression14049); if (state.failed) return retval; 
									if ( state.backtracking==0 ) stream_SUPER.add(SUPER499);

									innerDot=(Token)match(input,DOT,FOLLOW_DOT_in_qualifiedIdentExpression14053); if (state.failed) return retval; 
									if ( state.backtracking==0 ) stream_DOT.add(innerDot);

									IDENT500=(Token)match(input,IDENT,FOLLOW_IDENT_in_qualifiedIdentExpression14055); if (state.failed) return retval; 
									if ( state.backtracking==0 ) stream_IDENT.add(IDENT500);

									pushFollow(FOLLOW_arguments_in_qualifiedIdentExpression14057);
									arguments501=arguments();
									state._fsp--;
									if (state.failed) return retval;
									if ( state.backtracking==0 ) stream_arguments.add(arguments501.getTree());
									// AST REWRITE
									// elements: IDENT, genericTypeArgumentListSimplified, qualifiedIdentifier, outerDot, SUPER, innerDot, arguments
									// token labels: outerDot, innerDot
									// rule labels: retval
									// token list labels: 
									// rule list labels: 
									// wildcard labels: 
									if ( state.backtracking==0 ) {

									retval.tree = root_0;
									RewriteRuleTokenStream stream_outerDot=new RewriteRuleTokenStream(adaptor,"token outerDot",outerDot);
									RewriteRuleTokenStream stream_innerDot=new RewriteRuleTokenStream(adaptor,"token innerDot",innerDot);
									RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

									root_0 = (CommonTree)adaptor.nil();
									// 1031:57: -> ^( METHOD_CALL ^( $innerDot ^( $outerDot qualifiedIdentifier SUPER ) IDENT ) genericTypeArgumentListSimplified arguments )
									{
										// Java.g:1031:61: ^( METHOD_CALL ^( $innerDot ^( $outerDot qualifiedIdentifier SUPER ) IDENT ) genericTypeArgumentListSimplified arguments )
										{
										CommonTree root_1 = (CommonTree)adaptor.nil();
										root_1 = (CommonTree)adaptor.becomeRoot(
										(CommonTree)adaptor.create(METHOD_CALL, "METHOD_CALL")
										, root_1);

										// Java.g:1031:75: ^( $innerDot ^( $outerDot qualifiedIdentifier SUPER ) IDENT )
										{
										CommonTree root_2 = (CommonTree)adaptor.nil();
										root_2 = (CommonTree)adaptor.becomeRoot(stream_innerDot.nextNode(), root_2);

										// Java.g:1031:87: ^( $outerDot qualifiedIdentifier SUPER )
										{
										CommonTree root_3 = (CommonTree)adaptor.nil();
										root_3 = (CommonTree)adaptor.becomeRoot(stream_outerDot.nextNode(), root_3);

										adaptor.addChild(root_3, stream_qualifiedIdentifier.nextTree());

										adaptor.addChild(root_3, 
										stream_SUPER.nextNode()
										);

										adaptor.addChild(root_2, root_3);
										}

										adaptor.addChild(root_2, 
										stream_IDENT.nextNode()
										);

										adaptor.addChild(root_1, root_2);
										}

										adaptor.addChild(root_1, stream_genericTypeArgumentListSimplified.nextTree());

										adaptor.addChild(root_1, stream_arguments.nextTree());

										adaptor.addChild(root_0, root_1);
										}

									}


									retval.tree = root_0;
									}

									}
									break;
								case 3 :
									// Java.g:1032:21: IDENT arguments
									{
									IDENT502=(Token)match(input,IDENT,FOLLOW_IDENT_in_qualifiedIdentExpression14107); if (state.failed) return retval; 
									if ( state.backtracking==0 ) stream_IDENT.add(IDENT502);

									pushFollow(FOLLOW_arguments_in_qualifiedIdentExpression14109);
									arguments503=arguments();
									state._fsp--;
									if (state.failed) return retval;
									if ( state.backtracking==0 ) stream_arguments.add(arguments503.getTree());
									// AST REWRITE
									// elements: arguments, qualifiedIdentifier, IDENT, DOT, genericTypeArgumentListSimplified
									// token labels: 
									// rule labels: retval
									// token list labels: 
									// rule list labels: 
									// wildcard labels: 
									if ( state.backtracking==0 ) {

									retval.tree = root_0;
									RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

									root_0 = (CommonTree)adaptor.nil();
									// 1032:57: -> ^( METHOD_CALL ^( DOT qualifiedIdentifier IDENT ) genericTypeArgumentListSimplified arguments )
									{
										// Java.g:1032:61: ^( METHOD_CALL ^( DOT qualifiedIdentifier IDENT ) genericTypeArgumentListSimplified arguments )
										{
										CommonTree root_1 = (CommonTree)adaptor.nil();
										root_1 = (CommonTree)adaptor.becomeRoot(
										(CommonTree)adaptor.create(METHOD_CALL, "METHOD_CALL")
										, root_1);

										// Java.g:1032:75: ^( DOT qualifiedIdentifier IDENT )
										{
										CommonTree root_2 = (CommonTree)adaptor.nil();
										root_2 = (CommonTree)adaptor.becomeRoot(
										stream_DOT.nextNode()
										, root_2);

										adaptor.addChild(root_2, stream_qualifiedIdentifier.nextTree());

										adaptor.addChild(root_2, 
										stream_IDENT.nextNode()
										);

										adaptor.addChild(root_1, root_2);
										}

										adaptor.addChild(root_1, stream_genericTypeArgumentListSimplified.nextTree());

										adaptor.addChild(root_1, stream_arguments.nextTree());

										adaptor.addChild(root_0, root_1);
										}

									}


									retval.tree = root_0;
									}

									}
									break;

							}

							}
							break;
						case 3 :
							// Java.g:1034:17: THIS
							{
							THIS504=(Token)match(input,THIS,FOLLOW_THIS_in_qualifiedIdentExpression14184); if (state.failed) return retval; 
							if ( state.backtracking==0 ) stream_THIS.add(THIS504);

							// AST REWRITE
							// elements: qualifiedIdentifier, THIS, DOT
							// token labels: 
							// rule labels: retval
							// token list labels: 
							// rule list labels: 
							// wildcard labels: 
							if ( state.backtracking==0 ) {

							retval.tree = root_0;
							RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

							root_0 = (CommonTree)adaptor.nil();
							// 1034:57: -> ^( DOT qualifiedIdentifier THIS )
							{
								// Java.g:1034:61: ^( DOT qualifiedIdentifier THIS )
								{
								CommonTree root_1 = (CommonTree)adaptor.nil();
								root_1 = (CommonTree)adaptor.becomeRoot(
								stream_DOT.nextNode()
								, root_1);

								adaptor.addChild(root_1, stream_qualifiedIdentifier.nextTree());

								adaptor.addChild(root_1, 
								stream_THIS.nextNode()
								);

								adaptor.addChild(root_0, root_1);
								}

							}


							retval.tree = root_0;
							}

							}
							break;
						case 4 :
							// Java.g:1035:17: Super= SUPER arguments
							{
							Super=(Token)match(input,SUPER,FOLLOW_SUPER_in_qualifiedIdentExpression14250); if (state.failed) return retval; 
							if ( state.backtracking==0 ) stream_SUPER.add(Super);

							pushFollow(FOLLOW_arguments_in_qualifiedIdentExpression14252);
							arguments505=arguments();
							state._fsp--;
							if (state.failed) return retval;
							if ( state.backtracking==0 ) stream_arguments.add(arguments505.getTree());
							// AST REWRITE
							// elements: qualifiedIdentifier, arguments
							// token labels: 
							// rule labels: retval
							// token list labels: 
							// rule list labels: 
							// wildcard labels: 
							if ( state.backtracking==0 ) {

							retval.tree = root_0;
							RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

							root_0 = (CommonTree)adaptor.nil();
							// 1035:57: -> ^( SUPER_CONSTRUCTOR_CALL[$Super, \"SUPER_CONSTRUCTOR_CALL\"] qualifiedIdentifier arguments )
							{
								// Java.g:1035:61: ^( SUPER_CONSTRUCTOR_CALL[$Super, \"SUPER_CONSTRUCTOR_CALL\"] qualifiedIdentifier arguments )
								{
								CommonTree root_1 = (CommonTree)adaptor.nil();
								root_1 = (CommonTree)adaptor.becomeRoot(
								(CommonTree)adaptor.create(SUPER_CONSTRUCTOR_CALL, Super, "SUPER_CONSTRUCTOR_CALL")
								, root_1);

								adaptor.addChild(root_1, stream_qualifiedIdentifier.nextTree());

								adaptor.addChild(root_1, stream_arguments.nextTree());

								adaptor.addChild(root_0, root_1);
								}

							}


							retval.tree = root_0;
							}

							}
							break;
						case 5 :
							// Java.g:1036:17: innerNewExpression
							{
							pushFollow(FOLLOW_innerNewExpression_in_qualifiedIdentExpression14300);
							innerNewExpression506=innerNewExpression();
							state._fsp--;
							if (state.failed) return retval;
							if ( state.backtracking==0 ) stream_innerNewExpression.add(innerNewExpression506.getTree());
							// AST REWRITE
							// elements: qualifiedIdentifier, innerNewExpression, DOT
							// token labels: 
							// rule labels: retval
							// token list labels: 
							// rule list labels: 
							// wildcard labels: 
							if ( state.backtracking==0 ) {

							retval.tree = root_0;
							RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

							root_0 = (CommonTree)adaptor.nil();
							// 1036:57: -> ^( DOT qualifiedIdentifier innerNewExpression )
							{
								// Java.g:1036:61: ^( DOT qualifiedIdentifier innerNewExpression )
								{
								CommonTree root_1 = (CommonTree)adaptor.nil();
								root_1 = (CommonTree)adaptor.becomeRoot(
								stream_DOT.nextNode()
								, root_1);

								adaptor.addChild(root_1, stream_qualifiedIdentifier.nextTree());

								adaptor.addChild(root_1, stream_innerNewExpression.nextTree());

								adaptor.addChild(root_0, root_1);
								}

							}


							retval.tree = root_0;
							}

							}
							break;

					}

					}
					break;

			}

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 106, qualifiedIdentExpression_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "qualifiedIdentExpression"


	public static class newExpression_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "newExpression"
	// Java.g:1041:1: newExpression : NEW ( primitiveType newArrayConstruction -> ^( STATIC_ARRAY_CREATOR[$NEW, \"STATIC_ARRAY_CREATOR\"] primitiveType newArrayConstruction ) | ( genericTypeArgumentListSimplified )? qualifiedTypeIdentSimplified ( newArrayConstruction -> ^( STATIC_ARRAY_CREATOR[$NEW, \"STATIC_ARRAY_CREATOR\"] ( genericTypeArgumentListSimplified )? qualifiedTypeIdentSimplified newArrayConstruction ) | arguments ( classBody )? -> ^( CLASS_CONSTRUCTOR_CALL[$NEW, \"STATIC_ARRAY_CREATOR\"] ( genericTypeArgumentListSimplified )? qualifiedTypeIdentSimplified arguments ( classBody )? ) ) ) ;
	public final JavaParser.newExpression_return newExpression() throws RecognitionException {
		JavaParser.newExpression_return retval = new JavaParser.newExpression_return();
		retval.start = input.LT(1);
		int newExpression_StartIndex = input.index();

		CommonTree root_0 = null;

		Token NEW507=null;
		ParserRuleReturnScope primitiveType508 =null;
		ParserRuleReturnScope newArrayConstruction509 =null;
		ParserRuleReturnScope genericTypeArgumentListSimplified510 =null;
		ParserRuleReturnScope qualifiedTypeIdentSimplified511 =null;
		ParserRuleReturnScope newArrayConstruction512 =null;
		ParserRuleReturnScope arguments513 =null;
		ParserRuleReturnScope classBody514 =null;

		CommonTree NEW507_tree=null;
		RewriteRuleTokenStream stream_NEW=new RewriteRuleTokenStream(adaptor,"token NEW");
		RewriteRuleSubtreeStream stream_newArrayConstruction=new RewriteRuleSubtreeStream(adaptor,"rule newArrayConstruction");
		RewriteRuleSubtreeStream stream_arguments=new RewriteRuleSubtreeStream(adaptor,"rule arguments");
		RewriteRuleSubtreeStream stream_qualifiedTypeIdentSimplified=new RewriteRuleSubtreeStream(adaptor,"rule qualifiedTypeIdentSimplified");
		RewriteRuleSubtreeStream stream_primitiveType=new RewriteRuleSubtreeStream(adaptor,"rule primitiveType");
		RewriteRuleSubtreeStream stream_classBody=new RewriteRuleSubtreeStream(adaptor,"rule classBody");
		RewriteRuleSubtreeStream stream_genericTypeArgumentListSimplified=new RewriteRuleSubtreeStream(adaptor,"rule genericTypeArgumentListSimplified");

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 107) ) { return retval; }

			// Java.g:1042:5: ( NEW ( primitiveType newArrayConstruction -> ^( STATIC_ARRAY_CREATOR[$NEW, \"STATIC_ARRAY_CREATOR\"] primitiveType newArrayConstruction ) | ( genericTypeArgumentListSimplified )? qualifiedTypeIdentSimplified ( newArrayConstruction -> ^( STATIC_ARRAY_CREATOR[$NEW, \"STATIC_ARRAY_CREATOR\"] ( genericTypeArgumentListSimplified )? qualifiedTypeIdentSimplified newArrayConstruction ) | arguments ( classBody )? -> ^( CLASS_CONSTRUCTOR_CALL[$NEW, \"STATIC_ARRAY_CREATOR\"] ( genericTypeArgumentListSimplified )? qualifiedTypeIdentSimplified arguments ( classBody )? ) ) ) )
			// Java.g:1042:9: NEW ( primitiveType newArrayConstruction -> ^( STATIC_ARRAY_CREATOR[$NEW, \"STATIC_ARRAY_CREATOR\"] primitiveType newArrayConstruction ) | ( genericTypeArgumentListSimplified )? qualifiedTypeIdentSimplified ( newArrayConstruction -> ^( STATIC_ARRAY_CREATOR[$NEW, \"STATIC_ARRAY_CREATOR\"] ( genericTypeArgumentListSimplified )? qualifiedTypeIdentSimplified newArrayConstruction ) | arguments ( classBody )? -> ^( CLASS_CONSTRUCTOR_CALL[$NEW, \"STATIC_ARRAY_CREATOR\"] ( genericTypeArgumentListSimplified )? qualifiedTypeIdentSimplified arguments ( classBody )? ) ) )
			{
			NEW507=(Token)match(input,NEW,FOLLOW_NEW_in_newExpression14376); if (state.failed) return retval; 
			if ( state.backtracking==0 ) stream_NEW.add(NEW507);

			// Java.g:1043:9: ( primitiveType newArrayConstruction -> ^( STATIC_ARRAY_CREATOR[$NEW, \"STATIC_ARRAY_CREATOR\"] primitiveType newArrayConstruction ) | ( genericTypeArgumentListSimplified )? qualifiedTypeIdentSimplified ( newArrayConstruction -> ^( STATIC_ARRAY_CREATOR[$NEW, \"STATIC_ARRAY_CREATOR\"] ( genericTypeArgumentListSimplified )? qualifiedTypeIdentSimplified newArrayConstruction ) | arguments ( classBody )? -> ^( CLASS_CONSTRUCTOR_CALL[$NEW, \"STATIC_ARRAY_CREATOR\"] ( genericTypeArgumentListSimplified )? qualifiedTypeIdentSimplified arguments ( classBody )? ) ) )
			int alt147=2;
			int LA147_0 = input.LA(1);
			if ( (LA147_0==BOOLEAN||LA147_0==BYTE||LA147_0==CHAR||LA147_0==DOUBLE||LA147_0==FLOAT||LA147_0==INT||LA147_0==LONG||LA147_0==SHORT) ) {
				alt147=1;
			}
			else if ( (LA147_0==IDENT||LA147_0==LESS_THAN) ) {
				alt147=2;
			}
			else {
				if (state.backtracking>0) {state.failed=true; return retval;}
				NoViableAltException nvae =
					new NoViableAltException("", 147, 0, input);
				throw nvae;
			}
			switch (alt147) {
				case 1 :
					// Java.g:1043:13: primitiveType newArrayConstruction
					{
					pushFollow(FOLLOW_primitiveType_in_newExpression14392);
					primitiveType508=primitiveType();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_primitiveType.add(primitiveType508.getTree());
					pushFollow(FOLLOW_newArrayConstruction_in_newExpression14394);
					newArrayConstruction509=newArrayConstruction();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_newArrayConstruction.add(newArrayConstruction509.getTree());
					// AST REWRITE
					// elements: newArrayConstruction, primitiveType
					// token labels: 
					// rule labels: retval
					// token list labels: 
					// rule list labels: 
					// wildcard labels: 
					if ( state.backtracking==0 ) {

					retval.tree = root_0;
					RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

					root_0 = (CommonTree)adaptor.nil();
					// 1044:13: -> ^( STATIC_ARRAY_CREATOR[$NEW, \"STATIC_ARRAY_CREATOR\"] primitiveType newArrayConstruction )
					{
						// Java.g:1044:17: ^( STATIC_ARRAY_CREATOR[$NEW, \"STATIC_ARRAY_CREATOR\"] primitiveType newArrayConstruction )
						{
						CommonTree root_1 = (CommonTree)adaptor.nil();
						root_1 = (CommonTree)adaptor.becomeRoot(
						(CommonTree)adaptor.create(STATIC_ARRAY_CREATOR, NEW507, "STATIC_ARRAY_CREATOR")
						, root_1);

						adaptor.addChild(root_1, stream_primitiveType.nextTree());

						adaptor.addChild(root_1, stream_newArrayConstruction.nextTree());

						adaptor.addChild(root_0, root_1);
						}

					}


					retval.tree = root_0;
					}

					}
					break;
				case 2 :
					// Java.g:1045:13: ( genericTypeArgumentListSimplified )? qualifiedTypeIdentSimplified ( newArrayConstruction -> ^( STATIC_ARRAY_CREATOR[$NEW, \"STATIC_ARRAY_CREATOR\"] ( genericTypeArgumentListSimplified )? qualifiedTypeIdentSimplified newArrayConstruction ) | arguments ( classBody )? -> ^( CLASS_CONSTRUCTOR_CALL[$NEW, \"STATIC_ARRAY_CREATOR\"] ( genericTypeArgumentListSimplified )? qualifiedTypeIdentSimplified arguments ( classBody )? ) )
					{
					// Java.g:1045:13: ( genericTypeArgumentListSimplified )?
					int alt144=2;
					int LA144_0 = input.LA(1);
					if ( (LA144_0==LESS_THAN) ) {
						alt144=1;
					}
					switch (alt144) {
						case 1 :
							// Java.g:1045:13: genericTypeArgumentListSimplified
							{
							pushFollow(FOLLOW_genericTypeArgumentListSimplified_in_newExpression14438);
							genericTypeArgumentListSimplified510=genericTypeArgumentListSimplified();
							state._fsp--;
							if (state.failed) return retval;
							if ( state.backtracking==0 ) stream_genericTypeArgumentListSimplified.add(genericTypeArgumentListSimplified510.getTree());
							}
							break;

					}

					pushFollow(FOLLOW_qualifiedTypeIdentSimplified_in_newExpression14441);
					qualifiedTypeIdentSimplified511=qualifiedTypeIdentSimplified();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_qualifiedTypeIdentSimplified.add(qualifiedTypeIdentSimplified511.getTree());
					// Java.g:1046:13: ( newArrayConstruction -> ^( STATIC_ARRAY_CREATOR[$NEW, \"STATIC_ARRAY_CREATOR\"] ( genericTypeArgumentListSimplified )? qualifiedTypeIdentSimplified newArrayConstruction ) | arguments ( classBody )? -> ^( CLASS_CONSTRUCTOR_CALL[$NEW, \"STATIC_ARRAY_CREATOR\"] ( genericTypeArgumentListSimplified )? qualifiedTypeIdentSimplified arguments ( classBody )? ) )
					int alt146=2;
					int LA146_0 = input.LA(1);
					if ( (LA146_0==LBRACK) ) {
						alt146=1;
					}
					else if ( (LA146_0==LPAREN) ) {
						alt146=2;
					}
					else {
						if (state.backtracking>0) {state.failed=true; return retval;}
						NoViableAltException nvae =
							new NoViableAltException("", 146, 0, input);
						throw nvae;
					}
					switch (alt146) {
						case 1 :
							// Java.g:1046:17: newArrayConstruction
							{
							pushFollow(FOLLOW_newArrayConstruction_in_newExpression14459);
							newArrayConstruction512=newArrayConstruction();
							state._fsp--;
							if (state.failed) return retval;
							if ( state.backtracking==0 ) stream_newArrayConstruction.add(newArrayConstruction512.getTree());
							// AST REWRITE
							// elements: genericTypeArgumentListSimplified, newArrayConstruction, qualifiedTypeIdentSimplified
							// token labels: 
							// rule labels: retval
							// token list labels: 
							// rule list labels: 
							// wildcard labels: 
							if ( state.backtracking==0 ) {

							retval.tree = root_0;
							RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

							root_0 = (CommonTree)adaptor.nil();
							// 1047:17: -> ^( STATIC_ARRAY_CREATOR[$NEW, \"STATIC_ARRAY_CREATOR\"] ( genericTypeArgumentListSimplified )? qualifiedTypeIdentSimplified newArrayConstruction )
							{
								// Java.g:1047:21: ^( STATIC_ARRAY_CREATOR[$NEW, \"STATIC_ARRAY_CREATOR\"] ( genericTypeArgumentListSimplified )? qualifiedTypeIdentSimplified newArrayConstruction )
								{
								CommonTree root_1 = (CommonTree)adaptor.nil();
								root_1 = (CommonTree)adaptor.becomeRoot(
								(CommonTree)adaptor.create(STATIC_ARRAY_CREATOR, NEW507, "STATIC_ARRAY_CREATOR")
								, root_1);

								// Java.g:1047:74: ( genericTypeArgumentListSimplified )?
								if ( stream_genericTypeArgumentListSimplified.hasNext() ) {
									adaptor.addChild(root_1, stream_genericTypeArgumentListSimplified.nextTree());

								}
								stream_genericTypeArgumentListSimplified.reset();

								adaptor.addChild(root_1, stream_qualifiedTypeIdentSimplified.nextTree());

								adaptor.addChild(root_1, stream_newArrayConstruction.nextTree());

								adaptor.addChild(root_0, root_1);
								}

							}


							retval.tree = root_0;
							}

							}
							break;
						case 2 :
							// Java.g:1048:17: arguments ( classBody )?
							{
							pushFollow(FOLLOW_arguments_in_newExpression14524);
							arguments513=arguments();
							state._fsp--;
							if (state.failed) return retval;
							if ( state.backtracking==0 ) stream_arguments.add(arguments513.getTree());
							// Java.g:1048:27: ( classBody )?
							int alt145=2;
							int LA145_0 = input.LA(1);
							if ( (LA145_0==LCURLY) ) {
								alt145=1;
							}
							switch (alt145) {
								case 1 :
									// Java.g:1048:27: classBody
									{
									pushFollow(FOLLOW_classBody_in_newExpression14526);
									classBody514=classBody();
									state._fsp--;
									if (state.failed) return retval;
									if ( state.backtracking==0 ) stream_classBody.add(classBody514.getTree());
									}
									break;

							}

							// AST REWRITE
							// elements: classBody, qualifiedTypeIdentSimplified, genericTypeArgumentListSimplified, arguments
							// token labels: 
							// rule labels: retval
							// token list labels: 
							// rule list labels: 
							// wildcard labels: 
							if ( state.backtracking==0 ) {

							retval.tree = root_0;
							RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

							root_0 = (CommonTree)adaptor.nil();
							// 1049:17: -> ^( CLASS_CONSTRUCTOR_CALL[$NEW, \"STATIC_ARRAY_CREATOR\"] ( genericTypeArgumentListSimplified )? qualifiedTypeIdentSimplified arguments ( classBody )? )
							{
								// Java.g:1049:21: ^( CLASS_CONSTRUCTOR_CALL[$NEW, \"STATIC_ARRAY_CREATOR\"] ( genericTypeArgumentListSimplified )? qualifiedTypeIdentSimplified arguments ( classBody )? )
								{
								CommonTree root_1 = (CommonTree)adaptor.nil();
								root_1 = (CommonTree)adaptor.becomeRoot(
								(CommonTree)adaptor.create(CLASS_CONSTRUCTOR_CALL, NEW507, "STATIC_ARRAY_CREATOR")
								, root_1);

								// Java.g:1049:76: ( genericTypeArgumentListSimplified )?
								if ( stream_genericTypeArgumentListSimplified.hasNext() ) {
									adaptor.addChild(root_1, stream_genericTypeArgumentListSimplified.nextTree());

								}
								stream_genericTypeArgumentListSimplified.reset();

								adaptor.addChild(root_1, stream_qualifiedTypeIdentSimplified.nextTree());

								adaptor.addChild(root_1, stream_arguments.nextTree());

								// Java.g:1049:150: ( classBody )?
								if ( stream_classBody.hasNext() ) {
									adaptor.addChild(root_1, stream_classBody.nextTree());

								}
								stream_classBody.reset();

								adaptor.addChild(root_0, root_1);
								}

							}


							retval.tree = root_0;
							}

							}
							break;

					}

					}
					break;

			}

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 107, newExpression_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "newExpression"


	public static class innerNewExpression_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "innerNewExpression"
	// Java.g:1054:1: innerNewExpression : NEW ( genericTypeArgumentListSimplified )? IDENT arguments ( classBody )? -> ^( CLASS_CONSTRUCTOR_CALL[$NEW, \"STATIC_ARRAY_CREATOR\"] ( genericTypeArgumentListSimplified )? IDENT arguments ( classBody )? ) ;
	public final JavaParser.innerNewExpression_return innerNewExpression() throws RecognitionException {
		JavaParser.innerNewExpression_return retval = new JavaParser.innerNewExpression_return();
		retval.start = input.LT(1);
		int innerNewExpression_StartIndex = input.index();

		CommonTree root_0 = null;

		Token NEW515=null;
		Token IDENT517=null;
		ParserRuleReturnScope genericTypeArgumentListSimplified516 =null;
		ParserRuleReturnScope arguments518 =null;
		ParserRuleReturnScope classBody519 =null;

		CommonTree NEW515_tree=null;
		CommonTree IDENT517_tree=null;
		RewriteRuleTokenStream stream_NEW=new RewriteRuleTokenStream(adaptor,"token NEW");
		RewriteRuleTokenStream stream_IDENT=new RewriteRuleTokenStream(adaptor,"token IDENT");
		RewriteRuleSubtreeStream stream_arguments=new RewriteRuleSubtreeStream(adaptor,"rule arguments");
		RewriteRuleSubtreeStream stream_classBody=new RewriteRuleSubtreeStream(adaptor,"rule classBody");
		RewriteRuleSubtreeStream stream_genericTypeArgumentListSimplified=new RewriteRuleSubtreeStream(adaptor,"rule genericTypeArgumentListSimplified");

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 108) ) { return retval; }

			// Java.g:1055:5: ( NEW ( genericTypeArgumentListSimplified )? IDENT arguments ( classBody )? -> ^( CLASS_CONSTRUCTOR_CALL[$NEW, \"STATIC_ARRAY_CREATOR\"] ( genericTypeArgumentListSimplified )? IDENT arguments ( classBody )? ) )
			// Java.g:1055:9: NEW ( genericTypeArgumentListSimplified )? IDENT arguments ( classBody )?
			{
			NEW515=(Token)match(input,NEW,FOLLOW_NEW_in_innerNewExpression14625); if (state.failed) return retval; 
			if ( state.backtracking==0 ) stream_NEW.add(NEW515);

			// Java.g:1055:13: ( genericTypeArgumentListSimplified )?
			int alt148=2;
			int LA148_0 = input.LA(1);
			if ( (LA148_0==LESS_THAN) ) {
				alt148=1;
			}
			switch (alt148) {
				case 1 :
					// Java.g:1055:13: genericTypeArgumentListSimplified
					{
					pushFollow(FOLLOW_genericTypeArgumentListSimplified_in_innerNewExpression14627);
					genericTypeArgumentListSimplified516=genericTypeArgumentListSimplified();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_genericTypeArgumentListSimplified.add(genericTypeArgumentListSimplified516.getTree());
					}
					break;

			}

			IDENT517=(Token)match(input,IDENT,FOLLOW_IDENT_in_innerNewExpression14630); if (state.failed) return retval; 
			if ( state.backtracking==0 ) stream_IDENT.add(IDENT517);

			pushFollow(FOLLOW_arguments_in_innerNewExpression14632);
			arguments518=arguments();
			state._fsp--;
			if (state.failed) return retval;
			if ( state.backtracking==0 ) stream_arguments.add(arguments518.getTree());
			// Java.g:1055:64: ( classBody )?
			int alt149=2;
			int LA149_0 = input.LA(1);
			if ( (LA149_0==LCURLY) ) {
				alt149=1;
			}
			switch (alt149) {
				case 1 :
					// Java.g:1055:64: classBody
					{
					pushFollow(FOLLOW_classBody_in_innerNewExpression14634);
					classBody519=classBody();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_classBody.add(classBody519.getTree());
					}
					break;

			}

			// AST REWRITE
			// elements: genericTypeArgumentListSimplified, arguments, classBody, IDENT
			// token labels: 
			// rule labels: retval
			// token list labels: 
			// rule list labels: 
			// wildcard labels: 
			if ( state.backtracking==0 ) {

			retval.tree = root_0;
			RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

			root_0 = (CommonTree)adaptor.nil();
			// 1056:9: -> ^( CLASS_CONSTRUCTOR_CALL[$NEW, \"STATIC_ARRAY_CREATOR\"] ( genericTypeArgumentListSimplified )? IDENT arguments ( classBody )? )
			{
				// Java.g:1056:13: ^( CLASS_CONSTRUCTOR_CALL[$NEW, \"STATIC_ARRAY_CREATOR\"] ( genericTypeArgumentListSimplified )? IDENT arguments ( classBody )? )
				{
				CommonTree root_1 = (CommonTree)adaptor.nil();
				root_1 = (CommonTree)adaptor.becomeRoot(
				(CommonTree)adaptor.create(CLASS_CONSTRUCTOR_CALL, NEW515, "STATIC_ARRAY_CREATOR")
				, root_1);

				// Java.g:1056:68: ( genericTypeArgumentListSimplified )?
				if ( stream_genericTypeArgumentListSimplified.hasNext() ) {
					adaptor.addChild(root_1, stream_genericTypeArgumentListSimplified.nextTree());

				}
				stream_genericTypeArgumentListSimplified.reset();

				adaptor.addChild(root_1, 
				stream_IDENT.nextNode()
				);

				adaptor.addChild(root_1, stream_arguments.nextTree());

				// Java.g:1056:119: ( classBody )?
				if ( stream_classBody.hasNext() ) {
					adaptor.addChild(root_1, stream_classBody.nextTree());

				}
				stream_classBody.reset();

				adaptor.addChild(root_0, root_1);
				}

			}


			retval.tree = root_0;
			}

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 108, innerNewExpression_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "innerNewExpression"


	public static class newArrayConstruction_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "newArrayConstruction"
	// Java.g:1059:1: newArrayConstruction : ( arrayDeclaratorList arrayInitializer | LBRACK ! expression RBRACK ! ( LBRACK ! expression RBRACK !)* ( arrayDeclaratorList )? );
	public final JavaParser.newArrayConstruction_return newArrayConstruction() throws RecognitionException {
		JavaParser.newArrayConstruction_return retval = new JavaParser.newArrayConstruction_return();
		retval.start = input.LT(1);
		int newArrayConstruction_StartIndex = input.index();

		CommonTree root_0 = null;

		Token LBRACK522=null;
		Token RBRACK524=null;
		Token LBRACK525=null;
		Token RBRACK527=null;
		ParserRuleReturnScope arrayDeclaratorList520 =null;
		ParserRuleReturnScope arrayInitializer521 =null;
		ParserRuleReturnScope expression523 =null;
		ParserRuleReturnScope expression526 =null;
		ParserRuleReturnScope arrayDeclaratorList528 =null;

		CommonTree LBRACK522_tree=null;
		CommonTree RBRACK524_tree=null;
		CommonTree LBRACK525_tree=null;
		CommonTree RBRACK527_tree=null;

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 109) ) { return retval; }

			// Java.g:1060:5: ( arrayDeclaratorList arrayInitializer | LBRACK ! expression RBRACK ! ( LBRACK ! expression RBRACK !)* ( arrayDeclaratorList )? )
			int alt152=2;
			int LA152_0 = input.LA(1);
			if ( (LA152_0==LBRACK) ) {
				int LA152_1 = input.LA(2);
				if ( (LA152_1==RBRACK) ) {
					alt152=1;
				}
				else if ( (LA152_1==BOOLEAN||LA152_1==BYTE||(LA152_1 >= CHAR && LA152_1 <= CHARACTER_LITERAL)||(LA152_1 >= DEC && LA152_1 <= DECIMAL_LITERAL)||LA152_1==DOUBLE||LA152_1==FALSE||(LA152_1 >= FLOAT && LA152_1 <= FLOATING_POINT_LITERAL)||(LA152_1 >= HEX_LITERAL && LA152_1 <= IDENT)||LA152_1==INC||LA152_1==INT||LA152_1==LESS_THAN||LA152_1==LOGICAL_NOT||(LA152_1 >= LONG && LA152_1 <= LPAREN)||LA152_1==MINUS||(LA152_1 >= NEW && LA152_1 <= NOT)||LA152_1==NULL||LA152_1==OCTAL_LITERAL||LA152_1==PLUS||LA152_1==SHORT||(LA152_1 >= STRING_LITERAL && LA152_1 <= SUPER)||LA152_1==THIS||LA152_1==TRUE||LA152_1==VOID) ) {
					alt152=2;
				}
				else {
					if (state.backtracking>0) {state.failed=true; return retval;}
					int nvaeMark = input.mark();
					try {
						input.consume();
						NoViableAltException nvae =
							new NoViableAltException("", 152, 1, input);
						throw nvae;
					} finally {
						input.rewind(nvaeMark);
					}
				}
			}
			else {
				if (state.backtracking>0) {state.failed=true; return retval;}
				NoViableAltException nvae =
					new NoViableAltException("", 152, 0, input);
				throw nvae;
			}
			switch (alt152) {
				case 1 :
					// Java.g:1060:9: arrayDeclaratorList arrayInitializer
					{
					root_0 = (CommonTree)adaptor.nil();


					pushFollow(FOLLOW_arrayDeclaratorList_in_newArrayConstruction14680);
					arrayDeclaratorList520=arrayDeclaratorList();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) adaptor.addChild(root_0, arrayDeclaratorList520.getTree());

					pushFollow(FOLLOW_arrayInitializer_in_newArrayConstruction14682);
					arrayInitializer521=arrayInitializer();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) adaptor.addChild(root_0, arrayInitializer521.getTree());

					}
					break;
				case 2 :
					// Java.g:1061:9: LBRACK ! expression RBRACK ! ( LBRACK ! expression RBRACK !)* ( arrayDeclaratorList )?
					{
					root_0 = (CommonTree)adaptor.nil();


					LBRACK522=(Token)match(input,LBRACK,FOLLOW_LBRACK_in_newArrayConstruction14692); if (state.failed) return retval;
					pushFollow(FOLLOW_expression_in_newArrayConstruction14695);
					expression523=expression();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) adaptor.addChild(root_0, expression523.getTree());

					RBRACK524=(Token)match(input,RBRACK,FOLLOW_RBRACK_in_newArrayConstruction14697); if (state.failed) return retval;
					// Java.g:1061:36: ( LBRACK ! expression RBRACK !)*
					loop150:
					do {
						int alt150=2;
						int LA150_0 = input.LA(1);
						if ( (LA150_0==LBRACK) ) {
							int LA150_1 = input.LA(2);
							if ( (synpred234_Java()) ) {
								alt150=1;
							}

						}

						switch (alt150) {
						case 1 :
							// Java.g:1061:37: LBRACK ! expression RBRACK !
							{
							LBRACK525=(Token)match(input,LBRACK,FOLLOW_LBRACK_in_newArrayConstruction14701); if (state.failed) return retval;
							pushFollow(FOLLOW_expression_in_newArrayConstruction14704);
							expression526=expression();
							state._fsp--;
							if (state.failed) return retval;
							if ( state.backtracking==0 ) adaptor.addChild(root_0, expression526.getTree());

							RBRACK527=(Token)match(input,RBRACK,FOLLOW_RBRACK_in_newArrayConstruction14706); if (state.failed) return retval;
							}
							break;

						default :
							break loop150;
						}
					} while (true);

					// Java.g:1061:66: ( arrayDeclaratorList )?
					int alt151=2;
					int LA151_0 = input.LA(1);
					if ( (LA151_0==LBRACK) ) {
						int LA151_1 = input.LA(2);
						if ( (LA151_1==RBRACK) ) {
							alt151=1;
						}
					}
					switch (alt151) {
						case 1 :
							// Java.g:1061:66: arrayDeclaratorList
							{
							pushFollow(FOLLOW_arrayDeclaratorList_in_newArrayConstruction14711);
							arrayDeclaratorList528=arrayDeclaratorList();
							state._fsp--;
							if (state.failed) return retval;
							if ( state.backtracking==0 ) adaptor.addChild(root_0, arrayDeclaratorList528.getTree());

							}
							break;

					}

					}
					break;

			}
			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 109, newArrayConstruction_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "newArrayConstruction"


	public static class arguments_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "arguments"
	// Java.g:1064:1: arguments : LPAREN ( expressionList )? RPAREN -> ^( ARGUMENT_LIST[$LPAREN, \"ARGUMENT_LIST\"] ( expressionList )? ) ;
	public final JavaParser.arguments_return arguments() throws RecognitionException {
		JavaParser.arguments_return retval = new JavaParser.arguments_return();
		retval.start = input.LT(1);
		int arguments_StartIndex = input.index();

		CommonTree root_0 = null;

		Token LPAREN529=null;
		Token RPAREN531=null;
		ParserRuleReturnScope expressionList530 =null;

		CommonTree LPAREN529_tree=null;
		CommonTree RPAREN531_tree=null;
		RewriteRuleTokenStream stream_RPAREN=new RewriteRuleTokenStream(adaptor,"token RPAREN");
		RewriteRuleTokenStream stream_LPAREN=new RewriteRuleTokenStream(adaptor,"token LPAREN");
		RewriteRuleSubtreeStream stream_expressionList=new RewriteRuleSubtreeStream(adaptor,"rule expressionList");

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 110) ) { return retval; }

			// Java.g:1065:5: ( LPAREN ( expressionList )? RPAREN -> ^( ARGUMENT_LIST[$LPAREN, \"ARGUMENT_LIST\"] ( expressionList )? ) )
			// Java.g:1065:9: LPAREN ( expressionList )? RPAREN
			{
			LPAREN529=(Token)match(input,LPAREN,FOLLOW_LPAREN_in_arguments14731); if (state.failed) return retval; 
			if ( state.backtracking==0 ) stream_LPAREN.add(LPAREN529);

			// Java.g:1065:16: ( expressionList )?
			int alt153=2;
			int LA153_0 = input.LA(1);
			if ( (LA153_0==BOOLEAN||LA153_0==BYTE||(LA153_0 >= CHAR && LA153_0 <= CHARACTER_LITERAL)||(LA153_0 >= DEC && LA153_0 <= DECIMAL_LITERAL)||LA153_0==DOUBLE||LA153_0==FALSE||(LA153_0 >= FLOAT && LA153_0 <= FLOATING_POINT_LITERAL)||(LA153_0 >= HEX_LITERAL && LA153_0 <= IDENT)||LA153_0==INC||LA153_0==INT||LA153_0==LESS_THAN||LA153_0==LOGICAL_NOT||(LA153_0 >= LONG && LA153_0 <= LPAREN)||LA153_0==MINUS||(LA153_0 >= NEW && LA153_0 <= NOT)||LA153_0==NULL||LA153_0==OCTAL_LITERAL||LA153_0==PLUS||LA153_0==SHORT||(LA153_0 >= STRING_LITERAL && LA153_0 <= SUPER)||LA153_0==THIS||LA153_0==TRUE||LA153_0==VOID) ) {
				alt153=1;
			}
			switch (alt153) {
				case 1 :
					// Java.g:1065:16: expressionList
					{
					pushFollow(FOLLOW_expressionList_in_arguments14733);
					expressionList530=expressionList();
					state._fsp--;
					if (state.failed) return retval;
					if ( state.backtracking==0 ) stream_expressionList.add(expressionList530.getTree());
					}
					break;

			}

			RPAREN531=(Token)match(input,RPAREN,FOLLOW_RPAREN_in_arguments14736); if (state.failed) return retval; 
			if ( state.backtracking==0 ) stream_RPAREN.add(RPAREN531);

			// AST REWRITE
			// elements: expressionList
			// token labels: 
			// rule labels: retval
			// token list labels: 
			// rule list labels: 
			// wildcard labels: 
			if ( state.backtracking==0 ) {

			retval.tree = root_0;
			RewriteRuleSubtreeStream stream_retval=new RewriteRuleSubtreeStream(adaptor,"rule retval",retval!=null?retval.getTree():null);

			root_0 = (CommonTree)adaptor.nil();
			// 1066:9: -> ^( ARGUMENT_LIST[$LPAREN, \"ARGUMENT_LIST\"] ( expressionList )? )
			{
				// Java.g:1066:13: ^( ARGUMENT_LIST[$LPAREN, \"ARGUMENT_LIST\"] ( expressionList )? )
				{
				CommonTree root_1 = (CommonTree)adaptor.nil();
				root_1 = (CommonTree)adaptor.becomeRoot(
				(CommonTree)adaptor.create(ARGUMENT_LIST, LPAREN529, "ARGUMENT_LIST")
				, root_1);

				// Java.g:1066:55: ( expressionList )?
				if ( stream_expressionList.hasNext() ) {
					adaptor.addChild(root_1, stream_expressionList.nextTree());

				}
				stream_expressionList.reset();

				adaptor.addChild(root_0, root_1);
				}

			}


			retval.tree = root_0;
			}

			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 110, arguments_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "arguments"


	public static class literal_return extends ParserRuleReturnScope {
		CommonTree tree;
		public Object getTree() { return tree; }
	};


	// $ANTLR start "literal"
	// Java.g:1069:1: literal : ( HEX_LITERAL | OCTAL_LITERAL | DECIMAL_LITERAL | FLOATING_POINT_LITERAL | CHARACTER_LITERAL | STRING_LITERAL | TRUE | FALSE | NULL );
	public final JavaParser.literal_return literal() throws RecognitionException {
		JavaParser.literal_return retval = new JavaParser.literal_return();
		retval.start = input.LT(1);
		int literal_StartIndex = input.index();

		CommonTree root_0 = null;

		Token set532=null;

		CommonTree set532_tree=null;

		try {
			if ( state.backtracking>0 && alreadyParsedRule(input, 111) ) { return retval; }

			// Java.g:1070:5: ( HEX_LITERAL | OCTAL_LITERAL | DECIMAL_LITERAL | FLOATING_POINT_LITERAL | CHARACTER_LITERAL | STRING_LITERAL | TRUE | FALSE | NULL )
			// Java.g:
			{
			root_0 = (CommonTree)adaptor.nil();


			set532=(Token)input.LT(1);
			if ( input.LA(1)==CHARACTER_LITERAL||input.LA(1)==DECIMAL_LITERAL||input.LA(1)==FALSE||input.LA(1)==FLOATING_POINT_LITERAL||input.LA(1)==HEX_LITERAL||input.LA(1)==NULL||input.LA(1)==OCTAL_LITERAL||input.LA(1)==STRING_LITERAL||input.LA(1)==TRUE ) {
				input.consume();
				if ( state.backtracking==0 ) adaptor.addChild(root_0, 
				(CommonTree)adaptor.create(set532)
				);
				state.errorRecovery=false;
				state.failed=false;
			}
			else {
				if (state.backtracking>0) {state.failed=true; return retval;}
				MismatchedSetException mse = new MismatchedSetException(null,input);
				throw mse;
			}
			}

			retval.stop = input.LT(-1);

			if ( state.backtracking==0 ) {
			retval.tree = (CommonTree)adaptor.rulePostProcessing(root_0);
			adaptor.setTokenBoundaries(retval.tree, retval.start, retval.stop);
			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
			retval.tree = (CommonTree)adaptor.errorNode(input, retval.start, input.LT(-1), re);
		}
		finally {
			// do for sure before leaving
			if ( state.backtracking>0 ) { memoize(input, 111, literal_StartIndex); }

		}
		return retval;
	}
	// $ANTLR end "literal"

	// $ANTLR start synpred14_Java
	public final void synpred14_Java_fragment() throws RecognitionException {
		// Java.g:387:9: ( GREATER_THAN )
		// Java.g:387:9: GREATER_THAN
		{
		match(input,GREATER_THAN,FOLLOW_GREATER_THAN_in_synpred14_Java5119); if (state.failed) return ;

		}

	}
	// $ANTLR end synpred14_Java

	// $ANTLR start synpred15_Java
	public final void synpred15_Java_fragment() throws RecognitionException {
		// Java.g:388:9: ( SHIFT_RIGHT )
		// Java.g:388:9: SHIFT_RIGHT
		{
		match(input,SHIFT_RIGHT,FOLLOW_SHIFT_RIGHT_in_synpred15_Java5129); if (state.failed) return ;

		}

	}
	// $ANTLR end synpred15_Java

	// $ANTLR start synpred16_Java
	public final void synpred16_Java_fragment() throws RecognitionException {
		// Java.g:389:9: ( BIT_SHIFT_RIGHT )
		// Java.g:389:9: BIT_SHIFT_RIGHT
		{
		match(input,BIT_SHIFT_RIGHT,FOLLOW_BIT_SHIFT_RIGHT_in_synpred16_Java5139); if (state.failed) return ;

		}

	}
	// $ANTLR end synpred16_Java

	// $ANTLR start synpred17_Java
	public final void synpred17_Java_fragment() throws RecognitionException {
		// Java.g:394:15: ( bound )
		// Java.g:394:15: bound
		{
		pushFollow(FOLLOW_bound_in_synpred17_Java5169);
		bound();
		state._fsp--;
		if (state.failed) return ;

		}

	}
	// $ANTLR end synpred17_Java

	// $ANTLR start synpred32_Java
	public final void synpred32_Java_fragment() throws RecognitionException {
		// Java.g:451:9: ( STATIC block )
		// Java.g:451:9: STATIC block
		{
		match(input,STATIC,FOLLOW_STATIC_in_synpred32_Java5701); if (state.failed) return ;

		pushFollow(FOLLOW_block_in_synpred32_Java5703);
		block();
		state._fsp--;
		if (state.failed) return ;

		}

	}
	// $ANTLR end synpred32_Java

	// $ANTLR start synpred42_Java
	public final void synpred42_Java_fragment() throws RecognitionException {
		Token ident=null;


		// Java.g:453:13: ( ( genericTypeParameterList )? ( type IDENT formalParameterList ( arrayDeclaratorList )? ( throwsClause )? ( block | SEMI ) | VOID IDENT formalParameterList ( throwsClause )? ( block | SEMI ) |ident= IDENT formalParameterList ( throwsClause )? block ) )
		// Java.g:453:13: ( genericTypeParameterList )? ( type IDENT formalParameterList ( arrayDeclaratorList )? ( throwsClause )? ( block | SEMI ) | VOID IDENT formalParameterList ( throwsClause )? ( block | SEMI ) |ident= IDENT formalParameterList ( throwsClause )? block )
		{
		// Java.g:453:13: ( genericTypeParameterList )?
		int alt159=2;
		int LA159_0 = input.LA(1);
		if ( (LA159_0==LESS_THAN) ) {
			alt159=1;
		}
		switch (alt159) {
			case 1 :
				// Java.g:453:13: genericTypeParameterList
				{
				pushFollow(FOLLOW_genericTypeParameterList_in_synpred42_Java5740);
				genericTypeParameterList();
				state._fsp--;
				if (state.failed) return ;

				}
				break;

		}

		// Java.g:454:13: ( type IDENT formalParameterList ( arrayDeclaratorList )? ( throwsClause )? ( block | SEMI ) | VOID IDENT formalParameterList ( throwsClause )? ( block | SEMI ) |ident= IDENT formalParameterList ( throwsClause )? block )
		int alt166=3;
		switch ( input.LA(1) ) {
		case BOOLEAN:
		case BYTE:
		case CHAR:
		case DOUBLE:
		case FLOAT:
		case INT:
		case LONG:
		case SHORT:
			{
			alt166=1;
			}
			break;
		case IDENT:
			{
			int LA166_2 = input.LA(2);
			if ( (LA166_2==DOT||LA166_2==IDENT||LA166_2==LBRACK||LA166_2==LESS_THAN) ) {
				alt166=1;
			}
			else if ( (LA166_2==LPAREN) ) {
				alt166=3;
			}
			else {
				if (state.backtracking>0) {state.failed=true; return ;}
				int nvaeMark = input.mark();
				try {
					input.consume();
					NoViableAltException nvae =
						new NoViableAltException("", 166, 2, input);
					throw nvae;
				} finally {
					input.rewind(nvaeMark);
				}
			}
			}
			break;
		case VOID:
			{
			alt166=2;
			}
			break;
		default:
			if (state.backtracking>0) {state.failed=true; return ;}
			NoViableAltException nvae =
				new NoViableAltException("", 166, 0, input);
			throw nvae;
		}
		switch (alt166) {
			case 1 :
				// Java.g:454:17: type IDENT formalParameterList ( arrayDeclaratorList )? ( throwsClause )? ( block | SEMI )
				{
				pushFollow(FOLLOW_type_in_synpred42_Java5759);
				type();
				state._fsp--;
				if (state.failed) return ;

				match(input,IDENT,FOLLOW_IDENT_in_synpred42_Java5761); if (state.failed) return ;

				pushFollow(FOLLOW_formalParameterList_in_synpred42_Java5763);
				formalParameterList();
				state._fsp--;
				if (state.failed) return ;

				// Java.g:454:48: ( arrayDeclaratorList )?
				int alt160=2;
				int LA160_0 = input.LA(1);
				if ( (LA160_0==LBRACK) ) {
					alt160=1;
				}
				switch (alt160) {
					case 1 :
						// Java.g:454:48: arrayDeclaratorList
						{
						pushFollow(FOLLOW_arrayDeclaratorList_in_synpred42_Java5765);
						arrayDeclaratorList();
						state._fsp--;
						if (state.failed) return ;

						}
						break;

				}

				// Java.g:454:69: ( throwsClause )?
				int alt161=2;
				int LA161_0 = input.LA(1);
				if ( (LA161_0==THROWS) ) {
					alt161=1;
				}
				switch (alt161) {
					case 1 :
						// Java.g:454:69: throwsClause
						{
						pushFollow(FOLLOW_throwsClause_in_synpred42_Java5768);
						throwsClause();
						state._fsp--;
						if (state.failed) return ;

						}
						break;

				}

				// Java.g:454:83: ( block | SEMI )
				int alt162=2;
				int LA162_0 = input.LA(1);
				if ( (LA162_0==LCURLY) ) {
					alt162=1;
				}
				else if ( (LA162_0==SEMI) ) {
					alt162=2;
				}
				else {
					if (state.backtracking>0) {state.failed=true; return ;}
					NoViableAltException nvae =
						new NoViableAltException("", 162, 0, input);
					throw nvae;
				}
				switch (alt162) {
					case 1 :
						// Java.g:454:84: block
						{
						pushFollow(FOLLOW_block_in_synpred42_Java5772);
						block();
						state._fsp--;
						if (state.failed) return ;

						}
						break;
					case 2 :
						// Java.g:454:92: SEMI
						{
						match(input,SEMI,FOLLOW_SEMI_in_synpred42_Java5776); if (state.failed) return ;

						}
						break;

				}

				}
				break;
			case 2 :
				// Java.g:456:17: VOID IDENT formalParameterList ( throwsClause )? ( block | SEMI )
				{
				match(input,VOID,FOLLOW_VOID_in_synpred42_Java5838); if (state.failed) return ;

				match(input,IDENT,FOLLOW_IDENT_in_synpred42_Java5840); if (state.failed) return ;

				pushFollow(FOLLOW_formalParameterList_in_synpred42_Java5842);
				formalParameterList();
				state._fsp--;
				if (state.failed) return ;

				// Java.g:456:48: ( throwsClause )?
				int alt163=2;
				int LA163_0 = input.LA(1);
				if ( (LA163_0==THROWS) ) {
					alt163=1;
				}
				switch (alt163) {
					case 1 :
						// Java.g:456:48: throwsClause
						{
						pushFollow(FOLLOW_throwsClause_in_synpred42_Java5844);
						throwsClause();
						state._fsp--;
						if (state.failed) return ;

						}
						break;

				}

				// Java.g:456:62: ( block | SEMI )
				int alt164=2;
				int LA164_0 = input.LA(1);
				if ( (LA164_0==LCURLY) ) {
					alt164=1;
				}
				else if ( (LA164_0==SEMI) ) {
					alt164=2;
				}
				else {
					if (state.backtracking>0) {state.failed=true; return ;}
					NoViableAltException nvae =
						new NoViableAltException("", 164, 0, input);
					throw nvae;
				}
				switch (alt164) {
					case 1 :
						// Java.g:456:63: block
						{
						pushFollow(FOLLOW_block_in_synpred42_Java5848);
						block();
						state._fsp--;
						if (state.failed) return ;

						}
						break;
					case 2 :
						// Java.g:456:71: SEMI
						{
						match(input,SEMI,FOLLOW_SEMI_in_synpred42_Java5852); if (state.failed) return ;

						}
						break;

				}

				}
				break;
			case 3 :
				// Java.g:458:17: ident= IDENT formalParameterList ( throwsClause )? block
				{
				ident=(Token)match(input,IDENT,FOLLOW_IDENT_in_synpred42_Java5911); if (state.failed) return ;

				pushFollow(FOLLOW_formalParameterList_in_synpred42_Java5913);
				formalParameterList();
				state._fsp--;
				if (state.failed) return ;

				// Java.g:458:49: ( throwsClause )?
				int alt165=2;
				int LA165_0 = input.LA(1);
				if ( (LA165_0==THROWS) ) {
					alt165=1;
				}
				switch (alt165) {
					case 1 :
						// Java.g:458:49: throwsClause
						{
						pushFollow(FOLLOW_throwsClause_in_synpred42_Java5915);
						throwsClause();
						state._fsp--;
						if (state.failed) return ;

						}
						break;

				}

				pushFollow(FOLLOW_block_in_synpred42_Java5918);
				block();
				state._fsp--;
				if (state.failed) return ;

				}
				break;

		}

		}

	}
	// $ANTLR end synpred42_Java

	// $ANTLR start synpred43_Java
	public final void synpred43_Java_fragment() throws RecognitionException {
		Token ident=null;


		// Java.g:452:9: ( modifierList ( ( genericTypeParameterList )? ( type IDENT formalParameterList ( arrayDeclaratorList )? ( throwsClause )? ( block | SEMI ) | VOID IDENT formalParameterList ( throwsClause )? ( block | SEMI ) |ident= IDENT formalParameterList ( throwsClause )? block ) | type classFieldDeclaratorList SEMI ) )
		// Java.g:452:9: modifierList ( ( genericTypeParameterList )? ( type IDENT formalParameterList ( arrayDeclaratorList )? ( throwsClause )? ( block | SEMI ) | VOID IDENT formalParameterList ( throwsClause )? ( block | SEMI ) |ident= IDENT formalParameterList ( throwsClause )? block ) | type classFieldDeclaratorList SEMI )
		{
		pushFollow(FOLLOW_modifierList_in_synpred43_Java5726);
		modifierList();
		state._fsp--;
		if (state.failed) return ;

		// Java.g:453:9: ( ( genericTypeParameterList )? ( type IDENT formalParameterList ( arrayDeclaratorList )? ( throwsClause )? ( block | SEMI ) | VOID IDENT formalParameterList ( throwsClause )? ( block | SEMI ) |ident= IDENT formalParameterList ( throwsClause )? block ) | type classFieldDeclaratorList SEMI )
		int alt175=2;
		switch ( input.LA(1) ) {
		case LESS_THAN:
		case VOID:
			{
			alt175=1;
			}
			break;
		case BOOLEAN:
		case BYTE:
		case CHAR:
		case DOUBLE:
		case FLOAT:
		case INT:
		case LONG:
		case SHORT:
			{
			int LA175_2 = input.LA(2);
			if ( (synpred42_Java()) ) {
				alt175=1;
			}
			else if ( (true) ) {
				alt175=2;
			}
			else {
				if (state.backtracking>0) {state.failed=true; return ;}
				int nvaeMark = input.mark();
				try {
					input.consume();
					NoViableAltException nvae =
						new NoViableAltException("", 175, 2, input);
					throw nvae;
				} finally {
					input.rewind(nvaeMark);
				}
			}
			}
			break;
		case IDENT:
			{
			int LA175_3 = input.LA(2);
			if ( (synpred42_Java()) ) {
				alt175=1;
			}
			else if ( (true) ) {
				alt175=2;
			}
			else {
				if (state.backtracking>0) {state.failed=true; return ;}
				int nvaeMark = input.mark();
				try {
					input.consume();
					NoViableAltException nvae =
						new NoViableAltException("", 175, 3, input);
					throw nvae;
				} finally {
					input.rewind(nvaeMark);
				}
			}
			}
			break;
		default:
			if (state.backtracking>0) {state.failed=true; return ;}
			NoViableAltException nvae =
				new NoViableAltException("", 175, 0, input);
			throw nvae;
		}
		switch (alt175) {
			case 1 :
				// Java.g:453:13: ( genericTypeParameterList )? ( type IDENT formalParameterList ( arrayDeclaratorList )? ( throwsClause )? ( block | SEMI ) | VOID IDENT formalParameterList ( throwsClause )? ( block | SEMI ) |ident= IDENT formalParameterList ( throwsClause )? block )
				{
				// Java.g:453:13: ( genericTypeParameterList )?
				int alt167=2;
				int LA167_0 = input.LA(1);
				if ( (LA167_0==LESS_THAN) ) {
					alt167=1;
				}
				switch (alt167) {
					case 1 :
						// Java.g:453:13: genericTypeParameterList
						{
						pushFollow(FOLLOW_genericTypeParameterList_in_synpred43_Java5740);
						genericTypeParameterList();
						state._fsp--;
						if (state.failed) return ;

						}
						break;

				}

				// Java.g:454:13: ( type IDENT formalParameterList ( arrayDeclaratorList )? ( throwsClause )? ( block | SEMI ) | VOID IDENT formalParameterList ( throwsClause )? ( block | SEMI ) |ident= IDENT formalParameterList ( throwsClause )? block )
				int alt174=3;
				switch ( input.LA(1) ) {
				case BOOLEAN:
				case BYTE:
				case CHAR:
				case DOUBLE:
				case FLOAT:
				case INT:
				case LONG:
				case SHORT:
					{
					alt174=1;
					}
					break;
				case IDENT:
					{
					int LA174_2 = input.LA(2);
					if ( (LA174_2==DOT||LA174_2==IDENT||LA174_2==LBRACK||LA174_2==LESS_THAN) ) {
						alt174=1;
					}
					else if ( (LA174_2==LPAREN) ) {
						alt174=3;
					}
					else {
						if (state.backtracking>0) {state.failed=true; return ;}
						int nvaeMark = input.mark();
						try {
							input.consume();
							NoViableAltException nvae =
								new NoViableAltException("", 174, 2, input);
							throw nvae;
						} finally {
							input.rewind(nvaeMark);
						}
					}
					}
					break;
				case VOID:
					{
					alt174=2;
					}
					break;
				default:
					if (state.backtracking>0) {state.failed=true; return ;}
					NoViableAltException nvae =
						new NoViableAltException("", 174, 0, input);
					throw nvae;
				}
				switch (alt174) {
					case 1 :
						// Java.g:454:17: type IDENT formalParameterList ( arrayDeclaratorList )? ( throwsClause )? ( block | SEMI )
						{
						pushFollow(FOLLOW_type_in_synpred43_Java5759);
						type();
						state._fsp--;
						if (state.failed) return ;

						match(input,IDENT,FOLLOW_IDENT_in_synpred43_Java5761); if (state.failed) return ;

						pushFollow(FOLLOW_formalParameterList_in_synpred43_Java5763);
						formalParameterList();
						state._fsp--;
						if (state.failed) return ;

						// Java.g:454:48: ( arrayDeclaratorList )?
						int alt168=2;
						int LA168_0 = input.LA(1);
						if ( (LA168_0==LBRACK) ) {
							alt168=1;
						}
						switch (alt168) {
							case 1 :
								// Java.g:454:48: arrayDeclaratorList
								{
								pushFollow(FOLLOW_arrayDeclaratorList_in_synpred43_Java5765);
								arrayDeclaratorList();
								state._fsp--;
								if (state.failed) return ;

								}
								break;

						}

						// Java.g:454:69: ( throwsClause )?
						int alt169=2;
						int LA169_0 = input.LA(1);
						if ( (LA169_0==THROWS) ) {
							alt169=1;
						}
						switch (alt169) {
							case 1 :
								// Java.g:454:69: throwsClause
								{
								pushFollow(FOLLOW_throwsClause_in_synpred43_Java5768);
								throwsClause();
								state._fsp--;
								if (state.failed) return ;

								}
								break;

						}

						// Java.g:454:83: ( block | SEMI )
						int alt170=2;
						int LA170_0 = input.LA(1);
						if ( (LA170_0==LCURLY) ) {
							alt170=1;
						}
						else if ( (LA170_0==SEMI) ) {
							alt170=2;
						}
						else {
							if (state.backtracking>0) {state.failed=true; return ;}
							NoViableAltException nvae =
								new NoViableAltException("", 170, 0, input);
							throw nvae;
						}
						switch (alt170) {
							case 1 :
								// Java.g:454:84: block
								{
								pushFollow(FOLLOW_block_in_synpred43_Java5772);
								block();
								state._fsp--;
								if (state.failed) return ;

								}
								break;
							case 2 :
								// Java.g:454:92: SEMI
								{
								match(input,SEMI,FOLLOW_SEMI_in_synpred43_Java5776); if (state.failed) return ;

								}
								break;

						}

						}
						break;
					case 2 :
						// Java.g:456:17: VOID IDENT formalParameterList ( throwsClause )? ( block | SEMI )
						{
						match(input,VOID,FOLLOW_VOID_in_synpred43_Java5838); if (state.failed) return ;

						match(input,IDENT,FOLLOW_IDENT_in_synpred43_Java5840); if (state.failed) return ;

						pushFollow(FOLLOW_formalParameterList_in_synpred43_Java5842);
						formalParameterList();
						state._fsp--;
						if (state.failed) return ;

						// Java.g:456:48: ( throwsClause )?
						int alt171=2;
						int LA171_0 = input.LA(1);
						if ( (LA171_0==THROWS) ) {
							alt171=1;
						}
						switch (alt171) {
							case 1 :
								// Java.g:456:48: throwsClause
								{
								pushFollow(FOLLOW_throwsClause_in_synpred43_Java5844);
								throwsClause();
								state._fsp--;
								if (state.failed) return ;

								}
								break;

						}

						// Java.g:456:62: ( block | SEMI )
						int alt172=2;
						int LA172_0 = input.LA(1);
						if ( (LA172_0==LCURLY) ) {
							alt172=1;
						}
						else if ( (LA172_0==SEMI) ) {
							alt172=2;
						}
						else {
							if (state.backtracking>0) {state.failed=true; return ;}
							NoViableAltException nvae =
								new NoViableAltException("", 172, 0, input);
							throw nvae;
						}
						switch (alt172) {
							case 1 :
								// Java.g:456:63: block
								{
								pushFollow(FOLLOW_block_in_synpred43_Java5848);
								block();
								state._fsp--;
								if (state.failed) return ;

								}
								break;
							case 2 :
								// Java.g:456:71: SEMI
								{
								match(input,SEMI,FOLLOW_SEMI_in_synpred43_Java5852); if (state.failed) return ;

								}
								break;

						}

						}
						break;
					case 3 :
						// Java.g:458:17: ident= IDENT formalParameterList ( throwsClause )? block
						{
						ident=(Token)match(input,IDENT,FOLLOW_IDENT_in_synpred43_Java5911); if (state.failed) return ;

						pushFollow(FOLLOW_formalParameterList_in_synpred43_Java5913);
						formalParameterList();
						state._fsp--;
						if (state.failed) return ;

						// Java.g:458:49: ( throwsClause )?
						int alt173=2;
						int LA173_0 = input.LA(1);
						if ( (LA173_0==THROWS) ) {
							alt173=1;
						}
						switch (alt173) {
							case 1 :
								// Java.g:458:49: throwsClause
								{
								pushFollow(FOLLOW_throwsClause_in_synpred43_Java5915);
								throwsClause();
								state._fsp--;
								if (state.failed) return ;

								}
								break;

						}

						pushFollow(FOLLOW_block_in_synpred43_Java5918);
						block();
						state._fsp--;
						if (state.failed) return ;

						}
						break;

				}

				}
				break;
			case 2 :
				// Java.g:461:13: type classFieldDeclaratorList SEMI
				{
				pushFollow(FOLLOW_type_in_synpred43_Java5982);
				type();
				state._fsp--;
				if (state.failed) return ;

				pushFollow(FOLLOW_classFieldDeclaratorList_in_synpred43_Java5984);
				classFieldDeclaratorList();
				state._fsp--;
				if (state.failed) return ;

				match(input,SEMI,FOLLOW_SEMI_in_synpred43_Java5986); if (state.failed) return ;

				}
				break;

		}

		}

	}
	// $ANTLR end synpred43_Java

	// $ANTLR start synpred44_Java
	public final void synpred44_Java_fragment() throws RecognitionException {
		// Java.g:464:9: ( typeDeclaration )
		// Java.g:464:9: typeDeclaration
		{
		pushFollow(FOLLOW_typeDeclaration_in_synpred44_Java6031);
		typeDeclaration();
		state._fsp--;
		if (state.failed) return ;

		}

	}
	// $ANTLR end synpred44_Java

	// $ANTLR start synpred50_Java
	public final void synpred50_Java_fragment() throws RecognitionException {
		// Java.g:470:13: ( ( genericTypeParameterList )? ( type IDENT formalParameterList ( arrayDeclaratorList )? ( throwsClause )? SEMI | VOID IDENT formalParameterList ( throwsClause )? SEMI ) )
		// Java.g:470:13: ( genericTypeParameterList )? ( type IDENT formalParameterList ( arrayDeclaratorList )? ( throwsClause )? SEMI | VOID IDENT formalParameterList ( throwsClause )? SEMI )
		{
		// Java.g:470:13: ( genericTypeParameterList )?
		int alt178=2;
		int LA178_0 = input.LA(1);
		if ( (LA178_0==LESS_THAN) ) {
			alt178=1;
		}
		switch (alt178) {
			case 1 :
				// Java.g:470:13: genericTypeParameterList
				{
				pushFollow(FOLLOW_genericTypeParameterList_in_synpred50_Java6087);
				genericTypeParameterList();
				state._fsp--;
				if (state.failed) return ;

				}
				break;

		}

		// Java.g:471:13: ( type IDENT formalParameterList ( arrayDeclaratorList )? ( throwsClause )? SEMI | VOID IDENT formalParameterList ( throwsClause )? SEMI )
		int alt182=2;
		int LA182_0 = input.LA(1);
		if ( (LA182_0==BOOLEAN||LA182_0==BYTE||LA182_0==CHAR||LA182_0==DOUBLE||LA182_0==FLOAT||LA182_0==IDENT||LA182_0==INT||LA182_0==LONG||LA182_0==SHORT) ) {
			alt182=1;
		}
		else if ( (LA182_0==VOID) ) {
			alt182=2;
		}
		else {
			if (state.backtracking>0) {state.failed=true; return ;}
			NoViableAltException nvae =
				new NoViableAltException("", 182, 0, input);
			throw nvae;
		}
		switch (alt182) {
			case 1 :
				// Java.g:471:17: type IDENT formalParameterList ( arrayDeclaratorList )? ( throwsClause )? SEMI
				{
				pushFollow(FOLLOW_type_in_synpred50_Java6106);
				type();
				state._fsp--;
				if (state.failed) return ;

				match(input,IDENT,FOLLOW_IDENT_in_synpred50_Java6108); if (state.failed) return ;

				pushFollow(FOLLOW_formalParameterList_in_synpred50_Java6110);
				formalParameterList();
				state._fsp--;
				if (state.failed) return ;

				// Java.g:471:48: ( arrayDeclaratorList )?
				int alt179=2;
				int LA179_0 = input.LA(1);
				if ( (LA179_0==LBRACK) ) {
					alt179=1;
				}
				switch (alt179) {
					case 1 :
						// Java.g:471:48: arrayDeclaratorList
						{
						pushFollow(FOLLOW_arrayDeclaratorList_in_synpred50_Java6112);
						arrayDeclaratorList();
						state._fsp--;
						if (state.failed) return ;

						}
						break;

				}

				// Java.g:471:69: ( throwsClause )?
				int alt180=2;
				int LA180_0 = input.LA(1);
				if ( (LA180_0==THROWS) ) {
					alt180=1;
				}
				switch (alt180) {
					case 1 :
						// Java.g:471:69: throwsClause
						{
						pushFollow(FOLLOW_throwsClause_in_synpred50_Java6115);
						throwsClause();
						state._fsp--;
						if (state.failed) return ;

						}
						break;

				}

				match(input,SEMI,FOLLOW_SEMI_in_synpred50_Java6118); if (state.failed) return ;

				}
				break;
			case 2 :
				// Java.g:473:17: VOID IDENT formalParameterList ( throwsClause )? SEMI
				{
				match(input,VOID,FOLLOW_VOID_in_synpred50_Java6176); if (state.failed) return ;

				match(input,IDENT,FOLLOW_IDENT_in_synpred50_Java6178); if (state.failed) return ;

				pushFollow(FOLLOW_formalParameterList_in_synpred50_Java6180);
				formalParameterList();
				state._fsp--;
				if (state.failed) return ;

				// Java.g:473:48: ( throwsClause )?
				int alt181=2;
				int LA181_0 = input.LA(1);
				if ( (LA181_0==THROWS) ) {
					alt181=1;
				}
				switch (alt181) {
					case 1 :
						// Java.g:473:48: throwsClause
						{
						pushFollow(FOLLOW_throwsClause_in_synpred50_Java6182);
						throwsClause();
						state._fsp--;
						if (state.failed) return ;

						}
						break;

				}

				match(input,SEMI,FOLLOW_SEMI_in_synpred50_Java6185); if (state.failed) return ;

				}
				break;

		}

		}

	}
	// $ANTLR end synpred50_Java

	// $ANTLR start synpred51_Java
	public final void synpred51_Java_fragment() throws RecognitionException {
		// Java.g:469:9: ( modifierList ( ( genericTypeParameterList )? ( type IDENT formalParameterList ( arrayDeclaratorList )? ( throwsClause )? SEMI | VOID IDENT formalParameterList ( throwsClause )? SEMI ) | type interfaceFieldDeclaratorList SEMI ) )
		// Java.g:469:9: modifierList ( ( genericTypeParameterList )? ( type IDENT formalParameterList ( arrayDeclaratorList )? ( throwsClause )? SEMI | VOID IDENT formalParameterList ( throwsClause )? SEMI ) | type interfaceFieldDeclaratorList SEMI )
		{
		pushFollow(FOLLOW_modifierList_in_synpred51_Java6073);
		modifierList();
		state._fsp--;
		if (state.failed) return ;

		// Java.g:470:9: ( ( genericTypeParameterList )? ( type IDENT formalParameterList ( arrayDeclaratorList )? ( throwsClause )? SEMI | VOID IDENT formalParameterList ( throwsClause )? SEMI ) | type interfaceFieldDeclaratorList SEMI )
		int alt188=2;
		switch ( input.LA(1) ) {
		case LESS_THAN:
		case VOID:
			{
			alt188=1;
			}
			break;
		case BOOLEAN:
		case BYTE:
		case CHAR:
		case DOUBLE:
		case FLOAT:
		case INT:
		case LONG:
		case SHORT:
			{
			int LA188_2 = input.LA(2);
			if ( (synpred50_Java()) ) {
				alt188=1;
			}
			else if ( (true) ) {
				alt188=2;
			}
			else {
				if (state.backtracking>0) {state.failed=true; return ;}
				int nvaeMark = input.mark();
				try {
					input.consume();
					NoViableAltException nvae =
						new NoViableAltException("", 188, 2, input);
					throw nvae;
				} finally {
					input.rewind(nvaeMark);
				}
			}
			}
			break;
		case IDENT:
			{
			int LA188_3 = input.LA(2);
			if ( (synpred50_Java()) ) {
				alt188=1;
			}
			else if ( (true) ) {
				alt188=2;
			}
			else {
				if (state.backtracking>0) {state.failed=true; return ;}
				int nvaeMark = input.mark();
				try {
					input.consume();
					NoViableAltException nvae =
						new NoViableAltException("", 188, 3, input);
					throw nvae;
				} finally {
					input.rewind(nvaeMark);
				}
			}
			}
			break;
		default:
			if (state.backtracking>0) {state.failed=true; return ;}
			NoViableAltException nvae =
				new NoViableAltException("", 188, 0, input);
			throw nvae;
		}
		switch (alt188) {
			case 1 :
				// Java.g:470:13: ( genericTypeParameterList )? ( type IDENT formalParameterList ( arrayDeclaratorList )? ( throwsClause )? SEMI | VOID IDENT formalParameterList ( throwsClause )? SEMI )
				{
				// Java.g:470:13: ( genericTypeParameterList )?
				int alt183=2;
				int LA183_0 = input.LA(1);
				if ( (LA183_0==LESS_THAN) ) {
					alt183=1;
				}
				switch (alt183) {
					case 1 :
						// Java.g:470:13: genericTypeParameterList
						{
						pushFollow(FOLLOW_genericTypeParameterList_in_synpred51_Java6087);
						genericTypeParameterList();
						state._fsp--;
						if (state.failed) return ;

						}
						break;

				}

				// Java.g:471:13: ( type IDENT formalParameterList ( arrayDeclaratorList )? ( throwsClause )? SEMI | VOID IDENT formalParameterList ( throwsClause )? SEMI )
				int alt187=2;
				int LA187_0 = input.LA(1);
				if ( (LA187_0==BOOLEAN||LA187_0==BYTE||LA187_0==CHAR||LA187_0==DOUBLE||LA187_0==FLOAT||LA187_0==IDENT||LA187_0==INT||LA187_0==LONG||LA187_0==SHORT) ) {
					alt187=1;
				}
				else if ( (LA187_0==VOID) ) {
					alt187=2;
				}
				else {
					if (state.backtracking>0) {state.failed=true; return ;}
					NoViableAltException nvae =
						new NoViableAltException("", 187, 0, input);
					throw nvae;
				}
				switch (alt187) {
					case 1 :
						// Java.g:471:17: type IDENT formalParameterList ( arrayDeclaratorList )? ( throwsClause )? SEMI
						{
						pushFollow(FOLLOW_type_in_synpred51_Java6106);
						type();
						state._fsp--;
						if (state.failed) return ;

						match(input,IDENT,FOLLOW_IDENT_in_synpred51_Java6108); if (state.failed) return ;

						pushFollow(FOLLOW_formalParameterList_in_synpred51_Java6110);
						formalParameterList();
						state._fsp--;
						if (state.failed) return ;

						// Java.g:471:48: ( arrayDeclaratorList )?
						int alt184=2;
						int LA184_0 = input.LA(1);
						if ( (LA184_0==LBRACK) ) {
							alt184=1;
						}
						switch (alt184) {
							case 1 :
								// Java.g:471:48: arrayDeclaratorList
								{
								pushFollow(FOLLOW_arrayDeclaratorList_in_synpred51_Java6112);
								arrayDeclaratorList();
								state._fsp--;
								if (state.failed) return ;

								}
								break;

						}

						// Java.g:471:69: ( throwsClause )?
						int alt185=2;
						int LA185_0 = input.LA(1);
						if ( (LA185_0==THROWS) ) {
							alt185=1;
						}
						switch (alt185) {
							case 1 :
								// Java.g:471:69: throwsClause
								{
								pushFollow(FOLLOW_throwsClause_in_synpred51_Java6115);
								throwsClause();
								state._fsp--;
								if (state.failed) return ;

								}
								break;

						}

						match(input,SEMI,FOLLOW_SEMI_in_synpred51_Java6118); if (state.failed) return ;

						}
						break;
					case 2 :
						// Java.g:473:17: VOID IDENT formalParameterList ( throwsClause )? SEMI
						{
						match(input,VOID,FOLLOW_VOID_in_synpred51_Java6176); if (state.failed) return ;

						match(input,IDENT,FOLLOW_IDENT_in_synpred51_Java6178); if (state.failed) return ;

						pushFollow(FOLLOW_formalParameterList_in_synpred51_Java6180);
						formalParameterList();
						state._fsp--;
						if (state.failed) return ;

						// Java.g:473:48: ( throwsClause )?
						int alt186=2;
						int LA186_0 = input.LA(1);
						if ( (LA186_0==THROWS) ) {
							alt186=1;
						}
						switch (alt186) {
							case 1 :
								// Java.g:473:48: throwsClause
								{
								pushFollow(FOLLOW_throwsClause_in_synpred51_Java6182);
								throwsClause();
								state._fsp--;
								if (state.failed) return ;

								}
								break;

						}

						match(input,SEMI,FOLLOW_SEMI_in_synpred51_Java6185); if (state.failed) return ;

						}
						break;

				}

				}
				break;
			case 2 :
				// Java.g:476:13: type interfaceFieldDeclaratorList SEMI
				{
				pushFollow(FOLLOW_type_in_synpred51_Java6248);
				type();
				state._fsp--;
				if (state.failed) return ;

				pushFollow(FOLLOW_interfaceFieldDeclaratorList_in_synpred51_Java6250);
				interfaceFieldDeclaratorList();
				state._fsp--;
				if (state.failed) return ;

				match(input,SEMI,FOLLOW_SEMI_in_synpred51_Java6252); if (state.failed) return ;

				}
				break;

		}

		}

	}
	// $ANTLR end synpred51_Java

	// $ANTLR start synpred52_Java
	public final void synpred52_Java_fragment() throws RecognitionException {
		// Java.g:479:9: ( typeDeclaration )
		// Java.g:479:9: typeDeclaration
		{
		pushFollow(FOLLOW_typeDeclaration_in_synpred52_Java6297);
		typeDeclaration();
		state._fsp--;
		if (state.failed) return ;

		}

	}
	// $ANTLR end synpred52_Java

	// $ANTLR start synpred58_Java
	public final void synpred58_Java_fragment() throws RecognitionException {
		// Java.g:518:9: ( arrayDeclarator )
		// Java.g:518:9: arrayDeclarator
		{
		pushFollow(FOLLOW_arrayDeclarator_in_synpred58_Java6599);
		arrayDeclarator();
		state._fsp--;
		if (state.failed) return ;

		}

	}
	// $ANTLR end synpred58_Java

	// $ANTLR start synpred76_Java
	public final void synpred76_Java_fragment() throws RecognitionException {
		// Java.g:567:23: ( arrayDeclaratorList )
		// Java.g:567:23: arrayDeclaratorList
		{
		pushFollow(FOLLOW_arrayDeclaratorList_in_synpred76_Java7000);
		arrayDeclaratorList();
		state._fsp--;
		if (state.failed) return ;

		}

	}
	// $ANTLR end synpred76_Java

	// $ANTLR start synpred77_Java
	public final void synpred77_Java_fragment() throws RecognitionException {
		// Java.g:572:28: ( arrayDeclaratorList )
		// Java.g:572:28: arrayDeclaratorList
		{
		pushFollow(FOLLOW_arrayDeclaratorList_in_synpred77_Java7049);
		arrayDeclaratorList();
		state._fsp--;
		if (state.failed) return ;

		}

	}
	// $ANTLR end synpred77_Java

	// $ANTLR start synpred79_Java
	public final void synpred79_Java_fragment() throws RecognitionException {
		// Java.g:582:20: ( DOT typeIdent )
		// Java.g:582:20: DOT typeIdent
		{
		match(input,DOT,FOLLOW_DOT_in_synpred79_Java7134); if (state.failed) return ;

		pushFollow(FOLLOW_typeIdent_in_synpred79_Java7136);
		typeIdent();
		state._fsp--;
		if (state.failed) return ;

		}

	}
	// $ANTLR end synpred79_Java

	// $ANTLR start synpred90_Java
	public final void synpred90_Java_fragment() throws RecognitionException {
		// Java.g:611:40: ( COMMA genericTypeArgument )
		// Java.g:611:40: COMMA genericTypeArgument
		{
		match(input,COMMA,FOLLOW_COMMA_in_synpred90_Java7361); if (state.failed) return ;

		pushFollow(FOLLOW_genericTypeArgument_in_synpred90_Java7363);
		genericTypeArgument();
		state._fsp--;
		if (state.failed) return ;

		}

	}
	// $ANTLR end synpred90_Java

	// $ANTLR start synpred92_Java
	public final void synpred92_Java_fragment() throws RecognitionException {
		// Java.g:617:18: ( genericWildcardBoundType )
		// Java.g:617:18: genericWildcardBoundType
		{
		pushFollow(FOLLOW_genericWildcardBoundType_in_synpred92_Java7417);
		genericWildcardBoundType();
		state._fsp--;
		if (state.failed) return ;

		}

	}
	// $ANTLR end synpred92_Java

	// $ANTLR start synpred97_Java
	public final void synpred97_Java_fragment() throws RecognitionException {
		// Java.g:642:42: ( COMMA formalParameterStandardDecl )
		// Java.g:642:42: COMMA formalParameterStandardDecl
		{
		match(input,COMMA,FOLLOW_COMMA_in_synpred97_Java7635); if (state.failed) return ;

		pushFollow(FOLLOW_formalParameterStandardDecl_in_synpred97_Java7637);
		formalParameterStandardDecl();
		state._fsp--;
		if (state.failed) return ;

		}

	}
	// $ANTLR end synpred97_Java

	// $ANTLR start synpred99_Java
	public final void synpred99_Java_fragment() throws RecognitionException {
		// Java.g:642:13: ( formalParameterStandardDecl ( COMMA formalParameterStandardDecl )* ( COMMA formalParameterVarArgDecl )? )
		// Java.g:642:13: formalParameterStandardDecl ( COMMA formalParameterStandardDecl )* ( COMMA formalParameterVarArgDecl )?
		{
		pushFollow(FOLLOW_formalParameterStandardDecl_in_synpred99_Java7632);
		formalParameterStandardDecl();
		state._fsp--;
		if (state.failed) return ;

		// Java.g:642:41: ( COMMA formalParameterStandardDecl )*
		loop191:
		do {
			int alt191=2;
			int LA191_0 = input.LA(1);
			if ( (LA191_0==COMMA) ) {
				int LA191_1 = input.LA(2);
				if ( (synpred97_Java()) ) {
					alt191=1;
				}

			}

			switch (alt191) {
			case 1 :
				// Java.g:642:42: COMMA formalParameterStandardDecl
				{
				match(input,COMMA,FOLLOW_COMMA_in_synpred99_Java7635); if (state.failed) return ;

				pushFollow(FOLLOW_formalParameterStandardDecl_in_synpred99_Java7637);
				formalParameterStandardDecl();
				state._fsp--;
				if (state.failed) return ;

				}
				break;

			default :
				break loop191;
			}
		} while (true);

		// Java.g:642:78: ( COMMA formalParameterVarArgDecl )?
		int alt192=2;
		int LA192_0 = input.LA(1);
		if ( (LA192_0==COMMA) ) {
			alt192=1;
		}
		switch (alt192) {
			case 1 :
				// Java.g:642:79: COMMA formalParameterVarArgDecl
				{
				match(input,COMMA,FOLLOW_COMMA_in_synpred99_Java7642); if (state.failed) return ;

				pushFollow(FOLLOW_formalParameterVarArgDecl_in_synpred99_Java7644);
				formalParameterVarArgDecl();
				state._fsp--;
				if (state.failed) return ;

				}
				break;

		}

		}

	}
	// $ANTLR end synpred99_Java

	// $ANTLR start synpred100_Java
	public final void synpred100_Java_fragment() throws RecognitionException {
		// Java.g:645:13: ( formalParameterVarArgDecl )
		// Java.g:645:13: formalParameterVarArgDecl
		{
		pushFollow(FOLLOW_formalParameterVarArgDecl_in_synpred100_Java7701);
		formalParameterVarArgDecl();
		state._fsp--;
		if (state.failed) return ;

		}

	}
	// $ANTLR end synpred100_Java

	// $ANTLR start synpred101_Java
	public final void synpred101_Java_fragment() throws RecognitionException {
		Token ident=null;


		// Java.g:666:13: ( DOT ident= IDENT )
		// Java.g:666:13: DOT ident= IDENT
		{
		match(input,DOT,FOLLOW_DOT_in_synpred101_Java7946); if (state.failed) return ;

		ident=(Token)match(input,IDENT,FOLLOW_IDENT_in_synpred101_Java7950); if (state.failed) return ;

		}

	}
	// $ANTLR end synpred101_Java

	// $ANTLR start synpred102_Java
	public final void synpred102_Java_fragment() throws RecognitionException {
		// Java.g:673:9: ( annotation )
		// Java.g:673:9: annotation
		{
		pushFollow(FOLLOW_annotation_in_synpred102_Java8003);
		annotation();
		state._fsp--;
		if (state.failed) return ;

		}

	}
	// $ANTLR end synpred102_Java

	// $ANTLR start synpred114_Java
	public final void synpred114_Java_fragment() throws RecognitionException {
		// Java.g:724:9: ( modifierList type ( IDENT LPAREN RPAREN ( annotationDefaultValue )? SEMI | classFieldDeclaratorList SEMI ) )
		// Java.g:724:9: modifierList type ( IDENT LPAREN RPAREN ( annotationDefaultValue )? SEMI | classFieldDeclaratorList SEMI )
		{
		pushFollow(FOLLOW_modifierList_in_synpred114_Java8457);
		modifierList();
		state._fsp--;
		if (state.failed) return ;

		pushFollow(FOLLOW_type_in_synpred114_Java8459);
		type();
		state._fsp--;
		if (state.failed) return ;

		// Java.g:725:9: ( IDENT LPAREN RPAREN ( annotationDefaultValue )? SEMI | classFieldDeclaratorList SEMI )
		int alt197=2;
		int LA197_0 = input.LA(1);
		if ( (LA197_0==IDENT) ) {
			int LA197_1 = input.LA(2);
			if ( (LA197_1==LPAREN) ) {
				alt197=1;
			}
			else if ( (LA197_1==ASSIGN||LA197_1==COMMA||LA197_1==LBRACK||LA197_1==SEMI) ) {
				alt197=2;
			}
			else {
				if (state.backtracking>0) {state.failed=true; return ;}
				int nvaeMark = input.mark();
				try {
					input.consume();
					NoViableAltException nvae =
						new NoViableAltException("", 197, 1, input);
					throw nvae;
				} finally {
					input.rewind(nvaeMark);
				}
			}
		}
		else {
			if (state.backtracking>0) {state.failed=true; return ;}
			NoViableAltException nvae =
				new NoViableAltException("", 197, 0, input);
			throw nvae;
		}
		switch (alt197) {
			case 1 :
				// Java.g:725:13: IDENT LPAREN RPAREN ( annotationDefaultValue )? SEMI
				{
				match(input,IDENT,FOLLOW_IDENT_in_synpred114_Java8473); if (state.failed) return ;

				match(input,LPAREN,FOLLOW_LPAREN_in_synpred114_Java8475); if (state.failed) return ;

				match(input,RPAREN,FOLLOW_RPAREN_in_synpred114_Java8477); if (state.failed) return ;

				// Java.g:725:33: ( annotationDefaultValue )?
				int alt196=2;
				int LA196_0 = input.LA(1);
				if ( (LA196_0==DEFAULT) ) {
					alt196=1;
				}
				switch (alt196) {
					case 1 :
						// Java.g:725:33: annotationDefaultValue
						{
						pushFollow(FOLLOW_annotationDefaultValue_in_synpred114_Java8479);
						annotationDefaultValue();
						state._fsp--;
						if (state.failed) return ;

						}
						break;

				}

				match(input,SEMI,FOLLOW_SEMI_in_synpred114_Java8482); if (state.failed) return ;

				}
				break;
			case 2 :
				// Java.g:727:13: classFieldDeclaratorList SEMI
				{
				pushFollow(FOLLOW_classFieldDeclaratorList_in_synpred114_Java8524);
				classFieldDeclaratorList();
				state._fsp--;
				if (state.failed) return ;

				match(input,SEMI,FOLLOW_SEMI_in_synpred114_Java8526); if (state.failed) return ;

				}
				break;

		}

		}

	}
	// $ANTLR end synpred114_Java

	// $ANTLR start synpred116_Java
	public final void synpred116_Java_fragment() throws RecognitionException {
		// Java.g:745:9: ( localVariableDeclaration SEMI )
		// Java.g:745:9: localVariableDeclaration SEMI
		{
		pushFollow(FOLLOW_localVariableDeclaration_in_synpred116_Java8661);
		localVariableDeclaration();
		state._fsp--;
		if (state.failed) return ;

		match(input,SEMI,FOLLOW_SEMI_in_synpred116_Java8663); if (state.failed) return ;

		}

	}
	// $ANTLR end synpred116_Java

	// $ANTLR start synpred117_Java
	public final void synpred117_Java_fragment() throws RecognitionException {
		// Java.g:746:9: ( typeDeclaration )
		// Java.g:746:9: typeDeclaration
		{
		pushFollow(FOLLOW_typeDeclaration_in_synpred117_Java8674);
		typeDeclaration();
		state._fsp--;
		if (state.failed) return ;

		}

	}
	// $ANTLR end synpred117_Java

	// $ANTLR start synpred121_Java
	public final void synpred121_Java_fragment() throws RecognitionException {
		ParserRuleReturnScope elseStat =null;


		// Java.g:763:13: ( ELSE elseStat= statement )
		// Java.g:763:13: ELSE elseStat= statement
		{
		match(input,ELSE,FOLLOW_ELSE_in_synpred121_Java8972); if (state.failed) return ;

		pushFollow(FOLLOW_statement_in_synpred121_Java8976);
		elseStat=statement();
		state._fsp--;
		if (state.failed) return ;

		}

	}
	// $ANTLR end synpred121_Java

	// $ANTLR start synpred123_Java
	public final void synpred123_Java_fragment() throws RecognitionException {
		// Java.g:767:13: ( forInit SEMI forCondition SEMI forUpdater RPAREN statement )
		// Java.g:767:13: forInit SEMI forCondition SEMI forUpdater RPAREN statement
		{
		pushFollow(FOLLOW_forInit_in_synpred123_Java9159);
		forInit();
		state._fsp--;
		if (state.failed) return ;

		match(input,SEMI,FOLLOW_SEMI_in_synpred123_Java9161); if (state.failed) return ;

		pushFollow(FOLLOW_forCondition_in_synpred123_Java9163);
		forCondition();
		state._fsp--;
		if (state.failed) return ;

		match(input,SEMI,FOLLOW_SEMI_in_synpred123_Java9165); if (state.failed) return ;

		pushFollow(FOLLOW_forUpdater_in_synpred123_Java9167);
		forUpdater();
		state._fsp--;
		if (state.failed) return ;

		match(input,RPAREN,FOLLOW_RPAREN_in_synpred123_Java9169); if (state.failed) return ;

		pushFollow(FOLLOW_statement_in_synpred123_Java9171);
		statement();
		state._fsp--;
		if (state.failed) return ;

		}

	}
	// $ANTLR end synpred123_Java

	// $ANTLR start synpred143_Java
	public final void synpred143_Java_fragment() throws RecognitionException {
		// Java.g:805:9: ( switchCaseLabel )
		// Java.g:805:9: switchCaseLabel
		{
		pushFollow(FOLLOW_switchCaseLabel_in_synpred143_Java10138);
		switchCaseLabel();
		state._fsp--;
		if (state.failed) return ;

		}

	}
	// $ANTLR end synpred143_Java

	// $ANTLR start synpred146_Java
	public final void synpred146_Java_fragment() throws RecognitionException {
		// Java.g:817:9: ( localVariableDeclaration )
		// Java.g:817:9: localVariableDeclaration
		{
		pushFollow(FOLLOW_localVariableDeclaration_in_synpred146_Java10228);
		localVariableDeclaration();
		state._fsp--;
		if (state.failed) return ;

		}

	}
	// $ANTLR end synpred146_Java

	// $ANTLR start synpred147_Java
	public final void synpred147_Java_fragment() throws RecognitionException {
		// Java.g:818:9: ( expressionList )
		// Java.g:818:9: expressionList
		{
		pushFollow(FOLLOW_expressionList_in_synpred147_Java10250);
		expressionList();
		state._fsp--;
		if (state.failed) return ;

		}

	}
	// $ANTLR end synpred147_Java

	// $ANTLR start synpred190_Java
	public final void synpred190_Java_fragment() throws RecognitionException {
		// Java.g:954:9: ( LPAREN type RPAREN unaryExpression )
		// Java.g:954:9: LPAREN type RPAREN unaryExpression
		{
		match(input,LPAREN,FOLLOW_LPAREN_in_synpred190_Java11783); if (state.failed) return ;

		pushFollow(FOLLOW_type_in_synpred190_Java11785);
		type();
		state._fsp--;
		if (state.failed) return ;

		match(input,RPAREN,FOLLOW_RPAREN_in_synpred190_Java11787); if (state.failed) return ;

		pushFollow(FOLLOW_unaryExpression_in_synpred190_Java11789);
		unaryExpression();
		state._fsp--;
		if (state.failed) return ;

		}

	}
	// $ANTLR end synpred190_Java

	// $ANTLR start synpred218_Java
	public final void synpred218_Java_fragment() throws RecognitionException {
		// Java.g:1022:13: ( ( arrayDeclarator )+ ( DOT CLASS ) )
		// Java.g:1022:13: ( arrayDeclarator )+ ( DOT CLASS )
		{
		// Java.g:1022:13: ( arrayDeclarator )+
		int cnt220=0;
		loop220:
		do {
			int alt220=2;
			int LA220_0 = input.LA(1);
			if ( (LA220_0==LBRACK) ) {
				alt220=1;
			}

			switch (alt220) {
			case 1 :
				// Java.g:1022:17: arrayDeclarator
				{
				pushFollow(FOLLOW_arrayDeclarator_in_synpred218_Java13690);
				arrayDeclarator();
				state._fsp--;
				if (state.failed) return ;

				}
				break;

			default :
				if ( cnt220 >= 1 ) break loop220;
				if (state.backtracking>0) {state.failed=true; return ;}
					EarlyExitException eee =
						new EarlyExitException(220, input);
					throw eee;
			}
			cnt220++;
		} while (true);

		// Java.g:1024:13: ( DOT CLASS )
		// Java.g:1024:17: DOT CLASS
		{
		match(input,DOT,FOLLOW_DOT_in_synpred218_Java13758); if (state.failed) return ;

		match(input,CLASS,FOLLOW_CLASS_in_synpred218_Java13760); if (state.failed) return ;

		}

		}

	}
	// $ANTLR end synpred218_Java

	// $ANTLR start synpred226_Java
	public final void synpred226_Java_fragment() throws RecognitionException {
		Token outerDot=null;
		Token Super=null;
		Token innerDot=null;


		// Java.g:1027:13: (outerDot= DOT ( CLASS | genericTypeArgumentListSimplified (Super= SUPER arguments | SUPER innerDot= DOT IDENT arguments | IDENT arguments ) | THIS |Super= SUPER arguments | innerNewExpression ) )
		// Java.g:1027:13: outerDot= DOT ( CLASS | genericTypeArgumentListSimplified (Super= SUPER arguments | SUPER innerDot= DOT IDENT arguments | IDENT arguments ) | THIS |Super= SUPER arguments | innerNewExpression )
		{
		outerDot=(Token)match(input,DOT,FOLLOW_DOT_in_synpred226_Java13891); if (state.failed) return ;

		// Java.g:1028:13: ( CLASS | genericTypeArgumentListSimplified (Super= SUPER arguments | SUPER innerDot= DOT IDENT arguments | IDENT arguments ) | THIS |Super= SUPER arguments | innerNewExpression )
		int alt223=5;
		switch ( input.LA(1) ) {
		case CLASS:
			{
			alt223=1;
			}
			break;
		case LESS_THAN:
			{
			alt223=2;
			}
			break;
		case THIS:
			{
			alt223=3;
			}
			break;
		case SUPER:
			{
			alt223=4;
			}
			break;
		case NEW:
			{
			alt223=5;
			}
			break;
		default:
			if (state.backtracking>0) {state.failed=true; return ;}
			NoViableAltException nvae =
				new NoViableAltException("", 223, 0, input);
			throw nvae;
		}
		switch (alt223) {
			case 1 :
				// Java.g:1028:17: CLASS
				{
				match(input,CLASS,FOLLOW_CLASS_in_synpred226_Java13909); if (state.failed) return ;

				}
				break;
			case 2 :
				// Java.g:1029:17: genericTypeArgumentListSimplified (Super= SUPER arguments | SUPER innerDot= DOT IDENT arguments | IDENT arguments )
				{
				pushFollow(FOLLOW_genericTypeArgumentListSimplified_in_synpred226_Java13972);
				genericTypeArgumentListSimplified();
				state._fsp--;
				if (state.failed) return ;

				// Java.g:1030:17: (Super= SUPER arguments | SUPER innerDot= DOT IDENT arguments | IDENT arguments )
				int alt222=3;
				int LA222_0 = input.LA(1);
				if ( (LA222_0==SUPER) ) {
					int LA222_1 = input.LA(2);
					if ( (LA222_1==DOT) ) {
						alt222=2;
					}
					else if ( (LA222_1==LPAREN) ) {
						alt222=1;
					}
					else {
						if (state.backtracking>0) {state.failed=true; return ;}
						int nvaeMark = input.mark();
						try {
							input.consume();
							NoViableAltException nvae =
								new NoViableAltException("", 222, 1, input);
							throw nvae;
						} finally {
							input.rewind(nvaeMark);
						}
					}
				}
				else if ( (LA222_0==IDENT) ) {
					alt222=3;
				}
				else {
					if (state.backtracking>0) {state.failed=true; return ;}
					NoViableAltException nvae =
						new NoViableAltException("", 222, 0, input);
					throw nvae;
				}
				switch (alt222) {
					case 1 :
						// Java.g:1030:21: Super= SUPER arguments
						{
						Super=(Token)match(input,SUPER,FOLLOW_SUPER_in_synpred226_Java13997); if (state.failed) return ;

						pushFollow(FOLLOW_arguments_in_synpred226_Java13999);
						arguments();
						state._fsp--;
						if (state.failed) return ;

						}
						break;
					case 2 :
						// Java.g:1031:21: SUPER innerDot= DOT IDENT arguments
						{
						match(input,SUPER,FOLLOW_SUPER_in_synpred226_Java14049); if (state.failed) return ;

						innerDot=(Token)match(input,DOT,FOLLOW_DOT_in_synpred226_Java14053); if (state.failed) return ;

						match(input,IDENT,FOLLOW_IDENT_in_synpred226_Java14055); if (state.failed) return ;

						pushFollow(FOLLOW_arguments_in_synpred226_Java14057);
						arguments();
						state._fsp--;
						if (state.failed) return ;

						}
						break;
					case 3 :
						// Java.g:1032:21: IDENT arguments
						{
						match(input,IDENT,FOLLOW_IDENT_in_synpred226_Java14107); if (state.failed) return ;

						pushFollow(FOLLOW_arguments_in_synpred226_Java14109);
						arguments();
						state._fsp--;
						if (state.failed) return ;

						}
						break;

				}

				}
				break;
			case 3 :
				// Java.g:1034:17: THIS
				{
				match(input,THIS,FOLLOW_THIS_in_synpred226_Java14184); if (state.failed) return ;

				}
				break;
			case 4 :
				// Java.g:1035:17: Super= SUPER arguments
				{
				Super=(Token)match(input,SUPER,FOLLOW_SUPER_in_synpred226_Java14250); if (state.failed) return ;

				pushFollow(FOLLOW_arguments_in_synpred226_Java14252);
				arguments();
				state._fsp--;
				if (state.failed) return ;

				}
				break;
			case 5 :
				// Java.g:1036:17: innerNewExpression
				{
				pushFollow(FOLLOW_innerNewExpression_in_synpred226_Java14300);
				innerNewExpression();
				state._fsp--;
				if (state.failed) return ;

				}
				break;

		}

		}

	}
	// $ANTLR end synpred226_Java

	// $ANTLR start synpred234_Java
	public final void synpred234_Java_fragment() throws RecognitionException {
		// Java.g:1061:37: ( LBRACK expression RBRACK )
		// Java.g:1061:37: LBRACK expression RBRACK
		{
		match(input,LBRACK,FOLLOW_LBRACK_in_synpred234_Java14701); if (state.failed) return ;

		pushFollow(FOLLOW_expression_in_synpred234_Java14704);
		expression();
		state._fsp--;
		if (state.failed) return ;

		match(input,RBRACK,FOLLOW_RBRACK_in_synpred234_Java14706); if (state.failed) return ;

		}

	}
	// $ANTLR end synpred234_Java

	// Delegated rules

	public final boolean synpred226_Java() {
		state.backtracking++;
		int start = input.mark();
		try {
			synpred226_Java_fragment(); // can never throw exception
		} catch (RecognitionException re) {
			System.err.println("impossible: "+re);
		}
		boolean success = !state.failed;
		input.rewind(start);
		state.backtracking--;
		state.failed=false;
		return success;
	}
	public final boolean synpred43_Java() {
		state.backtracking++;
		int start = input.mark();
		try {
			synpred43_Java_fragment(); // can never throw exception
		} catch (RecognitionException re) {
			System.err.println("impossible: "+re);
		}
		boolean success = !state.failed;
		input.rewind(start);
		state.backtracking--;
		state.failed=false;
		return success;
	}
	public final boolean synpred121_Java() {
		state.backtracking++;
		int start = input.mark();
		try {
			synpred121_Java_fragment(); // can never throw exception
		} catch (RecognitionException re) {
			System.err.println("impossible: "+re);
		}
		boolean success = !state.failed;
		input.rewind(start);
		state.backtracking--;
		state.failed=false;
		return success;
	}
	public final boolean synpred76_Java() {
		state.backtracking++;
		int start = input.mark();
		try {
			synpred76_Java_fragment(); // can never throw exception
		} catch (RecognitionException re) {
			System.err.println("impossible: "+re);
		}
		boolean success = !state.failed;
		input.rewind(start);
		state.backtracking--;
		state.failed=false;
		return success;
	}
	public final boolean synpred114_Java() {
		state.backtracking++;
		int start = input.mark();
		try {
			synpred114_Java_fragment(); // can never throw exception
		} catch (RecognitionException re) {
			System.err.println("impossible: "+re);
		}
		boolean success = !state.failed;
		input.rewind(start);
		state.backtracking--;
		state.failed=false;
		return success;
	}
	public final boolean synpred116_Java() {
		state.backtracking++;
		int start = input.mark();
		try {
			synpred116_Java_fragment(); // can never throw exception
		} catch (RecognitionException re) {
			System.err.println("impossible: "+re);
		}
		boolean success = !state.failed;
		input.rewind(start);
		state.backtracking--;
		state.failed=false;
		return success;
	}
	public final boolean synpred97_Java() {
		state.backtracking++;
		int start = input.mark();
		try {
			synpred97_Java_fragment(); // can never throw exception
		} catch (RecognitionException re) {
			System.err.println("impossible: "+re);
		}
		boolean success = !state.failed;
		input.rewind(start);
		state.backtracking--;
		state.failed=false;
		return success;
	}
	public final boolean synpred102_Java() {
		state.backtracking++;
		int start = input.mark();
		try {
			synpred102_Java_fragment(); // can never throw exception
		} catch (RecognitionException re) {
			System.err.println("impossible: "+re);
		}
		boolean success = !state.failed;
		input.rewind(start);
		state.backtracking--;
		state.failed=false;
		return success;
	}
	public final boolean synpred218_Java() {
		state.backtracking++;
		int start = input.mark();
		try {
			synpred218_Java_fragment(); // can never throw exception
		} catch (RecognitionException re) {
			System.err.println("impossible: "+re);
		}
		boolean success = !state.failed;
		input.rewind(start);
		state.backtracking--;
		state.failed=false;
		return success;
	}
	public final boolean synpred117_Java() {
		state.backtracking++;
		int start = input.mark();
		try {
			synpred117_Java_fragment(); // can never throw exception
		} catch (RecognitionException re) {
			System.err.println("impossible: "+re);
		}
		boolean success = !state.failed;
		input.rewind(start);
		state.backtracking--;
		state.failed=false;
		return success;
	}
	public final boolean synpred79_Java() {
		state.backtracking++;
		int start = input.mark();
		try {
			synpred79_Java_fragment(); // can never throw exception
		} catch (RecognitionException re) {
			System.err.println("impossible: "+re);
		}
		boolean success = !state.failed;
		input.rewind(start);
		state.backtracking--;
		state.failed=false;
		return success;
	}
	public final boolean synpred101_Java() {
		state.backtracking++;
		int start = input.mark();
		try {
			synpred101_Java_fragment(); // can never throw exception
		} catch (RecognitionException re) {
			System.err.println("impossible: "+re);
		}
		boolean success = !state.failed;
		input.rewind(start);
		state.backtracking--;
		state.failed=false;
		return success;
	}
	public final boolean synpred16_Java() {
		state.backtracking++;
		int start = input.mark();
		try {
			synpred16_Java_fragment(); // can never throw exception
		} catch (RecognitionException re) {
			System.err.println("impossible: "+re);
		}
		boolean success = !state.failed;
		input.rewind(start);
		state.backtracking--;
		state.failed=false;
		return success;
	}
	public final boolean synpred147_Java() {
		state.backtracking++;
		int start = input.mark();
		try {
			synpred147_Java_fragment(); // can never throw exception
		} catch (RecognitionException re) {
			System.err.println("impossible: "+re);
		}
		boolean success = !state.failed;
		input.rewind(start);
		state.backtracking--;
		state.failed=false;
		return success;
	}
	public final boolean synpred42_Java() {
		state.backtracking++;
		int start = input.mark();
		try {
			synpred42_Java_fragment(); // can never throw exception
		} catch (RecognitionException re) {
			System.err.println("impossible: "+re);
		}
		boolean success = !state.failed;
		input.rewind(start);
		state.backtracking--;
		state.failed=false;
		return success;
	}
	public final boolean synpred143_Java() {
		state.backtracking++;
		int start = input.mark();
		try {
			synpred143_Java_fragment(); // can never throw exception
		} catch (RecognitionException re) {
			System.err.println("impossible: "+re);
		}
		boolean success = !state.failed;
		input.rewind(start);
		state.backtracking--;
		state.failed=false;
		return success;
	}
	public final boolean synpred190_Java() {
		state.backtracking++;
		int start = input.mark();
		try {
			synpred190_Java_fragment(); // can never throw exception
		} catch (RecognitionException re) {
			System.err.println("impossible: "+re);
		}
		boolean success = !state.failed;
		input.rewind(start);
		state.backtracking--;
		state.failed=false;
		return success;
	}
	public final boolean synpred77_Java() {
		state.backtracking++;
		int start = input.mark();
		try {
			synpred77_Java_fragment(); // can never throw exception
		} catch (RecognitionException re) {
			System.err.println("impossible: "+re);
		}
		boolean success = !state.failed;
		input.rewind(start);
		state.backtracking--;
		state.failed=false;
		return success;
	}
	public final boolean synpred51_Java() {
		state.backtracking++;
		int start = input.mark();
		try {
			synpred51_Java_fragment(); // can never throw exception
		} catch (RecognitionException re) {
			System.err.println("impossible: "+re);
		}
		boolean success = !state.failed;
		input.rewind(start);
		state.backtracking--;
		state.failed=false;
		return success;
	}
	public final boolean synpred100_Java() {
		state.backtracking++;
		int start = input.mark();
		try {
			synpred100_Java_fragment(); // can never throw exception
		} catch (RecognitionException re) {
			System.err.println("impossible: "+re);
		}
		boolean success = !state.failed;
		input.rewind(start);
		state.backtracking--;
		state.failed=false;
		return success;
	}
	public final boolean synpred52_Java() {
		state.backtracking++;
		int start = input.mark();
		try {
			synpred52_Java_fragment(); // can never throw exception
		} catch (RecognitionException re) {
			System.err.println("impossible: "+re);
		}
		boolean success = !state.failed;
		input.rewind(start);
		state.backtracking--;
		state.failed=false;
		return success;
	}
	public final boolean synpred15_Java() {
		state.backtracking++;
		int start = input.mark();
		try {
			synpred15_Java_fragment(); // can never throw exception
		} catch (RecognitionException re) {
			System.err.println("impossible: "+re);
		}
		boolean success = !state.failed;
		input.rewind(start);
		state.backtracking--;
		state.failed=false;
		return success;
	}
	public final boolean synpred123_Java() {
		state.backtracking++;
		int start = input.mark();
		try {
			synpred123_Java_fragment(); // can never throw exception
		} catch (RecognitionException re) {
			System.err.println("impossible: "+re);
		}
		boolean success = !state.failed;
		input.rewind(start);
		state.backtracking--;
		state.failed=false;
		return success;
	}
	public final boolean synpred32_Java() {
		state.backtracking++;
		int start = input.mark();
		try {
			synpred32_Java_fragment(); // can never throw exception
		} catch (RecognitionException re) {
			System.err.println("impossible: "+re);
		}
		boolean success = !state.failed;
		input.rewind(start);
		state.backtracking--;
		state.failed=false;
		return success;
	}
	public final boolean synpred17_Java() {
		state.backtracking++;
		int start = input.mark();
		try {
			synpred17_Java_fragment(); // can never throw exception
		} catch (RecognitionException re) {
			System.err.println("impossible: "+re);
		}
		boolean success = !state.failed;
		input.rewind(start);
		state.backtracking--;
		state.failed=false;
		return success;
	}
	public final boolean synpred92_Java() {
		state.backtracking++;
		int start = input.mark();
		try {
			synpred92_Java_fragment(); // can never throw exception
		} catch (RecognitionException re) {
			System.err.println("impossible: "+re);
		}
		boolean success = !state.failed;
		input.rewind(start);
		state.backtracking--;
		state.failed=false;
		return success;
	}
	public final boolean synpred90_Java() {
		state.backtracking++;
		int start = input.mark();
		try {
			synpred90_Java_fragment(); // can never throw exception
		} catch (RecognitionException re) {
			System.err.println("impossible: "+re);
		}
		boolean success = !state.failed;
		input.rewind(start);
		state.backtracking--;
		state.failed=false;
		return success;
	}
	public final boolean synpred58_Java() {
		state.backtracking++;
		int start = input.mark();
		try {
			synpred58_Java_fragment(); // can never throw exception
		} catch (RecognitionException re) {
			System.err.println("impossible: "+re);
		}
		boolean success = !state.failed;
		input.rewind(start);
		state.backtracking--;
		state.failed=false;
		return success;
	}
	public final boolean synpred50_Java() {
		state.backtracking++;
		int start = input.mark();
		try {
			synpred50_Java_fragment(); // can never throw exception
		} catch (RecognitionException re) {
			System.err.println("impossible: "+re);
		}
		boolean success = !state.failed;
		input.rewind(start);
		state.backtracking--;
		state.failed=false;
		return success;
	}
	public final boolean synpred14_Java() {
		state.backtracking++;
		int start = input.mark();
		try {
			synpred14_Java_fragment(); // can never throw exception
		} catch (RecognitionException re) {
			System.err.println("impossible: "+re);
		}
		boolean success = !state.failed;
		input.rewind(start);
		state.backtracking--;
		state.failed=false;
		return success;
	}
	public final boolean synpred99_Java() {
		state.backtracking++;
		int start = input.mark();
		try {
			synpred99_Java_fragment(); // can never throw exception
		} catch (RecognitionException re) {
			System.err.println("impossible: "+re);
		}
		boolean success = !state.failed;
		input.rewind(start);
		state.backtracking--;
		state.failed=false;
		return success;
	}
	public final boolean synpred234_Java() {
		state.backtracking++;
		int start = input.mark();
		try {
			synpred234_Java_fragment(); // can never throw exception
		} catch (RecognitionException re) {
			System.err.println("impossible: "+re);
		}
		boolean success = !state.failed;
		input.rewind(start);
		state.backtracking--;
		state.failed=false;
		return success;
	}
	public final boolean synpred146_Java() {
		state.backtracking++;
		int start = input.mark();
		try {
			synpred146_Java_fragment(); // can never throw exception
		} catch (RecognitionException re) {
			System.err.println("impossible: "+re);
		}
		boolean success = !state.failed;
		input.rewind(start);
		state.backtracking--;
		state.failed=false;
		return success;
	}
	public final boolean synpred44_Java() {
		state.backtracking++;
		int start = input.mark();
		try {
			synpred44_Java_fragment(); // can never throw exception
		} catch (RecognitionException re) {
			System.err.println("impossible: "+re);
		}
		boolean success = !state.failed;
		input.rewind(start);
		state.backtracking--;
		state.failed=false;
		return success;
	}



	public static final BitSet FOLLOW_compilationUnit_in_javaSource4506 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_annotationList_in_compilationUnit4542 = new BitSet(new long[]{0x0100000800400012L,0x8040000084000004L,0x0004004105010380L});
	public static final BitSet FOLLOW_packageDeclaration_in_compilationUnit4553 = new BitSet(new long[]{0x0100000800400012L,0x0040000084000004L,0x0004004105010380L});
	public static final BitSet FOLLOW_importDeclaration_in_compilationUnit4565 = new BitSet(new long[]{0x0100000800400012L,0x0040000084000004L,0x0004004105010380L});
	public static final BitSet FOLLOW_typeDecls_in_compilationUnit4577 = new BitSet(new long[]{0x0100000800400012L,0x0040000080000004L,0x0004004105010380L});
	public static final BitSet FOLLOW_typeDeclaration_in_typeDecls4597 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_SEMI_in_typeDecls4607 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_PACKAGE_in_packageDeclaration4627 = new BitSet(new long[]{0x0000000000000000L,0x0000000000400000L});
	public static final BitSet FOLLOW_qualifiedIdentifier_in_packageDeclaration4630 = new BitSet(new long[]{0x0000000000000000L,0x0000000000000000L,0x0000000000010000L});
	public static final BitSet FOLLOW_SEMI_in_packageDeclaration4632 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_IMPORT_in_importDeclaration4658 = new BitSet(new long[]{0x0000000000000000L,0x0000000000400000L,0x0000000001000000L});
	public static final BitSet FOLLOW_STATIC_in_importDeclaration4661 = new BitSet(new long[]{0x0000000000000000L,0x0000000000400000L});
	public static final BitSet FOLLOW_qualifiedIdentifier_in_importDeclaration4664 = new BitSet(new long[]{0x0010000000000000L,0x0000000000000000L,0x0000000000010000L});
	public static final BitSet FOLLOW_DOTSTAR_in_importDeclaration4666 = new BitSet(new long[]{0x0000000000000000L,0x0000000000000000L,0x0000000000010000L});
	public static final BitSet FOLLOW_SEMI_in_importDeclaration4669 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_modifierList_in_typeDeclaration4693 = new BitSet(new long[]{0x0100000800400000L,0x0000000080000000L});
	public static final BitSet FOLLOW_classTypeDeclaration_in_typeDeclaration4708 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_interfaceTypeDeclaration_in_typeDeclaration4723 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_enumTypeDeclaration_in_typeDeclaration4738 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_annotationTypeDeclaration_in_typeDeclaration4753 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_CLASS_in_classTypeDeclaration4788 = new BitSet(new long[]{0x0000000000000000L,0x0000000000400000L});
	public static final BitSet FOLLOW_IDENT_in_classTypeDeclaration4790 = new BitSet(new long[]{0x4000000000000000L,0x0000014001000000L});
	public static final BitSet FOLLOW_genericTypeParameterList_in_classTypeDeclaration4792 = new BitSet(new long[]{0x4000000000000000L,0x0000004001000000L});
	public static final BitSet FOLLOW_classExtendsClause_in_classTypeDeclaration4795 = new BitSet(new long[]{0x0000000000000000L,0x0000004001000000L});
	public static final BitSet FOLLOW_implementsClause_in_classTypeDeclaration4798 = new BitSet(new long[]{0x0000000000000000L,0x0000004000000000L});
	public static final BitSet FOLLOW_classBody_in_classTypeDeclaration4801 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_EXTENDS_in_classExtendsClause4854 = new BitSet(new long[]{0x0020000214000000L,0x0000400020400010L,0x0000000000200000L});
	public static final BitSet FOLLOW_type_in_classExtendsClause4856 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_EXTENDS_in_interfaceExtendsClause4900 = new BitSet(new long[]{0x0020000214000000L,0x0000400020400010L,0x0000000000200000L});
	public static final BitSet FOLLOW_typeList_in_interfaceExtendsClause4902 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_IMPLEMENTS_in_implementsClause4946 = new BitSet(new long[]{0x0020000214000000L,0x0000400020400010L,0x0000000000200000L});
	public static final BitSet FOLLOW_typeList_in_implementsClause4948 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_LESS_THAN_in_genericTypeParameterList4993 = new BitSet(new long[]{0x0000000000000000L,0x0000000000400000L});
	public static final BitSet FOLLOW_genericTypeParameter_in_genericTypeParameterList4995 = new BitSet(new long[]{0x0000020000800000L,0x0000000000080000L,0x0000000000080000L});
	public static final BitSet FOLLOW_COMMA_in_genericTypeParameterList4998 = new BitSet(new long[]{0x0000000000000000L,0x0000000000400000L});
	public static final BitSet FOLLOW_genericTypeParameter_in_genericTypeParameterList5000 = new BitSet(new long[]{0x0000020000800000L,0x0000000000080000L,0x0000000000080000L});
	public static final BitSet FOLLOW_genericTypeListClosing_in_genericTypeParameterList5004 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_GREATER_THAN_in_genericTypeListClosing5119 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_SHIFT_RIGHT_in_genericTypeListClosing5129 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_BIT_SHIFT_RIGHT_in_genericTypeListClosing5139 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_IDENT_in_genericTypeParameter5167 = new BitSet(new long[]{0x4000000000000002L});
	public static final BitSet FOLLOW_bound_in_genericTypeParameter5169 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_EXTENDS_in_bound5215 = new BitSet(new long[]{0x0020000214000000L,0x0000400020400010L,0x0000000000200000L});
	public static final BitSet FOLLOW_type_in_bound5217 = new BitSet(new long[]{0x0000000000000022L});
	public static final BitSet FOLLOW_AND_in_bound5220 = new BitSet(new long[]{0x0020000214000000L,0x0000400020400010L,0x0000000000200000L});
	public static final BitSet FOLLOW_type_in_bound5222 = new BitSet(new long[]{0x0000000000000022L});
	public static final BitSet FOLLOW_ENUM_in_enumTypeDeclaration5263 = new BitSet(new long[]{0x0000000000000000L,0x0000000000400000L});
	public static final BitSet FOLLOW_IDENT_in_enumTypeDeclaration5265 = new BitSet(new long[]{0x0000000000000000L,0x0000004001000000L});
	public static final BitSet FOLLOW_implementsClause_in_enumTypeDeclaration5267 = new BitSet(new long[]{0x0000000000000000L,0x0000004000000000L});
	public static final BitSet FOLLOW_enumBody_in_enumTypeDeclaration5270 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_LCURLY_in_enumBody5317 = new BitSet(new long[]{0x0000000000400000L,0x0000000000400000L});
	public static final BitSet FOLLOW_enumScopeDeclarations_in_enumBody5319 = new BitSet(new long[]{0x0000000000000000L,0x0000000000000000L,0x0000000000002000L});
	public static final BitSet FOLLOW_RCURLY_in_enumBody5321 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_enumConstants_in_enumScopeDeclarations5358 = new BitSet(new long[]{0x0000020000000002L,0x0000000000000000L,0x0000000000010000L});
	public static final BitSet FOLLOW_COMMA_in_enumScopeDeclarations5361 = new BitSet(new long[]{0x0000000000000002L,0x0000000000000000L,0x0000000000010000L});
	public static final BitSet FOLLOW_enumClassScopeDeclarations_in_enumScopeDeclarations5366 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_SEMI_in_enumClassScopeDeclarations5386 = new BitSet(new long[]{0x0120000A14400012L,0x00404140A0400014L,0x0005004105210380L});
	public static final BitSet FOLLOW_classScopeDeclarations_in_enumClassScopeDeclarations5388 = new BitSet(new long[]{0x0120000A14400012L,0x00404140A0400014L,0x0005004105210380L});
	public static final BitSet FOLLOW_enumConstant_in_enumConstants5427 = new BitSet(new long[]{0x0000020000000002L});
	public static final BitSet FOLLOW_COMMA_in_enumConstants5430 = new BitSet(new long[]{0x0000000000400000L,0x0000000000400000L});
	public static final BitSet FOLLOW_enumConstant_in_enumConstants5433 = new BitSet(new long[]{0x0000020000000002L});
	public static final BitSet FOLLOW_annotationList_in_enumConstant5458 = new BitSet(new long[]{0x0000000000000000L,0x0000000000400000L});
	public static final BitSet FOLLOW_IDENT_in_enumConstant5460 = new BitSet(new long[]{0x0000000000000002L,0x0000804000000000L});
	public static final BitSet FOLLOW_arguments_in_enumConstant5463 = new BitSet(new long[]{0x0000000000000002L,0x0000004000000000L});
	public static final BitSet FOLLOW_classBody_in_enumConstant5466 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_INTERFACE_in_interfaceTypeDeclaration5491 = new BitSet(new long[]{0x0000000000000000L,0x0000000000400000L});
	public static final BitSet FOLLOW_IDENT_in_interfaceTypeDeclaration5493 = new BitSet(new long[]{0x4000000000000000L,0x0000014000000000L});
	public static final BitSet FOLLOW_genericTypeParameterList_in_interfaceTypeDeclaration5495 = new BitSet(new long[]{0x4000000000000000L,0x0000004000000000L});
	public static final BitSet FOLLOW_interfaceExtendsClause_in_interfaceTypeDeclaration5498 = new BitSet(new long[]{0x0000000000000000L,0x0000004000000000L});
	public static final BitSet FOLLOW_interfaceBody_in_interfaceTypeDeclaration5501 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_type_in_typeList5551 = new BitSet(new long[]{0x0000020000000002L});
	public static final BitSet FOLLOW_COMMA_in_typeList5554 = new BitSet(new long[]{0x0020000214000000L,0x0000400020400010L,0x0000000000200000L});
	public static final BitSet FOLLOW_type_in_typeList5557 = new BitSet(new long[]{0x0000020000000002L});
	public static final BitSet FOLLOW_LCURLY_in_classBody5582 = new BitSet(new long[]{0x0120000A14400010L,0x00404140A0400014L,0x0005004105212380L});
	public static final BitSet FOLLOW_classScopeDeclarations_in_classBody5584 = new BitSet(new long[]{0x0120000A14400010L,0x00404140A0400014L,0x0005004105212380L});
	public static final BitSet FOLLOW_RCURLY_in_classBody5587 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_LCURLY_in_interfaceBody5629 = new BitSet(new long[]{0x0120000A14400010L,0x00404100A0400014L,0x0005004105212380L});
	public static final BitSet FOLLOW_interfaceScopeDeclarations_in_interfaceBody5631 = new BitSet(new long[]{0x0120000A14400010L,0x00404100A0400014L,0x0005004105212380L});
	public static final BitSet FOLLOW_RCURLY_in_interfaceBody5634 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_block_in_classScopeDeclarations5672 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_STATIC_in_classScopeDeclarations5701 = new BitSet(new long[]{0x0000000000000000L,0x0000004000000000L});
	public static final BitSet FOLLOW_block_in_classScopeDeclarations5703 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_modifierList_in_classScopeDeclarations5726 = new BitSet(new long[]{0x0020000214000000L,0x0000410020400010L,0x0001000000200000L});
	public static final BitSet FOLLOW_genericTypeParameterList_in_classScopeDeclarations5740 = new BitSet(new long[]{0x0020000214000000L,0x0000400020400010L,0x0001000000200000L});
	public static final BitSet FOLLOW_type_in_classScopeDeclarations5759 = new BitSet(new long[]{0x0000000000000000L,0x0000000000400000L});
	public static final BitSet FOLLOW_IDENT_in_classScopeDeclarations5761 = new BitSet(new long[]{0x0000000000000000L,0x0000800000000000L});
	public static final BitSet FOLLOW_formalParameterList_in_classScopeDeclarations5763 = new BitSet(new long[]{0x0000000000000000L,0x0000006000000000L,0x0000001000010000L});
	public static final BitSet FOLLOW_arrayDeclaratorList_in_classScopeDeclarations5765 = new BitSet(new long[]{0x0000000000000000L,0x0000004000000000L,0x0000001000010000L});
	public static final BitSet FOLLOW_throwsClause_in_classScopeDeclarations5768 = new BitSet(new long[]{0x0000000000000000L,0x0000004000000000L,0x0000000000010000L});
	public static final BitSet FOLLOW_block_in_classScopeDeclarations5772 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_SEMI_in_classScopeDeclarations5776 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_VOID_in_classScopeDeclarations5838 = new BitSet(new long[]{0x0000000000000000L,0x0000000000400000L});
	public static final BitSet FOLLOW_IDENT_in_classScopeDeclarations5840 = new BitSet(new long[]{0x0000000000000000L,0x0000800000000000L});
	public static final BitSet FOLLOW_formalParameterList_in_classScopeDeclarations5842 = new BitSet(new long[]{0x0000000000000000L,0x0000004000000000L,0x0000001000010000L});
	public static final BitSet FOLLOW_throwsClause_in_classScopeDeclarations5844 = new BitSet(new long[]{0x0000000000000000L,0x0000004000000000L,0x0000000000010000L});
	public static final BitSet FOLLOW_block_in_classScopeDeclarations5848 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_SEMI_in_classScopeDeclarations5852 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_IDENT_in_classScopeDeclarations5911 = new BitSet(new long[]{0x0000000000000000L,0x0000800000000000L});
	public static final BitSet FOLLOW_formalParameterList_in_classScopeDeclarations5913 = new BitSet(new long[]{0x0000000000000000L,0x0000004000000000L,0x0000001000000000L});
	public static final BitSet FOLLOW_throwsClause_in_classScopeDeclarations5915 = new BitSet(new long[]{0x0000000000000000L,0x0000004000000000L});
	public static final BitSet FOLLOW_block_in_classScopeDeclarations5918 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_type_in_classScopeDeclarations5982 = new BitSet(new long[]{0x0000000000000000L,0x0000000000400000L});
	public static final BitSet FOLLOW_classFieldDeclaratorList_in_classScopeDeclarations5984 = new BitSet(new long[]{0x0000000000000000L,0x0000000000000000L,0x0000000000010000L});
	public static final BitSet FOLLOW_SEMI_in_classScopeDeclarations5986 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_typeDeclaration_in_classScopeDeclarations6031 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_SEMI_in_classScopeDeclarations6041 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_modifierList_in_interfaceScopeDeclarations6073 = new BitSet(new long[]{0x0020000214000000L,0x0000410020400010L,0x0001000000200000L});
	public static final BitSet FOLLOW_genericTypeParameterList_in_interfaceScopeDeclarations6087 = new BitSet(new long[]{0x0020000214000000L,0x0000400020400010L,0x0001000000200000L});
	public static final BitSet FOLLOW_type_in_interfaceScopeDeclarations6106 = new BitSet(new long[]{0x0000000000000000L,0x0000000000400000L});
	public static final BitSet FOLLOW_IDENT_in_interfaceScopeDeclarations6108 = new BitSet(new long[]{0x0000000000000000L,0x0000800000000000L});
	public static final BitSet FOLLOW_formalParameterList_in_interfaceScopeDeclarations6110 = new BitSet(new long[]{0x0000000000000000L,0x0000002000000000L,0x0000001000010000L});
	public static final BitSet FOLLOW_arrayDeclaratorList_in_interfaceScopeDeclarations6112 = new BitSet(new long[]{0x0000000000000000L,0x0000000000000000L,0x0000001000010000L});
	public static final BitSet FOLLOW_throwsClause_in_interfaceScopeDeclarations6115 = new BitSet(new long[]{0x0000000000000000L,0x0000000000000000L,0x0000000000010000L});
	public static final BitSet FOLLOW_SEMI_in_interfaceScopeDeclarations6118 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_VOID_in_interfaceScopeDeclarations6176 = new BitSet(new long[]{0x0000000000000000L,0x0000000000400000L});
	public static final BitSet FOLLOW_IDENT_in_interfaceScopeDeclarations6178 = new BitSet(new long[]{0x0000000000000000L,0x0000800000000000L});
	public static final BitSet FOLLOW_formalParameterList_in_interfaceScopeDeclarations6180 = new BitSet(new long[]{0x0000000000000000L,0x0000000000000000L,0x0000001000010000L});
	public static final BitSet FOLLOW_throwsClause_in_interfaceScopeDeclarations6182 = new BitSet(new long[]{0x0000000000000000L,0x0000000000000000L,0x0000000000010000L});
	public static final BitSet FOLLOW_SEMI_in_interfaceScopeDeclarations6185 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_type_in_interfaceScopeDeclarations6248 = new BitSet(new long[]{0x0000000000000000L,0x0000000000400000L});
	public static final BitSet FOLLOW_interfaceFieldDeclaratorList_in_interfaceScopeDeclarations6250 = new BitSet(new long[]{0x0000000000000000L,0x0000000000000000L,0x0000000000010000L});
	public static final BitSet FOLLOW_SEMI_in_interfaceScopeDeclarations6252 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_typeDeclaration_in_interfaceScopeDeclarations6297 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_SEMI_in_interfaceScopeDeclarations6307 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_classFieldDeclarator_in_classFieldDeclaratorList6327 = new BitSet(new long[]{0x0000020000000002L});
	public static final BitSet FOLLOW_COMMA_in_classFieldDeclaratorList6330 = new BitSet(new long[]{0x0000000000000000L,0x0000000000400000L});
	public static final BitSet FOLLOW_classFieldDeclarator_in_classFieldDeclaratorList6332 = new BitSet(new long[]{0x0000020000000002L});
	public static final BitSet FOLLOW_variableDeclaratorId_in_classFieldDeclarator6371 = new BitSet(new long[]{0x0000000000200002L});
	public static final BitSet FOLLOW_ASSIGN_in_classFieldDeclarator6374 = new BitSet(new long[]{0x0020600614000000L,0x1582D14028600032L,0x0001008218200002L});
	public static final BitSet FOLLOW_variableInitializer_in_classFieldDeclarator6376 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_interfaceFieldDeclarator_in_interfaceFieldDeclaratorList6421 = new BitSet(new long[]{0x0000020000000002L});
	public static final BitSet FOLLOW_COMMA_in_interfaceFieldDeclaratorList6424 = new BitSet(new long[]{0x0000000000000000L,0x0000000000400000L});
	public static final BitSet FOLLOW_interfaceFieldDeclarator_in_interfaceFieldDeclaratorList6426 = new BitSet(new long[]{0x0000020000000002L});
	public static final BitSet FOLLOW_variableDeclaratorId_in_interfaceFieldDeclarator6465 = new BitSet(new long[]{0x0000000000200000L});
	public static final BitSet FOLLOW_ASSIGN_in_interfaceFieldDeclarator6467 = new BitSet(new long[]{0x0020600614000000L,0x1582D14028600032L,0x0001008218200002L});
	public static final BitSet FOLLOW_variableInitializer_in_interfaceFieldDeclarator6469 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_IDENT_in_variableDeclaratorId6511 = new BitSet(new long[]{0x0000000000000002L,0x0000002000000000L});
	public static final BitSet FOLLOW_arrayDeclaratorList_in_variableDeclaratorId6514 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_arrayInitializer_in_variableInitializer6534 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_expression_in_variableInitializer6544 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_LBRACK_in_arrayDeclarator6563 = new BitSet(new long[]{0x0000000000000000L,0x0000000000000000L,0x0000000000001000L});
	public static final BitSet FOLLOW_RBRACK_in_arrayDeclarator6565 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_arrayDeclarator_in_arrayDeclaratorList6599 = new BitSet(new long[]{0x0000000000000002L,0x0000002000000000L});
	public static final BitSet FOLLOW_LCURLY_in_arrayInitializer6644 = new BitSet(new long[]{0x0020600614000000L,0x1582D14028600032L,0x0001008218202002L});
	public static final BitSet FOLLOW_variableInitializer_in_arrayInitializer6647 = new BitSet(new long[]{0x0000020000000000L,0x0000000000000000L,0x0000000000002000L});
	public static final BitSet FOLLOW_COMMA_in_arrayInitializer6650 = new BitSet(new long[]{0x0020600614000000L,0x1582D14028600032L,0x0001008218200002L});
	public static final BitSet FOLLOW_variableInitializer_in_arrayInitializer6652 = new BitSet(new long[]{0x0000020000000000L,0x0000000000000000L,0x0000000000002000L});
	public static final BitSet FOLLOW_COMMA_in_arrayInitializer6656 = new BitSet(new long[]{0x0000000000000000L,0x0000000000000000L,0x0000000000002000L});
	public static final BitSet FOLLOW_RCURLY_in_arrayInitializer6661 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_THROWS_in_throwsClause6699 = new BitSet(new long[]{0x0000000000000000L,0x0000000000400000L});
	public static final BitSet FOLLOW_qualifiedIdentList_in_throwsClause6701 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_modifier_in_modifierList6738 = new BitSet(new long[]{0x0000000000400012L,0x0040000000000004L,0x0004004105000380L});
	public static final BitSet FOLLOW_PUBLIC_in_modifier6779 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_PROTECTED_in_modifier6789 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_PRIVATE_in_modifier6799 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_STATIC_in_modifier6809 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_ABSTRACT_in_modifier6819 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_NATIVE_in_modifier6829 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_SYNCHRONIZED_in_modifier6839 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_TRANSIENT_in_modifier6849 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_VOLATILE_in_modifier6859 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_STRICTFP_in_modifier6869 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_localModifier_in_modifier6879 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_localModifier_in_localModifierList6898 = new BitSet(new long[]{0x0000000000400002L,0x0000000000000004L});
	public static final BitSet FOLLOW_FINAL_in_localModifier6939 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_annotation_in_localModifier6949 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_simpleType_in_type6968 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_objectType_in_type6978 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_primitiveType_in_simpleType6998 = new BitSet(new long[]{0x0000000000000002L,0x0000002000000000L});
	public static final BitSet FOLLOW_arrayDeclaratorList_in_simpleType7000 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_qualifiedTypeIdent_in_objectType7047 = new BitSet(new long[]{0x0000000000000002L,0x0000002000000000L});
	public static final BitSet FOLLOW_arrayDeclaratorList_in_objectType7049 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_qualifiedTypeIdentSimplified_in_objectTypeSimplified7089 = new BitSet(new long[]{0x0000000000000002L,0x0000002000000000L});
	public static final BitSet FOLLOW_arrayDeclaratorList_in_objectTypeSimplified7091 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_typeIdent_in_qualifiedTypeIdent7131 = new BitSet(new long[]{0x0008000000000002L});
	public static final BitSet FOLLOW_DOT_in_qualifiedTypeIdent7134 = new BitSet(new long[]{0x0000000000000000L,0x0000000000400000L});
	public static final BitSet FOLLOW_typeIdent_in_qualifiedTypeIdent7136 = new BitSet(new long[]{0x0008000000000002L});
	public static final BitSet FOLLOW_typeIdentSimplified_in_qualifiedTypeIdentSimplified7176 = new BitSet(new long[]{0x0008000000000002L});
	public static final BitSet FOLLOW_DOT_in_qualifiedTypeIdentSimplified7179 = new BitSet(new long[]{0x0000000000000000L,0x0000000000400000L});
	public static final BitSet FOLLOW_typeIdentSimplified_in_qualifiedTypeIdentSimplified7181 = new BitSet(new long[]{0x0008000000000002L});
	public static final BitSet FOLLOW_IDENT_in_typeIdent7221 = new BitSet(new long[]{0x0000000000000002L,0x0000010000000000L});
	public static final BitSet FOLLOW_genericTypeArgumentList_in_typeIdent7224 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_IDENT_in_typeIdentSimplified7244 = new BitSet(new long[]{0x0000000000000002L,0x0000010000000000L});
	public static final BitSet FOLLOW_genericTypeArgumentListSimplified_in_typeIdentSimplified7247 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_LESS_THAN_in_genericTypeArgumentList7356 = new BitSet(new long[]{0x0020000214000000L,0x0000400020400010L,0x0000000000200800L});
	public static final BitSet FOLLOW_genericTypeArgument_in_genericTypeArgumentList7358 = new BitSet(new long[]{0x0000020000800000L,0x0000000000080000L,0x0000000000080000L});
	public static final BitSet FOLLOW_COMMA_in_genericTypeArgumentList7361 = new BitSet(new long[]{0x0020000214000000L,0x0000400020400010L,0x0000000000200800L});
	public static final BitSet FOLLOW_genericTypeArgument_in_genericTypeArgumentList7363 = new BitSet(new long[]{0x0000020000800000L,0x0000000000080000L,0x0000000000080000L});
	public static final BitSet FOLLOW_genericTypeListClosing_in_genericTypeArgumentList7367 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_type_in_genericTypeArgument7405 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_QUESTION_in_genericTypeArgument7415 = new BitSet(new long[]{0x4000000000000002L,0x0000000000000000L,0x0000000010000000L});
	public static final BitSet FOLLOW_genericWildcardBoundType_in_genericTypeArgument7417 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_set_in_genericWildcardBoundType7459 = new BitSet(new long[]{0x0020000214000000L,0x0000400020400010L,0x0000000000200000L});
	public static final BitSet FOLLOW_type_in_genericWildcardBoundType7468 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_LESS_THAN_in_genericTypeArgumentListSimplified7487 = new BitSet(new long[]{0x0020000214000000L,0x0000400020400010L,0x0000000000200800L});
	public static final BitSet FOLLOW_genericTypeArgumentSimplified_in_genericTypeArgumentListSimplified7489 = new BitSet(new long[]{0x0000020000800000L,0x0000000000080000L,0x0000000000080000L});
	public static final BitSet FOLLOW_COMMA_in_genericTypeArgumentListSimplified7492 = new BitSet(new long[]{0x0020000214000000L,0x0000400020400010L,0x0000000000200800L});
	public static final BitSet FOLLOW_genericTypeArgumentSimplified_in_genericTypeArgumentListSimplified7494 = new BitSet(new long[]{0x0000020000800000L,0x0000000000080000L,0x0000000000080000L});
	public static final BitSet FOLLOW_genericTypeListClosing_in_genericTypeArgumentListSimplified7498 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_type_in_genericTypeArgumentSimplified7540 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_QUESTION_in_genericTypeArgumentSimplified7550 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_qualifiedIdentifier_in_qualifiedIdentList7573 = new BitSet(new long[]{0x0000020000000002L});
	public static final BitSet FOLLOW_COMMA_in_qualifiedIdentList7576 = new BitSet(new long[]{0x0000000000000000L,0x0000000000400000L});
	public static final BitSet FOLLOW_qualifiedIdentifier_in_qualifiedIdentList7579 = new BitSet(new long[]{0x0000020000000002L});
	public static final BitSet FOLLOW_LPAREN_in_formalParameterList7604 = new BitSet(new long[]{0x0020000214400000L,0x0000400020400014L,0x0000000000208000L});
	public static final BitSet FOLLOW_formalParameterStandardDecl_in_formalParameterList7632 = new BitSet(new long[]{0x0000020000000000L,0x0000000000000000L,0x0000000000008000L});
	public static final BitSet FOLLOW_COMMA_in_formalParameterList7635 = new BitSet(new long[]{0x0020000214400000L,0x0000400020400014L,0x0000000000200000L});
	public static final BitSet FOLLOW_formalParameterStandardDecl_in_formalParameterList7637 = new BitSet(new long[]{0x0000020000000000L,0x0000000000000000L,0x0000000000008000L});
	public static final BitSet FOLLOW_COMMA_in_formalParameterList7642 = new BitSet(new long[]{0x0020000214400000L,0x0000400020400014L,0x0000000000200000L});
	public static final BitSet FOLLOW_formalParameterVarArgDecl_in_formalParameterList7644 = new BitSet(new long[]{0x0000000000000000L,0x0000000000000000L,0x0000000000008000L});
	public static final BitSet FOLLOW_formalParameterVarArgDecl_in_formalParameterList7701 = new BitSet(new long[]{0x0000000000000000L,0x0000000000000000L,0x0000000000008000L});
	public static final BitSet FOLLOW_RPAREN_in_formalParameterList7778 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_localModifierList_in_formalParameterStandardDecl7801 = new BitSet(new long[]{0x0020000214000000L,0x0000400020400010L,0x0000000000200000L});
	public static final BitSet FOLLOW_type_in_formalParameterStandardDecl7803 = new BitSet(new long[]{0x0000000000000000L,0x0000000000400000L});
	public static final BitSet FOLLOW_variableDeclaratorId_in_formalParameterStandardDecl7805 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_localModifierList_in_formalParameterVarArgDecl7849 = new BitSet(new long[]{0x0020000214000000L,0x0000400020400010L,0x0000000000200000L});
	public static final BitSet FOLLOW_type_in_formalParameterVarArgDecl7851 = new BitSet(new long[]{0x0040000000000000L});
	public static final BitSet FOLLOW_ELLIPSIS_in_formalParameterVarArgDecl7853 = new BitSet(new long[]{0x0000000000000000L,0x0000000000400000L});
	public static final BitSet FOLLOW_variableDeclaratorId_in_formalParameterVarArgDecl7855 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_IDENT_in_qualifiedIdentifier7903 = new BitSet(new long[]{0x0008000000000002L});
	public static final BitSet FOLLOW_DOT_in_qualifiedIdentifier7946 = new BitSet(new long[]{0x0000000000000000L,0x0000000000400000L});
	public static final BitSet FOLLOW_IDENT_in_qualifiedIdentifier7950 = new BitSet(new long[]{0x0008000000000002L});
	public static final BitSet FOLLOW_annotation_in_annotationList8003 = new BitSet(new long[]{0x0000000000400002L});
	public static final BitSet FOLLOW_AT_in_annotation8041 = new BitSet(new long[]{0x0000000000000000L,0x0000000000400000L});
	public static final BitSet FOLLOW_qualifiedIdentifier_in_annotation8044 = new BitSet(new long[]{0x0000000000000002L,0x0000800000000000L});
	public static final BitSet FOLLOW_annotationInit_in_annotation8046 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_LPAREN_in_annotationInit8070 = new BitSet(new long[]{0x0020600614400000L,0x1582D14028600032L,0x0001008218200002L});
	public static final BitSet FOLLOW_annotationInitializers_in_annotationInit8072 = new BitSet(new long[]{0x0000000000000000L,0x0000000000000000L,0x0000000000008000L});
	public static final BitSet FOLLOW_RPAREN_in_annotationInit8074 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_annotationInitializer_in_annotationInitializers8111 = new BitSet(new long[]{0x0000020000000002L});
	public static final BitSet FOLLOW_COMMA_in_annotationInitializers8114 = new BitSet(new long[]{0x0000000000000000L,0x0000000000400000L});
	public static final BitSet FOLLOW_annotationInitializer_in_annotationInitializers8116 = new BitSet(new long[]{0x0000020000000002L});
	public static final BitSet FOLLOW_annotationElementValue_in_annotationInitializers8146 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_IDENT_in_annotationInitializer8187 = new BitSet(new long[]{0x0000000000200000L});
	public static final BitSet FOLLOW_ASSIGN_in_annotationInitializer8190 = new BitSet(new long[]{0x0020600614400000L,0x1582D14028600032L,0x0001008218200002L});
	public static final BitSet FOLLOW_annotationElementValue_in_annotationInitializer8193 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_annotationElementValueExpression_in_annotationElementValue8216 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_annotation_in_annotationElementValue8226 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_annotationElementValueArrayInitializer_in_annotationElementValue8236 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_conditionalExpression_in_annotationElementValueExpression8259 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_LCURLY_in_annotationElementValueArrayInitializer8299 = new BitSet(new long[]{0x0020620614400000L,0x1582D14028600032L,0x0001008218202002L});
	public static final BitSet FOLLOW_annotationElementValue_in_annotationElementValueArrayInitializer8302 = new BitSet(new long[]{0x0000020000000000L,0x0000000000000000L,0x0000000000002000L});
	public static final BitSet FOLLOW_COMMA_in_annotationElementValueArrayInitializer8305 = new BitSet(new long[]{0x0020600614400000L,0x1582D14028600032L,0x0001008218200002L});
	public static final BitSet FOLLOW_annotationElementValue_in_annotationElementValueArrayInitializer8307 = new BitSet(new long[]{0x0000020000000000L,0x0000000000000000L,0x0000000000002000L});
	public static final BitSet FOLLOW_COMMA_in_annotationElementValueArrayInitializer8314 = new BitSet(new long[]{0x0000000000000000L,0x0000000000000000L,0x0000000000002000L});
	public static final BitSet FOLLOW_RCURLY_in_annotationElementValueArrayInitializer8318 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_AT_in_annotationTypeDeclaration8361 = new BitSet(new long[]{0x0000000000000000L,0x0000000080000000L});
	public static final BitSet FOLLOW_INTERFACE_in_annotationTypeDeclaration8363 = new BitSet(new long[]{0x0000000000000000L,0x0000000000400000L});
	public static final BitSet FOLLOW_IDENT_in_annotationTypeDeclaration8365 = new BitSet(new long[]{0x0000000000000000L,0x0000004000000000L});
	public static final BitSet FOLLOW_annotationBody_in_annotationTypeDeclaration8367 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_LCURLY_in_annotationBody8410 = new BitSet(new long[]{0x0120000A14400010L,0x00404000A0400014L,0x0004004105202380L});
	public static final BitSet FOLLOW_annotationScopeDeclarations_in_annotationBody8412 = new BitSet(new long[]{0x0120000A14400010L,0x00404000A0400014L,0x0004004105202380L});
	public static final BitSet FOLLOW_RCURLY_in_annotationBody8415 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_modifierList_in_annotationScopeDeclarations8457 = new BitSet(new long[]{0x0020000214000000L,0x0000400020400010L,0x0000000000200000L});
	public static final BitSet FOLLOW_type_in_annotationScopeDeclarations8459 = new BitSet(new long[]{0x0000000000000000L,0x0000000000400000L});
	public static final BitSet FOLLOW_IDENT_in_annotationScopeDeclarations8473 = new BitSet(new long[]{0x0000000000000000L,0x0000800000000000L});
	public static final BitSet FOLLOW_LPAREN_in_annotationScopeDeclarations8475 = new BitSet(new long[]{0x0000000000000000L,0x0000000000000000L,0x0000000000008000L});
	public static final BitSet FOLLOW_RPAREN_in_annotationScopeDeclarations8477 = new BitSet(new long[]{0x0000800000000000L,0x0000000000000000L,0x0000000000010000L});
	public static final BitSet FOLLOW_annotationDefaultValue_in_annotationScopeDeclarations8479 = new BitSet(new long[]{0x0000000000000000L,0x0000000000000000L,0x0000000000010000L});
	public static final BitSet FOLLOW_SEMI_in_annotationScopeDeclarations8482 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_classFieldDeclaratorList_in_annotationScopeDeclarations8524 = new BitSet(new long[]{0x0000000000000000L,0x0000000000000000L,0x0000000000010000L});
	public static final BitSet FOLLOW_SEMI_in_annotationScopeDeclarations8526 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_typeDeclaration_in_annotationScopeDeclarations8571 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_DEFAULT_in_annotationDefaultValue8594 = new BitSet(new long[]{0x0020600614400000L,0x1582D14028600032L,0x0001008218200002L});
	public static final BitSet FOLLOW_annotationElementValue_in_annotationDefaultValue8597 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_LCURLY_in_block8618 = new BitSet(new long[]{0x0124700E1C500010L,0x15C2D140A8E000B6L,0x000D01CB5D216382L});
	public static final BitSet FOLLOW_blockStatement_in_block8620 = new BitSet(new long[]{0x0124700E1C500010L,0x15C2D140A8E000B6L,0x000D01CB5D216382L});
	public static final BitSet FOLLOW_RCURLY_in_block8623 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_localVariableDeclaration_in_blockStatement8661 = new BitSet(new long[]{0x0000000000000000L,0x0000000000000000L,0x0000000000010000L});
	public static final BitSet FOLLOW_SEMI_in_blockStatement8663 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_typeDeclaration_in_blockStatement8674 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_statement_in_blockStatement8684 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_localModifierList_in_localVariableDeclaration8707 = new BitSet(new long[]{0x0020000214000000L,0x0000400020400010L,0x0000000000200000L});
	public static final BitSet FOLLOW_type_in_localVariableDeclaration8709 = new BitSet(new long[]{0x0000000000000000L,0x0000000000400000L});
	public static final BitSet FOLLOW_classFieldDeclaratorList_in_localVariableDeclaration8711 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_block_in_statement8764 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_ASSERT_in_statement8774 = new BitSet(new long[]{0x0020600614000000L,0x1582D10028600032L,0x0001008218200002L});
	public static final BitSet FOLLOW_expression_in_statement8778 = new BitSet(new long[]{0x0000010000000000L,0x0000000000000000L,0x0000000000010000L});
	public static final BitSet FOLLOW_COLON_in_statement8793 = new BitSet(new long[]{0x0020600614000000L,0x1582D10028600032L,0x0001008218200002L});
	public static final BitSet FOLLOW_expression_in_statement8797 = new BitSet(new long[]{0x0000000000000000L,0x0000000000000000L,0x0000000000010000L});
	public static final BitSet FOLLOW_SEMI_in_statement8799 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_SEMI_in_statement8862 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_IF_in_statement8951 = new BitSet(new long[]{0x0000000000000000L,0x0000800000000000L});
	public static final BitSet FOLLOW_parenthesizedExpression_in_statement8953 = new BitSet(new long[]{0x002470061C100000L,0x1582D14028E000B2L,0x0009018B58214002L});
	public static final BitSet FOLLOW_statement_in_statement8957 = new BitSet(new long[]{0x0080000000000002L});
	public static final BitSet FOLLOW_ELSE_in_statement8972 = new BitSet(new long[]{0x002470061C100000L,0x1582D14028E000B2L,0x0009018B58214002L});
	public static final BitSet FOLLOW_statement_in_statement8976 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_FOR_in_statement9142 = new BitSet(new long[]{0x0000000000000000L,0x0000800000000000L});
	public static final BitSet FOLLOW_LPAREN_in_statement9144 = new BitSet(new long[]{0x0020600614400000L,0x1582D10028600036L,0x0001008218210002L});
	public static final BitSet FOLLOW_forInit_in_statement9159 = new BitSet(new long[]{0x0000000000000000L,0x0000000000000000L,0x0000000000010000L});
	public static final BitSet FOLLOW_SEMI_in_statement9161 = new BitSet(new long[]{0x0020600614000000L,0x1582D10028600032L,0x0001008218210002L});
	public static final BitSet FOLLOW_forCondition_in_statement9163 = new BitSet(new long[]{0x0000000000000000L,0x0000000000000000L,0x0000000000010000L});
	public static final BitSet FOLLOW_SEMI_in_statement9165 = new BitSet(new long[]{0x0020600614000000L,0x1582D10028600032L,0x0001008218208002L});
	public static final BitSet FOLLOW_forUpdater_in_statement9167 = new BitSet(new long[]{0x0000000000000000L,0x0000000000000000L,0x0000000000008000L});
	public static final BitSet FOLLOW_RPAREN_in_statement9169 = new BitSet(new long[]{0x002470061C100000L,0x1582D14028E000B2L,0x0009018B58214002L});
	public static final BitSet FOLLOW_statement_in_statement9171 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_localModifierList_in_statement9206 = new BitSet(new long[]{0x0020000214000000L,0x0000400020400010L,0x0000000000200000L});
	public static final BitSet FOLLOW_type_in_statement9208 = new BitSet(new long[]{0x0000000000000000L,0x0000000000400000L});
	public static final BitSet FOLLOW_IDENT_in_statement9210 = new BitSet(new long[]{0x0000010000000000L});
	public static final BitSet FOLLOW_COLON_in_statement9212 = new BitSet(new long[]{0x0020600614000000L,0x1582D10028600032L,0x0001008218200002L});
	public static final BitSet FOLLOW_expression_in_statement9214 = new BitSet(new long[]{0x0000000000000000L,0x0000000000000000L,0x0000000000008000L});
	public static final BitSet FOLLOW_RPAREN_in_statement9216 = new BitSet(new long[]{0x002470061C100000L,0x1582D14028E000B2L,0x0009018B58214002L});
	public static final BitSet FOLLOW_statement_in_statement9218 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_WHILE_in_statement9333 = new BitSet(new long[]{0x0000000000000000L,0x0000800000000000L});
	public static final BitSet FOLLOW_parenthesizedExpression_in_statement9335 = new BitSet(new long[]{0x002470061C100000L,0x1582D14028E000B2L,0x0009018B58214002L});
	public static final BitSet FOLLOW_statement_in_statement9337 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_DO_in_statement9386 = new BitSet(new long[]{0x002470061C100000L,0x1582D14028E000B2L,0x0009018B58214002L});
	public static final BitSet FOLLOW_statement_in_statement9388 = new BitSet(new long[]{0x0000000000000000L,0x0000000000000000L,0x0008000000000000L});
	public static final BitSet FOLLOW_WHILE_in_statement9390 = new BitSet(new long[]{0x0000000000000000L,0x0000800000000000L});
	public static final BitSet FOLLOW_parenthesizedExpression_in_statement9392 = new BitSet(new long[]{0x0000000000000000L,0x0000000000000000L,0x0000000000010000L});
	public static final BitSet FOLLOW_SEMI_in_statement9394 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_TRY_in_statement9435 = new BitSet(new long[]{0x0000000000000000L,0x0000004000000000L});
	public static final BitSet FOLLOW_block_in_statement9437 = new BitSet(new long[]{0x0000000080000000L,0x0000000000000008L});
	public static final BitSet FOLLOW_catches_in_statement9440 = new BitSet(new long[]{0x0000000000000002L,0x0000000000000008L});
	public static final BitSet FOLLOW_finallyClause_in_statement9442 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_finallyClause_in_statement9447 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_SWITCH_in_statement9490 = new BitSet(new long[]{0x0000000000000000L,0x0000800000000000L});
	public static final BitSet FOLLOW_parenthesizedExpression_in_statement9492 = new BitSet(new long[]{0x0000000000000000L,0x0000004000000000L});
	public static final BitSet FOLLOW_LCURLY_in_statement9494 = new BitSet(new long[]{0x0000800020000000L});
	public static final BitSet FOLLOW_switchBlockLabels_in_statement9496 = new BitSet(new long[]{0x0000000000000000L,0x0000000000000000L,0x0000000000002000L});
	public static final BitSet FOLLOW_RCURLY_in_statement9498 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_SYNCHRONIZED_in_statement9524 = new BitSet(new long[]{0x0000000000000000L,0x0000800000000000L});
	public static final BitSet FOLLOW_parenthesizedExpression_in_statement9526 = new BitSet(new long[]{0x0000000000000000L,0x0000004000000000L});
	public static final BitSet FOLLOW_block_in_statement9528 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_RETURN_in_statement9574 = new BitSet(new long[]{0x0020600614000000L,0x1582D10028600032L,0x0001008218210002L});
	public static final BitSet FOLLOW_expression_in_statement9576 = new BitSet(new long[]{0x0000000000000000L,0x0000000000000000L,0x0000000000010000L});
	public static final BitSet FOLLOW_SEMI_in_statement9579 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_THROW_in_statement9643 = new BitSet(new long[]{0x0020600614000000L,0x1582D10028600032L,0x0001008218200002L});
	public static final BitSet FOLLOW_expression_in_statement9645 = new BitSet(new long[]{0x0000000000000000L,0x0000000000000000L,0x0000000000010000L});
	public static final BitSet FOLLOW_SEMI_in_statement9647 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_BREAK_in_statement9712 = new BitSet(new long[]{0x0000000000000000L,0x0000000000400000L,0x0000000000010000L});
	public static final BitSet FOLLOW_IDENT_in_statement9714 = new BitSet(new long[]{0x0000000000000000L,0x0000000000000000L,0x0000000000010000L});
	public static final BitSet FOLLOW_SEMI_in_statement9717 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_CONTINUE_in_statement9787 = new BitSet(new long[]{0x0000000000000000L,0x0000000000400000L,0x0000000000010000L});
	public static final BitSet FOLLOW_IDENT_in_statement9789 = new BitSet(new long[]{0x0000000000000000L,0x0000000000000000L,0x0000000000010000L});
	public static final BitSet FOLLOW_SEMI_in_statement9792 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_IDENT_in_statement9859 = new BitSet(new long[]{0x0000010000000000L});
	public static final BitSet FOLLOW_COLON_in_statement9861 = new BitSet(new long[]{0x002470061C100000L,0x1582D14028E000B2L,0x0009018B58214002L});
	public static final BitSet FOLLOW_statement_in_statement9863 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_expression_in_statement9930 = new BitSet(new long[]{0x0000000000000000L,0x0000000000000000L,0x0000000000010000L});
	public static final BitSet FOLLOW_SEMI_in_statement9932 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_SEMI_in_statement9943 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_catchClause_in_catches9982 = new BitSet(new long[]{0x0000000080000002L});
	public static final BitSet FOLLOW_CATCH_in_catchClause10024 = new BitSet(new long[]{0x0000000000000000L,0x0000800000000000L});
	public static final BitSet FOLLOW_LPAREN_in_catchClause10027 = new BitSet(new long[]{0x0020000214400000L,0x0000400020400014L,0x0000000000200000L});
	public static final BitSet FOLLOW_formalParameterStandardDecl_in_catchClause10030 = new BitSet(new long[]{0x0000000000000000L,0x0000000000000000L,0x0000000000008000L});
	public static final BitSet FOLLOW_RPAREN_in_catchClause10032 = new BitSet(new long[]{0x0000000000000000L,0x0000004000000000L});
	public static final BitSet FOLLOW_block_in_catchClause10035 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_FINALLY_in_finallyClause10054 = new BitSet(new long[]{0x0000000000000000L,0x0000004000000000L});
	public static final BitSet FOLLOW_block_in_finallyClause10056 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_switchCaseLabels_in_switchBlockLabels10088 = new BitSet(new long[]{0x0000800020000000L});
	public static final BitSet FOLLOW_switchDefaultLabel_in_switchBlockLabels10090 = new BitSet(new long[]{0x0000000020000000L});
	public static final BitSet FOLLOW_switchCaseLabels_in_switchBlockLabels10093 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_switchCaseLabel_in_switchCaseLabels10138 = new BitSet(new long[]{0x0000000020000002L});
	public static final BitSet FOLLOW_CASE_in_switchCaseLabel10166 = new BitSet(new long[]{0x0020600614000000L,0x1582D10028600032L,0x0001008218200002L});
	public static final BitSet FOLLOW_expression_in_switchCaseLabel10169 = new BitSet(new long[]{0x0000010000000000L});
	public static final BitSet FOLLOW_COLON_in_switchCaseLabel10171 = new BitSet(new long[]{0x0124700E1C500012L,0x15C2D140A8E000B6L,0x000D01CB5D214382L});
	public static final BitSet FOLLOW_blockStatement_in_switchCaseLabel10174 = new BitSet(new long[]{0x0124700E1C500012L,0x15C2D140A8E000B6L,0x000D01CB5D214382L});
	public static final BitSet FOLLOW_DEFAULT_in_switchDefaultLabel10198 = new BitSet(new long[]{0x0000010000000000L});
	public static final BitSet FOLLOW_COLON_in_switchDefaultLabel10201 = new BitSet(new long[]{0x0124700E1C500012L,0x15C2D140A8E000B6L,0x000D01CB5D214382L});
	public static final BitSet FOLLOW_blockStatement_in_switchDefaultLabel10204 = new BitSet(new long[]{0x0124700E1C500012L,0x15C2D140A8E000B6L,0x000D01CB5D214382L});
	public static final BitSet FOLLOW_localVariableDeclaration_in_forInit10228 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_expressionList_in_forInit10250 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_expression_in_forCondition10338 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_expressionList_in_forUpdater10380 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_LPAREN_in_parenthesizedExpression10420 = new BitSet(new long[]{0x0020600614000000L,0x1582D10028600032L,0x0001008218200002L});
	public static final BitSet FOLLOW_expression_in_parenthesizedExpression10422 = new BitSet(new long[]{0x0000000000000000L,0x0000000000000000L,0x0000000000008000L});
	public static final BitSet FOLLOW_RPAREN_in_parenthesizedExpression10424 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_expression_in_expressionList10465 = new BitSet(new long[]{0x0000020000000002L});
	public static final BitSet FOLLOW_COMMA_in_expressionList10468 = new BitSet(new long[]{0x0020600614000000L,0x1582D10028600032L,0x0001008218200002L});
	public static final BitSet FOLLOW_expression_in_expressionList10471 = new BitSet(new long[]{0x0000020000000002L});
	public static final BitSet FOLLOW_assignmentExpression_in_expression10492 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_conditionalExpression_in_assignmentExpression10528 = new BitSet(new long[]{0x0002000001200042L,0x4024000000000000L,0x0040000000940004L});
	public static final BitSet FOLLOW_ASSIGN_in_assignmentExpression10547 = new BitSet(new long[]{0x0020600614000000L,0x1582D10028600032L,0x0001008218200002L});
	public static final BitSet FOLLOW_PLUS_ASSIGN_in_assignmentExpression10566 = new BitSet(new long[]{0x0020600614000000L,0x1582D10028600032L,0x0001008218200002L});
	public static final BitSet FOLLOW_MINUS_ASSIGN_in_assignmentExpression10585 = new BitSet(new long[]{0x0020600614000000L,0x1582D10028600032L,0x0001008218200002L});
	public static final BitSet FOLLOW_STAR_ASSIGN_in_assignmentExpression10604 = new BitSet(new long[]{0x0020600614000000L,0x1582D10028600032L,0x0001008218200002L});
	public static final BitSet FOLLOW_DIV_ASSIGN_in_assignmentExpression10623 = new BitSet(new long[]{0x0020600614000000L,0x1582D10028600032L,0x0001008218200002L});
	public static final BitSet FOLLOW_AND_ASSIGN_in_assignmentExpression10642 = new BitSet(new long[]{0x0020600614000000L,0x1582D10028600032L,0x0001008218200002L});
	public static final BitSet FOLLOW_OR_ASSIGN_in_assignmentExpression10661 = new BitSet(new long[]{0x0020600614000000L,0x1582D10028600032L,0x0001008218200002L});
	public static final BitSet FOLLOW_XOR_ASSIGN_in_assignmentExpression10680 = new BitSet(new long[]{0x0020600614000000L,0x1582D10028600032L,0x0001008218200002L});
	public static final BitSet FOLLOW_MOD_ASSIGN_in_assignmentExpression10699 = new BitSet(new long[]{0x0020600614000000L,0x1582D10028600032L,0x0001008218200002L});
	public static final BitSet FOLLOW_SHIFT_LEFT_ASSIGN_in_assignmentExpression10718 = new BitSet(new long[]{0x0020600614000000L,0x1582D10028600032L,0x0001008218200002L});
	public static final BitSet FOLLOW_SHIFT_RIGHT_ASSIGN_in_assignmentExpression10737 = new BitSet(new long[]{0x0020600614000000L,0x1582D10028600032L,0x0001008218200002L});
	public static final BitSet FOLLOW_BIT_SHIFT_RIGHT_ASSIGN_in_assignmentExpression10756 = new BitSet(new long[]{0x0020600614000000L,0x1582D10028600032L,0x0001008218200002L});
	public static final BitSet FOLLOW_assignmentExpression_in_assignmentExpression10778 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_logicalOrExpression_in_conditionalExpression10803 = new BitSet(new long[]{0x0000000000000002L,0x0000000000000000L,0x0000000000000800L});
	public static final BitSet FOLLOW_QUESTION_in_conditionalExpression10806 = new BitSet(new long[]{0x0020600614000000L,0x1582D10028600032L,0x0001008218200002L});
	public static final BitSet FOLLOW_assignmentExpression_in_conditionalExpression10809 = new BitSet(new long[]{0x0000010000000000L});
	public static final BitSet FOLLOW_COLON_in_conditionalExpression10811 = new BitSet(new long[]{0x0020600614000000L,0x1582D10028600032L,0x0001008218200002L});
	public static final BitSet FOLLOW_conditionalExpression_in_conditionalExpression10814 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_logicalAndExpression_in_logicalOrExpression10835 = new BitSet(new long[]{0x0000000000000002L,0x0000200000000000L});
	public static final BitSet FOLLOW_LOGICAL_OR_in_logicalOrExpression10838 = new BitSet(new long[]{0x0020600614000000L,0x1582D10028600032L,0x0001008218200002L});
	public static final BitSet FOLLOW_logicalAndExpression_in_logicalOrExpression10841 = new BitSet(new long[]{0x0000000000000002L,0x0000200000000000L});
	public static final BitSet FOLLOW_inclusiveOrExpression_in_logicalAndExpression10862 = new BitSet(new long[]{0x0000000000000002L,0x0000080000000000L});
	public static final BitSet FOLLOW_LOGICAL_AND_in_logicalAndExpression10865 = new BitSet(new long[]{0x0020600614000000L,0x1582D10028600032L,0x0001008218200002L});
	public static final BitSet FOLLOW_inclusiveOrExpression_in_logicalAndExpression10868 = new BitSet(new long[]{0x0000000000000002L,0x0000080000000000L});
	public static final BitSet FOLLOW_exclusiveOrExpression_in_inclusiveOrExpression10889 = new BitSet(new long[]{0x0000000000000002L,0x2000000000000000L});
	public static final BitSet FOLLOW_OR_in_inclusiveOrExpression10892 = new BitSet(new long[]{0x0020600614000000L,0x1582D10028600032L,0x0001008218200002L});
	public static final BitSet FOLLOW_exclusiveOrExpression_in_inclusiveOrExpression10895 = new BitSet(new long[]{0x0000000000000002L,0x2000000000000000L});
	public static final BitSet FOLLOW_andExpression_in_exclusiveOrExpression10916 = new BitSet(new long[]{0x0000000000000002L,0x0000000000000000L,0x0020000000000000L});
	public static final BitSet FOLLOW_XOR_in_exclusiveOrExpression10919 = new BitSet(new long[]{0x0020600614000000L,0x1582D10028600032L,0x0001008218200002L});
	public static final BitSet FOLLOW_andExpression_in_exclusiveOrExpression10922 = new BitSet(new long[]{0x0000000000000002L,0x0000000000000000L,0x0020000000000000L});
	public static final BitSet FOLLOW_equalityExpression_in_andExpression10943 = new BitSet(new long[]{0x0000000000000022L});
	public static final BitSet FOLLOW_AND_in_andExpression10946 = new BitSet(new long[]{0x0020600614000000L,0x1582D10028600032L,0x0001008218200002L});
	public static final BitSet FOLLOW_equalityExpression_in_andExpression10949 = new BitSet(new long[]{0x0000000000000022L});
	public static final BitSet FOLLOW_instanceOfExpression_in_equalityExpression10970 = new BitSet(new long[]{0x0400000000000002L,0x0200000000000000L});
	public static final BitSet FOLLOW_EQUAL_in_equalityExpression10989 = new BitSet(new long[]{0x0020600614000000L,0x1582D10028600032L,0x0001008218200002L});
	public static final BitSet FOLLOW_NOT_EQUAL_in_equalityExpression11008 = new BitSet(new long[]{0x0020600614000000L,0x1582D10028600032L,0x0001008218200002L});
	public static final BitSet FOLLOW_instanceOfExpression_in_equalityExpression11038 = new BitSet(new long[]{0x0400000000000002L,0x0200000000000000L});
	public static final BitSet FOLLOW_relationalExpression_in_instanceOfExpression11068 = new BitSet(new long[]{0x0000000000000002L,0x0000000010000000L});
	public static final BitSet FOLLOW_INSTANCEOF_in_instanceOfExpression11071 = new BitSet(new long[]{0x0020000214000000L,0x0000400020400010L,0x0000000000200000L});
	public static final BitSet FOLLOW_type_in_instanceOfExpression11074 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_shiftExpression_in_relationalExpression11095 = new BitSet(new long[]{0x0000000000000002L,0x00000180000C0000L});
	public static final BitSet FOLLOW_LESS_OR_EQUAL_in_relationalExpression11114 = new BitSet(new long[]{0x0020600614000000L,0x1582D10028600032L,0x0001008218200002L});
	public static final BitSet FOLLOW_GREATER_OR_EQUAL_in_relationalExpression11133 = new BitSet(new long[]{0x0020600614000000L,0x1582D10028600032L,0x0001008218200002L});
	public static final BitSet FOLLOW_LESS_THAN_in_relationalExpression11152 = new BitSet(new long[]{0x0020600614000000L,0x1582D10028600032L,0x0001008218200002L});
	public static final BitSet FOLLOW_GREATER_THAN_in_relationalExpression11171 = new BitSet(new long[]{0x0020600614000000L,0x1582D10028600032L,0x0001008218200002L});
	public static final BitSet FOLLOW_shiftExpression_in_relationalExpression11200 = new BitSet(new long[]{0x0000000000000002L,0x00000180000C0000L});
	public static final BitSet FOLLOW_additiveExpression_in_shiftExpression11234 = new BitSet(new long[]{0x0000000000800002L,0x0000000000000000L,0x00000000000A0000L});
	public static final BitSet FOLLOW_BIT_SHIFT_RIGHT_in_shiftExpression11252 = new BitSet(new long[]{0x0020600614000000L,0x1582D10028600032L,0x0001008218200002L});
	public static final BitSet FOLLOW_SHIFT_RIGHT_in_shiftExpression11271 = new BitSet(new long[]{0x0020600614000000L,0x1582D10028600032L,0x0001008218200002L});
	public static final BitSet FOLLOW_SHIFT_LEFT_in_shiftExpression11290 = new BitSet(new long[]{0x0020600614000000L,0x1582D10028600032L,0x0001008218200002L});
	public static final BitSet FOLLOW_additiveExpression_in_shiftExpression11319 = new BitSet(new long[]{0x0000000000800002L,0x0000000000000000L,0x00000000000A0000L});
	public static final BitSet FOLLOW_multiplicativeExpression_in_additiveExpression11349 = new BitSet(new long[]{0x0000000000000002L,0x0002000000000000L,0x0000000000000002L});
	public static final BitSet FOLLOW_PLUS_in_additiveExpression11367 = new BitSet(new long[]{0x0020600614000000L,0x1582D10028600032L,0x0001008218200002L});
	public static final BitSet FOLLOW_MINUS_in_additiveExpression11386 = new BitSet(new long[]{0x0020600614000000L,0x1582D10028600032L,0x0001008218200002L});
	public static final BitSet FOLLOW_multiplicativeExpression_in_additiveExpression11415 = new BitSet(new long[]{0x0000000000000002L,0x0002000000000000L,0x0000000000000002L});
	public static final BitSet FOLLOW_unaryExpression_in_multiplicativeExpression11445 = new BitSet(new long[]{0x0001000000000002L,0x0008000000000000L,0x0000000000400000L});
	public static final BitSet FOLLOW_STAR_in_multiplicativeExpression11464 = new BitSet(new long[]{0x0020600614000000L,0x1582D10028600032L,0x0001008218200002L});
	public static final BitSet FOLLOW_DIV_in_multiplicativeExpression11483 = new BitSet(new long[]{0x0020600614000000L,0x1582D10028600032L,0x0001008218200002L});
	public static final BitSet FOLLOW_MOD_in_multiplicativeExpression11502 = new BitSet(new long[]{0x0020600614000000L,0x1582D10028600032L,0x0001008218200002L});
	public static final BitSet FOLLOW_unaryExpression_in_multiplicativeExpression11531 = new BitSet(new long[]{0x0001000000000002L,0x0008000000000000L,0x0000000000400000L});
	public static final BitSet FOLLOW_PLUS_in_unaryExpression11565 = new BitSet(new long[]{0x0020600614000000L,0x1582D10028600032L,0x0001008218200002L});
	public static final BitSet FOLLOW_unaryExpression_in_unaryExpression11567 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_MINUS_in_unaryExpression11594 = new BitSet(new long[]{0x0020600614000000L,0x1582D10028600032L,0x0001008218200002L});
	public static final BitSet FOLLOW_unaryExpression_in_unaryExpression11596 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_INC_in_unaryExpression11622 = new BitSet(new long[]{0x0020400614000000L,0x1480C10020600032L,0x0001008218200000L});
	public static final BitSet FOLLOW_postfixedExpression_in_unaryExpression11624 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_DEC_in_unaryExpression11648 = new BitSet(new long[]{0x0020400614000000L,0x1480C10020600032L,0x0001008218200000L});
	public static final BitSet FOLLOW_postfixedExpression_in_unaryExpression11650 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_unaryExpressionNotPlusMinus_in_unaryExpression11674 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_NOT_in_unaryExpressionNotPlusMinus11693 = new BitSet(new long[]{0x0020600614000000L,0x1582D10028600032L,0x0001008218200002L});
	public static final BitSet FOLLOW_unaryExpression_in_unaryExpressionNotPlusMinus11695 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_LOGICAL_NOT_in_unaryExpressionNotPlusMinus11742 = new BitSet(new long[]{0x0020600614000000L,0x1582D10028600032L,0x0001008218200002L});
	public static final BitSet FOLLOW_unaryExpression_in_unaryExpressionNotPlusMinus11744 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_LPAREN_in_unaryExpressionNotPlusMinus11783 = new BitSet(new long[]{0x0020000214000000L,0x0000400020400010L,0x0000000000200000L});
	public static final BitSet FOLLOW_type_in_unaryExpressionNotPlusMinus11785 = new BitSet(new long[]{0x0000000000000000L,0x0000000000000000L,0x0000000000008000L});
	public static final BitSet FOLLOW_RPAREN_in_unaryExpressionNotPlusMinus11787 = new BitSet(new long[]{0x0020600614000000L,0x1582D10028600032L,0x0001008218200002L});
	public static final BitSet FOLLOW_unaryExpression_in_unaryExpressionNotPlusMinus11789 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_postfixedExpression_in_unaryExpressionNotPlusMinus11824 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_primaryExpression_in_postfixedExpression11860 = new BitSet(new long[]{0x0008200000000002L,0x0000002008000000L});
	public static final BitSet FOLLOW_DOT_in_postfixedExpression11922 = new BitSet(new long[]{0x0000000000000000L,0x0080010000400000L,0x0000000210000000L});
	public static final BitSet FOLLOW_genericTypeArgumentListSimplified_in_postfixedExpression11972 = new BitSet(new long[]{0x0000000000000000L,0x0000000000400000L});
	public static final BitSet FOLLOW_IDENT_in_postfixedExpression12054 = new BitSet(new long[]{0x0008200000000002L,0x0000802008000000L});
	public static final BitSet FOLLOW_arguments_in_postfixedExpression12133 = new BitSet(new long[]{0x0008200000000002L,0x0000002008000000L});
	public static final BitSet FOLLOW_THIS_in_postfixedExpression12207 = new BitSet(new long[]{0x0008200000000002L,0x0000002008000000L});
	public static final BitSet FOLLOW_SUPER_in_postfixedExpression12270 = new BitSet(new long[]{0x0000000000000000L,0x0000800000000000L});
	public static final BitSet FOLLOW_arguments_in_postfixedExpression12272 = new BitSet(new long[]{0x0008200000000002L,0x0000002008000000L});
	public static final BitSet FOLLOW_SUPER_in_postfixedExpression12325 = new BitSet(new long[]{0x0008000000000000L});
	public static final BitSet FOLLOW_DOT_in_postfixedExpression12329 = new BitSet(new long[]{0x0000000000000000L,0x0000000000400000L});
	public static final BitSet FOLLOW_IDENT_in_postfixedExpression12331 = new BitSet(new long[]{0x0008200000000002L,0x0000802008000000L});
	public static final BitSet FOLLOW_arguments_in_postfixedExpression12398 = new BitSet(new long[]{0x0008200000000002L,0x0000002008000000L});
	public static final BitSet FOLLOW_innerNewExpression_in_postfixedExpression12469 = new BitSet(new long[]{0x0008200000000002L,0x0000002008000000L});
	public static final BitSet FOLLOW_LBRACK_in_postfixedExpression12526 = new BitSet(new long[]{0x0020600614000000L,0x1582D10028600032L,0x0001008218200002L});
	public static final BitSet FOLLOW_expression_in_postfixedExpression12528 = new BitSet(new long[]{0x0000000000000000L,0x0000000000000000L,0x0000000000001000L});
	public static final BitSet FOLLOW_RBRACK_in_postfixedExpression12530 = new BitSet(new long[]{0x0008200000000002L,0x0000002008000000L});
	public static final BitSet FOLLOW_INC_in_postfixedExpression12591 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_DEC_in_postfixedExpression12615 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_parenthesizedExpression_in_primaryExpression12663 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_literal_in_primaryExpression12673 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_newExpression_in_primaryExpression12683 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_qualifiedIdentExpression_in_primaryExpression12693 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_genericTypeArgumentListSimplified_in_primaryExpression12703 = new BitSet(new long[]{0x0000000000000000L,0x0000000000400000L,0x0000000210000000L});
	public static final BitSet FOLLOW_SUPER_in_primaryExpression12718 = new BitSet(new long[]{0x0008000000000000L,0x0000800000000000L});
	public static final BitSet FOLLOW_arguments_in_primaryExpression12736 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_DOT_in_primaryExpression12796 = new BitSet(new long[]{0x0000000000000000L,0x0000000000400000L});
	public static final BitSet FOLLOW_IDENT_in_primaryExpression12798 = new BitSet(new long[]{0x0000000000000000L,0x0000800000000000L});
	public static final BitSet FOLLOW_arguments_in_primaryExpression12800 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_IDENT_in_primaryExpression12867 = new BitSet(new long[]{0x0000000000000000L,0x0000800000000000L});
	public static final BitSet FOLLOW_arguments_in_primaryExpression12869 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_THIS_in_primaryExpression12924 = new BitSet(new long[]{0x0000000000000000L,0x0000800000000000L});
	public static final BitSet FOLLOW_arguments_in_primaryExpression12926 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_THIS_in_primaryExpression12991 = new BitSet(new long[]{0x0000000000000002L,0x0000800000000000L});
	public static final BitSet FOLLOW_arguments_in_primaryExpression13059 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_SUPER_in_primaryExpression13124 = new BitSet(new long[]{0x0000000000000000L,0x0000800000000000L});
	public static final BitSet FOLLOW_arguments_in_primaryExpression13126 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_SUPER_in_primaryExpression13182 = new BitSet(new long[]{0x0008000000000000L});
	public static final BitSet FOLLOW_DOT_in_primaryExpression13184 = new BitSet(new long[]{0x0000000000000000L,0x0000000000400000L});
	public static final BitSet FOLLOW_IDENT_in_primaryExpression13186 = new BitSet(new long[]{0x0000000000000002L,0x0000800000000000L});
	public static final BitSet FOLLOW_arguments_in_primaryExpression13210 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_primitiveType_in_primaryExpression13352 = new BitSet(new long[]{0x0008000000000000L,0x0000002000000000L});
	public static final BitSet FOLLOW_arrayDeclarator_in_primaryExpression13411 = new BitSet(new long[]{0x0008000000000000L,0x0000002000000000L});
	public static final BitSet FOLLOW_DOT_in_primaryExpression13474 = new BitSet(new long[]{0x0000000800000000L});
	public static final BitSet FOLLOW_CLASS_in_primaryExpression13476 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_VOID_in_primaryExpression13536 = new BitSet(new long[]{0x0008000000000000L});
	public static final BitSet FOLLOW_DOT_in_primaryExpression13538 = new BitSet(new long[]{0x0000000800000000L});
	public static final BitSet FOLLOW_CLASS_in_primaryExpression13540 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_qualifiedIdentifier_in_qualifiedIdentExpression13620 = new BitSet(new long[]{0x0008000000000002L,0x0000802000000000L});
	public static final BitSet FOLLOW_arrayDeclarator_in_qualifiedIdentExpression13690 = new BitSet(new long[]{0x0008000000000000L,0x0000002000000000L});
	public static final BitSet FOLLOW_DOT_in_qualifiedIdentExpression13758 = new BitSet(new long[]{0x0000000800000000L});
	public static final BitSet FOLLOW_CLASS_in_qualifiedIdentExpression13760 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_arguments_in_qualifiedIdentExpression13830 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_DOT_in_qualifiedIdentExpression13891 = new BitSet(new long[]{0x0000000800000000L,0x0080010000000000L,0x0000000210000000L});
	public static final BitSet FOLLOW_CLASS_in_qualifiedIdentExpression13909 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_genericTypeArgumentListSimplified_in_qualifiedIdentExpression13972 = new BitSet(new long[]{0x0000000000000000L,0x0000000000400000L,0x0000000010000000L});
	public static final BitSet FOLLOW_SUPER_in_qualifiedIdentExpression13997 = new BitSet(new long[]{0x0000000000000000L,0x0000800000000000L});
	public static final BitSet FOLLOW_arguments_in_qualifiedIdentExpression13999 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_SUPER_in_qualifiedIdentExpression14049 = new BitSet(new long[]{0x0008000000000000L});
	public static final BitSet FOLLOW_DOT_in_qualifiedIdentExpression14053 = new BitSet(new long[]{0x0000000000000000L,0x0000000000400000L});
	public static final BitSet FOLLOW_IDENT_in_qualifiedIdentExpression14055 = new BitSet(new long[]{0x0000000000000000L,0x0000800000000000L});
	public static final BitSet FOLLOW_arguments_in_qualifiedIdentExpression14057 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_IDENT_in_qualifiedIdentExpression14107 = new BitSet(new long[]{0x0000000000000000L,0x0000800000000000L});
	public static final BitSet FOLLOW_arguments_in_qualifiedIdentExpression14109 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_THIS_in_qualifiedIdentExpression14184 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_SUPER_in_qualifiedIdentExpression14250 = new BitSet(new long[]{0x0000000000000000L,0x0000800000000000L});
	public static final BitSet FOLLOW_arguments_in_qualifiedIdentExpression14252 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_innerNewExpression_in_qualifiedIdentExpression14300 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_NEW_in_newExpression14376 = new BitSet(new long[]{0x0020000214000000L,0x0000410020400010L,0x0000000000200000L});
	public static final BitSet FOLLOW_primitiveType_in_newExpression14392 = new BitSet(new long[]{0x0000000000000000L,0x0000002000000000L});
	public static final BitSet FOLLOW_newArrayConstruction_in_newExpression14394 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_genericTypeArgumentListSimplified_in_newExpression14438 = new BitSet(new long[]{0x0000000000000000L,0x0000000000400000L});
	public static final BitSet FOLLOW_qualifiedTypeIdentSimplified_in_newExpression14441 = new BitSet(new long[]{0x0000000000000000L,0x0000802000000000L});
	public static final BitSet FOLLOW_newArrayConstruction_in_newExpression14459 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_arguments_in_newExpression14524 = new BitSet(new long[]{0x0000000000000002L,0x0000004000000000L});
	public static final BitSet FOLLOW_classBody_in_newExpression14526 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_NEW_in_innerNewExpression14625 = new BitSet(new long[]{0x0000000000000000L,0x0000010000400000L});
	public static final BitSet FOLLOW_genericTypeArgumentListSimplified_in_innerNewExpression14627 = new BitSet(new long[]{0x0000000000000000L,0x0000000000400000L});
	public static final BitSet FOLLOW_IDENT_in_innerNewExpression14630 = new BitSet(new long[]{0x0000000000000000L,0x0000800000000000L});
	public static final BitSet FOLLOW_arguments_in_innerNewExpression14632 = new BitSet(new long[]{0x0000000000000002L,0x0000004000000000L});
	public static final BitSet FOLLOW_classBody_in_innerNewExpression14634 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_arrayDeclaratorList_in_newArrayConstruction14680 = new BitSet(new long[]{0x0000000000000000L,0x0000004000000000L});
	public static final BitSet FOLLOW_arrayInitializer_in_newArrayConstruction14682 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_LBRACK_in_newArrayConstruction14692 = new BitSet(new long[]{0x0020600614000000L,0x1582D10028600032L,0x0001008218200002L});
	public static final BitSet FOLLOW_expression_in_newArrayConstruction14695 = new BitSet(new long[]{0x0000000000000000L,0x0000000000000000L,0x0000000000001000L});
	public static final BitSet FOLLOW_RBRACK_in_newArrayConstruction14697 = new BitSet(new long[]{0x0000000000000002L,0x0000002000000000L});
	public static final BitSet FOLLOW_LBRACK_in_newArrayConstruction14701 = new BitSet(new long[]{0x0020600614000000L,0x1582D10028600032L,0x0001008218200002L});
	public static final BitSet FOLLOW_expression_in_newArrayConstruction14704 = new BitSet(new long[]{0x0000000000000000L,0x0000000000000000L,0x0000000000001000L});
	public static final BitSet FOLLOW_RBRACK_in_newArrayConstruction14706 = new BitSet(new long[]{0x0000000000000002L,0x0000002000000000L});
	public static final BitSet FOLLOW_arrayDeclaratorList_in_newArrayConstruction14711 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_LPAREN_in_arguments14731 = new BitSet(new long[]{0x0020600614000000L,0x1582D10028600032L,0x0001008218208002L});
	public static final BitSet FOLLOW_expressionList_in_arguments14733 = new BitSet(new long[]{0x0000000000000000L,0x0000000000000000L,0x0000000000008000L});
	public static final BitSet FOLLOW_RPAREN_in_arguments14736 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_GREATER_THAN_in_synpred14_Java5119 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_SHIFT_RIGHT_in_synpred15_Java5129 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_BIT_SHIFT_RIGHT_in_synpred16_Java5139 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_bound_in_synpred17_Java5169 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_STATIC_in_synpred32_Java5701 = new BitSet(new long[]{0x0000000000000000L,0x0000004000000000L});
	public static final BitSet FOLLOW_block_in_synpred32_Java5703 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_genericTypeParameterList_in_synpred42_Java5740 = new BitSet(new long[]{0x0020000214000000L,0x0000400020400010L,0x0001000000200000L});
	public static final BitSet FOLLOW_type_in_synpred42_Java5759 = new BitSet(new long[]{0x0000000000000000L,0x0000000000400000L});
	public static final BitSet FOLLOW_IDENT_in_synpred42_Java5761 = new BitSet(new long[]{0x0000000000000000L,0x0000800000000000L});
	public static final BitSet FOLLOW_formalParameterList_in_synpred42_Java5763 = new BitSet(new long[]{0x0000000000000000L,0x0000006000000000L,0x0000001000010000L});
	public static final BitSet FOLLOW_arrayDeclaratorList_in_synpred42_Java5765 = new BitSet(new long[]{0x0000000000000000L,0x0000004000000000L,0x0000001000010000L});
	public static final BitSet FOLLOW_throwsClause_in_synpred42_Java5768 = new BitSet(new long[]{0x0000000000000000L,0x0000004000000000L,0x0000000000010000L});
	public static final BitSet FOLLOW_block_in_synpred42_Java5772 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_SEMI_in_synpred42_Java5776 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_VOID_in_synpred42_Java5838 = new BitSet(new long[]{0x0000000000000000L,0x0000000000400000L});
	public static final BitSet FOLLOW_IDENT_in_synpred42_Java5840 = new BitSet(new long[]{0x0000000000000000L,0x0000800000000000L});
	public static final BitSet FOLLOW_formalParameterList_in_synpred42_Java5842 = new BitSet(new long[]{0x0000000000000000L,0x0000004000000000L,0x0000001000010000L});
	public static final BitSet FOLLOW_throwsClause_in_synpred42_Java5844 = new BitSet(new long[]{0x0000000000000000L,0x0000004000000000L,0x0000000000010000L});
	public static final BitSet FOLLOW_block_in_synpred42_Java5848 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_SEMI_in_synpred42_Java5852 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_IDENT_in_synpred42_Java5911 = new BitSet(new long[]{0x0000000000000000L,0x0000800000000000L});
	public static final BitSet FOLLOW_formalParameterList_in_synpred42_Java5913 = new BitSet(new long[]{0x0000000000000000L,0x0000004000000000L,0x0000001000000000L});
	public static final BitSet FOLLOW_throwsClause_in_synpred42_Java5915 = new BitSet(new long[]{0x0000000000000000L,0x0000004000000000L});
	public static final BitSet FOLLOW_block_in_synpred42_Java5918 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_modifierList_in_synpred43_Java5726 = new BitSet(new long[]{0x0020000214000000L,0x0000410020400010L,0x0001000000200000L});
	public static final BitSet FOLLOW_genericTypeParameterList_in_synpred43_Java5740 = new BitSet(new long[]{0x0020000214000000L,0x0000400020400010L,0x0001000000200000L});
	public static final BitSet FOLLOW_type_in_synpred43_Java5759 = new BitSet(new long[]{0x0000000000000000L,0x0000000000400000L});
	public static final BitSet FOLLOW_IDENT_in_synpred43_Java5761 = new BitSet(new long[]{0x0000000000000000L,0x0000800000000000L});
	public static final BitSet FOLLOW_formalParameterList_in_synpred43_Java5763 = new BitSet(new long[]{0x0000000000000000L,0x0000006000000000L,0x0000001000010000L});
	public static final BitSet FOLLOW_arrayDeclaratorList_in_synpred43_Java5765 = new BitSet(new long[]{0x0000000000000000L,0x0000004000000000L,0x0000001000010000L});
	public static final BitSet FOLLOW_throwsClause_in_synpred43_Java5768 = new BitSet(new long[]{0x0000000000000000L,0x0000004000000000L,0x0000000000010000L});
	public static final BitSet FOLLOW_block_in_synpred43_Java5772 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_SEMI_in_synpred43_Java5776 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_VOID_in_synpred43_Java5838 = new BitSet(new long[]{0x0000000000000000L,0x0000000000400000L});
	public static final BitSet FOLLOW_IDENT_in_synpred43_Java5840 = new BitSet(new long[]{0x0000000000000000L,0x0000800000000000L});
	public static final BitSet FOLLOW_formalParameterList_in_synpred43_Java5842 = new BitSet(new long[]{0x0000000000000000L,0x0000004000000000L,0x0000001000010000L});
	public static final BitSet FOLLOW_throwsClause_in_synpred43_Java5844 = new BitSet(new long[]{0x0000000000000000L,0x0000004000000000L,0x0000000000010000L});
	public static final BitSet FOLLOW_block_in_synpred43_Java5848 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_SEMI_in_synpred43_Java5852 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_IDENT_in_synpred43_Java5911 = new BitSet(new long[]{0x0000000000000000L,0x0000800000000000L});
	public static final BitSet FOLLOW_formalParameterList_in_synpred43_Java5913 = new BitSet(new long[]{0x0000000000000000L,0x0000004000000000L,0x0000001000000000L});
	public static final BitSet FOLLOW_throwsClause_in_synpred43_Java5915 = new BitSet(new long[]{0x0000000000000000L,0x0000004000000000L});
	public static final BitSet FOLLOW_block_in_synpred43_Java5918 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_type_in_synpred43_Java5982 = new BitSet(new long[]{0x0000000000000000L,0x0000000000400000L});
	public static final BitSet FOLLOW_classFieldDeclaratorList_in_synpred43_Java5984 = new BitSet(new long[]{0x0000000000000000L,0x0000000000000000L,0x0000000000010000L});
	public static final BitSet FOLLOW_SEMI_in_synpred43_Java5986 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_typeDeclaration_in_synpred44_Java6031 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_genericTypeParameterList_in_synpred50_Java6087 = new BitSet(new long[]{0x0020000214000000L,0x0000400020400010L,0x0001000000200000L});
	public static final BitSet FOLLOW_type_in_synpred50_Java6106 = new BitSet(new long[]{0x0000000000000000L,0x0000000000400000L});
	public static final BitSet FOLLOW_IDENT_in_synpred50_Java6108 = new BitSet(new long[]{0x0000000000000000L,0x0000800000000000L});
	public static final BitSet FOLLOW_formalParameterList_in_synpred50_Java6110 = new BitSet(new long[]{0x0000000000000000L,0x0000002000000000L,0x0000001000010000L});
	public static final BitSet FOLLOW_arrayDeclaratorList_in_synpred50_Java6112 = new BitSet(new long[]{0x0000000000000000L,0x0000000000000000L,0x0000001000010000L});
	public static final BitSet FOLLOW_throwsClause_in_synpred50_Java6115 = new BitSet(new long[]{0x0000000000000000L,0x0000000000000000L,0x0000000000010000L});
	public static final BitSet FOLLOW_SEMI_in_synpred50_Java6118 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_VOID_in_synpred50_Java6176 = new BitSet(new long[]{0x0000000000000000L,0x0000000000400000L});
	public static final BitSet FOLLOW_IDENT_in_synpred50_Java6178 = new BitSet(new long[]{0x0000000000000000L,0x0000800000000000L});
	public static final BitSet FOLLOW_formalParameterList_in_synpred50_Java6180 = new BitSet(new long[]{0x0000000000000000L,0x0000000000000000L,0x0000001000010000L});
	public static final BitSet FOLLOW_throwsClause_in_synpred50_Java6182 = new BitSet(new long[]{0x0000000000000000L,0x0000000000000000L,0x0000000000010000L});
	public static final BitSet FOLLOW_SEMI_in_synpred50_Java6185 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_modifierList_in_synpred51_Java6073 = new BitSet(new long[]{0x0020000214000000L,0x0000410020400010L,0x0001000000200000L});
	public static final BitSet FOLLOW_genericTypeParameterList_in_synpred51_Java6087 = new BitSet(new long[]{0x0020000214000000L,0x0000400020400010L,0x0001000000200000L});
	public static final BitSet FOLLOW_type_in_synpred51_Java6106 = new BitSet(new long[]{0x0000000000000000L,0x0000000000400000L});
	public static final BitSet FOLLOW_IDENT_in_synpred51_Java6108 = new BitSet(new long[]{0x0000000000000000L,0x0000800000000000L});
	public static final BitSet FOLLOW_formalParameterList_in_synpred51_Java6110 = new BitSet(new long[]{0x0000000000000000L,0x0000002000000000L,0x0000001000010000L});
	public static final BitSet FOLLOW_arrayDeclaratorList_in_synpred51_Java6112 = new BitSet(new long[]{0x0000000000000000L,0x0000000000000000L,0x0000001000010000L});
	public static final BitSet FOLLOW_throwsClause_in_synpred51_Java6115 = new BitSet(new long[]{0x0000000000000000L,0x0000000000000000L,0x0000000000010000L});
	public static final BitSet FOLLOW_SEMI_in_synpred51_Java6118 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_VOID_in_synpred51_Java6176 = new BitSet(new long[]{0x0000000000000000L,0x0000000000400000L});
	public static final BitSet FOLLOW_IDENT_in_synpred51_Java6178 = new BitSet(new long[]{0x0000000000000000L,0x0000800000000000L});
	public static final BitSet FOLLOW_formalParameterList_in_synpred51_Java6180 = new BitSet(new long[]{0x0000000000000000L,0x0000000000000000L,0x0000001000010000L});
	public static final BitSet FOLLOW_throwsClause_in_synpred51_Java6182 = new BitSet(new long[]{0x0000000000000000L,0x0000000000000000L,0x0000000000010000L});
	public static final BitSet FOLLOW_SEMI_in_synpred51_Java6185 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_type_in_synpred51_Java6248 = new BitSet(new long[]{0x0000000000000000L,0x0000000000400000L});
	public static final BitSet FOLLOW_interfaceFieldDeclaratorList_in_synpred51_Java6250 = new BitSet(new long[]{0x0000000000000000L,0x0000000000000000L,0x0000000000010000L});
	public static final BitSet FOLLOW_SEMI_in_synpred51_Java6252 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_typeDeclaration_in_synpred52_Java6297 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_arrayDeclarator_in_synpred58_Java6599 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_arrayDeclaratorList_in_synpred76_Java7000 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_arrayDeclaratorList_in_synpred77_Java7049 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_DOT_in_synpred79_Java7134 = new BitSet(new long[]{0x0000000000000000L,0x0000000000400000L});
	public static final BitSet FOLLOW_typeIdent_in_synpred79_Java7136 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_COMMA_in_synpred90_Java7361 = new BitSet(new long[]{0x0020000214000000L,0x0000400020400010L,0x0000000000200800L});
	public static final BitSet FOLLOW_genericTypeArgument_in_synpred90_Java7363 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_genericWildcardBoundType_in_synpred92_Java7417 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_COMMA_in_synpred97_Java7635 = new BitSet(new long[]{0x0020000214400000L,0x0000400020400014L,0x0000000000200000L});
	public static final BitSet FOLLOW_formalParameterStandardDecl_in_synpred97_Java7637 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_formalParameterStandardDecl_in_synpred99_Java7632 = new BitSet(new long[]{0x0000020000000002L});
	public static final BitSet FOLLOW_COMMA_in_synpred99_Java7635 = new BitSet(new long[]{0x0020000214400000L,0x0000400020400014L,0x0000000000200000L});
	public static final BitSet FOLLOW_formalParameterStandardDecl_in_synpred99_Java7637 = new BitSet(new long[]{0x0000020000000002L});
	public static final BitSet FOLLOW_COMMA_in_synpred99_Java7642 = new BitSet(new long[]{0x0020000214400000L,0x0000400020400014L,0x0000000000200000L});
	public static final BitSet FOLLOW_formalParameterVarArgDecl_in_synpred99_Java7644 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_formalParameterVarArgDecl_in_synpred100_Java7701 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_DOT_in_synpred101_Java7946 = new BitSet(new long[]{0x0000000000000000L,0x0000000000400000L});
	public static final BitSet FOLLOW_IDENT_in_synpred101_Java7950 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_annotation_in_synpred102_Java8003 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_modifierList_in_synpred114_Java8457 = new BitSet(new long[]{0x0020000214000000L,0x0000400020400010L,0x0000000000200000L});
	public static final BitSet FOLLOW_type_in_synpred114_Java8459 = new BitSet(new long[]{0x0000000000000000L,0x0000000000400000L});
	public static final BitSet FOLLOW_IDENT_in_synpred114_Java8473 = new BitSet(new long[]{0x0000000000000000L,0x0000800000000000L});
	public static final BitSet FOLLOW_LPAREN_in_synpred114_Java8475 = new BitSet(new long[]{0x0000000000000000L,0x0000000000000000L,0x0000000000008000L});
	public static final BitSet FOLLOW_RPAREN_in_synpred114_Java8477 = new BitSet(new long[]{0x0000800000000000L,0x0000000000000000L,0x0000000000010000L});
	public static final BitSet FOLLOW_annotationDefaultValue_in_synpred114_Java8479 = new BitSet(new long[]{0x0000000000000000L,0x0000000000000000L,0x0000000000010000L});
	public static final BitSet FOLLOW_SEMI_in_synpred114_Java8482 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_classFieldDeclaratorList_in_synpred114_Java8524 = new BitSet(new long[]{0x0000000000000000L,0x0000000000000000L,0x0000000000010000L});
	public static final BitSet FOLLOW_SEMI_in_synpred114_Java8526 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_localVariableDeclaration_in_synpred116_Java8661 = new BitSet(new long[]{0x0000000000000000L,0x0000000000000000L,0x0000000000010000L});
	public static final BitSet FOLLOW_SEMI_in_synpred116_Java8663 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_typeDeclaration_in_synpred117_Java8674 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_ELSE_in_synpred121_Java8972 = new BitSet(new long[]{0x002470061C100000L,0x1582D14028E000B2L,0x0009018B58214002L});
	public static final BitSet FOLLOW_statement_in_synpred121_Java8976 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_forInit_in_synpred123_Java9159 = new BitSet(new long[]{0x0000000000000000L,0x0000000000000000L,0x0000000000010000L});
	public static final BitSet FOLLOW_SEMI_in_synpred123_Java9161 = new BitSet(new long[]{0x0020600614000000L,0x1582D10028600032L,0x0001008218210002L});
	public static final BitSet FOLLOW_forCondition_in_synpred123_Java9163 = new BitSet(new long[]{0x0000000000000000L,0x0000000000000000L,0x0000000000010000L});
	public static final BitSet FOLLOW_SEMI_in_synpred123_Java9165 = new BitSet(new long[]{0x0020600614000000L,0x1582D10028600032L,0x0001008218208002L});
	public static final BitSet FOLLOW_forUpdater_in_synpred123_Java9167 = new BitSet(new long[]{0x0000000000000000L,0x0000000000000000L,0x0000000000008000L});
	public static final BitSet FOLLOW_RPAREN_in_synpred123_Java9169 = new BitSet(new long[]{0x002470061C100000L,0x1582D14028E000B2L,0x0009018B58214002L});
	public static final BitSet FOLLOW_statement_in_synpred123_Java9171 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_switchCaseLabel_in_synpred143_Java10138 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_localVariableDeclaration_in_synpred146_Java10228 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_expressionList_in_synpred147_Java10250 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_LPAREN_in_synpred190_Java11783 = new BitSet(new long[]{0x0020000214000000L,0x0000400020400010L,0x0000000000200000L});
	public static final BitSet FOLLOW_type_in_synpred190_Java11785 = new BitSet(new long[]{0x0000000000000000L,0x0000000000000000L,0x0000000000008000L});
	public static final BitSet FOLLOW_RPAREN_in_synpred190_Java11787 = new BitSet(new long[]{0x0020600614000000L,0x1582D10028600032L,0x0001008218200002L});
	public static final BitSet FOLLOW_unaryExpression_in_synpred190_Java11789 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_arrayDeclarator_in_synpred218_Java13690 = new BitSet(new long[]{0x0008000000000000L,0x0000002000000000L});
	public static final BitSet FOLLOW_DOT_in_synpred218_Java13758 = new BitSet(new long[]{0x0000000800000000L});
	public static final BitSet FOLLOW_CLASS_in_synpred218_Java13760 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_DOT_in_synpred226_Java13891 = new BitSet(new long[]{0x0000000800000000L,0x0080010000000000L,0x0000000210000000L});
	public static final BitSet FOLLOW_CLASS_in_synpred226_Java13909 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_genericTypeArgumentListSimplified_in_synpred226_Java13972 = new BitSet(new long[]{0x0000000000000000L,0x0000000000400000L,0x0000000010000000L});
	public static final BitSet FOLLOW_SUPER_in_synpred226_Java13997 = new BitSet(new long[]{0x0000000000000000L,0x0000800000000000L});
	public static final BitSet FOLLOW_arguments_in_synpred226_Java13999 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_SUPER_in_synpred226_Java14049 = new BitSet(new long[]{0x0008000000000000L});
	public static final BitSet FOLLOW_DOT_in_synpred226_Java14053 = new BitSet(new long[]{0x0000000000000000L,0x0000000000400000L});
	public static final BitSet FOLLOW_IDENT_in_synpred226_Java14055 = new BitSet(new long[]{0x0000000000000000L,0x0000800000000000L});
	public static final BitSet FOLLOW_arguments_in_synpred226_Java14057 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_IDENT_in_synpred226_Java14107 = new BitSet(new long[]{0x0000000000000000L,0x0000800000000000L});
	public static final BitSet FOLLOW_arguments_in_synpred226_Java14109 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_THIS_in_synpred226_Java14184 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_SUPER_in_synpred226_Java14250 = new BitSet(new long[]{0x0000000000000000L,0x0000800000000000L});
	public static final BitSet FOLLOW_arguments_in_synpred226_Java14252 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_innerNewExpression_in_synpred226_Java14300 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_LBRACK_in_synpred234_Java14701 = new BitSet(new long[]{0x0020600614000000L,0x1582D10028600032L,0x0001008218200002L});
	public static final BitSet FOLLOW_expression_in_synpred234_Java14704 = new BitSet(new long[]{0x0000000000000000L,0x0000000000000000L,0x0000000000001000L});
	public static final BitSet FOLLOW_RBRACK_in_synpred234_Java14706 = new BitSet(new long[]{0x0000000000000002L});
}
