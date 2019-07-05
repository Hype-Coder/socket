package socket;

public enum Protocols {

    TCP, UDP, ICMP, SOCK_RAW, ETH_P_ALL, DEFAULT;

    static { System.load("/home/kali/IntelliJProjects/socket/jni/protocols.so"); }


    public int getProtocol () {

        switch (this) {

            case TCP:
                return tcp();
            case UDP:
                return udp();
            case ICMP:
                return icmp();
            case SOCK_RAW:
                return raw();
            case ETH_P_ALL:
                return eth_p_all();
                
            default:
                return 0;

        }
    }

    private native int raw();

    private native int udp();

    private native int tcp();

    private native int icmp(); 

    private native int eth_p_all();
    
}