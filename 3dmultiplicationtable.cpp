/*Write a function that takes three arguments, a length, width and height, 
dynamically allocates a three-dimensional array with those values and 
fills the three-dimensional array with multiplication tables. 
Make sure to free the array when you are done.*/

/***** ERROR ***** height and width and swapped******/


#include <iostream>

using namespace std;

void build_table(int ***p_p_p_row, int depth, int width, int height);
void print_table(int ***p_p_p_row, int depth, int width, int height);

int main(){
	int depth;
	int width;
	int height;
	
	cout << "Please input depth of 3d box :";
	cin >> depth;
	cout << "\nPlease input height of 3d box: ";
	cin >> width;
	cout << "\nPlease input width of 3d box: ";
	cin >> height;
	
	//declare a p-of-p-of-p to row
	int ***p_p_p_row;
	//create an array for depth
	p_p_p_row = new int**[depth];
	
	//for each element in the depth
	//create an array length of width
	for(int i=0; i<depth; i++){
		p_p_p_row[i] = new int*[width];
	}
	//for each element in the width
	//build the array upwards (height)
	for(int i=0; i<depth; i++){
		for(int j=0; j<width; j++){
			p_p_p_row[i][j] = new int[height];
		}
	}
	build_table(p_p_p_row, depth, width, height);
	print_table(p_p_p_row, depth, width, height);
	
	
	//delete 3d table
	for(int i=0; i<depth; i++){
		for(int j=0; j<width; j++){
			delete[] p_p_p_row[i][j];
		}
	}
	for(int i=0; i<depth; i++){
		delete[] p_p_p_row[i];
	}	 
	    
	delete[] p_p_p_row;
	
}

void build_table(int ***p_p_p_row, int depth, int width, int height){
	for(int i=0; i<depth; i++){
		for(int j=0; j<width; j++){
			for(int k=0; k<height; k++){
				p_p_p_row[i][j][k] = (i+1)*(j+1)*(k+1);
			}
		}
	}
}

void print_table(int ***p_p_p_row, int depth, int width, int height){
	for(int i=0; i<depth; i++){
		cout << "\n\nslice of 3d table " << i+1 << "\n\n";
		for(int j=0; j<width; j++){
			for(int k=0; k<height; k++){
				cout << " " << p_p_p_row[i][j][k] << " ";
			}
		cout << endl;	 
		}	 
	}
}

