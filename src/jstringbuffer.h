#ifndef JASMIN_STRINGBUFFER_H
#define JASMIN_STRINGBUFFER_H

#include "jobject.h"

class StringBuffer : public JObject {
  protected:
    char* _buffer;

    unsigned long _bufferLength;

    unsigned long _currentLength;

    int initMemory();

    int doubleMemory();


  public:
    StringBuffer(unsigned long bufSize = 0);

    ~StringBuffer();

    void cat(const char* str);

    void cat(const char* str, unsigned long length);

    void copyFrom(const char* str);

    void copyFrom(const char* str, unsigned long length);

    inline const char* getBuffer() { return _buffer; };

    inline const unsigned long getCurrentLength() { return _currentLength; };
};

#endif  //JASMIN_STRINGBUFFER_H

