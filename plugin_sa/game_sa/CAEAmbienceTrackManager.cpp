/*
    Plugin-SDK (Grand Theft Auto San Andreas) header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk

    Based on definitions from the GTA SA Reversed project.
    https://github.com/gta-reversed/gta-reversed
    Do not delete this comment block. Respect others' work!
*/

#include "CAEAmbienceTrackManager.h"

CAEAmbienceTrackManager& AEAmbienceTrackManager = *(CAEAmbienceTrackManager*)0x8CBA70;

bool CAEAmbienceTrackManager::Initialise(int channelId) {
    return plugin::CallMethodAndReturn<bool, 0x5B9660, CAEAmbienceTrackManager*, int>(this, channelId);
}

void CAEAmbienceTrackManager::Reset() {
    plugin::CallMethod<0x4D6CA0, CAEAmbienceTrackManager*>(this);
}

void CAEAmbienceTrackManager::StopAmbienceTrack() {
    plugin::CallMethod<0x4D6CC0, CAEAmbienceTrackManager*>(this);
}

bool CAEAmbienceTrackManager::IsAmbienceTrackActive() const {
    return plugin::CallMethodAndReturn<bool, 0x4D6CF0, const CAEAmbienceTrackManager*>(this);
}

bool CAEAmbienceTrackManager::IsAmbienceRadioActive() const {
    return plugin::CallMethodAndReturn<bool, 0x4D6D40, const CAEAmbienceTrackManager*>(this);
}

void CAEAmbienceTrackManager::PlaySpecialMissionAmbienceTrack(eAudioEvents event) {
    plugin::CallMethod<0x4D6D50, CAEAmbienceTrackManager*, eAudioEvents>(this, event);
}

void CAEAmbienceTrackManager::StopSpecialMissionAmbienceTrack() {
    plugin::CallMethod<0x4D6D60, CAEAmbienceTrackManager*>(this);
}

void CAEAmbienceTrackManager::StartTrackPlayback() const {
    plugin::CallMethod<0x4D6DA0, const CAEAmbienceTrackManager*>(this);
}

void CAEAmbienceTrackManager::CheckForPause() const {
    plugin::CallMethod<0x4D6DF0, const CAEAmbienceTrackManager*>(this);
}

void CAEAmbienceTrackManager::UpdateAmbienceTrackAndVolume() {
    plugin::CallMethod<0x4D6E60, CAEAmbienceTrackManager*>(this);
}

void CAEAmbienceTrackManager::Service(int playTime) {
    plugin::CallMethod<0x4D76C0, CAEAmbienceTrackManager*, int>(this, playTime);
}