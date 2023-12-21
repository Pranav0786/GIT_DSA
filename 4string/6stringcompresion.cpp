#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int compress(vector<char> &chars)
{
    int i=0 ;
    int ansIndex = 0 ;
    int n = chars.size() ;

    while( i<n )
    {
        int j = i+1 ; 
        while( j<n && chars[i]==chars[j] )
            j++ ;
        
        chars[ansIndex++] = chars[i] ;
        int count = j-1 ;
        
        if( count>1 )
        {
            string cnt = to_string( count ) ;
            for( char ch: cnt )
                chars[ansIndex++] = ch ;
        }
        i=j ;
    }
    return ansIndex ;
}
int main()
{
    string input ;
    cout<<"enter a string\n" ;
    cin >> input ;
    vector<char> chars( input.begin() , input.end() ) ;
    cout<< compress (chars) << endl ;
    return 0;
}