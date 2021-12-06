#include <jni.h>
#include "react-native-jsi-module.h"

extern "C"
JNIEXPORT void JNICALL
Java_com_reactnativejsimodule_JsiModule_nativeInstall(JNIEnv *env, jobject thiz, jlong jsi) {
    auto runtime = reinterpret_cast<facebook::jsi::Runtime *>(jsi);
    if (runtime) {
        example::install(*runtime);
    }
}
