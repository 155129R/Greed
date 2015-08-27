#include "game.h"
#include <iostream>

void load1process(){

    changeDiff();
    applyDiff();
    
    g_eGameState = S_LOADING2;
}

void load2process(){
    boardGen();
    g_eGameState = S_GAME;
}

void renderLoading1(){
    g_Console.writeToBuffer(0,0,"LOADING 1", 0x59);
}

void renderLoading2(){
    g_Console.writeToBuffer(0,0,"LOADING 2", 0x59);
}
