<== [Chapter 4.2](./Chapter_04_02.md) -- [Chapter 4.4](./Chapter_04_04.md) ==>

# Chapter 4.3 - OpenGL ES part 2

In this section we are going to go through a run down of the entire graphic pipeline. **This is intended** for those with little to no knowledge to get somewhat up to speed what is going on. This also serves as a great review for those who haven't played with graphics in a while.

**NOTE:** There is a (set of vocabulary)[#vocabulary] fo common words you might get stuck on

# Disclaimer
There are **MANY** more in depth explainations of the graphic pipeline and this is only a taste of the tip of the ice berg intended to help someone with little knowledge. This is just the information needed for someone to get their Tango app up off the ground, not for getting hired at a AAA Gaming Studio.

## The goal
When doing anything graphical the overall **goal** is take take data represented in 3-dimensions and have it so its displayed on the screen. We do this by taking data that would normally go into our RAM and used by our CPU and send it to the GPU so it can handle the task of filling in the pixels that will be displayed every frame. 

## Setting up shaders

## Getting the data

## Running the draw call each frame

## Vocabulary
This list out **all** the upcoming vocab, so don't be afraid to scroll back when you get stuck. Note these are NOT offical terms, but rather a "what you need to know about them" definition.

* Buffer
    * A way of holding data as it comes in and queue the data when needed
    * A queue data structure
* Clipping
    * A way of setting a limit how far out in the world you are going to have the graphics render
    * Anything outside the clipping zone will not be seen also known as "clipped"
* Fragment
    * -
* Frame
    * A complete set of all the pixels that make up your drawing screen.
    * There is a *Frame Buffer* in charge of holding all the upcoming **frames** to draw to the screen
* Material
    * -
* Mesh
    * -
* Pixel
    * One of many small squares on your screen that display the image. Each pixel can have a range of colors from being mixed with red, green, blue
* Rasterization
    * -
* Render
    * -
* Shader
    * -
* Texture
    * -
* Transform
    * -
* Vector
    * A way of expressing a direction and how much in that direction.
    * Represented by `vec2`, `vec3`, and `vec4` where a vec3 means a 3D vector with vec3.x, vec3.y, vec3.z
    * You use a **vector** to say "move the ball in this direction by this much"
* Vertex
    * A 3D point represented by 3 floats `(x-coord, y-coord, z-coord)`
    * A cube has 8 vertices, each corner makes up a point in space or a **vertex**


<== [Chapter 4.2](./Chapter_04_02.md) -- [Chapter 4.4](./Chapter_04_04.md) ==>
