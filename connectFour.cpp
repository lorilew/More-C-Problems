/*Write a two-player game of Connect Four where the user can 
set the width and height of the board and each player gets a 
turn to drop a token into the slot. Display the board using 
+ for one side, x for the other, and _ to indicate blank spaces.*/

#include <iostream>

using namespace std;

void intialize_board(int height, int width, char **p_p_board);
void print_board(int height, int width, char**p_p_board);
void update_board(char **p_p_board, int *p_player, int height);

int main(){
	int width=7;
	int height=5;
	char **p_p_board;
	int player = 1;
	int *p_player = &player;
	bool running = 1;
	
	cout << "\nWidth of board: ";
	cin >> width;
	cout << "\nHeight of board: ";
	cin >> height; 
	
	//point to an array with size height
	p_p_board = new char*[height];
	
	//point each element of height to a an array size of width
	for(int i=0; i<height; i++){
		p_p_board[i] = new char[width];
	}
	//Display initial board to player
	intialize_board(height,width,p_p_board);
	print_board(height,width,p_p_board);
	
	//PLAY
	while(running){
		
		update_board(p_p_board, p_player, height);
		print_board(height,width,p_p_board);
		
	}
	
}



//*************FUNCTIONS******************************************



void intialize_board(int height, int width, char**p_p_board){
	for(int i=0; i<height; i++){
		for(int j=0; j<width; j++){
			p_p_board[i][j] = '_';
		}
	}
}
void print_board(int height, int width, char**p_p_board){
	cout << "\n\n";
	for(int j=0; j<width; j++)
		cout << " " << j << " ";
	
	for(int i=0; i<height; i++){
		cout << "\n";
		for(int j=0; j<width; j++){
			cout << " " << p_p_board[i][j] << " ";
		}	 
	}
}	    
	
void update_board(char **p_p_board, int *p_player, int height){
	int choice;
	bool running = true;
	
	while(running){
		cout << "\n\nChoose a column: ";
		cin >> choice;
	
		for(int i=height; i>0; i--){
			if(p_p_board[i-1][choice] == '_'){
				p_p_board[i-1][choice] = (*p_player == 1) ? '*': '+';
				running = false;
			}
			if(!running)
				break;
		}
	}
	*p_player = (*p_player == 1)? 2:1;	  	  	  
}	 

