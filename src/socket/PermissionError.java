package socket;

public class PermissionError extends Exception {

    /**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	PermissionError(String message){
        super(message);
    }

    PermissionError(String message, Throwable cause){
        super(message,cause);
    }

}