#include "move.h"

bool move(int X, int Y, Player& P)
{
	int x = P.L.X + X;
	int y = P.L.Y + Y;

	if (x < 0) return false;
	if (y < 0) return false;
	if (x >= (signed)fieldSize.X) return false;
	if (y >= (signed)fieldSize.Y) return false;

	int N = playfield[y][x].V;
	if (N == 0) return false;

	if (x + (N - 1)*X < 0) return false;
	if (y + (N - 1)*Y < 0) return false;
	if (x + (N - 1)*X >= (signed)fieldSize.X) return false;
	if (y + (N - 1)*Y >= (signed)fieldSize.Y) return false;

	for (int i = 1; i < N; i++)
	{
		int xx = x + i * X;
		int yy = y + i * Y;

		if (playfield[yy][xx].V == 0) return false;
	}

	for (int i = 0; i < N; i++)
	{
		P.L.X += X;
		P.L.Y += Y;

		playfield[P.L.Y][P.L.X].V = 0;
	}
    Sleep(1000);
	return true;
}