// This is the main file for the game logic and function
//
//
#include "game.h"
#include <fstream>
#include <string>

double  g_dElapsedTime;
double  g_dDeltaTime;

COORD consoleSize;

unsigned int totalPlayers = 2;
Player player1;
Player player2;
const EKEYS playerKeys1[] = { K_UP, K_UPLEFT, K_UPRIGHT, K_DOWN, K_DOWNLEFT, K_DOWNRIGHT, K_LEFT, K_RIGHT };
const EKEYS playerKeys2[] = { K_UP2, K_UPLEFT2, K_UPRIGHT2, K_DOWN2, K_DOWNLEFT2, K_DOWNRIGHT2, K_LEFT2, K_RIGHT2 };
bool hintOn = false;

Chances boardChances;
unsigned int genID = 1;

const unsigned int chances1[8] = { 50, 60, 70, 80, 85, 90, 93, 95 }; 
const unsigned int chances2[8] = { 30, 35, 40, 50, 60, 70, 80, 90 };

Playfield playfield;

difficulty level = Novice;
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

unsigned int currentTurn;
bool entered;

KeyState keyStates[K_COUNT];

// Game specific variables here
EGAMESTATES g_eGameState = S_SPLASHSCREEN;
double  g_dBounceTime; // this is to prevent key bouncing, so we won't trigger keypresses more than once

// Console object
Console g_Console(80,40, "Greed Reloaded");


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
	const unsigned int* P;
	switch (genID)
	{
	case 0: P = chances1;
	case 1: P = chances2;
	}

	for (unsigned int i = 0; i < 8; i++) boardChances.percentiles[i] = P[i];

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
	keyStates[K_ENTER].key = VK_RETURN;
	keyStates[K_RETRY].key = 'R';
	keyStates[K_HINT].key = 'H';

	//--End of Defining keystates

	// rand() initialization
	srand((unsigned int)time(0)); rand();

    // Set precision for floating point output
    g_dElapsedTime = 0.0;
    g_dBounceTime = 0.0;

    // sets the initial state for the game
    g_eGameState = S_SPLASHSCREEN;


	//Defining playfield size
	playfield.sizeX = 20;
	playfield.sizeY = 20;

    // sets the width, height and the font name to use in the console
    g_Console.setConsoleFont(0, 25, L"Consolas");
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
        case S_SPLASHSCREEN : splashScreenWait(); // game logic for the splash screen
            break;
        
        case S_GAME: gameplay(); // gameplay logic when we are in the game
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
        case S_SPLASHSCREEN: renderSplashScreen();
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
        g_eGameState = S_GAME;
        boardGen();
    }
}

//-----Gameplay logic

