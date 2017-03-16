//
//  ViewController.m
//  iOSDeveloperTools
//
//  Created by Allen on 17/3/14.
//  Copyright © 2017年 AllenQin. All rights reserved.
//

#import "ViewController.h"
#import "AQFPS.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
#pragma mark -- 帧率显示
    AQFPS *fps = [AQFPS sharedInstance];
    [fps start];
    NSDictionary *dict = @{
                           @"key1" : @"你好",
                           @"键值2" : @"世界",
                           };
    NSLog(@"%@", dict);
    NSArray *array = [NSArray arrayWithObjects:@"你好", @"世界", nil];
    NSLog(@"%@", array);
//    
   

}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
