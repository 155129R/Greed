#include "move.h"

int coordX = 0;
int coordY = 0;
int selectedNumber = 0;//the value of the number

bool move(EKEYS key, Player& Pointer){
    if(check(key,Pointer) == true){
        moveChar(Pointer);
        return true;
    }
    else{
        return false;
    }
}

bool check(EKEYS key, Player& Pointer)//use -1,0,1
{
    switch(key)
    {
    case K_UP:                                      ::coordY = -1;  break;
    case K_DOWN:                                    ::coordY = 1;   break;
    case K_LEFT:                    ::coordX = -1;                  break;
    case K_RIGHT:                   ::coordX = 1;                   break;
    case K_DOWNLEFT:                ::coordX = -1;  ::coordY = 1;   break;
    case K_DOWNRIGHT:               ::coordX = 1;   ::coordY = 1;   break;
    case K_UPLEFT:                  ::coordX = -1;  ::coordY = -1;  break;
    case K_UPRIGHT:                 ::coordX = 1;   ::coordY = -1;  break;
    
    }
	int currentcoordX = Pointer.playerLocation.X + coordX;//cuurent location on player in direction by one step
	int currentcoordY = Pointer.playerLocation.Y + coordY;

	if (currentcoordX < 0) return false;
	if (currentcoordY < 0) return false;
	if (currentcoordX >= (signed)fieldSize.X) return false;
	if (currentcoordY >= (signed)fieldSize.Y) return false;

	::selectedNumber = playfield[currentcoordY][currentcoordX].Value;//the value of the number
	if (selectedNumber == 0) return false;

	if (currentcoordX + (selectedNumber - 1)*coordX < 0) return false;
	if (currentcoordY + (selectedNumber - 1)*coordY < 0) return false;
	if (currentcoordX + (selectedNumber - 1)*coordX >= (signed)fieldSize.X) return false;
	if (currentcoordY + (selectedNumber - 1)*coordY >= (signed)fieldSize.Y) return false;

	for (int i = 1; i < selectedNumber; i++)
	{
		int finalcoordX = currentcoordX + i * coordX; //where the player will end up
		int finalcoordY = currentcoordY + i * coordY;

		if (playfield[finalcoordY][finalcoordX].Value == 0) return false;
	}

	
	return true;
    
}

void moveChar(Player& Pointer){
    for (int i = 0; i < ::selectedNumber; i++)
	{
		Pointer.playerLocation.X += ::coordX;
		Pointer.playerLocation.Y += ::coordY;

		playfield[Pointer.playerLocation.Y][Pointer.playerLocation.X].Value = 0;
	}

}