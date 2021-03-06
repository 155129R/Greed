#include "HighScore.h"

#include <sstream>
#include "game.h"
#include "difficulty.h"
#include "playermenu.h"
#include "points.h"

using std::string;
int ChangeScore;
extern string Result1;
/*int value = atoi(FirstPlayerScoreString.c_str()); 
	std::cout <<value;*/
string FirstPlayer;
string FirstPlayerScoreString;
string SecondPlayer;
string SecondPlayerScoreString;
string ThirdPlayer;
string ThirdPlayerScoreString;
string PlayerName;
string name1;//FirstPlayer Name
string CheckPlayer1Score;
string name2;
string CheckPlayer2Score;
string name3;
string CheckPlayer3Score;
string ResetSelectedHighScore;	
COORD C;
COORD c;
extern Difficulty level;
int FirstPlayerScore;
int SecondPlayerScore;
int ThirdPlayerScore;
int ChangeFirst;
int ChangeSecond;
int ChangeThird;
int ResetSelectedHighScoreCounter=0;
int checkcounter=0;
extern Console g_Console;
extern int total1;
extern int total2;
extern Difficulty level;
bool g_abKeyPressedName[K_Z];
extern bool timer;

void AskforInput()//Done by Jeffrey,Ask player for name
{
  g_Console.writeToBuffer(1,0,"Input Your name(will only take in max 10 characters)and press enter:", 0x04);

}
void NameInputKeys()//Done by Jeffrey,input keys for highscore name
{
	g_abKeyPressedName[K_A]= isKeyPressed('A');
	g_abKeyPressedName[K_B]=isKeyPressed('B');
	g_abKeyPressedName[K_C]=isKeyPressed('C');
	g_abKeyPressedName[K_D]=isKeyPressed('D');
	g_abKeyPressedName[K_E]=isKeyPressed('E');
	g_abKeyPressedName[K_F]=isKeyPressed('F');
	g_abKeyPressedName[K_G]=isKeyPressed('G');
	g_abKeyPressedName[K_H]=isKeyPressed('H');
	g_abKeyPressedName[K_I]=isKeyPressed('I');
	g_abKeyPressedName[K_J]=isKeyPressed('J');
	g_abKeyPressedName[K_K]=isKeyPressed('K');
	g_abKeyPressedName[K_L]=isKeyPressed('L');
	g_abKeyPressedName[K_M]=isKeyPressed('M');
	g_abKeyPressedName[K_N]=isKeyPressed('N');
	g_abKeyPressedName[K_O]=isKeyPressed('O');
	g_abKeyPressedName[K_P]=isKeyPressed('P');
	g_abKeyPressedName[K_Q]=isKeyPressed('Q');
	g_abKeyPressedName[K_R]=isKeyPressed('R');
	g_abKeyPressedName[K_S]=isKeyPressed('S');
	g_abKeyPressedName[K_T]=isKeyPressed('T');
	g_abKeyPressedName[K_U]=isKeyPressed('U');
	g_abKeyPressedName[K_V]=isKeyPressed('V');
	g_abKeyPressedName[K_W]=isKeyPressed('W');
	g_abKeyPressedName[K_X]=isKeyPressed('X');
	g_abKeyPressedName[K_Y]=isKeyPressed('Y');
	g_abKeyPressedName[K_Z]=isKeyPressed('Z');
	g_abKeyPressedName[K_1]=isKeyPressed('1');
	g_abKeyPressedName[K_2]=isKeyPressed('2');
	g_abKeyPressedName[K_3]=isKeyPressed('3');
	g_abKeyPressedName[K_4]=isKeyPressed('4');
	g_abKeyPressedName[K_5]=isKeyPressed('5');
	g_abKeyPressedName[K_6]=isKeyPressed('6');
	g_abKeyPressedName[K_7]=isKeyPressed('7');
	g_abKeyPressedName[K_8]=isKeyPressed('8');
	g_abKeyPressedName[K_9]=isKeyPressed('9');
	g_abKeyPressedName[K_0]=isKeyPressed('0');
	g_abKeyPressedName[K_ENTER2]=isKeyPressed(VK_RETURN);
	g_abKeyPressedName[K_BACKSPACE]=isKeyPressed(VK_BACK);
	g_abKeyPressedName[K_ESCAPE2] = isKeyPressed(VK_ESCAPE);
}
void NameInput()//Done by Jeffrey,insert letters into player name
{
	if(PlayerName.length()<11)//Max 10 characters for name
	{
	
		if(g_abKeyPressedName[K_A])
		{
		PlayerName+="A";
		Sleep(100);
		}
		if(g_abKeyPressedName[K_B])
		{
		 PlayerName+='B';Sleep(100);
		}
		if(g_abKeyPressedName[K_C])
		{
		PlayerName+='C';Sleep(100);
		}
		if(g_abKeyPressedName[K_D])
		{
		PlayerName+='D';Sleep(100);
		}
		if(g_abKeyPressedName[K_E])
		{
		PlayerName+='E';Sleep(100);
		}
		if(g_abKeyPressedName[K_F])
		{
		PlayerName+='F';Sleep(100);
		}
		if(g_abKeyPressedName[K_G])
		{
		PlayerName+='G';Sleep(100);
		}
		if(g_abKeyPressedName[K_H])
		{
		PlayerName+='H';Sleep(100);
		}
		if(g_abKeyPressedName[K_I])
		{
		PlayerName+='I';Sleep(100);
		}
		if(g_abKeyPressedName[K_J])
		{
		PlayerName+='J';Sleep(100);
		}
		if(g_abKeyPressedName[K_K])
		{
		PlayerName+='K';Sleep(100);
		}
		if(g_abKeyPressedName[K_L])
		{
		PlayerName+='L';Sleep(100);
		}
		if(g_abKeyPressedName[K_M])
		{
		PlayerName+='M';Sleep(100);
		}
		if(g_abKeyPressedName[K_N])
		{
		PlayerName+='N';Sleep(100);
		}
		 if(g_abKeyPressedName[K_O])
		{
		PlayerName+='O';Sleep(100);
		}
		if(g_abKeyPressedName[K_P])
		{
		PlayerName+='P';Sleep(100);
		}
		if(g_abKeyPressedName[K_Q])
		{
		PlayerName+='Q';Sleep(100);
		}
		if(g_abKeyPressedName[K_R])
		{
		PlayerName+='R';Sleep(100);
		}
		if(g_abKeyPressedName[K_S])
		{
		PlayerName+='S';Sleep(100);
		}
		if(g_abKeyPressedName[K_T])
		{
		PlayerName+='T';Sleep(100);
		}
		if(g_abKeyPressedName[K_U])
		{
		PlayerName+='U';Sleep(100);
		}
		if(g_abKeyPressedName[K_V])
		{
		PlayerName+='V';Sleep(100);
		}
		if(g_abKeyPressedName[K_W])
		{
		PlayerName+='W';Sleep(100);
		}
		if(g_abKeyPressedName[K_X])
		{
		PlayerName+='X';Sleep(100);
		}
		if(g_abKeyPressedName[K_Y])
		{
		PlayerName+='Y';Sleep(100);
		}
		if(g_abKeyPressedName[K_Z])
		{
		PlayerName+='Z';Sleep(100);
		}
		if(g_abKeyPressedName[K_0])
		{
		 PlayerName+='0';
		}
		if(g_abKeyPressedName[K_1])
		{
		 PlayerName+='1';
		}
		if(g_abKeyPressedName[K_2])
		{
		  PlayerName+='2';
		}
		if(g_abKeyPressedName[K_3])
		{
		  PlayerName+='3';
		}
		if(g_abKeyPressedName[K_4])
		{
		  PlayerName+='4';
		}
		if(g_abKeyPressedName[K_5])
		{
		  PlayerName+='5';
		}
		if(g_abKeyPressedName[K_6])
		{
		  PlayerName+='6';
		}
		if(g_abKeyPressedName[K_7])
		{
		  PlayerName+='7';
		}
		if(g_abKeyPressedName[K_8])
		{
		  PlayerName+='8';
 		}
		if(g_abKeyPressedName[K_9])
		{
		   PlayerName+='9';
		}
	}
	 if(g_abKeyPressedName[K_BACKSPACE])
	{
		if(PlayerName.length()<1)
		{
			PlayerName="";
		}
		else
		{
		PlayerName.pop_back();
		}
	 
	 }
	 if(g_abKeyPressedName[K_ENTER2] && checkcounter==0)
	{
		check(total1,total2);
		write();
		//g_eGameState=S_PRINTHIGHSCORE;
		checkcounter++;
	}
	if (isKeyPressed(VK_ESCAPE))
	{
		 g_eGameState=S_MAINMENU;
		 checkcounter=0;
	}



}
void displayPlayerName()//Done by Jeffrey,display player name when inputting
{
	{g_Console.writeToBuffer(0,2,PlayerName, 0x04);}
}
void check(int &total1,int &total2)//done by jeffrey,check whether the points earned are in 1st,2nd or 3rd place
{
	
	{
		if(total2>total1)
		{
			total1=total2;
		}
	
	/*gotoXY(1,1);*/
	
	
	//std::cin>>total;
	ChangeScore=total1;
	
	std::ifstream ReadFile;
	if (level == Novice && totalPlayers == 1&&timer==false)
	{
	ReadFile.open("display\\HighScoreEasy1.txt");
	}
	if(level==Intermediate&&totalPlayers == 1&&timer==false)
	{
		ReadFile.open("display\\HighScoreNormal1.txt");
	}
	if (level==Advanced &&totalPlayers == 1&&timer==false)
	{
		ReadFile.open("display\\HighScoreHard1.txt");
	}
	if (level==Novice &&totalPlayers ==2&&timer==false)
	{
	ReadFile.open("HighScoreEasy2.txt");
	}
	if(level==Intermediate &&totalPlayers == 2&&timer==false)
	{
		ReadFile.open("display\\HighScoreNormal2.txt");
	}
	if (level==Advanced&&totalPlayers == 2&&timer==false)
	{
		ReadFile.open("display\\HighScoreHard2.txt");
	
	}
	if (level == Novice && totalPlayers == 1&&timer==true)
	{
	ReadFile.open("display\\HighScoreEasy1time.txt");
	}
	if(level==Intermediate&&totalPlayers == 1&&timer==true)
	{
		ReadFile.open("display\\HighScoreNormal1time.txt");
	}
	if (level==Advanced &&totalPlayers == 1&&timer==true)
	{
		ReadFile.open("display\\HighScoreHard1time.txt");
	}
	if (level==Novice &&totalPlayers ==2&&timer==true)
	{
	ReadFile.open("display\\HighScoreEasy2time.txt");
	}
	if(level==Intermediate &&totalPlayers == 2&&timer==true)
	{
		ReadFile.open("display\\HighScoreNormal2time.txt");
	}
	if (level==Advanced&&totalPlayers == 2&&timer==true)
	{
		ReadFile.open("display\\HighScoreHard2time.txt");
	
	}
	
		std::getline(ReadFile,FirstPlayer,'\n');
		std::getline(ReadFile,CheckPlayer1Score,'\n');
		std::getline(ReadFile,SecondPlayer,'\n');
		std::getline(ReadFile,CheckPlayer2Score,'\n');
		std::getline(ReadFile,ThirdPlayer,'\n');
		std::getline(ReadFile,CheckPlayer3Score,'\n');
		if(ChangeScore>atoi(CheckPlayer1Score.c_str()))//if score > First player score,replace
		{
			FirstPlayerScore=ChangeScore;
			ChangeFirst++;
		}
		else if(ChangeScore>(atoi(CheckPlayer2Score.c_str())))//if score> secondplayer score,replace
		{
			SecondPlayerScore=ChangeScore;
			ChangeSecond++;
		}
		else if(ChangeScore> (atoi(CheckPlayer3Score.c_str())))//if score> thirdplayer,replace
		{
			ThirdPlayerScore=ChangeScore;
			ChangeThird++;
		}
		else if (ChangeScore==0 && ChangeScore>=(atoi(CheckPlayer1Score.c_str())) )// If they score 0 and greater than first player,replace.
		{	
			FirstPlayerScore=ChangeScore;
			ChangeFirst++;
		}
	
		else if (ChangeScore==0 && ChangeScore>=(atoi(CheckPlayer2Score.c_str())) )// if they score 0 and greater than second player,replace
		{
			SecondPlayerScore=ChangeScore;
			ChangeSecond++;
		}
		else if  (ChangeScore==0 && ChangeScore>=(atoi(CheckPlayer3Score.c_str())) )//if they score 0 and greater than third player,replace
		{
			ThirdPlayerScore=ChangeScore;
			ChangeThird++;
		}
		
		ReadFile.close();

		
}
		

	
}
void write()//Done by jeffrey,write highscore to text file
{
	
	std::ofstream WriteFile;
	if (level==Novice && totalPlayers == 1&&timer==false)
	{
	WriteFile.open("display\\HighScoreEasy1.txt");
	}
	if(level==Intermediate&&totalPlayers == 1&&timer==false)
	{
		WriteFile.open("display\\HighScoreNormal1.txt");
	}
	if (level==Advanced&&totalPlayers ==1&&timer==false)
	{
		WriteFile.open("display\\HighScoreHard1.txt");
	}
	if (level==Novice&&totalPlayers == 2&&timer==false)
	{
	WriteFile.open("display\\HighScoreEasy2.txt");
	}
	if(level==Intermediate&&totalPlayers == 2&&timer==false)
	{
		WriteFile.open("display\\HighScoreNormal2.txt");
	}
	if (level==Advanced&&totalPlayers == 2&&timer==false)
	{
		WriteFile.open("display\\HighScoreHard2.txt");
	}
	if (level == Novice && totalPlayers == 1&&timer==true)
	{
	WriteFile.open("display\\HighScoreEasy1time.txt");
	}
	if(level==Intermediate&&totalPlayers == 1&&timer==true)
	{
		WriteFile.open("display\\HighScoreNormal1time.txt");
	}
	if (level==Advanced &&totalPlayers == 1&&timer==true)
	{
		WriteFile.open("display\\HighScoreHard1time.txt");
	}
	if (level==Novice &&totalPlayers ==2&&timer==true)
	{
		WriteFile.open("display\\HighScoreEasy2time.txt");
	}
	if(level==Intermediate &&totalPlayers == 2&&timer==true)
	{
		WriteFile.open("display\\HighScoreNormal2time.txt");
	}
	if (level==Advanced&&totalPlayers == 2&&timer==true)
	{
		WriteFile.open("display\\HighScoreHard2time.txt");
	
	}
	if(ChangeFirst==0 && ChangeSecond==0 && ChangeThird==0)//Rewrite Text
	{
		WriteFile<<FirstPlayer <<std::endl;
		WriteFile<<CheckPlayer1Score<<std::endl;
		WriteFile<<SecondPlayer<<std::endl;
		WriteFile<<CheckPlayer2Score<<std::endl;
		WriteFile<<ThirdPlayer<<std::endl;
		WriteFile<<CheckPlayer3Score<<std::endl;
	}
	if(ChangeFirst==1)//replace first player
	{
	ThirdPlayer=SecondPlayer;
	SecondPlayer=FirstPlayer;
	CheckPlayer3Score=CheckPlayer2Score;
	CheckPlayer2Score=CheckPlayer1Score;
	FirstPlayer=PlayerName;
	std::ostringstream convert;
	convert << static_cast<int>(ChangeScore);
	FirstPlayerScoreString = convert.str();
	WriteFile<<FirstPlayer<< std::endl;
	WriteFile<<FirstPlayerScoreString<<std::endl;
	WriteFile<<SecondPlayer<<std::endl;
	WriteFile<<CheckPlayer2Score<<std::endl;
	WriteFile<<ThirdPlayer<<std::endl;
	WriteFile<<CheckPlayer3Score<<std::endl;
	ChangeFirst=0;
	}
	if(ChangeSecond==1)//replace second player 
	{
	ThirdPlayer=SecondPlayer;
	CheckPlayer3Score=CheckPlayer2Score;
	SecondPlayer=PlayerName;
	std::ostringstream convert;
	convert << static_cast<int>(ChangeScore);
	SecondPlayerScoreString = convert.str();
	WriteFile<<FirstPlayer<< std::endl;
	WriteFile<<CheckPlayer1Score<<std::endl;
	WriteFile<<SecondPlayer<<std::endl;
	WriteFile<<SecondPlayerScoreString<<std::endl;
	WriteFile<<ThirdPlayer<<std::endl;
	WriteFile<<CheckPlayer3Score<<std::endl;
	ChangeSecond=0;
	}
	if(ChangeThird==1)//replace third player
	{
	ThirdPlayer=PlayerName;
	std::ostringstream convert;
	convert << static_cast<int>(ChangeScore);
	ThirdPlayerScoreString = convert.str();
	WriteFile<<FirstPlayer<< std::endl;
	WriteFile<<CheckPlayer1Score<<std::endl;
	WriteFile<<SecondPlayer<<std::endl;
	WriteFile<<CheckPlayer2Score<<std::endl;
	WriteFile<<ThirdPlayer<<std::endl;
	WriteFile<<ThirdPlayerScoreString<<std::endl;
	ChangeThird=0;
	}
	
	WriteFile.close();
}
void print()//Done by jeffrey, Print out highscore after game ends
{
		COORD c;c.X=0;
			c.Y=8;
		std::ifstream ReadFile;
		std::ifstream ReadTitle;
		string Title;
	if (level==Novice&&totalPlayers == 1&&timer==false)
	{
		ReadFile.open("display\\HighScoreEasy1.txt");
		
	}
	if(level==Intermediate&&totalPlayers == 1&&timer==false)
	{
		ReadFile.open("display\\HighScoreNormal1.txt");
		
	}
	if (level==Advanced&&totalPlayers == 1&&timer==false)
	{
		ReadFile.open("display\\HighScoreHard1.txt");
		
	}
	if (level==Novice&&totalPlayers == 2&&timer==false)
	{
		ReadFile.open("display\\HighScoreEasy2.txt");
	}
	if(level==Intermediate&&totalPlayers == 2&&timer==false)
	{
		ReadFile.open("display\\HighScoreNormal2.txt");
		
	}
	if (level==Advanced&&totalPlayers == 2&&timer==false)
	{
		ReadFile.open("display\\HighScoreHard2.txt");
		
	}
	if (level == Novice && totalPlayers == 1&&timer==true)
	{
	ReadFile.open("display\\HighScoreEasy1time.txt");
	}
	if(level==Intermediate&&totalPlayers == 1&&timer==true)
	{
		ReadFile.open("display\\HighScoreNormal1time.txt");
	}
	if (level==Advanced &&totalPlayers == 1&&timer==true)
	{
		ReadFile.open("display\\HighScoreHard1time.txt");
	}
	if (level==Novice &&totalPlayers ==2&&timer==true)
	{
	ReadFile.open("display\\HighScoreEasy2time.txt");
	}
	if(level==Intermediate &&totalPlayers == 2&&timer==true)
	{
		ReadFile.open("display\\HighScoreNormal2time.txt");
	}
	if (level==Advanced&&totalPlayers == 2&&timer==true)
	{
		ReadFile.open("display\\HighScoreHard2time.txt");
	
	}
		std::getline(ReadFile,FirstPlayer,'\n');
		std::getline(ReadFile,CheckPlayer1Score,'\n');
		std::getline(ReadFile,SecondPlayer,'\n');
		std::getline(ReadFile,CheckPlayer2Score,'\n');
		std::getline(ReadFile,ThirdPlayer,'\n');
		std::getline(ReadFile,CheckPlayer3Score,'\n');
		g_Console.writeToBuffer(1,14,"First :");
		g_Console.writeToBuffer(8,14,FirstPlayer);
		g_Console.writeToBuffer(8+FirstPlayer.length(),14," : ");
		g_Console.writeToBuffer(8+2+FirstPlayer.length(),14,CheckPlayer1Score);
		g_Console.writeToBuffer(0,15,"Second :");
		g_Console.writeToBuffer(8,15,SecondPlayer);
		g_Console.writeToBuffer(8+SecondPlayer.length(),15," : ");
		g_Console.writeToBuffer(8+2+SecondPlayer.length(),15,CheckPlayer2Score);
		g_Console.writeToBuffer(1,16,"Third :");
		g_Console.writeToBuffer(8,16,ThirdPlayer);
		g_Console.writeToBuffer(8+ThirdPlayer.length(),16," : ");
		g_Console.writeToBuffer(8+2+ThirdPlayer.length(),16,CheckPlayer3Score);
		if(Result1=="")//If 0 points earned,a '0' will be placed in the string that will be printed
		{
			Result1="0";
		}
			g_Console.writeToBuffer(0,3,"Total Points Earned:");
		if (total1>total2)
		{
			g_Console.writeToBuffer(22,3,Result1, 0x04);
		}
		else
		{
			g_Console.writeToBuffer(22,3,Result2, 0x04);
		}
		ReadFile.close();
} 
void printalltime()//Done by Jeffrey,Print out all highscore for timed mode
{
		clearScreen();  
		g_Console.writeToBuffer(20,3,"1 Player Timed Mode");
		std::ifstream ReadFile;
		ReadFile.open("display\\HighScoreEasy1time.txt");
		std::getline(ReadFile,FirstPlayer,'\n');
		std::getline(ReadFile,CheckPlayer1Score,'\n');
		std::getline(ReadFile,SecondPlayer,'\n');
		std::getline(ReadFile,CheckPlayer2Score,'\n');
		std::getline(ReadFile,ThirdPlayer,'\n');
		std::getline(ReadFile,CheckPlayer3Score,'\n');
		g_Console.writeToBuffer(0,5,"1:Easy");
		g_Console.writeToBuffer(0,7,FirstPlayer);
		g_Console.writeToBuffer(0+FirstPlayer.length(),7," : ");
		g_Console.writeToBuffer(0+3+FirstPlayer.length(),7,CheckPlayer1Score);
		g_Console.writeToBuffer(0,8,SecondPlayer);
		g_Console.writeToBuffer(0+SecondPlayer.length(),8," : ");
		g_Console.writeToBuffer(0+3+SecondPlayer.length(),8,CheckPlayer2Score);
		g_Console.writeToBuffer(0,9,ThirdPlayer);
		g_Console.writeToBuffer(0+ThirdPlayer.length(),9," : ");
		g_Console.writeToBuffer(0+3+ThirdPlayer.length(),9,CheckPlayer3Score);
		ReadFile.close();

		std::ifstream ReadFile2;
		ReadFile2.open("display\\HighScoreNormal1time.txt");
		std::getline(ReadFile2,FirstPlayer,'\n');
		std::getline(ReadFile2,CheckPlayer1Score,'\n');
		std::getline(ReadFile2,SecondPlayer,'\n');
		std::getline(ReadFile2,CheckPlayer2Score,'\n');
		std::getline(ReadFile2,ThirdPlayer,'\n');
		std::getline(ReadFile2,CheckPlayer3Score,'\n');
		g_Console.writeToBuffer(20,5,"2:Normal");
		g_Console.writeToBuffer(20,7,FirstPlayer);
		g_Console.writeToBuffer(20+FirstPlayer.length(),7," : ");
		g_Console.writeToBuffer(20+2+FirstPlayer.length(),7,CheckPlayer1Score);
		g_Console.writeToBuffer(20,8,SecondPlayer);
		g_Console.writeToBuffer(20+SecondPlayer.length(),8," : ");
		g_Console.writeToBuffer(20+2+SecondPlayer.length(),8,CheckPlayer2Score);
		g_Console.writeToBuffer(20,9,ThirdPlayer);
		g_Console.writeToBuffer(20+ThirdPlayer.length(),9," : ");
		g_Console.writeToBuffer(20+2+ThirdPlayer.length(),9,CheckPlayer3Score);
		ReadFile2.close();
		std::ifstream ReadFile3;
		ReadFile3.open("display\\HighScoreHard1time.txt");
		std::getline(ReadFile3,FirstPlayer,'\n');
		std::getline(ReadFile3,CheckPlayer1Score,'\n');
		std::getline(ReadFile3,SecondPlayer,'\n');
		std::getline(ReadFile3,CheckPlayer2Score,'\n');
		std::getline(ReadFile3,ThirdPlayer,'\n');
		std::getline(ReadFile3,CheckPlayer3Score,'\n');
		g_Console.writeToBuffer(40,5,"3:Hard");
		g_Console.writeToBuffer(40,7,FirstPlayer);
		g_Console.writeToBuffer(40+FirstPlayer.length(),7," : ");
		g_Console.writeToBuffer(40+2+FirstPlayer.length(),7,CheckPlayer1Score);
		g_Console.writeToBuffer(40,8,SecondPlayer);
		g_Console.writeToBuffer(40+SecondPlayer.length(),8," : ");
		g_Console.writeToBuffer(40+2+SecondPlayer.length(),8,CheckPlayer2Score);
		g_Console.writeToBuffer(40,9,ThirdPlayer);
		g_Console.writeToBuffer(40+ThirdPlayer.length(),9," : ");
		g_Console.writeToBuffer(40+2+ThirdPlayer.length(),9,CheckPlayer3Score);
		ReadFile3.close();
		
		g_Console.writeToBuffer(20,15,"2 Player Timed Mode");

			std::ifstream ReadFile4;
		ReadFile4.open("display\\HighScoreEasy2time.txt");
		std::getline(ReadFile4,FirstPlayer,'\n');
		std::getline(ReadFile4,CheckPlayer1Score,'\n');
		std::getline(ReadFile4,SecondPlayer,'\n');
		std::getline(ReadFile4,CheckPlayer2Score,'\n');
		std::getline(ReadFile4,ThirdPlayer,'\n');
		std::getline(ReadFile4,CheckPlayer3Score,'\n');
		g_Console.writeToBuffer(0,17,"4:Easy");
		g_Console.writeToBuffer(0,19,FirstPlayer);
		g_Console.writeToBuffer(0+FirstPlayer.length(),19," : ");
		g_Console.writeToBuffer(0+3+FirstPlayer.length(),19,CheckPlayer1Score);
		g_Console.writeToBuffer(0,20,SecondPlayer);
		g_Console.writeToBuffer(0+SecondPlayer.length(),20," : ");
		g_Console.writeToBuffer(0+3+SecondPlayer.length(),20,CheckPlayer2Score);
		g_Console.writeToBuffer(0,21,ThirdPlayer);
		g_Console.writeToBuffer(0+ThirdPlayer.length(),21," : ");
		g_Console.writeToBuffer(0+3+ThirdPlayer.length(),21,CheckPlayer3Score);
		ReadFile4.close();

			std::ifstream ReadFile5;
		ReadFile5.open("display\\HighScoreNormal2time.txt");
		std::getline(ReadFile5,FirstPlayer,'\n');
		std::getline(ReadFile5,CheckPlayer1Score,'\n');
		std::getline(ReadFile5,SecondPlayer,'\n');
		std::getline(ReadFile5,CheckPlayer2Score,'\n');
		std::getline(ReadFile5,ThirdPlayer,'\n');
		std::getline(ReadFile5,CheckPlayer3Score,'\n');
		g_Console.writeToBuffer(20,17,"5:Normal");
		g_Console.writeToBuffer(20,19,FirstPlayer);
		g_Console.writeToBuffer(20+FirstPlayer.length(),19," : ");
		g_Console.writeToBuffer(20+2+FirstPlayer.length(),19,CheckPlayer1Score);
		g_Console.writeToBuffer(20,20,SecondPlayer);
		g_Console.writeToBuffer(20+SecondPlayer.length(),20," : ");
		g_Console.writeToBuffer(20+2+SecondPlayer.length(),20,CheckPlayer2Score);
		g_Console.writeToBuffer(20,21,ThirdPlayer);
		g_Console.writeToBuffer(20+ThirdPlayer.length(),21," : ");
		g_Console.writeToBuffer(20+2+ThirdPlayer.length(),21,CheckPlayer3Score);
		ReadFile5.close();



			std::ifstream ReadFile6;
			ReadFile6.open("display\\HighScoreHard2time.txt");
		std::getline(ReadFile6,FirstPlayer,'\n');
		std::getline(ReadFile6,CheckPlayer1Score,'\n');
		std::getline(ReadFile6,SecondPlayer,'\n');
		std::getline(ReadFile6,CheckPlayer2Score,'\n');
		std::getline(ReadFile6,ThirdPlayer,'\n');
		std::getline(ReadFile6,CheckPlayer3Score,'\n');
		g_Console.writeToBuffer(40,17,"6:Hard");
		g_Console.writeToBuffer(40,19,FirstPlayer);
		g_Console.writeToBuffer(40+FirstPlayer.length(),19," : ");
		g_Console.writeToBuffer(40+2+FirstPlayer.length(),19,CheckPlayer1Score);
		g_Console.writeToBuffer(40,20,SecondPlayer);
		g_Console.writeToBuffer(40+SecondPlayer.length(),20," : ");
		g_Console.writeToBuffer(40+2+SecondPlayer.length(),20,CheckPlayer2Score);
		g_Console.writeToBuffer(40,21,ThirdPlayer);
		g_Console.writeToBuffer(40+ThirdPlayer.length(),21," : ");
		g_Console.writeToBuffer(40+2+ThirdPlayer.length(),21,CheckPlayer3Score);
		ReadFile6.close();
}
void printall()//Done by Jeffrey,print all highscore for normal mode
{

	 
		clearScreen();  
		g_Console.writeToBuffer(20,3,"1 Player Mode");
		
		std::ifstream ReadFile;
		ReadFile.open("display\\HighScoreEasy1.txt");
		std::getline(ReadFile,FirstPlayer,'\n');
		std::getline(ReadFile,CheckPlayer1Score,'\n');
		std::getline(ReadFile,SecondPlayer,'\n');
		std::getline(ReadFile,CheckPlayer2Score,'\n');
		std::getline(ReadFile,ThirdPlayer,'\n');
		std::getline(ReadFile,CheckPlayer3Score,'\n');
		g_Console.writeToBuffer(0,5,"1:Easy");
		g_Console.writeToBuffer(0,7,FirstPlayer);
		g_Console.writeToBuffer(0+FirstPlayer.length(),7," : ");
		g_Console.writeToBuffer(0+3+FirstPlayer.length(),7,CheckPlayer1Score);
		g_Console.writeToBuffer(0,8,SecondPlayer);
		g_Console.writeToBuffer(0+SecondPlayer.length(),8," : ");
		g_Console.writeToBuffer(0+3+SecondPlayer.length(),8,CheckPlayer2Score);
		g_Console.writeToBuffer(0,9,ThirdPlayer);
		g_Console.writeToBuffer(0+ThirdPlayer.length(),9," : ");
		g_Console.writeToBuffer(0+3+ThirdPlayer.length(),9,CheckPlayer3Score);
		ReadFile.close();

		std::ifstream ReadFile2;
		ReadFile2.open("display\\HighScoreNormal1.txt");
		std::getline(ReadFile2,FirstPlayer,'\n');
		std::getline(ReadFile2,CheckPlayer1Score,'\n');
		std::getline(ReadFile2,SecondPlayer,'\n');
		std::getline(ReadFile2,CheckPlayer2Score,'\n');
		std::getline(ReadFile2,ThirdPlayer,'\n');
		std::getline(ReadFile2,CheckPlayer3Score,'\n');
		g_Console.writeToBuffer(20,5,"2:Normal");
		g_Console.writeToBuffer(20,7,FirstPlayer);
		g_Console.writeToBuffer(20+FirstPlayer.length(),7," : ");
		g_Console.writeToBuffer(20+2+FirstPlayer.length(),7,CheckPlayer1Score);
		g_Console.writeToBuffer(20,8,SecondPlayer);
		g_Console.writeToBuffer(20+SecondPlayer.length(),8," : ");
		g_Console.writeToBuffer(20+2+SecondPlayer.length(),8,CheckPlayer2Score);
		g_Console.writeToBuffer(20,9,ThirdPlayer);
		g_Console.writeToBuffer(20+ThirdPlayer.length(),9," : ");
		g_Console.writeToBuffer(20+2+ThirdPlayer.length(),9,CheckPlayer3Score);
		ReadFile2.close();
		std::ifstream ReadFile3;
		ReadFile3.open("display\\HighScoreHard1.txt");
		std::getline(ReadFile3,FirstPlayer,'\n');
		std::getline(ReadFile3,CheckPlayer1Score,'\n');
		std::getline(ReadFile3,SecondPlayer,'\n');
		std::getline(ReadFile3,CheckPlayer2Score,'\n');
		std::getline(ReadFile3,ThirdPlayer,'\n');
		std::getline(ReadFile3,CheckPlayer3Score,'\n');
		g_Console.writeToBuffer(40,5,"3:Hard");
		g_Console.writeToBuffer(40,7,FirstPlayer);
		g_Console.writeToBuffer(40+FirstPlayer.length(),7," : ");
		g_Console.writeToBuffer(40+2+FirstPlayer.length(),7,CheckPlayer1Score);
		g_Console.writeToBuffer(40,8,SecondPlayer);
		g_Console.writeToBuffer(40+SecondPlayer.length(),8," : ");
		g_Console.writeToBuffer(40+2+SecondPlayer.length(),8,CheckPlayer2Score);
		g_Console.writeToBuffer(40,9,ThirdPlayer);
		g_Console.writeToBuffer(40+ThirdPlayer.length(),9," : ");
		g_Console.writeToBuffer(40+2+ThirdPlayer.length(),9,CheckPlayer3Score);
		ReadFile3.close();
		
		g_Console.writeToBuffer(20,15,"2 Player Mode");

		std::ifstream ReadFile4;
		ReadFile4.open("display\\HighScoreEasy2.txt");
		std::getline(ReadFile4,FirstPlayer,'\n');
		std::getline(ReadFile4,CheckPlayer1Score,'\n');
		std::getline(ReadFile4,SecondPlayer,'\n');
		std::getline(ReadFile4,CheckPlayer2Score,'\n');
		std::getline(ReadFile4,ThirdPlayer,'\n');
		std::getline(ReadFile4,CheckPlayer3Score,'\n');
		g_Console.writeToBuffer(0,17,"4:Easy");
		g_Console.writeToBuffer(0,19,FirstPlayer);
		g_Console.writeToBuffer(0+FirstPlayer.length(),19," : ");
		g_Console.writeToBuffer(0+3+FirstPlayer.length(),19,CheckPlayer1Score);
		g_Console.writeToBuffer(0,20,SecondPlayer);
		g_Console.writeToBuffer(0+SecondPlayer.length(),20," : ");
		g_Console.writeToBuffer(0+3+SecondPlayer.length(),20,CheckPlayer2Score);
		g_Console.writeToBuffer(0,21,ThirdPlayer);
		g_Console.writeToBuffer(0+ThirdPlayer.length(),21," : ");
		g_Console.writeToBuffer(0+3+ThirdPlayer.length(),21,CheckPlayer3Score);
		ReadFile4.close();

		std::ifstream ReadFile5;
		ReadFile5.open("display\\HighScoreNormal2.txt");
		std::getline(ReadFile5,FirstPlayer,'\n');
		std::getline(ReadFile5,CheckPlayer1Score,'\n');
		std::getline(ReadFile5,SecondPlayer,'\n');
		std::getline(ReadFile5,CheckPlayer2Score,'\n');
		std::getline(ReadFile5,ThirdPlayer,'\n');
		std::getline(ReadFile5,CheckPlayer3Score,'\n');
		g_Console.writeToBuffer(20,17,"5:Normal");
		g_Console.writeToBuffer(20,19,FirstPlayer);
		g_Console.writeToBuffer(20+FirstPlayer.length(),19," : ");
		g_Console.writeToBuffer(20+2+FirstPlayer.length(),19,CheckPlayer1Score);
		g_Console.writeToBuffer(20,20,SecondPlayer);
		g_Console.writeToBuffer(20+SecondPlayer.length(),20," : ");
		g_Console.writeToBuffer(20+2+SecondPlayer.length(),20,CheckPlayer2Score);
		g_Console.writeToBuffer(20,21,ThirdPlayer);
		g_Console.writeToBuffer(20+ThirdPlayer.length(),21," : ");
		g_Console.writeToBuffer(20+2+ThirdPlayer.length(),21,CheckPlayer3Score);
		ReadFile5.close();


		std::ifstream ReadFile6;
		ReadFile6.open("display\\HighScoreHard2.txt");
		std::getline(ReadFile6,FirstPlayer,'\n');
		std::getline(ReadFile6,CheckPlayer1Score,'\n');
		std::getline(ReadFile6,SecondPlayer,'\n');
		std::getline(ReadFile6,CheckPlayer2Score,'\n');
		std::getline(ReadFile6,ThirdPlayer,'\n');
		std::getline(ReadFile6,CheckPlayer3Score,'\n');
		g_Console.writeToBuffer(40,17,"6:Hard");
		g_Console.writeToBuffer(40,19,FirstPlayer);
		g_Console.writeToBuffer(40+FirstPlayer.length(),19," : ");
		g_Console.writeToBuffer(40+2+FirstPlayer.length(),19,CheckPlayer1Score);
		g_Console.writeToBuffer(40,20,SecondPlayer);
		g_Console.writeToBuffer(40+SecondPlayer.length(),20," : ");
		g_Console.writeToBuffer(40+2+SecondPlayer.length(),20,CheckPlayer2Score);
		g_Console.writeToBuffer(40,21,ThirdPlayer);
		g_Console.writeToBuffer(40+ThirdPlayer.length(),21," : ");
		g_Console.writeToBuffer(40+2+ThirdPlayer.length(),21,CheckPlayer3Score);
		ReadFile6.close();
}
void  ResetSelectedHighScoreInput()//Done by Jeffrey,Reset highscore for normal mode.
{
	
		if(g_abKeyPressedName[K_1])
		 {
		  PlaySound(L"sound\\button.wav",NULL,SND_ASYNC);
		  ResetEasy1();
		 }
		if(g_abKeyPressedName[K_2])
		 {
		  PlaySound(L"sound\\button.wav",NULL,SND_ASYNC);
		  ResetNormal1();
		 }
	 
		 if(g_abKeyPressedName[K_3])
	     {
		   PlaySound(L"sound\\.wav",NULL,SND_ASYNC);
		   ResetHard1();
	     } 
		 if(g_abKeyPressedName[K_4])
		 {
		    PlaySound(L"sound\\button.wav",NULL,SND_ASYNC);
			ResetEasy2();
		 }
		if(g_abKeyPressedName[K_5])
		 {
		  PlaySound(L"sound\\button.wav",NULL,SND_ASYNC);
		   ResetNormal2();
	     }
		if(g_abKeyPressedName[K_6])
		{
		 PlaySound(L"sound\\button.wav",NULL,SND_ASYNC);
		 ResetHard2();
		}
		if (g_abKeyPressedName[K_ESCAPE2])
		{
		 PlaySound(L"sound\\button.wav",NULL,SND_ASYNC);
		 g_eGameState=S_MAINMENU;
		}

}	
void ResetEasy1()//Done by Jeffrey,Reset Easy difficulty ,1 player for normal mode
{
		FirstPlayer="Empty";
		SecondPlayer="Empty";
		ThirdPlayer="Empty";
		CheckPlayer1Score="0";
		CheckPlayer2Score="0";
		CheckPlayer3Score="0";
		std::ofstream WriteFile;
		WriteFile.open("display\\HighScoreEasy1.txt");
		WriteFile<<FirstPlayer <<std::endl;
		WriteFile<<CheckPlayer1Score<<std::endl;
		WriteFile<<SecondPlayer<<std::endl;
		WriteFile<<CheckPlayer2Score<<std::endl;
		WriteFile<<ThirdPlayer<<std::endl;
		WriteFile<<CheckPlayer3Score<<std::endl;
		WriteFile.close();
	
}
void ResetNormal1()// Done by jeffrey ,Reset Normal difficulty, 1 player for normal mode
{
		FirstPlayer="Empty";
		SecondPlayer="Empty";
		ThirdPlayer="Empty";
		CheckPlayer1Score="0";
		CheckPlayer2Score="0";
		CheckPlayer3Score="0";
		std::ofstream WriteFile;
		WriteFile.open("display\\HighScoreNormal1.txt");
		WriteFile<<FirstPlayer <<std::endl;
		WriteFile<<CheckPlayer1Score<<std::endl;
		WriteFile<<SecondPlayer<<std::endl;
		WriteFile<<CheckPlayer2Score<<std::endl;
		WriteFile<<ThirdPlayer<<std::endl;
		WriteFile<<CheckPlayer3Score<<std::endl;
		WriteFile.close();
}
void ResetHard1()//Done by jeffrey,Reset Hard difficulty,1 player,for normal mode
{
		FirstPlayer="Empty";
		SecondPlayer="Empty";
		ThirdPlayer="Empty";
		CheckPlayer1Score="0";
		CheckPlayer2Score="0";
		CheckPlayer3Score="0";
		std::ofstream WriteFile;
		WriteFile.open("display\\HighScoreHard1.txt");
		WriteFile<<FirstPlayer <<std::endl;
		WriteFile<<CheckPlayer1Score<<std::endl;
		WriteFile<<SecondPlayer<<std::endl;
		WriteFile<<CheckPlayer2Score<<std::endl;
		WriteFile<<ThirdPlayer<<std::endl;
		WriteFile<<CheckPlayer3Score<<std::endl;
		WriteFile.close();
	
}
void ResetEasy2()// Done by Jeffrey,Reset Easy difficulty,2 player,Normal mode
{
		FirstPlayer="Empty";
		SecondPlayer="Empty";
		ThirdPlayer="Empty";
		CheckPlayer1Score="0";
		CheckPlayer2Score="0";
		CheckPlayer3Score="0";
		std::ofstream WriteFile;
		WriteFile.open("display\\HighScoreEasy2.txt");
		WriteFile<<FirstPlayer <<std::endl;
		WriteFile<<CheckPlayer1Score<<std::endl;
		WriteFile<<SecondPlayer<<std::endl;
		WriteFile<<CheckPlayer2Score<<std::endl;
		WriteFile<<ThirdPlayer<<std::endl;
		WriteFile<<CheckPlayer3Score<<std::endl;
		WriteFile.close();
	
}
void ResetNormal2()//Done by Jeffrey,Reset Normal difficulty ,2 player,for normal mode
{
		FirstPlayer="Empty";
		SecondPlayer="Empty";
		ThirdPlayer="Empty";
		CheckPlayer1Score="0";
		CheckPlayer2Score="0";
		CheckPlayer3Score="0";
		std::ofstream WriteFile;
		WriteFile.open("display\\HighScoreNormal2.txt");
		WriteFile<<FirstPlayer <<std::endl;
		WriteFile<<CheckPlayer1Score<<std::endl;
		WriteFile<<SecondPlayer<<std::endl;
		WriteFile<<CheckPlayer2Score<<std::endl;
		WriteFile<<ThirdPlayer<<std::endl;
		WriteFile<<CheckPlayer3Score<<std::endl;
		WriteFile.close();
}
void ResetHard2()//Done by Jeffrey,Reset Hard difficulty,2 player ,Normal mode
{
		FirstPlayer="Empty";
		SecondPlayer="Empty";
		ThirdPlayer="Empty";
		CheckPlayer1Score="0";
		CheckPlayer2Score="0";
		CheckPlayer3Score="0";
		std::ofstream WriteFile;
		WriteFile.open("display\\HighScoreHard2.txt");
		WriteFile<<FirstPlayer <<std::endl;
		WriteFile<<CheckPlayer1Score<<std::endl;
		WriteFile<<SecondPlayer<<std::endl;
		WriteFile<<CheckPlayer2Score<<std::endl;
		WriteFile<<ThirdPlayer<<std::endl;
		WriteFile<<CheckPlayer3Score<<std::endl;
		WriteFile.close();
	
}
void renderResetSelectedHighScore()//Done by Jeffrey,Ask player what highscore they want to reset
{
	g_Console.writeToBuffer(0,0,"Select what highscore you want to reset by pressing it's number",0x04);
	
}
void ResetEasy1time()//Done by Jeffrey,Reset Easy Difficulty, for 1 player,timed mode
{
		FirstPlayer="Empty";
		SecondPlayer="Empty";
		ThirdPlayer="Empty";
		CheckPlayer1Score="0";
		CheckPlayer2Score="0";
		CheckPlayer3Score="0";
		std::ofstream WriteFile;
		WriteFile.open("display\\HighScoreEasy1time.txt");
		WriteFile<<FirstPlayer <<std::endl;
		WriteFile<<CheckPlayer1Score<<std::endl;
		WriteFile<<SecondPlayer<<std::endl;
		WriteFile<<CheckPlayer2Score<<std::endl;
		WriteFile<<ThirdPlayer<<std::endl;
		WriteFile<<CheckPlayer3Score<<std::endl;
		WriteFile.close();
	
}
void ResetNormal1time()// Done by jeffrey,Reset Normal Difficulty,for 1 player,timed mode
{
		FirstPlayer="Empty";
		SecondPlayer="Empty";
		ThirdPlayer="Empty";
		CheckPlayer1Score="0";
		CheckPlayer2Score="0";
		CheckPlayer3Score="0";
		std::ofstream WriteFile;
		WriteFile.open("display\\HighScoreNormal1time.txt");
		WriteFile<<FirstPlayer <<std::endl;
		WriteFile<<CheckPlayer1Score<<std::endl;
		WriteFile<<SecondPlayer<<std::endl;
		WriteFile<<CheckPlayer2Score<<std::endl;
		WriteFile<<ThirdPlayer<<std::endl;
		WriteFile<<CheckPlayer3Score<<std::endl;
		WriteFile.close();
}
void ResetHard1time()//Done by Jeffrey ,Reset Hard difficulty,1 player mode,timed mode
{
		FirstPlayer="Empty";
		SecondPlayer="Empty";
		ThirdPlayer="Empty";
		CheckPlayer1Score="0";
		CheckPlayer2Score="0";
		CheckPlayer3Score="0";
		std::ofstream WriteFile;
		WriteFile.open("display\\HighScoreHard1time.txt");
		WriteFile<<FirstPlayer <<std::endl;
		WriteFile<<CheckPlayer1Score<<std::endl;
		WriteFile<<SecondPlayer<<std::endl;
		WriteFile<<CheckPlayer2Score<<std::endl;
		WriteFile<<ThirdPlayer<<std::endl;
		WriteFile<<CheckPlayer3Score<<std::endl;
		WriteFile.close();
	
}
void ResetEasy2time()//Done by Jeffrey,Reset Easy difficulty,2player mode,timed mode
{
		FirstPlayer="Empty";
		SecondPlayer="Empty";
		ThirdPlayer="Empty";
		CheckPlayer1Score="0";
		CheckPlayer2Score="0";
		CheckPlayer3Score="0";
		std::ofstream WriteFile;
		WriteFile.open("display\\HighScoreEasy2time.txt");
		WriteFile<<FirstPlayer <<std::endl;
		WriteFile<<CheckPlayer1Score<<std::endl;
		WriteFile<<SecondPlayer<<std::endl;
		WriteFile<<CheckPlayer2Score<<std::endl;
		WriteFile<<ThirdPlayer<<std::endl;
		WriteFile<<CheckPlayer3Score<<std::endl;
		WriteFile.close();
	
}
void ResetNormal2time()//Done by Jeffrey,Reset normal difficulty,2 player mode,timed mode
{
		FirstPlayer="Empty";
		SecondPlayer="Empty";
		ThirdPlayer="Empty";
		CheckPlayer1Score="0";
		CheckPlayer2Score="0";
		CheckPlayer3Score="0";
		std::ofstream WriteFile;
		WriteFile.open("display\\HighScoreNormal2time.txt");
		WriteFile<<FirstPlayer <<std::endl;
		WriteFile<<CheckPlayer1Score<<std::endl;
		WriteFile<<SecondPlayer<<std::endl;
		WriteFile<<CheckPlayer2Score<<std::endl;
		WriteFile<<ThirdPlayer<<std::endl;
		WriteFile<<CheckPlayer3Score<<std::endl;
		WriteFile.close();
}
void ResetHard2time()//Reset Hard Difficulty,2 player mode,timed mode
{
		FirstPlayer="Empty";
		SecondPlayer="Empty";
		ThirdPlayer="Empty";
		CheckPlayer1Score="0";
		CheckPlayer2Score="0";
		CheckPlayer3Score="0";
		std::ofstream WriteFile;
		WriteFile.open("display\\HighScoreHard2time.txt");
		WriteFile<<FirstPlayer <<std::endl;
		WriteFile<<CheckPlayer1Score<<std::endl;
		WriteFile<<SecondPlayer<<std::endl;
		WriteFile<<CheckPlayer2Score<<std::endl;
		WriteFile<<ThirdPlayer<<std::endl;
		WriteFile<<CheckPlayer3Score<<std::endl;
		WriteFile.close();
	
}
void ResetSelectedHighScoreInputTime()//Done by jeffrey,Reset highscore for Timed mode
{
	if(g_abKeyPressedName[K_1])
		 {
		  PlaySound(L"sound\\button.wav",NULL,SND_ASYNC);
		  ResetEasy1time();
		 }
		if(g_abKeyPressedName[K_2])
		 {
		   PlaySound(L"sound\\button.wav",NULL,SND_ASYNC);
		   ResetNormal1time();
		 }
	 
		 if(g_abKeyPressedName[K_3])
	     {
			PlaySound(L"sound\\button.wav",NULL,SND_ASYNC);
			ResetHard1time();
	
	     } 
		if(g_abKeyPressedName[K_4])
		{
		 PlaySound(L"sound\\button.wav",NULL,SND_ASYNC);
		 ResetEasy2time();
		}
	  if(g_abKeyPressedName[K_5])
		{
		 PlaySound(L"sound\\button.wav",NULL,SND_ASYNC);
		 ResetNormal2time();
		}
	  if(g_abKeyPressedName[K_6])
		{
		PlaySound(L"sound\\button.wav",NULL,SND_ASYNC);
		ResetHard2time();
		}
	  if (g_abKeyPressedName[K_ESCAPE2])
	  {
		PlaySound(L"sound\\button.wav",NULL,SND_ASYNC);
		g_eGameState=S_MAINMENU;
	  }

}