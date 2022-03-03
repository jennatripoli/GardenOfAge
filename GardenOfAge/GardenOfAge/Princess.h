#ifndef __PRINCESS_H__
#define __PRINCESS_H__

#include "Character.h"

class Princess : public Character {
private:
	bool isIronfast; 
	bool isBraveHearty;
	bool isOfKinderedSpirit;
	bool isTheRightfulHeir;
	
public:
	Princess();
	int eventHandler(const df::Event* p_e) override;
	int draw() override;
	int characterMoveSet(int choice) override;

	bool getIsIronFast() const;
	bool getIsBraveHearty() const;
	bool getisOfKinderedSpirit() const; 
	bool getisTheRightfulHeir() const; 

	void Caliburn();
	void GildedShield();
	void Honorless();
	void HolyLight();
};

#endif __PRINCESS_H__
