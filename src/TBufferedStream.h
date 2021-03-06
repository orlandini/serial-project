#ifndef TBUFFEREDSTREAM_H
#define TBUFFEREDSTREAM_H
#include "TStream.h"
#include <sstream>

class TBufferedStream : public TStream {
public:
    //TBufferedStream();
    TBufferedStream(TStream &underlyingStream);
    TBufferedStream(const TBufferedStream &readBuffer);
    ~TBufferedStream();
    virtual void Read(double *p, int size=1);
    virtual void Write(const double *var, int size=1);
    TBufferedStream &operator=(const TBufferedStream &);
    virtual TBufferedStream &operator<<(TBufferedStream &other);
    virtual TBufferedStream &operator<<(const TBufferedStream &other);
    void Print();
    void BeginUpdate();
    void EndUpdate(unsigned long new_version);
protected:
    virtual void ReadFromBuffer(char *dest, const size_t &nBytes);
    virtual void ConstRead(char *dest, const size_t &nBytes) const;
    virtual void WriteToBuffer(const char *source, const size_t &nBytes);
private:
    char *fBuffer;
    char *fFirst;
    char *fLast;
    size_t nAllocatedBytes;
    size_t fSize;
    bool readFromUnderlyingStream;
    TStream &underlyingStream;

    virtual void ConstReadFromBuffer(char *dest, const size_t &nBytes) const;
    static const size_t SIZE_INCREMENT = size_t(1);
};
#endif // TBUFFEREDSTREAM_H