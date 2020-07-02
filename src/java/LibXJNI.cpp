//
// Created by cihan on 01/07/2020.
//

#include "LibXJNI.h"
#include "../core/library.h"

JNIEXPORT void JNICALL Java_LibXJNI_hello (JNIEnv* _env, jobject _this)
{
    hello_Implementation();
}
