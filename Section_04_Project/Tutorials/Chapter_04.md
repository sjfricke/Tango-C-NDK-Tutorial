<== [Chapter 3.3](./Chapter_03_03.md) -- [Chapter 3.5](./Chapter_03_05.md) ==>

# Chapter 3.4

* Make sure the `local.properites` file in root folder of project points to the correct location of your SDK and NDK libraries on your machine
	* Android Studio does a good job setting this file up, but has been root of compile errors in past
	* This is why you use a .gitignore file :)

* make a folder for the JNI files
	* You can right click app and add a new JNI folder
		* ![Adding JNI folder](../Images/Project_Folder.png)
	* you should have a file `<Project>/app/src/main/jni`
	* it defaults with a `cpp` folder, you can keep it, but for the tutorials we will refer to the file as the `jni` folder and also assumes you renamed the `cpp` folder or removed it

* Open `app/build.gradle`
* Get rid of all cmake calls and replace with ndk call
	* You can remove the `app/CMakelist.txt` file as well
	* Add `ndk { abiFilters 'armeabi-v7a', 'arm64-v8a', 'x86' } ` to have it build for all three ISA types
	* If you are not planning on running unit test you can remove the JUint calls as well
	* add ```externalNativeBuild { ndkBuild { path 'src/main/jni/Android.mk' } } ```	
	* See example at [sampleCode]() for an example of a build.gradle for the project

* Create your two make files
	* Create `app/src/main/jni/Android.mk` and `app/src/main/jni/Application.mk`
	* **Note:** the files won't appear in Android studio if the folder is completly empty so you may need to use other file system methods to create the file


<== [Chapter 3.3](./Chapter_03_03.md) -- [Chapter 3.5](./Chapter_03_05.md) ==>
