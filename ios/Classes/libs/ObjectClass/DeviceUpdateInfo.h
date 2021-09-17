//
//  DeviceUpdateInfo.h
//  NVSDK
//
//  Created by caffe on 2019/2/22.
//  Copyright © 2019 macrovideo. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DeviceUpdateInfo : NSObject
@property (assign) int nResult;
@property (assign) int nServerID;
@property (assign) int nResultType; //add by xie yongsheng 20181206

@property (assign) int nCurrentVersion;
@property (copy) NSString *strCurrentVersionName;
@property (copy) NSString *strCurrentVersionDate;

@property (assign) int nNewVersion;
@property (copy) NSString *strNewVersionName;
@property (copy) NSString *strNewVersionDate;
@end

NS_ASSUME_NONNULL_END
