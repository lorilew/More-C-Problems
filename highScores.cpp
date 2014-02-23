/*************************************************************************************
Write a program that allows a user to enter high scores of a game, 
keeping tracking of the name of the user and the score. 
Add the ability to show the highest score for each user, 
all scores for a particular user, all scores from all users, and the list of users.
**************************************************************************************/

#include <iostream>
#include <string>

using namespace std;

struct Player{
	string name;
	int score[100];
	int highScore;
	};

void printNames(int numOfPlayers, Player player[]){
	for(int i=0; i<numOfPlayers; i++){
		cout << player[i].name;
	}
}

int main(){
	Player player[100];
	int numOfPlayers = 0;
	
	printNames(numOfPlayers, player);
	
	
}

