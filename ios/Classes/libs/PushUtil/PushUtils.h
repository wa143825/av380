//
//  PushUtils.h
//  NVSDK
//
//  Created by MacroVideo on 2017/9/18.
//  Copyright © 2017年 macrovideo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AlarmMessage.h"

typedef void(^PushUtilsResultBlock)(BOOL Success);

@interface PushUtils : NSObject

//@property(nonatomic,copy) Myblock Success;


/*  注册信鸽（阿里云）推送---注册设备到服务器---上传设备列表到服务器---收到推送通知---userInfo解析成AlarmMessage模型
 （收到阿里云消息后--body解析成AlarmMessage模型）
 */
/*
 ┏               ┓
 **信鸽推送**
 ┗               ┛
 
 --------------------------
 |        注册设备          |
 --------------------------
 
 @param:{
 "sys_lan":          系统语言 中文:cn 英文:en 俄罗斯:ru....,
 "client_id":        客户端id号（devicetoken） 字符串,
 "phone_type":       手机类型(ios:1001) 整数,
 "phone_num":        手机号码(如果没有传"unknow") 字符串,
 "apikey":           信鸽ACCESS KEY  长整数,
 "secretkey":        信鸽SECRET KEY 字符串,
 "channel_id"        信鸽ACCESS ID 字符串
 "user_id"           信鸽ACCESS KEY 字符串
 "recv_msg_pri":     是否接收推送(开启：1 关闭：0) 整数,
 "vibrate":          是否开启震动提示(开启：1 关闭：0) 整数,
 "sound":            声音是否开启(开启：1 关闭：0) 整数,
 "sound_file":       声音文件 字符串,
 "env":              env: 0表示发布版，1 表示开发版
 }
 Success:              注册成功回调
 */
+(void)registDeviceToServer:(NSDictionary*)param Success:(PushUtilsResultBlock)Success;

/*
 --------------------------
 |       注册设备列表         |
 --------------------------
 clientID:    设备devicetoken
 serverList:  设备列表数组
 Success:      上传成功回调
 */
+(void)setClientWithDeviceParam:(NSString*)clientID addDeviceArr:(NSArray*)serverList Success:(PushUtilsResultBlock)Success;

/*
 -------------------------------------------
 |       前台收到通知后将推送内容解析成模型       |
 -------------------------------------------
 
 ╱                           ╲
 不管是信鸽还是阿里云都会调用此方法
 ╲                           ╱
 
 userInfo:前台接收远程消息推送的内容
 return:AlarmMessage报警图片模型
 */
+(AlarmMessage*)recNotificationWithUserInfo:(NSDictionary*)userInfo;

/*
 ┏               ┓
    **阿里云推送**
 ┗               ┛
 
 --------------------------
 |        注册设备          |
 --------------------------
 param:{
 "app_id":      app id 整数,
 "phone_type":  手机类型 整数,
 "phone_num":   手机号码 字符串,
 "appkey":      阿里云appkey 长整数,
 "appsecret":   阿里云secret 字符串,
 "clientid":    客户端id号 字符串,
 "enable":      是否接收推送 整数,
 "vibrate":     是否开启震动提示 整数,
 "sound":       声音是否开启 整数,
 "sound_file":  声音文件 字符串,
 "sys_lan":     手机系统类型 字符串
 "sys_num":     系统版本 整数
 "env":         env: 0表示发布版，1 表示开发版
 "login":       login:   1：登录 0：未登录
 }
 Success:               注册成功回调
 */
+ (void)registDeviceToServerForALiPush:(NSDictionary*)param Success:(PushUtilsResultBlock)Success;

/*
 --------------------------
 |       注册设备列表        |
 --------------------------
 deviceID:    获取本机的deviceId,[CloudPushSDK getDeviceId],若为空传"unknow";
 serverList:  设备列表数组
 Success:     上传成功回调
 */
+ (void)setClientWithDeviceParamForALiPush:(NSString*)deviceID addDeviceArr:(NSArray*)serverList Success:(PushUtilsResultBlock)Success;

/*
 ------------------------------
 |       处理到来推送消息         |
 ------------------------------
 注册推送消息到来监听：CCPDidReceiveMessageNotification
 处理到来推送消息:boby
 return:AlarmMessage模型
 */
+ (AlarmMessage*)onMessageReceivedByALi:(NSString *)body;



/*
 ┏               ┓
    **极光推送**
 ┗               ┛
 
 --------------------------
 |        注册设备          |
 --------------------------
 param:{
 "app_id":      app id 整数,
 "phone_type":  手机类型 整数,
 "phone_num":   手机号码 字符串,
 "appkey":      阿里云appkey 长整数,
 "appsecret":   阿里云secret 字符串,
 "clientid":    客户端id号 字符串,
 "enable":      是否接收推送 整数,
 "vibrate":     是否开启震动提示 整数,
 "sound":       声音是否开启 整数,
 "sound_file":  声音文件 字符串,
 "sys_lan":     手机系统类型 字符串
 "sys_num":     系统版本 整数
 "env":         env: 0表示发布版，1 表示开发版
 "login":       login:   1：登录 0：未登录
 }
 Success:               注册成功回调
 */
+ (void)registDeviceToServerForJPush:(NSDictionary*)param Success:(PushUtilsResultBlock)Success;

/*
 --------------------------
 |       注册设备列表        |
 --------------------------
 deviceID:    获取本机的deviceId,[CloudPushSDK getDeviceId],若为空传"unknow";
 serverList:  设备列表数组
 Success:     上传成功回调
 */
+ (void)setClientWithDeviceParamForJPush:(NSString*)deviceID addDeviceArr:(NSArray*)serverList Success:(PushUtilsResultBlock)Success;


@end
