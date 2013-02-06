#include "NativeCodeLauncher.h"
#include "NativeCodeLauncherJni.h"

namespace Cocos2dExt
{
	void NativeCodeLauncher::startAd()
	{
		startAdJNI();
	}
	void NativeCodeLauncher::stopAd()
	{
		stopAdJNI();
	}
	void NativeCodeLauncher::nextAd()
	{
		nextAdJNI();
	}
}
