#include "game.h"

const size_t S = 8;

const int Dx[S] = { -1, 1, 0, 0, -1, 1, -1, 1 };
const int Dy[S] = { 0, 0, -1, 1, -1, -1, 1, 1 };

void hinting(COORD C)
{
	for (unsigned int Y = 0; Y < fieldSize.Y; Y++)
	for (unsigned int X = 0; X < fieldSize.X; X++)
		playfield[Y][X].H = NONE;

	for (unsigned int D = 0; D < S; D++)
	{
		int MX = Dx[D];
		int MY = Dy[D];

		int X = MX + C.X;
		int Y = MY + C.Y;

		if (X < 0) continue;
		if (Y < 0) continue;
		if (X >= (int)playfield[0].size()) continue;
		if (Y >= (int)playfield.size()) continue;

		int N = playfield[Y][X].V;
		if (N == 0) continue;

		if (X + MX * (N - 1) < 0) continue;
		if (Y + MY * (N - 1) < 0) continue;
		if (X + MX * (N - 1) >= (signed)playfield[0].size()) continue;
		if (Y + MY * (N - 1) >= (signed)playfield.size()) continue;
		
		bool B = true;
		
		for (int i = 1; i < N; i++)
		{
			if (playfield[Y + i * MY][X + i * MX].V == 0)
			{
				B = false;
				break;
			}
		}

		if (!B) continue;

		playfield[Y][X].H = NEARBY;
		for (int i = 1; i < N; i++) playfield[Y + i * MY][X + i * MX].H = TRAJECTORY;

		continue;
	}
}