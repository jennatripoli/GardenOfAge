#include "Color.h"
#include "EventKeyboard.h"
#include "GameManager.h"
#include "LogManager.h"
#include "ResourceManager.h"
#include "WorldManager.h"
#include "Music.h"

#include "GameStart.h"
#include "game.h"

GameStart::GameStart() {
  setType("GameStart");
  setSprite("gamestart");
  setLocation(df::CENTER_CENTER);
  registerInterest(df::KEYBOARD_EVENT);

  // music = RM.getMusic("start music");
  // playMusic();
}

void GameStart::playMusic() {
  // music->play();
}

// handle event (return 0 if ignored, else return 1)
int GameStart::eventHandler(const df::Event *p_e) {
    if (p_e->getType() == df::KEYBOARD_EVENT) {
        df::EventKeyboard *p_keyboard_event = (df::EventKeyboard *) p_e;
        switch (p_keyboard_event->getKey()) {
        case df::Keyboard::P:  // play
            start();
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
    // music->pause();
    setActive(false);  // when game starts, become inactive
    game::phase1();
}

// override default draw so as not to display "value"
int GameStart::draw() {
  return df::Object::draw();
}
