#include <iostream>
#include <string>

using namespace std;

bool checkpassword(int userinput, int t);

int main(){
	int userinput;
	int t=0; //tries
	bool password = false;
	
	
	while(t<3 && password == false){
		
		cout << "\n\n    Enter the five digit password: ";
		cin >> userinput;
		password = checkpassword(userinput,t);
		t++;
	}
}

bool checkpassword(int userinput, int t){
	if(userinput == 88888 || userinput == 12345){
		cout << "\n\n    Welcome!\n\n";
		return true;
	}
	else{
		cout << "\n\n    Invalid Password!\n\n";
		t++;
		cout << "\n\n    Number of tries: " << t << "\n\n";
		return false;
	}
}

