//
//  AQFPS.h
//  iOSDeveloperTools
//
//  Created by Allen on 16/3/14.
//  Copyright © 2016年 AllenQin. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface AQFPS : NSObject
/**
 单例方法
 */
+ (instancetype)sharedInstance;

/**
 开始运行帧率检测
 */
- (void)start;

/**
 停止帧率检测
 */
- (void)stop;

@end
