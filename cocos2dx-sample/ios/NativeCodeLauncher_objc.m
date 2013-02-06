#import "AppController.h"
#import "NativeCodeLauncher_objc.h"
#import "EAGLView.h"

@implementation NativeCodeLauncher

+(void)startAd
{
	AppController *appController = (AppController *)[UIApplication sharedApplication].delegate;
	[appController.viewController startAd];
}
+(void)stopAd
{
	AppController *appController = (AppController *)[UIApplication sharedApplication].delegate;
	[appController.viewController stopAd];
}
+(void)nextAd
{
	AppController *appController = (AppController *)[UIApplication sharedApplication].delegate;
	[appController.viewController nextAd];
}

@end
