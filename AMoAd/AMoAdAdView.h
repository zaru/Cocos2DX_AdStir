#import <UIKit/UIKit.h>
#import "JSONKit.h"
#import <QuartzCore/QuartzCore.h>

@class AMoAdAdView;

@protocol AMoAdAdViewDelegate
-(void)AMoAdAdViewDidReady:(AMoAdAdView*)adView;
-(void)AMoAdAdViewDidFailReady:(AMoAdAdView*)adView;
-(void)clickAdView:(NSString*)url;
@end

@interface AMoAdAdView : UIView<UIWebViewDelegate>{
	NSData* responseData;
	UIWebView* webView;
	NSString* text;
	NSUInteger type;
	NSString* targetUrl;
	CALayer* wrapLayer;
	BOOL highlighted;
	BOOL isReady;
	BOOL isTouch;
	id delegate;
	NSUInteger orientation;
	NSMutableArray* colors;
	
	NSTimer* checker;
	BOOL isThread;
	
	NSInteger sspId;
}

@property(assign, nonatomic) id delegate;
@property(assign) NSUInteger clickAnimation;

-(void)setData:(NSMutableDictionary*)jsonData;

@end
