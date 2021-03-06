#include "game.h"

#include "board.h"
#include "move.h"
#include "hinting.h"
#include "gameGUI.h"
#include "HighScore.h"
#include "startmenu.h"
#include "modemenu.h"
#include "countdowntimer.h"
#include "tutorial.h"
bool hintOn;
bool timer;
bool gameRunning;

double g_dElapsedTime;
double g_dDeltaTime;

const short fontSize = 28;
const short consoleX = 100;
const short consoleY = 35;

COORD renderOffset;

unsigned int totalPlayers = 1;
Player player1;
Player player2;
const EKEYS playerKeys1[] = { K_UP, K_UPLEFT, K_UPRIGHT, K_DOWN, K_DOWNLEFT, K_DOWNRIGHT, K_LEFT, K_RIGHT };
const EKEYS playerKeys2[] = { K_UP2, K_UPLEFT2, K_UPRIGHT2, K_DOWN2, K_DOWNLEFT2, K_DOWNRIGHT2, K_LEFT2, K_RIGHT2 };

const Directions directions[] = { DIR_UP, DIR_UPLEFT, DIR_UPRIGHT, DIR_DOWN, DIR_DOWNLEFT, DIR_DOWNRIGHT, DIR_LEFT, DIR_RIGHT };

Chances boardChances;

Playfield playfield;

playsize dim = normal;
int Dchoice = 1;
std::string Result1;
std::string Result2;
int total1;
int total2;
int chooseDiff();
int chooseSize();
void changeDiff(int Dchoice);
void changeSize();
void boardGen();
void printBoard();
void changeScreen();
void printNumber(COORD C, unsigned int N, WORD col);
void renderhighscore();
void renderprinthighscore();
void rendermainmenu();
void inputhighscore();
void inputprintallhighscore();
unsigned int currentTurn;
void renderprinttimehighscore();
void inputprinttimehighscore();

// Game specific variables here
EGAMESTATES g_eGameState = S_SPLASHSCREEN;
double  g_dBounceTime; // this is to prevent key bouncing, so we won't trigger keypresses more than once

// Console object
Console g_Console(consoleX, consoleY, "Greed Reloaded");

//-----Core functions

//--------------------------------------------------------------
// Purpose  : Initialisation function
//            Initialize variables, allocate memory, load data from file, etc. 
//            This is called once before entering into your main loop
// Input    : void
// Output   : void
//--------------------------------------------------------------
void init( void )
{
	//--Defining keystates

	//Player 1

        keyStates[K_UP].key = VK_NUMPAD8;
	    keyStates[K_UPLEFT].key = VK_NUMPAD7;
	    keyStates[K_UPRIGHT].key = VK_NUMPAD9;
	    keyStates[K_DOWN].key = VK_NUMPAD2;
	    keyStates[K_DOWNLEFT].key = VK_NUMPAD1;
	    keyStates[K_DOWNRIGHT].key = VK_NUMPAD3;
	    keyStates[K_LEFT].key = VK_NUMPAD4;
	    keyStates[K_RIGHT].key = VK_NUMPAD6;


	//Player 2
        keyStates[K_UP2].key = VK_NUMPAD8;
	    keyStates[K_UPLEFT2].key = VK_NUMPAD7;
	    keyStates[K_UPRIGHT2].key = VK_NUMPAD9;
	    keyStates[K_DOWN2].key = VK_NUMPAD2;
	    keyStates[K_DOWNLEFT2].key = VK_NUMPAD1;
	    keyStates[K_DOWNRIGHT2].key = VK_NUMPAD3;
	    keyStates[K_LEFT2].key = VK_NUMPAD4;
	    keyStates[K_RIGHT2].key = VK_NUMPAD6;

	//Others
	keyStates[K_ESCAPE].key = VK_ESCAPE;
	keyStates[K_SPACE].key = VK_SPACE;
	keyStates[K_RETRY].key = 'R';
	keyStates[K_HINT].key = 'H';

	//--End of Defining keystates

	// rand() initialization
	srand((unsigned int)time(0)); rand();

    // Set precision for floating point output
    g_dElapsedTime = 0.0;
    g_dBounceTime = 0.0;

    // sets the initial state for the game
    g_eGameState = S_MAINMENU;

    // sets the width, height and the font name to use in the console
    g_Console.setConsoleFont(0, fontSize, L"Consolas");
}

//--------------------------------------------------------------
// Purpose  : Getting all the key press states
//            This function checks if any key had been pressed since the last time we checked
//            If a key is pressed, the value for that particular key will be true
//
//            Add more keys to the enum in game.h if you need to detect more keys
//            To get other VK key defines, right click on the VK define (e.g. VK_UP) and choose "Go To Definition" 
//            For Alphanumeric keys, the values are their ascii values (uppercase).
// Input    : Void
// Output   : void
//--------------------------------------------------------------
void getInput( void )
{   
	for (unsigned int i = 0; i < K_COUNT; i++) keyStates[i].ifHeld();
}

