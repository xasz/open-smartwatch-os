#ifndef OSW_UI_LABEL_H
#define OSW_UI_LABEL_H

#include "ui/drawable.h"

class OswUiLabel : public OswUiDrawable{
  public:
    OswUiLabel(uint16_t posX, uint16_t posY) : OswUiDrawable(posX, posY){};
    OswUiLabel(uint16_t posX, uint16_t posY, char* text) : OswUiDrawable(posX, posY){ this->text = text;};
    virtual void draw(ArduinoGraphics2DCanvas* c);
    void setText(char* text);
    virtual void calculate(ArduinoGraphics2DCanvas* c);
    ~OswUiLabel(){};
  private:
    char* text;
};

#endif
