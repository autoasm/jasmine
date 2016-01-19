
#include "jbuffer.h"
#include <stdlib.h>
#include <string.h>

JBuffer::JBuffer() {
  _buffer = 0;
  initBuffer(DEFAULT_SIZE);
  _size = DEFAULT_SIZE;
  _currentPos = 0;
}

JBuffer::JBuffer(const JBuffer& buffer) {
  _size = buffer._size;
  _currentPos = buffer._currentPos;
  if(_buffer) {
    delete[] _buffer;
  }
  _buffer = new u1[_size];
  memcpy(_buffer, buffer._buffer, _size);
}

JBuffer::~JBuffer() {
  if(_buffer) {
    delete[] _buffer;
  }
}

void JBuffer::doubleSize() {
  unsigned long newSize = _size*2;
  u1* tmpBuf = new u1[newSize];
  memset(tmpBuf, 0, newSize);
  memcpy(tmpBuf, _buffer, _size);
  delete[] _buffer;
  _buffer = tmpBuf;
  _size = newSize;
}

void JBuffer::initBuffer(unsigned long size) {
  if(_buffer) {
    delete[] _buffer;
  }
  _buffer = new u1[size];
  memset(_buffer, 0, size);
}
