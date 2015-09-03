#include "game.h"
void renderMode() //Done by Glence, Render the modes on screen
	{
    std::string normal;
    std::string time;
    COORD c = g_Console.getConsoleSize();

	g_Console.writeToBuffer(0, 1, "Select the mode. (1 for Normal; 2 for Timed)", 0x0B);

    c.Y = 4;
    c.X = 4;
    
    std::ifstream normalmodefile;
    normalmodefile.open("display/normalmode.txt");
    for(int i=0; normalmodefile.good(); i++)
	{
        std::getline(normalmodefile, normal);
        g_Console.writeToBuffer(c, normal, 0x03);
        c.Y += 1;
    }

    c.Y += 2;

    std::ifstream timemodefile;
    timemodefile.open("display\\timemode.txt");
    for(int i=0; timemodefile.good(); i++)
	{
		std::getline(timemodefile, time);
		g_Console.writeToBuffer(c, time, 0x03);
		c.Y += 1;
    }

    c.Y += 2;
}

void processmodeMenu()// Done by Glence, process mode menu inputs
{
    if((isKeyPressed('1'))||(isKeyPressed(VK_NUMPAD1))){
	    
		PlaySound(L"sound\\button.wav",NULL,SND_ASYNC);
		timer = false;
	    g_eGameState = S_DIFFICULTY;

    }
    if((isKeyPressed('2'))||(isKeyPressed(VK_NUMPAD2))){
	    PlaySound(L"sound\\button.wav",NULL,SND_ASYNC);
		timer = true;
	    g_eGameState = S_DIFFICULTY;
    }
    if (isKeyPressed(VK_ESCAPE))
	  {
		  PlaySound(L"sound\\button.wav",NULL,SND_ASYNC);
		  g_eGameState = S_PLAYERMENU;
	  }
 
}
void processmodeMenuHighScore()//Done By Jeffrey,process inputs for printing all highscore boards
 {
	 if((isKeyPressed('1'))||(isKeyPressed(VK_NUMPAD1))){
	    
		PlaySound(L"sound\\button.wav",NULL,SND_ASYNC);
		timer = false;
	    g_eGameState = S_PRINTHIGHSCORE;

    }
    if((isKeyPressed('2'))||(isKeyPressed(VK_NUMPAD2))){
	    PlaySound(L"sound\\button.wav",NULL,SND_ASYNC);
		timer = true;
	    g_eGameState = S_PRINTTIMEHIGHSCORE;
    }
    if (isKeyPressed(VK_ESCAPE))
	  {
		  PlaySound(L"sound\\button.wav",NULL,SND_ASYNC);
		  g_eGameState = S_MAINMENU;
	  }
 }