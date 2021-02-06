#pragma once
#include <ncurses.h>
#include <iostream>
#include <string>
#include "drawing.hpp"



class Logical {

    Menu menu;
    uint8_t trackPoint = 1; //1- menu

    public:
    

    void menuController(){
        clear();
        menu.logoShow();
        menu.mainMenu();
        inputController(); 
    }

    void menuLogicalController(){
        if (trackPoint == 1)
            switch (menu.curU_D){
                
                case 0:

                break;

                case 1:

                break;

                case 2:

                break;

                case 3:

                break;

                case 4:
                    Exit();
                break;

                default: 
                break;

            }
    }

    void inputController(){
        int gay = getch();
        switch(gay){
            
            case KEY_UP:
                if (menu.curU_D != 0) 
                menu.curU_D--;
                menuController();
            break;

            case KEY_DOWN:
                if (menu.curU_D != 4)
                menu.curU_D++;   
                menuController();
            break;

            case 10:

                menuLogicalController();

            break;

            default:
                menuController();
            break;
        }
    }

    void Exit(){
        std::cout << "Exiting program with code 0"; 
    }

    void Start(){

    }

    void Log(){

    }

    void Creditals(){

    }

    void Settings(){

    }

};