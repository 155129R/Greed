#include "move.h"
#include "points.h"
#include <string>
#include "HighScore.h"
extern int total1;
extern int total2;
extern std::string Result1;
extern std::string Result2;
bool move(Player* P, Directions D)
{
	if (!allowedMoves[D]) return false;

	unsigned int X = (*P).playerLocation.X + unitX[D];
	unsigned int Y = (*P).playerLocation.Y + unitY[D];

	unsigned int V = playfield.cell[Y][X].value;
	addingPoints( V,total1,total2);
	convertTotalPoints (Result1,Result2,total1,total2);
	for (unsigned int i = 0; i < V; i++)
	{
		(*P).playerLocation.X += unitX[D];
		(*P).playerLocation.Y += unitY[D];

		playfield.cell[(*P).playerLocation.Y][(*P).playerLocation.X].value = 0;
	}

	//(*P).totalScore += V;
	
	return true;
}