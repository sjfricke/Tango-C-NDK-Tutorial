<== [Chapter 2](https://github.com/sjfricke/Tango-C-NDK-Tutorial/blob/master/Chapter_02.md) -- [Chapter 4](https://github.com/sjfricke/Tango-C-NDK-Tutorial/blob/master/Chapter_04.md) ==>

# Chapter 3

--------

## Different Tango devices
* As of now there are only **2** Tango powered devices
    * The Tango Dev Kit ![Tango Dev Kit image](images/Chapter_03_IMG_001.png)
    * Lenovo Phab 2 Pro ![Phab 2 Pro image](images/Chapter_03_IMG_002.png)
    * **COMMING SOON** ASUS ZenFone AR ![ZenFone AR image](images/Chapter_03_IMG_003.png)
    
### Dev Kit notes
* The only thing to watch out for is if you have the Dev Kit is that the device being a few years older suffers from a few drawbacks
    * The Tegra chip is **way** less powerful then the Snapdragon 810 the Phab 2 Pro is running
    * For production uses, the Phab 2 Pro should be your "Worst Case Phone"
    * For development the Dev Kit as a few work arounds to make it work
1. You will need to make sure you are running API 19
    * The Dev Kit is capped at Android 4.4 KitKat and need to make sure to support that SDK during development
        * The Phab 2 Pro is running Android 6.0 with plans for a 7.0 upgrade in mid to late 2017
2. The Dev Kit has OpenGL ES 3.1 supported, but being API 19 there is a need for a small hack to get OpenGL ES 3.0+ to run
    * [Stack Overflow post](http://stackoverflow.com/questions/31003863/gles-3-0-including-gl2ext-h)
    * Trust me, you want to have OpenGL ES 3.0+

<== [Chapter 2](https://github.com/sjfricke/Tango-C-NDK-Tutorial/blob/master/Chapter_02.md) -- [Chapter 4](https://github.com/sjfricke/Tango-C-NDK-Tutorial/blob/master/Chapter_04.md) ==>