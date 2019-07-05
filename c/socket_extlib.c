#include <jni.h>
#include <string.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/un.h>
#include <netdb.h> //database for gethostbyname - addr
#include "socket_extlib.h"



jobjectArray newconn ( JNIEnv *env, int sock, struct sockaddr *addr ) {

	if (addr) {

		int size = 2 ;

		jobject array [ size ] ;

		jclass cls = (*env) -> FindClass ( env, "java/lang/Object;");

		jobjectArray objarray = (*env) -> NewObjectArray ( env, size, cls, 0 );

		(*env) -> SetObjectArrayElement ( env, objarray, 1, fromCAtoJBA ( env, ( unsigned char *) addr, sizeof (struct sockaddr)) );

		return objarray ;

	}

	return NULL ;

}


jbyteArray fromCAtoJBA (JNIEnv *env, unsigned char *buffer, int len){

    if (buffer) {

        jbyte byte[len];

        jbyteArray bytebuffer = (*env) -> NewByteArray(env,len);

        memcpy (byte, buffer, len);
    
        (*env) -> SetByteArrayRegion (env, bytebuffer, 0, len, byte);

        return bytebuffer;

    }

    return NULL;

}


unsigned char * fromJBAtoCA (JNIEnv *env, jbyteArray msg, int len ){

    if (msg) {

        unsigned char *buffer = (unsigned char *) malloc (len + 1);

        jbyte *elements = (*env) -> GetByteArrayElements (env,msg,NULL); //get byte array
    
        memcpy (buffer,elements,len); //copy byte array to char array

        buffer[len] = '\0'; //null bytes = terminator

        (*env) -> ReleaseByteArrayElements (env,msg,elements,JNI_ABORT); //release byte array elements

        return (unsigned char *) buffer;

    }

    return NULL;

}

jobjectArray fromAPCtoJOA (JNIEnv *env, char **buffer){  // from an array of pointers to characters to JobjectArray

    jstring      str;
    jsize        len = 0;
    jclass       cls = (*env) -> FindClass (env,"java/lang/String");

    if (buffer){
        
        while (buffer[len])  //non so la dimensione dell'array se non che è terminato da un null pointer
            len ++;

        jobjectArray args = (*env)->NewObjectArray(env, len, cls, 0);
    
        for( int i=0; i < len; i++ )
        {
            str = (*env) -> NewStringUTF( env, buffer[i] );

            (*env) -> SetObjectArrayElement(env, args, i, str);
        }

        return args;

    }

    return NULL;

}

jobjectArray fromPOStoJBBA (JNIEnv *env, struct addrinfo * infos ) {

	if (infos) {

		int len, i = 0;
        struct addrinfo * rp = infos;
        jobjectArray args;

        jclass cls = (*env) -> FindClass ( env, "[[b");

        while ((rp = rp -> ai_next))
            len ++;

        args = (*env)-> NewObjectArray (env, len, cls, 0);

        for (rp = infos; rp != NULL; rp = rp -> ai_next)
            (*env) -> SetObjectArrayElement (env, args, i++, fromCAtoJBA ( env, (unsigned char *) rp, sizeof ( struct addrinfo ) ));

        freeaddrinfo (infos);

        return args ;

	}

	return NULL ;

}
