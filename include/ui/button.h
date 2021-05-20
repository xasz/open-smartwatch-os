#ifndef OSW_UI_BUTTON_H
#define OSW_UI_BUTTON_H

#include "ui/label.h"

class OswUiButton : public OswUiLabel{
  public:
    OswUiButton(uint16_t posX, uint16_t posY) : OswUiLabel(posX, posY){};
    OswUiButton(uint16_t posX, uint16_t posY, char* text) : OswUiLabel(posX, posY, text){};
    void draw(ArduinoGraphics2DCanvas* c) override;
    ~OswUiButton(){};
  private:
};

#endif
