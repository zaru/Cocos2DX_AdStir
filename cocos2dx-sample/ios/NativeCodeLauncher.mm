#include "NativeCodeLauncher.h"
#include "NativeCodeLauncher_objc.h"

static void static_startAd()
{
	[NativeCodeLauncher startAd];
}
static void static_stopAd()
{
	[NativeCodeLauncher stopAd];
}
static void static_nextAd()
{
	[NativeCodeLauncher nextAd];
}

namespace Cocos2dExt
{
	void NativeCodeLauncher::startAd()
	{
		static_startAd();
	}
	void NativeCodeLauncher::stopAd()
	{
		static_stopAd();
	}
	void NativeCodeLauncher::nextAd()
	{
		static_nextAd();
	}
}