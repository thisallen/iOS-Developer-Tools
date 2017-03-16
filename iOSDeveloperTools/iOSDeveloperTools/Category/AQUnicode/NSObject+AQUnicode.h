//
//  NSObject+AQUnicode.h
//  iOSDeveloperTools
//
//  Created by Allen on 17/3/16.
//  Copyright © 2017年 AllenQin. All rights reserved.
//

#import <Foundation/Foundation.h>

#define ExchangMethod \
+ (void)load{ \
    [[self class] exchangeSysMethod:@selector(description) withMyMethod:@selector(myDescription)]; \
    [[self class] exchangeSysMethod:@selector(descriptionWithLocale:) withMyMethod:@selector(myDescriptionWithLocale:)]; \
    [[self class] exchangeSysMethod:@selector(descriptionWithLocale:indent:) withMyMethod:@selector(myDescriptionWithLocale:indent:)]; \
} \
\
\
- (NSString *)myDescription{ \
    return [self stringFromUnicode:[self myDescription]]; \
} \
\
- (NSString *)myDescriptionWithLocale:(id)locale{ \
    return [self stringFromUnicode:[self myDescriptionWithLocale:locale]]; \
} \
\
- (NSString *)myDescriptionWithLocale:(id)locale indent:(NSUInteger)level{ \
    return [self stringFromUnicode:[self myDescriptionWithLocale:locale indent:level]]; \
} \


@interface NSObject (AQUnicode)
/**
 方法交换
 
 */
+ (void)exchangeSysMethod:(SEL)sysMethod withMyMethod:(SEL)myMethod;

/**
 Unicode转中文
 */
- (NSString *)stringFromUnicode:(NSString *)unicode;

// 这几个对象方法要单独写在分类里，要不然会报错
//- (NSString *)myDescription;
//- (NSString *)myDescriptionWithLocale:(id)locale;
//- (NSString *)myDescriptionWithLocale:(id)locale indent:(NSUInteger)level;
@end
