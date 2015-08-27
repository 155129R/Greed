#include <iostream>
#include <fstream>
#include "game.h"
#include "playermenu.h"
#include "board.h"

numberofPlayers Number = Single;


int playerinTotal;



void totalplayerNumber(){
    switch(Number){
        case 1: Number = Single; break;

        case 2: Number = Multi; break;

        default: g_Console.writeToBuffer(4,4,"Invalid option");
                     g_eGameState = S_SPLASHSCREEN;
                     
    }
}

void applyplayer(){
    if(Number == Single){

   playerinTotal = 1;

    }
    else if(Number == Multi){

    playerinTotal = 2;

    }

   
}


void renderPlayerMenu(){
    std::string Single;
    std::string Multi;
    COORD c = g_Console.getConsoleSize();

    g_Console.writeToBuffer(0,1,"Choose how many players you want(1 for Single-Player , 2 for Multiplayer)", 0x04);

    c.Y = 4;
    c.X = 4;
    
    std::ifstream Singlefile;
    Singlefile.open("Single.txt");
        for(int i=0; Singlefile.good(); i++){
            std::getline(Singlefile, Single);
            g_Console.writeToBuffer(c, Single, 0x04);
            c.Y += 1;
        }

    c.Y += 2;


     std::ifstream Multifile;
    Multifile.open("Multi.txt");
        for(int i=0; Multifile.good(); i++){
            std::getline(Multifile, Multi);
            g_Console.writeToBuffer(c, Multi, 0x04);
            c.Y += 1;
        }

    c.Y += 2;
}

void processPlayerMenu(){
       int input;
    std::cin>>input;
    Number = static_cast<numberofPlayers>(input);
    g_eGameState = S_DIFFICULTY;
}


