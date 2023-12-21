#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void say( int n , unordered_map< int , string > &mp)
{
    if( n==0 ) return  ;
    int r = n%10 ;
    n = n/10 ;
    say( n , mp ) ;
    cout << mp[r] << " " ;
}
int main()
{
    unordered_map< int , string > mp = {
        {0,"zero"},
        {1,"one"},
        {2,"two"},
        {3,"three"},
        {4,"four"},
        {5,"five"},
        {6,"six"},
        {7,"seven"},
        {8,"eight"},
        {9,"nine"},
    } ;

    int n ; 
    cout << "enter a num\n" ;
    cin >> n ;
    say( n , mp ) ;
    cout << endl << endl << endl ;
    return 0;
}