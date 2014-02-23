#include <iostream>

using namespace std;

int main(){
	double userinput;
	double runningSum;
	
	cout << "\n\n    Enter a number other than 0: ";
	cin >> userinput;
	runningSum = userinput;
	cout << "\n\n    The running sum is: " << runningSum;
	
	while(userinput != 0){
	
		cout << "\n\n    Enter a number to add: ";
		cin >> userinput;
		
		if(userinput ==0){
			continue;
		}
		
		runningSum += userinput;
		cout << "\n\n    The running sum is: " << runningSum;
	}

	cout << "\n\n    *You entered 0 - END*\n\n";
}

