#ifndef _GAME_H
#define _GAME_H

#include "Framework\console.h"
#include <iostream>
#include <vector>
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

struct PSize
{
	size_t X;
	size_t Y;
};

extern vector<vector<playerField>> playfield;
extern PSize fieldSize;

struct VBool
{
	vector<vector<bool>> V;
};


#endif // _GAME_H