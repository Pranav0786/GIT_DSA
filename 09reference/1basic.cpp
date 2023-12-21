#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int i = 9 ; 
    int &j = i ;

    cout << i++ << endl ;
    cout << j++ << endl ;
    cout << ++i << endl ;
    cout << ++j << endl ;
    return 0;
}