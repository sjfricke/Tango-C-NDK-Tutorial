<== [Chapter 3.2](./Chapter_03_02.md) -- [Chapter 3.4](./Chapter_03_04.md) ==>

# Chapter 3.3 - Java code explained

* There are three things you will want to add right away to your activity
1. An instance of your renderer class (explained in depth next section)
    * `private AugmentedRealityRenderer mRenderer;`
2. An instance of a GLSurfaceView for OpenGL ES to render to
    * `private GLSurfaceView mGLView;`
3. Create a screen size for normalizing the touch input for orbiting the render camera.
    * `private Point mScreenSize = new Point();`

<== [Chapter 3.2](./Chapter_03_02.md) -- [Chapter 3.4](./Chapter_03_04.md) ==>
