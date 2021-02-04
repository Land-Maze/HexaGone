#include <iostream>
#include <fstream>
#include "Addons/drawing.hpp"
#include "Addons/logical.hpp"
#pragma once

int main()
{
	initscr();
	clear();
    keypad(stdscr,1);
	noecho();
	cbreak();
    Menu menu;
    Logical logical;
    logical.inputController();
    menu.mainMenu();
    endwin();
    return 0;
}