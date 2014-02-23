/*Write a program that provides the option of tallying
 up the results of a poll with 3 possible values. 
 The first input to the program is the poll question; 
 the next three inputs are the possible answers. 
 The first answer is indicated by 1, the second by 2, the third by 3. 
 The answers are tallied until a 0 is entered. 
 The program should then show the results of the poll—
 try making a bar graph that shows the results properly scaled 
 to fit on your screen no matter how many results were entered.*/

#include <iostream>
#include <string>

using namespace std;

int main(){

	string pollQuestion;
	string answer1;
	string answer2;
	string answer3;
	string userinput;
	int tally1=0, tally2=0, tally3=0;
	
	//User write question
	cout << "\n\n    Poll Question: ";
	getline(cin, pollQuestion, '\n');
	
	//User defines options
	cout << "\n\n    Answer 1: ";
	getline(cin, answer1, '\n');
	cout << "\n\n    Answer 2: ";
	getline(cin, answer2, '\n');
	cout << "\n\n    Answer 3: ";
	getline(cin, answer3, '\n');
	
	//Output all the screen
	cout << "\n\n    Question: " << pollQuestion;
	cout << "\n\n    1: " << answer1;
	cout << "\n    2. " << answer2;
	cout << "\n    3. " << answer3;
	
	cout << "\n\n    Enter Answers, enter 0 when finished: \n";
	
	while(userinput != "0"){
		getline(cin, userinput, '\n');
		if(userinput == answer1){
			tally1++;
		}
		else if(userinput == answer2){
			tally2++;
		}
		else if(userinput == answer3){
			tally3++;
		}
		else if(userinput == "0"){
			continue;
		}
		else{
			cout << "^^^^^INVALID\n";
		}
	
	}
	//Out put tally results
	cout << "\n\n   Tally 1: " << tally1;
	cout << "\n   Tally 2: " << tally2;
	cout << "\n   Tally 3: " << tally3 << "\n\n";
	
	//Horizontal bar chart
	cout << "\n\n\t" << answer1 << "    ";
	for(int x=0; x<tally1; x++){
		cout << "*";
	}
		cout << "\n\t" << answer2 << "    ";
	for(int x=0; x<tally2; x++){
		cout << "*";
	}
		cout << "\n\t" << answer3 << "    ";
	for(int x=0; x<tally3; x++){
		cout << "*";
	}
	cout << "\n\n";
	
	//Vertical bar chart;
	int tallyLong;
	if(tally1 >= tally2 && tally1 >= tally3){
		tallyLong = tally1;
	}
	if(tally2 >= tally3 && tally2 >= tally1){
		tallyLong = tally2;
	}
	else{
		tallyLong = tally3;
	}
	
	for(int i=0; i<tallyLong; i++){
		if(tally1 >= tallyLong-i){
			cout << "    *    ";
		}
		else{
			cout << "         ";
		}
		
		if(tally2 >= tallyLong-i){
			cout << "*    ";
		}
		else{
			cout << "     ";
		}	
		if(tally3 >= tallyLong-i){
			cout << "*";
		}
		else{
			cout << "";
		}	      
		cout << "\n";
	}
	cout << "    1    2    3\n\n";
	
}	       

