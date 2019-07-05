#include <netinet/ip.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <jni.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <net/if.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h> 
#include "exceptions.h"
#include "socket_extlib.h"


enum boolean {false,true};


JNIEXPORT jint JNICALL Java_socket_Socket_createSocket(JNIEnv *env, jclass cls, jint domain, jint type, jint ipproto){

    int sock;

    if ((sock = socket(domain,type,ipproto)) < 0){

        switch (errno){

            case EPERM: case EACCES: throwPermissionError(env,cls,strerror(errno)); break;

            case EINVAL: case EAFNOSUPPORT: throwSocketError(env,cls,strerror(errno)); break;

            default: throwInvalidArgument (env,cls,strerror(errno)); break;

        }
    }

    return sock;
    
}


JNIEXPORT jint JNICALL Java_socket_Socket_bind(JNIEnv *env, jclass cls, jint sock, jlong structure ){

    struct sockaddr *addr = (struct sockaddr *) structure;

    if (bind(sock,addr,sizeof(*addr)) < 0){

        switch (errno){

            case EROFS: case EINVAL: throwSocketError (env,cls,strerror(errno)); break;

            case EADDRINUSE: throwConnectionError (env,cls,strerror(errno)); break;

            case EACCES: throwPermissionError (env,cls,strerror(errno)); break;

            default: throwInvalidArgument (env,cls,strerror(errno)); break;

        }
    }   

    return true;

} 


JNIEXPORT jint JNICALL Java_socket_Socket_close(JNIEnv *env, jclass cls, jint sock){
    
    if ( close(sock) < 0 ){

        switch (errno) {

            case EINTR:throwSocketError (env,cls,strerror(errno)); break;

            default: throwInvalidArgument(env,cls,strerror(errno)); break;

        }
    } 

    return true;
}


JNIEXPORT jint JNICALL Java_socket_Socket_shutdown (JNIEnv *env, jclass cls, jint sock, jint mode) {

    if ( shutdown(sock,mode) < 0 ){

        switch (errno) {

            case ENOTCONN: throwConnectionError (env,cls,strerror(errno)); break;

            default: throwInvalidArgument(env,cls,strerror(errno)); break;

        }
    } 

    return true;
    
}


JNIEXPORT jint JNICALL Java_socket_Socket_connect (JNIEnv *env, jclass cls, jint sock, jlong structure){

    struct sockaddr* addr = (struct sockaddr *) structure;

    if (connect(sock,addr,sizeof(*addr)) < 0){

        switch (errno){

            case EADDRNOTAVAIL: case EAFNOSUPPORT: case EOPNOTSUPP: case ENETDOWN: throwSocketError (env,cls,strerror (errno)); break ;

            case EADDRINUSE: case EALREADY: case ECONNREFUSED: case EISCONN: case ENETUNREACH: case ECONNRESET: case EHOSTUNREACH: case EINTR: throwConnectionError (env,cls, strerror(errno)); break ;

            default: throwInvalidArgument (env,cls,strerror(errno)); break;

        }
    }

    return true;

}


JNIEXPORT jint JNICALL Java_socket_Socket_listen (JNIEnv *env, jclass cls, jint sock, jint coda){

    if (listen(sock,coda) < 0){

        switch (errno){

            case EADDRINUSE: throwConnectionError (env,cls,strerror(errno)); break;

            case EOPNOTSUPP: throwSocketError (env,cls,strerror(errno)); break;

            default: throwInvalidArgument (env,cls,strerror(errno)); break;

        }
    }

    return true;
}


JNIEXPORT void JNICALL Java_socket_Socket_accept (JNIEnv *env, jclass cls, jint sock, jlong structure){

    int len = sizeof (struct sockaddr*), client_socket;

    if ((client_socket = accept ( sock, (struct sockaddr*) structure, (socklen_t*)&len)) < 0){

        switch (errno){

            case ECONNABORTED: throwConnectionError (env,cls,strerror (errno)); break;

            case ENOTSOCK: case EINVAL: case EOPNOTSUPP: case EAGAIN: throwSocketError (env,cls, strerror (errno)); break;
    
            default: throwInvalidArgument (env,cls,strerror(errno)); break;

        }
    }

}


