//
//  RecordVideoInfo.h
//  NVSDK
//
//  Created by caffe on 2019/2/22.
//  Copyright © 2019 macrovideo. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface RecordVideoInfo : NSObject
@property (assign) int nFileID;
@property (assign) int nFileSize;
@property (copy) NSString *strFileName;
@property (assign) int nStartHour;
@property (assign) int nStartMin;
@property (assign) int nStartSec;
@property (assign) int nFileTimeLen;

@property (assign) int nDownloadStatus;
@property (assign) float nDownloadProcess;

@property (assign) int nfileType;
@property (assign) int nStartTime;
@property (assign) int nEndTime;
@property (assign) int nCurrentTime;//增属性，支持新协议 by weibin 20190225
@end

NS_ASSUME_NONNULL_END
