//
//  AgoraRtcEngineKitForGaming.h
//
//  Created by GongYuhua on 2017/3/8.
//  Copyright © 2017年 Agora. All rights reserved.
//

#import "AgoraRtcEngineObjects.h"

@class AgoraRtcEngineKitForGaming;

@protocol AgoraRtcEngineKitForGamingDelegate <NSObject>
@optional

- (void)rtcEngine:(AgoraRtcEngineKitForGaming *)engine didOccurWarning:(AgoraRtcWarningCode)warningCode;
- (void)rtcEngine:(AgoraRtcEngineKitForGaming *)engine didOccurError:(AgoraRtcErrorCode)errorCode;

- (void)rtcEngine:(AgoraRtcEngineKitForGaming *)engine reportAudioVolumeIndicationOfSpeakers:(NSArray*)speakers totalVolume:(NSInteger)totalVolume;

- (void)rtcEngine:(AgoraRtcEngineKitForGaming *)engine didJoinChannel:(NSString *)channel withUid:(NSUInteger)uid elapsed:(NSInteger)elapsed;
- (void)rtcEngine:(AgoraRtcEngineKitForGaming *)engine didRejoinChannel:(NSString*)channel withUid:(NSUInteger)uid elapsed:(NSInteger)elapsed;

- (void)rtcEngine:(AgoraRtcEngineKitForGaming *)engine didLeaveChannelWithStats:(AgoraRtcStats*)stats;

- (void)rtcEngine:(AgoraRtcEngineKitForGaming *)engine didAudioRouteChanged:(AudioOutputRouting)routing;

- (void)rtcEngine:(AgoraRtcEngineKitForGaming *)engine didAudioMuted:(BOOL)muted byUid:(NSUInteger)uid;

- (void)rtcEngine:(AgoraRtcEngineKitForGaming *)engine reportRtcStats:(AgoraRtcStats*)stats;

- (void)rtcEngine:(AgoraRtcEngineKitForGaming *)engine didJoinedOfUid:(NSUInteger)uid elapsed:(NSInteger)elapsed;
- (void)rtcEngine:(AgoraRtcEngineKitForGaming *)engine didOfflineOfUid:(NSUInteger)uid reason:(AgoraRtcUserOfflineReason)reason;

- (void)rtcEngineConnectionDidInterrupted:(AgoraRtcEngineKitForGaming *)rtcKit;
- (void)rtcEngineConnectionDidLost:(AgoraRtcEngineKitForGaming *)rtcKit;

- (void)rtcEngineRequestChannelKey:(AgoraRtcEngineKitForGaming *)rtcKit;
@end

__attribute__((visibility("default"))) @interface AgoraRtcEngineKitForGaming : NSObject

/**
 *  Initializes the AgoraRtcEngineKitForGaming object.
 *
 *  @param appId The appId is issued to the application developers by Agora.
 *  @param delegate The AgoraRtcEngineKitForGamingDelegate
 *
 *  @return an object of AgoraRtcEngineKitForGaming class
 */
+ (instancetype)sharedEngineWithAppId:(NSString *)appId delegate:(id<AgoraRtcEngineKitForGamingDelegate>)delegate;

/**
 *  Get the version information of the SDK
 *
 *  @return return the version string
 */
+ (NSString *)getSdkVersion;

/**
 *  Get the error description from SDK
 *  @param [in] code
 *         the error code
 *  @return string, the error description
 */
+ (NSString *)getErrorDescription:(NSInteger) code;

/**
 *  Specifies the SDK output log file
 *  @param filePath The full file path of the log file
 *
 *  @return return 0 if success or an error code
 */
- (int)setLogFile:(NSString*)filePath;

/**
 *  Specifiy the log level of output
 *  @param filter The log level
 *
 *  @return return 0 if success or an error code
 */
- (int)setLogFilter:(NSUInteger)filter;

/**
 *  Set the channel profile: such as game free mode, game command mode
 *  @param profile the channel profile
 *
 *  @return return 0 if success or an error code
 */
- (int)setChannelProfile:(AgoraRtcChannelProfile)profile;

/**
 *  Set the role of user: such as broadcaster, audience
 *
 *  @param role the role of client
 *  @param permissionKey the permission key to apply the role
 *  @return return 0 if success or an error code
 */
- (int)setClientRole:(AgoraRtcClientRole)role withKey: (NSString *)permissionKey;

/**
 *  Join specified channe by channel name with uid
 *
 *  @param channelName The specified channel name
 *  @param info The optinal info data
 *  @param uid, if you specify 0, we will generate a uid for you
 *
 *  @return return 0 if success or an error code
 */
