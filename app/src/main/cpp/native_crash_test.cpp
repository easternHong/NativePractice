#include <jni.h>
#include <string>
#include "breakpad_lib.h"

extern "C" JNIEXPORT jstring JNICALL
Java_test_eastern_com_nativetest_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";

    return env->NewStringUTF(hello.c_str());
}

extern "C" JNIEXPORT jstring JNICALL
Java_test_eastern_com_nativetest_MainActivity_breakpadInit(
        JNIEnv *env,
        jobject obj, jstring dump_path) {
    breakpadInit(env, obj, dump_path);
}

extern "C" JNIEXPORT jstring JNICALL
Java_test_eastern_com_nativetest_MainActivity_testNativeCrash(
        JNIEnv *env,
        jobject obj) {

    char *name = NULL;

    name = "nihao";
    int a = 1 / 0;
}


JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *env;
    if (vm->GetEnv((void **) &env, JNI_VERSION_1_6) != JNI_OK) {
        return JNI_ERR;
    }
    return JNI_VERSION_1_6;
}