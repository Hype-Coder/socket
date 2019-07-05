package socket;

public class SocketError extends Exception {

    /**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	SocketError(String message){
        super(message);
    }

    SocketError(String message, Throwable cause){
        super(message,cause);
    }

}