
#include "ui/button.h"

void OswUiButton::draw(ArduinoGraphics2DCanvas* c){
    if(hasFocus()){
        setBackground(ui->getForegroundColor());
    }else{
        setBackground(ui->getBackgroundColor());
    }
    OswUiLabel::draw(c);
}
