<== [Chapter 2](./Chapter_02.md) -- [Chapter 4](./Chapter_04.md) ==>

# Chapter 3 - Loading Tango API Libraries

The Tango API's are just like any C library where you have your include folder with the header files, the lib folder with the compiled shared library file and now its just a matter of have it build along with your Android APK.

### Where is the library
* The download site currently is [on the offical Google Tango Developer site](https://developers.google.com/tango/downloads)
* You will want to download at least the client API (also named *Tango SDK for C* on site)
	* Also download the support API or 3D Reconstruction as needed

### How to add it to Android.mk
* First note, the names of files/folders are mainly arbitrary, but for best interest I would advise you to stick with the below naming conventions.
* We first will start by making a folder called `tango_client_api` to hold the library
* Inside we will have two subfolders: `include` and `lib`
	* `include` will hold the `tango_client_api.h` header file
	* `lib` will have a subfolder for each architecture
		* Note: if you know for sure you only need one then have one
		* The two subfolders used here are `arm64-v8a` and `armeabi-v7a`
		* Each of these subfolders contain the `libtango_client_api.so` library
		* For this tutorial you will also need the `libtango_client_stub.a` file in your `lib` folder [found here](../../Section_04_Project/Sample_Code/tango_client_api/lib/libtango_client_stub.a). This static file is JUST for the client API
* To build this library itself we will include an `Android.mk` file inside the `tango_client_api` folder.
	* You can find the file [here](../../Section_04_Project/Sample_Code/tango_client_api/Android.mk), but we are also going to break down what the `Android.mk` file is doing:
	```
	LOCAL_PATH := $(call my-dir)

	include $(CLEAR_VARS)
	LOCAL_MODULE := tango_client_api

	ifeq ($(TARGET_ARCH), arm64)
	  LOCAL_EXPORT_LDLIBS := -L$(LOCAL_PATH)/lib/arm64-v8a -ltango_client_api
	endif

	ifeq ($(TARGET_ARCH), arm)
	  LOCAL_EXPORT_LDLIBS := -L$(LOCAL_PATH)/lib/armeabi-v7a -ltango_client_api
	endif

	LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/include
	LOCAL_SRC_FILES := lib/libtango_client_stub.a

	include $(PREBUILT_STATIC_LIBRARY)
	```
	* First we always start our makefiles with defining the `LOCAL_PATH` to the directory our `Android.mk` lives. Then we also always call `include $(CLEAR_VARS)` to clear unwanted local enviroment variables.
	* We load the module by name which in this case we just left out the "lib" prefix
	* Next we decided which architecture its building for and link it to the path of the `.so` file as well and telling the linker to include it with the `-ltango_client_api` flag
	* Next we export include the header file location
	* For the client API **ONLY** we also include the static file we added
	* Last thing we do is tell it generate the library as a Prebuilt Static library
* We repeat the steps above for the support and 3D Reconstruction API as needed and then we can now add it to the main `Android.mk` project file
* Here is the link to the [main project Android.mk file](../../Section_04_Project/Sample_Code/Tango-NDK-Tutorial/app/src/main/cpp/Android.mk) which we now need to add a few lines
* `LOCAL_SHARED_LIBRARIES := tango_client_api` is where we declare the shared libraries we plan to include
* `$(call import-add-path, $(PROJECT_ROOT))` is used to add the folder location of your `tango_client_api` folder locations
	* Note: If you want to move your `tango_client_api` folder just create a path to the directory and add another line such as `$(call import-add-path, $(PATH_TO_MY_TANGO_CLIENT_API_FOLDER))` for example
* The last thing we need to do is actually import the module we built using `$(call import-module,tango_client_api)` which calls it in.

<== [Chapter 2](./Chapter_02.md) -- [Chapter 4](./Chapter_04.md) ==>
