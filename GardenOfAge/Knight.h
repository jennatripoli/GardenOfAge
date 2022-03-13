#ifndef __KNIGHT_H__
#define __KNIGHT_H__

#include "Character.h"

class Knight : public Character {
private:
	int priorMove;

public:
	Knight();
	int eventHandler(const df::Event* p_e) override;
	int draw() override;
	int characterMoveSet(int choice) override;
	int decideMove() override;

	void attackArrows();
	void attackStruggle();
	void attackComrades();
	void attackIsHonorless();
	void attackNoSavior(); 
};

#endif __KNIGHT_H__
