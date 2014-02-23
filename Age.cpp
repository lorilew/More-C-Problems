#include <iostream>

using namespace std;

int main(){

	int age1, age2;
	
	cout << "How old are you1? ";
	cin >> age1;
	cout << "How old are you2? ";
	cin >> age2;
	
	if(age1<100 && age2<100){
		if(age1>age2){
			cout << "You1 is older!\n\n";
		}
		else if(age1<age2){
			cout << "You2 is waaay older!\n\n";
		}
		else{
			cout << "Same age?/n/n";
		}
	}
	else{
		if(age1 == 100){
			cout << "You1 is 100!!!";
		}
		else{
			cout << "You2 is 100!!!";
		}
	}
	
}
		
	
			   

