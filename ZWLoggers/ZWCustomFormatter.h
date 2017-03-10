//
//  ZWCustomFormatter.h
//  ZWLoggers
//
//  Created by Gavin on 17/3/7.
//  Copyright © 2017年 Gavin. All rights reserved.
//

#import "ZWLoggerServiceDefines.h">
#import <CocoaLumberjack/CocoaLumberjack.h>

NS_ASSUME_NONNULL_BEGIN

/**
 配置日志的输出格式
 */
@interface ZWCustomFormatter : NSObject <DDLogFormatter > {
  int atomicLoggerCount;
  NSDateFormatter *threadUnsafeDateFormatter;
}

@end

NS_ASSUME_NONNULL_END
