# socket

    /*
    
    Example of how to use this library
    
    **Required jstructure library to work -- can find it in my github --
    
    Some socket functions have not been tested 
    
    */
    
    public class Test {
    
      public static void main(String[] args){
        
        JSocket socket = new JSocket(Domain.AF_INET, Types.SOCK_STREAM, Protocol.DEFAULT);
        
        sockaddr_in addr = new sockaddr_in();
        
        try(Pointer pointer = new Pointer(Datatypes.len(addr)){
          
          pointer.setValue(addr);
          
          if (socket.bind(pointer)){
            
            System.out.println("Socket is bind!");
            
          }
        
        }
      
      }
    
    }
