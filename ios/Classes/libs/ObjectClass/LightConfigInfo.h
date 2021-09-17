//
//  LightConfigInfo.h
//  NVSDK
//
//  Created by caffe on 2019/2/22.
//  Copyright © 2019 macrovideo. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LightConfigInfo : NSObject

@property (assign) int nResult;
@property (assign) int nSensitivity_PRI;    //PIR灵敏度
@property (assign) int nBrightness;         //白光灯亮度
@property (assign) int nLightTime;          //亮灯时长
@property (assign) int nLightControl;       //光敏触发调节
@property (assign) int nMoveSensitivity;    //移动开关灯灵敏度

@end

NS_ASSUME_NONNULL_END
