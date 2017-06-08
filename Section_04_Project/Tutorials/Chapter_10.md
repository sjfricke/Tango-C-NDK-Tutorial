<== [Chapter 9](./Chapter_09.md) -- [Chapter 11](./Chapter_11.md) ==>

# Chapter 10 - Main Native C/C++ code part 2
Now that we have got our Gradle working correctly we can now more easily work on our main native code!

* So I am going to just link the [Tango_NDK_Tutorial.cpp](../Sample_Code/Tango-NDK-Tutorial/app/src/main/cpp/Tango_NDK_Tutorial.cpp) and [Tango_NDK_Tutorial.h](../Sample_Code/Tango-NDK-Tutorial/app/src/main/cpp/Tango_NDK_Tutorial.h) files here and go over how they work snippet at a time from here

# Tango_NDK_Tutorial.h
* The first we do is make sure to include the JNI library and the Tango APIs being used
```
#include <jni.h>
#include "tango_client_api.h"
#include "tango_support_api.h"  // Optional API
```
* To make things easier we also define some logging tools in this demo so we log out to logcat easier
	* Example: `LOGI("You will see this part printed out in logcat with value %d", someValue)`
	* This works the same as `printf` formatting
	* With this you will be able to filter out all the *Tutorial_TAG* logs later so make sure to use a meaniful naming for the tags of your logs to make debugging easier.
		* Change the `#define LOG_TAG "Tutorial_TAG"` with a different tag if you want
* The rest of the header is very standard for C++ programmer, but will help fill a few gaps if you are new to that (I would highly suggest learning about standard C++ OOP before getting knee deep in NDK development)
	* Since we included this header in our `native-lib.cpp` file we need to make sure to declare each function
	* Since we are using a namespace you need to reference this class as *NAMESPACE::CLASS* or for this case `tango_tutorial::Tango_NDK_Tutorial`
	* We have a private local instance of `TangoConfig tango_config_` which we will use later.

# Tango_NDK_Tutorial.cpp
You Made it! If you got here you got through the boring setup and now we can start coding with the Tango API!

* This file is split into our main Tango usage in the `namespace tango_tutorial {}` while we create an *anonymous namespace* above to keep hold of more general items
* If you are not up too speed with some of the techincal aspect going on make sure to checkout the [Coding Techincal Stuff Section](../../Section_03_Tango/Tutorials/Chapter_01.md#error-type)

### void Tango_NDK_Tutorial::OnCreate
* We need to first address what to do when our MainActivity calls the `onCreate` function
* We call `TangoSupport_GetTangoVersion(env, caller_activity, &version);` which will return the version of our Tango Core
to `version`
* We then can compare the version with a minimum version we have set to prevent people with outdated Tango to use our application
	* Note I have yet to find anywhere online what core version are needed to use features, but I figure this is for future ground breaking changes they might add one day.
	* Currently I am running verison 16016 as of writing this tutorial

### void Tango_NDK_Tutorial::OnTangoServiceConnected
This is where we do all of our *setup* and get Tango up and running

* First we need to just run `TangoService_setBinder(env, iBinder)` which will take the `JNIEnv* env, jobject iBinder` values passed in
	* This is how Tango takes in the `IBinder service` value we created in our Java MainActivity.
	* This right here will link the Tango service and we can techinically begin using it if it returns `TANGO_SUCCESS`

* Next we need to setup our `TangoConfig tango_config_` value.
* Tango comes with many different API features and it would be wasteful to turn them all on if we are not using them all. To save power and processing we tell Tango which feature we want to use in our TangoConfig value
* There are two ways to set up the `TangoConfig`
	1. Use a preset [TangoConfig Type](https://developers.google.com/tango/apis/c/reference/group/enums#tangoconfigtype)
		* This what we use for our tutorial demo
		* By calling `tango_config_ = TangoService_getConfig(TANGO_CONFIG_DEFAULT);` we give our `TangoConfig` permission to use Motion Tracking but we have turn off Depth Perception and the rest of the settings
	2. We can add each `TangoConfig` setting one at a time by using the [Tango Config Refernce Guide](https://developers.google.com/tango/apis/c/reference/group/config-params)
		* To add Depth Perception we would call
		```
		// Sets our TangoConfig 'config_enable_depth' configuration on for use
		TangoConfig_setBool(tango_config_, "config_enable_depth", true);

		// Tells Tango to get depth as pointcloud of type XYZC
		TangoConfig_setInt32(tango_config_, "config_depth_mode", TANGO_POINTCLOUD_XYZC);
		```
		* Here we make a call first to `TangoConfig_setBool` to toggle on the setting and then another to `TangoConfig_setInt32` to tell what depth mode options we want to include as well
		* Again, you will need to consult the [Tango Config Reference](https://developers.google.com/tango/apis/c/reference/group/config-params) for knowing what you need to enable and set
* Next since we are using the Motion sensor we need to tell Tango abour the Frame of Reference being used
	* More info about that can be found in [Frame of Reference Chapter](../../Section_03_Tango/Tutorials/Chapter_07.md)
* Once we set our `TangoCoordinateFramePair` to be what we want we need to call the `TangoService_connectOnPoseAvailable` function to set up what do with our position data.
	* The first two arguments are for telling which `TangoCoordinateFramePair` to use
	* The third argument is where we tell it to call the `onPoseAvailable` function whenever it gets a new set of Motion Tracking position values
* The last thing we need to do is set the configurations with `TangoService_connect(nullptr, tango_config_)` and we are all connected!

### void Tango_NDK_Tutorial::OnPause
If we pause our application we need to take the correct steps to get Tango disconnected correctly. What we need to do is well self documented from good naming conventions on Tango's part.

* The first thing we call is `TangoConfig_free(tango_config_);` which will properly free the `TangoConfig` object
* It is good memory managment practice to set the point to null to prevent it being seen as valid else where in the program
	* `tango_config_ = nullptr;`
* Last we call `TangoService_disconnect();` where Tango will unbind the service for use we have on it

### void onPoseAvailable
This is our callback we set whenever Tango has Pose data available. Again very well sell documented with good naming conventions

* It returns `const TangoPoseData* pose` which we can use to print out the value in this case
* Each pose has its XYZ position and its XYZW orientation.
* If you want to learn more about what values are in the Pose just check the [Pose Reference](https://developers.google.com/tango/apis/c/reference/struct/tango-pose-data)


<== [Chapter 9](./Chapter_09.md) -- [Chapter 11](./Chapter_11.md) ==>