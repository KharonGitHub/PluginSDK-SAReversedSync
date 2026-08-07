/*
    Plugin-SDK (Grand Theft Auto San Andreas) header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!

    Based on definitions from the GTA SA Reversed project.
    https://github.com/gta-reversed/gta-reversed
    Do not delete this comment block. Respect others' work!
*/
#pragma once

#include "PluginBase.h"
#include "enums/eRadioID.h"
#include "enums/eAudioEvents.h"

class CVehicle;

class PLUGIN_API CAEAudioUtility {
public:
    static void         StaticInitialise();

    static int          GetRandomNumberInRange(int min, int max);
    static float        GetRandomNumberInRange(float min, float max);

    static CVehicle* FindVehicleOfPlayer();
    static bool         ResolveProbability(float prob);
    static float        AudioLog10(float p);

    static unsigned int ConvertFromBytesToMS(unsigned int lengthInBytes, unsigned int sampleRate, unsigned short numChannels);
    static unsigned int ConvertFromMSToBytes(unsigned int lengthInMS, unsigned int sampleRate, unsigned short numChannels);

    static bool         GetBankAndSoundFromScriptSlotAudioEvent(eAudioEvents scriptID, int& outBankID, int& outSoundID, int slot);
    static float        GetPiecewiseLinear(float x, short dataCount, const float (*data)[2]);
    static uint64_t     GetCurrentTimeInMS();

    static eRadioID     GetRandomRadioStation();
};