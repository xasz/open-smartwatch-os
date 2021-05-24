 #include "ui/listview.h"   
    
void OswUiListView::draw(ArduinoGraphics2DCanvas* c){
    if(_needsRedraw){
        
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
void OswUiListView::add(OswUiComponent* d){
  count++;
  drawables.push_back(d);
}

void OswUiListView::down(){
    if(selected < count - 1){
        select(selected + 1);
    }else{
        select(count - 1);
    }    
}

void OswUiListView::up(){
    if(selected > 0){
        select(selected - 1);
    }else{
        select(0);
    }    
}

void OswUiListView::select(uint16_t index){
    if(selected < 0){
        selected = 0;
    }
    if(selected >= count){
        selected = count -1;
    }
    drawables[selected]->unfocus(); 
    selected = index;
    drawables[selected]->focus(); 
    Serial.println(selected);
    _needsRedraw = true;
}

void OswUiListView::setWidthToAllChilds(){
    for(uint16_t i = 0 ; i < count ; i++){
        setWidth(width);
    }
}