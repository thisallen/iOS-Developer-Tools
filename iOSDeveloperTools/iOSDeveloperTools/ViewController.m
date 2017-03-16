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

    
    AQFPS *fps = [AQFPS sharedInstance];
    NSLog(@"%@", fps);
    [fps start];

}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
