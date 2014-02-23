/*Write a program that compares the memory addresses of two different variables
on the stack and prints out the order of the variables by numerical order of their addresses. 
Does the order surprise you?*/

#include <iostream>

using namespace std;

int main(){
int numberroo =88;
int number = 5;

cout << &numberroo << endl;
cout << &number << endl;

}


