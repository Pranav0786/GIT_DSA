#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void reversestring( string &s , int i , int j )
{
    if( i>=j ) return ;
    swap( s[i] , s[j] ) ;
    reversestring( s , ++i , --j ) ;
}
int main()
{
    cout << "enter a string\n" ;
    string s ;
    cin >> s ; 
    cout << endl ; 
    cout << s << endl ;
    reversestring( s , 0 , s.length()-1 )  ;
    cout << s << endl ;
    return 0;
}