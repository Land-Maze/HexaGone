#pragma once
#include <ncurses.h>
#include <iostream>
#include <string>

using std::string;

class Menu {   

    const char* menuPunct[5] = {"<Start>", "<Creditals>", "Settings", "<Favorite>", "<Exit>"};
    const char* startPunct[4] = {"<SMS>", "<UDP>", "EMAIL", "<Back>"};
    const char* UDP[3] = {"Target(Ex. 192.168.254.72:88) -- ", "Threads(Max 200) -- ", "<Back>"};


public: 

    uint8_t threads[3];
    char targetIp[24];
    short curU_D = 0;

    void punctShow(const char* punct[], short sizeA){

        for (short i = 0;i < sizeA ;i++){
            
            if (i == curU_D){
                printw("\n\n\t");
                attron(A_BOLD | A_REVERSE);
                printw(punct[i]);
                attroff(A_BOLD | A_REVERSE);
            } else {
                printw("\n\n\t"); 
                printw(punct[i]);   
            }
        }
            refresh();

    }

    void mainMenu() {
        
        punctShow(menuPunct, sizeof(menuPunct)/ sizeof(char*));

    }

    void logoShow(){
        init_pair(1, COLOR_YELLOW, COLOR_BLACK);
        init_pair(2, COLOR_RED, COLOR_BLACK);
        attron(A_BOLD);
        
        attron(COLOR_PAIR(1));
        printw("    __  __                ");
        attroff(COLOR_PAIR(1));

        attron(COLOR_PAIR(2));
        printw("______               \n");
        attroff(COLOR_PAIR(2));


        attron(COLOR_PAIR(1));
        printw("   / / / /__  _  ______ _");
        attroff(COLOR_PAIR(1));

        attron(COLOR_PAIR(2));
        printw("/ ____/___  ____  ___ \n");
        attroff(COLOR_PAIR(2));

        attron(COLOR_PAIR(1));
        printw("  / /_/ / _ \\| |/_/ __ `");
        attroff(COLOR_PAIR(1));


        attron(COLOR_PAIR(2));
        printw("/ / __/ __ \\/ __ \\/ _ \\\n");
        attroff(COLOR_PAIR(2));

        attron(COLOR_PAIR(1));
        printw(" / __  /  __/>  </ /_/ ");
        attroff(COLOR_PAIR(1));

        attron(COLOR_PAIR(2));
        printw("/ /_/ / /_/ / / / /  __/\n");
        attroff(COLOR_PAIR(2));

        attron(COLOR_PAIR(1));
        printw("/_/ /_/\\___/_/|_|\\__,_/");
        attroff(COLOR_PAIR(1));

        attron(COLOR_PAIR(2));
        printw("\\____/\\____/_/ /_/\\___/");
        attroff(COLOR_PAIR(2));

        attroff(A_BOLD);
        refresh();
    }

    void startMenu(){

        punctShow(startPunct, sizeof(startPunct) / sizeof(char*));

    }

    void showCreditals(){
        printw("\n\n\tAuthor: Land-Maze\n\n\tLicence: CC BY-NC-ND 4.0\n\tGet full info here > ");
        attron(A_BOLD | A_UNDERLINE);
        printw("https://creativecommons.org/licenses/by-nc-nd/4.0/");
        attroff(A_BOLD | A_UNDERLINE);
        refresh();

        printw("\n\n\n\n\t");
        attron(A_BOLD | A_REVERSE);
        printw("<Back>");
        attroff(A_BOLD | A_REVERSE);
    }

    void drawSendPacket(){

    }

    void menuUDP(){

        for (short i = 0;i < 2 ;i++){
            
            if (i == curU_D){
                printw("\n\n\t");
                attron(A_BOLD);
                printw(UDP[i]);
                printw()
                attroff(A_BOLD);
            } else {
                printw("\n\n\t"); 
                printw(UDP[i]);   
            }
        }
            refresh();


    }


};

/*

*/