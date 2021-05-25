#ifndef OSW_UI_TEST_H
#define OSW_UI_TEST_H

#include <osw_hal.h>

#include "osw_app.h"
#include "./ui/listview.h"
#include "./ui/button.h"
#include "./ui/slider.h"

class OswAppUiTest : public OswApp {
 public:
  OswAppUiTest(){};
  void setup(OswHal* hal);
  void loop(OswHal* hal);
  void stop(OswHal* hal);
  ~OswAppUiTest(){};
 private:
  OswUiListView* listView;
  OswUiButton* btnLorem;
  OswUiButton* btnIpsum;
  OswUiButton* btnDolor ;
  OswUiButton* btnSit;
  OswUiButton* btnAmet;
  OswUiSlider* slider;
};

#endif