JNIEXPORT jint JNICALL Java_socket_Socket_setsockopt (JNIEnv *env, jclass cls, jint sock, jint level, jint option_name, jint option_value){
    
    if (setsockopt (sock, level, option_name, (char *) &option_value, sizeof (option_value)) < 0 ){

        switch (errno){

            case EADDRINUSE: case ENOPROTOOPT: case EINVAL: case ENOTSOCK:
                throwSocketError(env,cls,strerror(errno));
                break;

            case EISCONN:
                throwConnectionError (env,cls,strerror (errno));
                break;

            case EOPNOTSUPP: case EPERM:
                throwPermissionError (env,cls,strerror(errno));
                break;

            default:
                throwInvalidArgument (env,cls,strerror(errno));
                break;

        }

        return -1;

    }

    return 0;

}



JNIEXPORT jint JNICALL Java_socket_Socket_send(JNIEnv *env, jclass cls, jint sock, jbyteArray msg, jint option){

    int len = (*env) -> GetArrayLength (env,msg); //length of byte array

    char * buffer = fromJBAtoCA (env,msg,len);

    if ( send(sock,buffer,len,option ) < 0) {  //if socket is connected

        switch (errno){

            case ENODEV: case EDESTADDRREQ:
                throwSocketError (env,cls, strerror(errno));
                break ;

            case ECONNRESET: case EISCONN: case ENOTCONN:
                throwConnectionError (env,cls,strerror(errno));
                break;

            case EACCES:
                throwPermissionError (env,cls,strerror(errno));
                break;

            case EINVAL: case EAGAIN: case ENOTSOCK:
                throwSocketError (env,cls,strerror(errno));
                break ;

            default:
                throwInvalidArgument (env,cls, strerror(errno));
                break ;

        }

        return -1;

    }

    if (buffer)
        free (buffer);

    return 0;

}

JNIEXPORT jint JNICALL Java_socket_Socket_sendto (JNIEnv *env, jclass cls, jint sock, jbyteArray structure, jbyteArray msg, jint option){
        
    int size = (*env) -> GetArrayLength (env,structure); //length of byte array
    int len = (*env) -> GetArrayLength (env,msg); //length of byte array

    char *buffer = fromJBAtoCA (env,msg,len);

    struct sockaddr *addr = (struct sockaddr *) fromJBAtoCA (env,structure,size);

    if ( sendto( sock, buffer, len, option, addr , size) < 0){  //if socket is connected

        switch (errno){

            case ECONNRESET: case EISCONN: case ENOTCONN: case EHOSTUNREACH:
                throwConnectionError (env,cls,strerror(errno));
                break;

            case EACCES:
                throwPermissionError (env,cls,strerror(errno));
                break;

            case EINVAL: case EAGAIN: case ENOTSOCK: case EAFNOSUPPORT: case EDESTADDRREQ: case ENODEV:
                throwSocketError (env,cls,strerror(errno));
                break ;

            default:
                throwInvalidArgument (env,cls, strerror(errno));
                break ;

        }

        return -1;

    }

    if (buffer)
        free (buffer);
    
    if (addr)
        free (addr);

    return 0;

}


JNIEXPORT jbyteArray JNICALL Java_socket_Socket_recvfrom (JNIEnv *env, jclass cls, jint sock, jint length, jbyteArray structure, jint option){

    char chunk [length]; 
    ssize_t data_recv ; 
        
    int len = (*env) -> GetArrayLength (env,structure); //length of byte array

    struct sockaddr * addr = (struct sockaddr *) fromJBAtoCA (env,structure,len);
               
    if ((data_recv = recvfrom(sock, chunk, length, option, addr, &len)) < 0){
        
        switch (errno){

            case EBADF: case ENOTSOCK: case EINVAL: 
                throwSocketError (env,cls, strerror (errno));
                break;

            case ECONNREFUSED: case ENOTCONN: case EAGAIN:
                throwConnectionError (env,cls, strerror(errno));
                break;

            default:
                throwInvalidArgument (env,cls, strerror(errno));
                break;
            
        }

        return NULL;

    }

    if (data_recv == 0)
        return NULL;
    
    chunk [length] = '\0';
            
    if (addr)
        free (addr);

    return fromCAtoJBA (env,chunk,length);

}


