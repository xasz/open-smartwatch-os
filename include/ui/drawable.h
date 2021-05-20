#ifndef OSW_UI_DRAWABLE_H
#define OSW_UI_DRAWABLE_H

#include <osw_hal.h>
#include <gfx_util.h>
#include "osw_ui.h"

class OswUiDrawable {
  public:
    OswUiDrawable(uint16_t posX, uint16_t posY){    
        ui = OswUI::getInstance();
        this->posX = posX;
        this->posY = posY;
        backgroundColor = ui->getBackgroundColor();
    }
    bool needsRedraw(){return _needsRedraw;}
    void setBackground(uint16_t color){backgroundColor = color;}
    virtual void calculate(ArduinoGraphics2DCanvas* c){}
    virtual void draw(ArduinoGraphics2DCanvas* c);
    void setWidth(uint16_t width){this->width = width;}
    void setHeight(uint16_t height){this->height = height;}
    uint16_t getWidth(){return width;}
    uint16_t getHeight(){return height;}
    void setPosX(uint16_t posX){this->posX = posX;}
    void setPosY(uint16_t posY){this->posY = posY;}

  protected:
    OswUI* ui;
    uint16_t posX = 0;
    uint16_t posY = 0;
    
    uint16_t width = 0;
    uint16_t height = 0;

    uint16_t backgroundColor = rgb565(0, 0, 0);
    bool _needsRedraw = true;
};

#endif
