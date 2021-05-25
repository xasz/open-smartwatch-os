
#include "ui/label.h"


void OswUiLabel::draw(ArduinoGraphics2DCanvas* c){
    OswUiDrawable::draw(c);
    c->setTextSize(textSize);
    switch(alignment){
        case Left:
          c->setCursor(posX,posY);
        break;
        case Center:
        default:
            int16_t  x1, y1;
            uint16_t  w, h;
            c->getTextBounds(text, 0, 0, &x1, &y1, &w, &h); 
            c->setCursor(posX + width / 2  - w / 2, posY + height / 2 - h / 2); 
        break;
    }
    c->print(text);
}

void OswUiLabel::clamp(ArduinoGraphics2DCanvas* c){
    int16_t  x1, y1;
    uint16_t  w, h;
    c->setTextSize(textSize);
    c->getTextBounds(text, 0, 0, &x1, &y1, &w, &h);  
    setWidth(w);
    setHeight(h);
}

void OswUiLabel::setText(char* text){
    this->text = text;
    _needsRedraw = true;
}