#include <jni.h>
#include <iostream>

JNIEnv *JNIGetEnv();

using namespace std;

JavaVM *global_jvm;
jint JNI_OnLoad(JavaVM* vm, void* reserved){
    global_jvm = vm;
}

int getInt(){
    JNIEnv *env = JNIGetEnv();

    jclass jniTestClass = env->FindClass("com/example/myapplication/JNITest");

    jmethodID getIntMethod = env->GetStaticMethodID(jniTestClass, "gerInt", "(Z)I");

    return (int)env->CallStaticIntMethod(jniTestClass, getIntMethod, (jboolean)true);
}

JNIEnv *JNIGetEnv(int *attach) {

}