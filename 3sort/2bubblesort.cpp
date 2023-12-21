#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void bubblesort( int arr[] , int n )
{
    bool swapped = false ;
    for( int j=1 ;j<n ;j++ )
    {
        for( int i=0 ; i< n-i ; i++)
        {
            if( arr[i] > arr[i+1] )
            {
                swap( arr[i] , arr[i+1] ) ;
                swapped = true ;
            }
        }
        if( swapped == false)
            break ; 
    }
    cout<<"sorted arr is \n";
    for( int i=0 ; i<n ; i++ )
        cout<<arr[i]<<" ";
    cout<<endl;
}
int main()
{
    int n;
    cout<<"enter the value of n\n";
    cin>>n;
    int arr[n];
    cout<<"enter the n elements\n";
    for( int i=0 ; i<n ;i++ )
        cin >> arr[i] ; 
    bubblesort( arr , n ) ; 
    return 0;
}