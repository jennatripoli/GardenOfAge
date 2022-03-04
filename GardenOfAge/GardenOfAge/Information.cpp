//#include <Windows.h>

#include "EventKeyboard.h"
#include "GameManager.h"
#include "WorldManager.h"
#include "DisplayManager.h"
#include "LogManager.h"

#include "Information.h"
#include "game.h"
#include "EventStep.h"

#include <Windows.h>

Information::Information(int num) {
    setType("Information");
    registerInterest(df::KEYBOARD_EVENT);
    setActive(true);

    num_screen = num;

    switch (num_screen) {
        // story
    case 1:
        setSprite("exp1");
        LM.writeLog("Information | exp1.");
        break;

        // lyla moves
    case 2:
        setSprite("exp2");
        LM.writeLog("Information | exp2.");
        break;

    default:
        setSprite("exp1");
        LM.writeLog("Information | exp1 (default).");
        break;
    }

    setLocation(df::CENTER_CENTER);
    draw();
    DM.swapBuffers();
}

// handle event (return 0 if ignored, else return 1)
int Information::eventHandler(const df::Event* p_e) {
    if (p_e->getType() == df::KEYBOARD_EVENT) {
        const df::EventKeyboard* p_keyboard_event = dynamic_cast <const df::EventKeyboard*> (p_e);

        switch (p_keyboard_event->getKey()) {
        case df::Keyboard::C:  // continue
            if (num_screen == 1) {
                setActive(false);
                new Information(2);
            }
            break;

        case df::Keyboard::P:  // play
            if (num_screen == 2) {
                setActive(false);
                game::start();
            }
            break;

        case df::Keyboard::Q:  // quit
            GM.setGameOver();
            break;

        default:
            break;
        }
        return 1;
    }

    return 0;  // event ignored
}

// override default draw so as not to display "value"
int Information::draw() {
    return df::Object::draw();
}
