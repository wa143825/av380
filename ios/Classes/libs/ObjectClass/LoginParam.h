//
//  LoginParam.h
//  NVSDK
//
//  Created by caffe on 2019/2/20.
//  Copyright © 2019 macrovideo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NVDevice.h"

typedef void(^completionHandler)(LoginHandle *loginResult);
@interface LoginParam : NSObject
@property (nonatomic, strong) NVDevice* device;
@property (nonatomic, assign) int connectionType;
@property (nonatomic, copy) completionHandler handler;//登录完成时block回调
@end
