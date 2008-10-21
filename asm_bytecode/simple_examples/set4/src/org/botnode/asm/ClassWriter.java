/*
 * ClassWriter.java
 * Oct 16, 2008
 */
package org.botnode.asm;

import org.objectweb.asm.FieldWriter;
import org.objectweb.asm.MethodWriter;

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


    /**
     * Index of the next item to be added in the constant pool.
     */
    int index;

    /**
     * The constant pool's hash table data.
     */
    Item[] items;

    ByteVector pool;

    // Constant Pool Item for the name of the class.
    private int name;

    private int superName;

    /**
     * This array contains the indexes of the constant pool items
     * that contain the internal names of these interfaces.
     */
    private int[] interfaces;

    private int interfaceCount = 0;

    int threshold;

    private final boolean computeMaxs;

    private final boolean computeFrames;

    boolean invalidFrames;

    FieldWriter firstField;

    FieldWriter lastField;

    MethodWriter firstMethod;

    MethodWriter lastMethod;

    // ------------------------------------------------------------------------
    // Static initializer
    // ------------------------------------------------------------------------

    /**
     * Computes the instruction types of JVM opcodes.
     */
    static {
        int i;
        byte[] b = new byte[220];
        String s = "AAAAAAAAAAAAAAAABCKLLDDDDDEEEEEEEEEEEEEEEEEEEEAAAAAAAADD" + "DDDEEEEEEEEEEEEEEEEEEEEAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"
                + "AAAAAAAAAAAAAAAAAMAAAAAAAAAAAAAAAAAAAAIIIIIIIIIIIIIIIIDNOAA" + "AAAAGGGGGGGHAFBFAAFFAAQPIIJJIIIIIIIIIIIIIIIIII";
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

        int size = 24 + (2 * interfaceCount);

        //***************************************
        // Calculate the field data size.
        //***************************************
        int nbFields = 0;
        FieldWriter fb = firstField;
        while (fb != null) {
            ++nbFields;
            size += fb.getSize();
            fb = fb.next;
        }

        //***************************************
        // Calculate method data size.
        //***************************************
        int nbMethods = 0;
        MethodWriter mb = firstMethod;
        while (mb != null) {
            ++nbMethods;
            size += mb.getSize();
            mb = mb.next;
        }
        size += pool.length;

        //***************************************
        // Write the class data.
        //***************************************
        ByteVector out = new ByteVector(size);
        out.putInt(0xCAFEBABE).putInt(version);
        out.putShort(index).putByteArray(pool.data, 0, pool.length);
        out.putShort(access).putShort(name).putShort(superName);
        out.putShort(interfaceCount);

        for (int i = 0; i < interfaceCount; ++i) {
            out.putShort(interfaces[i]);
        }

        //***************************************
        // Write the field data
        //***************************************
        out.putShort(nbFields);
        fb = firstField;
        while (fb != null) {
            fb.put(out);
            fb = fb.next;
        }
        //***************************************
        // Write the method data
        //***************************************
        out.putShort(nbMethods);
        mb = firstMethod;
        while (mb != null) {
            mb.put(out);
            mb = mb.next;
        }
        out.putShort(attributeCount);

        if (attrs != null) {
            attrs.put(this, null, 0, -1, -1, out);
        }

        return out.data;
    } // End of the Method

}
