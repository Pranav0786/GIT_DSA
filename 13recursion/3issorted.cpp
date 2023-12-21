#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool sorted( int arr[] , int size )
{
    if( size==0 || size==1 ) return true ; 

    if( arr[size-1] >= arr[size-2] )
        sorted( arr , size-2 ) ; 

    else return false ;
} 

int main()
{
    int size ;
    cout << "enter size\n" ;
    cin >> size ;
    int arr[size] ;
    cout << "enter the elements of arr\n" ;

    for( int i=0 ; i<size ; i++ )
        cin >> arr[i] ;

    cout << endl << sorted( arr , size ) << endl ;
    return 0;
}