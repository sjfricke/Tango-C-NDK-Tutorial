
#ifndef TANGO_NDK_TUTORIAL_TANGO_NDK_TUTORIAL_H
#define TANGO_NDK_TUTORIAL_TANGO_NDK_TUTORIAL_H

#include <android/log.h>
#include <jni.h>

#include "tango_client_api.h"   // NOLINT
#include "tango_support_api.h"  // NOLINT

#include <cstdlib>

// used to get logcat outputs which can be regex filtered by the LOG_TAG
#define LOG_TAG "Tutorial_TAG"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

namespace tango_tutorial {
// TangoHandler provides functionality to communicate with the Tango Service.
    class Tango_NDK_Tutorial {
    public:
        Tango_NDK_Tutorial() : tango_config_(nullptr) {}

        Tango_NDK_Tutorial(const Tango_NDK_Tutorial& other) = delete;

        Tango_NDK_Tutorial& operator=(const Tango_NDK_Tutorial& other) = delete;

        ~Tango_NDK_Tutorial() {
            if (tango_config_ != nullptr) {
                TangoConfig_free(tango_config_);
                tango_config_ = nullptr;
            }
        }

        // Check if the Tango Core version is compatible with this app.
        // If not, the application will exit.
        //
        // @param env, java environment parameter CheckVersion is being called.
        // @param caller_activity, caller of this function.
        void OnCreate(JNIEnv* env, jobject caller_activity);

        // Called when the Tango service is connect. We set the binder object to Tango
        // Service in this function.
        //
        // @param env, java environment parameter.
        // @param iBinder, the native binder object.
        void OnTangoServiceConnected(JNIEnv* env, jobject iBinder);

        // Disconnect and stop Tango service.
        void OnPause();

    private:
        TangoConfig tango_config_;
    };
}  // namespace tango_tutorial

#endif //TANGO_NDK_TUTORIAL_TANGO_NDK_TUTORIAL_H
