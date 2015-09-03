#include "points.h"


void addingPoints(int V,int &total1,int &total2);
void convertTotalPoints (std::string &Result1,std::string Result2,int &total1,int total2);

void addingPoints(int V,int &total1,int &total2)//Done by Jeffrey, add points to the total amount of points for player
{
	PlaySound(L"sound\\points.wav",NULL,SND_ASYNC);
	if(currentTurn == 0)
	{
		int points=V;
		total1+=static_cast<int>(points);
	}
	else if (currentTurn==1)
	{
		int points=V;
		total2+=static_cast<int>(points);
	}
}

void convertTotalPoints (std::string &Result1,std::string &Result2,int &total1,int &total2)//Done by Jeff ,Convert total points into a string for display
{
	if(currentTurn==0)
	{
    std::ostringstream convert;
	convert << static_cast<int>(total1);
	Result1 = convert.str();
	}
	else if (currentTurn==1)
	{
		std::ostringstream convert;
		convert << static_cast<int>(total2);
		Result2 = convert.str();
	}
	//std::cout<< Result;
}
