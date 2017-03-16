//
//  NSObject+AQUnicode.m
//  iOSDeveloperTools
//
//  Created by Allen on 17/3/16.
//  Copyright © 2017年 AllenQin. All rights reserved.
//

#import "NSObject+AQUnicode.h"
#import <objc/message.h>

@implementation NSObject (AQUnicode)

+ (void)exchangeSysMethod:(SEL)sysMethod withMyMethod:(SEL)myMethod{
    method_exchangeImplementations(class_getInstanceMethod([self class], sysMethod), class_getInstanceMethod([self class], myMethod));
}

- (NSString *)stringFromUnicode:(NSString *)unicode{
    NSMutableString *convertedString = [unicode mutableCopy];
    [convertedString replaceOccurrencesOfString:@"\\U" withString:@"\\u" options:0 range:NSMakeRange(0, convertedString.length)];
    CFStringRef transform = CFSTR("Any-Hex/Java");
    CFStringTransform((__bridge CFMutableStringRef)convertedString, NULL, transform, YES);
    return convertedString;
}

//- (NSString *)myDescription{
//    return [self stringFromUnicode:[self myDescription]];
//}
//
//- (NSString *)myDescriptionWithLocale:(id)locale{
//    return [self stringFromUnicode:[self myDescriptionWithLocale:locale]];
//}
//
//- (NSString *)myDescriptionWithLocale:(id)locale indent:(NSUInteger)level{
//    return [self stringFromUnicode:[self myDescriptionWithLocale:locale indent:level]];
//}

@end
