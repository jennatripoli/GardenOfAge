#ifndef __PHASE_H__
#define __PHASE_H__

#include "Object.h"
#include "Event.h"
#include "MenuGuide.h"
#include "Character.h"

class Phase :public df::Object {
private:
	Phase();
	std::string name;
	bool isPhaseOver();
	bool isPhaseDone;
	std::string* turn_queue[3];
	Character* player_party[3];

	Character* phase_boss;
	MenuGuide* character_menu;
	MenuGuide* info_menu;
	Phase* nextPhase();

public:
	// will modify later to have more characters to load
	Phase(std::string phase_name, Character* ch_1, Character* boss);
	void loadInfoMenu();
	void loadCharacterMenu();

	void completeTurn();
	void announcements(std::string announce);

	int startNextPhase();
	int eventHandler(const df::Event* p_e);
};

#endif  __PHASE_H__