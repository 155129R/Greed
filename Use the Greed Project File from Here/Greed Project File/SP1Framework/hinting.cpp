#include "hinting.h"

bool allowedMoves[8];

void findMoves(COORD P)
{
	for (unsigned int i = 0; i < 8; i++)
	{
		allowedMoves[i] = false;

		int TX = P.X + unitX[i];
		if (TX < 0) continue;
		if (TX >= (signed)playfield.sizeX) continue;

		int TY = P.Y + unitY[i];
		if (TY < 0) continue;
		if (TY >= (signed)playfield.sizeY) continue;

		unsigned int V = playfield.cell[TY][TX].value;
		if (V == 0) continue;
		
		if (P.X + unitX[i] * V < 0) continue;
		if (P.X + unitX[i] * V >= playfield.sizeX) continue;

		if (P.Y + unitY[i] * V < 0) continue;
		if (P.Y + unitY[i] * V >= playfield.sizeY) continue;

		allowedMoves[i] = true;

		bool m = allowedMoves[i];

		for (unsigned int j = 2; j <= V; j++)
		{
			unsigned int XX = P.X + unitX[i] * j;
			unsigned int YY = P.Y + unitY[i] * j;

			if (playfield.cell[YY][XX].value == 0) { allowedMoves[i] = false; break; }
		}
	}
}

void showHints(COORD P)
{
	for (unsigned int i = 0; i < 8; i++)
	{
		if (!allowedMoves[i]) continue;

		unsigned int XX = P.X + unitX[i];
		unsigned int YY = P.Y + unitY[i];

		playfield.cell[YY][XX].highlight = NEARBY;

		unsigned int V = playfield.cell[YY][XX].value;

		for (unsigned int j = 2; j <= V; j++)
		{
			XX += unitX[i]; YY += unitY[i];
			playfield.cell[YY][XX].highlight = TRAJECTORY;
		}
	}
}

void hideHints()
{
	for (unsigned int i = 0; i < playfield.sizeX; i++)
	{
		for (unsigned int j = 0; j < playfield.sizeY; j++)
		{
			playfield.cell[j][i].highlight = NONE;
		}
	}
}
void checkWinner()
{
    bool B = false;
    for (unsigned int i = 0; i < 8; i++)
    {
        B |= allowedMoves[i];
    }
    
    if ( B == false)
    {
        g_Console.writeToBuffer(12,10, "press the ESC key to end the game and check your score or press 'R' to retry", 0x04);
    }


}