#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int sum( int *arr , int n )
{
    int sum = 0 ;
    for( int i=0 ;i < n ; i++ )
        sum += arr[i] ;
    return sum ;
}
int main()
{
    int n ;
    cout<<"enter the value of n\n" ;
    cin >> n ;

    int *arr = new int [n] ;
    cout << "enter the elements in array\n" ;

    for( int i=0 ; i< n ; i++ )
        cin >> arr[i] ;

    cout << sum( arr , n ) << endl ;

    delete []arr ;

    return 0;
}