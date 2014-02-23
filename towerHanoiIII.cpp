#include <iostream>

using namespace std;

struct disc{
	int size;
	disc *next;
};

disc *newgame(disc *tower, int height);
void printTower(disc *tower);
disc *movedisc(disc *original, disc *other, disc *target);

int main(){
	int height = 2;
	disc* towerone;
	disc* towertwo;
	disc* towerthree;
	
	towerone = NULL;
	towertwo = NULL;
	towerthree = NULL;
	
	towerone = newgame(towerone, height);
	
	printTower(towerone);
	cout << endl;
	printTower(towertwo);
	cout << endl;
	printTower(towerthree);
	cout << endl;
	
	movedisc(towerone, towertwo, towerthree);
	
	
}


disc *newgame(disc *tower, int height){
	if(height>0){
		tower = newgame(tower, height-1);
		disc * newdisc = new disc;
		newdisc->size = height;
		newdisc->next = tower;
		tower = newdisc;
	}
	return tower;	 	 
}

void printTower(disc *tower){
	if(tower == NULL){
		cout << "-";
	}
	else if (tower->next != NULL){
		printTower(tower->next);
	
		cout << tower->size << " ";
	}
	else{
		cout << tower->size << " ";
	}
	
}
disc *movedisc(disc *original, disc *other, disc *target){
	if(original->next == NULL){
		original->next = target;
		target = original;
		original = NULL;
	}
	else{
		movedisc(original->next, target, other);
	}
		
	cout << "\n***\n";
		printTower(original);
		cout << "\n***\n";
		printTower(other);
		cout << "\n***\n";	     	 	 
		printTower(target);
		cout << "\n***\n";	     
	
}



/*		cout << "\n***\n";
		printTower(current);
		cout << "\n***\n";
		printTower(target);
		cout << "\n***\n";*/
		
/*FUNCTION MoveTower(disk, source, dest, spare):
IF disk == 0, THEN:
    move disk from source to dest
ELSE:
    MoveTower(disk - 1, source, spare, dest)   // Step 1 above
    move disk from source to dest              // Step 2 above
    MoveTower(disk - 1, spare, dest, source)   // Step 3 above
END IF*/

