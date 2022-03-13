#ifndef __BATTLE_COMPLETE_H__
#define __BATTLE_COMPLETE_H__

#include "Sound.h"
#include "ViewObject.h"

class BattleComplete : public df::ViewObject {
private:
	df::Sound* sound;

public:
	BattleComplete();
	int draw() override;
	void playSound();
};

#endif __BATTLE_COMPLETE_H__
