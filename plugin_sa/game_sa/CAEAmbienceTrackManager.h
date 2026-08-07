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
#include "enums/eRadioID.h"
#include "enums/eAudioEvents.h"

class PLUGIN_API CAEAmbienceTrackManager {
public:
    bool     m_bOverrideRadio;
    bool     m_bLastAmbienceOverrodeRadio;
    bool     m_bStartAmbienceAtBeginning;
    char     _pad;
    eRadioID m_nAmbienceRadioStation;
    int      m_nHwClientHandle;
    int      m_nAmbienceStatus;
    int      m_nSpecialMissionAmbienceTrackID;
    int      m_nPrevAmbiencePlayTimeMs;
    int      m_nPrevAmbienceStopTimeMs;
    float    m_fVolume;
    float    m_fFreqFactor;
    int      m_nRequestedTrackID;
    int      m_nRequestedPlayingTrackID;

public:
    bool Initialise(int channelId);
    void Reset();

    void CheckForPause() const;

    void StopAmbienceTrack();
    bool IsAmbienceRadioActive() const;
    void UpdateAmbienceTrackAndVolume();

    bool IsAmbienceTrackActive() const;

    void PlaySpecialMissionAmbienceTrack(eAudioEvents event);
    void StopSpecialMissionAmbienceTrack();

    void Service(int playTime);
    void StartTrackPlayback() const;
};

VALIDATE_OFFSET(CAEAmbienceTrackManager, m_bOverrideRadio, 0x00);
VALIDATE_OFFSET(CAEAmbienceTrackManager, m_bLastAmbienceOverrodeRadio, 0x01);
VALIDATE_OFFSET(CAEAmbienceTrackManager, m_bStartAmbienceAtBeginning, 0x02);
VALIDATE_OFFSET(CAEAmbienceTrackManager, m_nAmbienceRadioStation, 0x04);
VALIDATE_OFFSET(CAEAmbienceTrackManager, m_nHwClientHandle, 0x08);
VALIDATE_OFFSET(CAEAmbienceTrackManager, m_nAmbienceStatus, 0x0C);
VALIDATE_OFFSET(CAEAmbienceTrackManager, m_nSpecialMissionAmbienceTrackID, 0x10);
VALIDATE_OFFSET(CAEAmbienceTrackManager, m_nPrevAmbiencePlayTimeMs, 0x14);
VALIDATE_OFFSET(CAEAmbienceTrackManager, m_nPrevAmbienceStopTimeMs, 0x18);
VALIDATE_OFFSET(CAEAmbienceTrackManager, m_fVolume, 0x1C);
VALIDATE_OFFSET(CAEAmbienceTrackManager, m_fFreqFactor, 0x20);
VALIDATE_OFFSET(CAEAmbienceTrackManager, m_nRequestedTrackID, 0x24);
VALIDATE_SIZE(CAEAmbienceTrackManager, 0x2C);

extern CAEAmbienceTrackManager& AEAmbienceTrackManager;