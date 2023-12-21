#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void print( int *p )
{
    cout << p << endl ;
    cout << *p << endl ;
}
void update( int *p )
{
    p = p +1 ;
    cout << p << endl ;
    *p = *p + 1 ;
    cout << *p << endl ;
}
int main()
{
    int value = 5 ;
    int *p = &value ;

    print( p ) ;
    update( p ) ;

    cout << p << endl ;    
    return 0;
}