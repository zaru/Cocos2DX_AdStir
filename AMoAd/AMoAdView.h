#import <UIKit/UIKit.h>
#import "AMoAdAdView.h"
#import "AMoAdModal.h"

@class AMoAdView, AMoAdStorage;

//ローテーションアニメーション
typedef enum {
    AMoAdViewAnimationTransitionNone,
    AMoAdViewAnimationTransitionFlipFromLeft,
    AMoAdViewAnimationTransitionFlipFromRight,
    AMoAdViewAnimationTransitionCurlUp,
    AMoAdViewAnimationTransitionCurlDown,
} AMoAdViewAnimationTransition;

//クリックアニメーション
typedef enum {
    AMoAdViewClickAnimationTransitionNone,
    AMoAdViewClickAnimationTransitionJump,
} AMoAdViewClickAnimationTransition;

typedef enum {
	AMoAdContentSizeIdentifierPortrait = 1,
	AMoAdContentSizeIdentifierLandscape = 2,
} AMoAdContentSizeIdentifier;

@protocol AMoAdViewDelegate
@optional
- (void)AMoAdView:(AMoAdView *)adView didFailToReceiveAdWithError:(NSError *)error;
- (void)AMoAdViewDidReceiveEmptyAd:(AMoAdView *)adView;
- (void)AMoAdViewDidReceiveAd:(AMoAdView *)adView;
@end

@interface AMoAdView : UIView<AMoAdAdViewDelegate, AMoAdModalDelegate>{
@private
	NSString *sid;
	id delegate;
	NSMutableArray *displayedAids;
	int currentContentSizeIdentifier;
	NSString* ua;
	NSString* uid;
	BOOL enableRotation;
	NSMutableDictionary* jsonData;
	NSThread* timer;
	NSTimer* checker;
	BOOL isThread;	
	AMoAdAdView* nextView;
	AMoAdStorage* storage;
	NSString* domain;
	NSString* name;
	long interval;
}

@property (nonatomic, retain) NSString *sid;
@property (nonatomic, assign) id delegate;
@property (nonatomic) AMoAdContentSizeIdentifier currentContentSizeIdentifier;
@property (nonatomic) BOOL enableRotation;
@property (nonatomic) BOOL enableModal;
@property (nonatomic, assign) AMoAdViewAnimationTransition rotationAnimationTransition;
@property (nonatomic, assign) AMoAdViewClickAnimationTransition clickAnimationTransition;
@property (nonatomic, assign) id rootController;

- (void)displayAd;
- (void)startRotation;
- (void)stopRotation;
@end