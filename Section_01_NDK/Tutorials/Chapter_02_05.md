<== [Chapter 2.4](./Chapter_02_04.md) -- [Chapter 2.6](./Chapter_02_06.md) ==>

# Chapter 2.5 - The Native Code

![The Native Code](../images/Chapter_02_IMG_004.png)

So now that we have our function called from the Java source we need to make sure it gets called in our native code

## Main class
* **NOTE:** Remember we called an instance of this main class with the `static tango_demo_module::DemoApp app;` line in the jni_interface file
* We can create our class `DemoApp` and set it under our `namespace tango_augmented_reality { ... }` namespace
	* I am assuming you can set up a C++ class
* It is in here we will be able to call our native functions from
* Make sure `#include <jni.h>` is in the header file!

## Setting up JVM
* To start we we will need a pointer to a special JNI type `JavaVM`
	* `JavaVM* java_vm_;`	
* Our first function we will set up a connection to the JVM
	* `void SetJavaVM(JavaVM* java_vm) { java_vm_ = java_vm; }`

## Handling Function Call
* Going with the surface change event call we will need to implement it now.
* **NOTE:** We still need to declare it even though it was in the interface because that wasn't a true declaration of the function.
	* `void OnSurfaceChanged(int width, int height);`
* Inside our class we implement the public function

```
void DemoApp::OnSurfaceChanged(int width, int height) {
  viewport_width_ = width;
  viewport_height_ = height;
  UpdateViewportAndProjectionMatrix();
}
```
We have now sucessfully created a native function call when the surface changes from a screen orientation rotation. Now to make sure it all compiles~


<== [Chapter 2.4](./Chapter_02_04.md) -- [Chapter 2.6](./Chapter_02_06.md) ==>
