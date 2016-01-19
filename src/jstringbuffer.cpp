

#include "jobject.h"
#include "jstringbuffer.h"
#include "stdlib.h"
#include "string.h"

StringBuffer::StringBuffer(unsigned long bufSize) {
  _bufferLength = bufSize;
  _currentLength = 0;
  initMemory();
}

StringBuffer::~StringBuffer() {
  if(_buffer) {
    delete[] _buffer;
  }
}

int StringBuffer::initMemory() {
  int result = 0;

  if(_bufferLength > 0) {
    _buffer = new char[_bufferLength];
    memset(_buffer, 0, _bufferLength);
  }
  else {
    _buffer = 0;
  }

  return result;
}

int StringBuffer::doubleMemory() {
  char* tmpBuf = new char[_bufferLength*2];
  memset(tmpBuf, 0, _bufferLength*2);
  memcpy(tmpBuf, _buffer, _bufferLength);
  delete[] _buffer;
  _buffer = tmpBuf;
  return 0;
}


void StringBuffer::cat(const char* str) {
  if(_currentLength + strlen(str) >= _bufferLength) {
    doubleMemory();
    cat(str);
  }
  else {
    strcat(_buffer, str);
    _currentLength = _currentLength + strlen(str);
  }
}

void StringBuffer::cat(const char* str, unsigned long length) {
  if(_currentLength + length >= _bufferLength) {
    doubleMemory();
    cat(str, length);
  }
  else {
    strncat(_buffer, str, length);
    _currentLength = _currentLength + length;
  }
}

void StringBuffer::copyFrom(const char* str) {
  if(_bufferLength <= strlen(str)) {
    doubleMemory();
    copyFrom(str);
  }
  else {
    strcpy(_buffer, str);
    _currentLength = strlen(str);
  }
}

void StringBuffer::copyFrom(const char* str, unsigned long length) {
  if(_bufferLength <= length) {
    doubleMemory();
    copyFrom(str, length);
  }
  else {
    strncpy(_buffer, str, length);
    _currentLength = length;
  }
}


