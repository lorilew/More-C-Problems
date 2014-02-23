#include <iostream>

using namespace std;

int main(){
	int x = 0;
	while(x<12){
	
		cout << "    On the First day of Christmas my true love sent to me\n";
		
		switch(x){
			
			case 11:
				cout << "    12 Drummers Drumming\n";
			case 10:
				cout << "    11 Pipers Piping\n";
			case 9:
				cout << "    10 Lords-a-Leaping\n";
			case 8:
				cout << "    9 Ladies Dancing\n";
			case 7:
				cout << "    8 Maids-a-Milking\n";
			case 6:
				cout << "    7 Swans-a-Swimming\n";
			case 5:
				cout << "    6 Geese-a-Laying\n";
			case 4:
				cout << "    5 Gold Rings\n";
			case 3:
				cout << "    4 Calling Birds\n";
			case 2:
				cout << "    Three French Hens\n";
			case 1:
				cout << "    Two Turtle Doves\n    and ";
			case 0:
				cout << "a Partridge in a Pear Tree\n\n\n";
				cin.ignore();
				break;
			default:
				cout << "Error in switch";
				break;
		}
		x++;
	}
}

