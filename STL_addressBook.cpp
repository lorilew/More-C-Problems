/*Implement a small address book program that allows users to enter
names and email addresses, remove or change entries, and list the 
entries in their address book. Don’t worry about saving the address book to disk; 
it’s ok to lose the data when the program exits.*/

#include <iostream>
#include <map>
#include <string>

using namespace std;

map <string, string> add(map <string, string> name_to_email);

int main(){	
	int option = 1;
	map<string, string> name_to_email;
	string name;
	string email;
	
	while(option){
		cout << "\n\n1. Add new contact"
			 << "\n2. Search contact"
			 << "\n3. Update contact"
			 << "\n4. Remove contact"
			 << "\n5. Print all contacts"
			 << "\n0. Exit"
			 << "\n\nEnter a number: ";
		cin >> option;
		switch(option){
			case 1:
				name_to_email = add(name_to_email);
				break;
			case 2:
				cin.ignore();
				cout << "\n\nEnter name to search: ";
				getline(cin, name, '\n');
				cout << "\n" << name_to_email[name];
				break;
			case 3:
				cin.ignore();
				cout << "\n\nEnter name to update: ";
				getline(cin, name, '\n');
				cout << "\nEnter new email: ";
				getline(cin, email, '\n');
				name_to_email[name] = email;
				break;
			case 4:
				cin.ignore();
				cout << "\n\nEnter name to remove: ";
				getline(cin, name, '\n');
				name_to_email.erase(name);
				break;
			case 5:
				cout << "\n\nAddress Book\n\n";
				
				
				for(map<string, string>::iterator itr= name_to_email.begin(); 
					itr != name_to_email.end(); 
					++itr){
					cout << itr->first << "--->" << itr->second << "\n";
				}
				break;
			case 0:
				name_to_email.clear();
				break;
		}
	}
}

map <string, string> add(map <string, string> name_to_email){
	string name;
	string email;
	cin.ignore();
	
	cout << "\n\nEnter new name: ";
	getline(cin, name, '\n');
	cout << "\nEnter email address: ";
	getline(cin, email, '\n');
	
	name_to_email[name] = email;
	
	return name_to_email;
			
}



