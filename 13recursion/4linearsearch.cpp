#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool linearsearch( int *arr , int size , int k )
{
    if( size == 0) return false ;
    if( arr[0] == k ) return true ;

    linearsearch( arr+1 , size-1 , k ) ;

    // return false ;
} 
int main()
{
    int size ;
    cout << "Enter the size\n" ;
    cin >> size ;
    int arr[size] ;
    cout << "enter arr elements\n" ;

    for( int i=0 ; i < size ; i++ )
        cin >> arr[i] ;
    int k = 5 ;
    int ans = linearsearch( arr , size , k ) ;

    if( ans ) 
        cout << "element is found\n" ;
    else
        cout << "element is not found\n" ; 
    return 0;
}