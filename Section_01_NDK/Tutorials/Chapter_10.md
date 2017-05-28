<== [Chapter 9](./Chapter_09.md) -- [Chapter 11](./Chapter_11.md) ==>

# Chapter 10 - Debugging

## adb (Android Debug Bridge)
* adb is the main way to debug your code. It is built into Android Studios and also capable of being used from your terminal as well on the local machine
    * Open a terminal and type `adb device` and see if your device appears
* A popular command you will see is `adb logcat` which is where all your `printf()` are going
    * **Suggestion** is to use it in Android Studio  so you can filter it out and avoid the huge amount of noise

## Android logging helper
* Android has a nice logging library to help you more easily log to adb instead of using `printf()`

```
#include <android/log.h>
#define LOG_TAG "My_NDK_App"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
```

* This now lets you easily create log write with custome tags and different status
* Example:
	* `LOGI("Position: %f, %f, %f", pos->x, pos->y, pos->z);` will print `I My_NDK_APP: Position: 0.169661, 0.135381, 0.455411`
	* `LOGE("Invalid Value: %s", ErrorString);` will print `E My_NDK_APP: Invalid value: Overflow Value`

<== [Chapter 9](./Chapter_09.md) -- [Chapter 11](./Chapter_11.md) ==>