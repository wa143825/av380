//
//  NVMediaPlayer.h
//  OpenGLES2ShaderRanderDemo
//
//  Created by cyh on 12. 11. 26..
//  Copyright (c) 2012년 cyh3813. All rights reserved.
//

#import <UIKit/UIKit.h>
//player
#import <AudioToolbox/AudioToolbox.h>
#import <AudioToolbox/AudioQueue.h>

#import "LoginHandle.h"

#import "RecordVideoInfo.h"

#import "NVPanoPlayer.h"

#import "PlaybackDelegate.h"

@protocol SingleGestureRecognizerDelegate <NSObject>
@optional
-(void)singleGestureRecognizer;
@end
@interface NVPanoPlayer : UIView

@property (nonatomic,weak) id <SingleGestureRecognizerDelegate> singleDelegate;

@property (nonatomic, retain) UILabel *lblTimeOSD;

-(BOOL)scale:(CGFloat)scale;
-(void)clearView;

//player
@property (assign) id<PlaybackDelegate> playbackDelegate;


-(BOOL)startPlay:(int)nChn streamType:(int)nStreamType audio:(BOOL)bEnable loginHandel:(LoginHandle *)loginHandle;
-(BOOL)stopPlay;
-(void)setFullColorControl:(int)colorParam;
-(void)setLightControl:(int)lightParam;
-(void)enableAudio:(BOOL)bEnable;
-(void)setNetwordType:(int)nType;//add by luo 20170811

-(void)setImageOrientation:(int)nOrentation;//add by luo 20150106
-(void)setPTZActionLeft:(BOOL)left Right:(BOOL)right Up:(BOOL)up Down:(BOOL)down step:(int)nStep;
//回放文件
-(BOOL)startPlayBack:(LoginHandle *)loginHandle file:(RecordVideoInfo *)recordVideo;
-(BOOL)stopPlayBack;
-(int)setPlayProgress:(int)progress;
-(BOOL)startRecord:(NSString *)strSavePath;
-(BOOL)isRecording;
-(BOOL)stopRecord;
-(void)setPriValueCTRL:(BOOL)bCTRL_PRI Playback:(BOOL)bPLAYBACK_PRI Receive:(BOOL)bRECEIVE_PRI Speak:(BOOL)bSpeak_PRI Audio:(BOOL)bAudio_PRI PTZ:(BOOL)bPTZ_PRI;
-(void)enableRender:(BOOL)IsEnable;

- (void)setPanoMode:(int) iMode;//add by luo 20160914

//回放云端文件
-(BOOL)startCloudPlayBack:(int)nAccountID devID:(int)nDeviceID pToken:(NSString *)strPToken sToken:(NSString *)strSToken ecsip:(NSString *)strIP ecsport:(int)nPort file:(RecordVideoInfo *)recFile loginhandle:(LoginHandle*)loginhandle;

//回放报警图片录像  20171214
-(BOOL)startAlarmVideoPlayBack:(int)nAccountID devID:(int)nDeviceID sToken:(NSString *)strSToken ecsip:(NSString *)strIP ecsport:(int)nPort vType:(int)vtype vid:(long long)vid vts:(long long)vts;
-(BOOL)stopCloudPlayBack;
- (void)initFisheyeParam:(int)iFixType andCenterX:(int) xCenter andCenterY:(int)yCenter andRadius:(int)radius ;
- (void)setImageYUV:(int)RGBorYUV420 andImageBuffer:(Byte *) pData andWidth:(int) width andHeight:(int) height;
- (void)setMode:(int) iMode;
- (void)clearsurface;//RGB图片预览下一张加载过程的清屏工作
- (void)setActive: (BOOL) bActive;

-(void)setMoveTrackAction:(int)action switchState:(int)state; //移动跟踪看守位与开关
-(void)setZoomCtrl:(int)zoomParam; //聚焦

-(BOOL)isShotcutEnable;

-(void)showAcitvityView;
-(void)hideAcitvityView;


-(void)startSpeak;
-(void)stopSpeak;
-(BOOL)isSpeaking;
-(void)onHide;
-(void)onShow;

-(void)callPTZXLocationID:(int)nPTZXID handle:(LoginHandle *)lLoginHandle;

-(int)setPTZXLocationID:(int)nPTZXID handle:(LoginHandle *)lLoginHandle;

-(UIImage *)screenShot;//add by luo 20141120

-(BOOL)screenShotAndSaveToAlbum;//add by luo 20141120

-(void)onApplicationDidBecomeActive;
-(void)onApplicationWillResignActive;

//to hide
-(void)putAudioDataToQueue:(char *)pData Size:(int)nSize Id:(int)nID type:(int) nType;

-(void)resetRenderData;
-(void)updateRender;
-(void)freshRender;
//end to hide


- (void)timeIndexWhenPause: (int)pauseTimeIndex; // add by qiumuze 20170719
- (void)resetPause; // add by qiumuze 20170719

//add by lusongbin 20161104
-(void)setCamType:(int)camType;//这个是设置吸顶还是挂壁模式的

//add by zhantian 20180105
-(void)ztDoSomeRelease;



-(void)timeIndexChangePlayBackV30:(int)currentTime;


@end
