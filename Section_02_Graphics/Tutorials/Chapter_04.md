<== [Chapter 3](./Chapter_03.md) -- [Chapter 5](./Chapter_05.md) ==>

# Chapter 4 - 3D Model Files

## Files are just protocols
* If there is a cube with 8 vetices, 6 faces, etc, this can be represented in various ways.
* Each file format is given a standard/protocol how to store the data for a 3D model.
* It is up to the application to unpack it, parse it, and format it the way to allow for use in the application.

## OBJ files
* The easiest way to add a model to your AR world is via `.obj` files. These are easy to work with since they are written in plain text. The overall structure can be read more from [detail online](https://en.wikipedia.org/wiki/Wavefront_.obj_file)
* Each `.obj` file can have a pairing `.mtl` file which is the Material file. This file gives the color and possible image path for how the part of the UV it covers looks. 
* As of now there is no good way (that I know of at least) to read in the file since the entire NDK file is compressed and even with the use of the Asset_Manager the `.obj` file is just about unreachable and the *Hack* we found around it is to use one of these file names for the .obj file and pass it in the .obj loader anyway

```
static const char* kNoCompressExt[] = {
    ".jpg", ".jpeg", ".png", ".gif",
    ".wav", ".mp2", ".mp3", ".ogg", ".aac",
    ".mpg", ".mpeg", ".mid", ".midi", ".smf", ".jet",
    ".rtttl", ".imy", ".xmf", ".mp4", ".m4a",
    ".m4v", ".3gp", ".3gpp", ".3g2", ".3gpp2",
    ".amr", ".awb", ".wma", ".wmv"
};
```
## NOTE
* In the Google samples they store all the data in a header file which works but also defeats the simplicity of just taking in any valid `.obj` file.

# HELP
* If you know a better way to open and read an .obj file without having to change its extension, let us know!

<== [Chapter 3](./Chapter_03.md) -- [Chapter 5](./Chapter_05.md) ==>
