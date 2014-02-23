#include <iostream>
#include <string>

using namespace std;

struct addressbook{
	string name;
	string address;
	int phonenumber;
};

int main(){
	addressbook person;
	cout << "Enter name: ";
	getline(cin, person.name, '\n');
	cout << "\nEnter address";
	getline(cin, person.address, '\n');
	cout << "\nEnter phone number: ";
	cin >> person.phonenumber;
	
	cout << "\n\n" << person.name;
	cout << "\n" << person.address;
	cout << "\n" << person.phonenumber;
}

