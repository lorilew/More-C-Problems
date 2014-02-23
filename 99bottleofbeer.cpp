#include <iostream>

using namespace std;

int main(){
	
	//99 bottles of beer on the wall, 99 bottles of beer.
	//Take one down, pass it around, 98 bottles of beer on the wall...
	//No more bottles of beer on the wall, no more bottles of beer. 
	//Go to the store and buy some more, 99 bottles of beer on the wall.
	
	for(int i=0; i<99; i++){
		cout << 99-i << " bottles of beer on the wall, \n";
		cout << 99-i << "bottles of beer.\nTake one down, pass it around,\n";
	
	}
	
	cout << "No more bottles of beer on the wall,\nno more bottles of beer.\n";
	cout << "Go to the store and buy some more,\n99 bottles of beer on the wall.";
}
		

