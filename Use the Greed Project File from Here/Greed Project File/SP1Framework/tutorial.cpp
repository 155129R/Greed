#include "tutorial.h"
#include "game.h"
#include<iostream>
#include<string>
#include<sstream>
#include <fstream>
#include <iomanip>
COORD E;
extern Console g_Console;
std::string messages1="";
std::string messages2="";
std::string playercharacter="";
std::string board1="";
std::string board2="";
std::string hint1="";
std::string hint2="";
std::string hint3="";
std::string wholeboard="";
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
		messages1="These are your Characters,Press Enter to Continue";
		playercharacter="             Player 1:";
		playercharacter+=(char)153;
		hint1=(char)154;
		hint3="Player 2";
		tutorial++;
	}
	else if(isKeyPressed(VK_RETURN)&&tutorial==2)
	{
		clearScreen();
		hint1="";
		hint3="";
		playercharacter=(char)153;
		messages1="This is the game board with your character,press enter to continue";
		board1="12345 987654321987654321";
		wholeboard="123456987654321987654321";
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
		hint2="87654321";
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
		board1="12345          987654321";
		messages1="You have eaten up 9 blocks,now they are empty blocks.You also earned 9 points.Press Enter";
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
		board1="12345 98 654321987654321";
		board2="";
		tutorial++;
	}
	else if(isKeyPressed(VK_RETURN)&&tutorial==8)
	{
		messages1="You can move in 8 directions,check the options for the controls,press Enter";
		messages2="";
		board1="12345 987654321987654321";
		board2="";
		tutorial++;
	}
	else if (isKeyPressed(VK_RETURN)&&tutorial==9)
	{
		messages1="For 2 Player Mode,each player will each take a turn to make a move.";
		messages2="Press Enter to continue";
		playercharacter+=(char)153;
		hint1+=(char)154;
		tutorial++;
	}
	else if(isKeyPressed(VK_RETURN)&&tutorial==10)
	{
		messages1="The game will end if a player cannot make a move anymore";
		messages2="The player that win will have his scores recorded in the highscore board";
		tutorial++;
	}
	else if (isKeyPressed(VK_RETURN)&&tutorial==11)
	{
		messages1="For Timed Mode ,the game will end if the time";
		messages2=" runs out or someone cannot make a move anymore ,Press Esc to end the tutorial";
		tutorial++;
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
		hint3="";
		wholeboard="";
		g_eGameState=S_MAINMENU;
		
	}
	E.Y=7;
    E.X=15;
		for(int a=0;a<5;a++)
		{
			g_Console.writeToBuffer(E,wholeboard,0x2F);
			E.Y++;
		}
	g_Console.writeToBuffer(2,3,messages1);
	g_Console.writeToBuffer(2,4,messages2);
	g_Console.writeToBuffer(15,6,board1,0x2F);
	g_Console.writeToBuffer(29,6,board2,0x0E);
	g_Console.writeToBuffer(20,6,playercharacter,0x0E);
	 g_Console.writeToBuffer(12,6,hint3);
    g_Console.writeToBuffer(21,6,hint1,0xDF);
	g_Console.writeToBuffer(22,6,hint2,0x5F);
}
