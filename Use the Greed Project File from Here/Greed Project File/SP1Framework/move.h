#ifndef _MOVE_H
#define _MOVE_H

#include "Framework\timer.h"
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

struct Player
{
	COORD playerLocation;
	unsigned int H;
	bool A;
};

extern vector<vector<playerField>> playfield;

extern PSize fieldSize;

//End of Playfield variables

//--Player variables

//struct Player
//{
//	COORD playerLocation;
//	unsigned int H;
//	bool A;
//};
enum EKEYS
{
    K_UP,
    K_UPLEFT,
    K_UPRIGHT,
    K_DOWN,
    K_DOWNLEFT,
    K_DOWNRIGHT,
    K_LEFT,
	K_RIGHT,
	K_UP2,
	K_UPLEFT2,
	K_UPRIGHT2,
	K_DOWN2,
	K_DOWNLEFT2,
	K_DOWNRIGHT2,
	K_LEFT2,
	K_RIGHT2,

};
bool move(EKEYS key, Player& Pointer);//use -1,0,1
bool check(EKEYS key, Player& Pointer);
void moveChar(Player& Pointer);
void addingPoints(int selectedNumber,int &total1,int&total2);
void convertTotalPoints (std::string &Result1,std::string &Result2,int &total1,int &total2);
extern unsigned int currentTurn;
#endif // _MOVE_H