/*
1. Write a program to remove an element from a linked list; 
the remove function should take just the element to be removed. 
Is this function easy to write—and will it be fast? 
Could this be made easier or faster by adding an additional pointer to the list? 
(Hint: what if you have a pointer to the previous node? Does that help?) 

2. Write a program that adds elements to a linked list in sorted order, 
rather than at the beginning. 

3. Write a program to find an element in a linked list by name.*/

#include <iostream>
#include <string>

using namespace std;

struct PhoneBook{
	int number;
	string name;
	PhoneBook *p_next_page;
};

void updateNumber(PhoneBook *p_list){
	int new_number;
	cout << "Enter new number: ";
	cin >> new_number;
	p_list->number = new_number;
}

PhoneBook *deletePage(PhoneBook *p_list){
	PhoneBook *p_previous = new PhoneBook;
	string name;
	PhoneBook *p_start = new PhoneBook;
	p_start = p_list;
	cout << "Enter name to delete: ";
	getline(cin, name, '\n');
	
	while(p_list->name != name || p_list == NULL){
		p_previous = p_list;
		p_list = p_list->p_next_page;
	}
	
	if(p_list->name == name){
		p_previous->p_next_page = p_list->p_next_page;
		delete p_list;
		p_list = p_previous;
		delete p_previous;
	}
	p_list = p_start;
	return p_list;
}

PhoneBook *addNewPage(PhoneBook *p_list){
	PhoneBook *p_page = new PhoneBook;
	
	int new_number;
	string new_name;
	cout << "\nEnter new contact name: ";
	getline(cin, new_name, '\n');	
	cout << "\nEnter new contact number; ";
	
	while(!(cin >> new_number)){
		cout << "Hey enter a NUMBER :";
		cin >> new_number;
		cin.clear();
		cin.ignore();
	}
	p_page->number = new_number;
	p_page->name = new_name;
	//p_page->p_next_page = p_list;
	//ADD IN ALPHABETICAL ORDER ************************************************************
	PhoneBook *p_start_list = new PhoneBook;
	p_start_list = p_list;
	PhoneBook *p_temp = new PhoneBook;
	p_temp = NULL;
	
	if(p_list == NULL || p_list->name.at(0)<p_page->name.at(0)){
		p_page->p_next_page = p_list;
		p_list = p_page;
	}
	else{
		while(p_list!=NULL && p_list->name.at(0)>p_page->name.at(0)){
			p_temp = p_list;
			p_list = p_list->p_next_page;
		}
		p_page->p_next_page = p_list;
		p_temp->p_next_page = p_page;
		p_list = p_start_list;
	}
	//**************************************************************************************
	return p_list;
	delete p_page;
	delete p_start_list;
	delete p_temp;
}

void printList(PhoneBook *p_list){
	while(p_list != NULL){
		cout << "\n\n" << p_list->name << " " << p_list->number;
		p_list = p_list->p_next_page;
	}
}

int main() {
	bool running = true;
	PhoneBook *p_list;
	p_list = NULL;
	
	int option;
	
	while(running){
		cout << "\n\n\n0. Add a new contact.";
		cout << "\n1. Delete contact.";
		cout << "\n2. Print List.";
		cout << "\n3. Exit.";
		cout << "\n\nEnter a number: ";
		cin >> option;
		
		switch(option){
			case 0:
				cin.ignore();
				p_list = addNewPage(p_list);
				break;
			case 1:
				cin.ignore();
				p_list = deletePage(p_list);
				break;
			case 2:
				cin.ignore();
				printList(p_list);
				break;
			case 3:
				running = false;
				break;
		}
	}
	delete p_list;
	
	
	
}