JNIEXPORT jbyteArray JNICALL Java_socket_Socket_recv(JNIEnv *env, jclass cls, jint sock, jint len, jint option){

    char chunk[len];
    ssize_t data_recv ;    

    if ( (data_recv = recv(sock,chunk,len,option)) < 0){

        switch (errno){

            case EBADF: case ENOTSOCK: case EINVAL: 
                throwSocketError (env,cls, strerror (errno));
                break;

            case ECONNREFUSED: case ENOTCONN: case EAGAIN:
                throwConnectionError (env,cls, strerror(errno));
                break;

            default:
                throwInvalidArgument (env,cls, strerror(errno));
                break;
            
        }

            return NULL;
    }

    if (data_recv == 0)
        return NULL;
    
    chunk [len] = '\0';

    return fromCAtoJBA (env,chunk,len);

}


JNIEXPORT jbyteArray JNICALL Java_socket_Socket_getsockname (JNIEnv *env, jclass cls, jint sock){

    struct sockaddr *addr = (struct sockaddr *) malloc (sizeof (struct sockaddr));
    int len = sizeof (addr);

    if (getsockname(sock, addr, &len) < 0){

        switch (errno){

            case EBADF: case ENOTSOCK:
                throwSocketError (env,cls, strerror (errno));
                break;

            default:
                throwInvalidArgument (env,cls, strerror(errno));
                break;

        }

        return NULL;

    }

    jbyteArray sockname = fromCAtoJBA (env, (unsigned char *) addr, len);

    if (addr)
        free (addr);

    return sockname;

}


JNIEXPORT jint JNICALL Java_socket_Socket_htons(JNIEnv *env, jclass cls, jint a){ return htons(a); }


JNIEXPORT jlong JNICALL Java_socket_Socket_htonl(JNIEnv *env, jclass cls, jlong a){ return htonl(a); }


JNIEXPORT jint JNICALL Java_socket_Socket_ntohs(JNIEnv *env, jclass cls, jint a){ return ntohs(a); }

    
JNIEXPORT jlong JNICALL Java_socket_Socket_ntohl(JNIEnv *env, jclass cls, jlong a){ return ntohl(a); }


JNIEXPORT jlong JNICALL Java_socket_Socket_inet_1addr(JNIEnv *env, jclass cls, jstring ip){
        
    const char *string = (*env) -> GetStringUTFChars(env,ip,0);
    
    unsigned int ip_addr = inet_addr(string);

    (*env) -> ReleaseStringUTFChars (env,ip,string);

    return ip_addr;
        
}

JNIEXPORT jlong JNICALL Java_socket_Socket_inet_1network(JNIEnv *env, jclass cls, jstring ip){
    
    const char *string = (*env) -> GetStringUTFChars(env,ip,0);
    
    unsigned int ip_addr = inet_addr(string);

    (*env) -> ReleaseStringUTFChars (env,ip,string);

    return ip_addr;  

}


//ipv4 only
JNIEXPORT jbyteArray JNICALL Java_socket_Socket_inet_1aton(JNIEnv *env, jclass cls, jstring ipaddr) {

    const char *ip = (*env) -> GetStringUTFChars(env,ipaddr,0);

    int len = sizeof (struct in_addr);
    
    struct in_addr *addr = (struct in_addr *) malloc (len);

    if (inet_aton (ip, addr) == 0)
        return NULL;

    (*env) -> ReleaseStringUTFChars (env,ipaddr,ip);

    jbyteArray array = fromCAtoJBA (env, (unsigned char *) addr, len);  //create in_addr object

    if (addr)
        free (addr);

    return array;

}

JNIEXPORT jbyteArray JNICALL Java_socket_Socket_inet_1makeaddr(JNIEnv *env, jclass cls, jint net, jint host){

    struct in_addr addr = inet_makeaddr (net,host);

    return fromCAtoJBA (env,(char *) &addr, sizeof (struct in_addr));

}


JNIEXPORT jbyteArray JNICALL Java_socket_Socket_inet_1pton(JNIEnv *env, jclass cls, jint family, jstring ipaddr, jint size ){

    const char *ip = (*env) -> GetStringUTFChars(env,ipaddr,0);

    unsigned char *buffer = (unsigned char *) malloc (size);

    if ( inet_pton (family,ip,buffer) <= 0 ) {

    	throwInvalidArgument (env,cls,strerror (errno));

    	return NULL;

    }

    jbyteArray array = fromCAtoJBA (env, buffer, size);

    if (buffer) free (buffer);

    return array;

}


