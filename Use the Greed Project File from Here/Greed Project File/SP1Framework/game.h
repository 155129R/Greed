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

enum highlightedState
{
	NONE,
	NEARBY,
	TRAJECTORY
};

struct playerField
{
	unsigned int Value;
	highlightedState Hint;
};

struct PSize
{
	size_t X;
	size_t Y;
};

extern vector<vector<playerField>> playfield;


//End of Playfield variables

//--Player variables

struct Player
{
	COORD playerLocation;
	unsigned int H;
	bool A;
};

//End of Player variables

// Enumeration to store the control keys that your game will have
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
    K_RETRY,
	K_HINT,
    K_COUNT
};

// Enumeration for the different screen states
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


struct VBool
{
	vector<vector<bool>> V;
};
extern PSize fieldSize;
extern int total1;
extern std::string Result1;
extern int total2;
extern std::string Result2;
extern unsigned int currentTurn;

void hinting(COORD hintCoord);
void hintFlush();
bool move(EKEYS keys, Player& Pointer);

void splashScreenWait();    // waits for time to pass in splash screen
void gameplay();            // gameplay logic
void moveCharacter();       // moves the character, collision detection, physics, etc
void clearScreen();         // clears the current screen and draw from scratch 
void renderSplashScreen();  // renders the splash screen
void renderGame();          // renders the game stuff
void renderMap();
// renders the map to the buffer first
void renderCharacter();     // renders the character into the buffer
void renderFramerate();     // renders debug information, frame rate, elapsed time, etc
void renderToScreen();      // dump the contents of the buffer to the screen, one frame worth of game

#endif // _GAME_H