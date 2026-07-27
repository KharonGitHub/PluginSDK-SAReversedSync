/*
    Plugin-SDK (Grand Theft Auto San Andreas) header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk

    Based on definitions from the GTA SA Reversed project.
    https://github.com/gta-reversed/gta-reversed
    Do not delete this comment block. Respect others' work!
*/
#pragma once

#include "PluginBase.h"
#include "CAEMP3BankLoader.h"
#include "CAEStreamingChannel.h"
#include "CAEStreamThread.h"
#include "CAEAudioChannel.h"
#include "enums/eBassSetting.h"
#include "enums/eSoundID.h"
#include "enums/eSoundBankSlot.h"
#include "enums/eSoundBank.h"

class tBeatInfo;

class PLUGIN_API CAEAudioHardware {
public:
    unsigned char                 m_bInitialised;
    char                          m_bDisableEffectsLoading;
    char                          m_prev;
    char                          field_3;
    char                          m_bHardwareMixAvailable;
    char                          m_nReverbEnvironment;
    short                         m_awChannelFlags[64];
    short                         field_86;
    int                           m_nReverbDepth;
    unsigned short                m_nNumAvailableChannels;
    unsigned short                m_nNumChannels;
    short                         m_anNumChannelsInSlot[64];
    float                         m_afChannelVolumes[64];
    int                           m_afUnkn[64];
    float                         m_afChannelsFrqScalingFactor[64];
    float                         m_fMusicMasterScalingFactor;
    float                         m_fEffectMasterScalingFactor;
    float                         m_fMusicFaderScalingFactor;
    float                         m_fEffectsFaderScalingFactor;
    float                         m_fStreamFaderScalingFactor;
    float                         m_fNonStreamFaderScalingFactor;
    float                         field_428;
    float                         field_42C;
    short                         m_aBankSlotIds[300];
    short                         m_aSoundTypes[300];
    short                         m_anVirtualChannelSoundLoopStartTimes[300];
    short                         m_anVirtualChannelSoundLengths[300];
    char                          m_BassSetting;
    char                          _pad1[3];
    float                         m_BassGain;
    CAEMP3BankLoader*             m_pMP3BankLoader;
    unsigned long                 m_pMP3TrackLoader;
    void*                         m_pDirectSound;
    int                           m_nSpeakerConfig;
    char                          m_n3dEffectsQueryResult;
    void*                         m_dsCaps;
    char                          gap[92];
    void*                         m_pDirectSound3dListener;  // IDirectSound3DListener
    CAEStreamingChannel*          m_pStreamingChannel;
    CAEStreamThread               m_streamThread;
    CAEAudioChannel*              m_aChannels[64];
    char                          m_BeatInfo[160];
    int                           field_1004;
    int                           field_1008;
    int                           field_100C;
    char                          m_PlayingTrackFlags;
    int                           field_1014;

public:
    int     GetActiveTrackID();
    int     GetTrackLengthMs();
    int     GetPlayingTrackID();
    int     GetTrackPlayTime();
    void    PlayTrack(uint trackID, int nextTrackID, uint startOffsetMs, uchar trackFlags, bool bUserTrack, bool bUserNextTrack);
    void    StartTrackPlayback();
    void    StopTrack();
    void    SetBassSetting(eBassSetting bassSetting, float bassGain);
    void    Service();
    void    SetChannelFlags(short channel, unsigned short channelId, short flags);
    void    SetChannelVolume(short channel, unsigned short channelId, float volume, unsigned char unused);
    unsigned short GetNumAvailableChannels() const;
    void    SetChannelFrequencyScalingFactor(short channel, unsigned short channelId, float factor);
    void    SetMusicMasterScalingFactor(float factor);
    void    SetEffectsMasterScalingFactor(float factor);
    float   GetMusicMasterScalingFactor() const;
    float   GetEffectsMasterScalingFactor() const;
    void    SetMusicFaderScalingFactor(float factor);
    void    SetEffectsFaderScalingFactor(float factor);
    void    SetStreamFaderScalingFactor(float factor);
    void    SetNonStreamFaderScalingFactor(float factor);
    void    EnableEffectsLoading();
    void    DisableEffectsLoading();
    void    PlaySound(short channel, unsigned short channelSlot, unsigned short soundIdInSlot, unsigned short bankSlot, short playPosition, short flags, float speed);
    void    StopSound(short channel, unsigned short channelSlot) const;
    void    SetChannelPosition(short slotId, unsigned short channelSlot, const CVector& posn, unsigned char unused) const;
    void    UpdateReverbEnvironment();
    void    RescaleChannelVolumes();
    void    PauseAllSounds();
    void    ResumeAllSounds();
    void    LoadSoundBank(eSoundBank bank, eSoundBankSlot slot);
    bool    IsSoundBankLoaded(eSoundBank bank, eSoundBankSlot slot);
    char    GetSoundBankLoadingStatus(eSoundBank bank, eSoundBankSlot slot);
    void    LoadSound(eSoundBank bank, eSoundID sfx, eSoundBankSlot slot);
    bool    IsSoundLoaded(eSoundBank bank, eSoundID sfx, eSoundBankSlot slot);
    bool    GetSoundLoadingStatus(eSoundBank bank, eSoundID sfx, eSoundBankSlot slot);
    void    EnableBassEq();
    void    DisableBassEq();
    float   GetSoundHeadroom(eSoundID sfx, eSoundBankSlot slot);
    short   AllocateChannels(unsigned short numChannels);
    void    GetChannelPlayTimes(short channel, short* playTimes);
    void    RequestVirtualChannelSoundInfo(unsigned short vch, eSoundID sfx, eSoundBankSlot slot);
    void    GetVirtualChannelSoundLengths(short* outArr) const;
    void    GetVirtualChannelSoundLoopStartTimes(short* outArr) const;
    void    GetBeatInfo(tBeatInfo* beatInfo);
    bool    IsStreamingFromDVD();
    char    GetDVDDriveLetter();
    bool    CheckDVD();
};

