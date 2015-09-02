#ifndef _POINT_H
#define _POINT_H
#include <iostream>
#include <string>
#include <sstream>
#include <Windows.h>

void addingPoints(int selectedNumber, int &total1, int&total2);
void convertTotalPoints(std::string &Result1, std::string &Result2, int &total1, int &total2);
extern int V;
extern int total1;
extern int total2;
extern std::string Result1;
extern std::string Result2;

extern unsigned int currentTurn;
//void PointCounter(int N,int points, std::string Result);
#endif //_POINT_H