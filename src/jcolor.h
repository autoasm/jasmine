#ifndef JASMIN_COLOR_H
#define JASMIN_COLOR_H

#include "jobject.h"

class JColor : public JObject {

  protected:
    u1 _red;
    u1 _green;
    u1 _blue;
    u1 _alpha;

  public:
    JColor();

    JColor(u1 red, u1 green, u1 blue, u1 alpha);

    JColor(const JColor& color);

    virtual ~JColor();

    inline const u1 getRed() { return _red; };

    void setRed(u1 red);

    inline const u1 getGreen() { return _green; };

    void setGreen(u1 green);

    inline const u1 getBlue() { return _blue; };

    void setBlue(u1 blue);

    inline const u1 getAlpha() { return _alpha; };

    void setAlpha(u1 alpha);

};

#endif  //JASMIN_COLOR_H
