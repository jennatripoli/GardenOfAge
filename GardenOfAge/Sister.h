#ifndef __SISTER_H__
#define __SISTER_H__

#include "Character.h"

class Sister : public Character {
private:
	bool power_track;

public:
	Sister();
	int eventHandler(const df::Event* p_e) override;
	int draw() override;
	int moveSet(int choice) override;
	int decideMove() override;

	void attackGatheringMagic();	
	void attackTaunt();
	void attackElusiveStrike();
};

#endif __SISTER_H__
