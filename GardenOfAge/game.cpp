#include "GameManager.h"
#include "LogManager.h"
#include "Pause.h"
#include "ResourceManager.h"
#include "DisplayManager.h"
#include <Windows.h>

#include "GameStart.h"
#include "MenuSelect.h"
#include "Tank.h"
#include "EventDamage.h"

void loadResources(void);
void populateWorld(void);
void tests(void);

int main(int argc, char* argv[]) {
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

	tests();

    //GM.run();
    GM.shutDown();

	return 0;
}

void tests(void) {
	// test MenuSelect can display
	/*MenuSelect* menu = new MenuSelect("Hello, world!", df::YELLOW, NULL);
	menu->setLocation(1, 1);
	menu->draw();
	DM.swapBuffers();
	Sleep(1000);*/

	// test Tank can display
	/*Tank* t = new Tank();
	t->setPosition(df::Vector(10, 10));
	t->draw();
	t->drawHP();
	DM.swapBuffers();
	Sleep(1000);*/

	// test Tank can change hp
	/*t->takeDamage(10);
	t->draw();
	t->drawHP();
	DM.swapBuffers();
	Sleep(1000);*/

	// test sending an EventDamage to Tank
	/*EventDamage* d = new EventDamage(20);
	t->eventHandler(d);
	t->draw();
	t->drawHP();
	DM.swapBuffers();
	Sleep(1000);*/

	// test sending EventDamage from one Tank to another Tank
	Tank* t1 = new Tank();
	Tank* t2 = new Tank();
	t1->setPosition(df::Vector(10, 10));
	t2->setPosition(df::Vector(20, 10));
	t1->draw();
	t2->draw();
	DM.swapBuffers();
	Sleep(1000);
	t1->dealDamage(10, t2);
	t1->draw();
	t2->draw();
	DM.swapBuffers();
	Sleep(1000);
}

// load resources (sprites, sound effects, music)
void loadResources(void) {
	RM.loadSprite("sprites/menu-play-spr.txt", "menu-play");
}

// populate world with objects
void populateWorld(void) {
	new GameStart();
}
