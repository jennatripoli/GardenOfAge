#ifndef __FATHER_H__
#define __FATHER_H__

#include "Character.h"

class Father : public Character {
private:
public:
	Father();
	int eventHandler(const df::Event* p_e) override;
	int draw() override;
	int characterMoveSet(int choice) override;
	

	int decideMove() override; 
	void woeIsMe(); //1
	void woeIsYou(); //2
	void theEnd(); //3
	
	
};

#endif __FATHER_H__
