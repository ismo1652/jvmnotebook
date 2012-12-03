////

#include <jni.h>
#include "Hello.h"
#include <iostream>

using namespace std;

JNIEXPORT void JNICALL Java_Hello_hello(JNIEnv *env, jobject obj) {
    cout << "Hello" << endl;
    return;
}
