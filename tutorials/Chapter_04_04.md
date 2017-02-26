<== [Chapter 4.3](./Chapter_04_03.md) -- [Chapter 5](./Chapter_05.md) ==>

# Chapter 4.4 - 3D models OBJ files

The easiest way to add a model to your AR world is via `.obj` files. These are easy to work with since they are written in plain text. The overall structure can be read more from [detail online](https://en.wikipedia.org/wiki/Wavefront_.obj_file)

Each `.obj` file can have a pairing `.mtl` file which is the Material file. This file gives the color and possible image path for how the part of the UV it covers looks. 

As of now there is no good way (that I know of at least) to read in the file since the entire NDK file is compressed and even with the use of the Asset_Manager the `.obj` file is just about unreachable and the *Hack* I found around it is to use one of these file names for the .obj file and pass it in the .obj loader anyway

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

<== [Chapter 4.3](./Chapter_04_03.md) -- [Chapter 5](./Chapter_05.md) ==>
