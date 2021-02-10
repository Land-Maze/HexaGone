#pragma once
#include <ncurses.h>
#include <iostream>
#include <string>
#include "drawing.hpp"
#include "..//Tools/SMS.hpp"



class Logical {

    Menu draw;
    uint8_t trackPoint = 1; //1 - Menu; 2 - Start; 3 - Creditals;

    public:
    

    void menuController(){
        switch (trackPoint){
            case 1:
                mainMenu();
            break;

            case 2:
                Start();
            break;

            case 3:

                inputController();

            break;

        }
    }

    void menuLogicalController(){
        switch (trackPoint){
            case 1:
                switch (draw.curU_D){
                
                    case 0:
                        Start();
                    break;

                    case 1:
                        Creditals();
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
            break;

            case 2:
                switch (draw.curU_D){
                    case 1:
                    break;

                    case 2:
                    break;

                    case 3:
                    break;

                    case 4:
                    break;
                }
            break;

            case 3: //
                
                mainMenu();

            break;
        }
    }

    void inputController(){
        int gay = getch();
        switch(gay){
            
            case KEY_UP:
                if (draw.curU_D != 0) 
                draw.curU_D--;
                menuController();
            break;

            case KEY_DOWN:
                if (trackPoint == 1)
                    if (draw.curU_D != 4)
                        draw.curU_D++;   
                if (trackPoint == 2)
                    if (draw.curU_D != 3)
                        draw.curU_D++;
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
        std::cout << "Exiting program with code 0 "; 
    }

    void Start(){
        if (trackPoint != 2) draw.curU_D = 0;
        trackPoint = 2;
        clear();
        draw.logoShow();
        draw.startMenu();
        inputController();

    }

    void Log(){

    }

    void Creditals(){
        trackPoint = 3;
        draw.curU_D=0;
        clear();
        draw.logoShow();
        draw.showCreditals();
        inputController();
    }

    void Settings(){

    }

    void mainMenu(){
        if (trackPoint != 1) draw.curU_D=0;
        trackPoint = 1;
        clear();
        draw.logoShow();
        draw.mainMenu();
        inputController();
    }

};