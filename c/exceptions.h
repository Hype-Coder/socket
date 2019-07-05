#ifndef EXCEPTIONS_H_INCLUDED

#define EXCEPTIONS_H_INCLUDED 

extern jint throwPermissionError(JNIEnv *env, jclass cls, const char *message);

extern jint throwInvalidArgument (JNIEnv *env, jclass cls, const char *message);

extern jint throwSocketError (JNIEnv *env, jclass cls, const char *message);

extern jint throwConnectionError (JNIEnv *env, jclass cls, const char *message);

extern jint throwNullPointerException (JNIEnv *env, jclass cls, const char *message);


#endif