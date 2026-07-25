/*
    Plugin-SDK (Grand Theft Auto San Andreas) header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/
#pragma once

#include "PluginBase.h"
#include "CAEVehicleAudioEntity.h"
#include "eBassSetting.h"

struct PLUGIN_API tRadioSettings {
    int m_djIndex[4];
    int field_10;
    int trackId;
    int field_18;
    int trackPlayTime;
    int trackLength;
    char field_24;
    char m_nCurrentRadioStation;
    char m_nBassSet;
    char _pad;
    float m_fBassGain;
    char currRadioBC_[4];
    char field_30;
    char field_31;
    char m_musicTrackIndices[10];
};
VALIDATE_OFFSET(tRadioSettings, m_djIndex, 0x0);
VALIDATE_OFFSET(tRadioSettings, field_10, 0x10);
VALIDATE_OFFSET(tRadioSettings, trackId, 0x14);
VALIDATE_OFFSET(tRadioSettings, field_18, 0x18);
VALIDATE_OFFSET(tRadioSettings, trackPlayTime, 0x1C);
VALIDATE_OFFSET(tRadioSettings, trackLength, 0x20);
VALIDATE_OFFSET(tRadioSettings, field_24, 0x24);
VALIDATE_OFFSET(tRadioSettings, m_nCurrentRadioStation, 0x25);
VALIDATE_OFFSET(tRadioSettings, m_nBassSet, 0x26);
VALIDATE_OFFSET(tRadioSettings, _pad, 0x27);
VALIDATE_OFFSET(tRadioSettings, m_fBassGain, 0x28);
VALIDATE_OFFSET(tRadioSettings, currRadioBC_, 0x2C);
VALIDATE_OFFSET(tRadioSettings, field_30, 0x30);
VALIDATE_OFFSET(tRadioSettings, field_31, 0x31);
VALIDATE_OFFSET(tRadioSettings, m_musicTrackIndices, 0x32);
VALIDATE_SIZE(tRadioSettings, 0x3C);

struct PLUGIN_API tRadioStationData {
    int field_0;
    int field_4;
    int field_8;
    int m_nTimeRetuneStopped;
    int lastPlayingTime;
    int trackPlayTime;
    int field_18;
    int field_1C;
    int field_20;
    char field_24;
    char field_25;
    char field_26;
    char lastGameClockDays;
    int lastGameClockHours;
};
VALIDATE_OFFSET(tRadioStationData, field_0, 0x0);
VALIDATE_OFFSET(tRadioStationData, field_4, 0x4);
VALIDATE_OFFSET(tRadioStationData, field_8, 0x8);
VALIDATE_OFFSET(tRadioStationData, m_nTimeRetuneStopped, 0xC);
VALIDATE_OFFSET(tRadioStationData, lastPlayingTime, 0x10);
VALIDATE_OFFSET(tRadioStationData, trackPlayTime, 0x14);
VALIDATE_OFFSET(tRadioStationData, field_18, 0x18);
VALIDATE_OFFSET(tRadioStationData, field_1C, 0x1C);
VALIDATE_OFFSET(tRadioStationData, field_20, 0x20);
VALIDATE_OFFSET(tRadioStationData, field_24, 0x24);
VALIDATE_OFFSET(tRadioStationData, field_25, 0x25);
VALIDATE_OFFSET(tRadioStationData, field_26, 0x26);
VALIDATE_OFFSET(tRadioStationData, lastGameClockDays, 0x27);
VALIDATE_OFFSET(tRadioStationData, lastGameClockHours, 0x28);
VALIDATE_SIZE(tRadioStationData, 0x2C);

struct PLUGIN_API tMusicTrackHistory {
    char m_indices[20];
};
VALIDATE_OFFSET(tMusicTrackHistory, m_indices, 0x0);
VALIDATE_SIZE(tMusicTrackHistory, 0x14);

class PLUGIN_API CAERadioTrackManager {
public:
    bool m_bInitialised;                 // was field_0
    bool m_bDisplayStationName;          // was field_1
    char m_prev;                         // was field_2
    bool m_bEnabledInPauseMode;          // was field_3
    bool m_bBassEnhance;                 // was field_4
    bool m_bPauseMode;                   // was field_5
    bool m_bRetuneJustStarted;           
    bool m_bRadioAutoSelect;             
    char m_nTracksInARow[14];            // was field_8[14]
    unsigned char m_nSavedGameClockDays; // was m_nMonthDay
    unsigned char m_nSavedGameClockHours;// was m_nClockHours
    int m_aListenTimes[14];              // was m_anPlayerStats[14]
    unsigned int m_nTimeRadioStationRetuned;
    unsigned int m_nTimeToDisplayRadioName;
    unsigned int m_nSavedTimeMs;         // was field_58
    unsigned int m_nRetuneStartedTime;   // was field_5C
    int field_60;                        
    int m_HwClientHandle;                // was field_64
    int m_nMode;                         // was field_68
    int m_nStationsListed;               
    int m_nStationsListDown;             
    int m_nSavedRadioStationId;          // was field_74
    int m_iRadioStationMenuRequest;      // was field_78
    int m_iRadioStationScriptRequest;    // was field_7C
    unsigned long m_f80;                 // was field_80
    unsigned long m_f84;                 // was field_84
    tRadioSettings m_RequestedSettings;  // was m_TempSettings
    tRadioSettings m_ActiveSettings;
    tRadioStationData m_RadioStationsData[13];
    unsigned char gap33C[12];
    char field_348[32];
    unsigned long field_368;
    unsigned char m_nUserTrackPlayMode;  // was field_36C
    char field_36D[3];

    bool IsVehicleRadioActive();
    char* GetRadioStationName(signed char id);
    void StartRadio(eRadioID id, eBassSetting bassSetting, float bassGain, bool skipTrack);
    void StartRadio(const tVehicleAudioSettings& settings);
    void StopRadio(tVehicleAudioSettings* settings, char arg);

    static void Load();
    static void Save();

    bool Initialise(int channelId);
    void InitialiseRadioStationID(eRadioID id);
    void Reset();
    static void ResetStatistics();
    bool IsRadioOn() const;
    bool HasRadioRetuneJustStarted() const;
    eRadioID GetCurrentRadioStationID() const;
    int* GetRadioStationListenTimes();
    void SetRadioAutoRetuneOnOff(bool enable);
    void SetBassEnhanceOnOff(bool enable);
    void SetBassSetting(eBassSetting bassSetting, float bassGrain);
    void RetuneRadio(eRadioID id);
    void DisplayRadioStationName();
    void GetRadioStationNameKey(eRadioID id, char* outStr);
    void StartTrackPlayback();
    void UpdateRadioVolumes();
    void PlayRadioAnnouncement(unsigned int);
    void Service(int playTime);
    void CheckForStationRetuneDuringPause();
    void CheckForPause();
    static char ChooseTalkRadioShow();
    static void CheckForMissionStatsChanges();

    // 11 structures
    static tMusicTrackHistory *m_nMusicTrackIndexHistory;

protected:
    void CheckForStationRetune();
    void AddMusicTrackIndexToHistory(eRadioID id, char trackIndex);
    void AddIdentIndexToHistory(eRadioID id, char trackIndex);
    void AddAdvertIndexToHistory(eRadioID id, char trackIndex);
    void AddDJBanterIndexToHistory(eRadioID id, char trackIndex);
    void ChooseTracksForStation(eRadioID id);
    int ChooseIdentIndex(eRadioID id);
    int ChooseAdvertIndex(eRadioID id);
    int ChooseDJBanterIndex(eRadioID id);
    int ChooseDJBanterIndexFromList(eRadioID id, int** list);
    char ChooseMusicTrackIndex(eRadioID id);
    void CheckForTrackConcatenation();
    bool QueueUpTracksForStation(eRadioID id, char* iTrackCount, char radioState, tRadioSettings& settings);
    bool TrackRadioStation(eRadioID id, bool skipTrack);
};

VALIDATE_OFFSET(CAERadioTrackManager, m_bInitialised, 0x0);
VALIDATE_OFFSET(CAERadioTrackManager, m_bDisplayStationName, 0x1);
VALIDATE_OFFSET(CAERadioTrackManager, m_prev, 0x2);
VALIDATE_OFFSET(CAERadioTrackManager, m_bEnabledInPauseMode, 0x3);
VALIDATE_OFFSET(CAERadioTrackManager, m_bBassEnhance, 0x4);
VALIDATE_OFFSET(CAERadioTrackManager, m_bPauseMode, 0x5);
VALIDATE_OFFSET(CAERadioTrackManager, m_bRetuneJustStarted, 0x6);
VALIDATE_OFFSET(CAERadioTrackManager, m_bRadioAutoSelect, 0x7);
VALIDATE_OFFSET(CAERadioTrackManager, m_nTracksInARow, 0x8);
VALIDATE_OFFSET(CAERadioTrackManager, m_nSavedGameClockDays, 0x16);
VALIDATE_OFFSET(CAERadioTrackManager, m_nSavedGameClockHours, 0x17);
VALIDATE_OFFSET(CAERadioTrackManager, m_aListenTimes, 0x18);
VALIDATE_OFFSET(CAERadioTrackManager, m_nTimeRadioStationRetuned, 0x50);
VALIDATE_OFFSET(CAERadioTrackManager, m_nTimeToDisplayRadioName, 0x54);
VALIDATE_OFFSET(CAERadioTrackManager, m_nSavedTimeMs, 0x58);
VALIDATE_OFFSET(CAERadioTrackManager, m_nRetuneStartedTime, 0x5C);
VALIDATE_OFFSET(CAERadioTrackManager, field_60, 0x60);
VALIDATE_OFFSET(CAERadioTrackManager, m_HwClientHandle, 0x64);
VALIDATE_OFFSET(CAERadioTrackManager, m_nMode, 0x68);
VALIDATE_OFFSET(CAERadioTrackManager, m_nStationsListed, 0x6C);
VALIDATE_OFFSET(CAERadioTrackManager, m_nStationsListDown, 0x70);
VALIDATE_OFFSET(CAERadioTrackManager, m_nSavedRadioStationId, 0x74);
VALIDATE_OFFSET(CAERadioTrackManager, m_iRadioStationMenuRequest, 0x78);
VALIDATE_OFFSET(CAERadioTrackManager, m_iRadioStationScriptRequest, 0x7C);
VALIDATE_OFFSET(CAERadioTrackManager, m_f80, 0x80);
VALIDATE_OFFSET(CAERadioTrackManager, m_f84, 0x84);
VALIDATE_OFFSET(CAERadioTrackManager, m_RequestedSettings, 0x88);
VALIDATE_OFFSET(CAERadioTrackManager, m_ActiveSettings, 0xC4);
VALIDATE_OFFSET(CAERadioTrackManager, m_RadioStationsData, 0x100);
VALIDATE_OFFSET(CAERadioTrackManager, gap33C, 0x33C);
VALIDATE_OFFSET(CAERadioTrackManager, field_348, 0x348);
VALIDATE_OFFSET(CAERadioTrackManager, field_368, 0x368);
VALIDATE_OFFSET(CAERadioTrackManager, m_nUserTrackPlayMode, 0x36C);
VALIDATE_OFFSET(CAERadioTrackManager, field_36D, 0x36D);
VALIDATE_SIZE(CAERadioTrackManager, 0x370);

extern CAERadioTrackManager &AERadioTrackManager;
VALIDATE_SIZE(CAERadioTrackManager, 0x370);