
#include "ui/slider.h"


#define SLIDER_TIME_STEP 500

void OswUiSlider::draw(ArduinoGraphics2DCanvas* c){
    OswUiDrawable::draw(c);
    //TODO Fix this caluclation (width /  100) * value - 240 / 100 * 50 should be 120 but is 100
    if(hasFocus()){
        c->fillRect(posX,posY,(width /  100) * value, height, ui->getPrimaryColor());
    }else{
        c->fillRect(posX,posY,(width /  100) * value, height, ui->getInfoColor());
    } 
}

void OswUiSlider::stepUp(){
    value += step;
    if(value > 100){
        value = 100;
    }
    lastStepTime = millis();
    changed = true;
}

void OswUiSlider::stepDown(){
    if(value >= step){
        value-= step;
    }else{
        value = 0;
    }
    lastStepTime = millis();
    changed = true;
}

bool OswUiSlider::handleInput(OswHal* hal){
    

    if(hal->btnIsLongPress(BUTTON_3)){
        if(lastStepTime == 0){
            stepUp();
        }
        if(lastStepTime + SLIDER_TIME_STEP > millis()){
            stepUp();
        }
        return true;
    }
    if(hal->btnHasGoneUp(BUTTON_3) & lastStepTime > 0){
        lastStepTime = 0;
        return true;
    }

    if(hal->btnIsLongPress(BUTTON_2)){
        if(lastStepTime == 0){
            stepDown();
        }
        if(lastStepTime + SLIDER_TIME_STEP > millis()){
            stepDown();
        return true;
        }  
    }
    if(hal->btnHasGoneUp(BUTTON_2) & lastStepTime > 0){
        lastStepTime = 0;
        return true;
    }
    return false;
}
