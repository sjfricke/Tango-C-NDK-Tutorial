<== [Section 2 - Graphics](../README.md) -- [Chapter 2](./Chapter_02.md) ==>

# Chapter 1 - Graphic APIs 101

## What is an Graphics API?
* An API ([Application Programming Interface](https://en.wikipedia.org/wiki/Application_programming_interface)) is way to "tap into" code.
* A good analogy: A bank has to be able to both deposit and withdrawal money from you account and want to let you do it without needing a human tell do it. At the same the bank does **NOT** trust you to just enter a deposit as a bank tell does, so they give you an ATM machine (which is our API in this case). You have a way of using there service without ever having to know how to "actually" deposit money into the bank.
* The API for our GPU will let us send commands to it to perform actions without ever having to understand what the command is doing under the hood. We still need full knowledge of what the API call will do in terms of effecting our graphic project.

## How a computer works
* It is important you understand that a computer normally runs off of three parts: CPU, RAM, and Hard Drive.
    * When you open up Chrome/FireFox your computer's CPU figures out it needs the 1GB worth of data that is used to run the browser and goes to the Hard Drive to get it.
    * Since it takes **WAY** longer to get the Hard Drive relative  to the CPU speed it holds that 1GB in your RAM so it can access it faster
* So what happens when your computer wants to run 4GB-8GB worth of graphical data to let you play that Skyrim at Ultra High settings running 60+ FPS... its gonna want to use your Graphic Card, but how does it tell it what to do?
* This is where a `Graphic API` comes in, its job is to talk to your hardware about doing its job.

## Examples of Graphic API

There are a few different common Graphic APIs

* **OpenGL**
    * Open Graphic Language
    * The standard cross platform choice that has been used for a long time now.
        * Mainly for desktops only.
* **OpenGL ES**
    * ES stands for Embedded Systems
    * A lighter version of OpenGL found on mobile devices as power is a huge factor for mobile design.
* **WebGL**
    * A web based version that is based off OpenGL ES due to the web having to work the same across every platform.
* **DirectX**
    * Microsoft version of OpenGL which is found only for Window based devices.
* **Metal**
    * Apple version of OpenGL which is found on their hardware.
* **Vulkan**
    * The new API that was designed to allow full control over the GPU and with that comes with a huge learning curve.
    * **NOTE** that a 1080HD screen is 1080x1920 = 2 million pixels and if trying to run 90FPS that is 180 million pixels a second to calculate with only 11.1ms to get each frame out... Vulkan doesn't seem like a bad idea now talking about making AR more realistic and smooth.
        * Please don't try learning Vulkan without understanding ~~graphical programming~~ GPU pipeline first as a whole, you **will not** find success with that.

## OpenGL ES and my Tango
* So you will need to write some OpenGL ES for your Tango application if you plan on getting anything augmented to the world using the NDK.
    * Please note if you wanted to make a *small and quick* game for Tango we would suggest looking into the Unity API as it is made for abstracting all of this for you.
* You should assume OpenGL ES 3.1 as the lowest version to support for any production device with Tango
* If you want help there is a nice [tango_gl repo](https://github.com/sjfricke/tango_gl) we personally forked from the Google samples to make more capable of advanced tasks
    * It is not a full fledge OpenGL library, but it takes care of the whole matrix math of outputting your renderings to the screen and moving on camera movement.

## Vulkan and my Tango
* Currently the Phab 2 Pro only supports Android M (API 23). Once there is an update for Android N then all Tango production devices will be capable to support Vulkan.
    * Vulkan only runs on Android N or higher.
    * **Update:** The Phab 2 Pro is now not expected to get an [Android N Update](https://phandroid.com/2017/08/11/lenovo-phab-2-pro-android-nougat-update/)

## WebGL and my Tango
* Google has created an experimental WebAR [branch of Chromium](https://github.com/googlevr/chromium-webar) that can run on a Tango enabled device.
* It uses the Tango NDK to API calls wrapped in a way to be called safely from the browser.
* **NOTE** This is a experimental project and a cross web standard will be needed before you can rely on it being used in a production build.

## What is the fastest way to learn OpenGL ES
* This question can be taught in two ways
    * The theoretical mathematical way of why matrix and linear algebra works
    * How do I get the most pixels flung to the screen as fast as possible
* My suggestion is take some time reading up on OpenGL ES before you even attempt to dive into the Tango code.
    * Creating a few simple demos is a great idea as well.
* Here are some really good sources
    * [The Awesome-OpenGL page](https://github.com/eug/awesome-opengl)
    * [The Awesome-Courses page](https://github.com/prakhar1989/awesome-courses#computer-graphics) (Graphic section)

## Things you should be comfortable with before dealing with the Tango
* Do you understand what a vertex and fragment shaders are
    * What is there difference and why is it a big difference
    * Capable of reading and writing basic GLSL code
* Transformation, Scaling, and Rotation
    * Homogenous coordinates
    * Column-row major order
    * Model View Projection
* Buffers
    * Vertex Buffer Object vs Vertex Array Object
    * Vertex vs Normal vs Textures vs Indices
* How to handle when nothing appears on the screen
    * What if there is nothing on the debug log    

<== [Section 2 - Graphics](../README.md) -- [Chapter 2](./Chapter_02.md) ==>
