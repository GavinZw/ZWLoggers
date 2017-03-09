//
//  ViewController.m
//  ZWLoggerExample
//
//  Created by Gavin on 17/3/6.
//  Copyright © 2017年 Gavin. All rights reserved.
//

#import "ViewController.h"
#import <ZWLoggers/ZWLoggerService.h>

@interface ViewController (){
  NSTimer *_timer;
}

@end

static int test = 0;

@implementation ViewController

- (void)viewDidLoad {
  [super viewDidLoad];
  // Do any additional setup after loading the view, typically from a nib.
  
  self.view.backgroundColor = [UIColor redColor];

  _timer = [NSTimer scheduledTimerWithTimeInterval:1.f
                                                   repeats:YES
                                                     block:^(NSTimer * _Nonnull timer)
  {
    test++;

    dfatal(@"%d",test);
    derror(@"%d",test);
    dwarn(@"%d",test);
    dnotice(@"%d",test);
    dinfo(@"%d",test);
    ddebug(@"%d",test);
    
    if (test == 12) {
      [ZWLoggerService dd_dynamicSetLogLevel:DDLogLevelOff];
    }
  }];
}


@end
