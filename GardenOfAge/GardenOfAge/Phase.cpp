#include "GameManager.h"
#include "WorldManager.h"
#include "ResourceManager.h"
#include "LogManager.h"
#include "Vector.h"
#include "Event.h"
#include "EventStep.h"

#include "Princess.h"
#include "Knight.h"
#include "Father.h"
#include "Sister.h"
#include "Confidant.h"
#include "Regent.h"

#include "EventEndTurn.h"
#include "EndTurnButton.h"

#include "Phase.h"
#include "MenuSelect.h"
#include "MenuButton.h"
#include "CharacterActionButton.h"
#include "MenuGuide.h"
#include "CharacterButton.h"
#include "BattleComplete.h"

#include <Windows.h>

Phase::Phase(std::string phase_name, Character* ch_1, Character* boss) {
	registerInterest(df::STEP_EVENT);
	registerInterest(END_TURN_EVENT);

	name = phase_name;
	character_menu = new MenuGuide();
	isPhaseDone = false;

	player_party = ch_1;  // add characters 
	phase_boss = boss;       // set phase boss
	LM.writeLog("Phase created");
	//setSprite("menuplay");
	setPosition(df::Vector(45, 19));

	end_btn = new EndTurnButton();
	end_btn->setLocation(9, 9);

	enemy_killcount = 0;
}

bool Phase::isPhaseOver() {
	if (phase_boss->getHP() <= 0) isPhaseDone = true;
	else isPhaseDone = false;

	return isPhaseDone;
}

Phase* Phase::nextPhase() {
	return nullptr;
}

void Phase::loadInfoMenu() {
	
}

void Phase::loadCharacterMenu() {
	// creates and sets all Character buttons
	float x_view = 2;
	float y_view = 8;
	
	Character* temp_character = player_party;
	character_menu->addButton(new CharacterButton(temp_character, df::YELLOW, df::WHITE));		
	character_menu->getButton(0)->setLocation(x_view, y_view);
}

void Phase::completeTurn() {
	turn_queue = player_party->getCharacterMove();
	player_party->setTartget(phase_boss); 
	player_party->characterMoveSet(turn_queue);
}

void Phase::announcements(std::string announce) {
	//MenuSelect* announcement (announce, df::WHITE)
}

int Phase::startNextBoss() {

	if (phase_boss->getHP() == 0)
	{
		WM.markForDelete(phase_boss);

		enemy_killcount++;

		new BattleComplete();
		Sleep(3000);

		player_party = new Princess();

		switch (enemy_killcount) {

		case 1:
			phase_boss = new Confidant();
			break;

		case 2:
			phase_boss = new Father();
			break;

		case 3:
			phase_boss = new Sister();
			break;

		case 4:
			phase_boss = new Regent();
			break;
		}
	}
	return enemy_killcount;
}

// event toggle menu
int Phase::eventHandler(const df::Event* p_e) {
	if (p_e->getType() == END_TURN_EVENT) 
	{
		completeTurn();
		startNextBoss(); 
		LM.writeLog("EndTurn");
	}

	return 0;
}
