#ifndef OSW_UI_LISTVIEW_H
#define OSW_UI_LISTVIEW_H

#include "ui/drawable.h"
#include <vector>

enum Alignment{
  Center,
  Left
};

class OswUiListView : public OswUiDrawable{
  public:
    OswUiListView(uint16_t posX, uint16_t posY) : OswUiDrawable(posX, posY){};
    virtual void draw(ArduinoGraphics2DCanvas* c);
    virtual void calculate(ArduinoGraphics2DCanvas* c);
    void add(OswUiDrawable* d);
    void setAlignment(Alignment a);
    ~OswUiListView(){};
    
  private:
    std::vector<OswUiDrawable*> drawables;
    int16_t count = 0;
    int16_t selected = 0;
    int16_t visibleElements = 3;
    Alignment alignment;
};

#endif
