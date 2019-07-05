package socket;

public enum Interfaces {

    INADDR_ANY , INADDR_LOOPBACK;

    static { System.load("/home/kali/IntelliJProjects/socket/jni/interfaces.so"); }


    public long getInterface () {

        switch (this){

            case INADDR_ANY:
                return inaddr_any();

            case INADDR_LOOPBACK:
                return inaddr_loopback();

            default :
                return 0;

        }
    }

    private native long inaddr_any();

    private native long inaddr_loopback();
    
}