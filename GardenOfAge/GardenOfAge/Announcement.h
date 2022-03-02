#ifndef __ANNOUNCEMENT_H__
#define __ANNOUNCEMENT_H__

#include "Object.h"
#include "Event.h"
#include "ViewObject.h"
#include "Color.h"

#include "MenuSelect.h"

// base class for player to select option of menu
class Announcement : public MenuSelect {
private:
public:
	Announcement(std::string m_string, df::Color color = df::WHITE , float seconds_paused = 1.2f, bool singular_message = false);
 

};

#endif __ANNOUNCEMENT_H__
