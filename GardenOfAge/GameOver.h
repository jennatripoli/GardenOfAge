#ifndef __GAME_OVER_H__
#define __GAME_OVER_H__

#include "ViewObject.h"

class GameOver : public df::ViewObject {
private:
	int time_to_live;
	void step();

public:
	GameOver(bool isVictory = false);
	~GameOver();
	int eventHandler(const df::Event *p_e) override;
	int draw() override;
};

#endif __GAME_OVER_H__