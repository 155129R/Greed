#include "game.h"
#include "board.h"
#include <iostream>

void load1process(){

	changeDiff();
	applyDiff();
	totalplayerNumber();applyplayer(totalPlayers);
	g_eGameState = S_LOADING2;
}

void load2process(){

	boardGen();
	g_eGameState = S_PLAYERMENU;
}

void renderLoading1(){
	g_Console.writeToBuffer(0, 0, "LOADING 1", 0x59);
}

void renderLoading2(){
	g_Console.writeToBuffer(0, 0, "LOADING 2", 0x59);
}
