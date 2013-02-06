//
//  AdstirAdpapriView.h
//
//  Copyright 2012-2013 UNITED, inc. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef enum {
    kAdstirAdpapriErrorTimedOut = 100,
    kAdstirAdpapriErrorParameter = 200,
    kAdstirAdpapriErrorWebview = 300,
} AdstirAdpapriError;

@protocol AdstirAdpapriDelegate;
@interface AdstirAdpapriView : UIView
@property (copy) NSString*  media;
@property (copy) NSString*  spot;
@property (assign) NSTimeInterval interval;
@property (assign) id<AdstirAdpapriDelegate> delegate;
@end

@protocol AdstirAdpapriDelegate <NSObject>
- (void)adstirAdpapriDidReceived:(AdstirAdpapriView*)view;
- (void)adstirAdpapriDidFailed:(AdstirAdpapriView*)view;
- (void)adstirAdpapriDidError:(AdstirAdpapriView*)view WithCode:(AdstirAdpapriError)code;
@end
