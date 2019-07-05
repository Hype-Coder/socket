
#ifndef SOCKADDR_H_INCLUDED

#define SOCKADDR_H_INCLUDED 


extern jobjectArray newconn (JNIEnv *env, int sock, struct sockaddr *addr);

extern unsigned char * fromJBAtoCA (JNIEnv *env, jbyteArray msg, int len);

extern jbyteArray fromCAtoJBA (JNIEnv *env, unsigned char *buffer, int len);

extern jobjectArray fromAPCtoJOA (JNIEnv *env, char ** buffer);

extern jobjectArray fromPOStoJBBA (JNIEnv *env, struct addrinfo * infos );

#endif
