//
//  ZWLoggerService.m
//  ZWLoggers
//
//  Created by Gavin on 17/3/2.
//  Copyright © 2017年 Gavin. All rights reserved.
//

#import "ZWLoggerService.h"
#import "ZWDynamicLogLevel.h"
#import "ZWCustomFormatter.h"

#define kModuleInfoNameKey  @"moduleClass"

@interface ZWLoggerService ()

@property(nonatomic, strong)  NSMutableDictionary      *loggerModuleNames;
@property (ZW_DISPATCH_QUEUE_REFERENCE_TYPE, nonatomic) dispatch_queue_t moduleNameQueue;

@end

@implementation ZWLoggerService

+ (void)load {
  static dispatch_once_t onceToken;
  dispatch_once(&onceToken, ^{
    @autoreleasepool {
      [self.sharedInstance registeredLoggerService];
    }
  });
}

/**
 *  Returns the singleton `DDLog`.
 *  The instance is used by `DDLog` class methods.
 *
 *  @return The singleton `DDLog`.
 */
+ (instancetype)sharedInstance {
  static id sharedInstance = nil;
  
  static dispatch_once_t onceToken;
  dispatch_once(&onceToken, ^{
    sharedInstance = [[self alloc] init];
  });
  
  return sharedInstance;
}

- (instancetype)init
{
  self = [super init];
  if (self) {
    _loggerModuleNames = [NSMutableDictionary new];
    _moduleNameQueue = dispatch_queue_create("com.gavin.ZWLoggerModuleNameQueue", DISPATCH_QUEUE_CONCURRENT);
  }
  return self;
}

/**
 *  Returns the singleton `DDLog`.
 *  The instance is used by `DDLog` class methods.
 *
 *  @return The singleton `DDLog`.
 */
+ (instancetype)dlogSharedInstance {
  return [DDLog sharedInstance];
}

- (void)registeredLoggerService{
  static dispatch_once_t registeredOnce;
  dispatch_once(&registeredOnce, ^{
    // ASL = Apple System Logs
#ifdef RELEASE
    [self ConfigureDDASLLogger:[DDASLLogger sharedInstance]];
#endif
    
    [self ConfigureDDTTYLogger:[DDTTYLogger sharedInstance]];
    [self ConfigureDDFileLogger:[DDFileLogger new]];
  });
}

- (void)ConfigureDDASLLogger:(id <DDLogger>)logger{
  [DDLog addLogger:logger];
}

- (void)ConfigureDDTTYLogger:(DDTTYLogger <DDLogger>*)logger{
  // Open use XcodeColors
  setenv("XcodeColors", "YES", 0);
  
  // Check whether to open
  char *xcode_colors = getenv("XcodeColors");
  if (xcode_colors && (strcmp(xcode_colors, "YES") == 0)) {
    // XcodeColors is installed and enabled!
#ifdef DEBUG  
     NSLog(@"XcodeColors is installed and enabled ");
#endif
  }
  
  // Open DDLog color
  [logger setColorsEnabled:YES];
  [logger setForegroundColor:[UIColor redColor] backgroundColor:nil forFlag:DDLogFlagError];
  [logger setForegroundColor:[UIColor orangeColor] backgroundColor:nil forFlag:DDLogFlagWarning];
  [logger setForegroundColor:[UIColor blueColor] backgroundColor:nil forFlag:DDLogFlagInfo];
  [logger setForegroundColor:[UIColor purpleColor] backgroundColor:nil forFlag:DDLogFlagDebug];
  [logger setForegroundColor:[UIColor grayColor] backgroundColor:nil forFlag:DDLogFlagVerbose];
  
  // formatter
  [logger setLogFormatter:[ZWCustomFormatter new]];
  
  [DDLog addLogger:logger];
}

- (void)ConfigureDDFileLogger:(id <DDLogger>)fileLogger{
  // File Logger
  DDFileLogger *file = fileLogger;
  file.rollingFrequency = 60 * 60 * 24; // 24 hour rolling
  file.logFileManager.maximumNumberOfLogFiles = 7;
  [DDLog addLogger:file];
}

#pragma makr -
#pragma makr -

+ (void)dd_dynamicSetLogLevel:(DDLogLevel)level{
  [ZWDynamicLogLevel ddSetLogLevel:level];
}

#pragma makr -
#pragma makr -

+ (DDFileLogger *)currentLogPath{
  NSArray* loggers = [DDLog allLoggers];
  
  for(id fileLogger in loggers)
  {
    if([fileLogger isKindOfClass:[DDFileLogger class]])
    {
      return fileLogger;
    }
  }
  
  return nil;
}

#pragma mark -
#pragma mark - private

- (void)_registerDynamicModule:(NSString *)moduleName
{
  [self addModuleFromObject:moduleName];
}

- (void)addModuleFromObject:(NSString *)moduleName{
  if (moduleName.length == 0 || moduleName == nil) return;
  
  dispatch_barrier_sync(self.moduleNameQueue, ^{ @autoreleasepool {
      self.loggerModuleNames[moduleName] = moduleName;
    }
  });
}

#pragma mark -
#pragma mark - property setter or getter


@end
