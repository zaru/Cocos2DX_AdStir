#ifndef __NATIVE_CODE_LAUNCHER_JNI__
#define __NATIVE_CODE_LAUNCHER_JNI__

#include <jni.h>

extern "C"
{
	extern void startAdJNI();
	extern void stopAdJNI();
	extern void nextAdJNI();
}

#endif // __NATIVE_CODE_LAUNCHER_JNI__