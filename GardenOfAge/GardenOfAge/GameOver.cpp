#include "EventStep.h"
#include "LogManager.h"
#include "ResourceManager.h"
#include "WorldManager.h"
#include "DisplayManager.h"

#include "GameOver.h"
#include "GameStart.h"

GameOver::GameOver(bool isVictory) {
	setType("GameOver");
	setLocation(df::CENTER_CENTER);
	registerInterest(df::STEP_EVENT);

	std::string setting;

	if (isVictory) setting = "victory"; else setting = "gameover";
	
	if (setSprite(setting) == 0) time_to_live = getAnimation().getSprite()->getFrameCount() * getAnimation().getSprite()->getSlowdown();
	else time_to_live = 0;

	df::Sound *sound = RM.getSound("gameover");
	sound->play();
}

// when done, remove all Objects and reactivate GameStart
GameOver::~GameOver() {
	df::ObjectList object_list = WM.getAllObjects(true);
	df::ObjectListIterator i(&object_list);

	for (i.first(); !i.isDone(); i.next()) {
		df::Object* p_o = i.currentObject();

		///if (p_o->getType() == "Character" || p_o->getType() == "ViewObject" || p_o->getType() == "MenuButton" || p_o->getType() == "MenuSelect") {
		///	i.currentObject()->setActive(false);
		///	WM.markForDelete(p_o);
		//}

		if (p_o->getType() != "GameStart") {
			i.currentObject()->setActive(false);
			WM.markForDelete(p_o);
			WM.update();
		}

		// if GameStart, set as active
		if (p_o->getType() == "GameStart") {
			p_o->setActive(true);
			dynamic_cast <GameStart*> (p_o)->playMusic();	// resume start music
		}
	}
}

// handle event (return 0 if ignored, else return 1)
int GameOver::eventHandler(const df::Event* p_e) {
	if (p_e->getType() == df::STEP_EVENT) {
		step();
		return 1;
	}

	return 0;  // event ignored
}

// count down to end of message
void GameOver::step() {
	time_to_live--;
	if (time_to_live <= 0) WM.markForDelete(this);
}

// override default draw so as not to display "value"
int GameOver::draw() {
	return df::Object::draw();
}
