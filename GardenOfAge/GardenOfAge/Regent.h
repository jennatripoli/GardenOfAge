#ifndef __REGENT_H__
#define __REGENT_H__

#include "Character.h"

class Regent : public Character {

private:
	int countdown;
	
public:
	Regent();
	int eventHandler(const df::Event* p_e) override;
	int draw() override;
	int characterMoveSet(int choice) override;

	int decideMove() override;

	void famineOfWeeds(); 
	void respectMyrule();
	void areYouEvenWorthy();



};

#endif __REGENT_H__
