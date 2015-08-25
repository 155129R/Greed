// This is the main file for the game logic and function
//
//

#include "game.h"
<<<<<<< Updated upstream:Use the Greed Project File from Here/Backup/SP1Framework/game.cpp

double  g_dElapsedTime;
double  g_dDeltaTime;

COORD consoleSize;

const size_t playerNumber = 2;
Player players[playerNumber];
bool hintOn = false;

vector<vector<PField>> playfield;
PSize fieldSize;
size_t numbers = 5;

difficulty level = Novice;
playsize dim = normal;
int Dchoice = 1;
int total = 0;
int point = 0;

=======
#include "point.h"
#include "Framework\console.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <vector>
using std::vector; 
using std::string;

const size_t playerNumber = 2;
string Result;
int points=0;
int total=0;
int N=0;
>>>>>>> Stashed changes:SP1Framework-master(LATEST FRAMEWORK)/SP1Framework-master/SP1Framework/game.cpp
int chooseDiff();
int chooseSize();
void changeDiff(int Dchoice);
void changeSize();
void boardGen();
void printBoard();
void changeScreen();
unsigned int currentTurn;
<<<<<<< Updated upstream:Use the Greed Project File from Here/Backup/SP1Framework/game.cpp
bool g_abKeyPressed[K_COUNT];
=======
 //int Nvalue=0;
double  g_dElapsedTime;
double  g_dDeltaTime;
bool    g_abKeyPressed[K_COUNT];
COORD consoleSize;
size_t playfieldX = 15, playfieldY = 9;
size_t numbers = 5;

vector<vector<unsigned int>> playfield(playfieldY);
difficulty level = Novice;
playsize dim = normal;
int Dchoice = 1;

>>>>>>> Stashed changes:SP1Framework-master(LATEST FRAMEWORK)/SP1Framework-master/SP1Framework/game.cpp

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
	// rand() initialization
	srand((unsigned int)time(0)); rand();

    // Set precision for floating point output
    g_dElapsedTime = 0.0;
    g_dBounceTime = 0.0;

    // sets the initial state for the game
    g_eGameState = S_SPLASHSCREEN;

	//Defining playfieldSize
	fieldSize.X = 20;
	fieldSize.Y = 20;

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
    //PLAYER1
    g_abKeyPressed[K_UP]            = isKeyPressed(VK_NUMPAD8);
    g_abKeyPressed[K_UPLEFT]        = isKeyPressed(VK_NUMPAD7);
	g_abKeyPressed[K_UPRIGHT]       = isKeyPressed(VK_NUMPAD9);
    g_abKeyPressed[K_DOWN]          = isKeyPressed(VK_NUMPAD2);
    g_abKeyPressed[K_DOWNLEFT]      = isKeyPressed(VK_NUMPAD1);
	g_abKeyPressed[K_DOWNRIGHT]     = isKeyPressed(VK_NUMPAD3);
    g_abKeyPressed[K_LEFT]          = isKeyPressed(VK_NUMPAD4);
    g_abKeyPressed[K_RIGHT]         = isKeyPressed(VK_NUMPAD6);

    //PLAYER2
    g_abKeyPressed[K_UP2]            = isKeyPressed(VK_NUMPAD8);
    g_abKeyPressed[K_UPLEFT2]        = isKeyPressed(VK_NUMPAD7);
	g_abKeyPressed[K_UPRIGHT2]       = isKeyPressed(VK_NUMPAD9);
    g_abKeyPressed[K_DOWN2]          = isKeyPressed(VK_NUMPAD2);
    g_abKeyPressed[K_DOWNLEFT2]      = isKeyPressed(VK_NUMPAD1);
	g_abKeyPressed[K_DOWNRIGHT2]     = isKeyPressed(VK_NUMPAD3);
    g_abKeyPressed[K_LEFT2]          = isKeyPressed(VK_NUMPAD4);
    g_abKeyPressed[K_RIGHT2]         = isKeyPressed(VK_NUMPAD6);

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
	//addingPoints(N, total);
    switch (g_eGameState)
    {
        case S_SPLASHSCREEN : splashScreenWait(); // game logic for the splash screen
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
    moveCharacter();    
                        // sound can be played here too.
}

