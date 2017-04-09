<== [Chapter 3.1](./Chapter_03_01.md) -- [Chapter 3.3](./Chapter_03_03.md) ==>

# Chapter 3.2 - Getting the Java code

* If it create `public class MainActivity extends AppCompatActivity {` replace it with `public class MainActivity extends Activity {`
	* You will need to add `import android.app.Activity;`


* Create a new class `TangoInitializationHelper` inside your Java folder
	* Copy code from [sampleCode](../sampleCode/java/TangoInitializationHelper.java)	

* Create a new class `GLSurfaceRenderer` inside your Java folder
	* Copy code from [sampleCode](../sampleCode/java/GLSurfaceRenderer.java)

* Create a new class `TangoJNINative` inside your Java folder
	* Copy code from [sampleCode](../sampleCode/java/TangoJNINative.java)
	

* We can then get rid of the `static { System.loadLibrary("native-lib"); }` call in the MainActivity as we we call `loadTangoSharedLibrary()` from the `TangoJNINative` class which is implemented in `TangoInitializationHelper`
	* This will do the checking of finding the correct native library to use
* Also get rid of `public native String stringFromJNI();`
* Clean the `onCreate` function as we will rewrite it below


* Inside MainActivity add these two lines

	```
	// GLSurfaceView and renderer, all of the graphic content is rendered
    // through OpenGL ES 2.0 in native code.
    private GLSurfaceView mGLView;
    private GLSurfaceRenderer mRenderer;
    ```

    * Then add

    ```
     // Tango Service connection.
    ServiceConnection mTangoServiceConnection = new ServiceConnection() {
        public void onServiceConnected(ComponentName name, IBinder service) {
            TangoJNINative.onTangoServiceConnected(service);
            setAndroidOrientation();
        }

        public void onServiceDisconnected(ComponentName name) {
            // Handle this if you need to gracefully shutdown/retry
            // in the event that Tango itself crashes/gets upgraded while running.
        }
    };
    ```

    * For screen rotation

    ```
	// Pass device's camera sensor rotation to native layer.
	// This parameter is important for Tango to render video overlay and
	// virtual objects in the correct device orientation.
	private void setAndroidOrientation() {
		Display display = getWindowManager().getDefaultDisplay();

		TangoJNINative.onDisplayChanged(display.getRotation());
	}
    ```

    * To enable the xml display

    ```
	private void configureGlSurfaceView() {
        // OpenGL view where all of the graphics are drawn.
        mGLView = (GLSurfaceView) findViewById(R.id.gl_surface_view);

        mGLView.setEGLContextClientVersion(2);

        // Configure OpenGL renderer. The RENDERMODE_WHEN_DIRTY is set explicitly
        // for reducing the CPU load. The request render function call is triggered
        // by the onTextureAvailable callback from the Tango Service in the native
        // code.
        mRenderer = new GLSurfaceRenderer(getAssets());
        mGLView.setRenderer(mRenderer);
    }
    ```

    * onCreate()

	```
     @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        TangoJNINative.onCreate(this);

        getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN,
                WindowManager.LayoutParams.FLAG_FULLSCREEN);

        // Register for display orientation change updates.
        DisplayManager displayManager = (DisplayManager) getSystemService(DISPLAY_SERVICE);
        if (displayManager != null) {
            displayManager.registerDisplayListener(new DisplayManager.DisplayListener() {
                @Override
                public void onDisplayAdded(int displayId) {}

                @Override
                public void onDisplayChanged(int displayId) {
                    synchronized (this) {
                        setAndroidOrientation();
                    }
                }

                @Override
                public void onDisplayRemoved(int displayId) {}
            }, null);
        }

        // Setting content view of this activity and getting the mIsAutoRecovery
        // flag from StartActivity.
        setContentView(R.layout.activity_main);

        configureGlSurfaceView();
    }
    ```

    * onResume

    ```
     @Override
    protected void onResume() {
        super.onResume();
        mGLView.onResume();

        mGLView.setRenderMode(GLSurfaceView.RENDERMODE_CONTINUOUSLY);

        TangoInitializationHelper.bindTangoService(this, mTangoServiceConnection);
    }
    ```

    * onPause

    ```
    @Override
    protected void onPause() {
        super.onPause();
        mGLView.onPause();

        TangoJNINative.onPause();
        unbindService(mTangoServiceConnection);
    }

    ```

    * onDestory
    
    ```
    @Override
    protected void onDestroy() {
        super.onDestroy();
        TangoJNINative.onDestroy();
    }
    ```


* activity_main.xml
	* Get rid of padding
	* add
	
	```
	<android.opengl.GLSurfaceView
        android:id="@+id/gl_surface_view"
        android:layout_width="fill_parent"
        android:layout_height="fill_parent"
        android:layout_gravity="top" />

    ```
    
<== [Chapter 3.1](./Chapter_03_01.md) -- [Chapter 3.3](./Chapter_03_03.md) ==>
