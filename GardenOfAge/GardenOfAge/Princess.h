#ifndef __PRINCESS_H__
#define __PRINCESS_H__

#include "Character.h"

class Princess : public Character {
private:
//all princess moves counters/multiplyers
	bool isIronfast; 
	bool isBraveHearty;
	bool isOfKinderedSpirit;
	bool isTheRightfulHeir;
	
public:
	Princess();
	~Princess();
	int eventHandler(const df::Event* p_e) override;
	int draw() override;
	int characterMoveSet(int choice) override;
	 


	

	void Caliburn();
	void GildedSheild();
	void Honorless();
	void HolyLight(); //3 turn gradual heal
};

#endif __PRINCESS_H__
