#include "gameGUI.h"

void printNumber(COORD C, unsigned int N, WORD col);

void drawPlayerGUI(COORD loc, unsigned int playerNum)
{
	Player* p = pickPlayer(playerNum);
	const char *playerString;
	const char S1[] = "Player 1";
	const char S2[] = "Player 2";

	switch (playerNum)
	{
	case 0: playerString = S1; break;
	case 1: playerString = S2; break;
	}

	for (unsigned int i = 0; i < 7; i++)
	{
		g_Console.writeToBuffer(loc, "        ", 0x50);
		loc.Y++;
	}

	loc.Y = 1;

	g_Console.writeToBuffer(loc, playerString, 0x5E); loc.Y++; loc.X += 2;
	g_Console.writeToBuffer(loc, "Score", 0x5F); loc.Y++; loc.X += 4;
	printNumber(loc, (*p).totalScore, 0x5F); loc.Y += 2; loc.X -= 4;
	g_Console.writeToBuffer(loc, "Hints", 0x5F); loc.Y++;
	for (unsigned int i = 0; i < 3; i++)
	{
		WORD c = ((*p).hintsAvailable > i) ? 0x5E : 0x50;
		g_Console.writeToBuffer(loc.X + 4 - 2 * i, loc.Y, "?", c);
	}
}

void printNumber(COORD C, unsigned int N, WORD col)
{
	if (N == 0) g_Console.writeToBuffer(C, '0', col);

	while (N > 0)
	{
		g_Console.writeToBuffer(C, N % 10 + '0', col); C.X--;
		N /= 10;
	}
}