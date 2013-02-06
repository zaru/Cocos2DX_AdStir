#ifndef _NATIVE_CODE_LAUNCHER_H_
#define _NATIVE_CODE_LAUNCHER_H_

#include <stddef.h>

namespace Cocos2dExt {
    class NativeCodeLauncher
    {
    public:
		static void startAd();
		static void stopAd();
		static void nextAd();
    };
} // end of namespace Cocos2dExt

#endif // _NATIVE_CODE_LAUNCHER_H_
