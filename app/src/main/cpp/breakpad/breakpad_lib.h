//
// Created by eastern on 2019/5/18.
//

#ifndef NATIVETEST_BREAKPAD_LIB_H
#define NATIVETEST_BREAKPAD_LIB_H

#include <jni.h>

#ifdef __cplusplus
extern "C" {
#endif

#define XHOOK_EXPORT __attribute__((visibility("default")))

void breakpadInit(
        JNIEnv *env,
        jobject obj, jstring dump_path);

#ifdef __cplusplus
}
#endif
#endif //NATIVETEST_BREAKPAD_LIB_H
