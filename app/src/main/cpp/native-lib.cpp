#include <jni.h>
#include <string>
#include "android/log.h"


#define LOGD(TAG, ...) __android_log_print(ANDROID_LOG_DEBUG, TAG, __VA_ARGS__)
#define TAG_JNI "TAG_JNI"


extern "C" JNIEXPORT jstring JNICALL
Java_com_noway_android_jnidemo_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
extern "C"
JNIEXPORT jint JNICALL
Java_com_noway_android_jnidemo_MainActivity_intFromJNI(JNIEnv *env, jobject thiz, jint value) {
    LOGD(TAG_JNI,"intFromJNI value = %d" ,value);
    return value;
}
extern "C"
JNIEXPORT jchar JNICALL
Java_com_noway_android_jnidemo_MainActivity_charFromJNI(JNIEnv *env, jobject thiz, jchar value) {
    LOGD(TAG_JNI,"charFromJNI value = %c" ,value);
    return value;
}
extern "C"
JNIEXPORT jboolean JNICALL
Java_com_noway_android_jnidemo_MainActivity_booleanFromJNI(JNIEnv *env, jobject thiz,
                                                           jboolean value) {
    LOGD(TAG_JNI,"booleanFromJNI value = %d" , true);
    return value;
}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_noway_android_jnidemo_MainActivity_stringFromJNI2(JNIEnv *env, jobject thiz,
                                                           jstring value) {

    LOGD(TAG_JNI,"stringFromJNI2 value = %s" ,value);
    return value;
}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_noway_android_jnidemo_MainActivity_objectFromJNI(JNIEnv *env, jobject thiz,
                                                          jobject student) {
    LOGD(TAG_JNI,"objectFromJNI value = {}" ,student);
    //类似于java里面的反射
    jclass jStudent = env->FindClass("com/noway/android/jnidemo/Student");

    //field的形式去拿值

    //获取Long类型成员变量的值
    jfieldID jfId = env->GetFieldID(jStudent,"id", "Ljava/lang/Long;");
    jlong id = (jlong)env->GetObjectField(student, jfId);


    //获取方法的值
    jmethodID  jmName = env->GetMethodID(jStudent,"getName", "()Ljava/lang/String;");
    jstring name = (jstring)env->CallObjectMethod(student,jmName);
//    LOGD(TAG_JNI,"name = %s",name);
    return name;
}
extern "C"
JNIEXPORT void JNICALL
Java_com_noway_android_jnidemo_MainActivity_callJavaFromJNI(JNIEnv *env, jobject thiz) {
//    JavaVM* javaVm;
//    env->GetJavaVM(&javaVm);
//    javaVm->AttachCurrentThread(&env, nullptr);
    jobject jgObj = env->NewGlobalRef(thiz);
    jclass jcMainActivity = env->FindClass("com/noway/android/jnidemo/MainActivity");
    jmethodID  jmCallback = env->GetMethodID(jcMainActivity, "showCallJava", "()V");

    env->CallVoidMethod(jgObj, jmCallback);

}