#include <iostream>
#include <vector>
using namespace std;
enum suit_t {HEART, DIAMOND, SPADE, CLUB};

vector <int> dealhand();
vector <int> assign_value(vector <int> hand);
vector <int> assign_suit(vector <int> hand);
bool checkwin(vector <int> hand_value, vector <int> hand_suit);

int main()
{
	vector <int> hand_prelim;
	vector <int> hand_suit;
	vector <int> hand_value;
	
	hand_prelim = dealhand();//return hand vector;
	hand_suit = assign_suit(hand_prelim);
	hand_value = assign_value(hand_prelim);
	
	int size = hand_suit.size();
	for(int i=0; i<size; i++){
		cout << hand_suit.at(i) << "   " << hand_value.at(i) << "\n";
	}

}

vector <int> dealhand(){
	int r;
	srand(time(NULL));
	vector <int> deck;
	vector <int> hand;
	
	//RESET PACK
	for (int i=0; i<52; i++) {
		deck.push_back(i+1);
	}
	
	//CHOOSE 5 CARDS
	for (int i=0; i<5; i++) {
		do {
			r = rand()%52;
		} while (deck.at(r) == 0);
		//IF USED ASSIGN VALUE 0
		deck.at(r) = 0;
		//FILL HAND
		hand.push_back(r);
	}
	return hand;	
}


vector <int> assign_suit(vector <int> hand){
		vector <int> hand_suit;
		int size = hand.size();
		for(int i=0; i<size; i++){
			int r = hand.at(i);
			//GIVE CARD CHOSEN SUIT AND VALUE
			if (r<13) {
				hand_suit.push_back(HEART);
			} else if (r<26) {
				hand_suit.push_back(DIAMOND);
			} else if (r<39) {
				hand_suit.push_back(SPADE);
			} else if (r<52) {
				hand_suit.push_back(CLUB);
			} else {
				cout << "Error in assigning values in hand";
			}
		}
		return hand_suit; 	    
}
vector <int> assign_value(vector <int> hand){
		vector <int> hand_value;
		int size = hand.size();
		for(int i=0; i<size; i++){
			int r = hand.at(i);
			//GIVE CARD CHOSEN SUIT AND VALUE
			if (r<13) {
				hand_value.push_back(r+1);
			} else if (r<26) {
				hand_value.push_back(r-12);
			} else if (r<39) {
				hand_value.push_back(r-25);
			} else if (r<52) {
				hand_value.push_back(r-38);
			} else {
				cout << "Error in assigning values in hand";
			}
		}
		return hand_value; 	     


}

bool checkwin(vector <int> hand_value, vector <int> hand_suit){}

int royalflush(vector <int> hand_value, vector <int> hand_suit){
	
	//CHECK ALL SAME SUIT
	int suit = hand_suit.at(0);
	int size = hand_suit.size();
	bool samesuit;
	
	for(int i=0; i<size; i++){
		if(hand_suit.at(i)!=suit){
			samesuit = false;
			break;
		}
	}
	
	//CHECK FOR ROYAL FLUSH AKQJ10
	int sum=0;
	if(!(samesuit)){
		return false;
	}
	else{
		for(int i=0; i<size; i++){
			sum += hand_value.at(i);
		}
		if(sum == 47){
			return true;
		}
	}

}

