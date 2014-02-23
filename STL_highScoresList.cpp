/*Use vectors to implement a high score list for a video game. 
Make it so that scores are updated automatically, and new scores 
are added into the right place in the list. You may find the SGI 
website listed above useful for finding more operations you can do on vectors.*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void sort_scores(vector<int> *p_highscore_list, int size);

int main(){
	int highscore;
	vector<int> highscore_list;
	vector<int> *p_highscore_list;
	p_highscore_list = &highscore_list;
	
	while(true){
		cout << "\n    ***HIGH SCORES***\n"; 
		for(int i=highscore_list.size()-1; i>=0; i--){
			cout << "\n           " << highscore_list[i];
		}
		
		cout << "\n\n    Enter your new score: ";
		cin >> highscore;
		
		//Enter into vector highest first
		highscore_list.push_back(highscore);
		//need to sort list
		std::stable_sort (highscore_list.begin(), highscore_list.end());
		//remove lowest score
		if(highscore_list.size()>10){
			highscore_list.pop_back();
		}
		
	}
		
}



