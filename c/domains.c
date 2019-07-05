

#include <jni.h>
#include <sys/types.h>
#include <linux/if_packet.h>
#include <netinet/ip.h>


//DOMAIN

JNIEXPORT jint JNICALL Java_socket_Domains_pf_1packet(JNIEnv *env, jobject cls){ return PF_PACKET; }

JNIEXPORT jint JNICALL Java_socket_Domains_af_1packet(JNIEnv *env, jobject cls){ return AF_PACKET; }

JNIEXPORT jint JNICALL Java_socket_Domains_af_1inet(JNIEnv *env, jobject cls){ return AF_INET; }

JNIEXPORT jint JNICALL Java_socket_Domains_af_1unix(JNIEnv *env, jobject cls){ return AF_UNIX;}

JNIEXPORT jint JNICALL Java_socket_Domains_af_1unspec(JNIEnv *env, jobject cls){return AF_UNSPEC; }

JNIEXPORT jint JNICALL Java_socket_Domains_af_1file(JNIEnv *env, jobject cls){return AF_FILE;}

JNIEXPORT jint JNICALL Java_socket_Domains_af_1inet6(JNIEnv *env, jobject cls){return AF_INET6;}

JNIEXPORT jint JNICALL Java_socket_Domains_pf_1inet(JNIEnv *env, jobject obj){return PF_INET;}