//
//  ASTAdView.h
//
//  Copyright 2011-2013 UNITED, inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol ASTDelegateProtocol <NSObject>
@required
// Adビューは初期化失敗した。
- (void) didFailToInitView:(NSString *)appId;
// 
- (UIViewController *) currentViewController;

@optional
// 設定更新タイマー ディフォールトで30分間に一回
- (NSTimeInterval) updateConfigInterval;

- (void) didUpdateConfig;
- (void) didFailToUpdateConfig;

- (void) didLoadAdView;
- (void) didFailToLoadAdView;

// 親ビューにあるバナーの原点（左上の点）座標
- (CGPoint) originOfAdView;

// テストモードフラグを返却する。
// エミュレーターで実行する際に、
// AdMobはテストモードで実行しなければいけないので、
// YESを返却してください。
- (BOOL) astTestMode;
@end