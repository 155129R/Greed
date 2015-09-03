#include "game.h"
#include "playermenu.h"
#include "board.h"

extern numberofPlayers Number = Single;
void totalplayerNumber()//Done by Glence,find total amount of players
{
    switch(Number){
        case 1: Number = Single; break;

        case 2: Number = Multi; break;


                     
    }
}

void applyplayer()//Done by Glence,Set 1 player or 2 player for game
{
    if(Number == Single){

   totalPlayers = 1;

    }
    else if(Number == Multi){

    totalPlayers = 2;

    }
}


void renderPlayerMenu()//Done by Glence,Render Player menu screen
{
    std::string Single;
    std::string Multi;
    COORD c = g_Console.getConsoleSize();

    g_Console.writeToBuffer(0,1,"Choose how many players you want(1 for Single-Player , 2 for Multiplayer)", 0x0B);

    c.Y = 4;
    c.X = 4;
    
    std::ifstream Singlefile;
    Singlefile.open("display\\Single.txt");
    for(int i=0; Singlefile.good(); i++){
        std::getline(Singlefile, Single);
        g_Console.writeToBuffer(c, Single, 0x03);
        c.Y += 1;
    }

    c.Y += 2;

    std::ifstream Multifile;
    Multifile.open("display\\Multi.txt");
    for(int i=0; Multifile.good(); i++){
        std::getline(Multifile, Multi);
        g_Console.writeToBuffer(c, Multi, 0x03);
        c.Y += 1;
    }

    c.Y += 2;
}

void processPlayerMenu()//Done by glence,process Player menu inputs
{
    if((isKeyPressed('1'))||(isKeyPressed(VK_NUMPAD1))){
	    
		PlaySound(L"sound\\button.wav",NULL,SND_ASYNC);
		Number = static_cast<numberofPlayers>(1);
	    g_eGameState = S_MODE;

    }
    if((isKeyPressed('2'))||(isKeyPressed(VK_NUMPAD2))){
	    PlaySound(L"sound\\button.wav",NULL,SND_ASYNC);
		Number = static_cast<numberofPlayers>(2);
	    g_eGameState = S_MODE;
    }
    if (isKeyPressed(VK_ESCAPE))
	  {
		  PlaySound(L"sound\\button.wav",NULL,SND_ASYNC);
		  g_eGameState=S_MAINMENU;
	  }
    
}


