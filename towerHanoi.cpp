//The Tower of Hanoi!

#include <iostream>

using namespace std;

enum tower_t {TOWERONE = 1, TOWERTWO = 2, TOWERTHREE = 3};

struct disc{
	int size;
	int tower;
	disc *next;
};

disc *initialize(disc *list, int height);
void print(disc *list);	
void solve(disc *current_list, disc *target_list, disc *other_list);   

int main(){
	disc *list_one;
	disc *list_two;
	disc *list_three;
	list_one = NULL;
	list_two = NULL;
	list_three = NULL;
	int height = 2;
	int counter = 0;
	int *p_counter = &counter;
	
	list_one = initialize(list_one, height);
	print(list_one);
	solve(list_one, list_two, list_three);
	

}

disc *initialize(disc *list, int height){
	if(height > 1){
	list = initialize(list, height-1);
	}
		disc *noob = new disc;
		noob->size = height;
		noob->tower = TOWERONE;
		noob->next = list;
		list=noob;
		//delete noob;
		return list;
}

void print(disc *list){
	if(list != NULL){
		
		if(list->next != NULL){
			print(list->next);
		
		}
		for(int i=0; i<list->size; i++){
			cout << "*";
		}
		cout << "\n";
	}
	else{
		cout << "-\n";
	}

}
void solve(disc *current_list, disc *target_list, disc *other_list){
	//target = 3
	//current = 1
	disc* temp;
	
	// move *  -> 2
	temp = current_list->next->next;
	current_list->next->next = other_list;
	other_list = current_list->next;
	current_list->next = temp;
	delete temp;
	// move ** -> 3
	temp = current_list->next;
	current_list->next = target_list;
	target_list = current_list;
	current_list = temp;
	delete temp;
	// move *  -> 3
	temp = other_list->next;
	other_list->next = target_list;
	target_list = other_list;
	other_list = temp;
	delete temp;
	
	print(current_list);
	print(other_list);
	print(target_list);
}

