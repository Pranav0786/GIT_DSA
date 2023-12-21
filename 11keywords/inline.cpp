#include<iostream>
#include<bits/stdc++.h>
using namespace std;

inline int getmax( int &a , int &b )
{
    return ( a > b ) ? a : b ;
}
int main()
{
    int a = 1 ;
    int b = 3 ;

    cout << getmax( a , b ) << endl ;

    a = a+78 ;
    b++ ;
    cout << getmax( a , b ) << endl ;
    return 0;
}