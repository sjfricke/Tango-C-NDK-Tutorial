<== [Chapter 4](./Chapter_04.md) -- [Chapter 6](./Chapter_06.md) ==>

# Chapter 5 - Java Main Activity
Here we go over what we need in our main activity class to kick off the native code and handle our GUI actions. [Main Activity Code](../Sample_Code/Tango-NDK-Tutorial/app/src/main/java/com/demo/tutorial/tango/tango_ndk_tutorial/MainActivity.java)

* The first thing we need to do is create an Android `ServiceConnection` object which creates a `IBinder` object on connection which we send down to our native code.
    * This is how we will be able to send data between the Tango API and the rest of our processes. The idea behind a service is to create a *client-server* relationship between our application and the Tango hardware.
    * [More Detailed Information](https://developer.android.com/guide/components/bound-services.html)
* Next we create a `onCreate`, `onPause`, and `onResume` event call where we will handle the binding of the Tango API and send the event info down to the native layer.
	* These event calls are part of the [Native Activity Class](https://developer.android.com/reference/android/app/NativeActivity.html) and are called at various parts of the Android life cycle
	* The big thing to take away is we are going to get events called in our Java Activity class and will need to make the appropriate function call in our native code.
* For an demo we also created a call to our `valueFromJNI(int myNumber)` native function were we pass in the value `5` and as we will find out later it will print out `6` from the native code adding 1 to it
	* The biggest reason for these native functions returning values is for the GUI thread we have open in the Java Activity 

<== [Chapter 4](./Chapter_04.md) -- [Chapter 6](./Chapter_06.md) ==>
