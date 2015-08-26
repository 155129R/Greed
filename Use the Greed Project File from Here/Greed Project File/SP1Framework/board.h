#ifndef _BOARD_H
#define _BOARD_H

#include "Framework\timer.h"
#include "Framework\console.h"
#include <vector>
using std::vector;
using std::string;


void boardGen();
void renderMap();


extern Console g_Console;
extern const size_t playerNumber = 2;
extern Player players[playerNumber];
extern size_t numbers;


#endif