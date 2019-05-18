#include <jni.h>
#include <string>
#include <android/log.h>
#include "src/client/linux/handler/minidump_descriptor.h"
#include "src/client/linux/handler/exception_handler.h"
#include "breakpad_lib.h"

#define  LOG_TAG    "HUNT"
#define  ALOG(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

bool DumpCallback(const google_breakpad::MinidumpDescriptor &descriptor,
                  void *context,
                  bool succeeded) {
    ALOG("native crash happen %d",succeeded);
    return succeeded;
}

void breakpadInit(JNIEnv *env, jobject obj, jstring dump_path) {
    const char *path = env->GetStringUTFChars(dump_path, 0);

    google_breakpad::MinidumpDescriptor descriptor(path);
    static google_breakpad::ExceptionHandler eh(descriptor, NULL, DumpCallback, NULL, true, -1);

    env->ReleaseStringUTFChars(dump_path, path);
}
