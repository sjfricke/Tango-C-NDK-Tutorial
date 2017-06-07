<== [Chapter 1](./Chapter_01.md) -- [Chapter 3](./Chapter_03.md) ==>

# Chapter 2 - Setting up AndroidManifest.xml

The first thing we should do is setup the `AndroidManifest.xml` file to get all that fun configuration out of the way. [Sample AndroidManifest.xml](../Sample_Code/Tango-NDK-Tutorial/app/src/main/AndroidManifest.xml)

* The first we need to do is add this snippet inside our `<manifest>` tag

```
<uses-sdk
        android:minSdkVersion="23"
        android:targetSdkVersion="23" />
    <uses-permission android:name="android.permission.CAMERA" />
    <uses-feature android:glEsVersion="0x00030001" android:required="true" />
```
    
* The `uses-sdk` is where we set our API level as you probably could figure out
* **IMPORTANT:** You need to give permission to the camera or Tango will not be able to get data from it making this all pretty pointless already.
	* This is done by adding the `<uses-permission android:name="android.permission.CAMERA" />` line
	* More information about Android permissions for things like ADF files [check the documentation](https://developers.google.com/tango/apis/c/c-user-permissions)
* We plan to use OpenGL ES 3.1 which is guarenteed to work on all current capable Tango devices.
    
* We now need to add this in our `<Applicataion>` tag
    
```
    <uses-library
        android:name="com.projecttango.libtango_device2"
        android:required="true" />
```
* This is how load in Tango library currently out right now
        
## [Sample AndroidManifest.xml](../Sample_Code/Tango-NDK-Tutorial/app/src/main/AndroidManifest.xml)
    
<== [Chapter 1](./Chapter_01.md) -- [Chapter 3](./Chapter_03.md) ==>
