//
//  ASTAdView.h
//
//  Copyright 2011-2013 UNITED, inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ASTDelegateProtocol.h"

@class ASTAdNetworkAdapter;
@class ASTConfig;

@interface ASTAdView : UIView
@property (copy) NSString * appId;
@property (copy) NSString * adSpotNo;

+ (ASTAdView *) requestWithAppId:(NSString *) appId
                     andDelegate:(id<ASTDelegateProtocol>) delegate;
+ (ASTAdView *) requestWithAppId:(NSString *) appId andSpotNo:(NSString *)adSpotNo
                     andDelegate:(id<ASTDelegateProtocol>) delegate;

- (void) start;
- (void) nextAd;
- (void) pause;
- (void) stop;

@end
