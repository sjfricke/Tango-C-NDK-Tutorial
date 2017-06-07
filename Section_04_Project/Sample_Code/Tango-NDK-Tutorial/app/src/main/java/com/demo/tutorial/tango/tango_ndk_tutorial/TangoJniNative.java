package com.demo.tutorial.tango.tango_ndk_tutorial;

import android.app.Activity;
import android.os.IBinder;
import android.util.Log;

/**
 * Interfaces between C and Java.
 *
 * Note that these are the functions that call into native code, native code is
 * responsible for the communication between the application and Tango Service.
 */
public class TangoJniNative {
    static {
        // This project depends on tango_client_api, so we need to make sure we load
        // the correct library first.
        if (TangoInitializationHelper.loadTangoSharedLibrary() ==
                TangoInitializationHelper.ARCH_ERROR) {
            Log.e("TangoJNINative", "ERROR! Unable to load libtango_client_api.so!");
        }

        // This must match the LOAD_MODULE value in our Android.mk
        System.loadLibrary("tango_ndk_tutorial");
    }

    /**
     * Check if the Tango Core version is compatible with this app.
     * If not, the application will exit.
     *
     * @param callerActivity the caller activity of this function.
     */
    public static native void onCreate(Activity callerActivity);

    /*
     * Called when the Tango service is connected.
     *
     * @param binder The native binder object.
     */
    public static native void onTangoServiceConnected(IBinder binder);

    /**
     * Disconnect and stop Tango service.
     */
    public static native void onPause();

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public static native int valueFromJNI(int myNumber);
}
