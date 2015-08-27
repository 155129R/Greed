// This is the main file for the game logic and function
//
//
#include "game.h"
#include <fstream>
#include <sstream>
#include <string>

double  g_dElapsedTime;
double  g_dDeltaTime;
size_t numbers = 5;
COORD consoleSize;


bool hintOn = false;
vector<vector<playerField>> playfield;
PSize fieldSize;

int Dchoice = 1;
std::string Result1;
std::string Result2;
int total1;
int total2;

int chooseDiff();
int chooseSize();
void changeDiff(int Dchoice);
void changeSize();

void changeScreen();
unsigned int currentTurn;
bool g_abKeyPressed[K_COUNT];
const size_t playerNumber = 2;
Player players[playerNumber];

// Game specific variables here
EGAMESTATES g_eGameState = S_SPLASHSCREEN;
double  g_dBounceTime; // this is to prevent key bouncing, so we won't trigger keypresses more than once

// Console object
Console g_Console(80,50, "Greed Reloaded");


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
	// rand() initialization
	srand((unsigned int)time(0)); rand();

    // Set precision for floating point output
    g_dElapsedTime = 0.0;
    g_dBounceTime = 0.0;

    // sets the initial state for the game
    g_eGameState = S_SPLASHSCREEN;

	//Defining playfieldSize
	fieldSize.X = 30;
	fieldSize.Y = 30;

    // sets the width, height and the font name to use in the console
    g_Console.setConsoleFont(0, 25, L"Consolas");
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
    //Alphanumeric Keys
    //Player 1
    g_abKeyPressed[K_UP]            = isKeyPressed('W');
    g_abKeyPressed[K_UPLEFT]        = isKeyPressed('Q');
	g_abKeyPressed[K_UPRIGHT]       = isKeyPressed('E');
    g_abKeyPressed[K_DOWN]          = isKeyPressed('X');
    g_abKeyPressed[K_DOWNLEFT]      = isKeyPressed('Z');
	g_abKeyPressed[K_DOWNRIGHT]     = isKeyPressed('C');
    g_abKeyPressed[K_LEFT]          = isKeyPressed('A');
    g_abKeyPressed[K_RIGHT]         = isKeyPressed('D');

    //Player 2
    g_abKeyPressed[K_UP2]            = isKeyPressed('W');
    g_abKeyPressed[K_UPLEFT2]        = isKeyPressed('Q');
	g_abKeyPressed[K_UPRIGHT2]       = isKeyPressed('E');
    g_abKeyPressed[K_DOWN2]          = isKeyPressed('X');
    g_abKeyPressed[K_DOWNLEFT2]      = isKeyPressed('Z');
	g_abKeyPressed[K_DOWNRIGHT2]     = isKeyPressed('C');
    g_abKeyPressed[K_LEFT2]          = isKeyPressed('A');
    g_abKeyPressed[K_RIGHT2]         = isKeyPressed('D');

//----------------------------------------------------------------------------------------
    //NUMPAD
    //PLAYER1
   /* g_abKeyPressed[K_UP]            = isKeyPressed(VK_NUMPAD8);
    g_abKeyPressed[K_UPLEFT]        = isKeyPressed(VK_NUMPAD7);
	g_abKeyPressed[K_UPRIGHT]       = isKeyPressed(VK_NUMPAD9);
    g_abKeyPressed[K_DOWN]          = isKeyPressed(VK_NUMPAD2);
    g_abKeyPressed[K_DOWNLEFT]      = isKeyPressed(VK_NUMPAD1);
	g_abKeyPressed[K_DOWNRIGHT]     = isKeyPressed(VK_NUMPAD3);
    g_abKeyPressed[K_LEFT]          = isKeyPressed(VK_NUMPAD4);
    g_abKeyPressed[K_RIGHT]         = isKeyPressed(VK_NUMPAD6);
*/
    //PLAYER2
   /* g_abKeyPressed[K_UP2]            = isKeyPressed(VK_NUMPAD8);
    g_abKeyPressed[K_UPLEFT2]        = isKeyPressed(VK_NUMPAD7);
	g_abKeyPressed[K_UPRIGHT2]       = isKeyPressed(VK_NUMPAD9);
    g_abKeyPressed[K_DOWN2]          = isKeyPressed(VK_NUMPAD2);
    g_abKeyPressed[K_DOWNLEFT2]      = isKeyPressed(VK_NUMPAD1);
	g_abKeyPressed[K_DOWNRIGHT2]     = isKeyPressed(VK_NUMPAD3);
    g_abKeyPressed[K_LEFT2]          = isKeyPressed(VK_NUMPAD4);
    g_abKeyPressed[K_RIGHT2]         = isKeyPressed(VK_NUMPAD6);*/

    g_abKeyPressed[K_SPACE]         = isKeyPressed(VK_SPACE);
    g_abKeyPressed[K_ESCAPE]        = isKeyPressed(VK_ESCAPE);
    g_abKeyPressed[K_RETRY]         = isKeyPressed('R');
	g_abKeyPressed[K_HINT]          = isKeyPressed('H');
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
        case S_SPLASHSCREEN : splashScreenWait(); // game logic for the splash screen
            break;
        case S_DIFFICULTY: processDiff();
            break;
        case S_LOADING1: load1process();
            break;
        case S_LOADING2: load2process();
            break;
        case S_GAME: gameplay(); // gameplay logic when we are in the game
            break;
    }
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
        case S_SPLASHSCREEN: renderSplashScreen();
            break;
        case S_DIFFICULTY: renderDiff();
            break;
        case S_LOADING1: renderLoading1();
            break;
        case S_LOADING2: renderLoading2();
            break;
        case S_GAME: renderGame();
            break;
    }
    renderFramerate();  // renders debug information, frame rate, elapsed time, etc
    renderToScreen();   // dump the contents of the buffer to the screen, one frame worth of game
}

