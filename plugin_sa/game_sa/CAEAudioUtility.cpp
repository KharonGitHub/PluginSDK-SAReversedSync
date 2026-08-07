/*
    Plugin-SDK (Grand Theft Auto San Andreas) source file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!

    Based on definitions from the GTA SA Reversed project.
    https://github.com/gta-reversed/gta-reversed
    Do not delete this comment block. Respect others' work!
*/

#include "CAEAudioUtility.h"

void CAEAudioUtility::StaticInitialise() {
    plugin::Call<0x5B97F0>();
}

int CAEAudioUtility::GetRandomNumberInRange(int min, int max) {
    return plugin::CallAndReturn<int, 0x4D9C10, int, int>(min, max);
}

float CAEAudioUtility::GetRandomNumberInRange(float min, float max) {
    return plugin::CallAndReturn<float, 0x4D9C50, float, float>(min, max);
}

bool CAEAudioUtility::ResolveProbability(float prob) {
    return plugin::CallAndReturn<bool, 0x4D9C80, float>(prob);
}

float CAEAudioUtility::GetPiecewiseLinear(float x, short dataCount, const float (*data)[2]) {
    return plugin::CallAndReturn<float, 0x4D9D90, float, short, const float(*)[2]>(x, dataCount, data);
}

CVehicle* CAEAudioUtility::FindVehicleOfPlayer() {
    return plugin::CallAndReturn<CVehicle*, 0x4D9E10>();
}

float CAEAudioUtility::AudioLog10(float p) {
    return plugin::CallAndReturn<float, 0x4D9E50, float>(p);
}

uint64_t CAEAudioUtility::GetCurrentTimeInMS() {
    return plugin::CallAndReturn<uint64_t, 0x4D9E80>();
}

unsigned int CAEAudioUtility::ConvertFromBytesToMS(unsigned int lengthInBytes, unsigned int sampleRate, unsigned short numChannels) {
    return plugin::CallAndReturn<unsigned int, 0x4D9EF0, unsigned int, unsigned int, unsigned short>(lengthInBytes, sampleRate, numChannels);
}

unsigned int CAEAudioUtility::ConvertFromMSToBytes(unsigned int lengthInMS, unsigned int sampleRate, unsigned short numChannels) {
    return plugin::CallAndReturn<unsigned int, 0x4D9F40, unsigned int, unsigned int, unsigned short>(lengthInMS, sampleRate, numChannels);
}

bool CAEAudioUtility::GetBankAndSoundFromScriptSlotAudioEvent(eAudioEvents scriptID, int& outBankID, int& outSoundID, int slot) {
    return plugin::CallAndReturn<bool, 0x4D9CC0, eAudioEvents, int&, int&, int>(scriptID, outBankID, outSoundID, slot);
}

eRadioID CAEAudioUtility::GetRandomRadioStation() {
    return static_cast<eRadioID>(GetRandomNumberInRange(1, 12));
}