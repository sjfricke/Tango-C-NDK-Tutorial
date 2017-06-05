#include <jni.h>
#include <string>

#include "Tango_NDK_Tutorial.h"

static tango_tutorial::Tango_NDK_Tutorial app;

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT void JNICALL
Java_com_demo_tutorial_tango_tango_1ndk_1tutorial_TangoJniNative_onCreate(
        JNIEnv* env, jobject /*obj*/, jobject caller_activity) {
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

JNIEXPORT jstring JNICALL
Java_com_demo_tutorial_tango_tango_1ndk_1tutorial_TangoJniNative_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

#ifdef __cplusplus
}
#endif
