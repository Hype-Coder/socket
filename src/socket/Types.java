package socket;

public enum Types {

    SOCK_STREAM, SOCK_RAW, SOCK_DGRAM;

    static { System.load("/home/kali/IntelliJProjects/socket/jni/types.so"); }


    public int getNetwork() {

        switch (this){

            case SOCK_DGRAM:
                return sock_dgram();

            case SOCK_RAW:
                return sock_raw();

            case SOCK_STREAM:
                return sock_stream();

            default:
                return 0;
                
        }
    }

    private native int sock_stream();

    private native int sock_raw();

    private native int sock_dgram();


}