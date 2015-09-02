#include "tutorial.h"
#include "game.h"
#include<iostream>
#include<string>
#include<sstream>
#include <fstream>
#include <iomanip>

extern Console g_Console;
std::string messages1="";
std::string messages2="";
std::string playercharacter="";
std::string board1="";
std::string board2="";
std::string hint1="";
std::string hint2="";
int tutorial=0;
void renderTutorial()
{  
	if(tutorial==0)
	{	
		clearScreen();
		messages1="Welcome to the tutorial,Press enter to continue";
		playercharacter="";

		tutorial++;
	}
	else if(isKeyPressed(VK_RETURN)&&tutorial==1)
	{		
		clearScreen();
		messages1="This is your Character,Press Enter to Continue";
		playercharacter="           Player 1:";
		playercharacter+=(char)153;
		hint1="Player 2:";
		hint1+=(char)153;
		tutorial++;
	}
	else if(isKeyPressed(VK_RETURN)&&tutorial==2)
	{
		clearScreen();
		hint1="";
		playercharacter=(char)153;
		messages1="This is part of the game board with your character,press enter to continue";
		board1="987654321987654321";
		tutorial++;
	}
	else if (isKeyPressed(VK_RETURN)&&tutorial==3)
	{
		clearScreen();
		messages1="Press H to enable Hints(max 3 times in game)";
		tutorial++;
	}
	else if (isKeyPressed('H') &&tutorial==4)
	{
		clearScreen();
		messages1="The Number in the pink block represent the possible amount you will eat and Purple represent the ";
		messages2="blocks that may be eaten(total 9 including the pink colored block),Press Enter";
		hint1="9";
		hint2="12345678";
		tutorial++;
	}
	else if (isKeyPressed(VK_RETURN) &&tutorial==5)
	{
		messages1="Now move right by pressing either D or 6 in the numpad";
		messages2="";
		tutorial++;
	}
	else if (isKeyPressed('D') && tutorial==6 || isKeyPressed(VK_NUMPAD6) &&tutorial==6)
	{
		messages1 = "";
		board1="         987654321";
		messages1="You have eaten up 9 blocks,now they are empty blocks.Press Enter";
		playercharacter="";
		board2=(char)153;
		
		hint1="";
		hint2="";
		tutorial++;
	}
	else if(isKeyPressed(VK_RETURN)&&tutorial==7)
	{
		messages1="If theres a empty block in the middle of the numbers,you cannot move to the right.Press Enter";
		playercharacter=(char)153;
		board1="98 654321";
		board2="";
		tutorial++;
	}
	else if(isKeyPressed(VK_RETURN)&&tutorial==8)
	{
		messages1="You can move in 8 directions,check the options for the controls";
		messages2="Now Press Esc to end the tutorial :D Have fun.";
		board1="";
		board2="";
	}
	else if (isKeyPressed(VK_ESCAPE))
	{
		tutorial=0;
		 messages1="";
		 messages2="";
		 playercharacter="";
		 board1="";
		 board2="";
		hint1="";
		hint2="";
		g_eGameState=S_MAINMENU;
		
	}
	
	g_Console.writeToBuffer(20,6,playercharacter,0x0E);
	g_Console.writeToBuffer(2,3,messages1);
	g_Console.writeToBuffer(2,4,messages2);
	g_Console.writeToBuffer(21,6,board1,0x2F);
	g_Console.writeToBuffer(29,6,board2,0x0E);
	g_Console.writeToBuffer(19,6,hint1,0xDF);
	g_Console.writeToBuffer(11,6,hint2,0x5F);
	
}



