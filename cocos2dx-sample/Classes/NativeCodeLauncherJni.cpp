#include "NativeCodeLauncherJni.h"
#include <android/log.h>
#include "platform/android/jni/JniHelper.h"

#define  LOG_TAG    "NativeCodeLauncher"
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
//#define  CLASS_NAME "org/cocos2dx/lib/Cocos2dxActivity"
#define CLASS_NAME "com/yourcompany/cocos2dx/sample/Cocos2DXSample1"

typedef struct JniMethodInfo_
{
    JNIEnv *    env;
    jclass      classID;
    jmethodID   methodID;
} JniMethodInfo;

extern "C"
{
	// get env and cache it
	static JNIEnv* getJNIEnv(void)
	{
		JNIEnv *env = 0;

		// get jni environment
		if (cocos2d::JniHelper::getJavaVM()->GetEnv((void**)&env, JNI_VERSION_1_4) != JNI_OK)
		{
			LOGD("Failed to get the environment using GetEnv()");
		}

		if (cocos2d::JniHelper::getJavaVM()->AttachCurrentThread(&env, 0) < 0)
		{
			LOGD("Failed to get the environment using AttachCurrentThread()");
		}

		return env;
	}

	// get class and make it a global reference, release it at endJni().
	static jclass getClassID(JNIEnv *pEnv)
	{
		jclass ret = pEnv->FindClass(CLASS_NAME);
		if (! ret)
		{
			LOGD("Failed to find class of %s", CLASS_NAME);
		}

		return ret;
	}

	static bool getStaticMethodInfo(JniMethodInfo &methodinfo, const char *methodName, const char *paramCode)
    {
		jmethodID methodID = 0;
		JNIEnv *pEnv = 0;
		bool bRet = false;

        do 
        {
			pEnv = getJNIEnv();
			if (! pEnv)
			{
				break;
			}

            jclass classID = getClassID(pEnv);

            methodID = pEnv->GetStaticMethodID(classID, methodName, paramCode);
            if (! methodID)
            {
                LOGD("Failed to find static method id of %s", methodName);
                break;
            }

			methodinfo.classID = classID;
			methodinfo.env = pEnv;
			methodinfo.methodID = methodID;

			bRet = true;
        } while (0);

        return bRet;
    }

    
	void startAdJNI()
	{
		JniMethodInfo methodInfo;
        
        if (!getStaticMethodInfo(methodInfo, "startAd", "()V"))
        {
            return;
        }
        
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID);
		methodInfo.env->DeleteLocalRef(methodInfo.classID);
	}
	void stopAdJNI()
	{
		JniMethodInfo methodInfo;
        
        if (!getStaticMethodInfo(methodInfo, "stopAd", "()V"))
        {
            return;
        }
        
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID);
		methodInfo.env->DeleteLocalRef(methodInfo.classID);
	}
	void nextAdJNI()
	{
		JniMethodInfo methodInfo;
        
        if (!getStaticMethodInfo(methodInfo, "nextAd", "()V"))
        {
            return;
        }
        
		methodInfo.env->CallStaticVoidMethod(methodInfo.classID, methodInfo.methodID);
		methodInfo.env->DeleteLocalRef(methodInfo.classID);
	}
}
