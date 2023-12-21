#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string removedstring( string s , string part )
{
    while( s.length()!=0 && s.find(part) < s.length() )
        s.erase( s.find(part) , part.length() ) ;
    return s ;
}

int main()
{
    string s , part ; 
    cout<<"enter the string \n" ; 
    cin >> s ; 
    cout<<"enter the part of string to be remove\n" ; 
    cin >> part ; 
    
    cout << removedstring( s , part ) << endl ; 
    return 0;
}