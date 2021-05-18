
#include "ui/drawable.h"

void OswUiDrawable::draw(ArduinoGraphics2DCanvas* c){
  c->fillRect(posX,posY,width,height,backgroundColor);
  _needsRedraw = false;
}