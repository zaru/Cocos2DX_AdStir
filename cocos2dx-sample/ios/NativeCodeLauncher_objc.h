#import "CocosDenshion.h"
#if __IPHONE_OS_VERSION_MIN_REQUIRED >= 30000
#import <AVFoundation/AVFoundation.h>
#else
#import "CDXMacOSXSupport.h"
#endif

@interface NativeCodeLauncher : NSObject

+(void)startAd;
+(void)stopAd;
+(void)nextAd;

@end