void splashScreenWait()    // waits for time to pass in splash screen
{
    if (g_dElapsedTime > 3.0) // wait for 3 seconds to switch to game mode, else do nothing
    { 
        g_eGameState = S_DIFFICULTY;
        
    }
}

//-----Gameplay logic

void gameplay()
{
    moveCharacter();    
                        // sound can be played here too.
}

void moveCharacter()
{
	Player* P = &players[currentTurn];

	//Player 1 controls
	if (currentTurn == 0)
	{
		bool B = false;

		do
		{
			if (g_abKeyPressed[K_UP])			if (move(K_UP, *P)) { B = true; break; }
			if (g_abKeyPressed[K_DOWN])			if (move(K_DOWN, *P)) { B = true; break; }
			if (g_abKeyPressed[K_LEFT])			if (move(K_LEFT, *P)) { B = true; break; }
			if (g_abKeyPressed[K_RIGHT])		if (move(K_RIGHT, *P)) { B = true; break; }
			if (g_abKeyPressed[K_UPLEFT])		if (move(K_UPLEFT, *P)) { B = true; break; }
			if (g_abKeyPressed[K_UPRIGHT])		if (move(K_UPRIGHT, *P)) { B = true; break; }
			if (g_abKeyPressed[K_DOWNLEFT])		if (move(K_DOWNLEFT, *P)) { B = true; break; }
			if (g_abKeyPressed[K_DOWNRIGHT])	if (move(K_DOWNRIGHT, *P)) { B = true; break; }
		} while (false);

		if (B)
		{
			currentTurn +=1;
			hintOn = false;
			hintFlush();
		}
	}

	//Player 2 controls
    else if (currentTurn == 1)
	{
		bool B = false;

		do
		{

			if (g_abKeyPressed[K_UP2])			    if (move(K_UP, *P)) { B = true; break; }
			if (g_abKeyPressed[K_DOWN2])			if (move(K_DOWN, *P)) { B = true; break; }
			if (g_abKeyPressed[K_LEFT2])			if (move(K_LEFT, *P)) { B = true; break; }
			if (g_abKeyPressed[K_RIGHT2])		    if (move(K_RIGHT, *P)) { B = true; break; }
			if (g_abKeyPressed[K_UPLEFT2])		    if (move(K_UPLEFT, *P)) { B = true; break; }
			if (g_abKeyPressed[K_UPRIGHT2])		    if (move(K_UPRIGHT, *P)) { B = true; break; }
			if (g_abKeyPressed[K_DOWNLEFT2])		if (move(K_DOWNLEFT, *P)) { B = true; break; }
			if (g_abKeyPressed[K_DOWNRIGHT2])	    if (move(K_DOWNRIGHT, *P)) { B = true; break; }
		} while (false);

		if (B)
		{
			currentTurn = 0;
			hintOn = false;
			hintFlush();
		}
	}

	//Global controls

if (g_abKeyPressed[K_RETRY]) //Retry
	{
		//PlaySound(L"retry.wav" ,NULL,SND_ASYNC);
		total1=0;
		total2=0;
		Result1.clear();
		Result2.clear();
		boardGen();
		void render();
	}

	if (g_abKeyPressed[K_HINT])
	{
		if (!hintOn && players[currentTurn].H > 0)
		{
			hintOn = true;
			players[currentTurn].H--;
			hinting(players[currentTurn].playerLocation);
		}
	}

    // quits the game if player hits the escape key
    if (g_abKeyPressed[K_ESCAPE])
        g_bQuitGame = true; 
}


//-----Rendering

void clearScreen()
{
    // Clears the buffer with this colour attribute
    g_Console.clearBuffer(0x00);
}

void renderSplashScreen()  // renders the splash screen
{
  
    std::string gamename;
    COORD c = g_Console.getConsoleSize();
    c.Y /= 2;
    c.X = c.X / 1;
    c.Y += 1;
    c.X += 22;
    std::ifstream myfile;
    myfile.open("mainscreen.txt");
        for(int i=0; myfile.good(); i++){
            std::getline(myfile, gamename);
            g_Console.writeToBuffer(c, gamename, 0x04);
            c.Y += 1;
        }
    c.X -= 20;
    c.Y += 1;
    c.Y /= 3;
    c.X = c.X / 2 - 9;
    c.X -= 1;
     g_Console.writeToBuffer(c, "A game in 3 seconds", 0x03);
    c.Y += 1;
    c.X = g_Console.getConsoleSize().X / 2 - 20;

    c.Y += 1;
    c.X = g_Console.getConsoleSize().X / 2 - 9;
    g_Console.writeToBuffer(c, "Press 'Esc' to quit", 0x09);

}

void renderGame()
{
    renderMap();        // renders the map to the buffer first
    renderCharacter();  // renders the character into the buffer
}



void renderCharacter()
{
    // Draw the location of the characters
	const WORD inactive = 0x0A;

	for (size_t i = 0; i < playerNumber; i++)
	{
		WORD charColor[2] = { 0x0E, 0x0D };

		Player* P = &(players[i]);
		COORD*C = &((*P).playerLocation);
		WORD c = (*P).A ? charColor[i] : inactive;

		g_Console.writeToBuffer((*P).playerLocation, (char)2, charColor[i]);
	}
}

void renderFramerate()
{
    COORD c;
    // displays the framerate
    std::ostringstream ss;
    ss << std::fixed << std::setprecision(3);
    ss << 1.0 / g_dDeltaTime << "fps";
    c.X = g_Console.getConsoleSize().X - 9;
    c.Y = 0;
    g_Console.writeToBuffer(c, ss.str());

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


