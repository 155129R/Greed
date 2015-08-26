#include <iostream>
#include <sstream>
#include "PointSystem.h"
#include <string>
//int total=0;
//int points=0;
void addingPoints(int selectedNumber,int &total1,int &total2);
void convertTotalPoints (std::string &Result1,std::string Result2,int &total1,int total2);
//void PointCounter(int N, int points,std::string &Result);
//int main(void)
//{
//	addingPoints();
//	convertTotalPoints();

void addingPoints(int selectedNumber,int &total1,int &total2)
{
	//PlaySound(L"points.wav",NULL,SND_ASYNC);
	//std::cin >> Nvalue;
	if(currentTurn == 0)
	{
		int points=selectedNumber;
		total1+=static_cast<int>(points);
	}
	else if (currentTurn==1)
	{
		int points=selectedNumber;
		total2+=static_cast<int>(points);
	}
}

void convertTotalPoints (std::string &Result1,std::string &Result2,int &total1,int &total2)
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
