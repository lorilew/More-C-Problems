#include <iostream>

using namespace std;

void spaghetti(){
	cout << "\n\n    It's a spaghettio!\n\n";
}
void pizza(){
	cout << "\n\n    Pizza Pizza Pizza!\n\n";
}
void cheeseBurger(){
	cout << "\n\n    Cheeeeeeese!\n\n";
}
void icecream(){
	cout << "\n\n    Brr a bit chilly for that!\n\n";
}
void fudgeCake(){
	cout << "\n\n    Stick your face init!\n\n";
}
double calculator();
void bottlesong();

int main(){
	int choice=0;
	
	while(choice == 0){
	cout << "\n\n    Menu\n\n";
	cout << "    1. Spaghetti\n";
	cout << "    2. Pizza\n";
	cout << "    3. Cheese Burger\n";
	cout << "    4. Icecream\n";
	cout << "    5. Fudge Cake\n";
	cout << "\n\n    Select a number: ";
	cin >> choice;
	
	switch(choice){
		case 1:
			spaghetti();
			break;
		case 2:
			pizza();
			break;
		case 3:
			cheeseBurger();
			break;
		case 4:
			icecream();
			cout << "\n\n";
			//calculator();
			break;
		case 5:
			fudgeCake();
			cout << "\n\n";
			//bottlesong();
			break;
		default:
			choice = 0;
			break;
		}
	}	 
}
double calculator(){
char mathsymbol;
	double a;
	double b;
	double result;
	
	cout << "\n    MY CALCULATOR\n\n";
	cout << "    * multiply\n    / divide\n    + add\n    - subtract\n\n    Enter a symbol: ";
	cin >> mathsymbol;
	
	cout << "\n\n    Enter first number: ";
	cin >> a;
	
	cout << "\n\n    Enter second number: ";
	cin >> b;
	
	switch(mathsymbol){
		case '*':
			result = a*b;
			break;
		case '/':
			result = a/b;
			break;
		case '+':
			result = a+b;
			break;
		case '-':
			result = a-b;
			break;
		default:
			result = 0;
			cout << "\n\n    ****Invalid input****";
			break;
	}
	
	cout << "\n\n    Result = " << result << "\n\n";	
}

void bottlesong(){
for(int i=0; i<99; i++){
		cout << 99-i << " bottles of beer on the wall, \n";
		cout << 99-i << "bottles of beer.\nTake one down, pass it around,\n";
	
	}
	
	cout << "No more bottles of beer on the wall,\nno more bottles of beer.\n";
	cout << "Go to the store and buy some more,\n99 bottles of beer on the wall.";
}

