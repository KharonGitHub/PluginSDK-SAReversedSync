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
#include <objidl.h> // Required for IStream COM interface

class PLUGIN_API CAEDataStream : public IStream {
public:
    HANDLE       m_pFileHandle;
    char* m_pszFilename;
    bool         m_bIsOpen;
    unsigned int m_nCurrentPosition;
    unsigned int m_nStartPosition;
    unsigned int m_nLength;
    unsigned int m_nTrackId;
    bool         m_bIsEncrypted;
    unsigned int m_lRefCount;

public:
    CAEDataStream(int trackId, char* filename, unsigned int startPosition, unsigned int length, bool encrypted);
    ~CAEDataStream();

    // IStream COM Interface Methods
    HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void** objout) override;
    ULONG STDMETHODCALLTYPE   AddRef() override;
    ULONG STDMETHODCALLTYPE   Release() override;
    HRESULT STDMETHODCALLTYPE Read(void* dest, ULONG size, ULONG* readed) override;
    HRESULT STDMETHODCALLTYPE Write(const void* src, ULONG size, ULONG* written) override;
    HRESULT STDMETHODCALLTYPE Seek(LARGE_INTEGER offset, DWORD whence, ULARGE_INTEGER* newOffset) override;
    HRESULT STDMETHODCALLTYPE SetSize(ULARGE_INTEGER newSize) override;
    HRESULT STDMETHODCALLTYPE CopyTo(IStream* target, ULARGE_INTEGER size, ULARGE_INTEGER* readed, ULARGE_INTEGER* written) override;
    HRESULT STDMETHODCALLTYPE Commit(DWORD flags) override;
    HRESULT STDMETHODCALLTYPE Revert() override;
    HRESULT STDMETHODCALLTYPE LockRegion(ULARGE_INTEGER offset, ULARGE_INTEGER size, DWORD type) override;
    HRESULT STDMETHODCALLTYPE UnlockRegion(ULARGE_INTEGER libOffset, ULARGE_INTEGER cb, DWORD dwLockType) override;
    HRESULT STDMETHODCALLTYPE Stat(STATSTG* statout, DWORD flags) override;
    HRESULT STDMETHODCALLTYPE Clone(IStream** target) override;

    // CAEDataStream Native Methods
    bool         Initialise();
    unsigned int FillBuffer(void* dest, unsigned int size);
    unsigned int GetCurrentPosition();
    unsigned int Seek(long offset, int whence);
    bool         Close();
};

VALIDATE_OFFSET(CAEDataStream, m_pFileHandle, 0x04);
VALIDATE_OFFSET(CAEDataStream, m_pszFilename, 0x08);
VALIDATE_OFFSET(CAEDataStream, m_bIsOpen, 0x0C);
VALIDATE_OFFSET(CAEDataStream, m_nCurrentPosition, 0x10);
VALIDATE_OFFSET(CAEDataStream, m_nStartPosition, 0x14);
VALIDATE_OFFSET(CAEDataStream, m_nLength, 0x18);
VALIDATE_OFFSET(CAEDataStream, m_nTrackId, 0x1C);
VALIDATE_OFFSET(CAEDataStream, m_bIsEncrypted, 0x20);
VALIDATE_OFFSET(CAEDataStream, m_lRefCount, 0x24);
VALIDATE_SIZE(CAEDataStream, 0x28);