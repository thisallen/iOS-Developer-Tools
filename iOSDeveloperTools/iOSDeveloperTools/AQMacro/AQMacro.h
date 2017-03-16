//
//  AQMacro.h
//  iOSDeveloperTools
//
//  Created by Allen on 17/3/16.
//  Copyright © 2017年 AllenQin. All rights reserved.
//

#ifndef AQMacro_h
#define AQMacro_h



#ifdef DEBUG
//--> 0.开发环境中,模拟自动专用标示符 1为是,0为否
#define AutoLogin 0
#define AutoRegist 1

#else
// 上线环境中,全部为0,即否
#define AutoLogin 0
#define AutoRegist 0
#endif


//--> 1.常用公共头文件

//#import "ACCHTTPTool.h"
//#import "ACCAccountTool.h"
//#import "Masonry.h"
//#import "UIView+FrameExtension.h"
//#import "MJExtension.h"
//#import "ACCLabel.h" // 带inset的label
//#import "ACCButton.h" // 能调整图片和文字相对位置的button
//#import "ACCTextField.h"
//#import "ACCBigButton.h"
//#import "MBProgressHUD.h"
//#import "UIImage+Color.h"
//#import "UIButton+Position.h"
//#import "WPHotspotLabel.h"
//#import "WPAttributedStyleAction.h"
//#import "NSString+WPAttributedMarkup.h"
//#import <SDWebImage/UIImageView+WebCache.h>
//
//#import "TPKeyboardAvoidingScrollView.h"
//#import "UIScrollView+TPKeyboardAvoidingAdditions.h"

//--> 2.获取宽高尺寸
// 需要横屏或者竖屏，获取屏幕宽度与高度
#if __IPHONE_OS_VERSION_MAX_ALLOWED >= 80000 // 当前Xcode支持iOS8及以上

#define SCREEN_WIDTH ([[UIScreen mainScreen] respondsToSelector:@selector(nativeBounds)]?[UIScreen mainScreen].nativeBounds.size.width/[UIScreen mainScreen].nativeScale:[UIScreen mainScreen].bounds.size.width)
#define SCREEN_HEIGHT ([[UIScreen mainScreen] respondsToSelector:@selector(nativeBounds)]?[UIScreen mainScreen].nativeBounds.size.height/[UIScreen mainScreen].nativeScale:[UIScreen mainScreen].bounds.size.height)
#define SCREEN_SIZE ([[UIScreen mainScreen] respondsToSelector:@selector(nativeBounds)]?CGSizeMake([UIScreen mainScreen].nativeBounds.size.width/[UIScreen mainScreen].nativeScale,[UIScreen mainScreen].nativeBounds.size.height/[UIScreen mainScreen].nativeScale):[UIScreen mainScreen].bounds.size)
#else
#define SCREEN_WIDTH [UIScreen mainScreen].bounds.size.width
#define SCREEN_HEIGHT [UIScreen mainScreen].bounds.size.height
#define SCREEN_SIZE [UIScreen mainScreen].bounds.size
#endif
//相对iphone5 屏幕宽度比
#define kWidth_ScaleToiPhone5    [UIScreen mainScreen].bounds.size.width/320.0f
//各种设备及模式
#define iPhone4 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 960), [[UIScreen mainScreen] currentMode].size) : NO)
#define iPhone5 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 1136), [[UIScreen mainScreen] currentMode].size) : NO)
#define iPhone6 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(750, 1334), [[UIScreen mainScreen] currentMode].size) : NO)
#define iPhone6Plus ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1242, 2208), [[UIScreen mainScreen] currentMode].size) : NO)
#define iPhone6PlusBigMode ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1125, 2001), [[UIScreen mainScreen] currentMode].size) : NO)

#define GScreenSize   [[UIScreen mainScreen] bounds].size
#define GScreenWidth  [[UIScreen mainScreen] bounds].size.width
#define GScreenHeight [[UIScreen mainScreen] bounds].size.height

//--> 3.判断当前的iPhone设备
//判断是否为iPhone
#define IS_IPHONE (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)
//判断是否为iPad
#define IS_IPAD (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
//判断是否为ipod
#define IS_IPOD ([[[UIDevice currentDevice] model] isEqualToString:@"iPod touch"])
// 判断是否为 iPhone 5或5SE
#define iPhone5_5s [[UIScreen mainScreen] bounds].size.width == 320.0f && [[UIScreen mainScreen] bounds].size.height == 568.0f
// 判断是否为iPhone 6/6s
#define iPhone6_6s [[UIScreen mainScreen] bounds].size.width == 375.0f && [[UIScreen mainScreen] bounds].size.height == 667.0f
// 判断是否为iPhone 6Plus/6sPlus
#define iPhone6Plus_6sPlus [[UIScreen mainScreen] bounds].size.width == 414.0f && [[UIScreen mainScreen] bounds].size.height == 736.0f

//--> 4.获取系统版本
#define IOS_SYSTEM_VERSION [[[UIDevice currentDevice] systemVersion] floatValue]
//判断 iOS 8 或更高的系统版本
#define IOS_VERSION_8_OR_LATER (([[[UIDevice currentDevice] systemVersion] floatValue] >=8.0)? (YES):(NO))

