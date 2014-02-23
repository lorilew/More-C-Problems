#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	
	int userinput;
	string username;
	cout << "\n\n    Enter your username: ";
	getline(cin, username, '\n');
	cout << "\n\n    Enter your password: ";
	cin >> userinput;
	
	if(username == "Jenny" && userinput == 55555){
		cout << "\n\n    Welcome Jenny!\n\n";
	}

	else if(username == "Lauren" && userinput == 88888){
		cout << "\n\n    Welcome Lauren!\n\n";
	}

	else if(username == "Nick" && userinput == 11111){
		cout << "\n\n    Welcome Nick!\n\n";
	}
	else{
		cout  << "\n\n    Invalid password\n\n";
	}	     	   	   
		
	

}

