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

void userName(string *p_firstname, string *p_secondname){
	cout << p_firstname << "  " << p_secondname;
	cout << "Enter first name: ";
	getline(cin, *p_firstname, '\n');
	cout << "\nEnter second name: ";
	getline(cin, *p_secondname, '\n');

	
		
}  

int main(){
	string firstname;
	string secondname;
	
	string *p_firstname = NULL;
    string *p_secondname = NULL;
	
	cout << p_firstname << "  " << p_secondname << "\n\n";

	userName(&firstname, &secondname);
	cout << "\n\n" + firstname + " " + secondname;
	
}

