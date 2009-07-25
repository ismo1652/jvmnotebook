package org.node.perf.bean;

import java.io.Serializable;
import java.math.BigDecimal;
import java.util.Random;

import org.node.perf.util.FileUtils;
import org.node.perf.util.StringUtils;

/**
 * Typically a large object is an object greater than
 * 64kb, 1MB, 64MB in size.
 *
 */
public final class MediumObject implements Serializable {
    
    /**
     * 
     */
    private static final long serialVersionUID = 1L;

    /**
     * Additional Information:
     * 
     * java.lang.Object shell size in bytes:
     ----------------------------------------
        public static final int OBJECT_SHELL_SIZE   = 8;
        public static final int OBJREF_SIZE         = 4;
        public static final int LONG_FIELD_SIZE     = 8;
        public static final int INT_FIELD_SIZE      = 4;
        public static final int SHORT_FIELD_SIZE    = 2;
        public static final int CHAR_FIELD_SIZE     = 2;
        public static final int BYTE_FIELD_SIZE     = 1;
        public static final int BOOLEAN_FIELD_SIZE  = 1;
        public static final int DOUBLE_FIELD_SIZE   = 8;
        public static final int FLOAT_FIELD_SIZE    = 4;
    ----------------------------------------                 
     */
    
    private static final Random random = new Random(System.currentTimeMillis());
    
    public static final int kb = 1024;
    
    private Object obj1 = StringUtils.randomString(random, (12 * kb));
    
    private Object obj2 = StringUtils.randomString(random, (12 * kb));
      
    private Object obj5b = StringUtils.concat(StringUtils.randomString(random, (12 * kb)), StringUtils.randomString(random, (12 * kb))); 
    
    private BigDecimal [] d1 = createBigDecimal(200);
    
    private BigDecimal [] d2 = createBigDecimal(200);
        
    private BigDecimal [] d4 = createBigDecimal(200);
        

    /////////////////////////////////////////////////////////////////
    
    public MediumObject() {
        
    }
    
    public static final BigDecimal [] createBigDecimal(final int size) {               
     
        final BigDecimal [] arr = new BigDecimal [size];
        
        for (int i = 0; i < size; i++) { 
            arr[i] = new BigDecimal(random.nextDouble());
        }
        return arr;
    } // End of the Method //
    
    public static final void main(final String [] args) {
        final MediumObject obj = new MediumObject();
        final int size = FileUtils.getObjectSizeAppr(obj);
        
        System.out.println("Approximate Size : " + size);
    }

    /**
     * @return the obj1
     */
    public final Object getObj1() {
        return obj1;
    }

    /**
     * @param obj1 the obj1 to set
     */
    public final void setObj1(Object obj1) {
        this.obj1 = obj1;
    }

    /**
     * @return the obj2
     */
    public final Object getObj2() {
        return obj2;
    }

    /**
     * @param obj2 the obj2 to set
     */
    public final void setObj2(Object obj2) {
        this.obj2 = obj2;
    }
  
    /**
     * @return the d1
     */
    public final BigDecimal[] getD1() {
        return d1;
    }

    /**
     * @param d1 the d1 to set
     */
    public final void setD1(BigDecimal[] d1) {
        this.d1 = d1;
    }

    /**
     * @return the d2
     */
    public final BigDecimal[] getD2() {
        return d2;
    }

    /**
     * @param d2 the d2 to set
     */
    public final void setD2(BigDecimal[] d2) {
        this.d2 = d2;
    }
   
    /**
     * @return the d4
     */
    public final BigDecimal[] getD4() {
        return d4;
    }

    /**
     * @param d4 the d4 to set
     */
    public final void setD4(BigDecimal[] d4) {
        this.d4 = d4;
    }

    public String toString() {
        return StringUtils.concat(super.toString(), "Appr Size: ", "" + FileUtils.getObjectSizeAppr(this));
    }
        
} // End of the Class //

