
#include "jfont.h"

JFont::JFont() {
  _fontSize = DEFAULT_FONTSIZE;
  _fontName = "Arial";
  _fontStyle    = NORMAL;
}

JFont::JFont(const JFont& font) {
  _fontName = font._fontName;
  _fontSize = font._fontSize;
  _fontColor = font._fontColor;
  _fontStyle = font._fontStyle;
}

JFont::~JFont() {
}
