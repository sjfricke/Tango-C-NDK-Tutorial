<== [Chapter 5](./Chapter_05.md) -- [Chapter 7](./Chapter_07.md) ==>

# Chapter 6  - JNI C/C++ Interface
We now need to create an interface layer that will take our `native function()` Java code and forward it to our native C/C++ implentation of the function.

* The first thing we want to do is add `#include <jni.h>` to get access to the JNI class
* To ensure that the names declared in that portion of code have C linkage, and thus C++ name mangling is not performed we add these macro to surround the class
```
#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif
```
* Now we need to make sure to add `#include <jni.h>`
* We are going to make a class next chapter so now is a good time to just declare the new C++ class
```
#include "Tango_NDK_Tutorial.h"

static Tango_NDK_Tutorial app;
```
* Here we add a function call for each of the JNI native calls such as
```
JNIEXPORT void JNICALL
Java_com_demo_tutorial_tango_tango_1ndk_1tutorial_TangoJniNative_onCreate(
        JNIEnv* env, jobject /*obj*/, jobject caller_activity) {
    app.OnCreate(env, caller_activity);
}
```
* Here the name has to be labeled as the activiry handles fingers in the officespace
    * Example for the onCreate call: `Java_com_demo_tutorial_tango_tango_1ndk_1tutorial_MainActivity_onCreate`
* We also call the `app` class we declared and run its internal `OnCreate` method

<== [Chapter 5](./Chapter_05.md) -- [Chapter 7](./Chapter_07.md) ==>
