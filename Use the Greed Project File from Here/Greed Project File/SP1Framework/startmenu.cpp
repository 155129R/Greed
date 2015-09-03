#include "startmenu.h"

#include "game.h"
#include "playermenu.h"
#include "board.h"

COORD D;
void renderMenu()
{
	string Start;

	std::ifstream ReadFile;
	ReadFile.open("display\\Start.txt");
	D.Y=5;
	D.X=1;
	while(ReadFile.good())
	{
	std::getline(ReadFile,Start);
	g_Console.writeToBuffer(D.X,D.Y, Start, 0x03);
	D.Y+=1;
	}
	ReadFile.close();
		
	std::ifstream ReadFile2;
	string Option;
	ReadFile2.open("display\\Options.txt");
	
		D.Y=9;
		D.X=1;
		while(ReadFile2.good())
		{

			std::getline(ReadFile2,Option);
			g_Console.writeToBuffer(D,Option, 0x03);
			D.Y++;
		}
		g_Console.writeToBuffer(55,11,"<-- Please select your controls");
		g_Console.writeToBuffer(55,12,"before starting");
		ReadFile2.close();
	
	std::ifstream ReadFile3;
	string HighScore;
	ReadFile3.open("display\\HighScore.txt");
	
		D.Y=14;
		D.X=1;
		while(ReadFile3.good())
		{
			std::getline(ReadFile3,HighScore);
			g_Console.writeToBuffer(D,HighScore,0x03);
			D.Y++;
		}
		ReadFile3.close();
	
	
	std::ifstream ReadFile4;
	string Tutorial;
	ReadFile4.open("display\\Tutorial.txt");
	
		D.Y=19;
		D.X=1;
		while(ReadFile4.good())
		{
			std::getline(ReadFile4,Tutorial);
				g_Console.writeToBuffer(D,Tutorial,0x03);
			D.Y++;
		}
		ReadFile4.close();
	std::ifstream ReadFile5;
	string Exit;
	ReadFile5.open("display\\Exit.txt");
		D.Y=24;
		D.X=1;
		while(ReadFile5.good())
		{
			std::getline(ReadFile5,Exit);
				g_Console.writeToBuffer(D,Exit,0x03);
			D.Y++;
		}
		ReadFile5.close();
	
}
	


void selectMenuInput()
{
	 if(isKeyPressed(VK_NUMPAD1)||isKeyPressed('1'))
	 {
		 g_eGameState=S_PLAYERMENU;
		 PlaySound(L"sound\\button.wav",NULL,SND_ASYNC);

	 }
	 if(isKeyPressed(VK_NUMPAD2)||isKeyPressed('2'))
	  {
		  g_eGameState=S_OPTION;
		  PlaySound(L"sound\\button.wav",NULL,SND_ASYNC);
	  }
	 
	  if(isKeyPressed(VK_NUMPAD3)||isKeyPressed('3'))
	  {
		  g_eGameState= S_TIMEHIGHSCORECHECK;
		  PlaySound(L"sound\\button.wav",NULL,SND_ASYNC);
	  }
	  if(isKeyPressed(VK_NUMPAD4)||isKeyPressed('4'))
	  {
		  g_eGameState=S_TUTORIAL;
		  PlaySound(L"sound\\button.wav",NULL,SND_ASYNC);
	  }
	  
	  if(isKeyPressed(VK_NUMPAD5)||isKeyPressed('5'))
	  {PlaySound(L"sound\\button.wav",NULL,SND_ASYNC);
		  g_bQuitGame = true;
	  }
}

