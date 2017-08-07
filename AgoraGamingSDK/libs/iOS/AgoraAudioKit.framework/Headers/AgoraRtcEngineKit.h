//
//  AgoraRtcEngineKit.h
//  AgoraRtcEngineKit
//
//  Created by Sting Feng on 2015-8-11.
//  Copyright (c) 2015 Agora. All rights reserved.
//

#import "AgoraRtcEngineKitLite.h"

@interface AgoraRtcEngineKit (AgoraVideoExtension)
/**
 *  Enables video mode.  Switches from audio to video mode.
 It could be called during a call and before entering a channel.
 *
 *  @return 0 when this method is called successfully, or negative value when this method failed.
 */
- (int)enableVideo;

/**
 *  Disable video mode. Switch from video to audio mode.
 It could be called during a call and before entering a channel.
 *
 *  @return 0 when this method is called successfully, or negative value when this method failed.
 */
- (int)disableVideo;

/**
 *  Enables local video.
 *
 *  @param enabled YES to enabled local video capture and render (by default), NO to disable using local camera device.
 *  @return 0 when this method is called successfully, or negative value when this method failed.
 */
- (int)enableLocalVideo:(BOOL)enabled;

/**
 *  start local video preview, while not sending data to server
 *
 *  @return 0 when this method is called successfully, or negative value when this method failed.
 */
- (int)startPreview;

/**
 *  stop local video preview
 *
 *  @return 0 when this method is called successfully, or negative value when this method failed.
 */
- (int)stopPreview;

/**
 *  API deprecated. Please refer to open source https://github.com/AgoraLab/AgoraDemo, the function "onSwitchRemoteUsers" in demo agora-easycall-ios-oc
 *   Switches between video display views of two different users.
 *
 *  @param uid1 The user ID of the user whose video is to be switched.
 *  @param uid2 The user ID of another user whose video is to be switched.
 *
 *  @return 0 when executed successfully. return negative value if failed.
 */
- (int)switchView:(NSUInteger)uid1
       andAnother:(NSUInteger)uid2 __deprecated;

/**
 *  Switches between front and back cameras.
 *
 *  @return 0 when executed successfully. return negative value if failed.
 */
- (int)switchCamera;

/**
 *  set video profile, including resolution, fps, kbps
 *
 *  @param profile enumeration definition about the video resolution, fps and max kbps
 *
 *  @return 0 when executed successfully. return negative value if failed.
 */
- (int)setVideoProfile:(AgoraRtcVideoProfile)profile
    swapWidthAndHeight:(BOOL)swapWidthAndHeight;

/**
 *  Start screen capture
 *
 *  @return 0 when executed successfully. return negative value if failed.
 */
- (int)startScreenCapture:(NSUInteger)windowId;

/**
 *  Stop screen capture
 *
 *  @return 0 when executed successfully. return negative value if failed.
 */
- (int)stopScreenCapture;

- (int)setScreenCaptureId:(NSUInteger)windowId;

/** BEGIN OF VIDIO METHODS */

/**
 *  Set up the local video view. The video canvus is initialized with video display setting. And it could be called before entering a channel.
 *
 *  @param local the canvas is composed of view, renderMode and uid. How to initialize 'local'? please take a look at 'AgoraRtcVideoCanvas'
 *
 *  @return 0 when executed successfully. return negative value if failed.
 */
- (int)setupLocalVideo:(AgoraRtcVideoCanvas*)local;


/**
 *  Set up the remote video view. The video canvus is initialized with video display setting. It could be called after receiving the remote video streams to configure the video settings.
 *
 *  @param remote the canvas is composed of view, renderMode and uid. How to initialize 'remote'? please take a look at 'AgoraRtcVideoCanvas'
 *
 *  @return 0 when executed successfully. return negative value if failed.
 */
- (int)setupRemoteVideo:(AgoraRtcVideoCanvas*)remote;


/**
 *  Configure display setting of local view. And it could be called mutiple times during a call.
 *
 *  @param mode There are Hidden(1), Fit(2) and Adaptive(3) mode. Please take a look at definition of enum AgoraRtcRenderMode
 *
 *  @return 0 when executed successfully. return negative value if failed.
 */
- (int)setLocalRenderMode:(AgoraRtcRenderMode) mode;


/**
 *  Configure display setting of remote view. And it could be called mutiple times during a call.
 *
 *  @param uid  The user id of remote view.
 *  @param mode There are Hidden(1), Fit(2) and Adaptive(3) mode. Please take a look at definition of enum AgoraRtcRenderMode
 *
 *  @return 0 when executed successfully. return negative value if failed.
 */
- (int)setRemoteRenderMode: (NSUInteger)uid
                      mode:(AgoraRtcRenderMode) mode;



/**
 *  Enable / disable sending local video streams to the network.
 *
 *  @param mute YES: stop sending local video stream to the network, NO: start sending local video stream.
 *
 *  @return 0 when executed successfully. return negative value if failed.
 */
- (int)muteLocalVideoStream:(BOOL)mute;


/**
 *  Enables / disables playing all remote callers’ video streams.
 *
 *  @param mute YES: stop playing, NO: start playing.
 *
 *  @return 0 when executed successfully. return negative value if failed.
 */
