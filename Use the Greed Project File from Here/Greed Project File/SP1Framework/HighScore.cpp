#include<iostream>
#include<string>
#include<sstream>
#include <fstream>
#include <iomanip>
#include "HighScore.h"
#include "game.h"
using std::string;
int ChangeScore;
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
COORD c;
int FirstPlayerScore;
int SecondPlayerScore;
int ThirdPlayerScore;
int ChangeFirst;
int ChangeSecond;
int ChangeThird;
int checkcounter=0;
extern Console g_Console;
extern int total1;
extern int total2;
void write();
void print();
void check(int &total1,int &total2);
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
	COORD c = g_Console.getConsoleSize();

  g_Console.writeToBuffer(0,fieldSize.Y-2,"Input Your name", 0x04);
	

}
void check(int &total1,int &total2)
{

	if(checkcounter==0)
	{
		if(total2>total1)
		{
			total1=total2;
		}
	checkcounter++;
	std::cin>>PlayerName;
	//std::cin>>total;
	ChangeScore=total1;
	
	std::ifstream ReadFile;
	ReadFile.open("HighScore.txt");
		std::getline(ReadFile,FirstPlayer,'\n');
		std::getline(ReadFile,CheckPlayer1Score,'\n');
		std::getline(ReadFile,SecondPlayer,'\n');
		std::getline(ReadFile,CheckPlayer2Score,'\n');
		std::getline(ReadFile,ThirdPlayer,'\n');
		std::getline(ReadFile,CheckPlayer3Score,'\n');
		//if(CheckPlayer1Score==""|| CheckPlayer1Score=="0")//Check if Player 1 is empty
		//{
		//	
		//	CheckPlayer1Score="0";
		//	FirstPlayer="empty";
		//}
		//if(CheckPlayer2Score==""|| CheckPlayer2Score=="0")//Check if Player 2is empty
		//{
		//	CheckPlayer2Score="0";
		//	SecondPlayer="empty";
		//}
		//if(CheckPlayer3Score==""||CheckPlayer3Score=="0")//Check if Player 3 is empty
		//{
		//	CheckPlayer3Score="0";
		//	ThirdPlayer="empty";
		//}
		//
		//std::cout<<name1 <<"\n"<< name2;
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
	}
		
	
	
}
void write()
{
	
	std::ofstream WriteFile;
	WriteFile.open("HighScore.txt");
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

		std::ifstream ReadFile;
		ReadFile.open("HighScore.txt");
		std::getline(ReadFile,FirstPlayer,'\n');
		std::getline(ReadFile,CheckPlayer1Score,'\n');
		std::getline(ReadFile,SecondPlayer,'\n');
		std::getline(ReadFile,CheckPlayer2Score,'\n');
		std::getline(ReadFile,ThirdPlayer,'\n');
		std::getline(ReadFile,CheckPlayer3Score,'\n');
		g_Console.writeToBuffer(fieldSize.X,fieldSize.Y,FirstPlayer);
		g_Console.writeToBuffer(fieldSize.X+FirstPlayer.length(),fieldSize.Y," : ");
		g_Console.writeToBuffer(fieldSize.X+2+FirstPlayer.length(),fieldSize.Y,CheckPlayer1Score);
		g_Console.writeToBuffer(fieldSize.X,fieldSize.Y+1,SecondPlayer);
		g_Console.writeToBuffer(fieldSize.X+SecondPlayer.length(),fieldSize.Y+1," : ");
		g_Console.writeToBuffer(fieldSize.X+2+SecondPlayer.length(),fieldSize.Y+1,CheckPlayer2Score);
		g_Console.writeToBuffer(fieldSize.X,fieldSize.Y+2,ThirdPlayer);
		g_Console.writeToBuffer(fieldSize.X+ThirdPlayer.length(),fieldSize.Y+2," : ");
		g_Console.writeToBuffer(fieldSize.X+2+ThirdPlayer.length(),fieldSize.Y+2,CheckPlayer3Score);
		ReadFile.close();
 
}