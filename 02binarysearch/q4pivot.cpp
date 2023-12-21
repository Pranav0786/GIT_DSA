#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int pivot(int arr[],int size)
{
    int s=0, e= size-1;
    int mid = s/2 + e/2 ;
    while(s<=e)
    {
        if( arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1] )
            return arr[mid];
        else if( arr[mid] < arr[mid+1] )
            s = mid ;
        else if( arr[mid] < arr[mid-1] )
            e = mid ;
        
        mid = s/2 + e/2;
    }
    return 0;
} 
int main()
{
    int arr[8]={2,4,6,29,20,15,14,1};
    cout<<"pick element is "<<pivot(arr,8)<<endl;
    return 0;
}