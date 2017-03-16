//
//  AQFPS.m
//  iOSDeveloperTools
//
//  Created by Allen on 16/3/14.
//  Copyright © 2016年 AllenQin. All rights reserved.
//

#import "AQFPS.h"
#import "AQSingleton.h"
#import "AQMacro.h"

@interface AQFPS ()
@property (nonatomic, strong) UILabel *fpsLabel;
@property (nonatomic, strong) CADisplayLink *displayLink;
@end

@implementation AQFPS
{
    NSTimeInterval _lastTime;
    NSInteger _displayCount;
    BOOL _isRegistNotification;
}
#pragma mark -- 创建单例
AQSingletonM(tool);

/**
 设置默认加载
 */
- (void)setupConfig{
    if (_isRegistNotification == NO) {
        [[NSNotificationCenter defaultCenter] addObserver:self
                                                 selector:@selector(applicationDidBecomeActiveNotification)
                                                     name:UIApplicationDidBecomeActiveNotification
                                                   object:nil];
        [[NSNotificationCenter defaultCenter] addObserver:self
                                                 selector:@selector(applicationWillResignActiveNotification)
                                                     name:UIApplicationWillResignActiveNotification
                                                   object:nil];
        _isRegistNotification = YES;
    }
    [self displayLink];
    [self fpsLabel];
}

- (CADisplayLink *)displayLink{
    if (_displayLink == nil) {
        _displayLink = [CADisplayLink displayLinkWithTarget:self selector:@selector(displayLinkTick:)];
        [_displayLink setPaused:YES];
        [_displayLink addToRunLoop:[NSRunLoop currentRunLoop] forMode:NSRunLoopCommonModes];
    }
    return _displayLink;
}

- (UILabel *)fpsLabel{
    if (_fpsLabel == nil) {
        CGRect labelFrame = CGRectMake(SCREEN_WIDTH/2+25, 0, 50, 20);
        _fpsLabel = [[UILabel alloc] initWithFrame:labelFrame];
        _fpsLabel.font = SYS_FONT_Weight(12, UIFontWeightBold);
        _fpsLabel.textColor = [UIColor greenColor];
        _fpsLabel.textAlignment = NSTextAlignmentRight;
        _fpsLabel.tag = 101;
    }
    return _fpsLabel;
}

#pragma mark -- 通知方法
/**
 通知方法：程序活动时
 */
- (void)applicationDidBecomeActiveNotification{
    [_displayLink setPaused:NO];
}

/**
 通知方法：程序非活动时
 */
- (void)applicationWillResignActiveNotification{
    [_displayLink setPaused:YES];
}

/**
 频率值计算方法
->每秒该方法调用多少次，帧率就是多少
 @param link 频率定时器
 */
- (void)displayLinkTick:(CADisplayLink *)link{
    if (_lastTime == 0) {
        _lastTime = link.timestamp;
        return;
    }
    
    // 运行的次数计数，帧率默认一秒运行60次，根据CPU负载和界面情况可能在一秒内到不了60次。具体次数计算方法：由interval可以控制：每间隔一秒，计算出_displayCount值，由刷新的次数除以间隔时长得到的值就是帧数
    _displayCount++;
    NSTimeInterval interval = link.timestamp - _lastTime;
    if (interval < 1) { // 设置间隔为1秒，小于1秒的间隔return，不做计算
        return;
    }
    // 立即重置上次的时间
    _lastTime = link.timestamp;
    // 计算帧数
    float fps = _displayCount / interval;
    // 重置刷新次数
    _displayCount = 0;
    
    // 为label赋值
    NSString *test = [NSString stringWithFormat:@"%d FPS", (int)round(fps)];
    [self.fpsLabel setText:test];
}

- (void)start{
    [self setupConfig];

    NSArray *rootVCViewSubViews = [[UIApplication sharedApplication].delegate window].rootViewController.view.subviews;

    for (UIView *label in rootVCViewSubViews) {
        if ([label isKindOfClass:[UILabel class]] && label.tag == 101) {
            return;
        }
    }
    
    [_displayLink setPaused:NO];
    
    [[[UIApplication sharedApplication].delegate window].rootViewController.view addSubview:self.fpsLabel];
}

- (void)stop{
    [_displayLink setPaused:YES];
    
    NSArray *rootVCViewSubviews = [[UIApplication sharedApplication].delegate window].rootViewController.view.subviews;
    
    for (UIView *label in rootVCViewSubviews) {
        if ([label isKindOfClass:[UILabel class]] && label.tag == 101) {
            [label removeFromSuperview];
            return;
        }
    }
}

- (void)dealloc{
    [self stop];
    // invalidate即从所有运行循环移除
    [self.displayLink invalidate];
    _displayLink = nil;
    [[NSNotificationCenter defaultCenter] removeObserver:self name:UIApplicationDidBecomeActiveNotification object:nil];
    [[NSNotificationCenter defaultCenter] removeObserver:self name:UIApplicationWillResignActiveNotification object:nil];
    _isRegistNotification = NO;
}
@end
