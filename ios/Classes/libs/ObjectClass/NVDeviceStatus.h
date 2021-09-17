//
//  NVDeviceStatus.h
//  NVSDK
//
//  Created by macrovideo on 16/5/6.
//  Copyright © 2016年 macrovideo. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NVDeviceStatus : NSObject
@property (assign) int nResult;
@property (assign) int nOnlineStatus;
@property (assign) int nAlarmStatus; //
@property(nonatomic,assign) int deviceSoftwareUpdateStatus;//设备升级状态 0 未知 1 不升级 2需要提示升级
@end
