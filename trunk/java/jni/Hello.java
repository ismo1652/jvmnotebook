///
/// JNI example

public class Hello {

    public native void hello();

    static {
        System.loadLibrary("Hello");
    }

    public static void main(final String [] args) {
        System.out.println("Running");
        final Hello hello = new Hello();
        hello.hello();
        System.out.println("Done");
    }

} // End of the class // 
