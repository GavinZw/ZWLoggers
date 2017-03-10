//
//  ZWCatchCrash.h
//  ZWLoggers
//
//  Created by Gavin on 17/3/4.
//  Copyright © 2017年 Gavin. All rights reserved.
//

#import "ZWLoggerServiceDefines.h"
#import <CocoaLumberjack/CocoaLumberjack.h>

NS_ASSUME_NONNULL_BEGIN

/**
 抓取苹果自带的crash信息  TODO: 有问题的类
 */
@interface ZWCatchCrash : NSObject

/**
 抓取苹果自带的crash信息，程序崩溃时会执行的方法
 
 ...
 请在 didFinishLaunchingWithOptions 注册
 //注册消息处理函数的处理方法
 //如此一来，程序崩溃时会自动进入ZWCatchCrash的uncaughtExceptionHandler()方法
 NSSetUncaughtExceptionHandler(&uncaughtExceptionHandler);
 ...
 
 */
void UncaughtExceptionHandler(NSException *exception);

- (void)redirectNSLogToDocumentFolder;

@end

NS_ASSUME_NONNULL_END
