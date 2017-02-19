<== [Chapter 3](https://github.com/sjfricke/Tango-C-NDK-Tutorial/blob/master/Chapter_03.md) -- [Chapter 5](https://github.com/sjfricke/Tango-C-NDK-Tutorial/blob/master/Chapter_05.md) ==>


# Chapter 4

This is a very graphic heavy section as grapics is a vitale part of developing for the Tango
--------

## OpenGL ES

So if you are already familier with OpenGL ES and know what it is all about then I congratulate you and advise to go to next chapter

so you stuck around I see, where he is the laydown

## What is OpenGL?
* So first to answer this it is important you understand that a computer normally runs off of three parts, the CPU, RAM, and Hard Drive.
    * When you open up Chrome/FireFox your computer's CPU figures out it needs the 1GB worth of data that is used to run the browser and goes to the Hard Drive to get it.
    * Since it takes **WAY** longer to get the Hard Drive realitve to the CPU speed it holds that 1GB in your RAM so it can access it faster
* So what happens when your computer wants to run 4GB-8GB worth of graphical data to let you play that Skyrim at Ultra High settings running 60+ FPS... its gonna want to use your Graphic Card, but how does it tell it what to do?
* This is where a "Graphic API" comes in, its job is to talk to your hardware about doing its job.
* There are a few different Graphic APIs
    * OpenGL
        * Open Graphic Language
        * The standard cross plateform choice that has been used for a long time now
    * OpenGL ES
        * ES stands for Embedded Systems
        * A lighter version of OpenGL found on mobile devices as power is a huge factor for mobile design
    * WebGL
        * A web based verison that is mainly based off OpenGL ES due to the web only able to have so much power to run
    * DirectX
        * Microsoft version of OpenGL which is found in gaming engines for its more friendly game development traits
            * This is why you buy a PC to game
    * Vulkan
        * The *young gunner on the block* who is not here to *replace* OpenGL, but provide developers a way of having more control to get the maximum performance out of their applications
        * **NOTE** that a 1080HD screen is 1080x1920 = 2 million pixels and if trying to run 90FPS that is 180 million pixels a second to calulate with only 11.1ms to get each frame out... Vulkan doesn't seem like a bad idea now talking about making AR more realistic.
            * Please don't try learning Vulkan without understanding graphical programming first as a whole, you **will not** find success with that

## OpenGL ES and my Tango
* So you will need to write some OpenGL ES for your Tango applcation if you plan on getting any thing augmented to the world using the NDK.
    * Please note if you wanted to make a game for Tango I would suggest looking into the Unity API as it is made for abstracting all of this for you.
* You should assume OpenGL ES 3.1 as the lowest version to support for any production device
* If you want help there is a nice [tango_gl repo](https://github.com/sjfricke/tango_gl) I personally forked from the Google samples to make more capable of advance tasks
    * It is not a full fledge OpenGL library, but it takes care of the whole matrix math of outputing your renderings to the screen and moving on camera movement

## Whats the fastest way to learn OpenGL ES
* ... I was really hoping you weren't going to ask this, I personally was fortunate to take a course while studying in college on graphical programming. The real question is not "how do I learn OpenGL ES" but rather "how do I learn graphical programming and the whole graphic pipeline"
* This question can be taught in two ways
    * The theoretical mathametic way of why matrix and linear alebra works
    * How do I get the most pixels flung to the screen as fast as possible
* My suggestion is take some time, like a good month of practicing and reading, on OpenGL before you even attempt to dive into the Tango code
* Here are some really good sources
    * [The Awesome-OpenGL page](https://github.com/eug/awesome-opengl)
    * [The Awesome-Courses page](https://github.com/prakhar1989/awesome-courses#computer-graphics) (Graphic section)

## Things you should be comfortable with before dealing with the Tango
* Do you understand what a vertex and fragment shader are
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
    
<== [Chapter 3](https://github.com/sjfricke/Tango-C-NDK-Tutorial/blob/master/Chapter_03.md) -- [Chapter 5](https://github.com/sjfricke/Tango-C-NDK-Tutorial/blob/master/Chapter_05.md) ==>