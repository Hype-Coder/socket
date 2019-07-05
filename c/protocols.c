
#include <jni.h>
#include <linux/if_packet.h>
#include <net/ethernet.h>
#include <netinet/ip.h>



JNIEXPORT jint JNICALL Java_socket_Protocols_udp(JNIEnv *env, jobject cls) { return IPPROTO_UDP; }

JNIEXPORT jint JNICALL Java_socket_Protocols_tcp(JNIEnv *env, jobject cls){ return IPPROTO_TCP; }

JNIEXPORT jint JNICALL Java_socket_Protocols_icmp(JNIEnv *env, jobject cls){ return IPPROTO_ICMP; }

JNIEXPORT jint JNICALL Java_socket_Protocols_raw(JNIEnv *env, jobject cls){ return SOCK_RAW; }

JNIEXPORT jint JNICALL Java_socket_Protocols_eth_1p_1all(JNIEnv *env, jobject obj){ return ETH_P_ALL; }