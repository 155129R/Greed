#ifndef _HIGHSCORE_H
#define	_HIGHSCORE_H

#include "Framework\console.h"
#include <iostream>
#include "game.h"
enum NameInputKeysenum
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
void write();
void print();
void check(int &total1,int &total2);
void AskforInput();
void HighScorefor1player();
void printall();
void displayPlayerName();
void NameInput();
void NameInputKeys();
void ResetHighScore();
void renderResetSelectedHighScore();
void  ResetSelectedHighScoreInput();
extern string PlayerName;
extern Console g_Console;

#endif