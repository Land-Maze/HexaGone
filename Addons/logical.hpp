#include <ncurses.h>
#include <iostream>
#include <string>
#include "drawing.hpp"
#pragma once



class Logical {
    Menu menu;
    
    private:

    uint8_t trackPoint; 

    public:

    void menuController(){
        

        
        clear();
        menu.mainMenu();   
    }

    void inputController(){
        int gay = getch();
        switch(gay){
            
            case KEY_UP:
                
            break;

            default:

            break;
        }

        refresh();

    }

};