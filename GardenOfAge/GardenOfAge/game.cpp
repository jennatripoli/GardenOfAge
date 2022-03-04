#include "GameManager.h"
#include "LogManager.h"
#include "Pause.h"
#include "ResourceManager.h"
#include "DisplayManager.h"
#include "WorldManager.h"

#include "GameStart.h"
#include "MenuSelect.h"
#include "EventDamage.h"
#include "MenuGuide.h"
#include "game.h"
#include "Phase.h"
#include "Princess.h"
#include "Knight.h"
#include "Regent.h"

void loadResources(void);
void populateWorld(void);

int main(int argc, char* argv[]) {
	if (GM.startUp()) {
		LM.writeLog("GameManager | startUp() error.");
        GM.shutDown();
        return 0;
	}

	LM.setFlush(true);
	df::splash();
	DM.getWindow()->setMouseCursorVisible(true);
	new df::Pause(df::Keyboard::F10);

	loadResources();
	populateWorld();

    GM.run();
    GM.shutDown();

	return 0;
}

// load resources (sprites, sound effects, music)
void loadResources(void) {
	RM.loadSprite("sprites/gamestart-spr.txt", "gamestart");
	RM.loadSprite("sprites/exp1-spr.txt", "exp1");
	RM.loadSprite("sprites/exp2-spr.txt", "exp2");
	RM.loadSprite("sprites/gameover-spr.txt", "gameover");
	RM.loadSprite("sprites/victory-spr.txt", "gameover");
	RM.loadSprite("sprites/battlecomplete-spr.txt", "victory");

	RM.loadSprite("sprites/princess-spr.txt", "princess");
	RM.loadSprite("sprites/knight-spr.txt", "knight");
	RM.loadSprite("sprites/confidant-spr.txt", "confidant");
	RM.loadSprite("sprites/father-spr.txt", "father");
	RM.loadSprite("sprites/sister-spr.txt", "sister");
	RM.loadSprite("sprites/regent-spr.txt", "regent");

	RM.loadSprite("sprites/generic-spr.txt", "generic");
	RM.loadSprite("sprites/menuplay-spr.txt", "menuplay");
	RM.loadSprite("sprites/explosion-spr.txt", "explosion");

	RM.loadSound("sounds/damage.wav", "damage");
	RM.loadSound("sounds/battlecomplete.wav", "battlecomplete");
	RM.loadSound("sounds/gameover.wav", "gameover");
	RM.loadMusic("sounds/gamestart.wav", "gamestart");

}

// populate world with objects
void populateWorld(void) {
	new GameStart();
}

// start the game
void game::start(void) {
	Phase* phase = new Phase("Start Lyla's Battles");
	phase->loadCharacterMenu();
}
