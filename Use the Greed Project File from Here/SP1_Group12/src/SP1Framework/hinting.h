#ifndef _HINTING_H
#define _HINTING_H

#include "game.h"

void findMoves(COORD P);//find possible moves when using hints
void showHints(COORD P);//show possible moves when using hints
void hideHints();		//hide hints
void checkWinner();		//Check the winner of the game

bool hasPossibleMoves();//check whether theres a possible move

extern bool allowedMoves[8];

const char unitX[8] = { -1, 1, 0, 0, -1, 1, -1, 1 };
const char unitY[8] = { 0, 0, -1, 1, -1, -1, 1, 1 };

#endif 