//
//  NSArray+AQUnicode.m
//  iOSDeveloperTools
//
//  Created by Allen on 17/3/16.
//  Copyright © 2017年 AllenQin. All rights reserved.
//

#import "NSArray+AQUnicode.h"
#import "NSString+AQUnicode.h"
#import <objc/message.h>

@implementation NSArray (AQUnicode)

#if DEBUG

+ (void)load{
    method_exchangeImplementations(class_getInstanceMethod([self class], @selector(description)), class_getInstanceMethod([self class], @selector(myDescription)));
    method_exchangeImplementations(class_getInstanceMethod([self class], @selector(descriptionWithLocale:)), class_getInstanceMethod([self class], @selector(myDescriptionWithLocale:)));
    method_exchangeImplementations(class_getInstanceMethod([self class], @selector(descriptionWithLocale:indent:)), class_getInstanceMethod([self class], @selector(myDescriptionWithLocale:indent:)));
}

- (NSString *)myDescription{
    return [self myDescription].unicodeString;
}

- (NSString *)myDescriptionWithLocale:(id)locale{
    return [self myDescriptionWithLocale:locale].unicodeString;
}

- (NSString *)myDescriptionWithLocale:(id)locale indent:(NSUInteger)level{
    return [self myDescriptionWithLocale:locale indent:level].unicodeString;
}
#endif
@end
