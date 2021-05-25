
#include "./apps/tools/ui_test.h"



void OswAppUiTest::setup(OswHal* hal) {
    listView = new OswUiListView(0,0);

    btnLorem = new OswUiButton(0,0,"Lorem");
    listView->add(btnLorem);

    btnIpsum = new OswUiButton(0,0,"Ipsum");
    btnIpsum->setTextSize(3);
    listView->add(btnIpsum);
    
    btnDolor = new OswUiButton(0,0,"dolor");
    listView->add(btnDolor);

    btnSit = new OswUiButton(0,0,"sit");
    listView->add(btnSit);

    btnAmet = new OswUiButton(0,0,"amet");
    listView->add(btnAmet);
    
    slider = new OswUiSlider(0,0);
    listView->add(slider);
    

    listView->setAlignment(Center);
    listView->setWidth(hal->gfx()->getWidth());
    listView->setHeight(hal->gfx()->getHeight());
    listView->autoSizeChilds(hal->getCanvas());
    listView->setChildsAlignemnt(Center);
    listView->maxWithChilds();

}

void OswAppUiTest::loop(OswHal* hal) {

    if(btnAmet->isClicked()){
        Serial.println("Click Amet");
    }

    if(btnSit->isClicked()){
        Serial.println("Click sit");
    }
    
    if(slider->hasChanged()){
        Serial.print(slider->getValue());
        Serial.println(" New slider value ");
    }

    listView->draw(hal->getCanvas());
    listView->handleInput(hal);
    hal->requestFlush();
}

void OswAppUiTest::stop(OswHal* hal) {
    delete(listView);
}

