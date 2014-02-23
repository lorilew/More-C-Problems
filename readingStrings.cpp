/*Write a program that allows a user to type in tabular data 
similar to a CSV file, but instead of using commas a separator, 
you should try to detect valid separators. First let the user 
type in the lines of tabular data. Then detect possible 
separator characters by looking through the input for 
non-number, non-letter, non-space characters. 
Find all of these characters that appear on every single line, 
and display the user these characters to ask which one to use. 
For example, if you see input like this:    
Alex Allain, webmaster@cprogramming.com    
John Smith, john@nowhere.com*/

#include <iostream>
#include <string>

using namespace std;

int main(){
	string input;
	string data;
	string separators;
	string sep;
	
	while(input != "0"){
		cout << "Enter new data or enter 0 to quit: \n";
		getline(cin, input, '\n');
		cin.ignore();
		if(input != "0"){
			data = data + "\n" + input;
		}
	}
	
	for(int i=0; i<data.length(); i++){
		if(!(isalnum(data[i]))){
			separators += data[i];
		}
	}
	
	cout << "\n\nWhich separator: \n";
	for(int i=0; i<separators.length(); i++){
		if(separators[i] == ' '){
			cout << i+1 << ". SPACE\n";
		}
		if(separators[i] == '\n'){
			cout << i+1 << ". NEWLINE\n";
		}
		else{
			cout << i+1 << ". " << separators[i] << "\n";
		}
	}	 	 
	cout << "\nEnter separator here: ";
	
	getline(cin, sep, '\n');
	
	

}

