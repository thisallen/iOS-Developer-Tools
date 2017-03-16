//
//  UIView+FrameExtension.h
//
//  Created by 秦纪鹏 on 16/5/12.
//  Copyright © 2016年 ccys. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIView (FrameExtension)
/**
 *  frame.origin.x
 */
@property (nonatomic, assign) CGFloat x;
/**
 *  frame.origin.y
 */
@property (nonatomic, assign) CGFloat y;
/**
 *  Frame.size.width
 */
@property (nonatomic, assign) CGFloat width;
/**
 *  Frame.size.height
 */
@property (nonatomic, assign) CGFloat height;
/**
 *  Frame.size.size
 */
@property (nonatomic, assign) CGSize size;
/**
 *  Frame.size.centerX
 */
@property (nonatomic, assign) CGFloat centerX;
/**
 *  Frame.size.centerY
 */
@property (nonatomic, assign) CGFloat centerY;

@end
