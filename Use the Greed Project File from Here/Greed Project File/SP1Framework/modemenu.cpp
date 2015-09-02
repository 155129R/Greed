#include <iostream>
#include <fstream>
#include "game.h"
#include "modemenu.h"



bool timemode = false;



void renderPlayerMenu(){
    std::string normal;
    std::string time;
    COORD c = g_Console.getConsoleSize();

    g_Console.writeToBuffer(0,1,"Choose which mode you want (1 for normal 2 for time)", 0x0B);

    c.Y = 4;
    c.X = 4;
    
    std::ifstream normalmodefile;
    normalmodefile.open("normalmode.txt");
    for(int i=0; normalmodefile.good(); i++){
        std::getline(normalmodefile, normal);
        g_Console.writeToBuffer(c, normal, 0x03);
        c.Y += 1;
    }

    c.Y += 2;

    std::ifstream timemodefile;
    timemodefile.open("timemode.txt");
    for(int i=0; timemodefile.good(); i++){
        std::getline(timemodefile, time);
        g_Console.writeToBuffer(c, time, 0x03);
        c.Y += 1;
    }

    c.Y += 2;
}

void processmodeMenu(){
    if((isKeyPressed('1'))||(isKeyPressed(VK_NUMPAD1))){
	    
		PlaySound(L"button.wav",NULL,SND_ASYNC);
		bool timemode = false;
	    g_eGameState = S_DIFFICULTY;

    }
    if((isKeyPressed('2'))||(isKeyPressed(VK_NUMPAD2))){
	    PlaySound(L"button.wav",NULL,SND_ASYNC);
		bool timemode = true;
	    g_eGameState = S_DIFFICULTY;
    }
    if (isKeyPressed(VK_ESCAPE))
	  {
		  PlaySound(L"button.wav",NULL,SND_ASYNC);
		  g_eGameState = S_MAINMENU;
	  }
    
}