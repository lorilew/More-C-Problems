/*Create an array of space ship objects and write a program that 
continually updates their positions until they all go off the screen. 
Assume that the size of the screen is 1024 pixels by 768 pixels.*/
#include <iostream>

using namespace std;

struct Spaceship{
	int x_coordinate;
	int y_coordinate;
	bool isOnScreen;
	int index;
};

Spaceship updateSpaceship(Spaceship ship){
	ship.x_coordinate += 100;
	ship.y_coordinate += 100;
	return ship;
}
	

int main(){
	srand(time(NULL));
	int const numOfShips = 10;
	Spaceship ship[numOfShips];
	
	for(int i=0; i<numOfShips; i++){
		ship[i].x_coordinate = rand() % 1024;
		ship[i].y_coordinate = rand() % 768;
		ship[i].isOnScreen = true;
		ship[i].index = i;
	}
	int numOfShipsOnScreen = numOfShips;
	cout << "\n\n\n\nNUMBER OF SHIPS ON SCREEN: " << numOfShipsOnScreen;
	while(numOfShipsOnScreen > 0){
		for(int i=0; i<numOfShips; i++){
			if(ship[i].isOnScreen == true){
				ship[i] = updateSpaceship(ship[i]);
				cout << "\n(x,y) " << ship[i].index << "  " <<  ship[i].x_coordinate << "  " << ship[i].y_coordinate;
				if(ship[i].x_coordinate > 1024 || ship[i].y_coordinate > 768){
					numOfShipsOnScreen -= 1;
					ship[i].isOnScreen = false;
					cout << "   < -- SHIP GOODBYE";
				}
			}
		}
		cout << "\n\n\n\nNUMBER OF SHIPS ON SCREEN: " << numOfShipsOnScreen;
	}
	

	

}