- (int)joinChannel:(NSString *)channelName
              info:(NSString *)info
               uid:(NSUInteger)uid;

- (int)joinChannelByKey:(NSString *)channelKey
              channelName:(NSString *)channelName
              info:(NSString *)info
               uid:(NSUInteger)uid;

- (int)renewChannelKey:(NSString*)channelKey;

/**
* Leave current channel
*
*  @return return 0 if success or an error code
*/
- (int)leaveChannel;

- (void)pause;

- (void)resume;

/**
 * Enables audio function, which is enabled by default.
 *
 * @return return 0 if success or an error code
 */
- (int)enableAudio;

/**
 * Disable audio function
 *
 * @return return 0 if success or an error code
 */
- (int)disableAudio;

/**
 * Set parameters of the SDK
 * @param [in] options
 *        the parameters(in json format)
 *
 * @return return 0 if success or an error code
 */
- (int)setParameters:(NSString *)options;

/**
 * Enable / Disable speaker of device
 *
 * @param enableSpeaker YES: Switches to speakerphone. NO: Switches to headset
 *
 * @return return 0 if success or an error code
 */
- (int)setEnableSpeakerphone:(BOOL)enableSpeaker;

/**
 * test if the speakerphone is enabled or not.
 *
 * @return YES when speakerphone is enabled. NO when speakerphone is not enabled
 */
- (BOOL)isSpeakerphoneEnabled;

/**
 * Set default audio route to Speakerphone
 *
 * @param defaultToSpeaker YES: default to speakerphone. NO: default to earpiece for voice chat, speaker for video chat.
 *
 * @return return 0 if success or an error code
 */
- (int)setDefaultAudioRouteToSpeakerphone:(BOOL)defaultToSpeaker;

/**
 * Mute/unmute the local audio stream capturing
 * @param [in] mute
 *       true: mute
 *       false: unmute
 *
 * @return return 0 if success or an error code
 */
- (int)muteLocalAudioStream:(BOOL)mute;

/**
 * Mute/unmute all the remote audio stream receiving
 * @param [in] mute
 *       true: mute
 *       false: unmute
 *
 * @return return 0 if success or an error code
 */
- (int)muteAllRemoteAudioStreams:(BOOL)mute;

/**
 * Mute/unmute specified remote audio stream receiving
 * @param [in] uid
 *        the uid of the remote user you want to mute/unmute
 * @param [in] mute
 *       true: mute
 *       false: unmute
 *
 * @return return 0 if success or an error code
 */
- (int)muteRemoteAudioStream:(NSUInteger)uid
                            :(BOOL)mute;

/**
 * Start recording conversation to file specified by the file path.
 *
 * @param filePath file path to save recorded conversation.
 * @param quality  encode quality for the record file
 *
 * @return 0 when executed successfully. return negative value if failed.
 */
- (int)startAudioRecording:(NSString*)filePath
                   quality:(AgoraRtcAudioRecordingQuality)quality;

/**
 * Stop conversation recording
 *
 * @return 0 when executed successfully. return negative value if failed.
 */
- (int)stopAudioRecording;

/**
 * Mix microphone and local audio file into the audio stream
 * @param [in] filePath
 *        specify the path and file name of the audio file to be played
 * @param [in] loopback
 *        specify if local and remote participant can hear the audio file.
 *        false (default): both local and remote party can hear the the audio file
 *        true: only the local party can hear the audio file
 * @param [in] replace
 *        false (default): mix the local microphone captured voice with the audio file
 *        true: replace the microphone captured voice with the audio file
 * @param [in] cycle
 *        specify the number of cycles to play
 *        -1, infinite loop playback
 * @param [in] playTime
 *        specify the start time(ms) of the audio file to play
 *        0, from the start
 *
 * @return return 0 if success or an error code
 */
- (int)startAudioMixing:(NSString*) filePath
               loopback:(BOOL) loopback
                replace:(BOOL) replace
                  cycle:(NSInteger) cycle
               playTime:(NSInteger) playTime;

/**
 * stop mixing the local audio stream
 * @return return 0 if success or an error code
 */
- (int)stopAudioMixing;

/**
 * pause mixing the local audio stream
 *
 * @return return 0 if success or an error code
 */
- (int)pauseAudioMixing;

/**
 * resume mixing the local audio stream
 *
 * @return return 0 if success or an error code
 */
- (int)resumeAudioMixing;

/**
 * adjust mixing audio file volume
 * @param [in] volume range from 0 to 100
 *
 * @return return 0 if success or an error code
 */
- (int)adjustAudioMixingVolume:(NSInteger) volume;

/**
 * get the duration of the specified mixing audio file
 *
 * @return return duration(ms)
 */
