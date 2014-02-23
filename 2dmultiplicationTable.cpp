/*Write a function that builds a two-dimensional multiplication
table with arbitrary sizes for the two dimensions.*/

#include <iostream>

using namespace std;

void build_table(int **p_p_row, int num_of_rows);
void print_table(int **p_p_row, int num_of_rows);

int main(){
	int num_of_rows=0;
	
	cout << "How many rows?";
	cin >> num_of_rows;
	
	//declaring pointer of pointer
	int **p_p_row;
	//assigning p-of-p to point at a pointer array
	p_p_row = new int*[num_of_rows];
	//assigning each element in the pointer to an int array
	for(int i=0; i<num_of_rows; i++){
		p_p_row[i] = new int[num_of_rows];
	}
	//putting the value 0 into each element of each row
	for(int i=0; i<num_of_rows; i++){
		for(int j=0; j<num_of_rows; j++){
			p_p_row[i][j]=0;
		}
	}
	print_table(p_p_row, num_of_rows);
	build_table(p_p_row, num_of_rows);
	print_table(p_p_row, num_of_rows);
	
	//delete table
	for(int i=0; i<num_of_rows; i++){
		delete[] p_p_row[i];
	}
	delete[] p_p_row;
	
}
void build_table(int **p_p_row, int num_of_rows){
	for(int i=0; i<num_of_rows; i++){
		for(int j=0; j<num_of_rows; j++){
			p_p_row[i][j] = i*j;
			}
		}
}
void print_table(int **p_p_row, int num_of_rows){
	//display table to screen
	cout << "\n\n";
	for(int i=0; i<num_of_rows; i++){
		for(int j=0; j<num_of_rows; j++){
			cout << "\t" << p_p_row[i][j];
		}
		cout << endl;
	}	 
	cout << "\n\n";
}


