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

struct PField
{
	unsigned int V;
	highlightedState H;
};

struct PSize
{
	size_t X;
	size_t Y;
};

extern vector<vector<PField>> playfield;
extern PSize fieldSize;

struct VBool
{
	vector<vector<bool>> V;
};


#endif // _GAME_H