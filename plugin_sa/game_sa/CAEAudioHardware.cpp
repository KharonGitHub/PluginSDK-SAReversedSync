/*
    Plugin-SDK (Grand Theft Auto San Andreas) source file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk

    Based on definitions from the GTA SA Reversed project.
    https://github.com/gta-reversed/gta-reversed
    Do not delete this comment block. Respect others' work!
*/
#include "CAEAudioHardware.h"

CAEAudioHardware& AEAudioHardware = *(CAEAudioHardware*)0xB5F8B8;

int CAEAudioHardware::GetActiveTrackID() {
    return plugin::CallMethodAndReturn<int, 0x4D8F80, CAEAudioHardware*>(this);
}

int CAEAudioHardware::GetTrackLengthMs() {
    return plugin::CallMethodAndReturn<int, 0x4D8F70, CAEAudioHardware*>(this);
}

int CAEAudioHardware::GetPlayingTrackID() {
    return plugin::CallMethodAndReturn<int, 0x4D8F90, CAEAudioHardware*>(this);
}

int CAEAudioHardware::GetTrackPlayTime() {
    return plugin::CallMethodAndReturn<int, 0x4D8F60, CAEAudioHardware*>(this);
}

void CAEAudioHardware::PlayTrack(uint trackID, int nextTrackID, uint startOffsetMs, uchar trackFlags, bool bUserTrack, bool bUserNextTrack){
    plugin::CallMethod<0x4D8F10, CAEAudioHardware*, uint, int, uint, uchar, bool, bool>(
        this, trackID, nextTrackID, startOffsetMs, trackFlags, bUserTrack, bUserNextTrack);
}

void CAEAudioHardware::StartTrackPlayback() {
    plugin::CallMethod<0x4D8F30, CAEAudioHardware*>(this);
}

void CAEAudioHardware::StopTrack() {
    plugin::CallMethod<0x4D8F50, CAEAudioHardware*>(this);
}

void CAEAudioHardware::SetBassSetting(eBassSetting bassSetting, float bassGain) {
    plugin::CallMethod<0x4D94A0, CAEAudioHardware*, eBassSetting, float>(this, bassSetting, bassGain);
}

void CAEAudioHardware::Service() {
    plugin::CallMethod<0x4D9870, CAEAudioHardware*>(this);
}

void CAEAudioHardware::SetChannelFlags(short channel, ushort channelId, short flags) {
    plugin::CallMethod<0x4D9500, CAEAudioHardware*, short, ushort, short>(this, channel, channelId, flags);
}

void CAEAudioHardware::SetChannelVolume(short channel, ushort channelId, float volume, uchar unused) {
    plugin::CallMethod<0x4D8870, CAEAudioHardware*, short, ushort, float, uchar>(this, channel, channelId, volume, unused);
}

ushort CAEAudioHardware::GetNumAvailableChannels() const {
    return plugin::CallMethodAndReturn<ushort, 0x4D8810, const CAEAudioHardware*>(this);
}

void CAEAudioHardware::SetChannelFrequencyScalingFactor(short channel, ushort channelId, float factor) {
    plugin::CallMethod<0x4D8960, CAEAudioHardware*, short, ushort, float>(this, channel, channelId, factor);
}

void CAEAudioHardware::SetMusicMasterScalingFactor(float factor) {
    plugin::CallMethod<0x4D9530, CAEAudioHardware*, float>(this, factor);
}

void CAEAudioHardware::SetEffectsMasterScalingFactor(float factor) {
    plugin::CallMethod<0x4D9540, CAEAudioHardware*, float>(this, factor);
}

float CAEAudioHardware::GetMusicMasterScalingFactor() const {
    return plugin::CallMethodAndReturn<float, 0x4D9580, const CAEAudioHardware*>(this);
}

float CAEAudioHardware::GetEffectsMasterScalingFactor() const {
    return plugin::CallMethodAndReturn<float, 0x4D9570, const CAEAudioHardware*>(this);
}

void CAEAudioHardware::SetMusicFaderScalingFactor(float factor) {
    plugin::CallMethod<0x4D9550, CAEAudioHardware*, float>(this, factor);
}

void CAEAudioHardware::SetEffectsFaderScalingFactor(float factor) {
    plugin::CallMethod<0x4D9560, CAEAudioHardware*, float>(this, factor);
}

void CAEAudioHardware::SetStreamFaderScalingFactor(float factor) {
    plugin::CallMethod<0x4D95B0, CAEAudioHardware*, float>(this, factor);
}

void CAEAudioHardware::SetNonStreamFaderScalingFactor(float factor) {
    plugin::CallMethod<0x4D95A0, CAEAudioHardware*, float>(this, factor);
}

void CAEAudioHardware::EnableEffectsLoading() {
    plugin::CallMethod<0x4D8E40, CAEAudioHardware*>(this);
}

void CAEAudioHardware::DisableEffectsLoading() {
    plugin::CallMethod<0x4D8E50, CAEAudioHardware*>(this);
}

void CAEAudioHardware::PlaySound(short channel, ushort channelSlot, ushort soundIdInSlot, ushort bankSlot, short playPosition, short flags, float speed) {
    plugin::CallMethod<0x4D86B0, CAEAudioHardware*, short, ushort, ushort, ushort, short, short, float>(
        this, channel, channelSlot, soundIdInSlot, bankSlot, playPosition, flags, speed);
}

