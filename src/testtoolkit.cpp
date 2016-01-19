#include "toolkit.h"
#include <stdio.h>
#include <assert.h>

void testToolkit() {
  u1 high, low;
  u2 highWord, lowWord;
  u2 wordValue = 0xaabb;
  u4 doubleWordValue = 0xaabbccdd;

  high  = ToolKit::getHighByte(wordValue);
  low   = ToolKit::getLowByte(wordValue);
  assert(high == 0xaa);
  assert(low == 0xbb);

  highWord = ToolKit::getHighWord(doubleWordValue);
  lowWord = ToolKit::getLowWord(doubleWordValue);

  assert(highWord == 0xaabb);
  assert(lowWord == 0xccdd);

  u1 buf[32];
  memset(buf, 0, 32);

  unsigned int pos = 0;
  u4 gotValue;
  ToolKit::memSetU4(buf, doubleWordValue, 32, pos);
  pos = 0;
  gotValue = ToolKit::memGetU4(buf, pos);
  printf("%x", gotValue);
  assert(gotValue == doubleWordValue);
}
