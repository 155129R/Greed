#ifndef _GAME_H
#define _GAME_H

#include "Framework\timer.h"
#include "Framework\console.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>
using std::vector;
using std::string;

extern CStopWatch g_swTimer;
extern bool g_bQuitGame;//quit game

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
struct PlayfieldCell//For the board individual cells
{
	unsigned int value;
	highlightedState highlight;
};

class Chances// calculate chances of number appearing in the board
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
class Playfield//For the board
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

//Defines a player.
struct Player//for keeping track of score,time left(timed mode) and hints left
{
	bool active;
	unsigned int playerNum;

	unsigned int hintsAvailable;
	unsigned int totalScore;
	unsigned int timeLeft; //100 represents 10 seconds.


	COORD playerLocation;
};

extern Player player1;
extern Player player2;
extern unsigned int totalPlayers;
//End of Player variables

//---
//Enumeration to store the control keys that your game will have
//---
enum EKEYS//For keyboard inputs
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
class KeyState //Check whether button is pressed or not
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

//Enum for the different screen states

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
	S_PRINTHIGHSCORE,
	S_PRINTTIMEHIGHSCORE,
	S_TIMEHIGHSCORECHECK
    
};

enum playsize{		//for difficulty also
    mini = 1,
    normal = 2,
    big = 3
};


extern unsigned int currentTurn;
extern bool hintOn;
extern KeyState keyStates[K_COUNT];
Player* pickPlayer(unsigned int N);
extern unsigned int genID;
extern bool timer;
extern bool gameRunning;

void splashScreenWait();    // waits for time to pass in splash screen
void gameplay(double dt);            // gameplay logic
void clearScreen();         // clears the current screen and draw from scratch 
void renderSplashScreen();  // renders the splash screen
void setcursor(bool visible, DWORD size); //Changes cursor "visibility"
void renderGame();          // renders the game stuff
void renderCharacter();     // renders the character to buffer
void renderGUI();			//render user interface
void renderFramerate();     // renders debug information, frame rate, elapsed time, etc
void renderToScreen();      // dump the contents of the buffer to the screen, one frame worth of game
void changeDiff();          //Changes the difficulty according to user's chosen difficulty
void applyDiff();           //Apply changes for difficulty
void processPlayerMenu();	//Process Player input for playermenu
void renderPlayerMenu();	//Render Player Menu screen
void renderMode();			//Render the modes screen
void applyplayer();			//set 1 or 2 player for game
void totalplayerNumber();	//find total number of players
void processOptionsMenu();	//Process options input
void renderOptionsMenu();	//Render Option Screen
void renderPlayerControl();	//Render PLayer Control Scheme
void processPlayer1Control();//Set control scheme for player 1
void processPlayer2Control();//set control scheme for player 2
void load1process();		//Check for difficulty ,player and apply
void load2process();		//Render the board and game
void processDiff();			//Proccessing difficulty chosen
void renderDiff();			//Render Difficulty Screen
void renderLoading1();		// Render Loading screen 1
void renderLoading2();		//Render loading screen 2
void chancesofNumber();		//set chances of number appearing for difficulty
void processmodeMenu();		//Proccess mode menu inputs
void playerInit(Player& P);	//Initialise the player at the start of the game
void gameInit();			//Initialise gamehints,turns and starting turn at start of the game
void endTurn();				//ends the turn for the player
void processmodeMenuHighScore();//process inputs for printing all highscore boards
extern COORD renderOffset;
extern Console g_Console;
extern EGAMESTATES g_eGameState;

#endif