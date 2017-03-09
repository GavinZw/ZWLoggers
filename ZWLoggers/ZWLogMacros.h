//
//  ZWLogMacros.h
//  ZWLoggers
//
//  Created by Gavin on 17/3/8.
//  Copyright © 2017年 Gavin. All rights reserved.
//
#import "ZWLoggerServiceDefines.h"
#import "ZWDynamicLogLevel.h"

/**
 * The constant/variable/method responsible for controlling the current log level.
 **/
#ifndef ZW_LOG_LEVEL_DEF
#define ZW_LOG_LEVEL_DEF [ZWDynamicLogLevel ddLogLevel]
#endif


// We want to use the following log levels:
//
// Fatal
// Error
// Warn
// Notice
// Info
// Debug
//
// All we have to do is undefine the default values,
// and then simply define our own however we want.

// First undefine the default stuff we don't want to use.

#undef DDLogError
#undef DDLogWarn
#undef DDLogInfo
#undef DDLogDebug
#undef DDLogVerbose

#undef DDLogErrorToDDLog
#undef DDLogWarnToDDLog
#undef DDLogInfoToDDLog
#undef DDLogDebugToDDLog
#undef DDLogVerboseToDDLog


// Now define everything how we want it

#define LOG_FLAG_FATAL   (1 << 0)  // 0...000001
#define LOG_FLAG_ERROR   (1 << 1)  // 0...000010
#define LOG_FLAG_WARN    (1 << 2)  // 0...000100
#define LOG_FLAG_NOTICE  (1 << 3)  // 0...001000
#define LOG_FLAG_INFO    (1 << 4)  // 0...010000
#define LOG_FLAG_DEBUG   (1 << 5)  // 0...100000


/**
 Log levels are used to filter out logs. Used together with flags.
 */
#define LOG_LEVEL_FATAL   (LOG_FLAG_FATAL)                     // 0...000001
#define LOG_LEVEL_ERROR   (LOG_FLAG_ERROR  | LOG_LEVEL_FATAL ) // 0...000011
#define LOG_LEVEL_WARN    (LOG_FLAG_WARN   | LOG_LEVEL_ERROR ) // 0...000111
#define LOG_LEVEL_NOTICE  (LOG_FLAG_NOTICE | LOG_LEVEL_WARN  ) // 0...001111
#define LOG_LEVEL_INFO    (LOG_FLAG_INFO   | LOG_LEVEL_NOTICE) // 0...011111
#define LOG_LEVEL_DEBUG   (LOG_FLAG_DEBUG  | LOG_LEVEL_INFO  ) // 0...111111

#define DDLogFatal(frmt, ...)   LOG_MAYBE(NO,                ZW_LOG_LEVEL_DEF, LOG_FLAG_FATAL,  0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define DDLogError(frmt, ...)   LOG_MAYBE(LOG_ASYNC_ENABLED, ZW_LOG_LEVEL_DEF, LOG_FLAG_ERROR,  0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define DDLogWarn(frmt, ...)    LOG_MAYBE(LOG_ASYNC_ENABLED, ZW_LOG_LEVEL_DEF, LOG_FLAG_WARN,   0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define DDLogNotice(frmt, ...)  LOG_MAYBE(LOG_ASYNC_ENABLED, ZW_LOG_LEVEL_DEF, LOG_FLAG_NOTICE, 0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define DDLogInfo(frmt, ...)    LOG_MAYBE(LOG_ASYNC_ENABLED, ZW_LOG_LEVEL_DEF, LOG_FLAG_INFO,   0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define DDLogDebug(frmt, ...)   LOG_MAYBE(LOG_ASYNC_ENABLED, ZW_LOG_LEVEL_DEF, LOG_FLAG_DEBUG,  0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)


#define DDLogFatalToDDLog(ddlog, frmt, ...)   LOG_MAYBE_TO_DDLOG(ddlog, NO,                ZW_LOG_LEVEL_DEF, LOG_FLAG_FATAL,   0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define DDLogErrorToDDLog(ddlog, frmt, ...)   LOG_MAYBE_TO_DDLOG(ddlog, NO,                ZW_LOG_LEVEL_DEF, LOG_FLAG_ERROR,   0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define DDLogWarnToDDLog(ddlog, frmt, ...)    LOG_MAYBE_TO_DDLOG(ddlog, LOG_ASYNC_ENABLED, ZW_LOG_LEVEL_DEF, LOG_FLAG_WARN,    0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define DDLogNoticeToDDLog(ddlog, frmt, ...)  LOG_MAYBE_TO_DDLOG(ddlog, LOG_ASYNC_ENABLED, ZW_LOG_LEVEL_DEF, LOG_FLAG_NOTICE,  0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define DDLogInfoToDDLog(ddlog, frmt, ...)    LOG_MAYBE_TO_DDLOG(ddlog, LOG_ASYNC_ENABLED, ZW_LOG_LEVEL_DEF, LOG_FLAG_INFO,    0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define DDLogDebugToDDLog(ddlog, frmt, ...)   LOG_MAYBE_TO_DDLOG(ddlog, LOG_ASYNC_ENABLED, ZW_LOG_LEVEL_DEF, LOG_FLAG_DEBUG,   0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)


