//
//  AgoraRtcEngineObjects.h
//  AgoraRtcEngineObjects
//
//  Created by GongYuhua on 2017/3/2.
//  Copyright © 2017年 Agora. All rights reserved.
//

#import <Foundation/Foundation.h>

#if TARGET_OS_IPHONE
#import <UIKit/UIKit.h>
typedef UIView VIEW_CLASS;

#elif TARGET_OS_MAC
#import <AppKit/AppKit.h>
typedef NSView VIEW_CLASS;

#endif

typedef NS_ENUM(NSInteger, AgoraRtcVideoProfile) {
    // res       fps  kbps
    AgoraRtc_VideoProfile_Invalid = -1,
    AgoraRtc_VideoProfile_120P = 0,         // 160x120   15   65
#if TARGET_OS_IPHONE
    AgoraRtc_VideoProfile_120P_3 = 2,		// 120x120   15   50
    AgoraRtc_VideoProfile_180P = 10,		// 320x180   15   140
    AgoraRtc_VideoProfile_180P_3 = 12,		// 180x180   15   100
    AgoraRtc_VideoProfile_180P_4 = 13,		// 240x180   15   120
#endif
    AgoraRtc_VideoProfile_240P = 20,		// 320x240   15   200
#if TARGET_OS_IPHONE
    AgoraRtc_VideoProfile_240P_3 = 22,		// 240x240   15   140
    AgoraRtc_VideoProfile_240P_4 = 23,		// 424x240   15   220
#endif
    AgoraRtc_VideoProfile_360P = 30,		// 640x360   15   400
#if TARGET_OS_IPHONE
    AgoraRtc_VideoProfile_360P_3 = 32,		// 360x360   15   260
#endif
    AgoraRtc_VideoProfile_360P_4 = 33,		// 640x360   30   600
    AgoraRtc_VideoProfile_360P_6 = 35,		// 360x360   30   400
    AgoraRtc_VideoProfile_360P_7 = 36,		// 480x360   15   320
    AgoraRtc_VideoProfile_360P_8 = 37,		// 480x360   30   490
    AgoraRtc_VideoProfile_360P_9 = 38,      // 640x360   15   800
    AgoraRtc_VideoProfile_360P_10 = 39,     // 640x360   24   800
    AgoraRtc_VideoProfile_360P_11 = 100,    // 640x360   24   1000
    AgoraRtc_VideoProfile_480P = 40,		// 640x480   15   500
#if TARGET_OS_IPHONE
    AgoraRtc_VideoProfile_480P_3 = 42,		// 480x480   15   400
#endif
    AgoraRtc_VideoProfile_480P_4 = 43,		// 640x480   30   750
    AgoraRtc_VideoProfile_480P_6 = 45,		// 480x480   30   600
    AgoraRtc_VideoProfile_480P_8 = 47,		// 848x480   15   610
    AgoraRtc_VideoProfile_480P_9 = 48,		// 848x480   30   930
    AgoraRtc_VideoProfile_480P_10 = 49,		// 640x480   10   400
    AgoraRtc_VideoProfile_720P = 50,		// 1280x720  15   1130
    AgoraRtc_VideoProfile_720P_3 = 52,		// 1280x720  30   1710
    AgoraRtc_VideoProfile_720P_5 = 54,		// 960x720   15   910
    AgoraRtc_VideoProfile_720P_6 = 55,		// 960x720   30   1380
    AgoraRtc_VideoProfile_1080P = 60,		// 1920x1080 15   2080
    AgoraRtc_VideoProfile_1080P_3 = 62,		// 1920x1080 30   3150
    AgoraRtc_VideoProfile_1080P_5 = 64,		// 1920x1080 60   4780
    AgoraRtc_VideoProfile_1440P = 66,		// 2560x1440 30   4850
    AgoraRtc_VideoProfile_1440P_2 = 67,		// 2560x1440 60   7350
    AgoraRtc_VideoProfile_4K = 70,			// 3840x2160 30   8190
    AgoraRtc_VideoProfile_4K_3 = 72,		// 3840x2160 60   13500
    AgoraRtc_VideoProfile_DEFAULT = AgoraRtc_VideoProfile_360P,
};

