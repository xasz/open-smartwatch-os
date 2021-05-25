#ifndef OSW_UI_SLIDER_H
#define OSW_UI_SLIDER_H

#include "ui/uicomponent.h"

class OswUiSlider : public OswUiComponent{
  public:
    OswUiSlider(uint16_t posX, uint16_t posY) : OswUiComponent(posX, posY){
        height = 16;
    };
    void draw(ArduinoGraphics2DCanvas* c);
    void setValue(uint8_t v){
        value = v;
        if(value > 100){
            value = 100;
        }
    }
    uint8_t getValue(){return value;}
    void stepUp();
    void stepDown();
    bool hasChanged(){bool c = changed; changed = false; return c;};
    bool handleInput(OswHal* hal) override;
    ~OswUiSlider(){};
  protected:
    uint8_t value = 50;
    uint8_t step = 1;
    uint16_t lastStepTime = 0;
    bool changed = false;
};

#endif