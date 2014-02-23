/*Implement a simple map, in the form of a binary tree, 
that holds an address book; the key for the map should be a 
person’s name and the value should be the person’s email address. 
You should provide the ability to add email addresses to the map, 
remove email addresses, update email addresses, and of course find email addresses. 
You’ll also want to clean up your address book when your program shuts down. 
As a reminder, you can use any of the standard C++ comparison operators
(such as ==, < or >) to compare two strings.*/
 
#include <iostream>
#include <string>

struct node{
	std::string name;
	int value;
	node *p_left;
	node *p_right;
};

node *insert(node *p_tree, std::string newName, int newValue);
node *search(node *p_tree, std::string name);
void destroy(node *p_tree);
node *remove(node *p_tree, std::string RemoveName);
node *update(node *p_tree, std::string name, int newValue); //need to do
node *findmax(node *p_tree);
node *remove_max_node(node *p_tree, node *p_max_node);

int main(){
	std::string newName;
	std::string searchName;
	std::string removeName;
	std::string updateName;
	int newValue;
	int updateValue;
	node *p_tree;
	p_tree = NULL;
	int userinput;
	node *search_p_tree;
	search_p_tree = NULL;
	
	while(userinput != 5){
	
		std::cout << "\n1. Enter new contact.";
		std::cout << "\n2. Search a contact.";
		std::cout << "\n3. Remove a contact.";
		std::cout << "\n4. Update a contact.";
		std::cout << "\n5. Delete and Exit";
		
		std::cout << "\n\nEnter a number: ";
		std::cin >> userinput;
		
		switch(userinput){
			case 1:
				std::cin.ignore();
				std::cout << "\nEnter new Name: ";
				std::getline(std::cin, newName, '\n');
				std::cout << "\nEnter new phone number: ";
				std::cin >> newValue;
				p_tree = insert(p_tree, newName, newValue);
				break;
			case 2:
				std::cin.ignore();
				std::cout << "\nSearch name: ";
				std::getline(std::cin, searchName, '\n');
				search_p_tree = search(p_tree, searchName);
				if(search_p_tree !=NULL){
					std::cout << "\n" << search_p_tree->value;
				}
				search_p_tree = NULL;
				break;
			case 3:
				std::cin.ignore();
				std::cout << "\nDelete name: ";
				std::getline(std::cin, removeName, '\n');
				remove(p_tree, removeName);
				break;
			case 4:
				std::cin.ignore();
				std::cout << "\nUpdate name: ";
				std::getline(std::cin, updateName, '\n');
				std::cout << "\nNew number: ";
				std::cin >> updateValue;
				update(p_tree, updateName, updateValue);
				break;
			case 5:
				destroy(p_tree);
				break;
		}
	}	 
	
	delete p_tree;
	delete search_p_tree;
}

//****FUNCTIONS*****

node *insert(node *p_tree, std::string newName, int newValue){

	if(p_tree == NULL){
		node *p_new_tree = new node;
		p_new_tree->p_left = NULL;
		p_new_tree->p_right = NULL;
		p_new_tree->name = newName;
		p_new_tree->value = newValue;
		return p_new_tree;
	}
	
	if(newName[0] < p_tree->name[0]){
		p_tree->p_left = insert(p_tree->p_left, newName, newValue);
	}
	else{
		p_tree->p_right = insert(p_tree->p_right, newName, newValue);
	}
	return p_tree;

}
node *search(node *p_tree, std::string name){
	
	if(p_tree != NULL){
	
		if(name == p_tree->name){
			return p_tree;
		}
		else if(name[0] < p_tree->name[0]){
			return search(p_tree->p_left, name);
		}
		else{
				return search(p_tree->p_right, name);
		}
	}
	else{
		return NULL;
	}
	
	
}

node *remove(node *p_tree, std::string removeName){
	node *p_max_node;
	if(p_tree == NULL){
		return NULL;
	}
	if(p_tree->name == removeName){
		//if NULL
		if(p_tree->p_left == NULL){
			node *p_right_subtree = p_tree->p_right;
			delete p_tree;
			return p_right_subtree;
		}
		if(p_tree->p_right == NULL){
			node *p_left_subtree = p_tree->p_left;
			delete p_tree;
			return p_left_subtree;
		}
		p_max_node = findmax(p_tree->p_left);
		p_max_node->p_left = p_tree->p_left;
		p_max_node->p_right = p_tree->p_right;
		delete p_tree;
		return p_max_node;
	}
	else if(removeName[0] < p_tree->name[0]){
		p_tree->p_left = remove(p_tree->p_left, removeName);
	}
	else{
		p_tree->p_right = remove(p_tree->p_right, removeName);
	}
	return p_tree;
	//need to remove extra max node from tree
	remove_max_node(p_tree, p_max_node);	
}

node *findmax(node *p_tree){

	if(p_tree == NULL){
		return NULL;
	}
	//all higher nodes should be on the right
	if(p_tree->p_right == NULL){
		return p_tree;
	}
	else{
		return findmax(p_tree->p_right);
	}
}


node *remove_max_node(node *p_tree, node *p_max_node){

	if(p_tree == NULL){
		return NULL;
	}
	if(p_tree == p_max_node){
		return p_max_node->p_left;
	}
	p_tree->p_right = remove_max_node(p_tree->p_right, p_max_node);
	return p_tree;

}

void destroy(node *p_tree){
	if(p_tree != NULL){
		destroy(p_tree->p_left);
		destroy(p_tree->p_right);
		std::cout << "\nDELETING NAME: " << p_tree->name;
		delete p_tree;
	}
}

node *update(node *p_tree, std::string name, int newValue){
	if(p_tree == NULL){
		return NULL;
	}
	else if(name == p_tree->name){
		p_tree->value = newValue;
		return p_tree;
	}
	else if(name[0] < p_tree->name[0]){
		return search(p_tree->p_left, name);
	}
	else{
			return search(p_tree->p_right, name);
	}
}

