#include <Windows.h>

#include "Color.h"
#include "EventKeyboard.h"
#include "GameManager.h"
#include "LogManager.h"
#include "ResourceManager.h"
#include "WorldManager.h"
#include "DisplayManager.h"

#include "BattleComplete.h"
#include "Music.h"
#include "Phase.h"

//#include <Windows.h>

BattleComplete::BattleComplete() {
    setType("BattleComplete");
    setSprite("battlecomplete");
    setLocation(df::CENTER_CENTER);

    sound = RM.getSound("battlecomplete");
    playSound();

    df::ObjectList object_list = WM.getAllObjects(true);
    df::ObjectListIterator i(&object_list);

    // set all relevant Objects on screen to inactive
    for (i.first(); !i.isDone(); i.next()) {
        df::Object* p_o = i.currentObject();

        if (p_o->getType() == "Character" || p_o->getType() == "ViewObject" || p_o->getType() == "MenuButton" || p_o->getType() == "MenuSelect") {
            i.currentObject()->setActive(false);
            //WM.markForDelete(p_o);
        }
    }

    // draw BattleComplete on screen
    draw();
    DM.swapBuffers();
    Sleep(3000);
    setActive(false);
    WM.markForDelete(this);

    // set all relevant Objects on screen to active
    for (i.first(); !i.isDone(); i.next()) {
        df::Object* p_o = i.currentObject();

        if (p_o->getType() == "Character" || p_o->getType() == "ViewObject" || p_o->getType() == "MenuButton" || p_o->getType() == "MenuSelect") {
            i.currentObject()->setActive(true);
        }
    }

    WM.draw();
    DM.swapBuffers(); 
}

void BattleComplete::playSound() {
    sound->play();
}

// override default draw so as not to display "value"
int BattleComplete::draw() {
    return df::Object::draw();
}
