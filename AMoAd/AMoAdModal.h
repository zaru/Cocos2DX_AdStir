#import <UIKit/UIKit.h>

@protocol AMoAdModalDelegate
-(void)AMoAdModalClickCloseButton;
@end

@interface AMoAdModal : UIViewController <UIWebViewDelegate>{
	UIWebView* browser;
	UIBarButtonItem* close_btn;
	UIBarButtonItem* forward_button;
	UIBarButtonItem* back_button;
	UIBarButtonItem* stop_button;
	UIBarButtonItem* refresh_button;
}

-(void)requestUrl:(NSString*)url;
@property (nonatomic, assign) id delegate;
@end
