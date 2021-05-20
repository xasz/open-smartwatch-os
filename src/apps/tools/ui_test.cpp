
#include "./apps/tools/ui_test.h"
#include "./ui/button.h"



void OswAppUiTest::setup(OswHal* hal) {
    listView = new OswUiListView(0,0);
    listView->setWidth(hal->gfx()->getWidth());
    listView->setHeight(hal->gfx()->getHeight());
    listView->add(new OswUiLabel(0,0,"Lorem"));
    listView->add(new OswUiLabel(0,0,"Ipsum"));
    listView->add(new OswUiLabel(0,0,"dolor"));
    listView->add(new OswUiLabel(0,0,"sit"));
    listView->add(new OswUiLabel(0,0,"amet"));
    listView->add(new OswUiLabel(0,0,"consectetur"));
    OswUiButton* btn = new OswUiButton(0,0,"adipisici");
    listView->add(btn);
    btn->focus();
    listView->setAlignment(Center);
}

void OswAppUiTest::loop(OswHal* hal) {
    listView->calculate(hal->getCanvas());
    listView->draw(hal->getCanvas());
    hal->requestFlush();
}

void OswAppUiTest::stop(OswHal* hal) {
    delete(listView);
}