typedef NS_ENUM(NSInteger, AgoraRtcWarningCode) {
    AgoraRtc_Warn_InvalidView = 8,
    AgoraRtc_Warn_InitVideo = 16,
    AgoraRtc_Warn_Pending = 20,
    AgoraRtc_Warn_NoAvailableChannel = 103,
    AgoraRtc_Warn_LookupChannelTimeout = 104,
    AgoraRtc_Warn_LookupChannelRejected = 105,
    AgoraRtc_Warn_OpenChannelTimeout = 106,
    AgoraRtc_Warn_OpenChannelRejected = 107,
    AgoraRtc_Warn_SwitchLiveVideoTimeout = 111,
    // sdk:vos, callmanager, peermanager: 100~1000
    AgoraRtc_Warn_SetClientRoleTimeout = 118,
    AgoraRtc_Warn_SetClientRoleNotAuthorized = 119,
    AgoraRtc_Warn_AudioMixingOpenError = 701,

    AgoraRtc_Warn_Adm_RuntimePlayoutWarning = 1014,
    AgoraRtc_Warn_Adm_RuntimeRecordingWarning = 1016,
    AgoraRtc_Warn_Adm_RecordAudioSilence = 1019,
    AgoraRtc_Warn_Adm_PlaybackMalfunction = 1020,
    AgoraRtc_Warn_Adm_RecordMalfunction = 1021,
    AgoraRtc_Warn_Adm_Interruption = 1025,
    AgoraRtc_Warn_Adm_RouteChange = 1026,
    AgoraRtc_Warn_Apm_Howling = 1051,
};

typedef NS_ENUM(NSInteger, AgoraRtcErrorCode) {
    AgoraRtc_Error_NoError = 0,
    AgoraRtc_Error_Failed = 1,
    AgoraRtc_Error_InvalidArgument = 2,
    AgoraRtc_Error_NotReady = 3,
    AgoraRtc_Error_NotSupported = 4,
    AgoraRtc_Error_Refused = 5,
    AgoraRtc_Error_BufferTooSmall = 6,
    AgoraRtc_Error_NotInitialized = 7,
    AgoraRtc_Error_NoPermission = 9,
    AgoraRtc_Error_TimedOut = 10,
    AgoraRtc_Error_Canceled = 11,
    AgoraRtc_Error_TooOften = 12,
    AgoraRtc_Error_BindSocket = 13,
    AgoraRtc_Error_NetDown = 14,
    AgoraRtc_Error_NoBufs = 15,
    AgoraRtc_Error_JoinChannelRejected = 17,
    AgoraRtc_Error_LeaveChannelRejected = 18,
    AgoraRtc_Error_AlreadyInUse = 19,

    AgoraRtc_Error_InvalidAppId = 101,
    AgoraRtc_Error_InvalidChannelName = 102,
    AgoraRtc_Error_ChannelKeyExpired = 109,
    AgoraRtc_Error_InvalidChannelKey = 110,
    AgoraRtc_Error_ConnectionInterrupted = 111, // only used in web sdk
    AgoraRtc_Error_ConnectionLost = 112, // only used in web sdk
    AgoraRtc_Error_NotInChannel = 113,
    AgoraRtc_Error_SizeTooLarge = 114,
    AgoraRtc_Error_BitrateLimit = 115,
    AgoraRtc_Error_TooManyDataStreams = 116,
    AgoraRtc_Error_DecryptionFailed = 120,

    AgoraRtc_Error_LoadMediaEngine = 1001,
    AgoraRtc_Error_StartCall = 1002,
    AgoraRtc_Error_StartCamera = 1003,
    AgoraRtc_Error_StartVideoRender = 1004,
    AgoraRtc_Error_Adm_GeneralError = 1005,
    AgoraRtc_Error_Adm_JavaResource = 1006,
    AgoraRtc_Error_Adm_SampleRate = 1007,
    AgoraRtc_Error_Adm_InitPlayout = 1008,
    AgoraRtc_Error_Adm_StartPlayout = 1009,
    AgoraRtc_Error_Adm_StopPlayout = 1010,
    AgoraRtc_Error_Adm_InitRecording = 1011,
    AgoraRtc_Error_Adm_StartRecording = 1012,
    AgoraRtc_Error_Adm_StopRecording = 1013,
    AgoraRtc_Error_Adm_RuntimePlayoutError = 1015,
    AgoraRtc_Error_Adm_RuntimeRecordingError = 1017,
    AgoraRtc_Error_Adm_RecordAudioFailed = 1018,
    AgoraRtc_Error_Adm_Play_Abnormal_Frequency = 1020,
    AgoraRtc_Error_Adm_Record_Abnormal_Frequency = 1021,
    AgoraRtc_Error_Adm_Init_Loopback  = 1022,
    AgoraRtc_Error_Adm_Start_Loopback = 1023,
    // 1025, as warning for interruption of adm on ios
    // 1026, as warning for route change of adm on ios
    // VDM error code starts from 1500
    AgoraRtc_Error_Vdm_Camera_Not_Authorized = 1501,

    // VCM error code starts from 1600
    AgoraRtc_Error_Vcm_Unknown_Error = 1600,
    AgoraRtc_Error_Vcm_Encoder_Init_Error = 1601,
    AgoraRtc_Error_Vcm_Encoder_Encode_Error = 1602,
    AgoraRtc_Error_Vcm_Encoder_Set_Error = 1603,
};

