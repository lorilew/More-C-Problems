/*Create an address book program that builds on problem #1—this time, 
the user should be able to not just fill out a single structure, 
but should be able to add new entries, each with a separate name and phone number. 
Let the user add as many entries as he or she wants—is this easy to do? 
Is it even possible? Add the ability to display all, or some of the entries, 
letting the user browse the list of entries.*/

#include <iostream>
#include <string>

using namespace std;

struct addressbook{
	string name;
	string address;
	int phonenumber;
};

int main(){
	addressbook person[100];
	bool running = true;
	int index = 0;
	char userinput;
	while(running){
		
		cout << "\n\nEnter name: ";
		getline(cin, person[index].name, '\n');
		cout << "\nEnter address: ";
		getline(cin, person[index].address, '\n');
		cout << "\nEnter phone number: ";
		cin >> person[index].phonenumber; //check integer
	
		index++;
		
		cout << "\n\nAdd another? (y/n) ";
		cin >> userinput;
		running = (userinput == 'y')? true : false;
		cin.ignore();
	}
	
	int choice;
	
	cout << "\n\nDisplay results? (Enter a number)\n\n";
	cout << "1. All.\n";
	cout << "2. Search a letter.\n";
	cout << "3. No display.\n\n";
	cin >> choice;
	
	string firstletter;
	switch(choice){
		case 1:
			for(int i=0; i<index; i++){	
				cout << person[i].name << "\n";
				cout << person[i].address << "\n";
				cout << person[i].phonenumber << "\n\n";
			}
			break;
		case 2: 
			
			cin.ignore();
			cout << "Enter a letter: ";
			getline(cin, firstletter, '\n');
			for(int i=0; i<index; i++)
			{	
				if(firstletter[0] == person[i].name[0])
				{
					cout << person[i].name << "\n";
					cout << person[i].address << "\n";
					cout << person[i].phonenumber << "\n\n";
				}
			}
			break;
		case 3:
			break;
			
	}
			
	
}

