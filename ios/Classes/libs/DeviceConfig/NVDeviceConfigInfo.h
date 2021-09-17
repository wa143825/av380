//
//  NVDeviceConfigInfo.h
//  NVSDK
//
//  Created by caffe on 2019/2/21.
//  Copyright © 2019 macrovideo. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "NVDevice.h"
#import "LoginHandle.h"
//#import "AllDeviceConfigInfo.h"
#import "NetworkConfigInfo.h"
#import "RecordConfigInfo.h"
#import "AlarmConfigInfo.h"
#import "TimeConfigInfo.h"
#import "VersionInfo.h"
#import "IPConfigInfo.h"
#import "LightConfigInfo.h"


typedef enum{
    INFO_NETWORK=1,
    INFO_RECORD=2,
    INFO_ALARM=3,
    INFO_VERSION=4,
    INFO_IP=5,
    INFO_DATETIME=6,
    INFO_SETTING =7
}INFO_TYPE;

NS_ASSUME_NONNULL_BEGIN

@interface NVDeviceConfigInfo : NSObject
@property (assign) int nResult;

@property(nonatomic,strong)NetworkConfigInfo *networkconfig;
@property(nonatomic,strong) RecordConfigInfo *recordConfig;
@property(nonatomic,strong)AlarmConfigInfo *alarmConfig;
@property(nonatomic,strong)TimeConfigInfo *timeConfig;
@property(nonatomic,strong)VersionInfo *versionInfo;
@property(nonatomic,strong)IPConfigInfo *iPConfig;
@property(nonatomic,strong)LightConfigInfo *lightConfig;

-(BOOL)getDeviceConfigInfo:(NVDevice *)device handle:(LoginHandle *)lHandle;
@end

NS_ASSUME_NONNULL_END
