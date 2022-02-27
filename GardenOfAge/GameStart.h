#ifndef __GAME_START_H__
#define __GAME_START_H__

#include "Music.h"
#include "ViewObject.h"

class GameStart : public df::ViewObject {
private:
	df::Music *p_music;
	void start();

public:
	GameStart();
	int eventHandler(const df::Event *p_e) override;
	int draw() override;
	void playMusic();
};

#endif __GAME_START_H__
