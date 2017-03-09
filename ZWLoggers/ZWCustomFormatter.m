//
//  ZWCustomFormatter.m
//  ZWLoggers
//
//  Created by Gavin on 17/3/7.
//  Copyright © 2017年 Gavin. All rights reserved.
//
#import <libkern/OSAtomic.h>
#import "ZWCustomFormatter.h"

@implementation ZWCustomFormatter

#pragma makr -
#pragma makr - DDLogFormatter

- (NSString *)stringFromDate:(NSDate *)date {
  int32_t loggerCount = OSAtomicAdd32(0, &atomicLoggerCount);
  
  if (loggerCount <= 1) {
    // Single-threaded mode.
    
    if (threadUnsafeDateFormatter == nil) {
      threadUnsafeDateFormatter = [[NSDateFormatter alloc] init];
      [threadUnsafeDateFormatter setDateFormat:@"yyyy-MM-dd HH:mm:ss:SSS"];
    }
    
    return [threadUnsafeDateFormatter stringFromDate:date];
  } else {
    // Multi-threaded mode.
    // NSDateFormatter is NOT thread-safe.    
    NSString *key = @"ZWCustomFormatter_NSDateFormatter";
    NSMutableDictionary *threadDictionary = [[NSThread currentThread] threadDictionary];
    NSDateFormatter *dateFormatter = [threadDictionary objectForKey:key];
    
    if (dateFormatter == nil) {
      dateFormatter = [[NSDateFormatter alloc] init];
      [dateFormatter setDateFormat:@"yyyy-MM-dd HH:mm:ss:SSS"];
      
      [threadDictionary setObject:dateFormatter forKey:key];
    }
    
    return [dateFormatter stringFromDate:date];
  }
}

- (NSString *)formatLogMessage:(DDLogMessage *)logMessage{
  NSString *dateAndTime = [self stringFromDate:(logMessage.timestamp)];
  return [NSString stringWithFormat:@"[%@]%@[line %ld]%@",
          dateAndTime,
          logMessage.function,
          logMessage.line,
          logMessage.message];
}

- (void)didAddToLogger:(id <DDLogger>)logger {
  OSAtomicIncrement32(&atomicLoggerCount);
}

- (void)willRemoveFromLogger:(id <DDLogger>)logger {
   OSAtomicDecrement32(&atomicLoggerCount);
}


@end