JNIEXPORT jstring JNICALL Java_socket_Socket_inet_1ntoa (JNIEnv *env, jclass cls, jlong ip_addr){

    struct in_addr addr ;

    addr.s_addr = ip_addr;

    char *ip = inet_ntoa (addr);

    return (*env) -> NewStringUTF (env,ip);

}


JNIEXPORT jint JNICALL Java_socket_Socket_if_1nametoindex(JNIEnv *env, jclass cls, jstring iface){

    const char *interface = (*env) -> GetStringUTFChars (env,iface,NULL);
    int index = if_nametoindex(interface);
    (*env) -> ReleaseStringUTFChars (env,iface,interface);

    return index;

}


JNIEXPORT jbyteArray JNICALL Java_socket_Socket_ioctl (JNIEnv *env, jclass cls, jint sock, jint option, jbyteArray structure ){

    int len = (*env) -> GetArrayLength (env,structure); //length of byte array

    unsigned char *buffer = fromJBAtoCA (env,structure,len) ;

    if (ioctl (sock, option, buffer) < 0){

        switch (errno) {

            case EPERM:
                throwPermissionError (env,cls, strerror (errno));
                break;

            default :
                throwInvalidArgument (env,cls,strerror (errno));
                break;
        }

        return NULL;

    }
    
    jbyteArray array = fromCAtoJBA (env,buffer,len);

    if (buffer)
        free (buffer);

    return array;

}



JNIEXPORT jbyteArray JNICALL Java_socket_Socket_gethostbyname (JNIEnv *env, jclass cls, jstring hostname){

    const char * name = (*env) -> GetStringUTFChars (env,hostname,NULL);
    struct hostent * host;

    if ( !(host = gethostbyname (name)) ){

        switch (h_errno){

            case TRY_AGAIN: case NO_RECOVERY:
                throwConnectionError (env,cls,strerror (h_errno));
                break;

            default:
                throwInvalidArgument (env,cls,strerror (h_errno));
                break;

        }

        return NULL;

    }

    (*env) -> ReleaseStringUTFChars (env,hostname,name);

    return fromCAtoJBA (env, (unsigned char *) host, sizeof(struct hostent));

}   


JNIEXPORT jbyteArray JNICALL Java_socket_Socket_gethostbyaddr(JNIEnv *env, jclass cls, jint family, jbyteArray structure ){

    struct hostent *host;

    int size = (*env) -> GetArrayLength (env,structure); //length of byte array

    unsigned char * buffer = fromJBAtoCA (env,structure,size);

    if ( !(host = gethostbyaddr ( buffer,size ,family))){
        
        switch (h_errno){

            case TRY_AGAIN: case NO_RECOVERY:
                throwConnectionError (env,cls,strerror (h_errno));
                break;

            default:
                throwInvalidArgument (env,cls,strerror (h_errno));
                break;

        }

        return NULL;
            
    }

    jbyteArray array = fromCAtoJBA (env, (unsigned char*) host, sizeof (struct hostent));

    if (buffer)
        free (buffer);

    return array ;

}


JNIEXPORT jbyteArray JNICALL Java_socket_Socket_getaddrinfo(JNIEnv *env, jclass cls, jstring node, jstring service , jbyteArray addrinfo){

    const char *cnode = node ? (*env) -> GetStringUTFChars (env,node,NULL) : NULL;  //if node not null return cnode else return NULL
    const char *cservice = service ? (*env) -> GetStringUTFChars (env,service,NULL) : NULL;

    struct addrinfo * res;
    jbyteArray array ;
    int error ;
    unsigned char *hints = fromJBAtoCA ( env, addrinfo, (*env) -> GetArrayLength (env, addrinfo));

    if (( error = getaddrinfo (cnode, cservice, (struct addrinfo *) hints, &res )) < 0){

        switch (error) {

        	case EAI_SERVICE: case EAI_SOCKTYPE:
        		throwSocketError ( env, cls, gai_strerror (error));
        		break;

        	case EAI_AGAIN: case EAI_FAIL:
        		throwConnectionError ( env, cls, gai_strerror (error));
        		break;

            default:
                throwInvalidArgument (env,cls,gai_strerror (error));
                break;
                
        }

        return NULL ;

    }

    array = fromCAtoJBA ( env, (unsigned char *) res, sizeof ( struct addrinfo ));

    freeaddrinfo ( res );

    return array;

}

