#include <iostream>
#include <fstream>
#include <unistd.h>
#include <ncurses.h>
#include "Addons/drawing.hpp"
#include "Addons/logical.hpp"

int main()
{
    Menu menu;
    Logical logical;

    
	initscr();
	clear();
    keypad(stdscr,1);
	noecho();
	cbreak();
    menu.mainMenu();
    logical.inputController();
    sleep(2);
    endwin();
    return 0;
}