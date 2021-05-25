#ifndef OSW_UI_LISTVIEW_H
#define OSW_UI_LISTVIEW_H

#include "ui/uicomponent.h"
#include <vector>


class OswUiListView : public OswUiComponent{
  public:
    OswUiListView(uint16_t posX, uint16_t posY) : OswUiComponent(posX, posY){};
    virtual void draw(ArduinoGraphics2DCanvas* c);
    void add(OswUiComponent* d);
    void up();
    void down();
    void select(uint16_t index);
    void maxWithChilds();
    void setChildsAlignemnt(Alignment a);
    void autoSizeChilds(ArduinoGraphics2DCanvas* c);
    bool handleInput(OswHal* hal) override;
    ~OswUiListView(){};
    
  private:
    std::vector<OswUiComponent*> compoments;
    uint16_t count = 0;
    uint16_t selected = 0;
    uint16_t visibleElements = 3;
};

#endif
