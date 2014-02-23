/******************************************************************************
Write a function that takes two input arguments and 
provides two separate results to the caller, 
one that is the result of multiplying the two arguments, 
the other the result of adding them. 
Since you can directly return only one value from a function, 
you’ll need the second value to be returned through a pointer or reference parameter.
*******************************************************************************/


#include <iostream>

using namespace std;

double addMultiply(double num_one, double num_two, double *sum){
*sum = num_one + num_two;
return num_one*num_two;
}

int main(){

double x = 7.2;
double y = 9.9;
double sum;

double mult = addMultiply(x, y, &sum);

cout << x << " + " << y << " = " << sum << endl;
cout << x << " * " << y << " = " << mult << endl;

}

