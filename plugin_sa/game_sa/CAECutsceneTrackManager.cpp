/*
    Plugin-SDK (Grand Theft Auto San Andreas) source file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!

    Based on definitions from the GTA SA Reversed project.
    https://github.com/gta-reversed/gta-reversed
    Do not delete this comment block. Respect others' work!
*/

#include "CAECutsceneTrackManager.h"

CAECutsceneTrackManager& AECutsceneTrackManager = *(CAECutsceneTrackManager*)0x8AE554;

bool CAECutsceneTrackManager::Initialise(int nAudioChannel) {
    return plugin::CallMethodAndReturn<bool, 0x5B9630, CAECutsceneTrackManager*, int>(this, nAudioChannel);
}

void CAECutsceneTrackManager::PlayPreloadedCutsceneTrack() {
    plugin::CallMethod<0x4DBE70, CAECutsceneTrackManager*>(this);
}

void CAECutsceneTrackManager::StopCutsceneTrack() {
    plugin::CallMethod<0x4DBE80, CAECutsceneTrackManager*>(this);
}

bool CAECutsceneTrackManager::IsCutsceneTrackActive() const {
    return plugin::CallMethodAndReturn<bool, 0x4DBEB0, const CAECutsceneTrackManager*>(this);
}

int8_t CAECutsceneTrackManager::GetCutsceneTrackStatus() const {
    return plugin::CallMethodAndReturn<int8_t, 0x4DBEC0, const CAECutsceneTrackManager*>(this);
}

void CAECutsceneTrackManager::PauseTrack(bool pause) {
    plugin::CallMethod<0x4DBF00, CAECutsceneTrackManager*, bool>(this, pause);
}

void CAECutsceneTrackManager::StartTrackPlayback() const {
    plugin::CallMethod<0x4DBF10, const CAECutsceneTrackManager*>(this);
}

void CAECutsceneTrackManager::CheckForPause() const {
    plugin::CallMethod<0x4DBF60, const CAECutsceneTrackManager*>(this);
}

void CAECutsceneTrackManager::Service(int trackPlayTime) {
    plugin::CallMethod<0x4DBFB0, CAECutsceneTrackManager*, int>(this, trackPlayTime);
}

void CAECutsceneTrackManager::PreloadCutsceneTrack(short trackId, bool wait) {
    plugin::CallMethod<0x4DC0E0, CAECutsceneTrackManager*, short, bool>(this, trackId, wait);
}

void CAECutsceneTrackManager::PreloadBeatTrack(short trackId, bool wait) {
    plugin::CallMethod<0x4DC130, CAECutsceneTrackManager*, short, bool>(this, trackId, wait);
}