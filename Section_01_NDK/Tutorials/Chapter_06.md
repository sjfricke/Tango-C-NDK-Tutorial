<== [Chapter 5](./Chapter_05.md) -- [Chapter 7](./Chapter_07.md) ==>


# Chapter 6 - The C/C++ API

Part of the Tango technology is the ability to get data from the hardware. The C/C++ API is what allows us to call functions that are implemented inside the Tango technology to get information from it. An example is if we want to see the depth of the object pointing at, we will need to use the API to *get* the depth data from the internal hardware.

The API is broken into 3 different parts

## [Main C/C++ API](https://developers.google.com/tango/apis/c/reference/)
The main API call that gives you access to the core parts of the service.

## [Support Library API](https://developers.google.com/tango/apis/c/support/reference/)
Another set of API calls to let you get more helpful information like "edge detection" or "depth interface support"

## [3D Reconstruction Library API](https://developers.google.com/tango/apis/c/reconstruction/reference/)
This API has a set of calls to help you scan and create 3D models from the data infront of the camear
    
<== [Chapter 5](./Chapter_05.md) -- [Chapter 7](./Chapter_07.md) ==>