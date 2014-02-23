#include<iostream>

using namespace std;

int main()
{
    enum day_t {Monday,Tuesday,Wednesday,Thrusday,Friday,Saturday};
    day_t d;

    cout<<"\n0)Monday";
    cout<<"\n1)Tuesday";
    cout<<"\n2)Wednesday";
    cout<<"\n3)Thrusday";
    cout<<"\n4)Friday";
    cout<<"\n5)Saturday";
    cout<<"\n6)Sunday\n";

    cin>>d;

    if(d==5 || d==6)
    {
        cout<<"\n\nWEEKEND !!!!";
    }
    else
    {
        cout<<"\n\nWEEKDAY !!!!!";
    }
    cin.ignore();
}

