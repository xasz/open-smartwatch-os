
#include "ui/button.h"

void OswUiButton::draw(ArduinoGraphics2DCanvas* c){
    if(hasFocus()){
        setBackground(ui->getPrimaryColor());
    }else{
        setBackground(ui->getBackgroundColor());
    } 
    OswUiLabel::draw(c);
}

bool OswUiButton::handleInput(OswHal* hal){
    if(hal->btnHasGoneUp(BUTTON_1)){
        click();
        return true;
    }
    return false;
}
