/********************************************************************
1. Write a recursive algorithm to remove elements from a linked list. 
2. Write a recursive algorithm to add elements into a linked list. 
3. Try writing the same algorithms using iteration.
Q. Do the recursive implementations or the iterative implementations 
   feel more natural?
*********************************************************************/

#include <iostream>
#include <string>

using namespace std;

struct Monster{
	int level;
	int type;
	Monster *next;
};

Monster* makeMonster(Monster *p_list);
Monster* addMonster_inOrder(Monster *p_list, Monster *p_NewMonster);
void printList(Monster *p_list);
Monster* gobomb(Monster *p_list, int bomb);
Monster* bombTheRest(Monster *p_list, int bomb);

int main(){
	srand(time(NULL));
	Monster *p_list;
	p_list = NULL;
	for(int i=0; i<10; i++){
		p_list = makeMonster(p_list);
	}
	printList(p_list);
	p_list = gobomb(p_list, 5);
	printList(p_list);
}

//***********FUNCTIONS******************************************************************************

Monster* makeMonster(Monster *p_list){
	Monster *p_monster = new Monster;
	p_monster->level = rand()%10 + 1;
	p_monster->type = rand()%4 + 1;
	if(p_list==NULL){
		p_monster->next = NULL;
		p_list = p_monster;
		cout << p_monster->level << "<- level...so I'm the first\n";
	}
	else if(p_list->level <= p_monster->level){
		p_monster->next = p_list;
		p_list = p_monster;
		cout << p_monster->level << "<- level...All monsters are inferior\n";
	}
	else{
		cout << p_monster->level << "<-level...Have to find my place\n";
		p_list = addMonster_inOrder(p_list, p_monster);
	}
	
	return p_list;
	
}
void printList(Monster *p_list){
	cout << p_list->level << "  " << p_list->type << endl;
	if(p_list->next != NULL){
		printList(p_list->next);
	}
	cout << p_list->level << "**" << p_list->type << endl;
}
		
Monster* addMonster_inOrder(Monster *p_list, Monster *p_monster){
	if(p_list->next != NULL){
		addMonster_inOrder(p_list->next, p_monster);
		cout << "hi\n";
	}
	
	if(p_list->next == NULL && p_list->level >= p_monster->level){
		p_list->next = p_monster;
		p_monster->next = NULL;
	}
	else if(p_list->level >= p_monster->level && p_list->next->level < p_monster->level){
		p_monster->next = p_list->next;
		p_list->next = p_monster;	 
	}
		
	return p_list;
}
Monster* gobomb(Monster *p_list, int bomb){
	cout << "\n***BOMB**** = " << bomb << "\n";
	//Function to bomb the rest of list
	p_list = bombTheRest(p_list, bomb);
	//Then
	//Bomb the first.
	if(p_list->level <= bomb){
		Monster* temp = p_list;
		p_list = p_list->next;
		delete temp;
	}
	return p_list;
}
Monster* bombTheRest(Monster *p_list, int bomb){
	if(p_list->next !=NULL){
		bombTheRest(p_list->next, bomb);
	}
	if(p_list->next == NULL){
		return p_list;
	}
	else if(p_list->next->level <= bomb){
		Monster* temp = p_list->next;
		p_list->next = p_list->next->next;
		delete temp;
		return p_list;
	}
	else{	 
		return p_list;
	}
}	 	 	 

