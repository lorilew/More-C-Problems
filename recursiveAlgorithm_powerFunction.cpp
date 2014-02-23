/*Write a recursive algorithm to compute the power function pow(x, y) = x^y */

#include <iostream>

using namespace std;

int power(int base, unsigned exp);

int main()
{
    int base, result;
    unsigned exp;

    // Non-numeric entity ends the program
    cout << "Enter base and exponent: ";
    while (cin >> base >> exp)
    {                      
        cout << power(base, exp);
		break;
    }
}

int power(int base, unsigned exp)
{  
    if(exp >= 1) {       
        int value = power(base, exp-1);
        return base * value;
    }
    else {
        return 1; //When exp = 0 it return 1
    }
}

