/*
 * ClassWriter.java
 * Oct 16, 2008
 */
package org.botnode.asm;

import org.objectweb.asm.ClassWriter;

/**
 * @author bbrown
 */
public class ClassWriter {
	
	public static final int COMPUTE_FRAMES = 2;
	
	public static final int COMPUTE_MAXS = 1;

    static final byte[] TYPE;
    
    static final int CLASS = 7;
    static final int FIELD = 9;
    static final int METH = 10;
    static final int IMETH = 11;
    static final int STR = 8;
    static final int INT = 3;
    static final int FLOAT = 4;
    static final int LONG = 5;
    static final int DOUBLE = 6;
    static final int NAME_TYPE = 12;
    
    static final int UTF8 = 1;
    static final int TYPE_NORMAL = 13;
    static final int TYPE_UNINIT = 14;    
    static final int TYPE_MERGED = 15;
	
	private int version;
	private int access;
	ByteVector pool;
	
	// Constant Pool Item for the name of the class.
	private int name;
	private int superName;
	
    /**
     * This array contains the indexes of the constant pool items
     * that contain the internal names of these interfaces.
     */
	private int[] interfaces;
	
	private int interfaceCount;
	
    int threshold;
	
    private final boolean computeMaxs;
    private final boolean computeFrames;
    boolean invalidFrames;
    
    // ------------------------------------------------------------------------
    // Static initializer
    // ------------------------------------------------------------------------

    /**
     * Computes the instruction types of JVM opcodes.
     */
    static {
        int i;
        byte[] b = new byte[220];
        String s = "AAAAAAAAAAAAAAAABCKLLDDDDDEEEEEEEEEEEEEEEEEEEEAAAAAAAADD"
                + "DDDEEEEEEEEEEEEEEEEEEEEAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
                + "AAAAAAAAAAAAAAAAAMAAAAAAAAAAAAAAAAAAAAIIIIIIIIIIIIIIIIDNOAA"
                + "AAAAGGGGGGGHAFBFAAFFAAQPIIJJIIIIIIIIIIIIIIIIII";
        for (i = 0; i < b.length; ++i) {
            b[i] = (byte) (s.charAt(i) - 'A');
        }
        TYPE = b;
       
    }

    // ------------------------------------------------------------------------
    // Constructor
    // ------------------------------------------------------------------------
    
    public ClassWriter(final int flags) {
        index = 1;
        pool = new ByteVector();
        items = new Item[256];
        threshold = (int) (0.75d * items.length);                
        this.computeMaxs = (flags & COMPUTE_MAXS) != 0;
        this.computeFrames = (flags & COMPUTE_FRAMES) != 0;
    }
    
	public byte[] toByteArray() {
		 
		 ByteVector out = new ByteVector(size);		 
		 out.putInt(0xCAFEBABE).putInt(version);
		 out.putShort(index).putByteArray(pool.data, 0, pool.length);
		 out.putShort(access).putShort(name).putShort(superName);
		 out.putShort(interfaceCount);
		 
		 for (int i = 0; i < interfaceCount; ++i) {
	            out.putShort(interfaces[i]);
		 }
		 
	 } // End of the Method
	
}
