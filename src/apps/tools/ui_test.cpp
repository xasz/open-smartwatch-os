
#include "./apps/tools/ui_test.h"
#include "./ui/button.h"



void OswAppUiTest::setup(OswHal* hal) {
    listView = new OswUiListView(0,0);
    listView->setWidth(hal->gfx()->getWidth());
    listView->setHeight(hal->gfx()->getHeight());

    btnLorem = new OswUiButton(0,0,"Lorem");
    listView->add(btnLorem);

    btnIpsum = new OswUiButton(0,0,"Ipsum");
    listView->add(btnIpsum);
    
    btnDolor = new OswUiButton(0,0,"dolor");
    listView->add(btnDolor);

    btnSit = new OswUiButton(0,0,"sit");
    listView->add(btnSit);

    btnAmet = new OswUiButton(0,0,"amet");
    listView->add(btnAmet);

    listView->setAlignment(Center);
    listView->setWidthToAllChilds();
}

void OswAppUiTest::loop(OswHal* hal) {
    if(hal->btnHasGoneUp(BUTTON_3)){
        listView->up();
    }

    if(hal->btnHasGoneUp(BUTTON_2)){
        listView->down();
    }

    if(btnAmet->isClicked()){
        Serial.println("Amet");
    }


    listView->calculate(hal->getCanvas());
    listView->draw(hal->getCanvas());
    hal->requestFlush();
}

void OswAppUiTest::stop(OswHal* hal) {
    delete(listView);
}

