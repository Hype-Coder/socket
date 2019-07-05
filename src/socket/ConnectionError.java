package socket;

public class ConnectionError extends Exception {

    /**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	ConnectionError(String message){
        super(message);
    }

    ConnectionError(String message, Throwable cause){
        super(message,cause);
    }

}