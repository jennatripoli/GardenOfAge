#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "Object.h"

class Character : public df::Object {
private:
	int hp;
public:
	Character();
	virtual int eventHandler(const df::Event* p_e);
	virtual int draw();
	int getHP();
	void setHP(int new_hp);
};
#endif __CHARACTER_H__
