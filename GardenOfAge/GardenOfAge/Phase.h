#ifndef __PHASE_H__
#define __PHASE_H__

#include "Object.h"
#include "Event.h"
#include "MenuGuide.h"
#include "Character.h"
#include "EndTurnButton.h"

class Phase :public df::Object {
private:
	Phase();
	bool isPhaseOver();

	std::string name;
	bool is_phase_done;
	int turn_queue;
	Character* player_party;

	Character* phase_boss;
	int enemy_killcount;
	MenuGuide* character_menu;
	MenuGuide* info_menu;
	EndTurnButton* end_btn;

public:
	Phase(std::string phase_name);
	void loadCharacterMenu();

	void completeTurn();
	void announcements(std::string announce);

	int startNextBoss();
	int eventHandler(const df::Event* p_e);
};

#endif  __PHASE_H__