void gameplay()
{
	//Input section
	Player* P; //Pointer for player
	const EKEYS* PK; //Pointer for keys array

	P = pickPlayer(currentTurn);

	switch (currentTurn)
	{
	case 0: PK = playerKeys1; break;
	case 1: PK = playerKeys2; break;
	}

	//Player controls
	if (!entered) goto skipEntered;

	bool B = false;

	for (unsigned int i = 0; i < 8; i++)
	{
		EKEYS K = PK[i];
		if (keyStates[K].onPressed) if (move(K, *P)) { B = true; break; }
	}

	if (B)
	{
		currentTurn = (currentTurn < totalPlayers - 1) ? currentTurn + 1 : 0;
		entered = false;
		hintOn = false;
		hintFlush();
	}

	skipEntered:

	//Global controls

	if (keyStates[K_RETRY].onPressed) //Retry
	{
		//PlaySound(L"retry.wav" ,NULL,SND_ASYNC);
		total1 = 0;
		total2 = 0;
		Result1.clear();
		Result2.clear();
		boardGen();
		void render();
	}

	if (keyStates[K_HINT].onPressed)
	{
		Player* P;
		P = pickPlayer(currentTurn);

		if (!hintOn && (*P).hintsAvailable > 0)
		{
			hintOn = true;
			(*P).hintsAvailable--;
		}
	}

	if (keyStates[K_ENTER].onPressed)
	{
		entered = true;
	}

	// quits the game if player hits the escape key
	if (keyStates[K_ESCAPE].onPressed) g_bQuitGame = true;

	//End of Input section
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

void renderMap()
{
    char V;
	for (unsigned int Y = 0; Y < playfield.sizeY; Y++)
    {
        for (unsigned int X = 0; X < playfield.sizeX; X++)
        {
            //gotoXY(X, Y);
            
			V = playfield.cell[Y][X].value;

			WORD C;

			switch (playfield.cell[Y][X].highlight)
			{
			case NONE: C = 0x2F; break;
			case NEARBY: C = 0xDF; break;
			case TRAJECTORY: C = 0x5F; break;
			}

            g_Console.writeToBuffer(X, Y, static_cast<char>(V == 0 ? 0 : V + 48), C);
            
        }
    }
    g_Console.writeToBuffer(0, playfield.sizeY + 1, "Total Points for player 1 :", 0x59);
	g_Console.writeToBuffer(0, playfield.sizeY + 2, Result1, 0x59);
	g_Console.writeToBuffer(0, playfield.sizeY + 3, "Total Points for player 2 :", 0x59);
	g_Console.writeToBuffer(0, playfield.sizeY + 4, Result2, 0x59);
	g_Console.writeToBuffer(0, playfield.sizeY + 5, currentTurn + '0', 0x59);
}

void renderCharacter()
{
    // Draw the location of the characters
	const WORD inactive = 0x0A;
	WORD charColor;

	Player *P;

	for (unsigned int i = 0; i < 2; i++)
	{
		P = pickPlayer(i);

		switch (i)
		{
		case 0: charColor = 0x0E; break;
		case 1: charColor = 0x0D; break;
		default: charColor = 0x0F; break;
		}

		g_Console.writeToBuffer((*P).playerLocation, (char)2, charColor);
	}
}

void renderFramerate()
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

void changeScreen(){
    int choice = chooseSize();
    switch(choice){
        case 1: //playfield.resize(15);
            break;
        case 2: //playfield.resize(30);
            break;
        case 3: //playfield.resize(40);
            break;
    }
}

void changeDiff(int Dchoice){
    Dchoice = chooseDiff();
    switch(Dchoice){
    case 1: level = Novice;
            break;
        case 2: level = Intermediate;
            break;
        case 3: level = Advanced;
            break;
    }
    g_eGameState = S_GAME;
}

int chooseDiff()
{
    int choice;
    std::cout<<"Select your difficulty: "<<"(1 for Novice, 2 for Intermediate, 3 for Advance)"<<std::endl;
    std::cin>>choice;
    
    return choice;
}

int chooseSize()
{
    int choice;
    std::cout<<"Sizes: "<<std::endl;
    std::cout<<"1: 15 x 15"<<std::endl;
    std::cout<<"2: 30 x 30"<<std::endl;
    std::cout<<"3: 45 x 45"<<std::endl;
    std::cin>>choice;
    return choice;
}

void boardGen(){
	playfield.resize(25, 10);
	playfield.numberLimit = 5;

    for (unsigned int Y = 0; Y < playfield.sizeY; Y++)
    {
        vector<PlayfieldCell> V(playfield.sizeX);

        for (unsigned int X = 0; X < playfield.sizeX; X++)
		{
			V[X].highlight = NONE;

			V[X].value = boardChances.rollValue(playfield.numberLimit);

			unsigned int K = V[X].value;

			K = K;
        }
        playfield.cell[Y] = V;
    }

	for (size_t i = 0; i < 2; i++)
	{
		Player* P = pickPlayer(i);
		
		COORD* playerLocation = &((*P).playerLocation);

		reattempt:

		(*playerLocation).X = rand() % playfield.sizeX;
		(*playerLocation).Y = rand() % playfield.sizeY;

		for (size_t j = 0; j < i; j++)
		{
			Player* P = pickPlayer(j);
			COORD* T = &((*P).playerLocation);
			if ((*T).X == (*playerLocation).X) goto reattempt;
			if ((*T).Y == (*playerLocation).Y) goto reattempt;
		}
		
		playfield.cell[(*playerLocation).Y][(*playerLocation).X].value = 0;

		(*P).active = true;
		(*P).hintsAvailable = 3;
	}

	currentTurn = 0;
	entered = true;
}

Player* pickPlayer(unsigned int N)
{
	Player* P;

	switch (N)
	{
	case 0: P = &player1; break;
	case 1: P = &player2; break;
	}

	return P;
}
//Retry