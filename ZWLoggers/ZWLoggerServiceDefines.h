//
//  ZWLoggerServiceDefines.h
//  ZWLoggers
//
//  Created by Gavin on 17/3/2.
//  Copyright © 2017年 Gavin. All rights reserved.
//

#ifndef ZWLoggerServiceDefines_h
#define ZWLoggerServiceDefines_h

#import <Foundation/Foundation.h>
#import <CocoaLumberjack/CocoaLumberjack.h>
#import "ZWLogMacros.h"

#ifdef NS_DESIGNATED_INITIALIZER
#   define __ZW_DESIGNATED_INITIALIZER    NS_DESIGNATED_INITIALIZER
#else
#   define __ZW_DESIGNATED_INITIALIZER
#endif

#if OS_OBJECT_USE_OBJC
#define ZW_DISPATCH_QUEUE_REFERENCE_TYPE strong
#else
#define ZW_DISPATCH_QUEUE_REFERENCE_TYPE assign
#endif

#endif /* ZWLoggerServiceDefines_h */
