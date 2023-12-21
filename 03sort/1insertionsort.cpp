#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void insertionsort( int arr[] , int n )
{
    for( int i=1 ; i < n ; i++)
    {
        int temp = arr[i] ;
        int j = i-1 ; 
        while( j >= 0 )
        {
            if( arr[j] > temp )
                arr[j+1] = arr[j] ;
            else
                break;
            j-- ; 
        }

        arr[j+1] = temp ;   
    }

    for( int i=0 ; i<n ; i++ )
        cout<<arr[i]<<" " ; 
}

int main()
{
    int n;
    cout<<"enter the value of n\n";
    cin>>n ;
    int arr[n] ;
    cout<<"enter the elements\n";
    for( int i=0 ; i<n ; i++ )
        cin >> arr[i] ;
        
    insertionsort( arr, n );
    return 0;
}