void moveCharacter()
{
<<<<<<< Updated upstream:Use the Greed Project File from Here/Backup/SP1Framework/game.cpp
	Player* P = &players[currentTurn];

=======
	if (g_abKeyPressed[K_RETRY]) //Retry
	{	
		//PlaySound(L"retry.wav",NULL,SND_ASYNC);
		//int N=0;
		//total = 0;
		boardGen();
		//Result.clear();
		//pointcounter(Result,N,total,A);	
	}
>>>>>>> Stashed changes:SP1Framework-master(LATEST FRAMEWORK)/SP1Framework-master/SP1Framework/game.cpp
	//Player 1 controls
	if (currentTurn == 0)
	{
		bool B = false;

		do
		{
			if (g_abKeyPressed[K_UP])			if (move(0, -1, *P)) { B = true; break; }
			if (g_abKeyPressed[K_DOWN])			if (move(0, 1, *P)) { B = true; break; }
			if (g_abKeyPressed[K_LEFT])			if (move(-1, 0, *P)) { B = true; break; }
			if (g_abKeyPressed[K_RIGHT])		if (move(1, 0, *P)) { B = true; break; }
			if (g_abKeyPressed[K_UPLEFT])		if (move(-1, -1, *P)) { B = true; break; }
			if (g_abKeyPressed[K_UPRIGHT])		if (move(1, -1, *P)) { B = true; break; }
			if (g_abKeyPressed[K_DOWNLEFT])		if (move(-1, 1, *P)) { B = true; break; }
			if (g_abKeyPressed[K_DOWNRIGHT])	if (move(1, 1, *P)) { B = true; break; }
		} while (false);

<<<<<<< Updated upstream:Use the Greed Project File from Here/Backup/SP1Framework/game.cpp
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
=======
	
    // quits the game if player hits the escape key
    if (g_abKeyPressed[K_ESCAPE])
        g_bQuitGame = true; 
}

//X and Y can be -1, 0, or 1 for unit directions; P represents player number (zero-based index)
void move(int X, int Y, unsigned int P)
{

	if (P != currentTurn) return;
	COORD* C = &(g_sChar[P].m_cLocation);
>>>>>>> Stashed changes:SP1Framework-master(LATEST FRAMEWORK)/SP1Framework-master/SP1Framework/game.cpp

		do
		{

			if (g_abKeyPressed[K_UP2])			    if (move(0, -1, *P)) { B = true; break; }
			if (g_abKeyPressed[K_DOWN2])		    if (move(0, 1, *P)) { B = true; break; }
			if (g_abKeyPressed[K_LEFT2])		    if (move(-1, 0, *P)) { B = true; break; }
			if (g_abKeyPressed[K_RIGHT2])		    if (move(1, 0, *P)) { B = true; break; }
			if (g_abKeyPressed[K_UPLEFT2])		    if (move(-1, -1, *P)) { B = true; break; }
			if (g_abKeyPressed[K_UPRIGHT2])		    if (move(1, -1, *P)) { B = true; break; }
			if (g_abKeyPressed[K_DOWNLEFT2])	    if (move(-1, 1, *P)) { B = true; break; }
			if (g_abKeyPressed[K_DOWNRIGHT2])	    if (move(1, 1, *P)) { B = true; break; }
		} while (false);

<<<<<<< Updated upstream:Use the Greed Project File from Here/Backup/SP1Framework/game.cpp
		if (B)
		{
			currentTurn = 0;
			hintOn = false;
			hintFlush();
		}
	}

	//Global controls
=======
	int	N = playfield[TY][TX];
	if (TX + (N - 1)*X < 0) return;
	if (TX + (N - 1)*X >= (int)playfieldX) return;
	if (TY + (N - 1)*Y < 0) return;
	if (TY + (N - 1)*Y >= (int)playfieldY) return;
>>>>>>> Stashed changes:SP1Framework-master(LATEST FRAMEWORK)/SP1Framework-master/SP1Framework/game.cpp

	if (g_abKeyPressed[K_RETRY]) //Retry
	{
		boardGen();
		void render();
	}

<<<<<<< Updated upstream:Use the Greed Project File from Here/Backup/SP1Framework/game.cpp
	if (g_abKeyPressed[K_HINT])
	{
		if (!hintOn && players[currentTurn].H > 0)
		{
			hintOn = true;
			players[currentTurn].H--;
			hinting(players[currentTurn].L);
		}
	}

    // quits the game if player hits the escape key
    if (g_abKeyPressed[K_ESCAPE])
        g_bQuitGame = true; 
=======
	for (int i = 0; i < N; i++) playfield[(*C).Y + Y*i][(*C).X + X*i] = 0;
	{
	(*C).X += N*X;
	(*C).Y += N*Y;
	}
	addingPoints( N,total);
	convertTotalPoints (Result,total);

	/*point = N;						//Point Counter
    point2 = N;
    std::ostringstream convert;
    std::ostringstream convert2;
    convert << static_cast<int>(total);
    convert2 << static_cast<int>(total2);
    Result = convert.str();
    Result2 = convert2.str();*/

	//currentTurn = (currentTurn < playerNumber - 1) ? currentTurn + 1 : 0;
	
	
>>>>>>> Stashed changes:SP1Framework-master(LATEST FRAMEWORK)/SP1Framework-master/SP1Framework/game.cpp
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
<<<<<<< Updated upstream:Use the Greed Project File from Here/Backup/SP1Framework/game.cpp
=======
	
	//convertTotalPoints (Result,total);
	
    COORD c =  g_Console.getConsoleSize();
>>>>>>> Stashed changes:SP1Framework-master(LATEST FRAMEWORK)/SP1Framework-master/SP1Framework/game.cpp
    char V;
	for (unsigned int Y = 0; Y < fieldSize.Y; Y++)
    {
        for (unsigned int X = 0; X < fieldSize.X; X++)
        {
            //gotoXY(X, Y);
            
			V = playfield[Y][X].V;

			WORD C;

			switch (playfield[Y][X].H)
			{
			case NONE: C = 0x2F; break;
			case NEARBY: C = 0xDF; break;
			case TRAJECTORY: C = 0x5F; break;
			}

            g_Console.writeToBuffer(X, Y, static_cast<char>(V == 0 ? 0 : V + 48), C);
            
        }
<<<<<<< Updated upstream:Use the Greed Project File from Here/Backup/SP1Framework/game.cpp
    }
    g_Console.writeToBuffer(0, fieldSize.Y + 1, "Total Points: ", 0x59);
	g_Console.writeToBuffer(0, fieldSize.Y + 2, currentTurn + '0', 0x59);
=======

    }	
	
	 //g_Console.writeToBuffer(0, playfield.size() + 3,N, 0x59);
	  g_Console.writeToBuffer(0, playfield.size() + 3,static_cast<int>(points), 0x59);
	  g_Console.writeToBuffer(0,playfield.size()+ 4,static_cast<int>(total),0x59);
      g_Console.writeToBuffer(0, playfield.size() + 2,Result, 0x59);
