<== [Section 2 - Graphics](../README.md) -- [Chapter 2](./Chapter_02.md) ==>

# Chapter 1 - Graphic APIs 101

## What is an API?
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
* There are a few different Graphic APIs
* **OpenGL**
    * Open Graphic Language
    * The standard cross platform choice that has been used for a long time now
* **OpenGL ES**
    * ES stands for Embedded Systems
    * A lighter version of OpenGL found on mobile devices as power is a huge factor for mobile design
* **WebGL**
    * A web based version  that is mainly based off OpenGL ES due to the web only able to have so much power to run
* **DirectX**
    * Microsoft version of OpenGL which is found in gaming engines for its more friendly game development traits
        * This is why you buy a PC to game
* **Metal**
    * Apple version of OpenGL which only really is found on their hardware
* **Vulkan**
    * The *young gunner on the block* who is **not** here to *replace* OpenGL, but provide developers a way of having more control to get the maximum performance out of their applications
    * **NOTE** that a 1080HD screen is 1080x1920 = 2 million pixels and if trying to run 90FPS that is 180 million pixels a second to calculate with only 11.1ms to get each frame out... Vulkan doesn't seem like a bad idea now talking about making AR more realistic.
        * Please don't try learning Vulkan without understanding graphical programming first as a whole, you **will not** find success with that

## OpenGL ES and my Tango
* So you will need to write some OpenGL ES for your Tango application if you plan on getting anything augmented to the world using the NDK.
    * Please note if you wanted to make a game for Tango we would suggest looking into the Unity API as it is made for abstracting all of this for you.
* You should assume OpenGL ES 3.1 as the lowest version to support for any production device with Tango
* If you want help there is a nice [tango_gl repo](https://github.com/sjfricke/tango_gl) we personally forked from the Google samples to make more capable of advanced tasks
    * It is not a full fledge OpenGL library, but it takes care of the whole matrix math of outputting your renderings to the screen and moving on camera movement

## What is the fastest way to learn OpenGL ES
* ... We were really hoping you weren't going to ask this, some of us may have personally have been fortunate to take a course while studying in college on graphical programming. The real question is not "how do I learn OpenGL ES" but rather "how do I learn graphical programming and the whole graphic pipeline"
* This question can be taught in two ways
    * The theoretical mathematical way of why matrix and linear algebra works
    * How do I get the most pixels flung to the screen as fast as possible
* My suggestion is take some time, like a good month of practicing and reading, on OpenGL before you even attempt to dive into the Tango code
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