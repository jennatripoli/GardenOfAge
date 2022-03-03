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
	//all moves
	void arrows();//1
	void struggle();//2
	void comrades(); //3
	void areHonorless(); //4
	void noSavior(); //5th
};

#endif __KNIGHT_H__
