
#ifndef JASMIN_FONT_H
#define JASMIN_FONT_H

#include "jobject.h"
#include "jcolor.h"
#include <string>

#ifndef NO_NAMESPACE
using namespace std;
#endif

/*!
 * \class JFont
 * HtmlFormator support customizing font 
 */ 
class JFont : public JObject {
  public:
    enum {
      DEFAULT_FONTSIZE = 4  ///Default Font size
    };

    typedef enum {
         NORMAL  = 0,
         BORDER  = 1,
         ITALIC  = 2,
    }FontStyle;

  protected:
  	/// Font name
    string  _fontName;

	/// Font size
    u1      _fontSize;

    JColor  _fontColor;

    int _fontStyle;

  public:

    JFont();

    JFont(const JFont& font);

    virtual ~JFont();

    inline void setFontColor(const JColor& color) { _fontColor = color; };

    inline JColor* getFontColor() { return &_fontColor; };

    inline void setFontName(string fontName) { _fontName = fontName; };

    inline string getFontName() { return _fontName; };

    inline const u1 getFontSize() { return _fontSize; };

    inline void setFontSize(const u1 fontSize) { _fontSize = fontSize; };

    inline int getFontStyle() { return _fontStyle; };

    inline void setFontStyle(FontStyle style) { _fontStyle = style; };

    inline void setBold(bool bold) { };

    inline void setItablic(bool italic) { };

    inline bool isBold() { return true; };

    inline bool isItalic() { return true; };

    /*! \TODO */

};

#endif  //JASMIN_FONT_H

