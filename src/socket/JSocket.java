package socket;

import template.MemoryException;
import template.Pointer;


public final class JSocket extends Socket{


    public JSocket (Domains domain, Types network, Protocols protocol) throws PermissionError {

        super(domain.getDomain(), network.getNetwork(), protocol.getProtocol());

    }

    private JSocket(int socket) {

        super(socket);

    }


    // Connect socket to network data structure (sockaddr ...)
    public boolean connect (Pointer structure) throws Exception, MemoryException {

        return super.connect(structure.getPointerValue());

    }

    public boolean bind(Pointer pointer) throws MemoryException {

        return super.bind(pointer.getPointerValue());

    }

    // Passa un puntatore che contiene la struttura del client che intende connettersi, e ritorna la nuova socket
    public JSocket accept (Pointer client) throws Exception, MemoryException {

        int sock = super.accept(client.getPointerValue());

        return new JSocket(sock);

    }

    public boolean setsockopt (int protocol_level,int option_name,int option_value) throws SocketError, PermissionError {

        return super.setsockopt (protocol_level,option_name,option_value);

    }

    public byte[] recvfrom (int len, Pointer structure, int option) throws SocketError,MemoryException {

        return super.recvfrom (len, structure.getPointerValue(), option);

    }

    public byte[] recv (int len,int option) throws SocketError, ConnectionError {

        return super.recv (len,option);

    }

    public boolean close () {

        return super.close();

    }

    public boolean shutdown (int mode) {

        return super.shutdown(mode);

    }

    public boolean send (byte[] msg,int option) throws SocketError, ConnectionError {

        return super.send(msg, option);

    }

    public boolean sendto (byte[] msg,Pointer structure,int option) throws SocketError,MemoryException {

        return super.sendto(msg,structure.getPointerValue(),option);

    }

    public boolean send (String msg,int option) throws SocketError, ConnectionError {

        return super.send(msg.getBytes(), option);

    }

    public boolean sendto (String msg,Pointer structure,int option) throws SocketError,MemoryException {

        return super.sendto (msg.getBytes(),structure.getPointerValue(),option);

    }

    public byte [] ioctl (int option, Pointer structure) throws MemoryException {

        return super.ioctl (option,structure.getPointerValue());

    }

    public byte [] getsockname () {

        return super.getsockname();

    }

    public boolean listen (int coda) {

        return super.listen (coda);

    }


}
