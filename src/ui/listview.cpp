 #include "ui/listview.h"   
    
void OswUiListView::draw(ArduinoGraphics2DCanvas* c){
    if(_needsRedraw){
        if(selected < 0){
            selected = 0;
        }
        if(selected >= count){
            selected = count -1;
        }
        
        uint16_t offsetY = posY;

        for(uint16_t i = 0 ; i < count ; i++){
            
            switch(alignment){
                case Center:
                    drawables[i]->setPosX(width / 2 - drawables[i]->getWidth()/2);
                break;
                case Left:
                default:
                    drawables[i]->setPosX(posX);
                break;
            }
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

void OswUiListView::setAlignment(Alignment a){
    alignment = a;
}
