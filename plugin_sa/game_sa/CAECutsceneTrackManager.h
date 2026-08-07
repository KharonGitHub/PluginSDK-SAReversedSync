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

class PLUGIN_API CAECutsceneTrackManager {
public:
    bool         m_bPlayRequest;
    bool         m_bPaused;
    char         _pad1[2];
    int          m_nAudioChannel;
    int          m_nStatus;
    unsigned int m_nTrackId;
    int          field_10;
    unsigned int field_14;
    int          field_18;
    char         m_bIsUserTrack;
    char         _pad2[4];
    unsigned int m_nPlayingTrackId;
    int          m_nTrackPlayTime;
    int          m_nTrackLengthMs;

public:
    bool Initialise(int nAudioChannel);

    void PlayPreloadedCutsceneTrack();
    void StopCutsceneTrack();

    bool IsCutsceneTrackActive() const;
    int8_t GetCutsceneTrackStatus() const;

    void PauseTrack(bool pause);
    void Service(int trackPlayTime);
    void CheckForPause() const;
    void PreloadBeatTrack(short trackId, bool wait);
    void PreloadCutsceneTrack(short trackId, bool wait);
    void StartTrackPlayback() const;
};

VALIDATE_OFFSET(CAECutsceneTrackManager, m_bPlayRequest, 0x00);
VALIDATE_OFFSET(CAECutsceneTrackManager, m_bPaused, 0x01);
VALIDATE_OFFSET(CAECutsceneTrackManager, m_nAudioChannel, 0x04);
VALIDATE_OFFSET(CAECutsceneTrackManager, m_nStatus, 0x08);
VALIDATE_OFFSET(CAECutsceneTrackManager, m_nTrackId, 0x0C);
VALIDATE_OFFSET(CAECutsceneTrackManager, m_bIsUserTrack, 0x1C);
VALIDATE_OFFSET(CAECutsceneTrackManager, m_nPlayingTrackId, 0x24);
VALIDATE_OFFSET(CAECutsceneTrackManager, m_nTrackPlayTime, 0x28);
VALIDATE_OFFSET(CAECutsceneTrackManager, m_nTrackLengthMs, 0x2C);
VALIDATE_SIZE(CAECutsceneTrackManager, 0x30);

extern CAECutsceneTrackManager& AECutsceneTrackManager;