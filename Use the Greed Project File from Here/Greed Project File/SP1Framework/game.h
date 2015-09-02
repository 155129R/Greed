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

extern Chances boardChances;

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
extern unsigned int totalPlayers;
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
    K_RETRY,
	K_HINT,
    K_COUNT
};

//---
//Key state class extended for pressed and released events.
extern bool p1KeySet;
extern bool p2KeySet;
//---
class KeyState
{
public:
	char key;

	bool onPressed;
	bool onReleased;

	KeyState()
	{
		init();
	}
	KeyState(char K)
	{
		key = K;
		init();
	}

	void ifHeld()
	{
		bool K = isKeyPressed(key);

		onPressed = K && !H;
		onReleased = !K && H;

		H = K;
	}

private:
	bool H;

	void init()
	{

		onPressed = false;
		onReleased = false;
		H = false;
	}
};

//---
//Enum for the different screen states
//---
enum EGAMESTATES
{
    S_SPLASHSCREEN,
    S_MAINMENU,
    S_TUTORIAL,
    S_PLAYERMENU,
    S_MODE,
	S_LOADING1,
	S_LOADING2,
    S_DIFFICULTY,
    S_GAME,
    S_COUNT,
	S_OPTION,
    S_P1CTRL,
    S_P2CTRL,
	S_HIGHSCORE,
	S_PRINTHIGHSCORE
    
};

enum playsize{
    mini = 1,
    normal = 2,
    big = 3
};

extern unsigned int currentTurn;
extern bool hintOn;
extern KeyState keyStates[K_COUNT];
Player* pickPlayer(unsigned int N);
extern unsigned int genID;


void splashScreenWait();    // waits for time to pass in splash screen
void gameplay();            // gameplay logic
void clearScreen();         // clears the current screen and draw from scratch 
void renderSplashScreen();  // renders the splash screen
void setcursor(bool visible, DWORD size); //Changes cursor "visibility"
void renderGame();          // renders the game stuff
void renderCharacter();     // renders the character to buffer
void renderGUI();
void renderFramerate();     // renders debug information, frame rate, elapsed time, etc
void renderToScreen();      // dump the contents of the buffer to the screen, one frame worth of game
void changeDiff();          //Changes the difficulty according to user's chosen difficulty
void applyDiff();           //Apply changes for difficulty
void processPlayerMenu();
void renderPlayerMenu();
void applyplayer();
void totalplayerNumber();
void processOptionsMenu();
void renderOptionsMenu();
void renderPlayerControl();
void processPlayer1Control();
void renderPlayer2Control();
void processPlayer2Control();
void load1process();
void load2process();
void processDiff();
void renderDiff();
void renderLoading1();
void renderLoading2();
void chancesofNumber();

extern COORD renderOffset;
extern Console g_Console;
extern EGAMESTATES g_eGameState;


#endif