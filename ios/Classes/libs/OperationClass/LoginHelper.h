//
//  LoginHelper.h
//  iCamSee
//
//  Created by macrovideo on 15/10/14.
//  Copyright © 2015年 macrovideo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LoginHandle.h"
#import "NVDeviceStatus.h"
#import "SearchDeviceResult.h"

@class NVDevice;
@class LoginParam;

@interface LoginHelper : NSObject

+(void)loginDevice:(LoginParam *)loginParam;
+ (NVDeviceStatus *)getDeviceStatus:(NVDevice *)device;
+(SearchDeviceResult*)searchDeviceFromServer:(NVDevice *)device;

@end