//--> 5.字体与颜色
#define SYS_FONT(x)     [UIFont systemFontOfSize:x]
#define SYS_FONT_SMALL  [UIFont systemFontOfSize:12]    //小字体
#define SYS_FONT_MIDDLE [UIFont systemFontOfSize:14]    //中字体
#define SYS_FONT_BIG    [UIFont systemFontOfSize:16]    //大字体

#define SYS_FONT_Weight(x, y)     [UIFont systemFontOfSize:x weight:y]

//RGB
#define RGBA(r, g, b, a) [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:a]
#define RGB(r, g, b)     [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:1]

//随机颜色
#define kRandomColor RGB(arc4random_uniform(255), arc4random_uniform(255), arc4random_uniform(255))
// clear背景颜色
#define kClearColor [UIColor clearColor]
//
#define kWhiteColor [UIColor whiteColor]
//
#define kBlackColor [UIColor blackColor]
//默认背景色
#define kBackgroundColor RGB(240, 240, 240)
//默认分割线色
#define kSeperateLineColor RGB(187, 187, 187)
//默认Placeholder色
#define kPlaceholderColor RGB(163, 163, 179)
//默认View中大按钮深红色
#define kButtonColor RGB(219, 44, 44)

//--> 6.weak对象
#define ACCWeakObj(o) autoreleasepool{} __weak typeof(o) o##Weak = o;
#define ACCStrongObj(o) autoreleasepool{} __strong typeof(o) o = o##Weak;

//--> 7.消息中心
#define NotificationCenter [NSNotificationCenter defaultCenter]

//--> 8.获取图片资源
// 普通方法
#define kGetImage(imageName) [UIImage imageNamed:[NSString stringWithFormat:@"%@",imageName]]
// 类方法
#define kGetLocalImage(imageName) setImage:[UIImage imageNamed:[NSString stringWithFormat:@"%@",imageName]]
#define kGetWebImage(imageName) sd_setImageWithURL:[NSURL URLWithString:[NSString stringWithFormat:@"%@",imageName]] placeholderImage:[UIImage imageNamed:@"FangXing-PlaceHolder.png"]
#define kGetWebImageWithHolder(imageName, holder) sd_setImageWithURL:[NSURL URLWithString:imageName] placeholderImage:[UIImage imageNamed:holder]
#define kGetBGViewFor(viewName)
//viewName.backgroundColor = kBackgroundColor;\
//viewName.backgroundView = [[UIImageView alloc] initWithImage:kGetImage(@"placeHolder.png")];\
//viewName.backgroundView.contentMode = UIViewContentModeCenter;
//--> 9.设置加载提示框（第三方框架：MBProgressHUD）
// 加载提示器
#define kShowHUDAndActivity kShowHUD;kShowNetworkActivityIndicator()
// 隐藏提示器
#define kHiddenHUDAndAvtivity kHiddenHUD;kHideNetworkActivityIndicator()

// 添加文字提示框(显示1s)
#define kShowHUDWithTitle(title) MBProgressHUD *hud = [MBProgressHUD showHUDAddedTo:kWindow animated:YES]; \
hud.mode = MBProgressHUDModeText;\
hud.label.text = NSLocalizedString(title, @"HUD preparing title"); \
[hud hideAnimated:YES afterDelay:1.f];

// 添加红色文字提示框(显示2s)
#define kShowRedHUDWithTitle(title) MBProgressHUD *hud = [MBProgressHUD showHUDAddedTo:kWindow animated:YES]; \
hud.mode = MBProgressHUDModeText;\
hud.label.text = NSLocalizedString(title, @"HUD preparing title"); \
hud.contentColor = [UIColor colorWithRed:0.9f green:0.f blue:0.f alpha:1.f];\
hud.offset = CGPointMake(0.f, -MBProgressMaxOffset); \
[hud hideAnimated:YES afterDelay:2.f];

#define kShowHUDLoadingWith(title) MBProgressHUD *hud = [MBProgressHUD showHUDAddedTo:kWindow animated:YES]; \
hud.label.text = NSLocalizedString(title, @"HUD preparing title"); \
hud.minSize = CGSizeMake(150.f, 100.f); \
hud.backgroundView.style = MBProgressHUDBackgroundStyleSolidColor;  \
hud.backgroundView.color = [UIColor colorWithWhite:0.f alpha:0.3f];

