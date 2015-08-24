#include "game.h"

void boardGen(){
	playfield.resize(playfieldY);

    for (unsigned int Y = 0; Y < playfieldY; Y++)
    {
        vector<PField> V(playfieldX);

        for (unsigned int X = 0; X < playfieldX; X++)
		{
			unsigned int chances[8] = {50, 60, 70, 75, 80, 90, 93, 95}; //Chances (in %) for 2, 3, 4, 5, 6, 7, 8, 9; if chance is less than getting a 2, use 1.

			unsigned int R = rand() % 100;

			V[X].V = 1;
            
			while (V[X].V < numbers)
			{
				if (R < chances[V[X].V - 1]) break;
				V[X].V++;
			}
        }
        playfield[Y] = V;
    }

	for (size_t i = 0; i < playerNumber; i++)
	{
		currentTurn = 0;

		SGameChar* S = &(g_sChar[i]);
		COORD* L = &((*S).m_cLocation);

		do
		{
			bool onTop = false;

			(*L).X = rand() % playfieldX;
			(*L).Y = rand() % playfieldY;

			for (size_t j = 0; j < i; j++)
			{
				COORD* P = &(g_sChar[j].m_cLocation);
				if ((*P).X == (*L).X) { onTop = true; break; }
				if ((*P).Y == (*L).Y) { onTop = true; break; }
			}

			if (onTop) continue;
		} while (false);
		
		playfield[(*L).Y][(*L).X].V = 0;

		(*S).m_bActive = true;
	}

	hinting(g_sChar[currentTurn].m_cLocation);
}

void renderMap()
{
	for (unsigned int Y = 0; Y < playfieldY; Y++)
    {
        for (unsigned int X = 0; X < playfieldX; X++)
        {
            gotoXY(X, Y);
            
			char V = playfield[Y][X].V;

			WORD C;

			switch (playfield[Y][X].H)
			{
			    case NONE: C = 0x9F; break;
			    case NEARBY: C = 0xDF; break;
			    case TRAJECTORY: C = 0x5F; break;
			}

            g_Console.writeToBuffer(X, Y, static_cast<char>(V == 0 ? 0 : V + 48), C);
            
        }
    }
    g_Console.writeToBuffer(0, playfield.size() + 1, "Total Points: ", 0x59);
	g_Console.writeToBuffer(0, playfield.size() + 2, currentTurn + '0', 0x59);
}

