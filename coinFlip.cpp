#include <iostream>

using namespace std;

enum coin_t {TAIL = 0, HEAD = 1};

int main(){
	coin_t coin;
	int r;
	srand(time(NULL));
	r = rand()%2;
	
	if(r==0){
		coin = HEAD;
	}
	else{
		coin = TAIL;
	}
	
	cout << coin << endl;
}

