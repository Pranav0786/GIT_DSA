#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    // int arr[5] = {100,200,300,400,500} ;
    // cout<< arr << endl ;
    // cout<< &arr[0] << endl ;
    // cout<< &arr[1] << endl ;
    // cout<< *arr << endl ;
    // cout<< *arr+1 << endl ;
    // cout<< *(arr+1) << endl ;

/*
    cout<< arr[2] << endl ;
    cout<< *(arr+2) << endl ;
    cout<< 2[arr] << endl ;
*/

    int arr[5] = {1,2,3,4,5} ;
    char ch[6] = "abcde" ;
    
    cout << arr << endl ;
    cout << ch << endl ;

    char *c = &ch[0] ; 
    cout << c << endl ;

    return 0;
}