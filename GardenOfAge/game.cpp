#include "GameManager.h"
#include "LogManager.h"
#include "Pause.h"
#include "ResourceManager.h"
#include "DisplayManager.h"
#include "WorldManager.h"
#include <Windows.h>

#include "GameStart.h"
#include "MenuSelect.h"
#include "Tank.h"
#include "EventDamage.h"
#include "MenuGuide.h"
#include "game.h"
#include "Princess.h"
#include "Enemy.h"

void loadResources(void);
void populateWorld(void);
void tests(void);
void testMenu(void);

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

void game::phase1() {
	//testMenu();
	Princess* p = new Princess();
	p->setPosition(df::Vector(20, 10));
	Enemy* e = new Enemy();
	e->setPosition(df::Vector(60, 10));

	p->dealDamage(10, e);
	e->dealDamage(20, p);
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
	/*Tank* t1 = new Tank();
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
	Sleep(1000);*/
}

void testMenu(void) {
	MenuGuide* m = new MenuGuide();
	MenuButton* test_buttons[3];

	// creation of simple buttons to press/highlight and find button pressed in log
	test_buttons[0] = new MenuButton("Button", df::CYAN, df::RED, 1);
	test_buttons[0]->setLocation(3, 3);

	test_buttons[1] = new MenuButton("ClickME", df::MAGENTA, df::GREEN, 9);
	test_buttons[1]->setLocation(4, 4);

	test_buttons[2] = new MenuButton("Button", df::YELLOW, df::WHITE);
	test_buttons[2]->setLocation(5, 5);

	for (int i = 0; i < 4; i++) {
		if (i != 3) m->addButton(test_buttons[i]);
		else {
			MenuSelect* t_s = new MenuSelect("MenuSelect", df::Color::BLUE, 101);
			t_s->setLocation(6, 6);
			m->addMenu(t_s);
		}
	}
}

// load resources (sprites, sound effects, music)
void loadResources(void) {
	RM.loadSprite("sprites/menuplay-spr.txt", "menuplay");
	RM.loadSprite("sprites/gamestart-spr.txt", "gamestart");
	RM.loadSprite("sprites/princess-spr.txt", "princess");
	RM.loadSprite("sprites/generic-spr.txt", "generic");
}

// populate world with objects
void populateWorld(void) {
	new GameStart();
}