typedef NS_ENUM(NSInteger, AgoraRtcChannelProfile) {
    AgoraRtc_ChannelProfile_Game_Free_Mode = 2,
    AgoraRtc_ChannelProfile_Game_Command_Mode = 3,
};

typedef NS_ENUM(NSInteger, AgoraRtcClientRole) {
    AgoraRtc_ClientRole_Broadcaster = 1,
    AgoraRtc_ClientRole_Audience = 2,
};

typedef NS_ENUM(NSUInteger, AgoraRtcQuality) {
    AgoraRtc_Quality_Unknown = 0,
    AgoraRtc_Quality_Excellent = 1,
    AgoraRtc_Quality_Good = 2,
    AgoraRtc_Quality_Poor = 3,
    AgoraRtc_Quality_Bad = 4,
    AgoraRtc_Quality_VBad = 5,
    AgoraRtc_Quality_Down = 6,
};

typedef NS_ENUM(NSUInteger, AgoraRtcUserOfflineReason) {
    AgoraRtc_UserOffline_Quit = 0,
    AgoraRtc_UserOffline_Dropped = 1,
    AgoraRtc_UserOffline_BecomeAudience = 2,
};

typedef NS_ENUM(NSInteger, AgoraRtcVideoStreamType) {
    AgoraRtc_VideoStream_Unknown = -1,
    AgoraRtc_VideoStream_High = 0,
    AgoraRtc_VideoStream_Low = 1,
    AgoraRtc_VideoStream_Medium = 2,
};

typedef NS_ENUM(NSInteger, AudioOutputRouting)
{
    AudioOutputRouting_Default = -1,
    AudioOutputRouting_Headset = 0,
    AudioOutputRouting_Earpiece = 1,
    AudioOutputRouting_HeadsetNoMic = 2,
    AudioOutputRouting_Speakerphone = 3,
    AudioOutputRouting_Loudspeaker = 4,
    AudioOutputRouting_HeadsetBluetooth = 5
};

typedef NS_ENUM(NSInteger, AgoraRtcAudioRecordingQuality) {
    AgoraRtc_AudioRecordingQuality_Low = 0,
    AgoraRtc_AudioRecordingQuality_Medium = 1,
    AgoraRtc_AudioRecordingQuality_High = 2
};

typedef NS_ENUM(NSUInteger, AgoraRtcLogFilter) {
    AgoraRtc_LogFilter_Off = 0,
    AgoraRtc_LogFilter_Debug = 0x080f,
    AgoraRtc_LogFilter_Info = 0x000f,
    AgoraRtc_LogFilter_Warn = 0x000e,
    AgoraRtc_LogFilter_Error = 0x000c,
    AgoraRtc_LogFilter_Critical = 0x0008,
};


typedef NS_ENUM(NSUInteger, AgoraRtcRenderMode) {
    /**
     Hidden(1): If the video size is different than that of the display window, crops the borders of the video (if the video is bigger) or stretch the video (if the video is smaller) to fit it in the window.
     */
    AgoraRtc_Render_Hidden = 1,

    /**
     AgoraRtc_Render_Fit(2): If the video size is different than that of the display window, resizes the video proportionally to fit the window.
     */
    AgoraRtc_Render_Fit = 2,

    /**
     AgoraRtc_Render_Adaptive(3)：If both callers use the same screen orientation, i.e., both use vertical screens or both use horizontal screens, the AgoraRtc_Render_Hidden mode applies; if they use different screen orientations, i.e., one vertical and one horizontal, the AgoraRtc_Render_Fit mode applies.
     */
    AgoraRtc_Render_Adaptive = 3,
};

typedef NS_ENUM(NSUInteger, AgoraRtcQualityReportFormat) {
    AgoraRtc_QualityReportFormat_Json = 0,
    AgoraRtc_QualityReportFormat_Html = 1,
};

