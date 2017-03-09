//
//  ZWLoggerService.h
//  ZWLoggers
//
//  Created by Gavin on 17/3/2.
//  Copyright © 2017年 Gavin. All rights reserved.
//

#import "ZWLoggerServiceDefines.h"

//! Project version number for ZWLoggers.
FOUNDATION_EXPORT double ZWLoggersVersionNumber;

//! Project version string for ZWLoggers.
FOUNDATION_EXPORT const unsigned char ZWLoggersVersionString[];

#ifndef ZW_LOG_MODULE_NAME
#define ZW_LOG_MODULE_NAME ddLogModuleName
#endif

/**
 选择下面的方式进行输出
 */
#define dfatal(frmt, ...)   DDLogFatal(@"[Fatal]: " frmt, ##__VA_ARGS__)     // Fatal logs only
#define derror(frmt, ...)   DDLogError(@"[Error]: " frmt, ##__VA_ARGS__)     // Fatal and error logs
#define dwarn(frmt, ...)    DDLogWarn(@"[Warn]: " frmt, ##__VA_ARGS__)       // Fatal, error and warn logs
#define dnotice(frmt, ...)  DDLogNotice(@"[Notice]: " frmt, ##__VA_ARGS__)   // Fatal, error, warn and notice logs
#define dinfo(frmt, ...)    DDLogInfo(@"[Info]: " frmt, ##__VA_ARGS__)       // Fatal, error, warn, notice and info logs
#define ddebug(frmt, ...)   DDLogDebug(@"[Debug]: " frmt, ##__VA_ARGS__)     // Fatal, error, warn, notice, info and debug logs

#define dfatal_dlog(ddlog, frmt, ...)   DDLogFatalToDDLog(ddlog, @"[Fatal]: " frmt, ##__VA_ARGS__)     // Fatal logs only
#define derror_dlog(ddlog, frmt, ...)   DDLogErrorToDDLog(ddlog, @"[Error]: " frmt, ##__VA_ARGS__)     // Fatal and error logs
#define dwarn_dlog(ddlog, frmt, ...)    DDLogWarnToDDLog(ddlog, @"[Warn]: " frmt, ##__VA_ARGS__)       // Fatal, error and warn logs
#define dnotice_dlog(ddlog, frmt, ...)  DDLogNoticeToDDLog(ddlog, @"[Notice]: " frmt, ##__VA_ARGS__)   // Fatal, error, warn and notice logs
#define dinfo_dlog(ddlog, frmt, ...)    DDLogInfoToDDLog(ddlog, @"[Info]: " frmt, ##__VA_ARGS__)       // Fatal, error, warn, notice and info logs
#define ddebug_dlog(ddlog, frmt, ...)   DDLogDebugToDDLog(ddlog, @"[Debug]: " frmt, ##__VA_ARGS__)     // Fatal, error, warn, notice, info and debug logs

NS_ASSUME_NONNULL_BEGIN

/**
 * 基于CocoaLumberjack日志服务组件
 * 直接使用 dfatal, derror,dwarn... 不需要额外注册
 */
@interface ZWLoggerService : NSObject

/**
 *  Returns the singleton `ZWLoggerService`.
 *  The instance is used by `ZWLoggerService` class methods.
 */
@property (class, nonatomic, strong, readonly) ZWLoggerService *sharedInstance;

/**
 *  Returns the singleton `DDLog`.
 *  The instance is used by `DDLog` class methods.
 *
 *  @return The singleton `DDLog`.
 */
@property (class, nonatomic, strong, readonly) DDLog *dlogSharedInstance;

/**
 * 动态配置 DDLogLevel 级别
 * 默认: DEBUG模式:   DDLogLevelAll
        RELEASE模式: LOG_LEVEL_ERROR (Fatal and error logs)

 @param level 可以使用 DDLogLevel 枚举
              或者自定义的 日志级别宏,例如LOG_LEVEL_ERROR,LOG_FLAG_NOTICE...
 *            更多请参参考ZWLogMacros.h 自定义过滤级别.
 */
+ (void)dd_dynamicSetLogLevel:(DDLogLevel)level;


/**
 * Returns  DDFileLogger. the logs directory (path)
 *
 * fileLogger.logFileManager.logsDirectory
 * 可以配合 ZipArchive, 把日志发送到服务器
 */
+ (DDFileLogger *)currentFileLogger;

@end

NS_ASSUME_NONNULL_END
