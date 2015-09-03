#ifndef _HIGHSCORE_H
#define	_HIGHSCORE_H

#include "game.h"
enum NameInputKeysenum //Keyboard inputs for player name
{
	K_A,
	K_B,
	K_C,
	K_D,
	K_E,
	K_F,
	K_G,
	K_H,
	K_I,
	K_J,
	K_K,
	K_L,
	K_M,
	K_N,
	K_O,
	K_P,
	K_Q,
	K_R,
	K_S,
	K_T,
	K_U,
	K_V,
	K_W,
	K_X,
	K_Y,
	K_Z,
	K_ENTER2,
	K_BACKSPACE,
	K_ESCAPE2,
	K_1,
	K_2,
	K_3,
	K_4,
	K_5,
	K_6,
	K_7,
	K_8,
	K_9,
	K_0
	
};
void write();	//write highscore to textfile
void print();	//print out highscore after game ends
void check(int &total1,int &total2);//check whether points earned are in 1st,2nd or 3rd Place
void NameInput();    //Insert Letters into player name
void printall();	//print all highscore for normal mode
void displayPlayerName();//display player name when inputting
void NameInputKeys();//input keys for highscore name
void renderResetSelectedHighScore();//ask player what highscore they want to reset
void  ResetSelectedHighScoreInput();//Reset highscore for normal mode
void ResetEasy1();//Reset Easy difficulty ,1player for normal mode
void ResetNormal1();//Reset Normal difficulty, 1 player for normal mode
void ResetHard1();//Reset Hard difficulty,1 player,for normal mode
void ResetEasy2();//Reset Easy difficulty,2 player,Normal mode
void ResetNormal2();//Reset Normal difficulty ,2 player,for normal mode
void ResetHard2();//Reset Hard difficulty,2 player ,Normal mode
void ResetEasy1time();//Reset Easy Difficulty, for 1 player,timed mode
void ResetNormal1time();//Reset Normal Difficulty,for 1 player,timed mode
void ResetHard1time();//Reset Hard difficulty,1 player mode,timed mode
void ResetEasy2time();//,Reset Easy difficulty,2player mode,timed mode
void ResetNormal2time();//Reset normal difficulty,2 player mode,timed mode
void ResetHard2time();//Reset Hard Difficulty,2 player mode,timed mode
void printalltime();//Print out all highscore for timed mode
void ResetSelectedHighScoreInputTime();//Reset highscore for Timed mode
void AskforInput();//Ask player for name
extern string PlayerName;//Player Name
extern Console g_Console;

#endif