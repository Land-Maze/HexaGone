#pragma once
#include <ncurses.h>
#include <iostream>
#include <string>
#include <sstream> 

using std::string;

class Menu {   

    const char* menuPunct[5] = {"<Start>", "<Creditals>", "Settings", "<Favorite>", "<Exit>"};
    const char* startPunct[4] = {"<SMS>", "<UDP>", "EMAIL", "<Back>"};
    const char* UDP[4] = {"<Start>","Target -- ", "Threads -- ", "<Back>"};


public: 

    string targetIp = "";
    string threadsStr = "";
    short threads = 1;
    short curU_D = 0;

    void punctShow(const char* punct[], short sizeA){

        short sizeAR = sizeA / sizeof(char*);

        for (short i = 0;i < sizeAR ;i++){
            
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
        
        punctShow(menuPunct, sizeof(menuPunct));

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

        punctShow(startPunct, sizeof(startPunct));

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

    void drawSendPacket( u_int32_t size, bool successful = 1){
        if (successful == 1){
            attron(COLOR_PAIR(1));
            printw("[ OK ] -- Sended packet, size >> ");
            attroff(COLOR_PAIR(1));

            printw(std::to_string(size).c_str());
            printw("byte\n");

            refresh();
        } else {
            printw("Error!\n");
            refresh();
        }

    }

    void stopedThread(){

    }

    void menuUDP(){

        short sizeAR = sizeof(UDP) / sizeof(char*);

        for (short i = 0;i < sizeAR ;i++){
            
            if (i == curU_D){
                printw("\n\n\t");
                attron(A_BOLD | A_REVERSE);
                printw(UDP[i]);
                if (i == 1) printw(targetIp.c_str());
                if (i == 2) printw(threadsStr.c_str());
                attroff(A_BOLD | A_REVERSE);
            } else {
                printw("\n\n\t"); 
                printw(UDP[i]);   
                if (i == 1) printw(targetIp.c_str());
                if (i == 2) printw(threadsStr.c_str());
            }
        }
            refresh();

    }

    void inputUDPA(uint8_t choice){
        init_pair(3,COLOR_MAGENTA, COLOR_BLACK);
        switch (choice){
            case 1:
                printw("\n\n\t┌────Input the target IP -- ");
                attron(COLOR_PAIR(3));
                printw("Example: IPv4:Port -- Port 88 recommended");
                attroff(COLOR_PAIR(3));
                printw("\n\n\t│\n\n\t│\n\n\t└──>  ");
                targetIp = getstring();
            break;

            case 2:
                printw("\n\n\t┌────How many threads? -- ");
                attron(COLOR_PAIR(3));
                printw("Recommended --> 1 (Equal 100 Mbps == 12.2MB/s)");
                attroff(COLOR_PAIR(3));
                printw("\n\n\t│\n\n\t│\n\n\t└──>  ");
                threadsStr = getstring();
            break;
        }
        
    }

    string getstring(){
    std::string input;
    nocbreak();
    echo();
    int ch = getch();

    while ( ch != '\n' )
    {
        input.push_back( ch );
        ch = getch();
    }

    noecho();
	cbreak();

    return input;
    }

};

/*

*/