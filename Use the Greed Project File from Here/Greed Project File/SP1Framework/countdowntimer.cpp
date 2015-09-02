#include "countdowntimer.h"

bool hasStarted;

void countdownUpdate(double T, Player& P)
{
	if (!hasStarted) return;

	unsigned int D = (unsigned int)(T * 10);

	P.timeLeft = P.timeLeft > D ? P.timeLeft - D : 0;

	if (P.timeLeft == 0) endTurn();
}