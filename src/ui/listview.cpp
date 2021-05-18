 #include "ui/listview.h"   
    
void OswUiListView::draw(ArduinoGraphics2DCanvas* c){
    if(_needsRedraw){
        if(selected < 0){
            selected = 0;
        }
        if(selected >= count){
            selected = count -1;
        }
        
        uint16_t offsetX = posX;
        uint16_t offsetY = posY;

        for(uint16_t i = 0 ; i < count ; i++){
            drawables[i]->setPosX(offsetX);
            drawables[i]->setPosY(offsetY);
            drawables[i]->draw(c);
            offsetY += drawables[i]->getHeight();
        }
    }
    _needsRedraw = false;
}
void OswUiListView::calculate(ArduinoGraphics2DCanvas* c){
    for(uint16_t i = 0 ; i < count ; i++){
        drawables[i]->calculate(c);
    }
}
void OswUiListView::add(OswUiDrawable* d){
  count++;
  drawables.push_back(d);
}
