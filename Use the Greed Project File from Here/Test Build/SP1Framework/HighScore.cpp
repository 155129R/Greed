#include<iostream>
#include<string>
#include<sstream>
#include <fstream>
#include <iomanip>
#include "HighScore.h"
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
void write();
void print();
void check(int &total1,int &total2);
void NameInput();
void printall();
void displayPlayerName();
void NameInputKeys();
bool g_abKeyPressedName[K_Z];
void ResetHighScore();
void renderResetSelectedHighScore();
void  ResetSelectedHighScoreInput();
void ResetNovice1();
void ResetIntermediate1();
void ResetAdvanced1();
void ResetNovice2();
void ResetIntermediate2();
void ResetAdvanced2();
//void HighScorefor1player();
void AskforInput();
//void HighScorefor1Player()
//{
//	AskforInput();
//	check(total1);
//	write();
//	print();
//}
void AskforInput()
{
  g_Console.writeToBuffer(1,0,"Input Your name(will only take in max 10 characters)and press enter:", 0x04);

}
void NameInputKeys()
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
void NameInput()
{
	if(PlayerName.length()<11)
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
void displayPlayerName()
{
	{g_Console.writeToBuffer(0,2,PlayerName, 0x04);}
}
void check(int &total1,int &total2)
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
	if (level == Novice && totalPlayers == 1)
	{
	ReadFile.open("HighScoreNovice1.txt");
	}
	if(level==Intermediate&&totalPlayers == 1)
	{
		ReadFile.open("HighScoreIntermediate1.txt");
	}
	if (level==Advanced &&totalPlayers == 1)
	{
		ReadFile.open("HighScoreAdvanced1.txt");
	}
	if (level==Novice &&totalPlayers ==2)
	{
	ReadFile.open("HighScoreNovice2.txt");
	}
	if(level==Intermediate &&totalPlayers == 2)
	{
		ReadFile.open("HighScoreIntermediate2.txt");
	}
	if (level==Advanced&&totalPlayers == 2)
	{
		ReadFile.open("HighScoreAdvanced2.txt");
	
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
		}else if (ChangeScore==0 && ChangeScore>=(atoi(CheckPlayer1Score.c_str())) )// If they score 0 and greater than first player,replace.
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
	
		//g_eGameState=S_HIGHSCOREWRITE;
}
		

	
}
void write()
{
	
	std::ofstream WriteFile;
	if (level==Novice && totalPlayers == 1)
	{
	WriteFile.open("HighScoreNovice1.txt");
	}
	if(level==Intermediate&&totalPlayers == 1)
	{
		WriteFile.open("HighScoreIntermediate1.txt");
	}
	if (level==Advanced&&totalPlayers ==1)
	{
		WriteFile.open("HighScoreAdvanced1.txt");
	}
	if (level==Novice&&totalPlayers == 2)
	{
	WriteFile.open("HighScoreNovice2.txt");
	}
	if(level==Intermediate&&totalPlayers == 2)
	{
		WriteFile.open("HighScoreIntermediate2.txt");
	}
	if (level==Advanced&&totalPlayers == 2)
	{
		WriteFile.open("HighScoreAdvanced2.txt");
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


void print()
{
		COORD c;c.X=0;
			c.Y=8;
		std::ifstream ReadFile;
		std::ifstream ReadTitle;
		string Title;
	if (level==Novice&&totalPlayers == 1)
	{
		ReadFile.open("HighScoreNovice1.txt");
		ReadTitle.open("NoviceTitle.txt");
	}
	if(level==Intermediate&&totalPlayers == 1)
	{
		ReadFile.open("HighScoreIntermediate1.txt");
		ReadTitle.open("IntermediateTitle.txt");
	}
	if (level==Advanced&&totalPlayers == 1)
	{
		ReadFile.open("HighScoreAdvanced1.txt");
		ReadTitle.open("AdvancedTitle.txt");
	}
	if (level==Novice&&totalPlayers == 2)
	{
		ReadFile.open("HighScoreNovice2.txt");
		ReadTitle.open("NoviceTitle.txt");
	}
	if(level==Intermediate&&totalPlayers == 2)
	{
		ReadFile.open("HighScoreIntermediate2.txt");
		ReadTitle.open("IntermediateTitle.txt");
	}
	if (level==Advanced&&totalPlayers == 2)
	{
		ReadFile.open("HighScoreAdvanced2.txt");
		ReadTitle.open("AdvancedTitle.txt");
	}
		std::getline(ReadFile,FirstPlayer,'\n');
		std::getline(ReadFile,CheckPlayer1Score,'\n');
		std::getline(ReadFile,SecondPlayer,'\n');
		std::getline(ReadFile,CheckPlayer2Score,'\n');
		std::getline(ReadFile,ThirdPlayer,'\n');
		std::getline(ReadFile,CheckPlayer3Score,'\n');
		for(int i=0;ReadTitle.good(); i++)
		{
			
            std::getline(ReadTitle,Title);
            g_Console.writeToBuffer(c, Title,0x04);
			c.Y+=1;
        }
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



		if(Result1=="")
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

void printall()
{

	 
		clearScreen();  
		g_Console.writeToBuffer(20,3,"1 Player Mode");
		std::ifstream ReadFile;
		ReadFile.open("HighScoreNovice1.txt");
		std::getline(ReadFile,FirstPlayer,'\n');
		std::getline(ReadFile,CheckPlayer1Score,'\n');
		std::getline(ReadFile,SecondPlayer,'\n');
		std::getline(ReadFile,CheckPlayer2Score,'\n');
		std::getline(ReadFile,ThirdPlayer,'\n');
		std::getline(ReadFile,CheckPlayer3Score,'\n');
		g_Console.writeToBuffer(0,5,"1:Novice");
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
		ReadFile2.open("HighScoreIntermediate1.txt");
		std::getline(ReadFile2,FirstPlayer,'\n');
		std::getline(ReadFile2,CheckPlayer1Score,'\n');
		std::getline(ReadFile2,SecondPlayer,'\n');
		std::getline(ReadFile2,CheckPlayer2Score,'\n');
		std::getline(ReadFile2,ThirdPlayer,'\n');
		std::getline(ReadFile2,CheckPlayer3Score,'\n');
		g_Console.writeToBuffer(20,5,"2:Intermediate");
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
		ReadFile3.open("HighScoreAdvanced1.txt");
		std::getline(ReadFile3,FirstPlayer,'\n');
		std::getline(ReadFile3,CheckPlayer1Score,'\n');
		std::getline(ReadFile3,SecondPlayer,'\n');
		std::getline(ReadFile3,CheckPlayer2Score,'\n');
		std::getline(ReadFile3,ThirdPlayer,'\n');
		std::getline(ReadFile3,CheckPlayer3Score,'\n');
		g_Console.writeToBuffer(40,5,"3:Advanced");
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

			std::ifstream ReadFile4;
		ReadFile4.open("HighScoreNovice2.txt");
		std::getline(ReadFile4,FirstPlayer,'\n');
		std::getline(ReadFile4,CheckPlayer1Score,'\n');
		std::getline(ReadFile4,SecondPlayer,'\n');
		std::getline(ReadFile4,CheckPlayer2Score,'\n');
		std::getline(ReadFile4,ThirdPlayer,'\n');
		std::getline(ReadFile4,CheckPlayer3Score,'\n');
		g_Console.writeToBuffer(0,17,"4:Novice");
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
		ReadFile5.open("HighScoreIntermediate2.txt");
		std::getline(ReadFile5,FirstPlayer,'\n');
		std::getline(ReadFile5,CheckPlayer1Score,'\n');
		std::getline(ReadFile5,SecondPlayer,'\n');
		std::getline(ReadFile5,CheckPlayer2Score,'\n');
		std::getline(ReadFile5,ThirdPlayer,'\n');
		std::getline(ReadFile5,CheckPlayer3Score,'\n');
		g_Console.writeToBuffer(20,17,"5:Intermediate");
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



		g_Console.writeToBuffer(20,15,"2 Player Mode");

			std::ifstream ReadFile6;
			ReadFile6.open("HighScoreAdvanced2.txt");
		std::getline(ReadFile6,FirstPlayer,'\n');
		std::getline(ReadFile6,CheckPlayer1Score,'\n');
		std::getline(ReadFile6,SecondPlayer,'\n');
		std::getline(ReadFile6,CheckPlayer2Score,'\n');
		std::getline(ReadFile6,ThirdPlayer,'\n');
		std::getline(ReadFile6,CheckPlayer3Score,'\n');
		g_Console.writeToBuffer(40,17,"6:Advanced");
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
void  ResetSelectedHighScoreInput()
{
	
		if(g_abKeyPressedName[K_1])
		 {PlaySound(L"button.wav",NULL,SND_ASYNC);
		  ResetNovice1();
		 }
		if(g_abKeyPressedName[K_2])
		 {PlaySound(L"button.wav",NULL,SND_ASYNC);
		   ResetIntermediate1();
		 }
	 
		 if(g_abKeyPressedName[K_3])
	     {PlaySound(L"button.wav",NULL,SND_ASYNC);
		ResetAdvanced1();
	
	     } 
	   if(g_abKeyPressedName[K_4])
	  {PlaySound(L"button.wav",NULL,SND_ASYNC);
		  ResetNovice2();
	  }
	  if(g_abKeyPressedName[K_5])
	  {PlaySound(L"button.wav",NULL,SND_ASYNC);
		   ResetIntermediate2();
	  }
	  if(g_abKeyPressedName[K_6])
	  {PlaySound(L"button.wav",NULL,SND_ASYNC);
		ResetAdvanced2();
	  }
	  if (g_abKeyPressedName[K_ESCAPE2])
	  {PlaySound(L"button.wav",NULL,SND_ASYNC);
		  g_eGameState=S_MAINMENU;
	  }

}
	
void ResetNovice1()
{
		FirstPlayer="Empty";
		SecondPlayer="Empty";
		ThirdPlayer="Empty";
		CheckPlayer1Score="0";
		CheckPlayer2Score="0";
		CheckPlayer3Score="0";
		std::ofstream WriteFile;
		WriteFile.open("HighScoreNovice1.txt");
		WriteFile<<FirstPlayer <<std::endl;
		WriteFile<<CheckPlayer1Score<<std::endl;
		WriteFile<<SecondPlayer<<std::endl;
		WriteFile<<CheckPlayer2Score<<std::endl;
		WriteFile<<ThirdPlayer<<std::endl;
		WriteFile<<CheckPlayer3Score<<std::endl;
		WriteFile.close();
	
}
void ResetIntermediate1()
{
		FirstPlayer="Empty";
		SecondPlayer="Empty";
		ThirdPlayer="Empty";
		CheckPlayer1Score="0";
		CheckPlayer2Score="0";
		CheckPlayer3Score="0";
		std::ofstream WriteFile;
		WriteFile.open("HighScoreIntermediate1.txt");
		WriteFile<<FirstPlayer <<std::endl;
		WriteFile<<CheckPlayer1Score<<std::endl;
		WriteFile<<SecondPlayer<<std::endl;
		WriteFile<<CheckPlayer2Score<<std::endl;
		WriteFile<<ThirdPlayer<<std::endl;
		WriteFile<<CheckPlayer3Score<<std::endl;
		WriteFile.close();
}
void ResetAdvanced1()
{
		FirstPlayer="Empty";
		SecondPlayer="Empty";
		ThirdPlayer="Empty";
		CheckPlayer1Score="0";
		CheckPlayer2Score="0";
		CheckPlayer3Score="0";
		std::ofstream WriteFile;
		WriteFile.open("HighScoreAdvanced1.txt");
		WriteFile<<FirstPlayer <<std::endl;
		WriteFile<<CheckPlayer1Score<<std::endl;
		WriteFile<<SecondPlayer<<std::endl;
		WriteFile<<CheckPlayer2Score<<std::endl;
		WriteFile<<ThirdPlayer<<std::endl;
		WriteFile<<CheckPlayer3Score<<std::endl;
		WriteFile.close();
	
}
void ResetNovice2()
{
		FirstPlayer="Empty";
		SecondPlayer="Empty";
		ThirdPlayer="Empty";
		CheckPlayer1Score="0";
		CheckPlayer2Score="0";
		CheckPlayer3Score="0";
		std::ofstream WriteFile;
		WriteFile.open("HighScoreNovice2.txt");
		WriteFile<<FirstPlayer <<std::endl;
		WriteFile<<CheckPlayer1Score<<std::endl;
		WriteFile<<SecondPlayer<<std::endl;
		WriteFile<<CheckPlayer2Score<<std::endl;
		WriteFile<<ThirdPlayer<<std::endl;
		WriteFile<<CheckPlayer3Score<<std::endl;
		WriteFile.close();
	
}
void ResetIntermediate2()
{
		FirstPlayer="Empty";
		SecondPlayer="Empty";
		ThirdPlayer="Empty";
		CheckPlayer1Score="0";
		CheckPlayer2Score="0";
		CheckPlayer3Score="0";
		std::ofstream WriteFile;
		WriteFile.open("HighScoreIntermediate2.txt");
		WriteFile<<FirstPlayer <<std::endl;
		WriteFile<<CheckPlayer1Score<<std::endl;
		WriteFile<<SecondPlayer<<std::endl;
		WriteFile<<CheckPlayer2Score<<std::endl;
		WriteFile<<ThirdPlayer<<std::endl;
		WriteFile<<CheckPlayer3Score<<std::endl;
		WriteFile.close();
}
void ResetAdvanced2()
{
		FirstPlayer="Empty";
		SecondPlayer="Empty";
		ThirdPlayer="Empty";
		CheckPlayer1Score="0";
		CheckPlayer2Score="0";
		CheckPlayer3Score="0";
		std::ofstream WriteFile;
		WriteFile.open("HighScoreAdvanced2.txt");
		WriteFile<<FirstPlayer <<std::endl;
		WriteFile<<CheckPlayer1Score<<std::endl;
		WriteFile<<SecondPlayer<<std::endl;
		WriteFile<<CheckPlayer2Score<<std::endl;
		WriteFile<<ThirdPlayer<<std::endl;
		WriteFile<<CheckPlayer3Score<<std::endl;
		WriteFile.close();
	
}
void renderResetSelectedHighScore()
{
	g_Console.writeToBuffer(0,0,"Select what highscore you want to reset by pressing it's number",0x04);
	//g_Console.writeToBuffer(0,1,ResetSelectedHighScore, 0x04);
}