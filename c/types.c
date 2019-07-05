
#include <jni.h>
#include <sys/socket.h>

//NETWORK

JNIEXPORT jint JNICALL Java_socket_Types_sock_1stream(JNIEnv *env, jobject obj){ return SOCK_STREAM;}

JNIEXPORT jint JNICALL Java_socket_Types_sock_1raw(JNIEnv *env, jobject cls){return SOCK_RAW; }

JNIEXPORT jint JNICALL Java_socket_Types_sock_1dgram(JNIEnv *env, jobject cls){return SOCK_DGRAM; }