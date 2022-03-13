#ifndef __PRINCESS_H__
#define __PRINCESS_H__

#include "Character.h"

class Princess : public Character {
private:
	bool isIronfast; 
	bool isBraveHearty;
	bool isOfKinderedSpirit;
	bool isTheRightfulHeir;
	bool trueRuler;
	bool isVictor;
	
public:
	Princess();
	int eventHandler(const df::Event* p_e) override;
	int draw() override;
	int characterMoveSet(int choice) override;
	void setVictory(bool state);

	bool getIsIronFast() const;
	bool getIsBraveHearty() const;
	bool getisOfKinderedSpirit() const; 
	bool getisTheRightfulHeir() const;
	void setTrueRuler(bool state);

	void attackCaliburn();
	void attackGildedShield();
	void attackHonorless();
	void attackHolyLight();
};

#endif __PRINCESS_H__
