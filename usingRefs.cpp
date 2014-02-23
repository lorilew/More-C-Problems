/**********************************************************************************
Write a function that prompts the user to enter his or her first name and last name, 
as two separate values. This function should return both values to the caller via
additional pointer (or reference) parameters that are passed to the function. 
Try doing this first with pointers and then with references. 
(Hint: the function signature will look similar to the swap function from earlier!)
**********************************************************************************/
 
#include <iostream>
#include <string>

using namespace std;

void userName(string& firstname, string& secondname){
	cout << "Enter first name: ";
	getline(cin, firstname, '\n');
	cout << "\nEnter second name: ";
	getline(cin, secondname, '\n');
		
}  

int main(){
	string firstname;
	string secondname;
	userName(firstname, secondname);
	cout << "\n\n" + firstname + " " + secondname;
	
}

