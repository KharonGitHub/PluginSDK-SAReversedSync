/*
    Plugin-SDK (Grand Theft Auto San Andreas) source file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk

    Based on definitions from the GTA SA Reversed project.
    https://github.com/gta-reversed/gta-reversed
    Do not delete this comment block. Respect others' work!
*/

#include "CAEDataStream.h"

CAEDataStream::CAEDataStream(int trackId, char* filename, unsigned int startPosition, unsigned int length, bool encrypted) {
    plugin::CallMethod<0x4DC620, CAEDataStream*, int, char*, unsigned int, unsigned int, bool>(this, trackId, filename, startPosition, length, encrypted);
}

CAEDataStream::~CAEDataStream() {
    plugin::CallMethod<0x4DC490, CAEDataStream*>(this);
}

bool CAEDataStream::Initialise() {
    return plugin::CallMethodAndReturn<bool, 0x4DC2B0, CAEDataStream*>(this);
}

unsigned int CAEDataStream::FillBuffer(void* dest, unsigned int size) {
    return plugin::CallMethodAndReturn<unsigned int, 0x4DC1C0, CAEDataStream*, void*, unsigned int>(this, dest, size);
}

unsigned int CAEDataStream::GetCurrentPosition() {
    return plugin::CallMethodAndReturn<unsigned int, 0x4DC230, CAEDataStream*>(this);
}

unsigned int CAEDataStream::Seek(long offset, int whence) {
    return plugin::CallMethodAndReturn<unsigned int, 0x4DC250, CAEDataStream*, long, int>(this, offset, whence);
}

bool CAEDataStream::Close() {
    return plugin::CallMethodAndReturn<bool, 0x4DC290, CAEDataStream*>(this);
}

HRESULT STDMETHODCALLTYPE CAEDataStream::QueryInterface(REFIID riid, void** objout) {
    return plugin::CallMethodAndReturn<HRESULT, 0x4DC410, CAEDataStream*, REFIID, void**>(this, riid, objout);
}

ULONG STDMETHODCALLTYPE CAEDataStream::AddRef() {
    return plugin::CallMethodAndReturn<ULONG, 0x4DC460, CAEDataStream*>(this);
}

ULONG STDMETHODCALLTYPE CAEDataStream::Release() {
    return plugin::CallMethodAndReturn<ULONG, 0x4DC5B0, CAEDataStream*>(this);
}

HRESULT STDMETHODCALLTYPE CAEDataStream::Read(void* dest, ULONG size, ULONG* readed) {
    return plugin::CallMethodAndReturn<HRESULT, 0x4DC320, CAEDataStream*, void*, ULONG, ULONG*>(this, dest, size, readed);
}

HRESULT STDMETHODCALLTYPE CAEDataStream::Write(const void* src, ULONG size, ULONG* written) {
    return plugin::CallMethodAndReturn<HRESULT, 0x4DC4D0, CAEDataStream*, const void*, ULONG, ULONG*>(this, src, size, written);
}

HRESULT STDMETHODCALLTYPE CAEDataStream::Seek(LARGE_INTEGER offset, DWORD whence, ULARGE_INTEGER* newOffset) {
    return plugin::CallMethodAndReturn<HRESULT, 0x4DC340, CAEDataStream*, LARGE_INTEGER, DWORD, ULARGE_INTEGER*>(this, offset, whence, newOffset);
}

HRESULT STDMETHODCALLTYPE CAEDataStream::SetSize(ULARGE_INTEGER newSize) {
    return plugin::CallMethodAndReturn<HRESULT, 0x4DC4E0, CAEDataStream*, ULARGE_INTEGER>(this, newSize);
}

HRESULT STDMETHODCALLTYPE CAEDataStream::CopyTo(IStream* target, ULARGE_INTEGER size, ULARGE_INTEGER* readed, ULARGE_INTEGER* written) {
    return plugin::CallMethodAndReturn<HRESULT, 0x4DC4F0, CAEDataStream*, IStream*, ULARGE_INTEGER, ULARGE_INTEGER*, ULARGE_INTEGER*>(this, target, size, readed, written);
}

HRESULT STDMETHODCALLTYPE CAEDataStream::Commit(DWORD flags) {
    return plugin::CallMethodAndReturn<HRESULT, 0x4DC500, CAEDataStream*, DWORD>(this, flags);
}

HRESULT STDMETHODCALLTYPE CAEDataStream::Revert() {
    return plugin::CallMethodAndReturn<HRESULT, 0x4DC510, CAEDataStream*>(this);
}

HRESULT STDMETHODCALLTYPE CAEDataStream::LockRegion(ULARGE_INTEGER offset, ULARGE_INTEGER size, DWORD type) {
    return plugin::CallMethodAndReturn<HRESULT, 0x4DC520, CAEDataStream*, ULARGE_INTEGER, ULARGE_INTEGER, DWORD>(this, offset, size, type);
}

HRESULT STDMETHODCALLTYPE CAEDataStream::UnlockRegion(ULARGE_INTEGER libOffset, ULARGE_INTEGER cb, DWORD dwLockType) {
    return plugin::CallMethodAndReturn<HRESULT, 0x4DC530, CAEDataStream*, ULARGE_INTEGER, ULARGE_INTEGER, DWORD>(this, libOffset, cb, dwLockType);
}

HRESULT STDMETHODCALLTYPE CAEDataStream::Stat(STATSTG* statout, DWORD flags) {
    return plugin::CallMethodAndReturn<HRESULT, 0x4DC3A0, CAEDataStream*, STATSTG*, DWORD>(this, statout, flags);
}

HRESULT STDMETHODCALLTYPE CAEDataStream::Clone(IStream** target) {
    return plugin::CallMethodAndReturn<HRESULT, 0x4DC540, CAEDataStream*, IStream**>(this, target);
}