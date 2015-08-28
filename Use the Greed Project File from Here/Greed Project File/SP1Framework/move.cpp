#include "move.h"

bool move(Player* P, Directions D)
{
	if (!allowedMoves[D]) return false;

	unsigned int X = (*P).playerLocation.X + unitX[D];
	unsigned int Y = (*P).playerLocation.Y + unitY[D];

	unsigned int V = playfield.cell[Y][X].value;

	for (unsigned int i = 0; i < V; i++)
	{
		(*P).playerLocation.X += unitX[D];
		(*P).playerLocation.Y += unitY[D];

		playfield.cell[(*P).playerLocation.Y][(*P).playerLocation.X].value = 0;
	}

	return true;
}