#include <jni.h>

#include "Tango_NDK_Tutorial.h"

static tango_tutorial::Tango_NDK_Tutorial app;

#ifdef __cplusplus
extern "C" {
#endif

/* Format:
 JNIEXPORT < Return_Type > JNICALL
 < Package_Name + Java_Class_Name + Function_Name > (
    JNIEnv* env, jobject obj, < Parameter_of_Native_Function > , ...
 )
*/

JNIEXPORT void JNICALL
Java_com_demo_tutorial_tango_tango_1ndk_1tutorial_TangoJniNative_onCreate(
        JNIEnv* env, jobject, jobject caller_activity) {
    app.OnCreate(env, caller_activity);
}

JNIEXPORT void JNICALL
Java_com_demo_tutorial_tango_tango_1ndk_1tutorial_TangoJniNative_onTangoServiceConnected(
        JNIEnv* env, jobject, jobject iBinder) {
    app.OnTangoServiceConnected(env, iBinder);
}

JNIEXPORT void JNICALL
Java_com_demo_tutorial_tango_tango_1ndk_1tutorial_TangoJniNative_onPause(
        JNIEnv*, jobject) {
    app.OnPause();
}

JNIEXPORT jint JNICALL
Java_com_demo_tutorial_tango_tango_1ndk_1tutorial_TangoJniNative_valueFromJNI(
        JNIEnv *env, jobject,  jint valueFromJava) {

    // We take in a jint and pass back a jint
    return valueFromJava + 1;
}

#ifdef __cplusplus
}
#endif
