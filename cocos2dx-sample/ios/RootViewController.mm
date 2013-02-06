//
//  cocos2dx_sampleAppController.h
//  cocos2dx-sample
//
//  Created by zaru on 2013/01/29.
//  Copyright __MyCompanyName__ 2013年. All rights reserved.
//

#import "RootViewController.h"

@interface RootViewController()<ASTDelegateProtocol>
@property (nonatomic,retain) ASTAdView* adview;
@end

@implementation RootViewController


/*
 // The designated initializer.  Override if you create the controller programmatically and want to perform customization that is not appropriate for viewDidLoad.
 - (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
 if ((self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil])) {
 // Custom initialization
 }
 return self;
 }
 */

/*
 // Implement loadView to create a view hierarchy programmatically, without using a nib.
 - (void)loadView {
 }
 */

/*
 // Implement viewDidLoad to do additional setup after loading the view, typically from a nib.
 - (void)viewDidLoad {
 [super viewDidLoad];
 }
 
 */
// Override to allow orientations other than the default portrait orientation.
// This method is deprecated on ios6
- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation {
    //return UIInterfaceOrientationIsLandscape( interfaceOrientation );
    return UIInterfaceOrientationIsPortrait( interfaceOrientation );
}

// For ios6, use supportedInterfaceOrientations & shouldAutorotate instead
- (NSUInteger) supportedInterfaceOrientations{
#ifdef __IPHONE_6_0
    //return UIInterfaceOrientationMaskLandscape;
    return UIInterfaceOrientationMaskPortrait;
#endif
}

- (BOOL) shouldAutorotate {
    return YES;
}

- (void)didReceiveMemoryWarning {
    // Releases the view if it doesn't have a superview.
    [super didReceiveMemoryWarning];
    
    // Release any cached data, images, etc that aren't in use.
}

- (void)viewDidUnload {
    [super viewDidUnload];
    // Release any retained subviews of the main view.
    // e.g. self.myOutlet = nil;
}


- (void)dealloc {
    [super dealloc];
}


// 広告表示
-(void)startAd
{
	if(!self.adview)
	{
		self.adview = [ASTAdView requestWithAppId:@"MEDIA-メディアID" andSpotNo:@"広告枠" andDelegate:self];
		[self.view addSubview:self.adview];
		
		// 画面下に表示
		CGRect winSize = [[UIScreen mainScreen] bounds];
		//CGRect adviewRect = CGRectMake(0, winSize.size.height - 50, winSize.size.width, 50);
		CGRect adviewRect = CGRectMake(0, 0, 320, 50);
		self.adview.frame = adviewRect;
		
		[self.adview start];
        NSLog(@"Ad Start--------------------");
	}
	else
	{
		NSLog(@"Ad already started.");
	}
}

// 広告非表示
-(void)stopAd
{
	if(self.adview)
	{
		[self.adview stop];
		[self.adview removeFromSuperview];
		self.adview = nil;
	}
	else
	{
		NSLog(@"Ad already stopped.");
	}
}

// 次の広告を表示
-(void)nextAd
{
	[self.adview nextAd];
}

// ASTDelegateProtocol

- (void) didFailToInitView:(NSString *)appId{
	[self.adview stop];
	[self.adview removeFromSuperview];
	self.adview = nil;
}

- (UIViewController *) currentViewController{
	return self;
}

- (void) didFailToUpdateConfig{
	NSLog(@"didFailToUpdateConfig!");
}

- (void) didLoadAdView{
	NSLog(@"didLoadAdView!");
}
- (void) didFailToLoadAdView{
	NSLog(@"didFailToLoadAdView!");
	
	[self.adview nextAd];
}

- (CGPoint) originOfAdView{
	return CGPointMake(0, 0);
}
// テスト版を表示するかどうか
-(BOOL)astTestMode
{
#ifdef DEBUG
	return YES;
#else
	return NO;
#endif
}

@end
