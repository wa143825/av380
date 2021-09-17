//
//  LoginInfo.h
//  IMobilePlayer
//
//  Created by luo king on 11-12-17.
//  Copyright 2011 cctv. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#define ADD_TYPE_HANDMAKE 10
#define ADD_TYPE_SEARCH_FROM_LAN 11
#define ADD_TYPE_SYNC_FROM_NET 12
#define ADD_TYPE_DEMO 13
#define ADD_TYPE_SHARE 14  //add by yang 20180315

#define EDIT_TPYE_ADD 100
#define EDIT_TPYE_MODIFY 101

#define ONLINE_STAT_READY 0
#define ONLINE_STAT_ON 100
#define ONLINE_STAT_OFF 101
#define ONLINE_STAT_ON_LAN 102
#define ONLINE_STAT_ON_WAN 103
#define ONLINE_STAT_PWD_ERR 104
#define ONLINE_STAT_UNKNOW 110

#define ONLINE_TIME_DURATION 60000
#define ALARM_EXPIRT_TIME 259200000




@interface NVDevice : NSObject<NSCoding>
@property(nonatomic,assign) int deviceSoftwareUpdateStatus;//设备升级状态 0 未知 1 不升级 2需要提示升级


@property (assign) int nOnlineStatus;//
@property (assign) long long llOnlineTime;//
@property (assign) int isAlarmOn;//
@property (assign) BOOL isRecvAlarmMsg;

//add by luo20141103
@property (copy) NSString *strMRServer;
@property (assign) int nMRPort;
//end add by luo20141103

@property (assign) int nAlarmMsgCount;
@property (assign) long long lLastFreshTime;
@property (assign) long long lLastGetTime;
@property (assign) BOOL isSelect;
@property (assign) BOOL isInList;
@property (nonatomic,copy) NSString *strMacAddress;
@property (assign) int nID;
//@property (assign) int nDevID;
@property (assign) int nConfigID;//add by luo 20150409

@property (assign) int nAddType;
@property (nonatomic,copy) NSString *strName;
@property (nonatomic,copy) NSString *strServer;
@property (assign) int nPort;
@property (nonatomic,copy) NSString *strUsername;
@property (nonatomic,copy) NSString *strPassword;
@property (assign) BOOL isMRMode;
@property (nonatomic, copy) NSString *strDomain;
@property (nonatomic, retain) UIImage *imageFace;
@property (assign) int serverStatus;
@property(assign) int nDeviceType;

//add by xie yongsheng 20181023
@property (assign) int temporaryAlarmFlag;               //临时报警开关
@property (assign) NSTimeInterval temporaryAlarmTimestamp;        //临时报警开关的时间戳
@property (assign) int temporaryServiceID;               //临时云存储状态
@property (assign) NSTimeInterval temporaryServiceIDTimestamp;    //临时云存储状态的时间戳
//add end by xie yongsheng 20181023

@property (nonatomic,strong)NSNumber *tempServiceID;

-(void)setDevID:(int)nDeviceID;
-(int)NDevID;
-(BOOL)isMatch:(NVDevice *)info;
-(BOOL)isMatch:(int )devID username:(NSString *)username password:(NSString *)password;
-(void)copyDeviceInfo:(NVDevice *)info;
@end
