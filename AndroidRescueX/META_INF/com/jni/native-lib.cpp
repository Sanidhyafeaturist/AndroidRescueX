#include <jni.h>
#include <string>
#include <android/log.h>
#include <cstdlib>
#include <cstdio>

#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, "NativeApp", __VA_ARGS__))

extern "C" JNIEXPORT jstring JNICALL
Java_com_hoperescue_MainActivity_getKernelInfo(JNIEnv* env, jobject /* this */) {
    FILE *fp;
    char buffer[128];
    std::string result;

    fp = popen("uname -r", "r");
    if (fp == nullptr) {
        LOGI("Failed to run command\n");
        return env->NewStringUTF("Error");
    }

    while (fgets(buffer, sizeof(buffer), fp) != nullptr) {
        result += buffer;
    }
    pclose(fp);

    return env->NewStringUTF(result.c_str());
}

extern "C" JNIEXPORT void JNICALL
Java_com_hoperescue_MainActivity_flashZip(JNIEnv* env, jobject /* this */, jstring zipPath) {
    const char* zipPathStr = env->GetStringUTFChars(zipPath, nullptr);
    std::string command = "adb sideload " + std::string(zipPathStr);
    int result = system(command.c_str());
    if (result == 0) {
        LOGI("Flashed %s successfully.\n", zipPathStr);
    } else {
        LOGI("Failed to flash %s.\n", zipPathStr);
    }
    env->ReleaseStringUTFChars(zipPath, zipPathStr);
}

extern "C" JNIEXPORT void JNICALL
Java_com_hoperescue_MainActivity_mountPartition(JNIEnv* env, jobject /* this */, jstring partition, jstring mountPoint) {
    const char* partStr = env->GetStringUTFChars(partition, nullptr);
    const char* mountStr = env->GetStringUTFChars(mountPoint, nullptr);
    
    std::string command = "mount " + std::string(partStr) + " " + std::string(mountStr);
    int result = system(command.c_str());
    if (result == 0) {
        LOGI("Mounted %s to %s successfully.\n", partStr, mountStr);
    } else {
        LOGI("Failed to mount %s to %s.\n", partStr, mountStr);
    }
    
    env->ReleaseStringUTFChars(partition, partStr);
    env->ReleaseStringUTFChars(mountPoint, mountStr);
}
