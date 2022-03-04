#ifndef __INFORMATION_H__
#define __INFORMATION_H__

#include "ViewObject.h"

class Information : public df::ViewObject {
private:
	Information();
	int num_screen;

public:
	Information(int num);
	int eventHandler(const df::Event* p_e) override;
	int draw() override;
};

#endif __INFORMATION_H__