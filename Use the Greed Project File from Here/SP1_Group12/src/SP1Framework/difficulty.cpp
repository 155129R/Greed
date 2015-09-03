#include "game.h"
#include "difficulty.h"
#include <fstream>

Difficulty level = Novice;
unsigned int genID = 0;

//S_LOADING 1

void changeDiff()//Done by Sham, Changing difficulty
{
	switch (level){
	case 1: level = Novice; break;

	case 2: level = Intermediate; break;

	case 3: level = Advanced; break;

	default: g_Console.writeToBuffer(4, 4, "Invalid option");
		//_eGameState = S_PLAYERMENU;

	}
}

void applyDiff()//Done by Sham,change board according to difficulty

{
	if (level == Novice)
	{
		playfield.resize(30,30);
		playfield.numberLimit = 5;
        genID = 0;
     
	}

	else if (level == Intermediate){
		playfield.resize(25,25);
		playfield.numberLimit = 7;
        genID = 1;
	}
	else if (level == Advanced){

		playfield.resize(20,20);
		playfield.numberLimit = 9;
        genID = 2;
	}

}

void chancesofNumber()// Done by Glence, Set chances of number appearing for difficulty
{

	const unsigned int* P;
	switch (genID)
	{
	    case 0: P = chances1;
            break;
	    case 1: P = chances2;
            break;
        case 2: P = chances3;
            break;
	}

	for (unsigned int i = 0; i < 8; i++) boardChances.percentiles[i] = P[i];
}

//S_DIFFICULTY
void renderDiff()// Done by sham,render difficulty screen 
{
	std::string novice;
	std::string intermediate;
	std::string advanced;
	COORD c = g_Console.getConsoleSize();

	g_Console.writeToBuffer(0, 0, "Choose Your Difficulty (1,2, or 3)", 0x0B);

	c.Y = 4;
	c.X = 4;

	std::ifstream novicefile;
	novicefile.open("display\\Easy.txt");
	for (int i = 0; novicefile.good(); i++){
		std::getline(novicefile, novice);
		g_Console.writeToBuffer(c, novice, 0x03);
		c.Y += 1;
	}

	c.Y += 2;


	std::ifstream intermediatefile;
	intermediatefile.open("display\\Normal.txt");
	for (int i = 0; intermediatefile.good(); i++){
		std::getline(intermediatefile, intermediate);
		g_Console.writeToBuffer(c, intermediate, 0x03);
		c.Y += 1;
	}

	c.Y += 2;


	std::ifstream advancedfile;
	advancedfile.open("display\\Hard.txt");
	for (int i = 0; advancedfile.good(); i++){
		std::getline(advancedfile, advanced);
		g_Console.writeToBuffer(c, advanced, 0x03);
		c.Y += 1;
	}

}

void processDiff() //Done by Sham, processing the difficulty chosen
{

	if((isKeyPressed('1'))||(isKeyPressed(VK_NUMPAD1))){
	    level = static_cast<Difficulty>(1);
	    g_eGameState = S_LOADING1;
    }
    if((isKeyPressed('2'))||(isKeyPressed(VK_NUMPAD2))){
	    level = static_cast<Difficulty>(2);
	    g_eGameState = S_LOADING1;
    }
    if((isKeyPressed('3'))||(isKeyPressed(VK_NUMPAD3))){
	    level = static_cast<Difficulty>(3);
	    g_eGameState = S_LOADING1;
    }
	  if (isKeyPressed(VK_ESCAPE))
	  {
		  g_eGameState=S_PLAYERMENU;
	  }

}