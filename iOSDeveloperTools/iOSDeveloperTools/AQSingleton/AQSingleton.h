//
//  AQSingleton.h
//  iOSDeveloperTools
//
//  Created by Allen on 17/3/15.
//  Copyright © 2017年 AllenQin. All rights reserved.
//

#ifndef AQSingleton_h
#define AQSingleton_h

#define AQSingletonM(name) \
static id _instance; \
\
+ (instancetype)allocWithZone:(struct _NSZone *)zone \
{ \
static dispatch_once_t onceToken; \
dispatch_once(&onceToken, ^{ \
_instance = [super allocWithZone:zone]; \
}); \
return _instance; \
} \
\
+ (instancetype)sharedInstance \
{ \
static dispatch_once_t onceToken; \
dispatch_once(&onceToken, ^{ \
_instance = [[self alloc] init]; \
}); \
return _instance; \
} \
\
- (id)copyWithZone:(NSZone *)zone \
{ \
return _instance; \
} \
- (id)mutableCopyWithZone:(NSZone *)zone{ \
    return _instance; \
} \
\


#endif /* AQSingleton_h */
