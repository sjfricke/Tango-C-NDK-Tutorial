#include "Tango_NDK_Tutorial.h"

namespace {
    constexpr int kTangoCoreMinimumVersion = 9377;
    void onPoseAvailable(void*, const TangoPoseData* pose) {
        LOGI("Position: %f, %f, %f. Orientation: %f, %f, %f, %f",
             pose->translation[0], pose->translation[1], pose->translation[2],
             pose->orientation[0], pose->orientation[1], pose->orientation[2],
             pose->orientation[3]);
    }
}  // anonymous namespace.

namespace tango_tutorial {

    void Tango_NDK_Tutorial::OnCreate(JNIEnv* env, jobject caller_activity) {
        // Check the installed version of the TangoCore.  If it is too old, then
        // it will not support the most up to date features.
        int version = 0;
        TangoErrorType err =
                TangoSupport_GetTangoVersion(env, caller_activity, &version);
        if (err != TANGO_SUCCESS || version < kTangoCoreMinimumVersion) {
            LOGE("Tango_NDK_Tutorial::CheckVersion, Tango Core version is out of date.");
            std::exit(EXIT_SUCCESS);
        }
    }

    void Tango_NDK_Tutorial::OnTangoServiceConnected(JNIEnv* env, jobject iBinder) {
        if (TangoService_setBinder(env, iBinder) != TANGO_SUCCESS) {
            LOGE("Tango_NDK_Tutorial::ConnectTango, TangoService_setBinder error");
            std::exit(EXIT_SUCCESS);
        }

        // TANGO_CONFIG_DEFAULT is enabling Motion Tracking and disabling Depth
        // Perception.
        tango_config_ = TangoService_getConfig(TANGO_CONFIG_DEFAULT);
        if (tango_config_ == nullptr) {
            LOGE("Tango_NDK_Tutorial::ConnectTango, TangoService_getConfig error.");
            std::exit(EXIT_SUCCESS);
        }

        // TangoCoordinateFramePair is used to tell Tango Service about the frame of
        // references that the applicaion would like to listen to.
        TangoCoordinateFramePair pair;
        pair.base = TANGO_COORDINATE_FRAME_START_OF_SERVICE;
        pair.target = TANGO_COORDINATE_FRAME_DEVICE;
        if (TangoService_connectOnPoseAvailable(1, &pair, onPoseAvailable) !=
            TANGO_SUCCESS) {
            LOGE("Tango_NDK_Tutorial::ConnectTango, connectOnPoseAvailable error.");
            std::exit(EXIT_SUCCESS);
        }

        if (TangoService_connect(nullptr, tango_config_) != TANGO_SUCCESS) {
            LOGE("Tango_NDK_Tutorial::ConnectTango, TangoService_connect error.");
            std::exit(EXIT_SUCCESS);
        }
    }

    void Tango_NDK_Tutorial::OnPause() {
        TangoConfig_free(tango_config_);
        tango_config_ = nullptr;
        TangoService_disconnect();
    }
}  // namespace tango_tutorial
