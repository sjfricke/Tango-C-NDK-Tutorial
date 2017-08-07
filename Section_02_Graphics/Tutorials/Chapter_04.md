<== [Chapter 3](./Chapter_03.md)

# Chapter 4 - 3D Model Files

## Files are just protocols
* If there is a cube with 8 vertices, 6 faces, etc, this can be represented in various ways.
* Each file format is given a standard/protocol how to store the data for a 3D model.
* It is up to the application to unpack it, parse it, and format it the way to allow for use in the application.

## [OBJ files](https://en.wikipedia.org/wiki/Wavefront_.obj_file)
* The easiest way to add a model to your AR world is via `.obj` files. These are easy to work with since they are written in plain text.
* Each `.obj` file can have a pairing `.mtl` file which is the Material file. This file gives the color and possible image path for how the part of the UV it covers looks.
* **Note:** OBJ files only represent geometrey and can not hold information about animation.

## [PLY files](https://en.wikipedia.org/wiki/PLY_%28file_format%29)
* This is like the OBJ files that is designed to be human readable, but is used for point cloud data.
* PLY files is comprised of a header section where it represents all meta data.
* The rest of the file is listing all the values of each point in the point cloud

## [Draco](https://google.github.io/draco/)
* Draco is an open-source library for compressing and decompressing 3D geometric meshes and point clouds. It is intended to improve the storage and transmission of 3D graphics.

## [glTF](https://www.khronos.org/gltf)
* Specification for the efficient transmission and loading of 3D scenes and models by applications.
* Minimizes both the size of 3D assets, and the runtime processing needed to unpack and use those assets.

## NOTE
* In the Google samples they store all the data in a header file which works but also defeats the simplicity of just taking in any valid `.obj` file.

<== [Chapter 3](./Chapter_03.md)
