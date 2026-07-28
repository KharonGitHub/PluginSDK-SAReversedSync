/*
    Plugin-SDK (Grand Theft Auto San Andreas) source file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk

    Based on definitions from the GTA SA Reversed project.
    https://github.com/gta-reversed/gta-reversed
    Do not delete this comment block. Respect others' work!
*/

#include "CAEUserRadioTrackManager.h"

CAEUserRadioTrackManager& AEUserRadioTrackManager = *(CAEUserRadioTrackManager*)0x8CBA80;

bool CAEUserRadioTrackManager::Initialise() {
    return ((bool(__thiscall*)(CAEUserRadioTrackManager*))0x4F35B0)(this);
}

void CAEUserRadioTrackManager::Shutdown() {
    ((void(__thiscall*)(CAEUserRadioTrackManager*))0x4F2FB0)(this);
}

char* CAEUserRadioTrackManager::GetTrackPath(int trackID) const {
    return ((char* (__thiscall*)(const CAEUserRadioTrackManager*, int))0x4F3050)(this, trackID);
}

CAEStreamingDecoder* CAEUserRadioTrackManager::LoadUserTrack(int trackID) {
    return ((CAEStreamingDecoder * (__thiscall*)(CAEUserRadioTrackManager*, int))0x4F35F0)(this, trackID);
}

bool CAEUserRadioTrackManager::ReadUserTracks() {
    return ((bool(__thiscall*)(CAEUserRadioTrackManager*))0x4F2FD0)(this);
}

bool CAEUserRadioTrackManager::ScanUserTracks() {
    return ((bool(__thiscall*)(CAEUserRadioTrackManager*))0x4F4BA0)(this);
}

void CAEUserRadioTrackManager::DeleteUserTracksInfo() {
    ((void(__thiscall*)(CAEUserRadioTrackManager*))0x4F32F0)(this);
}

void CAEUserRadioTrackManager::SetUserTrackIndex(int index) {
    ((void(__thiscall*)(CAEUserRadioTrackManager*, int))0x4F3340)(this, index);
}

int CAEUserRadioTrackManager::SelectUserTrackIndex() const {
    return ((int(__thiscall*)(const CAEUserRadioTrackManager*))0x4F3250)(this);
}

eAudioFileType CAEUserRadioTrackManager::GetAudioFileType(const char* filename) {
    return ((eAudioFileType(__thiscall*)(CAEUserRadioTrackManager*, const char*))0x4F31F0)(this, filename);
}

bool CAEUserRadioTrackManager::IsShortcut(const char* path) {
    return ((bool(__thiscall*)(CAEUserRadioTrackManager*, const char*))0x4F32C0)(this, path);
}

unsigned char CAEUserRadioTrackManager::GetUserTrackPlayMode() {
    return ((unsigned char(__thiscall*)(CAEUserRadioTrackManager*))0x4F3330)(this);
}