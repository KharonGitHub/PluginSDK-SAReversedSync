/*
    Plugin-SDK (Grand Theft Auto San Andreas) source file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/
#include "CAERadioTrackManager.h"

CAERadioTrackManager &AERadioTrackManager = *(CAERadioTrackManager*)0x8CB6F8;

bool CAERadioTrackManager::IsVehicleRadioActive()
{
    return ((bool (__thiscall *)(CAERadioTrackManager *))0x4E9800)(this);
}

char *CAERadioTrackManager::GetRadioStationName(signed char id)
{
    return ((char *(__thiscall *)(CAERadioTrackManager *, signed char))0x4E9E10)(this, id);
}

void CAERadioTrackManager::StartRadio(eRadioID id, eBassSetting bassSetting, float bassGain, bool skipTrack) {
    plugin::CallMethod<0x4EB3C0, CAERadioTrackManager*, eRadioID, eBassSetting, float, bool>(this, id, bassSetting, bassGain, skipTrack);
}

void CAERadioTrackManager::StartRadio(const tVehicleAudioSettings& settings) {
    plugin::CallMethod<0x4EB550, CAERadioTrackManager*, const tVehicleAudioSettings&>(this, settings);
}

void CAERadioTrackManager::StopRadio(tVehicleAudioSettings* settings, char arg) {
    plugin::CallMethod<0x4E9820, CAERadioTrackManager*, tVehicleAudioSettings*, char>(this, settings, arg);
}

// 0x5D40E0
void CAERadioTrackManager::Load() {
    plugin::Call<0x5D40E0>();
}

// 0x5D3EE0
void CAERadioTrackManager::Save() {
    plugin::Call<0x5D3EE0>();
}

bool CAERadioTrackManager::Initialise(int channelId) {
    return plugin::CallMethodAndReturn<bool, 0x5B9390, CAERadioTrackManager*, int>(this, channelId);
}

void CAERadioTrackManager::InitialiseRadioStationID(eRadioID id) {
    plugin::CallMethod<0x4E8330, CAERadioTrackManager*, eRadioID>(this, id);
}

void CAERadioTrackManager::Reset() {
    plugin::CallMethod<0x4E7F80, CAERadioTrackManager*>(this);
}

void CAERadioTrackManager::ResetStatistics() {
    plugin::Call<0x4E8200>();
}

bool CAERadioTrackManager::IsRadioOn() const {
    return plugin::CallMethodAndReturn<bool, 0x4E8350, const CAERadioTrackManager*>(this);
}

bool CAERadioTrackManager::HasRadioRetuneJustStarted() const {
    return plugin::CallMethodAndReturn<bool, 0x4E8370, const CAERadioTrackManager*>(this);
}

eRadioID CAERadioTrackManager::GetCurrentRadioStationID() const {
    return plugin::CallMethodAndReturn<eRadioID, 0x4E83F0, const CAERadioTrackManager*>(this);
}

int* CAERadioTrackManager::GetRadioStationListenTimes() {
    return plugin::CallMethodAndReturn<int*, 0x4E83E0, CAERadioTrackManager*>(this);
}

void CAERadioTrackManager::SetRadioAutoRetuneOnOff(bool enable) {
    plugin::CallMethod<0x4E82E0, CAERadioTrackManager*, bool>(this, enable);
}

void CAERadioTrackManager::SetBassEnhanceOnOff(bool enable) {
    plugin::CallMethod<0x4E9DB0, CAERadioTrackManager*, bool>(this, enable);
}

void CAERadioTrackManager::SetBassSetting(eBassSetting bassSetting, float bassGrain) {
    plugin::CallMethod<0x4E82F0, CAERadioTrackManager*, eBassSetting, float>(this, bassSetting, bassGrain);
}

void CAERadioTrackManager::RetuneRadio(eRadioID id) {
    plugin::CallMethod<0x4E8290, CAERadioTrackManager*, eRadioID>(this, id);
}

void CAERadioTrackManager::DisplayRadioStationName() {
    plugin::CallMethod<0x4E9E50, CAERadioTrackManager*>(this);
}

void CAERadioTrackManager::GetRadioStationNameKey(eRadioID id, char* outStr) {
    plugin::CallMethod<0x4E8380, CAERadioTrackManager*, eRadioID, char*>(this, id, outStr);
}

void CAERadioTrackManager::StartTrackPlayback() {
    plugin::CallMethod<0x4EA640, CAERadioTrackManager*>(this);
}

void CAERadioTrackManager::UpdateRadioVolumes() {
    plugin::CallMethod<0x4EA010, CAERadioTrackManager*>(this);
}

void CAERadioTrackManager::PlayRadioAnnouncement(unsigned int a1) {
    plugin::CallMethod<0x4E8400, CAERadioTrackManager*, unsigned int>(this, a1);
}

void CAERadioTrackManager::Service(int playTime) {
    plugin::CallMethod<0x4EB9A0, CAERadioTrackManager*, int>(this, playTime);
}

void CAERadioTrackManager::CheckForStationRetuneDuringPause() {
    plugin::CallMethod<0x4EB890, CAERadioTrackManager*>(this);
}

void CAERadioTrackManager::CheckForPause() {
    plugin::CallMethod<0x4EA590, CAERadioTrackManager*>(this);
}

char CAERadioTrackManager::ChooseTalkRadioShow() {
    return plugin::CallAndReturn<char, 0x4E8E40>();
}

void CAERadioTrackManager::CheckForMissionStatsChanges() {
    plugin::Call<0x4E8410>();
}

void CAERadioTrackManager::CheckForStationRetune() {
    plugin::CallMethod<0x4EB660, CAERadioTrackManager*>(this);
}

void CAERadioTrackManager::AddMusicTrackIndexToHistory(eRadioID id, char trackIndex) {
    plugin::CallMethod<0x4E96C0, CAERadioTrackManager*, eRadioID, char>(this, id, trackIndex);
}

void CAERadioTrackManager::AddIdentIndexToHistory(eRadioID id, char trackIndex) {
    plugin::CallMethod<0x4E9720, CAERadioTrackManager*, eRadioID, char>(this, id, trackIndex);
}

void CAERadioTrackManager::AddAdvertIndexToHistory(eRadioID id, char trackIndex) {
    plugin::CallMethod<0x4E9760, CAERadioTrackManager*, eRadioID, char>(this, id, trackIndex);
}

void CAERadioTrackManager::AddDJBanterIndexToHistory(eRadioID id, char trackIndex) {
    plugin::CallMethod<0x4E97B0, CAERadioTrackManager*, eRadioID, char>(this, id, trackIndex);
}

void CAERadioTrackManager::ChooseTracksForStation(eRadioID id) {
    plugin::CallMethod<0x4EB180, CAERadioTrackManager*, eRadioID>(this, id);
}

int CAERadioTrackManager::ChooseIdentIndex(eRadioID id) {
    return plugin::CallMethodAndReturn<int, 0x4E94C0, CAERadioTrackManager*, eRadioID>(this, id);
}

int CAERadioTrackManager::ChooseAdvertIndex(eRadioID id) {
    return plugin::CallMethodAndReturn<int, 0x4E9570, CAERadioTrackManager*, eRadioID>(this, id);
}

int CAERadioTrackManager::ChooseDJBanterIndex(eRadioID id) {
    return plugin::CallMethodAndReturn<int, 0x4EA2D0, CAERadioTrackManager*, eRadioID>(this, id);
}

int CAERadioTrackManager::ChooseDJBanterIndexFromList(eRadioID id, int** list) {
    return plugin::CallMethodAndReturn<int, 0x4E95E0, CAERadioTrackManager*, eRadioID, int**>(this, id, list);
}

char CAERadioTrackManager::ChooseMusicTrackIndex(eRadioID id) {
    return plugin::CallMethodAndReturn<char, 0x4EA270, CAERadioTrackManager*, eRadioID>(this, id);
}

void CAERadioTrackManager::CheckForTrackConcatenation() {
    plugin::CallMethod<0x4EA930, CAERadioTrackManager*>(this);
}

bool CAERadioTrackManager::QueueUpTracksForStation(eRadioID id, char* iTrackCount, char radioState, tRadioSettings& settings) {
    return plugin::CallMethodAndReturn<bool, 0x4EA670, CAERadioTrackManager*, eRadioID, char*, char, tRadioSettings&>(this, id, iTrackCount, radioState, settings);
}

bool CAERadioTrackManager::TrackRadioStation(eRadioID id, bool skipTrack) {
    return plugin::CallMethodAndReturn<bool, 0x4EAC30, CAERadioTrackManager*, eRadioID, bool>(this, id, skipTrack);
}

tMusicTrackHistory* CAERadioTrackManager::m_nMusicTrackIndexHistory = (tMusicTrackHistory*)0xB62B40;