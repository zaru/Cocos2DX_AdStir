//
//  cocos2dx_sampleAppController.h
//  cocos2dx-sample
//
//  Created by zaru on 2013/01/29.
//  Copyright __MyCompanyName__ 2013年. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AdStir/ASTAdView.h>
#import <AdStir/ASTDelegateProtocol.h>


@interface RootViewController : UIViewController <ASTDelegateProtocol>{
}

// Adstir
-(void)startAd;
-(void)stopAd;
-(void)nextAd;

@end
