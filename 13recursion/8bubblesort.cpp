#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void bubble( int *arr , int size )
{
    if( size==0 || size==1 ) return ;

    for( int i=0 ; i<size-1 ; i++ )
    {
        if( arr[i] > arr[i+1] ) 
            swap( arr[i] , arr[i+1] ) ;
    }

    bubble( arr , size-1 ) ;
} 
int main()
{
    cout << "enter size of array\n" ;
    int size ;
    cin >> size ;
    int arr[size] ;
    cout<<"enter the elements\n" ;
    for( int i=0 ; i<size ; i++ )
        cin >> arr[i] ;
    
    bubble( arr , size ) ;

    for( int i=0 ; i<size ; i++ )
        cout << arr[i] << " " ;
    cout << endl ;
    return 0;
}