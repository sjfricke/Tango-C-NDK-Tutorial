<== [Chapter 1](./Chapter_01.md) -- [Chapter 3](./Chapter_03.md) ==>

# Chapter 2 - Tango Device 101

## Different Tango devices
* As of now there are only **3** Tango powered devices
    * The Tango Dev Kit ![Tango Dev Kit image](../Images/Development_Kit.png)
    * Lenovo Phab 2 Pro ![Phab 2 Pro image](../Images/Lenovo_Phab_2_Pro.png)
    * ASUS ZenFone AR ![ZenFone AR image](../Images/ASUS_Zenfone_AR.png)
    
### Dev Kit notes
* The only thing to watch out for is if you have the Dev Kit is that the device being a few years older suffers from a few drawbacks
    * The old Tegra chip is **way** less powerful than the Snapdragon 652 the Phab 2 Pro is running
      * The Snapdragon 652 was built on the Adreno 510 GPU
      * The ASUS ZenFone AR is coming with a Snapdragon 821 with the Adreno 530 GPU
    * For production uses, the Phab 2 Pro should be your "Worst Case Phone" for a user to have
    * For development the Dev Kit has a few work arounds to make it work like the Phab 2 Pro due to being capped at Android KitKat
1. You will need to make sure you are running API 19 (if using Dev Kit)
    * The Dev Kit is capped at Android 4.4 KitKat and need to make sure to support that SDK during development
        * The Phab 2 Pro is running Android 6.0 with plans for a 7.0 upgrade in mid to late 2017
        * If you are skipping the dev kit then you will not need API 19
2. The Dev Kit has OpenGL ES 3.1 supported, but being API 19 there is a need for a small hack to get OpenGL ES 3.0+ to run
    * [Stack Overflow post](http://stackoverflow.com/questions/31003863/gles-3-0-including-gl2ext-h)
    * Trust me, you want to have OpenGL ES 3.0+

## Tango API
* The API is broken into 3 different parts
* **[Main C/C++ API](https://developers.google.com/tango/apis/c/reference/)**
    * The main API call that gives you access to the core parts of the service.
* **[Support Library API](https://developers.google.com/tango/apis/c/support/reference/)**
    * Another set of API calls to let you get more helpful information like "edge detection" or "depth interface support"
* **[3D Reconstruction Library API](https://developers.google.com/tango/apis/c/reconstruction/reference/)**
    * This API has a set of calls to help you scan and create 3D models from the data in front of the camera

<== [Chapter 1](./Chapter_01.md) -- [Chapter 3](./Chapter_03.md) ==>