//--------------------------------------------------------------
// Purpose  : Update function
//            This is the update function
//            double dt - This is the amount of time in seconds since the previous call was made
//
//            Game logic should be done here.
//            Such as collision checks, determining the position of your game characters, status updates, etc
//            If there are any calls to write to the console here, then you are doing it wrong.
//
//            If your game has multiple states, you should determine the current state, and call the relevant function here.
//
// Input    : dt = deltatime
// Output   : void
//--------------------------------------------------------------
void update(double dt)
{
    // get the delta time
    g_dElapsedTime += dt;
    g_dDeltaTime = dt;

    switch (g_eGameState)
    {
	//case S_SPLASHSCREEN: splashScreenWait(); // game logic for the splash screen
	//	break;
	case S_DIFFICULTY: processDiff();
		break;
    case S_PLAYERMENU: processPlayerMenu();
        break;
	case S_LOADING1: load1process();
		break;
	case S_LOADING2: load2process();
		break;
	case S_GAME: gameplay(dt); // gameplay logic when we are in the game
		break;
	case S_MAINMENU: {selectMenuInput();}
		break;
    case S_P1CTRL: processPlayer1Control();
        break;
    case S_P2CTRL: processPlayer2Control();
        break;
    case S_OPTION: processOptionsMenu();
        break;
	case S_HIGHSCORE: inputhighscore();
		break;
	case S_PRINTHIGHSCORE: {inputprintallhighscore();}
		break;
	case S_PRINTTIMEHIGHSCORE:{inputprinttimehighscore();}
							  break;
	case S_MODE: processmodeMenu(); 
		break;
	case S_TIMEHIGHSCORECHECK:processmodeMenuHighScore();//checking for timed or normal mode
		break;
  }
}

//--------------------------------------------------------------
// Purpose  : Reset before exiting the program
//            Do your clean up of memory here
//            This is called once just before the game exits
// Input    : Void
// Output   : void
//--------------------------------------------------------------
void shutdown( void )
{
    // Reset to white text on black background
    colour(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);

    g_Console.clearBuffer();
}

//--------------------------------------------------------------
// Purpose  : Render function is to update the console screen
//            At this point, you should know exactly what to draw onto the screen.
//            Just draw it!
//            To get an idea of the values for colours, look at console.h and the URL listed there
// Input    : void
// Output   : void
//--------------------------------------------------------------
void render()
{
    clearScreen();      // clears the current screen and draw from scratch 
    switch (g_eGameState)
    {
	/*case S_SPLASHSCREEN: renderSplashScreen();
		break;*/
    case S_PLAYERMENU: renderPlayerMenu();
        break;
	case S_DIFFICULTY: renderDiff();
		break;
	case S_LOADING1: renderLoading1();
		break;
	case S_LOADING2: renderLoading2();
		break;
	case S_GAME: renderGame();
		break;
    case S_P1CTRL: renderPlayerControl();
        break;
    case S_P2CTRL: renderPlayerControl();
        break;
	case S_MAINMENU:rendermainmenu();
		break;
    case S_OPTION: renderOptionsMenu();
        break;
	case S_HIGHSCORE: renderhighscore();
			break;
	case S_PRINTHIGHSCORE: renderprinthighscore();
		    break;
	case S_PRINTTIMEHIGHSCORE:renderprinttimehighscore();
							  break;
	case S_MODE:renderMode(); 
			break;
	case S_TUTORIAL:renderTutorial();
		break;
	case S_TIMEHIGHSCORECHECK:renderMode();
		break;
    }
   // renderFramerate();  // renders debug information, frame rate, elapsed time, etc
    renderToScreen();   // dump the contents of the buffer to the screen, one frame worth of game
}
void inputprintallhighscore()//Done by Jeffrey, inputs for resetting highscore for normal mode
{
	NameInputKeys();
	ResetSelectedHighScoreInput();
}
void inputprinttimehighscore()//Done by Jeffrey, inputs for resetting highscore for Timed Mode
{
	NameInputKeys();
	ResetSelectedHighScoreInputTime();
}

void inputhighscore()//Done by Jeffrey,Inputting name for highscore
{
	NameInputKeys();
	NameInput();
}

void splashScreenWait()    // waits for time to pass in splash screen
{
    if (g_dElapsedTime > 3.0) // wait for 3 seconds to switch to game mode, else do nothing
    { 
        g_eGameState = S_PLAYERMENU;
    }
}

//-----Gameplay logic

