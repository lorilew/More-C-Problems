/*Write a program to display the contents of a binary tree. 
Can you write a program that prints the nodes in a binary tree 
in sorted order? What about in reverse sorted order?*/

#include <iostream>

struct node{
	int key_value;
	node *p_left;
	node *p_right;
};

node *insert(node *p_tree, int key);

node *insert(node *p_tree, int key){

	if(p_tree == NULL){
		node *p_new_tree = new node;
		p_new_tree->p_left = NULL;
		p_new_tree->p_right = NULL;
		p_new_tree->key_value = key;
		return p_new_tree;
	}
	
	if(key<p_tree->key_value){
		p_tree->p_left = insert(p_tree->p_left, key);
	}
	else{
		p_tree->p_right = insert(p_tree->p_right, key);
	}
	return p_tree;

}

void printInOrder(node *p_tree){
	if(p_tree->p_left == NULL){
		std::cout << p_tree->key_value << "\n";
	}
	else{
		printInOrder(p_tree->p_left);
		std::cout << p_tree->key_value << "\n";
		
	}
	if(p_tree->p_right != NULL){
			printInOrder(p_tree->p_right);
	}
	
	
}

int main(){
	int key;
	char userinput = 'y';
	node *p_tree;
	p_tree = NULL;
	
	while(userinput == 'y'){
		std::cout << "\nEnter a new key to store: ";
		std::cin >> key;
		p_tree = insert(p_tree, key);
		std::cout << "\nEnter another? (y/n): ";
		std::cin >> userinput;
	}	 
 	
	printInOrder(p_tree);
}	 

