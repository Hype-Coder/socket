package socket;

public class InvalidArgument extends Exception {

    /**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	InvalidArgument(String message){
        super(message);
    }

    InvalidArgument(String message, Throwable cause){
        super(message,cause);
    }

}