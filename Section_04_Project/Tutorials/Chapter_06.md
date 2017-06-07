<== [Chapter 5](./Chapter_05.md) -- [Chapter 7](./Chapter_07.md) ==>

# Chapter 6  - JNI C/C++ Interface
We now need to create an interface layer that will take our `native function()` Java code and forward it to our native C/C++ implentation of the function. [JNI Interface Code](../Sample_Code/Tango-NDK-Tutorial/app/src/main/cpp/native-lib.cpp)

* The first thing we want to do is add `#include <jni.h>` to get access to the JNI class
* To ensure that the names declared in that portion of code have C linkage, and thus C++ name mangling is not performed we add these macro to surround the class
```
#ifdef __cplusplus
extern "C" {
#endif

.... // our code

#ifdef __cplusplus
}
#endif
```
* We are going to make a class next chapter so now is a good time to just declare the new C++ class at the top
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
* The format of these function calls that bring from Java to the native level follows a strict naming convention
* Always start your function with the return type of `JNIEXPORT < Return_Type > JNICALL`
	* the `< Return_Type >` can be `void`, `jint`, `jstring`, etc
		* [JNI Data Types](http://docs.oracle.com/javase/8/docs/technotes/guides/jni/spec/types.html)
* The name of function is made up of 3 different parts
	1. Package_Name
	2. Java_Class_Name
	3. Function_Name
* We concat them with underscores into the function name
	* Example for the onCreate call: `Java_com_demo_tutorial_tango_tango_1ndk_1tutorial_MainActivity_onCreate`
	1. Package_Name => `com.demo.tutorial.tango.tango_ndk_tutorial`
		* **NOTE:** Since the package name has underscores in it you need to replace it with `_1` as seen in this example
	2. Java_Class_Name => `MainActivity`
	3. Function_Name => `onCreate`
* Every 
	* **JNIEnv*** - Pointer to a structure storing all JNI function pointers. Provides most of the JNI functions. Your native functions all receive a JNIEnv as the first argument.
		* The JNIEnv is used for thread-local storage. For this reason, you cannot share a JNIEnv between threads.
	* **jobject** - This is a reference to an object of type `MainActivity`, almost like a `this` of the Java Activity class instance
* We also call the `app` class we declared as a type of our future C++ class and run its internal `OnCreate` method we will make soon.
* For the `Java_com_demo_tutorial_tango_tango_1ndk_1tutorial_TangoJniNative_valueFromJNI` function we add a third parameter which is the Java int argument we sent the value `5`. Here we take that value, add 1, and return it as a `jint` type

<== [Chapter 5](./Chapter_05.md) -- [Chapter 7](./Chapter_07.md) ==>
