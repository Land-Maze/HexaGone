#include <ncurses.h>
#include <iostream>
#include "drawing.hpp"
#pragma once

class Logical {
    
    Menu menu;

    public:

    void menuController(){
        

        
        clear();
        menu.mainMenu();   
    }

    void inputController(){

        switch(getch()){
            case KEY_UP:
            printw("Pressed" + KEY_UP);
        }

    }

};