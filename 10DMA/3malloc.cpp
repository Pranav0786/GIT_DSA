#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int n ;
    cout << "enter the value of n\n" ;
    cin >> n ;
    int *ptr = ( int *) malloc(n * sizeof(int)) ;
    for( int i=0 ; i<n ; i++ )
        ptr[i] = i*2 ;
    
    for( int i=0 ; i<n ; i++ )
        cout << ptr[i] << " " ;
    cout << endl ;

    free( ptr ) ;
    
    return 0;
}