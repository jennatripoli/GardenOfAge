//#include <Windows.h>

#include "DisplayManager.h"
#include "ViewObject.h"
#include "WorldManager.h"
#include "Color.h"

#include "Announcement.h"
#include "MenuSelect.h"

#include <Windows.h>

Announcement::Announcement(std::string m_string, df::Color color, float seconds_paused, bool singular_message) {
	setViewString(m_string);
	setColor(color); 
	setBorder(false);
	setLocation(4.5, 3);

	if (singular_message) {
		setLocation(5, 5);
		draw();
	} else WM.draw();

	DM.swapBuffers();
	Sleep(seconds_paused * 1000);
	
	WM.markForDelete(this);
	WM.update();
}
