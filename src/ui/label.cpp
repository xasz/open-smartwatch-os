
#include "ui/label.h"


void OswUiLabel::draw(ArduinoGraphics2DCanvas* c){
    OswUiDrawable::draw(c);
    c->setTextSize(2);
    c->setCursor(posX,posY);
    c->print(text);
}

void OswUiLabel::calculate(ArduinoGraphics2DCanvas* c){
    int16_t  x1, y1;
    uint16_t  w, h;
    c->setTextSize(2);
    c->getTextBounds(text, 0, 0, &x1, &y1, &w, &h);  
    setWidth(w);
    setHeight(h);
}

void OswUiLabel::setText(char* text){
    this->text = text;
}