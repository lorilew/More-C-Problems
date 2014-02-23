/*Write a recursive function that takes an array and displays the elements 
in reverse order without starting the index of the array at the end. 
(In other words, don’t write the equivalent of a 
loop that starts printing at the end of the array.)*/
#include <iostream>

using namespace std;

void reverseArray(int array[], int i, int size);

int main(){
	int array[] = {2,4,6,8,10};
	int length = sizeof(array)/sizeof(*array);
	reverseArray(array, 0, length);
	
}

void reverseArray(int array[], int i, int size){
	
	if(i+1<size){
		reverseArray(array, i+1, size);
	}
	cout << array[i] << endl;
	
}

