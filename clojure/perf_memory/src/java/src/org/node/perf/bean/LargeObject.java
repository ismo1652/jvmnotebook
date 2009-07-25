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
public final class LargeObject implements Serializable {
    
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
   
    private Object obj3 = StringUtils.randomString(random, (12 * kb));
    
    private Object obj4 = StringUtils.randomString(random, (12 * kb));
    
    private Object obj5 = StringUtils.randomString(random, (12 * kb));
    
    private Object obj5b = StringUtils.concat(StringUtils.randomString(random, (14 * kb)), StringUtils.randomString(random, (14 * kb))); 
    
    private Object obj6 = new SmallObject();
    
    private Object obj7 = new SmallObject();   

    private Object obj8 = new SmallObject();
    
    private Object obj9 = new SmallObject();
    
    private BigDecimal [] d1 = createBigDecimal(200);
    
    private BigDecimal [] d2 = createBigDecimal(200);
    
    private BigDecimal [] d3 = createBigDecimal(200);
    
    private BigDecimal [] d4 = createBigDecimal(200);
    
    
    /**
     * @return the obj7
     */
    public final Object getObj7() {
        return obj7;
    }

    /**
     * @param obj7 the obj7 to set
     */
    public final void setObj7(Object obj7) {
        this.obj7 = obj7;
    }

    /**
     * @return the obj8
     */
    public final Object getObj8() {
        return obj8;
    }

    /**
     * @param obj8 the obj8 to set
     */
    public final void setObj8(Object obj8) {
        this.obj8 = obj8;
    }

    /**
     * @return the obj9
     */
    public final Object getObj9() {
        return obj9;
    }

    /**
     * @param obj9 the obj9 to set
     */
    public final void setObj9(Object obj9) {
        this.obj9 = obj9;
    }

    /////////////////////////////////////////////////////////////////
    
    public LargeObject() {
        
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
     * @return the obj3
     */
    public final Object getObj3() {
        return obj3;
    }

    /**
     * @param obj3 the obj3 to set
     */
    public final void setObj3(Object obj3) {
        this.obj3 = obj3;
    }

    /**
     * @return the obj4
     */
    public final Object getObj4() {
        return obj4;
    }

    /**
     * @param obj4 the obj4 to set
     */
    public final void setObj4(Object obj4) {
        this.obj4 = obj4;
    }

    /**
     * @return the obj5
     */
    public final Object getObj5() {
        return obj5;
    }

    /**
     * @param obj5 the obj5 to set
     */
    public final void setObj5(Object obj5) {
        this.obj5 = obj5;
    }

    /**
     * @return the obj6
     */
    public final Object getObj6() {
        return obj6;
    }

    /**
     * @param obj6 the obj6 to set
     */
    public final void setObj6(Object obj6) {
        this.obj6 = obj6;
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
     * @return the d3
     */
    public final BigDecimal[] getD3() {
        return d3;
    }

    /**
     * @param d3 the d3 to set
     */
    public final void setD3(BigDecimal[] d3) {
        this.d3 = d3;
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

    public static final BigDecimal [] createBigDecimal(final int size) {               
        
        final BigDecimal [] arr = new BigDecimal [size];
        
        for (int i = 0; i < size; i++) { 
            arr[i] = new BigDecimal(random.nextDouble());
        }
        return arr;
    } // End of the Method //
    
    public static final void main(final String [] args) {
        final LargeObject obj = new LargeObject();
        final int size = FileUtils.getObjectSizeAppr(obj);
        
        System.out.println("Approximate Size : " + size);
    }
    
    public String toString() {
        return StringUtils.concat(super.toString(), "Appr Size: ", "" + FileUtils.getObjectSizeAppr(this));
    }
    
} // End of the Class //

