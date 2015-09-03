#ifndef _POINT_H
#define _POINT_H
#include <iostream>
#include <string>
#include <sstream>
#include <Windows.h>

void addingPoints(int selectedNumber, int &total1, int&total2);//add points into total amount of points for player
void convertTotalPoints(std::string &Result1, std::string &Result2, int &total1, int &total2);//conver total points into a string for display
extern int V;
extern int total1;//total amount of points for first player
extern int total2;//total amount of points for second player
extern std::string Result1;//first player points converted into a string
extern std::string Result2;//second player points converted into a string

extern unsigned int currentTurn;
//void PointCounter(int N,int points, std::string Result);
#endif //_POINT_H