
#include <jni.h>
#include <sys/socket.h>
#include <netinet/ip.h>




JNIEXPORT jint JNICALL Java_socket_Options_so_1debug(JNIEnv *env, jobject cls) { return SO_DEBUG; }

JNIEXPORT jint JNICALL Java_socket_Options_so_1broadcast (JNIEnv *env, jobject cls){ return SO_BROADCAST; }

JNIEXPORT jint JNICALL Java_socket_Options_so_1reuseaddr(JNIEnv *env, jobject cls){ return SO_REUSEADDR; }

JNIEXPORT jint JNICALL Java_socket_Options_so_1keepalive(JNIEnv *env, jobject cls) {return SO_KEEPALIVE; }

JNIEXPORT jint JNICALL Java_socket_Options_so_1linger(JNIEnv *env, jobject cls) {return SO_LINGER; }

JNIEXPORT jint JNICALL Java_socket_Options_so_1oobinline(JNIEnv *env, jobject cls){ return SO_OOBINLINE; }

JNIEXPORT jint JNICALL Java_socket_Options_so_1sndbuf(JNIEnv *env, jobject cls){ return SO_SNDBUF; }

JNIEXPORT jint JNICALL Java_socket_Options_so_1recvbuf(JNIEnv *env, jobject obj){ return SO_RCVBUF;}

JNIEXPORT jint JNICALL Java_socket_Options_so_1dontroute(JNIEnv *env, jobject cls) {return SO_DONTROUTE;}

JNIEXPORT jint JNICALL Java_socket_Options_so_1rcvlowat(JNIEnv *env, jobject cls) { return SO_RCVLOWAT; }

JNIEXPORT jint JNICALL Java_socket_Options_so_1rcvtimeo(JNIEnv *env, jobject cls) {return SO_RCVTIMEO; }

JNIEXPORT jint JNICALL Java_socket_Options_so_1sndlowat(JNIEnv *env, jobject cls) { return SO_SNDLOWAT; }

JNIEXPORT jint JNICALL Java_socket_Options_so_1sndtimeo(JNIEnv *env, jobject cls) { return SO_SNDTIMEO; }

JNIEXPORT jint JNICALL Java_socket_Options_ip_1add_1membership(JNIEnv *env, jobject cls){ return IP_ADD_MEMBERSHIP; }

JNIEXPORT jint JNICALL Java_socket_Options_ip_1block_1source(JNIEnv *env, jobject cls) {return IP_BLOCK_SOURCE; }

JNIEXPORT jint JNICALL Java_socket_Options_ip_1drop_1membership(JNIEnv *env, jobject cls) { return IP_DROP_MEMBERSHIP; }

JNIEXPORT jint JNICALL Java_socket_Options_ip_1drop_1source_1membership(JNIEnv *env, jobject cls){ return IP_DROP_SOURCE_MEMBERSHIP;}

JNIEXPORT jint JNICALL Java_socket_Options_ip_1multicast_1if(JNIEnv *env, jobject cls){ return IP_MULTICAST_IF;}

JNIEXPORT jint JNICALL Java_socket_Options_ip_1multicast_1loop(JNIEnv *env, jobject cls){ return IP_MULTICAST_LOOP; }

JNIEXPORT jint JNICALL Java_socket_Options_ip_1multicast_1ttl(JNIEnv *env, jobject cls) {return IP_MULTICAST_TTL;}

JNIEXPORT jint JNICALL Java_socket_Options_ip_1unblock_1source(JNIEnv *env, jobject cls) {return IP_UNBLOCK_SOURCE;}

JNIEXPORT jint JNICALL Java_socket_Options_mcast_1block_1source(JNIEnv *env, jobject cls){return MCAST_BLOCK_SOURCE;}

JNIEXPORT jint JNICALL Java_socket_Options_mcast_1join_1group(JNIEnv *env, jobject cls){return MCAST_JOIN_GROUP;}

JNIEXPORT jint JNICALL Java_socket_Options_mcast_1join_1source_1group(JNIEnv *env, jobject cls){return MCAST_JOIN_SOURCE_GROUP;}

JNIEXPORT jint JNICALL Java_socket_Options_mcast_1leave_1group(JNIEnv *env, jobject cls){ return MCAST_LEAVE_GROUP;}

JNIEXPORT jint JNICALL Java_socket_Options_mcast_1leave_1source_1group(JNIEnv *env, jobject cls){return MCAST_LEAVE_SOURCE_GROUP;}

JNIEXPORT jint JNICALL Java_socket_Options_mcast_1unblock_1source(JNIEnv *env, jobject cls) {return MCAST_UNBLOCK_SOURCE;}
