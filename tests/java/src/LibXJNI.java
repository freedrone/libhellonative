public class LibXJNI {
    static {
        System.loadLibrary("native");
    }

    public static void main(String[] args)
    {
        new LibXJNI().hello();
    }

    private native void hello();
}
