[Section 2 - Graphics](../Section_02_Graphics) ==>

# Section 1 - Android NDK
* A big part of working with [Tango C/C++ API](https://developers.google.com/tango/apis/c/) is understanding the world of [Andorid NDK](https://developer.android.com/ndk/index.html) which is not a common thing to find good documentation on the web sadly.

## What This Section Is
* A set of tutorials to get you up on the basic of NDK.
* A way of teaching the difference between a "NDK Problem" and a "Tango Problem" as you start developing.
* All the NDK info to get a basic Tango project going and being capable of configuring it.
* How to layout a NDK project and all its different sections.

## What This Section Is NOT
* A way to learn about the Tango API
    * That is [Section 3](../Section_03_Tango)
    
### Android Studio
* The preferred way as shown in these tutorials is to use Android Studio.
    * Android Studio version 2.3.2 or higher please.
* However, we will still reference everything agnostic to your personal preference of work environment.
    * You are totally capable of using any other IDE.
        * Maybe you just want to do it all in emacs, be my guest.

# Table Of Content
* [Chapter 1 - **Android 101**](./Tutorials/Chapter_01.md)
    * Everything about Android in general to know.
* [Chapter 2 - **What is NDK**](./Tutorials/Chapter_02.md)
    * What and why you are using NDK.
* [Chapter 3 - **Directory Layout**](./Tutorials/Chapter_03.md)
    * The overall layout of a project.
* [Chapter 4 - **The Java Source**](./Tutorials/Chapter_04.md)
    * The separate UI thread in Java.
* [Chapter 5 - **The Java Native**](./Tutorials/Chapter_05.md)
    * Telling Java to use native code.
* [Chapter 6 - **The JNI Header**](./Tutorials/Chapter_06.md)
    * Header file to link native and Java together.
* [Chapter 7 - **The Native Code**](./Tutorials/Chapter_07.md)
    * Writing native C code.
* [Chapter 8 - **The Makefiles**](./Tutorials/Chapter_08.md)
    * Using ndk-build to build the project.
* [Chapter 9 - **Adding a library**](./Tutorials/Chapter_09.md)
    * How to add libraries to your project.
* [Chapter 10 - **Debugging**](./Tutorials/Chapter_10.md)
    * How to use adb and logcat to debug.   
* [Chapter 11 - **Adding a GUI**](./Tutorials/Chapter_11.md)
    * How to add a button and other GUI elements.        
        
[Section 2 - Graphics](../Section_02_Graphics) ==>