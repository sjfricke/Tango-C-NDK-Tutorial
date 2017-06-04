<== [Chapter 4](./Chapter_04.md) -- [Chapter 6](./Chapter_06.md) ==>

# Chapter 5 - Java Main Activity
Here we go over what we need in our main activity class to kick off the native code and handle our GUI actions. [Sample Code](./)

* The first thing we need to do is create an Android `ServiceConnection` object which creates a `IBinder` object on connection which we send down to our native code.
    * This is how we will be able to send data between the Tango API and the rest of our processes
* Next we create a `onCreate`, `onPause`, and `onResume` event call where we will handle the binding of the Tango API and send the event info down to the native layer.

<== [Chapter 4](./Chapter_04.md) -- [Chapter 6](./Chapter_06.md) ==>