VALIDATE_OFFSET(CAEAudioHardware, m_bInitialised, 0x0);
VALIDATE_OFFSET(CAEAudioHardware, m_bDisableEffectsLoading, 0x1);
VALIDATE_OFFSET(CAEAudioHardware, m_prev, 0x2);
VALIDATE_OFFSET(CAEAudioHardware, field_3, 0x3);
VALIDATE_OFFSET(CAEAudioHardware, m_bHardwareMixAvailable, 0x4);
VALIDATE_OFFSET(CAEAudioHardware, m_nReverbEnvironment, 0x5);
VALIDATE_OFFSET(CAEAudioHardware, m_awChannelFlags, 0x6);
VALIDATE_OFFSET(CAEAudioHardware, field_86, 0x86);
VALIDATE_OFFSET(CAEAudioHardware, m_nReverbDepth, 0x88);
VALIDATE_OFFSET(CAEAudioHardware, m_nNumAvailableChannels, 0x8C);
VALIDATE_OFFSET(CAEAudioHardware, m_nNumChannels, 0x8E);
VALIDATE_OFFSET(CAEAudioHardware, m_anNumChannelsInSlot, 0x90);
VALIDATE_OFFSET(CAEAudioHardware, m_afChannelVolumes, 0x110);
VALIDATE_OFFSET(CAEAudioHardware, m_afUnkn, 0x210);
VALIDATE_OFFSET(CAEAudioHardware, m_afChannelsFrqScalingFactor, 0x310);
VALIDATE_OFFSET(CAEAudioHardware, m_fMusicMasterScalingFactor, 0x410);
VALIDATE_OFFSET(CAEAudioHardware, m_fEffectMasterScalingFactor, 0x414);
VALIDATE_OFFSET(CAEAudioHardware, m_fMusicFaderScalingFactor, 0x418);
VALIDATE_OFFSET(CAEAudioHardware, m_fEffectsFaderScalingFactor, 0x41C);
VALIDATE_OFFSET(CAEAudioHardware, m_fStreamFaderScalingFactor, 0x420);
VALIDATE_OFFSET(CAEAudioHardware, m_fNonStreamFaderScalingFactor, 0x424);
VALIDATE_OFFSET(CAEAudioHardware, field_428, 0x428);
VALIDATE_OFFSET(CAEAudioHardware, field_42C, 0x42C);
VALIDATE_OFFSET(CAEAudioHardware, m_aBankSlotIds, 0x430);
VALIDATE_OFFSET(CAEAudioHardware, m_aSoundTypes, 0x688);
VALIDATE_OFFSET(CAEAudioHardware, m_anVirtualChannelSoundLoopStartTimes, 0x8E0);
VALIDATE_OFFSET(CAEAudioHardware, m_anVirtualChannelSoundLengths, 0xB38);
VALIDATE_OFFSET(CAEAudioHardware, m_BassSetting, 0xD90);
VALIDATE_OFFSET(CAEAudioHardware, _pad1, 0xD91);
VALIDATE_OFFSET(CAEAudioHardware, m_BassGain, 0xD94);
VALIDATE_OFFSET(CAEAudioHardware, m_pMP3BankLoader, 0xD98);
VALIDATE_OFFSET(CAEAudioHardware, m_pMP3TrackLoader, 0xD9C);
VALIDATE_OFFSET(CAEAudioHardware, m_pDirectSound, 0xDA0);
VALIDATE_OFFSET(CAEAudioHardware, m_nSpeakerConfig, 0xDA4);
VALIDATE_OFFSET(CAEAudioHardware, m_n3dEffectsQueryResult, 0xDA8);
VALIDATE_OFFSET(CAEAudioHardware, m_dsCaps, 0xDAC);
VALIDATE_OFFSET(CAEAudioHardware, gap, 0xDB0);
VALIDATE_OFFSET(CAEAudioHardware, m_pDirectSound3dListener, 0xE0C);
VALIDATE_OFFSET(CAEAudioHardware, m_pStreamingChannel, 0xE10);
VALIDATE_OFFSET(CAEAudioHardware, m_streamThread, 0xE14);
VALIDATE_OFFSET(CAEAudioHardware, m_aChannels, 0xE64);
VALIDATE_OFFSET(CAEAudioHardware, m_BeatInfo, 0xF64);
VALIDATE_OFFSET(CAEAudioHardware, field_1004, 0x1004);
VALIDATE_OFFSET(CAEAudioHardware, field_1008, 0x1008);
VALIDATE_OFFSET(CAEAudioHardware, field_100C, 0x100C);
VALIDATE_OFFSET(CAEAudioHardware, m_PlayingTrackFlags, 0x1010);
VALIDATE_OFFSET(CAEAudioHardware, field_1014, 0x1014);
VALIDATE_SIZE(CAEAudioHardware, 0x1018);

extern CAEAudioHardware& AEAudioHardware;