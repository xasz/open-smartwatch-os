#ifndef OSW_UI_LISTVIEW_H
#define OSW_UI_LISTVIEW_H

#include "ui/uicomponent.h"
#include <vector>


class OswUiListView : public OswUiComponent{
  public:
    OswUiListView(uint16_t posX, uint16_t posY) : OswUiComponent(posX, posY){};
    virtual void draw(ArduinoGraphics2DCanvas* c);
    virtual void calculate(ArduinoGraphics2DCanvas* c);
    void add(OswUiComponent* d);
    void up();
    void down();
    void select(uint16_t index);
    void setWidthToAllChilds();
    ~OswUiListView(){};
    
  private:
    std::vector<OswUiComponent*> drawables;
    uint16_t count = 0;
    uint16_t selected = 0;
    uint16_t visibleElements = 3;
};

#endif
