#ifndef OSW_UI_COMPONENT_H
#define OSW_UI_COMPONENT_H

#include "ui/drawable.h"

class OswUiComponent : public OswUiDrawable{
  public:
    OswUiComponent(uint16_t posX, uint16_t posY) : OswUiDrawable(posX, posY){};
    virtual void draw(ArduinoGraphics2DCanvas* c);
    virtual void calculate(ArduinoGraphics2DCanvas* c);
    void focus(){_hasFocus = true;};
    void unfocus(){_hasFocus = false;};
    bool hasFocus(){return _hasFocus;};
    ~OswUiComponent(){};
  private:
    bool _hasFocus = false;
};

#endif