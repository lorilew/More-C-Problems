/*Write a program that checks whether a binary tree is properly balanced.*/

#include <iostream>

struct node{
	int key_value;
	node *p_left;
	node *p_right;
};



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

bool checkBalance(node *p_tree){
	if(p_tree == NULL){
		return true;
	}
	else if(p_tree->p_left == NULL && p_tree->p_right == NULL){	 
		return true;
	}
	else if(p_tree->p_left == NULL && p_tree->p_right != NULL){
		return false;
	}
	else if(p_tree->p_left != NULL && p_tree->p_right == NULL){
		return false;
	}
	else{
		// WHAT???
		bool leftbalance = checkBalance(p_tree->p_left);
		bool rightbalance = checkBalance(p_tree->p_right);
		if(!(leftbalance && rightbalance)){
			return false;
		}
		else{
			return true;
		}
	}	 
}

int main(){
	int key;
	char userinput = 'y';
	bool isBalanced;
	node *p_tree;
	p_tree = NULL;
	
	while(userinput == 'y'){
		std::cout << "\nEnter a new key to store: ";
		std::cin >> key;
		p_tree = insert(p_tree, key);
		std::cout << "\nEnter another? (y/n): ";
		std::cin >> userinput;
	}	 
	
	isBalanced = checkBalance(p_tree);
	if(isBalanced){
		std::cout << "\nIt is balanced!\n";
	}
	else{
		std::cout << "\nIt's not balanced\n";
	}
}	 

