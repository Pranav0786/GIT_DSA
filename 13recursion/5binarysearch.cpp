#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool binarysearch( int *arr , int s , int e , int k )
{
    if( s>e ) return false ;

    while( s<e )
    {
        int mid = s/2 + e/2 ;

        if( arr[mid] == k )
            return true ;
        else if( arr[mid] < k )
            binarysearch( arr , mid+1 , e , k ) ;
        else
            binarysearch( arr , s , mid-1 , k ) ;
    }
    
}
int main()
{
    int s = 0 ;
    int e = 10 ;
    int arr[10] = { 2,3,4,5,6,8,9,10,34,89} ;
    int k = 5 ;
    int index = binarysearch( arr , s , e , k ) ;

    cout << index << endl; 
    return 0;
}