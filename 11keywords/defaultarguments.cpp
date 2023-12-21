#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void print( int *arr , int size , int start = 0 )
{
    for( int i=start ; i<size ; i++)
        cout << arr[i] <<" ";
    cout << endl ;
}
int main()
{
    int arr[5] = {1,2,3,4,5} ;
    print(arr,5);
    print(arr,5,2);
    return 0;
}