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

GameStart::GameStart() {
  setType("GameStart");
  setSprite("game-start");
  setLocation(df::CENTER_CENTER);
  registerInterest(df::KEYBOARD_EVENT);
  num_ofscreens = 3;

  music = RM.getMusic("gamestart");
  playMusic();
}

void GameStart::playMusic() {
  music->play();
}

// handle event (return 0 if ignored, else return 1)
int GameStart::eventHandler(const df::Event *p_e) {
    if (p_e->getType() == df::KEYBOARD_EVENT) {
        df::EventKeyboard *p_keyboard_event = (df::EventKeyboard *) p_e;
        switch (p_keyboard_event->getKey()) {
        case df::Keyboard::P:  // play

            num_ofscreens--; //traverse screens
            if (num_ofscreens > 0)
            {
                if (num_ofscreens == 2)
                 setSprite("exp1");
                if (num_ofscreens == 1)
                     setSprite("exp2"); 

                    draw();
                    DM.swapBuffers(); 
                    start();
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

void GameStart::start() {
    music->pause();
    setActive(false);  // when game starts, become inactive
    game::phase1();
}

// override default draw so as not to display "value"
int GameStart::draw() {
  return df::Object::draw();
}
