#include <iostream>
#include <fstream>
#include "game.h"
#include "playermenu.h"
#include "board.h"
void renderMenu();
void selectMenuInput();
extern int totalPlayer;
numberofPlayers Number = Single;
COORD D;
void totalplayerNumber(){
    switch(Number){
        case 1: Number = Single; break;

        case 2: Number = Multi; break;

        default: g_Console.writeToBuffer(4,4,"Invalid option");
                     g_eGameState = S_SPLASHSCREEN;
                     
    }
}
void renderMenu()
{
	string Start;

	std::ifstream ReadFile;
	ReadFile.open("Start.txt");
	D.Y=10;
	D.X=5;
	while(ReadFile.good())
	{
	std::getline(ReadFile,Start);
	g_Console.writeToBuffer(D.X,D.Y, Start, 0x04);
	D.Y+=1;
	}
	ReadFile.close();
		
	std::ifstream ReadFile2;
	string Option;
	ReadFile2.open("Options.txt");
	
		D.Y=20;
		D.X=5;
		while(ReadFile2.good())
		{

			std::getline(ReadFile2,Option);
			g_Console.writeToBuffer(D,Option, 0x04);
			D.Y++;
		}
		ReadFile2.close();
	
	std::ifstream ReadFile3;
	string HighScore;
	ReadFile3.open("HighScore.txt");
	
		D.Y=30;
		D.X=5;
		while(ReadFile3.good())
		{
			std::getline(ReadFile3,HighScore);
			g_Console.writeToBuffer(D,HighScore,0x04);
			D.Y++;
		}
		ReadFile3.close();
	
	std::ifstream ReadFile4;
	string Exit;
	ReadFile4.open("Exit");
	
		D.Y=46;
		D.X=5;
		while(ReadFile4.good())
		{
			std::getline(ReadFile4,Exit);
				g_Console.writeToBuffer(D,Exit,0x04);
			D.Y++;
		}
		ReadFile4.close();
	
}

void applyplayer(int totalPlayers){
    if(Number == Single){

   totalPlayers = 1;

    }
    else if(Number == Multi){

    totalPlayers = 2;

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
    if((isKeyPressed('1'))||(isKeyPressed(VK_NUMPAD1))){
	    Number = static_cast<numberofPlayers>(1);
	    g_eGameState = S_GAME;
    }
    if((isKeyPressed('2'))||(isKeyPressed(VK_NUMPAD2))){
	    Number = static_cast<numberofPlayers>(2);
	    g_eGameState = S_GAME;
    }
    
}

void selectMenuInput()
{
	 if(isKeyPressed(VK_NUMPAD1)||isKeyPressed('1'))
	 {
		 g_eGameState=S_DIFFICULTY;
	 }
	 if(isKeyPressed(VK_NUMPAD2)||isKeyPressed('2'))
	  {
		  g_eGameState=S_OPTION;
	  }
	 
	  if(isKeyPressed(VK_NUMPAD3)||isKeyPressed('3'))
	  {
		  g_eGameState=S_PRINTHIGHSCORE;
	  }
	  if(isKeyPressed(VK_NUMPAD4)||isKeyPressed('4'))
	  {
		  g_bQuitGame = true; 
	  }
}
