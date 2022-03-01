#include "GameManager.h"
#include "LogManager.h"
#include "Pause.h"
#include "ResourceManager.h"
#include "DisplayManager.h"
#include "WorldManager.h"
#include <Windows.h>

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
	RM.loadSprite("sprites/menuplay-spr.txt", "menuplay");
	RM.loadSprite("sprites/gamestart-spr.txt", "gamestart");
	RM.loadSprite("sprites/princess-spr.txt", "princess");
	RM.loadSprite("sprites/knight-spr.txt", "knight");
	RM.loadSprite("sprites/father-spr.txt", "father");
	RM.loadSprite("sprites/generic-spr.txt", "generic");
}

// populate world with objects
void populateWorld(void) {
	new GameStart();
}

void game::phase1() {
	testPhase();
}

void testPhase(void) {
	//runs a phase
	Princess* Lyla = new Princess();
	Lyla->setPosition(df::Vector(20, 5));
	Lyla->setHP(50);

	Knight* LittleKnight = new Knight();
	LittleKnight->setPosition(df::Vector(60, 5));
	LittleKnight->setHP(200);

	Phase* test_phase = new Phase("test phase", Lyla, LittleKnight);
	test_phase->loadCharacterMenu();
	test_phase->loadInfoMenu();
}
