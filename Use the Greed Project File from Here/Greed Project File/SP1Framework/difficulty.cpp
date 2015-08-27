#include "game.h"
#include "difficulty.h"
#include <fstream>

Difficulty level = Novice;


//S_LOADING 1


void changeDiff(){
    switch(level){
        case 1: level = Novice; break;

        case 2: level = Intermediate; break;

        case 3: level = Advanced; break;

        default: g_Console.writeToBuffer(4,4,"Invalid option");
                     g_eGameState = S_PLAYERMENU;
                     
    }
}

void applyDiff(){
    if(level == Novice){
        fieldSize.X = 35;
        fieldSize.Y = 35;
        numbers = 5;

    }
    else if(level == Intermediate){
        fieldSize.X = 30;
        fieldSize.Y = 30;
        numbers = 7;
    }
    else if(level == Advanced){
    
        fieldSize.X = 20;
        fieldSize.Y = 20;
        numbers = 9;
    
    }
   
}

//S_DIFFICULTY
void renderDiff(){
    std::string novice;
    std::string intermediate;
    std::string advanced;
    COORD c = g_Console.getConsoleSize();

    g_Console.writeToBuffer(0,1,"Choose Your Difficulty (1,2, or 3)", 0x04);

    c.Y = 4;
    c.X = 4;
    
    std::ifstream novicefile;
    novicefile.open("Novice.txt");
        for(int i=0; novicefile.good(); i++){
            std::getline(novicefile, novice);
            g_Console.writeToBuffer(c, novice, 0x04);
            c.Y += 1;
        }

    c.Y += 2;


     std::ifstream intermediatefile;
    intermediatefile.open("Intermediate.txt");
        for(int i=0; intermediatefile.good(); i++){
            std::getline(intermediatefile, intermediate);
            g_Console.writeToBuffer(c, intermediate, 0x04);
            c.Y += 1;
        }

    c.Y += 2;


     std::ifstream advancedfile;
    advancedfile.open("Advanced.txt");
        for(int i=0; advancedfile.good(); i++){
            std::getline(advancedfile, advanced);
            g_Console.writeToBuffer(c, advanced, 0x04);
            c.Y += 1;
        }

}

void processDiff(){
    int input;
    std::cin>>input;
    level = static_cast<Difficulty>(input);
    g_eGameState = S_LOADING1;
}