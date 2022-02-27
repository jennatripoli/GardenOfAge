#include "TestMenu.h"
#include "LogManager.h"
#include "MenuButton.h"
#include "MenuSelect.h"
#include "Color.h"
TestMenu::TestMenu()
//run the contructor in the game.cpp and everything in the comments should follow out
// with it toggling off and on every 10 seconds
//when on you can click on eveything excpt fo the 6,6 th spot
//and everyiing being cleared on the 40th seconds
{ 
	test_guide = new MenuGuide(); 
	testButton();
	testGetMenu();
}


//creation of simple buttons to press/highlight and find button cliked in log

void TestMenu::testButton()
{
	test_buttons[0] = new MenuButton("Button", df::CYAN, df::RED, 1);
	test_buttons[0]->setLocation(3, 3);

	test_buttons[1] = new MenuButton("ClickME", df::MAGENTA, df::GREEN, 9);
	test_buttons[1]->setLocation(4, 4);

	test_buttons[2] = new MenuButton("Button", df::YELLOW, df::WHITE);
	test_buttons[2]->setLocation(5, 5);
}

// puts all prior menus and buttons in a menu_guide
void TestMenu::testGetMenu()
{
	for (int i = 0; i < 4;i++)
	{
		if (i!=3)
		test_guide->addButton(test_buttons[i]); 
		else
		{
			MenuSelect* t_s = new MenuSelect("MenuSelect", df::Color::BLUE, 101);
			t_s->setLocation(6, 6); 
			test_guide->addMenu(t_s);
		}
	}
}

//menu guide through its event handler will toggle every 10 seconds
//clear itself out on 40 seconds
