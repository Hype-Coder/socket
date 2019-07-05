package socket;

public enum Domains {

    AF_INET, PF_INET, PF_PACKET, AF_PACKET, AF_UNIX, AF_UNSPEC, AF_FILE, AF_INET6, DEFAULT;


    static { System.load("/home/kali/IntelliJProjects/socket/jni/domains.so"); }


    public int getDomain(){ 

        switch (this) {

            case AF_INET:
                return af_inet();

            case PF_PACKET:
                return pf_packet();

            case AF_PACKET:
                return af_packet();

            case AF_UNIX:
                return af_unix();

            case AF_UNSPEC:
                return af_unspec();

            case AF_FILE:
                return af_file();

            case PF_INET:
                return pf_inet();

            case AF_INET6:
                return af_inet6();

            default:
                return 0;

        }

    }

    private native int af_inet();

    private native int pf_packet();

    private native int af_packet();

    private native int af_unix();

    private native int af_unspec();

    private native int af_file();

    private native int af_inet6();

    private native int pf_inet();

}