void CAEAudioHardware::StopSound(short channel, ushort channelSlot) const {
    plugin::CallMethod<0x4D88E0, const CAEAudioHardware*, short, ushort>(this, channel, channelSlot);
}

void CAEAudioHardware::SetChannelPosition(short slotId, ushort channelSlot, const CVector& posn, uchar unused) const {
    plugin::CallMethod<0x4D8920, const CAEAudioHardware*, short, ushort, const CVector&, uchar>(this, slotId, channelSlot, posn, unused);
}

void CAEAudioHardware::UpdateReverbEnvironment() {
    plugin::CallMethod<0x4D8DA0, CAEAudioHardware*>(this);
}

void CAEAudioHardware::RescaleChannelVolumes() {
    plugin::CallMethod<0x4D8990, CAEAudioHardware*>(this);
}

void CAEAudioHardware::PauseAllSounds() {
    plugin::CallMethod<0x4D95F0, CAEAudioHardware*>(this);
}

void CAEAudioHardware::ResumeAllSounds() {
    plugin::CallMethod<0x4D9630, CAEAudioHardware*>(this);
}

void CAEAudioHardware::LoadSoundBank(eSoundBank bank, eSoundBankSlot slot) {
    plugin::CallMethod<0x4D88A0, CAEAudioHardware*, eSoundBank, eSoundBankSlot>(this, bank, slot);
}

bool CAEAudioHardware::IsSoundBankLoaded(eSoundBank bank, eSoundBankSlot slot) {
    return plugin::CallMethodAndReturn<bool, 0x4D88C0, CAEAudioHardware*, eSoundBank, eSoundBankSlot>(this, bank, slot);
}

char CAEAudioHardware::GetSoundBankLoadingStatus(eSoundBank bank, eSoundBankSlot slot) {
    return plugin::CallMethodAndReturn<char, 0x4D88D0, CAEAudioHardware*, eSoundBank, eSoundBankSlot>(this, bank, slot);
}

void CAEAudioHardware::LoadSound(eSoundBank bank, eSoundID sfx, eSoundBankSlot slot) {
    plugin::CallMethod<0x4D8ED0, CAEAudioHardware*, eSoundBank, eSoundID, eSoundBankSlot>(this, bank, sfx, slot);
}

bool CAEAudioHardware::IsSoundLoaded(eSoundBank bank, eSoundID sfx, eSoundBankSlot slot) {
    return plugin::CallMethodAndReturn<bool, 0x4D8EF0, CAEAudioHardware*, eSoundBank, eSoundID, eSoundBankSlot>(this, bank, sfx, slot);
}

bool CAEAudioHardware::GetSoundLoadingStatus(eSoundBank bank, eSoundID sfx, eSoundBankSlot slot) {
    return plugin::CallMethodAndReturn<bool, 0x4D8F00, CAEAudioHardware*, eSoundBank, eSoundID, eSoundBankSlot>(this, bank, sfx, slot);
}

void CAEAudioHardware::EnableBassEq() {
    plugin::CallMethod<0x4D94E0, CAEAudioHardware*>(this);
}

void CAEAudioHardware::DisableBassEq() {
    plugin::CallMethod<0x4D94D0, CAEAudioHardware*>(this);
}

float CAEAudioHardware::GetSoundHeadroom(eSoundID sfx, eSoundBankSlot slot) {
    return plugin::CallMethodAndReturn<float, 0x4D8E30, CAEAudioHardware*, eSoundID, eSoundBankSlot>(this, sfx, slot);
}

short CAEAudioHardware::AllocateChannels(ushort numChannels) {
    return plugin::CallMethodAndReturn<short, 0x5B9340, CAEAudioHardware*, ushort>(this, numChannels);
}

void CAEAudioHardware::GetChannelPlayTimes(short channel, short* playTimes) {
    plugin::CallMethod<0x4D8820, CAEAudioHardware*, short, short*>(this, channel, playTimes);
}

void CAEAudioHardware::RequestVirtualChannelSoundInfo(ushort vch, eSoundID sfx, eSoundBankSlot slot) {
    plugin::CallMethod<0x4D8E60, CAEAudioHardware*, ushort, eSoundID, eSoundBankSlot>(this, vch, sfx, slot);
}

void CAEAudioHardware::GetVirtualChannelSoundLengths(short* outArr) const {
    plugin::CallMethod<0x4D8E90, const CAEAudioHardware*, short*>(this, outArr);
}

void CAEAudioHardware::GetVirtualChannelSoundLoopStartTimes(short* outArr) const {
    plugin::CallMethod<0x4D8EB0, const CAEAudioHardware*, short*>(this, outArr);
}

void CAEAudioHardware::GetBeatInfo(tBeatInfo* beatInfo) {
    plugin::CallMethod<0x4D8FA0, CAEAudioHardware*, tBeatInfo*>(this, beatInfo);
}

bool CAEAudioHardware::IsStreamingFromDVD() {
    return plugin::CallMethodAndReturn<bool, 0x4D95C0, CAEAudioHardware*>(this);
}

char CAEAudioHardware::GetDVDDriveLetter() {
    return plugin::CallMethodAndReturn<char, 0x4D95D0, CAEAudioHardware*>(this);
}

bool CAEAudioHardware::CheckDVD() {
    return plugin::CallMethodAndReturn<bool, 0x4D95E0, CAEAudioHardware*>(this);
}