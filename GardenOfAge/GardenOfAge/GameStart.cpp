#include "Color.h"
#include "EventKeyboard.h"
#include "GameManager.h"
#include "LogManager.h"
#include "ResourceManager.h"
#include "WorldManager.h"

#include "GameStart.h"
#include "Music.h"
#include "game.h"

GameStart::GameStart() {
  setType("GameStart");

  // link to gamestart sprite
  setSprite("gamestart");

  // put in center of screen
  setLocation(df::CENTER_CENTER);

  // register for keyboard event
  registerInterest(df::KEYBOARD_EVENT);

  // play start music
  // p_music = RM.getMusic("start music");
  // playMusic();
}

// play start music
void GameStart::playMusic() {
  //p_music->play();
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
    //p_music->pause();  // pause start music
    setActive(false);  // when game starts, become inactive
    game::phase1();
}

// override default draw so as not to display "value"
int GameStart::draw() {
  return df::Object::draw();
}
