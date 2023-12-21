#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Hero
{
    private:
    char health ;
    char level ;
    public:
    Hero()
    {
        cout << "constructor\n" ;
    }
};

int main()
{
    Hero h1 ;
    Hero* h2 = new Hero ;

    cout << sizeof(h1) << endl ;
    cout << sizeof(*h2) << endl ;
    return 0;
}