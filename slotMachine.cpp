/*Make a “slot machine” game that randomly displays the results of a slot machine to a player
—have three (or more) possible values for each wheel of the slot machine. 
Don’t worry about displaying the text “spinning” by. 
Just choose the results and display them and print out the winnings (
choose your own winning combinations).*/
 
#include <iostream> 

using namespace std;

enum symbol_t {SMILE = 1, HEART = 3, DIAMOND = 4, BOY = 11, GIRL = 12, MUSIC = 14, SPLAT = 15};

void display(int slot1, int slot2, int slot3, int winnings);
int calculateWin(int slot1, int slot2, int slot3);
int assignSym(int slot);

int main(){
	int slot1 = 0;
	int slot2 = 0;
	int slot3 = 0;
	int winnings = 12;
	srand(time(NULL));
	
	while(winnings > 0){
		winnings -=2;
		slot1 = rand() % 100;
		slot2 = rand() % 100;
		slot3 = rand() % 100;
		
		slot1 = assignSym(slot1);
		slot2 = assignSym(slot2);
		slot3 = assignSym(slot3);
		winnings += calculateWin(slot1,slot2,slot3);
		display(slot1,slot2,slot3,winnings);

		cin.ignore();
	}
}
		
void display(int slot1, int slot2, int slot3, int winnings){
	char first = slot1;
	char second = slot2;
	char third = slot3;
	cout << "\n\n\n\n\n\n\n\n";
	cout << "    CREDIT = 2\n\n";
	cout << "\n\n    *************************    ANY PAIR\t2";
	cout <<   "\n    ** LORILEWS * AWESOME ***    3 SMILES\t4";
	cout <<   "\n    *****  SLOTMACHINE ******    3 HEARTS\t8";
	cout <<   "\n    *************************    3 DIAMONDS\t10";
	cout <<   "\n                                 3 BOYS\t15"; 
	cout <<   "\n    *************************    3 GIRLS\t25";
	cout <<	  "\n    ***     **     **     ***    3 MUSIC\t50";
	cout <<   "\n    ***  " << first << "  **  " << second << "  **  " << third << "  ***";	   
	cout <<	  "\n    ***     **     **     ***   *3 SPLATS\t100*";	  
	cout <<   "\n    *************************\n\n";
	cout <<   "\n                                 CREDIT = " << winnings;
	cout << "\n\n\n\n\n";
	
}

int assignSym(int slot){
	if(slot<30){
		slot = SMILE;
	}
	else if(slot<50){
		slot = HEART;
	}
	else if(slot<60){
		slot = DIAMOND;
	}
	else if(slot<70){
		slot = BOY;
	}
	else if(slot<80){
		slot = GIRL;
	}
	else if(slot<90){
		slot = MUSIC;
	}
	else if(slot<100){
		slot = SPLAT;
	}
	return slot;

}
int calculateWin(int slot1, int slot2, int slot3){
	//TRIPLE
	int winnings;
	if(slot1 == slot2 && slot2 == slot3){
		switch(slot1){
			case 1:
			winnings = 4;
			break;
		case 3:
			winnings = 8;
			break;
		case 4:
			winnings = 10;
			break;
		case 11:
			winnings = 15;
			break;
		case 12:
			winnings = 25;
			break;
		case 14:
			winnings = 50;
			break;
		case 15:
			winnings = 100;
			break;
		default:
			cout << "ERROR IN CALCULATE WIN FUNC";
			break;
		}
	}
	else if(slot1 == slot2 || slot2 == slot3 || slot3 == slot1){
		winnings = 2;
	}
	else{
		winnings = 0;
	}
	return winnings;
}

