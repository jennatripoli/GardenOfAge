#include "Color.h"
#include "EventKeyboard.h"
#include "GameManager.h"
#include "LogManager.h"
#include "ResourceManager.h"
#include "WorldManager.h"
#include "DisplayManager.h"

#include "BattleComplete.h"
#include "Music.h"
#include "game.h"
#include "Phase.h"

#include <Windows.h>

BattleComplete::BattleComplete() {
    setType("BattleComplete");

    // link to gamestart sprite
    setSprite("battlecomplete");

    // put in center of screen
    setLocation(df::CENTER_CENTER);

    // play start music
    // p_music = RM.getMusic("start music");
    // playMusic();

    df::ObjectList object_list = WM.getAllObjects(true);
    df::ObjectListIterator i(&object_list);

    for (i.first(); !i.isDone(); i.next()) {
        df::Object* p_o = i.currentObject();

        if (p_o->getType() == "Character" || p_o->getType() == "ViewObject"
            || p_o->getType() == "MenuButton") WM.markForDelete(p_o);
    }

    draw();
    DM.swapBuffers();
    Sleep(3000);
    setActive(false);
    WM.markForDelete(this);
}

void BattleComplete::playMusic() {
    //p_music->play();
}

// override default draw so as not to display "value"
int BattleComplete::draw() {
    return df::Object::draw();
}
