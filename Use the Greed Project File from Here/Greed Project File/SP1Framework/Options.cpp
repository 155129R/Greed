#include <iostream>
#include <fstream>
#include "game.h"

bool p1KeySet = 0;
bool p2KeySet = 0;
string choicePrint;
KeyState keyStates[K_COUNT];

void renderOptionsMenu()
{
    std::ifstream p1File;
	string p1control;
    std::ifstream p2File;
	string p2control;

    COORD textPrintCoord;
    textPrintCoord.X = 5;
    textPrintCoord.Y = 3;

	p1File.open("p1controls.txt");
	
		
        
		while(p1File.good())
		{
			std::getline(p1File,p1control);
				g_Console.writeToBuffer(textPrintCoord,p1control,0x04);
			textPrintCoord.Y++;
		}
		p1File.close();
    textPrintCoord.Y += 5;
        p2File.open("p2controls.txt");
		while(p2File.good())
		{
			std::getline(p2File,p2control);
				g_Console.writeToBuffer(textPrintCoord,p2control,0x04);
			textPrintCoord.Y++;
		}
		p2File.close();
    
    
}

void processOptionsMenu()
{

    if((isKeyPressed('1'))||(isKeyPressed(VK_NUMPAD1))){
	   
        g_eGameState = S_P1CTRL;
        
    }
    if((isKeyPressed('2'))||(isKeyPressed(VK_NUMPAD2))){
	    
        g_eGameState = S_P2CTRL;
        
    }
    if (isKeyPressed(VK_ESCAPE))
	  {
		  g_eGameState=S_MAINMENU;
	  }
    

}

//PLAYER 1 CONTROL MENU

void renderPlayerControl(){
    
    std::ifstream qweFile;
	string controlSet1;
    std::ifstream numFile;
	string controlSet2;

    COORD textPrintCoord;
    textPrintCoord.X = 5;
    textPrintCoord.Y = 3;

	qweFile.open("qwekeys.txt");
        
		while(qweFile.good())
		{
			std::getline(qweFile,controlSet1);
				g_Console.writeToBuffer(textPrintCoord,controlSet1,0x04);
			textPrintCoord.Y++;
		}
		qweFile.close();
        textPrintCoord.Y = 3;
        textPrintCoord.X += 35;
        	numFile.open("numkeys.txt");
        
		while(numFile.good())
		{
			std::getline(numFile,controlSet2);
				g_Console.writeToBuffer(textPrintCoord,controlSet2,0x04);
			textPrintCoord.Y++;
		}
		numFile.close();
        if((isKeyPressed('1'))||(isKeyPressed(VK_NUMPAD1))){
            choicePrint="Option 1 was selected";
        }
        else if((isKeyPressed('2'))||(isKeyPressed(VK_NUMPAD2))){
            choicePrint="Option 2 was selected";
        }

        g_Console.writeToBuffer(1,1,choicePrint,0x04);

}

void processPlayer1Control(){
    if((isKeyPressed('1'))||(isKeyPressed(VK_NUMPAD1))){

	    keyStates[K_UP].key = 'W';
	    keyStates[K_UPLEFT].key = 'Q';
	    keyStates[K_UPRIGHT].key = 'E';
	    keyStates[K_DOWN].key = 'X';
	    keyStates[K_DOWNLEFT].key = 'Z';
	    keyStates[K_DOWNRIGHT].key = 'C';
	    keyStates[K_LEFT].key = 'A';
	    keyStates[K_RIGHT].key = 'D';

        
    }
    else if((isKeyPressed('2'))||(isKeyPressed(VK_NUMPAD2))){
    
        keyStates[K_UP].key = VK_NUMPAD8;
	    keyStates[K_UPLEFT].key = VK_NUMPAD7;
	    keyStates[K_UPRIGHT].key = VK_NUMPAD9;
	    keyStates[K_DOWN].key = VK_NUMPAD2;
	    keyStates[K_DOWNLEFT].key = VK_NUMPAD1;
	    keyStates[K_DOWNRIGHT].key = VK_NUMPAD3;
	    keyStates[K_LEFT].key = VK_NUMPAD4;
	    keyStates[K_RIGHT].key = VK_NUMPAD6;
  
    }
    else if (isKeyPressed(VK_ESCAPE))
	  {
		  g_eGameState=S_OPTION;
	  }


}




void processPlayer2Control(){
        if((isKeyPressed('1'))||(isKeyPressed(VK_NUMPAD1))){

	    keyStates[K_UP2].key = 'W';
	    keyStates[K_UPLEFT2].key = 'Q';
	    keyStates[K_UPRIGHT2].key = 'E';
	    keyStates[K_DOWN2].key = 'X';
	    keyStates[K_DOWNLEFT2].key = 'Z';
	    keyStates[K_DOWNRIGHT2].key = 'C';
	    keyStates[K_LEFT2].key = 'A';
	    keyStates[K_RIGHT2].key = 'D';

        
    }
    else if((isKeyPressed('2'))||(isKeyPressed(VK_NUMPAD2))){
    
        keyStates[K_UP2].key = VK_NUMPAD8;
	    keyStates[K_UPLEFT2].key = VK_NUMPAD7;
	    keyStates[K_UPRIGHT2].key = VK_NUMPAD9;
	    keyStates[K_DOWN2].key = VK_NUMPAD2;
	    keyStates[K_DOWNLEFT2].key = VK_NUMPAD1;
	    keyStates[K_DOWNRIGHT2].key = VK_NUMPAD3;
	    keyStates[K_LEFT2].key = VK_NUMPAD4;
	    keyStates[K_RIGHT2].key = VK_NUMPAD6;
  
    }
    else if (isKeyPressed(VK_ESCAPE))
	  {
		  g_eGameState=S_OPTION;
	  }


}