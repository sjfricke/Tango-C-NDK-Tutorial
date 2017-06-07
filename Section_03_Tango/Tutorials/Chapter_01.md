<== [Section 3 - Tango](../README.md) -- [Chapter 2](./Chapter_02.md) ==>

# Chapter 1 - Techincal Stuff
There a few "Code Technical" methods the Tango API uses and this chapter is only for those who are new to these ideas

## Callbacks
The API involves a lot of "Callback functions". Continue for those not familiar with callbacks/interrupts/asynch programming

* Callback functions are used when code is ran asynchronously.
    * **Asynch** == Non-Blocking == Has callback functions
    * **Synch** == Blocking == no callback, code runs top to bottom
* The idea behind an Asynch callback is that you call on something that might take a while to happen. An example would be sending a request to a remote server or in this case having the Tango check on a certain aspect of the API.
```
.... // some code

Check_My_Phone_For_Something(); // Waits idle for 2 seconds

.... // more code
```
* If this was our code we would be stopping for no reason which means if someone is trying to press a button in our App it will not be able to due to the waiting
* This time we will give a **callback function** which us saying "Hey, when you are done waiting and return with some data I want you to run this function. In the meantime I am going to continue with the rest of the code under you"
```
.... // some code

Check_My_Phone_For_Something( onReturn ); // Waits idle for 2 seconds

.... // more code

void onReturn(int ValueFromCallback) {
    ... // We run this function with the values returned from callback
}
```
### Real Callback Example
In the API there is a function [TangoService_connectOnPoseAvailable](https://developers.google.com/tango/apis/c/reference/group/pose#tangoservice_connectonposeavailable)

* Notice that the last argument is of type `void(*)(void *context, const TangoPoseData *pose)`
    * This is a *Function Pointer* in C/C++ and lets break it down
    * `void(*)` means the the return type of the function we use for our callback will be `void`
    * `(void *context, const TangoPoseData *pose)` means the callback function should have two paramter of type `void*` and `const TangoPoseData`
* Here is an example of using this call
```
TangoService_connectOnPoseAvailable(1, &pair, onPoseAvailable);

void onPoseAvailable(void* context, const TangoPoseData* pose) {
    LOGI("Position: %f, %f, %f. Orientation: %f, %f, %f, %f",
         pose->translation[0], pose->translation[1], pose->translation[2],
         pose->orientation[0], pose->orientation[1], pose->orientation[2],
         pose->orientation[3]);

    // Prints out the coodinates of the TangoPoseData value when it gets it
}
```
* The idea to take away is that instead of waiting for the function to return, we give it a function to execute when it is done
* If this is still confusing do a quick [Google Search](http://lmgtfy.com/?q=C+Callback+Functions+Explained)

## Event Based Calls
If you have ever done normal Android development you will learn that it is all based on Event calls.

* Event calls are really just Callback functions that are set for us and we can't control over the naming of the function.
* Great example is `onCreate()` for Anroid as this is called by the Activity in the Java side when the class is created.
* Events on [Android Life Cycle](https://developer.android.com/guide/components/activities/activity-lifecycle.html)
* Events on [GUI Input](https://developer.android.com/guide/topics/ui/ui-events.html)

### Tango Events
Tango has a struct called [TangoEvent](https://developers.google.com/tango/apis/c/reference/struct/tango-event)

* The idea behind events are to hold data about functions that we can look at and examine
    * This is great information for debugging
* More info on [Overview of Events](https://developers.google.com/tango/overview/events)

<== [Section 3 - Tango](../README.md) -- [Chapter 2](./Chapter_02.md) ==>
