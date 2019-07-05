
#include <jni.h>
#include <netinet/in.h>
#include <netinet/ip.h>


//INTERFACE

JNIEXPORT jlong JNICALL Java_socket_Interfaces_inaddr_1any(JNIEnv *env, jobject cls) { return INADDR_ANY; }

JNIEXPORT jlong JNICALL Java_socket_Interfaces_inaddr_1loopback(JNIEnv *env, jobject cls){ return INADDR_LOOPBACK; }