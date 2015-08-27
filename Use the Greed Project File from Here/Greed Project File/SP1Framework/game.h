#ifndef _GAME_H
#define _GAME_H

#include "Framework\timer.h"
#include "Framework\console.h"
#include <iostream>
#include <iomanip>
#include <vector>
using std::vector;
using std::string;

extern CStopWatch g_swTimer;
extern bool g_bQuitGame;

void init(void);      // initialize your variables, allocate memory, etc
void getInput(void);      // get input from player
void update(double dt); // update the game and the state of the game
void render(void);      // renders the current state of the game to the console
void shutdown(void);      // do clean up, free memory

//--Playfield variables

//Defines an enum to represent different highlighted states.
enum highlightedState
{
	NONE,
	NEARBY,
	TRAJECTORY
};

//---
//Defines a cell in the playfield.
//Variable highlight represents a highlighted state.
//---
struct PlayfieldCell
{
	unsigned int value;
	highlightedState highlight;
};

class Chances
{
public:
	unsigned int percentiles[8]; //Chances (in %) for 2, 3, 4, 5, 6, 7, 8, 9 respectively. Uses 1 if rolled value is less than required for 2.

	unsigned int rollValue(unsigned int maxValue = 9)
	{
		unsigned int rolledValue = rand() % 100;
		unsigned int returningValue = 1;

		while (returningValue < maxValue)
		{
			if (rolledValue < percentiles[returningValue - 1]) break;
			returningValue++;
		}

		return returningValue;
	}
};

//---
//Defines a playfield class.
//---
class Playfield
{
public:
	size_t sizeX;
	size_t sizeY;
	size_t numberLimit;

	vector<vector<PlayfieldCell>> cell;

	unsigned int chances[8];

	//Resizes the playfield to square.
	void resize(size_t width)
	{
		sizeX = width;
		sizeY = sizeX;

		cell.resize(sizeY);
	}

	//Resizes the playfield with given length and height.
	void resize(size_t width, size_t height)
	{
		sizeX = width;
		sizeY = height;

		cell.resize(sizeY);
	}
};

extern Playfield playfield;

//End of Playfield variables


//--Player variables

//---
//Defines a player.
//---
struct Player
{
	bool active;
	unsigned int playerNum;

	unsigned int hintsAvailable;
	unsigned int totalScore;
	string scoreText;

	COORD playerLocation;
};

extern Player player1;
extern Player player2;

//End of Player variables

//---
//Enumeration to store the control keys that your game will have
//---
enum EKEYS
{
	K_UP,
	K_UPLEFT,
	K_UPRIGHT,
	K_DOWN,
	K_DOWNLEFT,
	K_DOWNRIGHT,
	K_LEFT,
	K_RIGHT,
	K_UP2,
	K_UPLEFT2,
	K_UPRIGHT2,
	K_DOWN2,
	K_DOWNLEFT2,
	K_DOWNRIGHT2,
	K_LEFT2,
	K_RIGHT2,
	K_ESCAPE,
	K_SPACE,
	K_ENTER,
    K_RETRY,
	K_HINT,
    K_COUNT
};

//---
//Key state class extended for pressed and released events.
//---
class KeyState
{
public:
	char key;

	bool onPressed = false;
	bool onReleased = false;

	void ifHeld()
	{
		bool K = isKeyPressed(key);

		onPressed = K && !H;
		onReleased = !K && H;
	}

private:
	bool H = false;
};

//---
//Enum for the different screen states
//---
enum EGAMESTATES
{
    S_SPLASHSCREEN,
    S_MAINMENU,
    S_DIFFICULTY,
    S_GAME,
    S_COUNT
};

enum difficulty{

    Novice = 1,
    Intermediate = 2,
    Advanced = 3

};

enum playsize{
    mini = 1,
    normal = 2,
    big = 3
};

extern unsigned int currentTurn;

void hintFlush();
bool move(EKEYS keys, Player& Pointer);
Player* pickPlayer(unsigned int N);

void splashScreenWait();    // waits for time to pass in splash screen
void gameplay();            // gameplay logic
void clearScreen();         // clears the current screen and draw from scratch 
void renderSplashScreen();  // renders the splash screen
void renderGame();          // renders the game stuff
void renderMap();
// renders the map to the buffer first
void renderCharacter();     // renders the character into the buffer
void renderFramerate();     // renders debug information, frame rate, elapsed time, etc
void renderToScreen();      // dump the contents of the buffer to the screen, one frame worth of game

#endif // _GAME_H