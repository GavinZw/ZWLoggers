//
//  ZWDynamicLogLevel.h
//  ZWLoggers
//
//  Created by Gavin on 17/3/3.
//  Copyright © 2017年 Gavin. All rights reserved.
//

#import "ZWLoggerServiceDefines.h"

NS_ASSUME_NONNULL_BEGIN

/**
 Dynamically changing log levels during run-time
 */
@interface ZWDynamicLogLevel : NSObject <
 DDRegisteredDynamicLogging
>

@end

NS_ASSUME_NONNULL_END
