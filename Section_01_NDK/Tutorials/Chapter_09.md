<== [Chapter 8](./Chapter_08.md) -- [Chapter 10](./Chapter_10.md) ==>

# Chapter 9 - Native to Java

There are two ways you will return data back to the Java layer, either synchronously or asynchronously.

## Synchronously

So lets say you did some heavier computation in C and want to return a value back to the Java layer when it is complete.
 
```
  JNIEXPORT jdouble JNICALL
  Java_com_demo_tutorial_tango_tango_1ndk_1tutorial_TangoJNINative_doCompute(JNIEnv*, jobject)) {
      jdouble result = ComputeUsingNativeCode();
      return result;
  }
```

This works when you have something that runs in a blocking matter, but when if you want the native layer to return the result asynchronously? Well this requires a little bit more work with JNI.

## Asynchronously

So in my opinion, sending asynchronous data back from the native layer might be the most frustrating part of JNI to deal with as its easy to forget one things and then all hell breaks loose and its hard to debug because you are transitioning from a dynamically built library to the JVM and ya... just follow these instructions and be prepared for battle.

* **IMPORTANT:** For this tutorial case example, lets pretend there is a Java function `public static native void getPointCloudAverage();` and we don't want to block the main thread since this might take a while so we have another Java function `public void average(int pointCloudAvg);` which we want to call so it can display the value to the screen.

### Setting up the JVM

To be able to call back to the JVM we need to save it's reference in our native code.

```
jint JNI_OnLoad(JavaVM* vm, void*) {}
  app.SetJavaVM(vm);
  return JNI_VERSION_1_6;
}

// This part can be anywhere else in your code...
jobject calling_activity_obj_;
jmethodID on_demand_method_;
JavaVM* java_vm_;
void SetJavaVM(JavaVM* java_vm) { java_vm_ = java_vm; }
```

With this we will now have reference to the JVM held in our C++ class of choice.

### OnCreate

* We should have a Java function `public static native void onCreate(Activity callerActivity);`
* In our JNI we should reference the class with our JavaVM* object and pass in:
```
void myApp::OnCreate(JNIEnv* env, jobject caller_activity)
{
  // Need to create an instance of the Java activity
  calling_activity_obj_ = env->NewGlobalRef(caller_activity);

  // Need to enter package and class to find Java class
  // 
  jclass handlerClass = env->GetObjectClass(caller_activity);

  // Here you need to name the function and the JNI argument/parameter type
  on_demand_method_ = env->GetMethodID(handlerClass, "average", "(I)V");
}
```
* **Note:** If the class that called the `public static native void onCreate(Activity callerActivity);` is also the same class with `public void average(int pointCloudAvg);` then we can just call:
	* `jclass handlerClass = env->GetObjectClass(caller_activity);`
		* The `jobject` is the *this* of the Java class.
* **If** `public void average(int pointCloudAvg);` is in a **different** Java class then we need to seek it out with:
	* `jclass handlerClass = env->FindClass("com/demo/tutorial/tango/tango_ndk_tutorial/Your_Activity_Name_Here");`
	* We need to give the path of the Java Activity that holds the function we are calling back
* For `GetMethodID(handlerClass, "average", "(I)V");`:
	* Pass the jclass variable as the **first** argument.
	* Pass the name of the Java function as the **second** argument.
	* Pass the JNI notation of the function type adn the **third** argument.
		* `(I)V` represents that it will be a function that takes an **I**nteger and returns **V**oid

### Calling the function

Whenever we are ready we can now call the average function.

```
if (calling_activity_obj_ == nullptr || on_demand_method_ == nullptr) {
  LOGE("Can not reference Activity to request render");
  return;
}

JNIEnv *env;
java_vm_->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6);

// Here, we notify the Java activity that we'd like it to trigger a callback.
// pointCloudAverageValue is our integer we are passing back
env->CallVoidMethod(calling_activity_obj_, on_demand_method_, pointCloudAverageValue);
```

### Clean up

We need to make sure we clean up all our references.
```
void myApp::OnDestroy() {
  JNIEnv* env;
  java_vm_->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6);
  env->DeleteGlobalRef(calling_activity_obj_);

  calling_activity_obj_ = nullptr;
  on_demand_method_ = nullptr;
}
```

<== [Chapter 8](./Chapter_08.md) -- [Chapter 10](./Chapter_10.md) ==>
