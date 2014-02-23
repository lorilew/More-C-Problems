#include <iostream>

using namespace std;

enum suit_t {HEART, DIAMOND, SPADE, CLUB};

class Card{
	public:
		int suit;
		int value;
		int index;
	
		int getSuit(){
			return suit;
		}
		int getValue(){
			return value;
		}
		int getIndex(){
			return index;
		}
		void setSuit(int integer)
		{
			if (integer<13)  	 {
				suit = HEART;
			} 
			else if (integer<26) {
				suit = DIAMOND;
			} 
			else if (integer<39) {
				suit = SPADE;
			} 
			else if (integer<52) {
				suit = CLUB;
			} 
			else {
				cout << "Error in setSuit in ClassCard";
			}
		}
		void setValue(int r){
			if (r<13) {
				value = r+1;
			} else if (r<26) {
				value = r-12;
			} else if (r<39) {
				value = r-25;
			} else if (r<52) {
				value = r-38;
			} else {
				cout << "Error in setValue in ClassCard";
			}
		}
		void setIndex(int my_int){
			index = my_int;
		}	 
		
};


			
int main(){
	std::srand(time(NULL));
	int r;
	int fulldeck_index[52];
	Card::Card hand[5];
	
	for(int i=0; i<52; i++){
		fulldeck_index[i] = i+1;
	}	 
	
	for(int i=0; i<5; i++){
		
		do { 
			r = std::rand()%52;
		}
		while(fulldeck_index[r] == 0);
		fulldeck_index[r] = 0;
		hand[i].setIndex(r);
		hand[i].setValue(r);
		hand[i].setSuit(r);
	}
	//NEED TO FIND A WAY TO MAKE A NEW CARD
	for(int i=0; i<5; i++){	
		cout << hand[i].getValue() << "   " << hand[i].getSuit() << "\n";
	}
	
}
			
				
			
			

