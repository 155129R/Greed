#include <iostream>
#include <sstream>
#include "point.h"
#include <string>
//int total=0;
//int points=0;
void addingPoints(int N,int &total);
void convertTotalPoints (std::string &Result,int &total);
void PointCounter(int N, int points,std::string &Result);
//int main(void)
//{
//	addingPoints();
//	convertTotalPoints();

void addingPoints(int N,int &total)
{
	//PlaySound(L"points.wav",NULL,SND_ASYNC);
	//std::cin >> Nvalue;
	 int points=N;
	total+=static_cast<int>(points);
	
}

void convertTotalPoints (std::string &Result,int &total)
{
    std::ostringstream convert;
	convert << static_cast<int>(total);
	Result = convert.str();

	//std::cout<< Result;
}
//void PointCounter(int N,int points,std::string Result)
//{
//	addingPoints(N,points,total);
//	convertTotalPoints (Result,total);
//}