#include <iostream>
#include <string>

using namespace std;

int main(){
	string name;
	string name2;
	string name3;
	cout << "What's your name? ";
	getline(cin, name, '\n');
	cout << "What's your friend's name? ";
	getline(cin, name2, '\n');
	cout << "What's your other friend's name? ";
	getline(cin, name3, '\n');	       
	cout << "\nHello " << name;
	cout << "\nHello " << name2;
	cout << "\nHello " << name3;
}

