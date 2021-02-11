#pragma once
#include <ncurses.h>
#include <iostream>
#include <string>
#include <sstream> 
#include "drawing.hpp"
#include "..//Tools/SMS.hpp"



class Logical {

    int gay;

    Menu draw;
    uint8_t trackPoint = 1; //1 - Menu; 2 - Start; 3 - Creditals, 4 - Fav, 5 - Settings, 6 - SMS, 7 - UDP, 8 - EMAIL;
    public:
    
    void attackController(uint8_t Id){
        switch (Id){
            case 0:

            break;


            case 1:
                UDP();
            break;


            case 2:

            break;


            case 3:

            break;
        }
    }

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

            case 7:
                UDP();            
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
                    case 0:
                        attackController(draw.curU_D);
                    break;

                    case 1:
                        attackController(draw.curU_D);
                    break;

                    case 2:
                        attackController(draw.curU_D);
                    break;

                    case 3:
                        mainMenu();
                    break;
                }
            break;

            case 3: //
                
                mainMenu();

            break;

            case 7:
                if (draw.curU_D == 0) startUDP();

                if (draw.curU_D == 1){
                    draw.inputUDPA(1);
                    UDP();
                }

                if (draw.curU_D == 2){
                    draw.inputUDPA(2);
                    UDP();
                }

                if (draw.curU_D == 3) Start();
            break;
        }
    }

    void inputController(){
        gay = getch();
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
                if (trackPoint == 7)
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

    void Favorite(){

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

    void SMS(){

    }

    void EMAIL(){

    }

    void UDP(){
        if (trackPoint != 7) {
            draw.curU_D = 0;
            draw.targetIp = "192.168.0.1:88";
            draw.threads = "1";
            trackPoint = 7;
        }
        clear();
        draw.logoShow();
        draw.menuUDP();
        inputController();
    }

    void startUDP(){

    }
};