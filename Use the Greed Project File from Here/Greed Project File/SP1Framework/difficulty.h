#ifndef _difficulty
#define _difficulty


enum Difficulty{

	Novice = 1,
	Intermediate = 2,
	Advanced = 3

};

const unsigned int chances1[8] = { 15, 35, 55, 80, 100, 100, 100, 100 };	//genID = 0
const unsigned int chances2[8] = { 15, 30, 50, 70, 80, 90, 100, 100 };	//genID = 1
const unsigned int chances3[8] = { 10, 20, 30, 45, 60, 75, 90, 95 };	//genID = 2

#endif