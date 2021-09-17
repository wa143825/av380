//
//  AlarmMessage.h
//  macroSEE
//
//  Created by macrovideo on 14-9-17.
//  Copyright (c) 2014年 cctv. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface AlarmMessage : NSObject

@property (assign) int nID;
@property (assign) long long nSaveID; //update by xie yongsheng 20180920 //修改了数据类型以防止系统长时间的运行导致的数据溢出问题
@property (assign) int nDevID;
@property (assign) int nAlarmType;
@property (assign) int nAlarmLevel;
@property (assign) long long llAlarmTime;
@property (copy) NSString *strAlarmContent;
@property (copy) NSString *strAccureTime;
@property (retain) UIImage *imageData;
@property (assign) BOOL hasPosition;//add by lusongbin
@property (copy) NSString *strImageIP;

@property (assign) long oss_id;
@property (assign) int ctype;
@property (assign) long cx;
@property (assign) long cy;
@property (assign) long cr;
@property (assign) int vtype;       //录像类型(非0表示报警录像)
@property (assign) long long vid;   //录像ID
@property (assign) long long vts;   //录像时间
@end
