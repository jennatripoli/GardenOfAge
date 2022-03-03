#include <Windows.h>

#include "GameManager.h"
#include "WorldManager.h"
#include "DisplayManager.h"
#include "ResourceManager.h"
#include "LogManager.h"
#include "Vector.h"
#include "Event.h"
#include "EventStep.h"

#include "EventEndTurn.h"
#include "EndTurnButton.h"
#include "EventStartTurn.h"
#include "EventEnemyTurn.h"
#include "Princess.h"
#include "Knight.h"
#include "Father.h"
#include "Sister.h"
#include "Confidant.h"
#include "Regent.h"
#include "Phase.h"
#include "MenuSelect.h"
#include "MenuButton.h"
#include "CharacterActionButton.h"
#include "MenuGuide.h"
#include "CharacterButton.h"
#include "BattleComplete.h"
#include "Announcement.h"

//#include <Windows.h>

Phase::Phase(std::string phase_name, Character* ch_1, Character* boss) {
	registerInterest(df::STEP_EVENT);
	registerInterest(END_TURN_EVENT);
	registerInterest(START_TURN_EVENT);

	name = phase_name;
	character_menu = new MenuGuide();
	is_phase_done = false;

	player_party = ch_1;  // add characters 
	phase_boss = boss;    // set phase boss
	LM.writeLog("Phase %s created.", phase_name);

	end_btn = new EndTurnButton();
	end_btn->setLocation(5,1.5);

	enemy_killcount = 0;
}

bool Phase::isPhaseOver() {
	if (phase_boss->getHP() <= 0) is_phase_done = true;
	else is_phase_done = false;

	return is_phase_done;
}

void Phase::loadCharacterMenu() {
	// creates and sets all Character buttons
	float x_view = 2;
	float y_view = 8;
	
	character_menu->addButton(new CharacterButton(player_party, df::YELLOW, df::WHITE));
	character_menu->getButton(0)->setLocation(x_view, y_view);
}

void Phase::completeTurn() {
	turn_queue = player_party->getCharacterMove();
	player_party->setTarget(phase_boss); 
	player_party->characterMoveSet(turn_queue);
}

void Phase::announcements(std::string announce) {
	// MenuSelect* announcement (announce, df::WHITE)
}

int Phase::startNextBoss() {
	
		//Sleep(500);
		Princess* princess = dynamic_cast <Princess*> (player_party);

		phase_boss->draw();
		DM.swapBuffers();
		Sleep(500);
		WM.markForDelete(phase_boss);
		WM.update();
		enemy_killcount++;
		new BattleComplete();
		Sleep(2000);


		if (enemy_killcount == 4)
		{
			princess->setTrueRuler(true);
			princess->setHP(80);
			Announcement* sm1 = new Announcement("Sister", df::GREEN, 3, true);
			Announcement* sm2 = new Announcement("You're no longer a baby green to be harvested...", df::GREEN, 3, true);
			Announcement* sm3 = new Announcement("WWhen you face him", df::GREEN, 3, true);
			Announcement* sm4 = new Announcement("The future is made by seeds of the past and ", df::GREEN, 3, true);
		}
		// player_party = new Princess();

		switch (enemy_killcount) {
		case 1:
			phase_boss = new Confidant();
			player_party->setTarget(phase_boss);
			phase_boss->setTarget(player_party); 
			break;
		case 2:
			phase_boss = new Father();
			phase_boss->setTarget(player_party);
			player_party->setTarget(phase_boss);
			break;
		case 3:
			phase_boss = new Sister();
			player_party->setTarget(phase_boss);
			phase_boss->setTarget(player_party);
			break;
		case 4:
			phase_boss = new Regent();
			player_party->setTarget(phase_boss);
			phase_boss->setTarget(player_party);			
			break;
		}
	

	return enemy_killcount;
}

// handle event (return 0 if ignored, else return 1)
int Phase::eventHandler(const df::Event* p_e) {
	if (p_e->getType() == START_TURN_EVENT) {		
		end_btn->setActive(true);
		WM.draw();
		DM.swapBuffers(); 
		return 1;
	}
	
	if (p_e->getType() == END_TURN_EVENT) {
		completeTurn();
		if(phase_boss->getHP() == 0)
			startNextBoss(); 		
		
		LM.writeLog("Phase | end turn.");

		EventEnemyEndTurn* nextTurn = new EventEnemyEndTurn(); 
		phase_boss->setTarget(player_party); 
		phase_boss->eventHandler(nextTurn);
		return 1;
	}

	return 0;  // event ignored
}
