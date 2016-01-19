

#include "jcolor.h"

JColor::JColor() {
  _red  = 0;
  _green= 0;
  _blue = 0;
  _alpha= 0;

}

JColor::JColor(u1 red, u1 green, u1 blue, u1 alpha) {
  _red  = red;
  _green= green;
  _blue = blue;
  _alpha= alpha;
}

JColor::JColor(const JColor& color) {
  _red = color._red;
  _green = color._green;
  _blue = color._blue;
  _alpha = color._alpha;
}

JColor::~JColor() {
}

void JColor::setRed(u1 red)
{
  _red = red;
}

void JColor::setGreen(u1 green) {
  _green = green;
}

void JColor::setBlue(u1 blue) {
  _blue = blue;
}

void JColor::setAlpha(u1 alpha) {
  _alpha = alpha;
}

