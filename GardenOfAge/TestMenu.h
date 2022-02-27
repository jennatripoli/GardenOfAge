#include "MenuButton.h"
#include "MenuGuide.h"
#include "MenuSelect.h"
class TestMenu
{

private:
	MenuButton* test_buttons[3]; 
	MenuGuide* test_guide; 

public: 

	TestMenu();

	//MenuButton Test

	//contructor
	void testButton(); // create button s with colors and different phrases, variables, and placements
	

	//MenuGuide, the  Management System for buttonns and selects

	void testGetMenu(); //add some buttons or select with add menu 

	// loop to toggle Menu on & off based on every 5 seconds for 20 seconds

	//after 40 seconds it'll use clear and clear all of its componenets 
	//it should remain but no buttons nor munuselects


};

