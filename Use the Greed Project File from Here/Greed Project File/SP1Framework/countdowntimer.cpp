#include "countdowntimer.h"

bool hasStarted;//Done by Glence,Whether the game has started or not

void countdownUpdate(double T, Player& P)//Done by Glence,check whether timer ends ends 
{
	if (!hasStarted) return;
    if (!timer) return;

	unsigned int D = (unsigned int)(T * 10);

	P.timeLeft = P.timeLeft > D ? P.timeLeft - D : 0;

	if (P.timeLeft == 0) 
    {
        if (totalPlayers == 2) endTurn();
        else gameRunning = false;
    }
}