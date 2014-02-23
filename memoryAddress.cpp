/*Write a program that prints out the memory addresses of each element 
in a two-dimensional array. Check to see if the values printed out 
make sense to you based on the way I explained it before.*/

#include <iostream>

using namespace std;

int main(){
	int height = 5;
	int length = 4;
	
	int **p_p_row;
	//Create an array size of height
	p_p_row = new int*[height];
	
	//for each element in height create a row size of length
	for(int i=0; i<height; i++){
		p_p_row[i] = new int[length];
	}
	
	//print address of each element
	for(int i=0; i<height; i++){
		for(int j=0; j<length; j++){
			cout << "    " << &p_p_row[i][j];
		}
		cout << "\n";
	}
	
	//delete
	for(int i=0; i<height; i++){
		delete[] p_p_row[i];
	}
	delete p_p_row;
	//set to NULL
	p_p_row = NULL;
	//check
	cout << p_p_row;
}


