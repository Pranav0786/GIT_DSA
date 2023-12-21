#include<iostream> 
#include<bits/stdc++.h> 
using namespace std ; 

int main()
{
    char *ptr = (char *) calloc( 5 , sizeof(char)) ; 

    cout << "enter the 5 chars\n" ; 
    for( int i=0 ; i< 5 ; i++ )
        cin >> ptr[i] ; 

    for( int i=0 ; i< 5 ; i++ )
        cout << ptr[i] <<" " ; 
    cout << endl ; 
    
    free( ptr ) ; 
    return 0 ; 

}