//     g_Console.writeToBuffer(0, playfield.size() + 4, Result2, 0x59);
    
>>>>>>> Stashed changes:SP1Framework-master(LATEST FRAMEWORK)/SP1Framework-master/SP1Framework/game.cpp
}

void renderCharacter()
{
    // Draw the location of the characters
	const WORD inactive = 0x0A;

	for (size_t i = 0; i < playerNumber; i++)
	{
		WORD charColor[2] = { 0x0E, 0x0D };

		Player* P = &(players[i]);
		COORD*C = &((*P).L);
		WORD c = (*P).A ? charColor[i] : inactive;

		g_Console.writeToBuffer((*P).L, (char)2, charColor[i]);
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
        case 1: playfield.resize(15);
            break;
        case 2: playfield.resize(30);
            break;
        case 3: playfield.resize(40);
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
	playfield.resize(fieldSize.Y);

    for (unsigned int Y = 0; Y < fieldSize.Y; Y++)
    {
        vector<PField> V(fieldSize.X);

        for (unsigned int X = 0; X < fieldSize.X; X++)
		{
			unsigned int chances[8] = {20, 60, 70, 75, 80, 90, 93, 95}; //Chances (in %) for 2, 3, 4, 5, 6, 7, 8, 9; if chance is less than getting a 2, use 1.

			unsigned int R = rand() % 100;

			V[X].V = 1;
			V[X].H = NONE;

			while (V[X].V < numbers)
			{
				if (R < chances[V[X].V - 1]) break;
				V[X].V++;
			}
        }
        playfield[Y] = V;
    }

	for (size_t i = 0; i < playerNumber; i++)
	{
		currentTurn = 0;

		Player* P = &(players[i]);
		COORD* L = &((*P).L);

		do
		{
			bool onTop = false;

			(*L).X = rand() % fieldSize.X;
			(*L).Y = rand() % fieldSize.Y;

			for (size_t j = 0; j < i; j++)
			{
				COORD* P = &(players[j].L);
				if ((*P).X == (*L).X) { onTop = true; break; }
				if ((*P).Y == (*L).Y) { onTop = true; break; }
			}

			if (onTop) continue;
		} while (false);
		
		playfield[(*L).Y][(*L).X].V = 0;

		(*P).A = true;
		(*P).H = 3;
	}
}
//Retry