- (int)muteAllRemoteVideoStreams:(BOOL)mute;

/**
 *  Enable / disable a remote user's video stream
 *
 *  @param uid  The remote user id
 *  @param mute YES: discard the video stream from remote user, NO: start receiving remote video stream.
 *
 *  @return 0 when executed successfully. return negative value if failed.
 */
- (int)muteRemoteVideoStream:(NSUInteger)uid
                        mute:(BOOL)mute;

/** END OF VIDIO METHODS */

- (int)enableDualStreamMode:(BOOL)enabled;

- (int) setRemoteVideoStream: (NSUInteger) uid
                        type: (AgoraRtcVideoStreamType) streamType;

- (int) startRecordingService:(NSString*)recordingKey;
- (int) stopRecordingService:(NSString*)recordingKey;
- (int) refreshRecordingServiceStatus;

- (int)enableWebSdkInteroperability:(BOOL)enabled;

- (int)setVideoQualityParameters:(BOOL)preferFrameRateOverImageQuality;

- (int)setVideoCompositingLayout:(AgoraRtcVideoCompositingLayout*)layout;

- (int)clearVideoCompositingLayout;

#if (!(TARGET_OS_IPHONE) && (TARGET_OS_MAC))

- (void) monitorDeviceChange: (BOOL)enabled;
- (NSArray*) enumerateDevices:(AgoraRtcDeviceType)type;  // return array of AgoraRtcDeviceInfo
- (NSString*) getDeviceId:(AgoraRtcDeviceType)type;
- (int) setDevice:(AgoraRtcDeviceType)type deviceId:(NSString *) deviceId;
- (int) getDeviceVolume:(AgoraRtcDeviceType)type;
- (int) setDeviceVolume:(AgoraRtcDeviceType)type volume:(int)volume;

- (int) startRecordingDeviceTest:(int) indicationInterval;
- (int) stopRecordingDeviceTest;

- (int) startPlaybackDeviceTest:(NSString *) audioFileName;
- (int) stopPlaybackDeviceTest;

- (int) startCaptureDeviceTest:(NSView *) view;
- (int) stopCaptureDeviceTest;
#endif

#pragma mark - deprecated blocks
- (void)audioVolumeIndicationBlock:(void(^)(NSArray *speakers, NSInteger totalVolume))audioVolumeIndicationBlock __deprecated;
- (void)firstLocalVideoFrameBlock:(void(^)(NSInteger width, NSInteger height, NSInteger elapsed))firstLocalVideoFrameBlock __deprecated;
- (void)firstRemoteVideoDecodedBlock:(void(^)(NSUInteger uid, NSInteger width, NSInteger height, NSInteger elapsed))firstRemoteVideoDecodedBlock __deprecated;
- (void)firstRemoteVideoFrameBlock:(void(^)(NSUInteger uid, NSInteger width, NSInteger height, NSInteger elapsed))firstRemoteVideoFrameBlock __deprecated;
- (void)userJoinedBlock:(void(^)(NSUInteger uid, NSInteger elapsed))userJoinedBlock __deprecated;
- (void)userOfflineBlock:(void(^)(NSUInteger uid))userOfflineBlock __deprecated;
- (void)userMuteAudioBlock:(void(^)(NSUInteger uid, BOOL muted))userMuteAudioBlock __deprecated;
- (void)userMuteVideoBlock:(void(^)(NSUInteger uid, BOOL muted))userMuteVideoBlock __deprecated;
- (void)localVideoStatBlock:(void(^)(NSInteger sentBitrate, NSInteger sentFrameRate))localVideoStatBlock __deprecated;
- (void)remoteVideoStatBlock:(void(^)(NSUInteger uid, NSInteger delay, NSInteger receivedBitrate, NSInteger receivedFrameRate))remoteVideoStatBlock __deprecated;
- (void)cameraReadyBlock:(void(^)())cameraReadyBlock __deprecated;
- (void)connectionLostBlock:(void(^)())connectionLostBlock __deprecated;
- (void)rejoinChannelSuccessBlock:(void(^)(NSString* channel, NSUInteger uid, NSInteger elapsed))rejoinChannelSuccessBlock __deprecated;
- (void)rtcStatsBlock:(void(^)(AgoraRtcStats* stat))rtcStatsBlock __deprecated;
- (void)leaveChannelBlock:(void(^)(AgoraRtcStats* stat))leaveChannelBlock __deprecated;
- (void)audioQualityBlock:(void(^)(NSUInteger uid, AgoraRtcQuality quality, NSUInteger delay, NSUInteger lost))audioQualityBlock __deprecated;
- (void)networkQualityBlock:(void(^)(NSUInteger uid, AgoraRtcQuality txQuality, AgoraRtcQuality rxQuality))networkQualityBlock __deprecated;
- (void)lastmileQualityBlock:(void(^)(AgoraRtcQuality quality))lastmileQualityBlock __deprecated;
- (void)mediaEngineEventBlock:(void(^)(NSInteger code))mediaEngineEventBlock __deprecated;
@end
