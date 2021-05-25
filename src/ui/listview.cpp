 #include "ui/listview.h"   
    
void OswUiListView::draw(ArduinoGraphics2DCanvas* c){


    if(_needsRedraw){
        
        uint16_t offsetY = posY;

        for(uint16_t i = 0 ; i < count ; i++){
            
            switch(alignment){
                case Center:
                    compoments[i]->setPosX(width / 2 - compoments[i]->getWidth()/2);
                break;
                case Left:
                default:
                    compoments[i]->setPosX(posX);
                break;
            }
            compoments[i]->setPosY(offsetY);
            compoments[i]->draw(c);
            offsetY += compoments[i]->getHeight();
        }
    }else{
        //Always draw the current selected for instand update
        compoments[selected]->draw(c);
    }
    _needsRedraw = false;
}


void OswUiListView::add(OswUiComponent* d){
  count++;
  if(count == 1){
      d->focus();
      selected = 0;
  }
  compoments.push_back(d);
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
    compoments[selected]->unfocus(); 
    selected = index;
    compoments[selected]->focus(); 
    _needsRedraw = true;
}

void OswUiListView::maxWithChilds(){
    for(uint16_t i = 0 ; i < count ; i++){
        compoments[i]->setWidth(width); 
    }
}

void OswUiListView::autoSizeChilds(ArduinoGraphics2DCanvas* c){
    for(uint16_t i = 0 ; i < count ; i++){
        compoments[i]->clamp(c); 
    }
}

void OswUiListView::setChildsAlignemnt(Alignment a){
    for(uint16_t i = 0 ; i < count ; i++){
        compoments[i]->setAlignment(a);
    }
}

bool OswUiListView::handleInput(OswHal* hal){

    if(!compoments[selected]->handleInput(hal)){
        if(hal->btnHasGoneUp(BUTTON_3)){
            up();
        }

        if(hal->btnHasGoneUp(BUTTON_2)){
            down();
        }
    }
    return false;
}