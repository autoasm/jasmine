
#include "htmlformator.h"
#include <stdio.h>


HtmlFormator::HtmlFormator() {
  _buffer = new StringBuffer(DEFAULT_BUFFER_SIZE);
}


HtmlFormator::~HtmlFormator(void) {
  if(_buffer) {
    delete _buffer;
  }
}


JFont HtmlFormator::getDefaultFont() {
  JFont result;
  return result;
}


JFont HtmlFormator::getFontByType(unsigned int type) {
  JFont result = getDefaultFont();

  if(type >= CLASSNAME && type <= OPERAND) {
    result = _fontList[type];
  }

  return result;
}

void HtmlFormator::setFont(JFont font, unsigned int type) {
  if(type >= CLASSNAME && type <= OPERAND) {
    _fontList[type] = font;
  }
}

string HtmlFormator::getColorString(JFont font) {

  char redStr[16];
  char greenStr[16];
  char blueStr[16];

  memset(redStr, 0, 16);
  memset(greenStr, 0, 16);
  memset(blueStr, 0, 16);

  strcpy(redStr, "00");
  strcpy(greenStr, "00");
  strcpy(blueStr, "00");
  string result = " color=\"";

  sprintf(redStr, "%x", font.getFontColor()->getRed());
  sprintf(greenStr, "%x", font.getFontColor()->getGreen());
  sprintf(blueStr, "%x", font.getFontColor()->getBlue());

  if(font.getFontColor()->getRed() <= 0xf) {
    redStr[1] = redStr[0];
    redStr[0] = '0';
  }

  if(font.getFontColor()->getGreen() <= 0xf) {
    greenStr[1] = greenStr[0];
    greenStr[0] = '0';
  }

  if(font.getFontColor()->getBlue() <= 0xf) {
    blueStr[1] = blueStr[0];
    blueStr[0] = '0';
  }


  result = result + "#";
  result = result + redStr;
  result = result + greenStr;
  result = result + blueStr;
  result = result + "\"";

  return result;
}

string HtmlFormator::getFaceString(JFont font) {
  string result;

  result = "face=\"";
  result = result + font.getFontName();
  result = result + "\"";

  return result;
}

string HtmlFormator::getNextLine() {
  string result = "<br>";
  return result;
}

string HtmlFormator::getHtmlTextString(JFont font, string text) {
  string result;
  bool bold = false;
  bool italic = false;

  if(font.isBold()) {
    bold = true;
    result = result + "<b>";
  }
  if(font.isItalic()) {
    italic = true;
    result = result + "<i>";
  }
  result = result + "<font ";
  result = result + getFaceString(font);
  result = result + getColorString(font);
  result = result + ">";
  result = result + text;
  result = result + "</font>";

  if(bold) {
    result = result + "</b>";
  }
  if(italic) {
    result = result + "</i>";
  }

  return result;
}

void HtmlFormator::classBegin(char* className, char* superClass) {
  string superNameStr;
  string classNameStr = className;
  if(superClass) {
    superNameStr = superClass;
  }
  htmlBegin();
  addTab();
  _buffer->cat(getHtmlTextString(getFontByType(KEYWORD), "class").c_str());
  addSpace();
  _buffer->cat(getHtmlTextString(getFontByType(CLASSNAME), classNameStr).c_str());
  addSpace();
  if(superClass) {
    _buffer->cat(getHtmlTextString(getDefaultFont(), ":").c_str());
    addSpace();
    _buffer->cat(getHtmlTextString(getFontByType(CLASSNAME), superNameStr).c_str());
    addSpace();
  }
  _buffer->cat(getHtmlTextString(getDefaultFont(), "{").c_str());
  _buffer->cat(getNextLine().c_str());
}

void HtmlFormator::classEnd() {
  addTab();
  _buffer->cat(getHtmlTextString(getDefaultFont(), "}").c_str());
  _buffer->cat(getNextLine().c_str());
  htmlEnd();
}

void HtmlFormator::methodBegin(char* className, char* methodName) {
  /* TODO < = &lt; > = &gt; */
  char tmpMethodName[16];
  addTab();
  addTab();
  _buffer->cat(getHtmlTextString(getFontByType(CLASSNAME), className).c_str());
  _buffer->cat(getHtmlTextString(getDefaultFont(), "::").c_str());
  if(methodName[0] == '<') {
    /* <clinit> method */
    memset(tmpMethodName, 0, 16);
    strcpy(tmpMethodName, "&lt;");
    strncat(tmpMethodName, methodName + 1, strlen(methodName) - 2);
    strcat(tmpMethodName, "&gt;");
    _buffer->cat(getHtmlTextString(getFontByType(METHOD), tmpMethodName).c_str());
  }
  else {
    _buffer->cat(getHtmlTextString(getFontByType(METHOD), methodName).c_str());
  }
  _buffer->cat(getHtmlTextString(getDefaultFont(), "( ) {").c_str());
  _buffer->cat(getNextLine().c_str());
}

void HtmlFormator::methodEnd() {
  addTab();
  addTab();
  _buffer->cat(getHtmlTextString(getDefaultFont(), "}").c_str());
  _buffer->cat(getNextLine().c_str());
}

void HtmlFormator::upcase() {
}

void HtmlFormator::lowcase() {
}

void HtmlFormator::addKeyWord(char* keyWord) {
  addTab();
  addTab();
  addTab();
  _buffer->cat(getHtmlTextString(getFontByType(KEYWORD), keyWord).c_str());
  addSpace();
}

void HtmlFormator::addOperand(u1 operand) {
  char operandStr[4];
  memset(operandStr, 0, 4);
  sprintf(operandStr, "%d", operand);
  _buffer->cat(getHtmlTextString(getFontByType(OPERAND), operandStr).c_str());
}

void HtmlFormator::addComment(char* comment) {
}

void HtmlFormator::enter() {
  _buffer->cat(getNextLine().c_str());
}

void HtmlFormator::comma() {
}

void HtmlFormator::destroy() {
  delete this;
}

void HtmlFormator::addTab() {
  _buffer->cat("&nbsp;&nbsp;&nbsp;");
}

void HtmlFormator::addSpace() {
  _buffer->cat("&nbsp;");
}

const char* HtmlFormator::getHtmlString() {
  const char* result = 0;

  if(_buffer) {
    result = _buffer->getBuffer();
  }

  return result;
}

void HtmlFormator::htmlBegin() {
  //_htmlString = _htmlString + "<html><body>";
  _buffer->cat("<html><body>");
}

void HtmlFormator::htmlEnd() {
  //_htmlString = _htmlString + "</body></html>";
  _buffer->cat("</body></html>");
}
