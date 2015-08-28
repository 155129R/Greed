#include "game.h"
#include "board.h"

void renderMap()
{
	for (unsigned int Y = 0; Y < playfield.sizeY; Y++)
	{
		for (unsigned int X = 0; X < playfield.sizeX; X++)
		{
			WORD C;

			char V = playfield.cell[Y][X].value;

			switch (playfield.cell[Y][X].highlight)
			{
			case NONE: C = 0x2F; break;
			case NEARBY: C = 0xDF; break;
			case TRAJECTORY: C = 0x5F; break;
			}

			COORD loc = renderOffset;
			loc.X += X;
			loc.Y += Y;

			g_Console.writeToBuffer(loc, V == 0 ? 0 : V + '0', C);
		}
	}
}


void boardGen()
{
	for (unsigned int Y = 0; Y < playfield.sizeY; Y++)
	{
		vector<PlayfieldCell> V(playfield.sizeX);

		for (unsigned int X = 0; X < playfield.sizeX; X++)
		{
			V[X].highlight = NONE;

			V[X].value = boardChances.rollValue(playfield.numberLimit);

			unsigned int K = V[X].value;

			K = K;
		}
		playfield.cell[Y] = V;
	}

	for (size_t i = 0; i < 2; i++)
	{
		Player* P = pickPlayer(i);

		COORD* playerLocation = &((*P).playerLocation);

	reattempt:

		(*playerLocation).X = rand() % playfield.sizeX;
		(*playerLocation).Y = rand() % playfield.sizeY;

		for (size_t j = 0; j < i; j++)
		{
			Player* P = pickPlayer(j);
			COORD* T = &((*P).playerLocation);
			if ((*T).X == (*playerLocation).X) goto reattempt;
			if ((*T).Y == (*playerLocation).Y) goto reattempt;
		}

		playfield.cell[(*playerLocation).Y][(*playerLocation).X].value = 0;

		(*P).active = true;
		(*P).hintsAvailable = 3;
		(*P).totalScore = 0;
	}

	currentTurn = 0;
	entered = true;
	hintOn = false;
}

void renderCharacter()
{
	// Draw the location of the characters
	const WORD inactive = 0x0A;
	WORD charColor;

	Player *P;

	for (unsigned int i = 0; i < 2; i++)
	{
		P = pickPlayer(i);
		COORD L = (*P).playerLocation;

		COORD loc = renderOffset; \
			loc.X += L.X;
		loc.Y += L.Y;

		switch (i)
		{
		case 0: charColor = 0x0E; break;
		case 1: charColor = 0x0D; break;
		default: charColor = 0x0F; break;
		}

		g_Console.writeToBuffer(loc, (char)2, charColor);
	}
}