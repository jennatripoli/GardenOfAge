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

void loadResources(void);
void populateWorld(void);
void testPhase(void);

int main(int argc, char* argv[]) {
	if (GM.startUp()) {
		LM.writeLog("GameManager | startUp() error.");
        GM.shutDown();
        return 0;
	}

	LM.setFlush(true);
	df::splash();
	DM.getWindow()->setMouseCursorVisible(true);  // turn on mouse cursor
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
	RM.loadSprite("sprites/gameover-spr.txt", "gameover");
	RM.loadSprite("sprites/battlecomplete-spr.txt", "battlecomplete");

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

void game::phase1() {
	testPhase();
}

void testPhase(void) {
	// runs a phase
	Princess* Lyla = new Princess();
	Knight* LittleKnight = new Knight();

	Phase* test_phase = new Phase("test phase", Lyla, LittleKnight);
	test_phase->loadCharacterMenu();
}
