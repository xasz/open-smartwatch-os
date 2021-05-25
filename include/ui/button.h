#ifndef OSW_UI_BUTTON_H
#define OSW_UI_BUTTON_H

#include "ui/label.h"

class OswUiButton : public OswUiLabel{
  public:
    OswUiButton(uint16_t posX, uint16_t posY) : OswUiLabel(posX, posY){};
    OswUiButton(uint16_t posX, uint16_t posY, char* text) : OswUiLabel(posX, posY, text){};
    void draw(ArduinoGraphics2DCanvas* c) override;
    bool handleInput(OswHal* hal) override;
    bool isClicked(){bool r = clicked; clicked = false; return r;};
    void click(){clicked = true; onClick();};
    virtual void onClick(){};
    ~OswUiButton(){};
  private:
    bool clicked = false;
};

#endif
