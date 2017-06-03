<== [Chapter 1](./Chapter_01.md) -- [Chapter 3](./Chapter_03.md) ==>

# Chapter 2 - Graphic Pipeline 101

This is going to be a **really** quick overview of graphical programming as there are tons of better tutorials out there already.

## The goal
* When doing anything graphical the overall **goal** is take take data represented in 3-dimensions and have it so it's displayed on the screen.
* We do this by taking data that would normally go into our RAM and used by our CPU and send it to the GPU so it can handle the task of filling in the pixels that will be displayed every frame. 

## Graphic Pipeline in 10 over simplified quick steps
1. Get all the vertices that make up your scene
2. Give each vertex info about its color, normal, texture mapping
3. Make sure all buffered objects such as images are mapped and allocated
4. Run all the vertices through a `vertex shader` and produce shapes
5. Touch up results, such as getting rid of vertices out of the view window
6. Rasterize them to give you a fragment to work with
7. Run all the fragments through a `fragment shader` to decide on a color
8. Have test to decide which fragment becomes the pixel and what color it is
9. Push the data to the screen
10. Repeat hopefully over 60 times a second

## Extra Sources
* [Tutorial by Joe Groff](http://duriansoftware.com/joe/An-intro-to-modern-OpenGL.-Chapter-1:-The-Graphics-Pipeline.html)

<== [Chapter 1](./Chapter_01.md) -- [Chapter 3](./Chapter_03.md) ==>
