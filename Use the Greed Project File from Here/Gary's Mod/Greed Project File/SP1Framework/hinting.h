#ifndef _GAME_H
#define _GAME_H

#include "Framework\console.h"
#include <iostream>
#include <vector>
#include "test.h"
using std::vector;
using std::string;


//--Playfield variables

enum highlightedState
{
	NONE,
	NEARBY,
	TRAJECTORY
};

struct playerField
{
    unsigned int Value;
	highlightedState Hint;
};


extern vector<vector<playerField>> playfield;


struct VBool
{
	vector<vector<bool>> V;
};


#endif // _GAME_H