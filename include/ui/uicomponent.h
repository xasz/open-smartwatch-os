#ifndef OSW_UI_COMPONENT_H
#define OSW_UI_COMPONENT_H

#include "ui/drawable.h"


enum Alignment{
  Center,
  Left
};

class OswUiComponent : public OswUiDrawable{
  public:
    OswUiComponent(uint16_t posX, uint16_t posY) : OswUiDrawable(posX, posY){};
    virtual void draw(ArduinoGraphics2DCanvas* c);
    virtual void calculate(ArduinoGraphics2DCanvas* c);
    void focus(){_hasFocus = true;_needsRedraw = true;};
    void unfocus(){_hasFocus = false;_needsRedraw = true;};
    bool hasFocus(){return _hasFocus;};
    void setAlignment(Alignment a){
      alignment = a;
    }
    ~OswUiComponent(){};
  protected:
    bool _hasFocus = false;
    Alignment alignment;
};

#endif