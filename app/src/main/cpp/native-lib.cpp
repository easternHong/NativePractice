#include <jni.h>
#include <string>

#include "sub_module.h"
#include "common.h"

extern "C" JNIEXPORT jstring JNICALL
Java_test_eastern_com_nativetest_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";

    test_sub_module();
    ALOG("nihao a");
    return env->NewStringUTF(hello.c_str());
}
