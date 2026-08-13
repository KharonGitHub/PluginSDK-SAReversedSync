/*
    Plugin-SDK (Grand Theft Auto San Andreas) source file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk

    Based on definitions from the GTA SA Reversed project.
    https://github.com/gta-reversed/gta-reversed
    Do not delete this comment block. Respect others' work!
*/
#include "CAEStreamingDecoder.h"

CAEStreamingDecoder::CAEStreamingDecoder(CAEDataStream* dataStream) {
    plugin::CallMethod<0x4F2810, CAEStreamingDecoder*, CAEDataStream*>(this, dataStream);
}

CAEStreamingDecoder::~CAEStreamingDecoder() {
    plugin::CallMethod<0x4F2830, CAEStreamingDecoder*>(this);
}