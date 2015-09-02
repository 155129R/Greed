#include <iostream>
#include <fstream>
#include "game.h"
#include "playermenu.h"
#include "board.h"
#include "startmenu.h"

COORD D;
void renderMenu()
{
	string Start;

	std::ifstream ReadFile;
	ReadFile.open("Start.txt");
	D.Y=5;
	D.X=1;
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
	
		D.Y=9;
		D.X=1;
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
	
		D.Y=14;
		D.X=1;
		while(ReadFile3.good())
		{
			std::getline(ReadFile3,HighScore);
			g_Console.writeToBuffer(D,HighScore,0x04);
			D.Y++;
		}
		ReadFile3.close();
	
	std::ifstream ReadFile4;
	string Exit;
	ReadFile4.open("Exit.txt");
	
		D.Y=18;
		D.X=1;
		while(ReadFile4.good())
		{
			std::getline(ReadFile4,Exit);
				g_Console.writeToBuffer(D,Exit,0x04);
			D.Y++;
		}
		ReadFile4.close();
	
}

void selectMenuInput()
{
	 if(isKeyPressed(VK_NUMPAD1)||isKeyPressed('1'))
	 {
		 g_eGameState=S_PLAYERMENU;
		 PlaySound(L"button.wav",NULL,SND_ASYNC);

	 }
	 if(isKeyPressed(VK_NUMPAD2)||isKeyPressed('2'))
	  {
		  g_eGameState=S_OPTION;
		  PlaySound(L"button.wav",NULL,SND_ASYNC);
	  }
	 
	  if(isKeyPressed(VK_NUMPAD3)||isKeyPressed('3'))
	  {
		  g_eGameState=S_PRINTHIGHSCORE;
		  PlaySound(L"button.wav",NULL,SND_ASYNC);
	  }
	  if(isKeyPressed(VK_NUMPAD4)||isKeyPressed('4'))
	  {PlaySound(L"button.wav",NULL,SND_ASYNC);
		  g_bQuitGame = true; 
	  }
}

