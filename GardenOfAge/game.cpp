#include "GameManager.h"
#include "LogManager.h"
#include "Pause.h"
#include "ResourceManager.h"
#include "DisplayManager.h"
#include <Windows.h>

#include "GameStart.h"
#include "MenuSelect.h"

void loadResources(void);
void populateWorld(void);

int main(int argc, char* argv[]) {
    // start up GameManager
	if (GM.startUp()) {
		LM.writeLog("GameManager | startUp() error.");
        GM.shutDown();
        return 0;
	}

	LM.setFlush(true);
	df::splash();

	loadResources();
	populateWorld();

	new df::Pause(df::Keyboard::F10);

	MenuSelect* menu = new MenuSelect("Hello, world!", df::YELLOW, NULL);
	menu->setLocation(1, 1);
	menu->draw();
	DM.swapBuffers();
	Sleep(1000);

    //GM.run();
    //GM.shutDown();

	return 0;
}

// Load resources (sprites, sound effects, music).
void loadResources(void) {
  RM.loadSprite("sprites/saucer-spr.txt", "saucer");
  RM.loadSprite("sprites/ship-spr.txt", "ship");
  RM.loadSprite("sprites/bullet-spr.txt", "bullet");
  RM.loadSprite("sprites/explosion-spr.txt", "explosion");
  RM.loadSprite("sprites/gamestart-spr.txt", "gamestart");
  RM.loadSprite("sprites/gameover-spr.txt", "gameover");
  RM.loadSound("sounds/fire.wav", "fire");
  RM.loadSound("sounds/explode.wav", "explode");
  RM.loadSound("sounds/nuke.wav", "nuke");
  RM.loadSound("sounds/game-over.wav", "game over");
  RM.loadMusic("sounds/start-music.wav", "start music");
}

// Populate world with some objects.
void populateWorld(void) {

  // Create GameStart object.
  new GameStart();
}
