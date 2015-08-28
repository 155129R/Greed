#include "hinting.h"

void hintFlush();
PSize fieldSize;
vector<vector<playerField>> playfield;

const size_t directionSize = 8;

const int directionX[directionSize] = { -1, 1, 0, 0, -1, 1, -1, 1 };
const int directionY[directionSize] = { 0, 0, -1, 1, -1, -1, 1, 1 };

void hinting(COORD hintCoord)
{
	for (unsigned int D = 0; D < directionSize; D++)
	{
		int moveX = directionX[D];
		int moveY = directionY[D];

		int hintcoordX = moveX + hintCoord.X;
		int hintcoordY = moveY + hintCoord.Y;

		if (hintcoordX < 0) continue;
		if (hintcoordY < 0) continue;
		if (hintcoordX >= (int)playfield[0].size()) continue;
		if (hintcoordY >= (int)playfield.size()) continue;

		int finalplace = playfield[hintcoordY][hintcoordX].Value;
		if (finalplace == 0) continue;

		if (hintcoordX + moveX * (finalplace - 1) < 0) continue;
		if (hintcoordY + moveY * (finalplace - 1) < 0) continue;
		if (hintcoordX + moveX * (finalplace - 1) >= (signed)playfield[0].size()) continue;
		if (hintcoordY + moveY * (finalplace - 1) >= (signed)playfield.size()) continue;
		
		bool checktrue = true;
		
		for (int i = 1; i < finalplace; i++)
		{
			if (playfield[hintcoordY + i * moveY][hintcoordX + i * moveX].Value == 0)
			{
				checktrue = false;
				break;
			}
		}

		if (!checktrue) continue;

		playfield[hintcoordY][hintcoordX].Hint = NEARBY;
		for (int i = 1; i < finalplace; i++) playfield[hintcoordY + i * moveY][hintcoordX + i * moveX].Hint = TRAJECTORY;

		continue;
	}
}

void hintFlush()
{
	for (unsigned int hintcoordY = 0; hintcoordY < fieldSize.Y; hintcoordY++)
	for (unsigned int hintcoordX = 0; hintcoordX < fieldSize.X; hintcoordX++)
		playfield[hintcoordY][hintcoordX].Hint = NONE;
}