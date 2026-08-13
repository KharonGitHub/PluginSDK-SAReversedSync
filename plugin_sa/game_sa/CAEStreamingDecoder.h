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
#include "CAEDataStream.h"

class PLUGIN_API CAEStreamingDecoder {
public:
    CAEDataStream* m_pDataStream; // 0x4

public:
    CAEStreamingDecoder(CAEDataStream* dataStream);
    virtual ~CAEStreamingDecoder();

    virtual bool     Initialise() = 0;
    virtual size_t   FillBuffer(void* dest, size_t size) = 0;
    virtual long     GetStreamLengthMs() = 0;
    virtual long     GetStreamPlayTimeMs() = 0;
    virtual void     SetCursor(unsigned long pos) = 0;
    virtual int32_t  GetSampleRate() = 0;
    virtual int32_t  GetStreamID() = 0;
};

VALIDATE_OFFSET(CAEStreamingDecoder, m_pDataStream, 0x4);
VALIDATE_SIZE(CAEStreamingDecoder, 0x8);