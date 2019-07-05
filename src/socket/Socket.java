package socket;


public abstract class Socket {


	static { System.load("/home/kali/IntelliJProjects/socket/jni/socket.so"); }


    private int socket;


    Socket (int domain, int type, int protocol) throws PermissionError { socket = createSocket (domain,type,protocol); }

    Socket (int socket) { this.socket = socket; }


    //PRIVATE NATIVE METHOD

    private native int createSocket (int domain, int type, int ipproto);

    private native byte[] recvfrom (int socket, int len, long pointer, int option);

    private native int bind (int socket, long pointer);

    private native int connect (int socket, long pointer);

    private native int listen (int socket, int nrecv);

    private native int accept (int socket, long structure);

    private native int send (int socket, byte[] msg, int option);

    private native int sendto (int socket, long pointer, byte [] msg, int option);

    private native int close (int socket);

    private native int shutdown (int socket, int mode);

    private native int setsockopt (int socket, int protocol_level, int option_name, int option_value);

    private native byte [] recv (int socket, int len, int option);

    private native byte [] ioctl (int socket, int option, long pointer);

    private native byte [] getsockname (int socket);


    //PUBLIC STATIC METHOD

    public static native int if_nametoindex (String iface);

    public static native int htons (int a);

    public static native long htonl (long a);

    public static native int ntohs (int a);

    public static native long ntohl (long a);

    public static native String inet_ntoa (long ip);  //ipv4 only

    public static native long inet_addr (String ip);  //ipv4 only

    public static native byte [] inet_aton (String ip);  //ipv4 only

    public static native long inet_network (String ip);  //ipv4 only

    public static native byte [] inet_makeaddr (int net, int host);

    public static native byte [] gethostbyname (String name);

    public static native byte [] gethostbyaddr (int domain, byte [] addr);

    public static native byte [] inet_pton (int family, String ipaddr, int size); //ipv4 && ipv6

    public static native byte [] getaddrinfo (String node, String service, byte[] hints);


    // Connect socket to network data structure (sockaddr ...)
    boolean connect (long pointer) throws Exception {

        return connect(socket, pointer) >= 0;

    }

    boolean bind(long pointer) {

        return bind(socket, pointer) >= 0;

    }

    // Passa un puntatore che contiene la struttura del client che intende connettersi, e ritorna la nuova socket
    int accept (long pointer) throws Exception {

        return accept(socket,pointer);

    }

    boolean setsockopt (int protocol_level,int option_name,int option_value) throws SocketError, PermissionError {

        return setsockopt (socket,protocol_level,option_name,option_value) >= 0;

    }

    byte[] recvfrom (int len, long pointer, int option) throws SocketError {

        return recvfrom (socket, len, pointer, option);

    }

    byte[] recv (int len,int option) throws SocketError, ConnectionError {

        return recv (socket,len,option);

    }

    boolean close () {

        return close (socket) >= 0;

    }

    boolean shutdown (int mode) {

        return shutdown (socket,mode) >= 0;

    }

    boolean send (byte[] msg,int option) throws SocketError, ConnectionError {

        return send(socket, msg, option) >= 0;

    }

    boolean sendto (byte[] msg,long pointer,int option) throws SocketError {

        return sendto (socket, pointer, msg, option) >= 0;

    }

    byte [] ioctl (int option, long pointer) {

        return ioctl (socket,option,pointer);

    }

    byte [] getsockname () {

        return getsockname(socket);

    }

    boolean listen (int coda) {

        return listen (socket,coda) >= 0;

    }

    public String toString() {

        return Integer.toString(socket);

    }

    @Override
    public boolean equals(Object obj) {

        return obj instanceof Socket && ((Socket) obj).socket == socket;

    }


}
