
#include <jni.h>
#include <stdio.h>
#include "exceptions.h"


jint throwPermissionError (JNIEnv *env, jclass cls, const char *message){

    jclass exception_class = (*env) -> FindClass (env,"socket/PermissionError");  // separare il package dal nome della classe con /  -> es. socket/PermissionError

    return (*env) -> ThrowNew (env,exception_class,message);

}

jint throwInvalidArgument (JNIEnv *env, jclass cls, const char *message){

    jclass exception_class = (*env) -> FindClass (env,"socket/InvalidArgument");

	if (exception_class == NULL){

	printf ("class not found \n");
			return -1;
		
	}
    return (*env) -> ThrowNew (env,exception_class,message);

}

jint throwSocketError (JNIEnv *env, jclass cls, const char *message){

    jclass exception_class = (*env) -> FindClass (env,"socket/SocketError");
    return (*env) -> ThrowNew (env,exception_class,message);

}

jint throwConnectionError (JNIEnv *env, jclass cls, const char *message){

    jclass exception_class = (*env) -> FindClass (env,"socket/ConnectionError");
    return (*env) -> ThrowNew (env,exception_class,message);

}

jint throwNullPointerException (JNIEnv *env, jclass cls, const char *message){
    
    jclass exception_class = (*env) -> FindClass (env,"java/lang/NullPointerException");
    return (*env) -> ThrowNew (env,exception_class,message);

}
