#ifndef __FATHER_H__
#define __FATHER_H__

#include "Character.h"

class Father : public Character {
public:
	Father();
	int eventHandler(const df::Event* p_e) override;
	int draw() override;
	int characterMoveSet(int choice) override;
	int decideMove() override; 

	void attackWoeIsMe();
	void attackWoeIsYou();
	void attackTheEnd();
};

#endif __FATHER_H__
