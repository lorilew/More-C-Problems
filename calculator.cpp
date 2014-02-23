#include <iostream>

using namespace std;

double multiply(double a, double b); 
double divide(double a, double b);
double add(double a, double b);
double subtract(double a, double b);

int main(){
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
			result = multiply(a,b);
			break;
		case '/':
			result = divide(a,b);
			break;
		case '+':
			result = add(a,b);
			break;
		case '-':
			result = subtract(a,b);
			break;
		default:
			result = 0;
			cout << "\n\n    ****Invalid input****";
			break;
	}
	
	cout << "\n\n    Result = " << result << "\n\n";
	
		
}

double multiply(double a, double b){
	return a*b;
}
double divide(double a, double b){
	return a/b;
}
double add(double a, double b){
	return a+b;
}
double subtract(double a, double b){
	return a-b;
}

