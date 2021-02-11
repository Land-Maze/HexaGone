#include <iostream>
#include <fstream>
#include <unistd.h>
#include <ncurses.h>
#include "Addons/logical.hpp"

int main()
{
    Logical logical;

    setlocale(LC_ALL, "");
	initscr();
    clear();
    keypad(stdscr,1);
    noecho();
	cbreak();
    start_color();
    logical.menuController();
    endwin();
    return 0;
}
