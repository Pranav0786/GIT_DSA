#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int n ;
    cout << "enter value of n\n" ;
    cin >> n ;
    
    // create
    int **arr = new int *[n] ;
    for( int i=0 ; i<n ; i++ )
        arr[i] = new int[n] ;
    // input
    for( int i=0 ;i < n ; i++ )
    {
        for( int j= 0 ; j< n ; j++ )
            cin >> arr[i][j] ;
    }
    // print
    for( int i=0 ;i < n ; i++ )
    {
        for( int j= 0 ; j< n ; j++ )
            cout<< arr[i][j] <<" ";
        cout << endl ;
    }
    // delete
    for( int i=0 ; i<n ; i++ )
        delete []arr[i] ;
    delete []arr ;

    return 0;
}