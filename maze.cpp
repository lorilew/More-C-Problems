/*Write a program that takes a width and a height and 
dynamically generates a maze with the given width and height. 
The maze must always have a valid path through it 
(how can you ensure this?). 
Print the maze to the screen once it’s been generated.*/

#include <iostream>

using namespace std;

void inializeBox(int ***p_p_box, int MAX);

int main(){
	srand(time(NULL));
	int MAX;
	cout << "Enter size of maze: ";
	cin >> MAX;
	
	//declare arrays of box and pointer
	int ***p_p_box;
	p_p_box = new int**[MAX];
	for(int i=0; i<MAX; i++){
		p_p_box[i] = new int*[MAX];
	}
	for(int i=0; i<MAX; i++){
		for(int j=0; j<MAX; j++){
			p_p_box[i][j] = new int[4];
		}
	}
	
	inializeBox(p_p_box, MAX);
	
}

//***********FUNCTIONS***************************************

void inializeBox(int ***p_p_box, int MAX){
	for(int i=0; i<MAX; i++){
		for(int j=0; j<MAX; j++){
			for(int k=0; k<4; k++){
				p_p_box[i][j][k] = 0;
			}
		}
	}
}

void findRoute(int MAX){
	int r = rand()%4 + 1;
	int valid= false;
	int i=0, j=0;
	int temp_i; temp_j;
	while(!(valid)){
		int r = rand()%4 + 1;
		switch(r){
			case 1:
				//NORTH
				if((i-1 >= 0) && (p_p_box[i-1][j] == 0)){
					valid = true;
				}	 
			case 2:
				//EAST
				if((j+1 <MAX) && (p_p_box[i][j+1] == 0)){
					valid = true;
				}	 
			case 3:
				//SOUTH
			case 4:
				//WEST
		}
		p_p_box[i][j] = r;
		i= temp_i;
		j= temp_j;
		i=i-1;
	}
}	 