- (int)getAudioMixingDuration;

/**
 * get the current playing position of the specified mixing audio file
 *
 * @return return the current playing(ms)
 */
- (int)getAudioMixingCurrentPosition;

/**
 * Adjust recording signal volume
 * @param [in] volume range from 0 to 400
 *
 * @return return 0 if success or an error code
 */
- (int)adjustRecordingSignalVolume:(NSInteger)volume;

/**
 * Adjust playback signal volume
 * @param [in] volume range from 0 to 400
 *
 * @return return 0 if success or an error code
 */
- (int)adjustPlaybackSignalVolume:(NSInteger)volume;

/**
 * Enable or disable the audio volume indication
 * @param [in] interval
 *        the period of the callback cycle, in ms
 *        interval <= 0: disable
 *        interval >  0: enable
 * @param [in] smooth
 *        the smooth parameter
 *
 * @return return 0 if success or an error code
 */
- (int)enableAudioVolumeIndication:(NSInteger)interval
                            smooth:(NSInteger)smooth;

/**
 * Get audio effect volume in the range of [0.0..100.0]
 *
 * @return return effect volume
 */
- (double) getEffectsVolume;

/**
 * Set audio effect volume
 * @param [in] volume
 *        in the range of [0..100]
 *
 * @return return 0 if success or an error code
 */
- (int) setEffectsVolume:(double) volume;

/**
 * Start playing local audio effect specified by file path and other parameters
 * @param [in] soundId
 *        specify the unique sound id
 * @param [in] filePath
 *        specify the path and file name of the effect audio file to be played
 * @param [in] loop
 *        whether to loop the effect playing or not, default value is false
 * @param [in] pitch
 *        frequency, in the range of [0.5..2.0], default value is 1.0
 * @param [in] pan
 *        stereo effect, in the range of [-1..1] where -1 enables only left channel, default value is 0.0
 * @param [in] gain
 *        volume, in the range of [0..100], default value is 100
 *
 * @return return 0 if success or an error code
 */
- (int) playEffect:(int) soundId
          filePath:(NSString*)filePath
              loop:(BOOL)loop
             pitch:(double) pitch
               pan:(double) pan
              gain:(double) gain;

/**
 * Stop playing specified audio effect
 * @param [in] soundId
 *        specify the unique sound id
 *
 * @return return 0 if success or an error code
 */
- (int) stopEffect:(int) soundId;

/**
 * Stop playing all audio effects
 *
 * @return return 0 if success or an error code
 */
- (int) stopAllEffects;

/**
 * Preload a compressed audio effect file specified by file path for later playing
 * @param [in] soundId
 *        specify the unique sound id
 * @param [in] filePath
 *        specify the path and file name of the effect audio file to be preloaded
 *
 * @return return 0 if success or an error code
 */
- (int) preloadEffect:(int) soundId
             filePath:(NSString*) filePath;

/**
 * Unload specified audio effect file from SDK
 *
 * @return return 0 if success or an error code
 */
- (int) unloadEffect:(int) soundId;

/**
 * Pause playing specified audio effect
 * @param [in] soundId
 *        specify the unique sound id
 *
 * @return return 0 if success or an error code
 */
- (int) pauseEffect:(int) soundId;

/**
 * Pausing playing all audio effects
 *
 * @return return 0 if success or an error code
 */
- (int) pauseAllEffects;

/**
 * Resume playing specified audio effect
 * @param [in] soundId
 *        specify the unique sound id
 *
 * @return return 0 if success or an error code
 */
- (int) resumeEffect:(int) soundId;

/**
 * Resume playing all audio effects
 *
 * @return return 0 if success or an error code
 */
- (int) resumeAllEffects;

/**
 * Set voice only mode(e.g. keyboard strokes sound will be eliminated)
 * @param [in] enable
 *        true for enable, false for disable
 *
 * @return return 0 if success or an error code
 */
- (int) setVoiceOnlyMode:(BOOL) enable;

/**
 * Place specified speaker's voice with pan and gain
 * @param [in] uid
 *        speaker's uid
 * @param [in] pan
 *        stereo effect, in the range of [-1..1] where -1 enables only left channel, default value is 0.0
 * @param [in] gain
 *        volume, in the range of [0..100], default value is 100
 *
 * @return return 0 if success or an error code
 */
- (int) setRemoteVoicePosition:(NSUInteger) uid
                           pan:(double) pan
                          gain:(double) gain;

/**
 * Change the pitch of local speaker's voice
 * @param [in] pitch
 *        frequency, in the range of [0.5..2.0], default value is 1.0
 *
 * @return return 0 if success or an error code
 */
- (int) setLocalVoicePitch:(double) pitch;

@end
