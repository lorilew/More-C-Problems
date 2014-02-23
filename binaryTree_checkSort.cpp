/*Write a program that checks if the binary tree is properly 
sorted so that all nodes to the left of a given node are less 
than the value of that node, and all nodes to the right are 
greater than the value of that node.*/
 
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

bool checkSort(node *p_tree){
	bool isSortedright=true;
	bool isSortedleft=true;
	if(p_tree == NULL){
		return true;
	}
	else if(p_tree->p_left == NULL && p_tree->p_right == NULL){
		return true;
	}
	else if(p_tree->key_value < p_tree->p_left->key_value){
		return false;
	}
	else if(p_tree->key_value > p_tree->p_right->key_value){
		return false;
	}
	else{
		if(p_tree->p_left != NULL){
			isSortedleft = checkSort(p_tree->p_left);
		}
		if(p_tree->p_right != NULL){
			isSortedright = checkSort(p_tree->p_right);
		}
		return isSortedleft && isSortedright;
	}

		
}

int main(){
	int key;
	char userinput = 'y';
	node *p_tree;
	p_tree = NULL;
	bool isSorted;
	
	while(userinput == 'y'){
		std::cout << "\nEnter a new key to store: ";
		std::cin >> key;
		p_tree = insert(p_tree, key);
		std::cout << "\nEnter another? (y/n): ";
		std::cin >> userinput;
	}	
	
	if(checkSort(p_tree)){
		std::cout << "YAY";
	}
	else{
		std::cout << "NEY!";
	}
 	
}	 

