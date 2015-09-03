#include "game.h"
#include "board.h"
#include <iostream>

void load1process()//Done by Sham,check for difficulty and apply 
{

	changeDiff();
	applyDiff();
    applyplayer();
    totalplayerNumber();
    chancesofNumber();
	g_eGameState = S_LOADING2;
}

void load2process()//Done by Sham, Render the board and game
{

	boardGen();
	g_eGameState = S_GAME;
}

void renderLoading1()//Done by sham,render loading screen
{
	g_Console.writeToBuffer(0, 0, "LOADING 1", 0x59);
}

void renderLoading2()//Done by sham,Render loading screen 2
{
	g_Console.writeToBuffer(0, 0, "LOADING 2", 0x59);
}
