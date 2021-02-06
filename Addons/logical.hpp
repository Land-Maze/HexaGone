#pragma once
#include <ncurses.h>
#include <iostream>
#include <string>
#include "drawing.hpp"



class Logical {

    Menu menu;
    uint8_t trackPoint; 

    public:
    

    void menuController(){
        clear();
        menu.logoShow();
        menu.mainMenu();  
        inputController(); 
    }

    void inputController(){
        int gay = getch();
        switch(gay){
            
            case KEY_UP:

                if (menu.curU_D != 5) 
                menu.curU_D++;   
                menuController();

            break;

            case KEY_DOWN:

                if (menu.curU_D != 1) 
                menu.curU_D--;
                menuController();

            break;

            case 10:



            break;

            default:
                menuController();
            break;
        }
    }

};