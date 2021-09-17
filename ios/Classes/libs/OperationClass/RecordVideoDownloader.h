//
//  RecordVideoDownloader
//  NVSDK
//
//  Created by caffe on 2019/2/22.
//  Copyright © 2019 macrovideo. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "LoginHandle.h"
#import "RecordVideoInfo.h"


#define DOWNLOAD_PROC_DOWNLOADING 10
#define DOWNLOAD_PROC_FINISH 11
#define DOWNLOAD_PROC_CONNECTING 12
#define DOWNLOAD_PROC_CLOSE -10
#define DOWNLOAD_PROC_NET_ERR -11
#define DOWNLOAD_PROC_BREAK 1

NS_ASSUME_NONNULL_BEGIN

@protocol RecordVideoDownloadDelegate <NSObject>
//-(void)onProcessChange:(int)nTotalCount size:(int)nRecv result:(int) nResult;//搜索录像文件接收函数
-(void)onDownloadProcess:(id)downloader flag:(int)nFlag process:(int) nProcess;//
@end

@interface RecordVideoDownloader : NSObject
@property (assign) int nTag;
@property (weak) id<RecordVideoDownloadDelegate> downloadDelegate;

- (BOOL)startDownloadRecordVideo:(NSString *)strSavePath handle:(LoginHandle *)deviceParam rec:(RecordVideoInfo *)recFile;


//云存储下载  add by yangchenghong 20170618
-(BOOL)startDownloadCloudVideo:(NSString *)strSavePath handle:(LoginHandle *)deviceParam rec:(RecordVideoInfo *)recFile accessToken:(NSString*)accessToken ecsIP:(NSString*)ecsIP ecsPort:(NSString*)escPort nDevID:(int)ndevID nAccountID:(int)nAccountID;

-(BOOL)stopDownLoadVideo;
-(void)deleteTempVideoInSandBox;
@end

NS_ASSUME_NONNULL_END
