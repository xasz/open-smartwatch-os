#ifndef OSW_UI_LABEL_H
#define OSW_UI_LABEL_H

#include "ui/uicomponent.h"

class OswUiLabel : public OswUiComponent{
  public:
    OswUiLabel(uint16_t posX, uint16_t posY) : OswUiComponent(posX, posY){};
    OswUiLabel(uint16_t posX, uint16_t posY, char* text) : OswUiComponent(posX, posY){ this->text = text;};
    void draw(ArduinoGraphics2DCanvas* c);
    void setText(char* text);
    void calculate(ArduinoGraphics2DCanvas* c);
    ~OswUiLabel(){};
  private:
    char* text;
};

#endif
