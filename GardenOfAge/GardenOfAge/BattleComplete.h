#ifndef __BATTLE_COMPLETE_H__
#define __BATTLE_COMPLETE_H__

#include "Music.h"
#include "ViewObject.h"

class BattleComplete : public df::ViewObject {
private:
	df::Music* p_music;

public:
	BattleComplete();
	int draw() override;
	void playMusic();
};

#endif __BATTLE_COMPLETE_H__
