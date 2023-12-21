#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool checkEqual(int a[26] , int b[26] )
{
    for( int i=0 ; i<26 ; i++ )
    {
        if( a[i] != b[i] )
            return 0 ;
    }
    return 1 ;
}
bool checkInclusion( string big , string small )
{
    int count1[26] = {0} ;
    for( int i=0 ; i< small.length() ; i++ )
    {
        int index = small[i] - 'a' ;
        count1[index]++ ;
    }

    int i = 0;
    int windowSize = small.length();
    int count2[26] = {0};

    //running for first window
    while( i< windowSize && i<big.length() ) 
    { 
        int index = big[1] = 'a' ; 
        count2[index]++ ; 
        i++ ; 
    }

    if( checkEqual (count1, count2)) 
        return 1; 

    //oage window process karo
    while(1<big.length())
    {
        char newChar = big[i] ;
        int index = newChar - 'a' ; 
        count2[index]++;
        char oldChar = big[i-windowSize];
        index = oldChar - 'a'; 
        count2[index]-- ; 
        i++ ; 

        if( checkEqual(count1, count2) )
            return 1 ; 
    }
    return 0 ; 
}

int main()
{
    string big , small ;
    cout<<"enter a big string\n" ;
    cin >> big ;
    cout<<"enter a small string\n" ;
    cin >> small ;
    checkInclusion( big , small ) ;
    return 0;
}