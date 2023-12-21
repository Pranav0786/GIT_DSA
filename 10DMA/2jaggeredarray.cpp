#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int n ;
    cout << "enter the value of n \n" ;
    cin >> n ;

    int **arr = new int *[n] ;
    for( int i=0 ; i<n ; i++)
        int *arr = new int[i+1] ;

    cout << "enter the elements of arr\n" ;

    for( int i=0 ; i< n ; i++ )
    {
        for( int j =0 ; j<i+1 ; j++ )
            cin >> arr[i][j] ;
    }

    for( int i=0 ; i< n ; i++ )
    {
        for( int j =0 ; j<i+1 ; j++ )
            cout << arr[i][j] << " " ;
        cout << endl ;
    }

    for( int i=0 ; i<n ; i++)
        delete []arr[i] ;
    delete []arr ;

    return 0;
}