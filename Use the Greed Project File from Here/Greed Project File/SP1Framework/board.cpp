#include "game.h"
#include "board.h"



void renderMap()
{
    char V;
	for (unsigned int Y = 0; Y < fieldSize.Y; Y++)
    {
        for (unsigned int X = 0; X < fieldSize.X; X++)
        {
            //gotoXY(X, Y);
            
			V = playfield[Y][X].Value;

			WORD C;

			switch (playfield[Y][X].Hint)
			{
			case NONE: C = 0x2F; break;
			case NEARBY: C = 0xDF; break;
			case TRAJECTORY: C = 0x5F; break;
			}

            g_Console.writeToBuffer(X, Y, static_cast<char>(V == 0 ? 0 : V + 48), C);
            
        }
    }
    g_Console.writeToBuffer(fieldSize.X + 4, 4, "Total Points for player 1: ", 0x59);
	g_Console.writeToBuffer(fieldSize.X + 31,4,Result1,0x59);
	g_Console.writeToBuffer(fieldSize.X + 4,6,"Total Points for player 2: ", 0x59);
	g_Console.writeToBuffer(fieldSize.X + 31,6,Result2,0x59);
	g_Console.writeToBuffer(0, fieldSize.Y + 5, currentTurn + '0', 0x59);

}



void boardGen(){
	playfield.resize(fieldSize.Y);

    for (unsigned int Y = 0; Y < fieldSize.Y; Y++)
    {
        vector<playerField> V(fieldSize.X);

        for (unsigned int X = 0; X < fieldSize.X; X++)
		{
			unsigned int chances[8] = {20, 60, 70, 75, 80, 90, 93, 95}; //Chances (in %) for 2, 3, 4, 5, 6, 7, 8, 9; if chance is less than getting a 2, use 1.

			unsigned int R = rand() % 100;

			V[X].Value = 1;
			V[X].Hint = NONE;

			while (V[X].Value < numbers)
			{
				if (R < chances[V[X].Value - 1]) break;
				V[X].Value++;
			}
        }
        playfield[Y] = V;
    }

	for (size_t i = 0; i < playerNumber; i++)
	{
		currentTurn = 0;

		Player* P = &(players[i]);
		COORD* playerLocation = &((*P).playerLocation);

		do
		{
			bool onTop = false;

			(*playerLocation).X = rand() % fieldSize.X;
			(*playerLocation).Y = rand() % fieldSize.Y;

			for (size_t j = 0; j < i; j++)
			{
				COORD* P = &(players[j].playerLocation);
				if ((*P).X == (*playerLocation).X) { onTop = true; break; }
				if ((*P).Y == (*playerLocation).Y) { onTop = true; break; }
			}

			if (onTop) continue;
		} while (false);
		
		playfield[(*playerLocation).Y][(*playerLocation).X].Value = 0;

		(*P).A = true;
		(*P).H = 3;
	}
}