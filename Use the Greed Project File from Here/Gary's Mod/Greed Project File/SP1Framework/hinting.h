#ifndef _HINTING_H
#define _HINTING_H

#include "game.h"

void findMoves(COORD P);
void showHints(COORD P);
void hideHints();

extern bool allowedMoves[8];

const char unitX[8] = { -1, 1, 0, 0, -1, 1, -1, 1 };
const char unitY[8] = { 0, 0, -1, 1, -1, -1, 1, 1 };

#endif 