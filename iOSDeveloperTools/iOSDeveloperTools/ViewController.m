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
    
    AQFPS *fps0 = [[AQFPS alloc] init];
    NSLog(@"%@", fps0);
    
    
    AQFPS *fps = [AQFPS shareInstance];
    NSLog(@"%@", fps);
    
    
    AQFPS *fps1 = [AQFPS shareInstance];
    NSLog(@"%@", fps1);

//    
//    AQFPS *fps2 = [AQFPS shareInstance];
//    NSLog(@"%@", fps2);
//    
//    
//    AQFPS *fps3 = [AQFPS shareInstance];
//    NSLog(@"%@", fps3);
    
    AQFPS *fps4 = [[AQFPS alloc] init];
    NSLog(@"%@", fps4);
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