void gameplay(double dt) // Game Control and Game flow
{
	//Input section

	//Players
	if (!gameRunning) goto BB;

	Player* P; //Pointer for player
	const EKEYS* PK; //Pointer for keys array

	P = pickPlayer(currentTurn);

	countdownUpdate(dt, *P);

	switch (currentTurn)
	{
	case 0: PK = playerKeys1; break;
	case 1: PK = playerKeys2; break;
	}

	//Player controls
	for (unsigned int i = 0; i < 8; i++)
	{
		EKEYS K = PK[i];
		if (keyStates[K].onPressed)
		if (move(*P, directions[i])) goto AA;
	}

	if (keyStates[K_HINT].onPressed)
	{
		if (!hintOn && (*P).hintsAvailable > 0)
		{
			hintOn = true;
			(*P).hintsAvailable--;

			showHints((*P).playerLocation);
		}
	}

	goto BB;
AA:
	endTurn();
BB:

	//Global controls

	if (keyStates[K_RETRY].onPressed) //Retry
	{
		PlaySound(L"sound\\retry.wav" ,NULL,SND_ASYNC);
		total1 = 0;
		total2 = 0;
		Result1.clear();
		Result2.clear();
		boardGen();
		void render();
	}

	// quits the game if player hits the escape key
	/*if (keyStates[K_ESCAPE].onPressed) g_bQuitGame = true;*/



	if(isKeyPressed(VK_ESCAPE))//Print out highscore after ending game
	{
		g_eGameState=S_HIGHSCORE;
        PlayerName = "";
		Sleep(200);
	}
	//End of Input section
}

//-----Rendering

void clearScreen()
{
    // Clears the buffer with this colour attribute
    g_Console.clearBuffer(0x00);
}
void rendermainmenu()//Done by Jeffrey,Rendereing the main menu
{
	renderSplashScreen();
	renderMenu();
	total1 = 0;
	total2 = 0;
	Result1.clear();
	Result2.clear();
}
void renderhighscore()//Done by Jeffrey,Render highscore after game ends
{
	AskforInput();
	displayPlayerName();
	print();

}
void renderprinthighscore()//Done by Jeffrey,Render all highscore for normal mode
{
	printall();
	renderResetSelectedHighScore();
}
void renderprinttimehighscore()//Done by Jeffrey,Render all highscore for timed mode
{
	printalltime();
	renderResetSelectedHighScore();
}
void renderSplashScreen()  // renders the splash screen
{
    string gamename;
    COORD c = g_Console.getConsoleSize();
	
    c.Y = 0;
    c.X = 0; 
	std::ifstream myfile;
    myfile.open("display\\mainscreen.txt");
    while (myfile.good())
	{
        std::getline(myfile, gamename);
        g_Console.writeToBuffer(c, gamename, 0x0A);
        c.Y += 1;
    }
}

void renderGame()//Done by Gary,Render the whole game
{
	renderOffset.X = (consoleX - playfield.sizeX) / 2;
	renderOffset.Y = 0;

    renderMap();        // renders the map to the buffer first
    renderCharacter();  // renders the character into the buffer
	renderGUI();
}

void renderGUI()//Done by Gary,Render user interface in-game
{
	COORD loc = renderOffset;
	loc.X -= 9;
	loc.Y += 1;

	drawPlayerGUI(loc, 0);

	if (totalPlayers == 2)
	{
		loc = renderOffset;
		loc.X += playfield.sizeX + 1;
		loc.Y += 1;

		drawPlayerGUI(loc, 1);
	}

	loc.X = 0;
	loc.Y = 0;
}

void renderFramerate()//Render framerate
{
    //COORD c;
    //// displays the framerate
    //std::ostringstream ss;
    //ss << std::fixed << std::setprecision(3);
    //ss << 1.0 / g_dDeltaTime << "fps";
    //c.X = g_Console.getConsoleSize().X - 9;
    //c.Y = 0;
    //g_Console.writeToBuffer(c, ss.str());

    //// displays the elapsed time
    //ss.str("");
    //ss << g_dElapsedTime << "secs";
    //c.X = 0;
    //c.Y = 0;
    //g_Console.writeToBuffer(c, ss.str(), 0x59);
}

void renderToScreen()
{
    // Writes the buffer to the console, hence you will see what you have written
    g_Console.flushBufferToConsole();
}

//-----Others

Player* pickPlayer(unsigned int N)//Done By Gary,Pick either Player 1 or 2
{
	Player* P;

	switch (N)
	{
	case 0: P = &player1; break;
	case 1: P = &player2; break;
	}

	return P;
}

void playerInit(Player& P)//Done by Gary,Intialise the player at the start of the game
{
	P.active = true;
	P.hintsAvailable = 3;
	P.totalScore = 0;
	P.timeLeft = 100;
}

void gameInit()//Done by Gary,Intialise game hints,turns and starting turn at start of the game	
{
	currentTurn = 0;
	hintOn = false;
	hasStarted = false;
	gameRunning = true;
}

void endTurn()//Done by Glence ends the turn for player
{
	Player *P = pickPlayer(currentTurn);
    switch (totalPlayers)
    {
    case 1: 
        currentTurn = (currentTurn < totalPlayers - 1) ? currentTurn + 1 : 0;
        P = pickPlayer(currentTurn);
        break;


    case 2:
        (*P).timeLeft = (*P).timeLeft < 30 ? 30 : (*P).timeLeft;	
        currentTurn = (currentTurn < totalPlayers - 1) ? currentTurn + 1 : 0;
        P = pickPlayer(currentTurn);
        break;
    }

	hintOn = false;
	hasStarted = true;
	hideHints();
	findMoves((*P).playerLocation);
}