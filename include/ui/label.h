#ifndef OSW_UI_LABEL_H
#define OSW_UI_LABEL_H

#include "ui/uicomponent.h"

class OswUiLabel : public OswUiComponent{
  public:
    OswUiLabel(uint16_t posX, uint16_t posY) : OswUiComponent(posX, posY){};
    OswUiLabel(uint16_t posX, uint16_t posY, char* text) : OswUiComponent(posX, posY){ this->text = text;};
    void draw(ArduinoGraphics2DCanvas* c);
    void setText(char* text);
    char* getText(){return text;};
    void setTextSize(uint8_t size){textSize = size;};
    uint8_t getTextSize(){return textSize;};
    void clamp(ArduinoGraphics2DCanvas* c) override;
    ~OswUiLabel(){};
  protected:
    char* text;
    uint8_t textSize = 2;
};

#endif
