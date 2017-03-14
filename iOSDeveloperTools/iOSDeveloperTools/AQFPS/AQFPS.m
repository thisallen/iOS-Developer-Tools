//
//  AQFPS.m
//  iOSDeveloperTools
//
//  Created by Allen on 16/3/14.
//  Copyright © 2016年 AllenQin. All rights reserved.
//

#import "AQFPS.h"

@implementation AQFPS

#pragma mark -- 创建单例
static AQFPS *_shareInstance;


+ (instancetype)shareInstance{
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        _shareInstance = [[super allocWithZone:NULL] init];
    });
    return _shareInstance;
}

+ (instancetype)allocWithZone:(struct _NSZone *)zone{
    return [AQFPS shareInstance];
}

- (id)copyWithZone:(NSZone *)zone{
    return [AQFPS shareInstance];
}

- (id)mutableCopyWithZone:(NSZone *)zone{
    return [AQFPS shareInstance];
}

#pragma mark -- INIT
- (instancetype)init{
    self = [super init];
    if (self) {
        
    }
    return self;
}
@end
