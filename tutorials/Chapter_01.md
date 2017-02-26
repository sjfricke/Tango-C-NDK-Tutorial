<== [Chapter 0](./Chapter_00.md) -- [Chapter 2](./Chapter_02.md) ==>

# Chapter 1 - The 101 Basics

So if you are reading this you have decided to take the journey and develop for the Tango with the C/C++ API... Contragulations! The main reason I hope you picked this over using Unity is because you wanted either better performance for your graphics or better access to the sensor data of the Tango.

* **NOTE:** at any time you get caught upo in the lingo of these tutorials there is a [**Glossary available**](../Glossary.md) to help you out.
* We are going to assume you understand what Augmented Reality is and you are here for developing, in that case you might be asking what you need to start.
* First and foremost make sure you are aware of the two things Google did document for us.
    * [A layout guide to the API](https://developers.google.com/tango/apis/c/)
    * [A set of good samples](https://github.com/googlesamples/tango-examples-c/)
        * Note they did a good job showing how to get NDK and Android Studio installed for you and this should be the easiest part of it all... unless you are using Windows, things seem to be an extra step more complicated then.
        
## NDK - what REALLY is it
* This is what the entire [Chapter 2](./Chapter_02.md) lesson is on, the short version, just realize that Android is a Unix based OS and runs a Java Virtual Machine on top of it to allow developers to program in Java. We are using the NDK (Native Development Kit) to program our app using C++ and the built-in Android OS C++ compiler.
* You can create a NDK app **without** using Tango

## Android Studio
* You **don't** have to use Android Studio, but we are going to for this tutorial. You can also use Eclipse or Emacs, it really is a personal preference. 

## The Android Event Cycle
* A huge thing to understand is that the Tango is just an Android application which will follow the Android life cycle chart.
![Android Life Cycle](../images/Chapter_01_IMG_001.png)
* The really big idea to take from this is that there are event driven functions that will be called throughout the applications and are usually where most of the boilerplate code will go to begin with.

## Gradle
* So hopefully doing some C++ development you are familiar with the concept of makefiles, well that is a good way to think of what gradle is for Java and more importantly Android.
* Gradle works off two basic concepts: `projects` and `tasks`
* The main thing for now is to understand that Gradle is what is taking care of building and compiling the code for most the app.

<== [Chapter 0](./Chapter_00.md) -- [Chapter 2](./Chapter_02.md) ==>