
#ifndef JASMINE_BUFFER_H
#define JASMINE_BUFFER_H

#include "jobject.h"

class JBuffer : public JObject {

  public:
	/// Default buffer size
    static const unsigned long DEFAULT_SIZE = 512 * 1024;

  protected:
    u1* _buffer;

    unsigned long _size;

    unsigned long _currentPos;

    void initBuffer(unsigned long size);



  public:
    JBuffer();

    JBuffer(const JBuffer& buffer);

    ~JBuffer();

    void doubleSize();

    inline u1* getBuffer() { return _buffer; };

    inline unsigned long getSize() { return _size; };

    inline unsigned long getCurrentPos() { return _currentPos; };

    inline void setCurrentPos(unsigned long pos) { _currentPos = pos; };

};



#endif  //JASMINE_BUFFER_H

