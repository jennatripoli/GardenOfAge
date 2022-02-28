#ifndef __ENEMY_H__
#define __ENEMY_H__

#include "Character.h"

class Enemy : public Character {
public:
	Enemy();
	~Enemy();
	int eventHandler(const df::Event* p_e) override;
	int draw() override;
};

#endif __ENEMY_H__
