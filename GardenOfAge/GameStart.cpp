//#include <Windows.h>

#include "Color.h"
#include "EventKeyboard.h"
#include "GameManager.h"
#include "LogManager.h"
#include "ResourceManager.h"
#include "DisplayManager.h"
#include "WorldManager.h"
#include "Music.h"

#include "GameStart.h"
#include "game.h"
#include "Information.h"

#include <Windows.h>

GameStart::GameStart() {
  setType("GameStart");
  setSprite("gamestart");
  setLocation(df::CENTER_CENTER);
  registerInterest(df::KEYBOARD_EVENT);

  music = RM.getMusic("gamestart");
  playMusic();
}

void GameStart::playMusic() {
  music->play();
}

// handle event (return 0 if ignored, else return 1)
int GameStart::eventHandler(const df::Event *p_e) {
    if (p_e->getType() == df::KEYBOARD_EVENT) {
        const df::EventKeyboard* p_keyboard_event = dynamic_cast <const df::EventKeyboard*> (p_e);

        switch (p_keyboard_event->getKey()) {
        case df::Keyboard::P:  // play
            music->pause();
            setActive(false);
            p_e = NULL;
            new Information(1);
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

void GameStart::start() {
    music->pause();    
    setActive(false);  // when game starts, become inactive
    game::start();
}

// override default draw so as not to display "value"
int GameStart::draw() {
  return df::Object::draw();
}
