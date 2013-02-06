//
//  AdstirRtbView.h
//
//  Copyright 2012-2013 UNITED, inc. All rights reserved.
//

#ifndef Adstir_AdstirRtbView_h
#define Adstir_AdstirRtbView_h

#define AST_RTB_BANNER (CGSizeMake(320,50))
#define AST_RTB_DEFAULT (CGSizeMake(320,50))

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol AdstirRtbDelegate;

@interface AdstirRtbView : UIView
+ (AdstirRtbView*) rtbViewWithFrame:(CGRect)frame andMedia:(NSString*)media andSpot:(NSString*)spot andDelegate:(id<AdstirRtbDelegate>)delegate andViewController:(UIViewController*)viewController;
@end

@protocol AdstirRtbDelegate <NSObject>
//広告が取得出来た際に呼ばれます
- (void)adstirRtbDidReceived:(AdstirRtbView*)view;
//広告が取得出来なかった際に呼ばれます
- (void)adstirRtbDidFailed:(AdstirRtbView*)view;
@end

#endif