#define kShowHUDCompleteWith(title) dispatch_async(dispatch_get_main_queue(), ^{    \
MBProgressHUD *hud = [MBProgressHUD HUDForView:kWindow];    \
UIImage *image = [[UIImage imageNamed:@"Checkmark"] imageWithRenderingMode:UIImageRenderingModeAlwaysTemplate]; \
UIImageView *imageView = [[UIImageView alloc] initWithImage:image]; \
hud.customView = imageView; \
hud.mode = MBProgressHUDModeCustomView; \
hud.label.text = NSLocalizedString(title, @"HUD completed title"); \
hud.backgroundView.color = kClearColor; \
[hud hideAnimated:YES afterDelay:0.3f]; \
});
//*------------- 以下是细节,用上面两个就行 ---------------*/
// 状态栏网络状态显示
#define kShowNetworkActivityIndicator() [UIApplication sharedApplication].networkActivityIndicatorVisible = YES
// 状态栏网络状态不显示
#define kHideNetworkActivityIndicator() [UIApplication sharedApplication].networkActivityIndicatorVisible = NO
// 状态栏网络状态是否显示
#define NetworkActivityIndicatorVisible(x)  [UIApplication sharedApplication].networkActivityIndicatorVisible = x
// 获取kWindow
#define kWindow [UIApplication sharedApplication].keyWindow
// 在kWindow上添加提示器
#define kShowHUD [MBProgressHUD showHUDAddedTo:kWindow animated:YES]
// 隐藏kWindow上得提示器
#define kHiddenHUD [MBProgressHUD hideHUDForView:kWindow animated:YES]

// 在kwindow上自定义提示器
#define kShowMyHud MBProgressHUD *hud = [MBProgressHUD showHUDAddedTo:kWindow animated:YES];\
hud.mode = MBProgressHUDModeAnnularDeterminate;\
hud.labelText = @"Loading";\
NSProgress *progress = [self doSomethingInBackgroundCompletion:^{\
[hud hide:YES];\
}];\
hud.progressObject = progress
// 隐藏kwindow上自定义提示器

//--> 10.数据库表名
#define Document_Path  NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES)[0]

//--> 11.设置 view 圆角和边框
#define SetViewBorderRadius(View, Radius, Width, Color)\
\
[View.layer setCornerRadius:(Radius)];\
[View.layer setMasksToBounds:YES];\
[View.layer setBorderWidth:(Width)];\
[View.layer setBorderColor:[Color CGColor]]

//--> 12.由角度转换弧度 由弧度转换角度
#define DegreesToRadian(x) (M_PI * (x) / 180.0)
#define RadianToDegrees(radian) (radian*180.0)/(M_PI)

//--> 13.获取当前语言
#define LRCurrentLanguage ([[NSLocale preferredLanguages] objectAtIndex:0])

//--> 14.使用 ARC 和 MRC
#if __has_feature(objc_arc)
// ARC
#else
// MRC
#endif
//--> 15.判断是真机还是模拟器
#if TARGET_OS_IPHONE
//iPhone Device
#endif

#if TARGET_IPHONE_SIMULATOR
//iPhone Simulator
#endif

//--> 16.沙盒目录文件
//获取temp
#define kPathTemp NSTemporaryDirectory()

//获取沙盒 Document
#define kPathDocument [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject]

//获取沙盒 Cache
#define kPathCache [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) firstObject]

//--> 17.GCD 的宏定义
//GCD - 一次性执行
#define kDISPATCH_ONCE_BLOCK(onceBlock) static dispatch_once_t onceToken; dispatch_once(&onceToken, onceBlock);

//GCD - 在Main线程上运行
#define kDISPATCH_MAIN_THREAD(mainQueueBlock) dispatch_async(dispatch_get_main_queue(), mainQueueBlock);

//GCD - 开启异步线程
#define kDISPATCH_GLOBAL_QUEUE_DEFAULT(globalQueueBlock) dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), globalQueueBlocl);

//--> 18.自定义高效率的 DLog
#ifdef DEBUG
#define AQLog(...) NSLog(@"%s 第%d行 \n %@\n\n",__func__,__LINE__,[NSString stringWithFormat:__VA_ARGS__])
#else
#define AQLog(...)
#endif

//#if DEBUG
//#define NSLog(FORMAT, ...) fprintf(stderr,"%s:%d\t%s\n",[[[NSString stringWithUTF8String:__FILE__] lastPathComponent] UTF8String], __LINE__, [[NSString stringWithFormat:FORMAT, ##__VA_ARGS__] UTF8String]);
//#else
//#define NSLog(FORMAT, ...)
//#endif

//#if defined(DEBUG)||defined(_DEBUG)
//[[JPFPSStatus sharedInstance] open];
//#endif
//return YES;
//}

//--> 19.一些数值
#define kScreenMargin 12
#define kInsetMargin 6
#define kBottomBtnHeight 48
#define kLeftEdge UIEdgeInsetsMake(0, kScreenMargin, 0, 0)
#define kRightEdge UIEdgeInsetsMake(0, 0, 0, kScreenMargin)
#define kHuaLangBigItemW (SCREEN_WIDTH-kScreenMargin*4)/3
#define kYiShuJiaBigItemW (SCREEN_WIDTH-kScreenMargin*4)/3
#define kYiShuJiaItemW (SCREEN_WIDTH-kScreenMargin*8)/4

//--> 20.btn添加点击事件
#define kButtonTouchUpInsideClick(btn, click) [btn addTarget:self action:@selector(click) forControlEvents:UIControlEventTouchUpInside]


#endif /* AQMacro_h */
