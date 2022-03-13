#ifndef __CONFIDANT_H__
#define __CONFIDANT_H__

#include "Character.h"

class Confidant : public Character {
public:
	Confidant();
	int eventHandler(const df::Event* p_e) override;
	int draw() override;
	int moveSet(int choice) override;
	int decideMove() override;
	
	void attackProtect();
	void attackBetray(); 
	void attackRealization(); 
};

#endif __CONFIDANT_H__
