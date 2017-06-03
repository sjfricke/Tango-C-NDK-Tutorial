<== [Chapter 10](./Chapter_10.md)

# Chapter 11 - Adding a GUI

Here are the steps to take to add a GUI such as a button to your NDK application

* in the `res/layout/*.xml` file create a button using the Android Studio drag and drop tool
    * In the `properties` section in the right give your item a good ID name
    * You can also change other useful information such as the text displayed
* You can set your onClick in the Main Activity programmatically or just set the onClick in the properties of the GUI.
    * **NOTE:** you need to have a function first in your main activity
* Create the function in your main activity
    * example - `public void snapShot(View view) { }`
    * **NOTE:** I have found from others that a better way of getting the click is using a `findViewById(R.id.snapshot).setOnClickListener(this);` call **after** `setContentView()`
        * This way lets you have one function to switch case the buttons
        * ```
          @Override
          public void onClick(View v) {
             // Handle button clicks.
            switch (v.getId()) {
            ...
            ...
            }
          }
          ```
* Now add a call to you JNI Native class
    *  ```
        public void snapShot(View view) {
            TangoJNINative.snapShot(1);
        }
        ```
* In you JNI Native file add the new function
    * `public static native void snapShot();`
* In the JNI_Header add if you are not auto generating it
    * ```
        Java_com_projecttango_examples_TangoJNINative_snapShot(JNIEnv*, jobject, int type)) {
            app.snapShot(type);
        }
      ```
* Add the function to you native code
    * Don't forget to declare it in your header file if needed
    * ```
        void myApp::snapShot(int type) {
            // cool stuff
        }
      ```
    
<== [Chapter 10](./Chapter_10.md)