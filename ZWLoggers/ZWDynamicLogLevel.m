//
//  ZWDynamicLogLevel.m
//  ZWLoggers
//
//  Created by Gavin on 17/3/3.
//  Copyright © 2017年 Gavin. All rights reserved.
//

#import "ZWDynamicLogLevel.h"

#ifdef DEBUG
static DDLogLevel z_ddLogLevel = DDLogLevelAll;
#else
static DDLogLevel z_ddLogLevel = LOG_LEVEL_ERROR;
#endif

@implementation ZWDynamicLogLevel

+ (DDLogLevel)ddLogLevel {
   return z_ddLogLevel;
}

+ (void)ddSetLogLevel:(DDLogLevel)level{
  z_ddLogLevel = level;
}

@end

