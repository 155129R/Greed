#ifndef _GAME_H
#define _GAME_H

#include "Framework\timer.h"
#include "Framework\console.h"
#include <iostream>
#include <vector>
#include <string>
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


//End of Playfield variables

//--Player variables

struct Player
{
	COORD L;
	unsigned int H;
	bool A;
};
void	addingPoints(int N,int &total1,int &total2);
void	convertTotalPoints (string &Result1,string &Result2 ,int &total1,int &total2);
extern int total1;
extern std::string Result1;
extern int total2;
extern std::string Result2;
#endif // _GAME_H