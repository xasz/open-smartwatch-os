
#include "./apps/tools/ui_test.h"



void OswAppUiTest::setup(OswHal* hal) {
    listView = new OswUiListView(0,0);
    listView->add(new OswUiLabel(0,0,"Lorem"));
    listView->add(new OswUiLabel(0,0,"Ipsum"));
    listView->add(new OswUiLabel(0,0,"dolor"));
    listView->add(new OswUiLabel(0,0,"sit"));
    listView->add(new OswUiLabel(0,0,"amet"));
    listView->add(new OswUiLabel(0,0,"consectetur"));
    listView->add(new OswUiLabel(0,0,"adipisici"));
    listView->add(new OswUiLabel(0,0,"elit"));
}

void OswAppUiTest::loop(OswHal* hal) {
    listView->calculate(hal->getCanvas());
    listView->draw(hal->getCanvas());
    hal->requestFlush();
}

void OswAppUiTest::stop(OswHal* hal) {
    delete(listView);
}