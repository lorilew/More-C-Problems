/*Write a program that lets users keep track of the last
 time they talked to each of their friends.
 Users should be able to add new friends (as many as they want!) 
 and store the number of days ago that they last talked to each 
 friend. Let users update this value (but don’t let them put in 
 bogus numbers like negative values). Make it possible to
 display the list sorted by the names of the friends of by how 
 recently it was since they talked to each friend.*/

#include <iostream>
#include <string>

using namespace std;

void new_user(string **p_p_days, int num_users);
void new_friend();
void update_days();

int main(){
	string **p_p_days;
	int num_friends = 0;
	p_p_days = new string*[num_friends];
		
	for(int i=0; i<num_friends; i++){
		p_p_days[i] = new int;
	}
	
	
	

}

