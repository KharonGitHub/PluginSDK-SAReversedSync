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

#include "enums/eUserTrackPlayMode.h"
#include "enums/eUserTrackScanState.h"
#include "enums/eAudioFileType.h"

struct PLUGIN_API tAudioExtensionType {
    const char* extension;
    eAudioFileType type;
};

VALIDATE_OFFSET(tAudioExtensionType, extension, 0x00);
VALIDATE_OFFSET(tAudioExtensionType, type, 0x04);
VALIDATE_SIZE(tAudioExtensionType, 0x08);

struct PLUGIN_API tUserTracksInfo {
    unsigned int startUfilesPath;
    unsigned int pathLength;
    eAudioFileType fileType;
};

VALIDATE_OFFSET(tUserTracksInfo, startUfilesPath, 0x00);
VALIDATE_OFFSET(tUserTracksInfo, pathLength, 0x04);
VALIDATE_OFFSET(tUserTracksInfo, fileType, 0x08);
VALIDATE_SIZE(tUserTracksInfo, 0x0C);

class CAEStreamingDecoder; // Forward declaration, dont wanna touch the decoder stuff for now

class PLUGIN_API CAEUserRadioTrackManager {
public:
    tUserTracksInfo*    m_pUserTracksInfo;                     
    bool                m_bUserTracksLoaded;                   
    bool                m_bUserTracksLoadedCopy;               
    unsigned short      m_nUserTracksCount;                    
    bool                m_baDecodersSupported[8];   // Max supported decoders
    DWORD               m_nUserTracksScanThreadID;             
    HANDLE              m_hwndUserTracksScanThreadHandle;      
    eUserTrackScanState m_nUserTracksScanState;      

    bool                 Initialise();
    void                 Shutdown();
    char*                GetTrackPath(int trackID) const;
    CAEStreamingDecoder* LoadUserTrack(int trackID);
    bool                 ReadUserTracks();
    bool                 ScanUserTracks();
    void                 DeleteUserTracksInfo();
    void                 SetUserTrackIndex(int index);
    int                  SelectUserTrackIndex() const;
    eAudioFileType       GetAudioFileType(const char* filename);
    bool                 IsShortcut(const char* path);
    unsigned char        GetUserTrackPlayMode();
};

VALIDATE_OFFSET(CAEUserRadioTrackManager, m_pUserTracksInfo, 0x00);
VALIDATE_OFFSET(CAEUserRadioTrackManager, m_bUserTracksLoaded, 0x04);
VALIDATE_OFFSET(CAEUserRadioTrackManager, m_bUserTracksLoadedCopy, 0x05);
VALIDATE_OFFSET(CAEUserRadioTrackManager, m_nUserTracksCount, 0x06);
VALIDATE_OFFSET(CAEUserRadioTrackManager, m_baDecodersSupported, 0x08);
VALIDATE_OFFSET(CAEUserRadioTrackManager, m_nUserTracksScanThreadID, 0x10);
VALIDATE_OFFSET(CAEUserRadioTrackManager, m_hwndUserTracksScanThreadHandle, 0x14);
VALIDATE_OFFSET(CAEUserRadioTrackManager, m_nUserTracksScanState, 0x18);
VALIDATE_SIZE(CAEUserRadioTrackManager, 0x1C);

extern CAEUserRadioTrackManager& AEUserRadioTrackManager;
VALIDATE_SIZE(CAEUserRadioTrackManager, 0x1C);