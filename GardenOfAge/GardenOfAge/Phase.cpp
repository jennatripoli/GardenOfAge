#include "GameManager.h"
#include "LogManager.h"
#include "Event.h"
#include "EventStep.h"
#include "EventToggleMenu.h"
#include "Phase.h"
#include "MenuSelect.h"
#include "MenuButton.h"
#include "CharacterActionButton.h"
#include "MenuGuide.h"
#include "CharacterButton.h"

Phase::Phase(std::string phase_name, Character* ch_1, Character* boss) {
	registerInterest(df::STEP_EVENT);
	name = phase_name;
	character_menu = new MenuGuide();
	isPhaseDone = false;

	player_party[0] = ch_1;  // add characters 
	phase_boss = boss;       // set phase boss
	LM.writeLog("Phase created");
}

bool Phase::isPhaseOver() {
	if (phase_boss->getHP() <= 0)
		isPhaseDone = true;
	else
		isPhaseDone = false;

	return isPhaseDone;
}

Phase* Phase::nextPhase() {
	return nullptr;
}

void Phase::loadInfoMenu() {
	CharacterActionButton* option1 = new CharacterActionButton(7, phase_boss, player_party[0], "Attack Princess 7");
	option1->setLocation(5, 7);

	CharacterActionButton* option2 = new CharacterActionButton(13, player_party[0], phase_boss, "Attack Knight 13");
	option2->setLocation(8, 7);

	//(int action_worth, Character * ch, Character * enemy, std::string m_string)
		/*for (int party_count = 0; party_count < 1; party_count++) {
			const CharacterButton* temp_chb = dynamic_cast <const CharacterButton*> (character_menu->getButton(party_count));
			if (temp_chb->isDisplayed()) temp_chb->getCharacter();
		}*/
}

void Phase::loadCharacterMenu() {
	// creates and sets all Character buttons
	float x_view = 2;
	float y_view = 7;
	for (int party_count = 0; party_count < 1; party_count++) {
		Character* temp_character = player_party[party_count];
		character_menu->addButton(new CharacterButton(temp_character, df::YELLOW, df::WHITE));
		character_menu->getButton(party_count)->setLocation(x_view, y_view);
		y_view++;
	}
}

void Phase::completeTurn() {
}

void Phase::announcements(std::string announce) {
	//MenuSelect* announcement (announce, df::WHITE)
}

int Phase::startNextPhase() {
	return 0;
}

// event toggle menu
int Phase::eventHandler(const df::Event* p_e) {
	if (p_e->getType() == MENU_TOGGLE_EVNT) {
	}

	return 0;
}