typedef NS_ENUM(NSInteger, AgoraRtcRawAudioFrameOpMode) {
    AgoraRtc_RawAudioFrame_OpMode_ReadOnly = 0,
    AgoraRtc_RawAudioFrame_OpMode_WriteOnly = 1,
    AgoraRtc_RawAudioFrame_OpMode_ReadWrite = 2,
};

#if (!(TARGET_OS_IPHONE) && (TARGET_OS_MAC))

typedef NS_ENUM(NSInteger, AgoraRtcDeviceType) {
    AgoraRtc_DeviceType_Audio_Unknown = -1,
    AgoraRtc_DeviceType_Audio_Recording = 0,
    AgoraRtc_DeviceType_Audio_Playout = 1,
    AgoraRtc_DeviceType_Video_Render = 2,
    AgoraRtc_DeviceType_Video_Capture = 3,
};

__attribute__((visibility("default"))) @interface AgoraRtcDeviceInfo : NSObject

@property (assign, nonatomic) int index;
@property (assign, nonatomic) AgoraRtcDeviceType type; // 0: recording, 1: playback, 2: capture
@property (copy, nonatomic) NSString* deviceId; //
@property (copy, nonatomic) NSString* deviceName; //
@end

#endif


__attribute__((visibility("default"))) @interface AgoraRtcVideoCanvas : NSObject

/**
 *  The video display view. The SDK does not maintain the lifecycle of the view.
 The view can be safely released after calling leaveChannel with a returned value.
 The SDK keeps a cache of the view value, so 'setupLocalVideo' to set the view value to NULL could be able to clear cache before switching or releasing view.
 */
@property (strong, nonatomic) VIEW_CLASS* view;
@property (assign, nonatomic) AgoraRtcRenderMode renderMode; // the render mode of view: hidden, fit and adaptive
@property (assign, nonatomic) NSUInteger uid; // the user id of view
@end


__attribute__((visibility("default"))) @interface AgoraRtcStats : NSObject
@property (assign, nonatomic) NSUInteger duration;
@property (assign, nonatomic) NSUInteger txBytes;
@property (assign, nonatomic) NSUInteger rxBytes;
@property (assign, nonatomic) NSUInteger txAudioKBitrate;
@property (assign, nonatomic) NSUInteger rxAudioKBitrate;
@property (assign, nonatomic) NSUInteger txVideoKBitrate;
@property (assign, nonatomic) NSUInteger rxVideoKBitrate;
@property (assign, nonatomic) NSUInteger users;
@end

__attribute__((visibility("default"))) @interface AgoraRtcLocalVideoStats : NSObject
@property (assign, nonatomic) NSUInteger sentBitrate;
@property (assign, nonatomic) NSUInteger sentFrameRate;
@end

__attribute__((visibility("default"))) @interface AgoraRtcRemoteVideoStats : NSObject
@property (assign, nonatomic) NSUInteger uid;
@property (assign, nonatomic) NSUInteger delay;
@property (assign, nonatomic) NSUInteger width;
@property (assign, nonatomic) NSUInteger height;
@property (assign, nonatomic) NSUInteger receivedBitrate;
@property (assign, nonatomic) NSUInteger receivedFrameRate;
@property (assign, nonatomic) AgoraRtcVideoStreamType rxStreamType;
@end

__attribute__((visibility("default"))) @interface AgoraRtcAudioVolumeInfo : NSObject
@property (assign, nonatomic) NSUInteger uid;
@property (assign, nonatomic) NSUInteger volume;
@end

__attribute__((visibility("default"))) @interface AgoraRtcVideoCompositingRegion : NSObject
@property (assign, nonatomic) NSUInteger uid;
@property (assign, nonatomic) double x;
@property (assign, nonatomic) double y;
@property (assign, nonatomic) double width;
@property (assign, nonatomic) double height;
@property (assign, nonatomic) NSInteger zOrder; //optional, [0, 100] //0 (default): bottom most, 100: top most
@property (assign, nonatomic) double alpha; //optional, [0, 1.0] where 0 denotes throughly transparent, 1.0 opaque
@property (assign, nonatomic) AgoraRtcRenderMode renderMode;
@end

__attribute__((visibility("default"))) @interface AgoraRtcVideoCompositingLayout : NSObject
@property (assign, nonatomic) NSInteger canvasWidth;
@property (assign, nonatomic) NSInteger canvasHeight;
@property (copy, nonatomic) NSString* backgroundColor;//e.g. "#c0c0c0"
@property (retain, nonatomic) NSArray* regions; //array of AgoraRtcVideoCompositingRegion
@property (copy, nonatomic) NSString* appData;//app defined data
@end
