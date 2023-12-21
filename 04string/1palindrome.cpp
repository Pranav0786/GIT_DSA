#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool valide( char ch )
{
    if( ( ch>='a' && ch<='z' ) || ( ch>='A' && ch<='Z' ) || ( ch>='0' && ch<='9' ) )
        return 1 ; 
    return 0 ;
} 
char lower( char ch )
{
    if( ( ch>='a' && ch<='z' ) || ( ch>='0' && ch<='9' ) )
        return ch ;
    return ch-'A'+'a' ;
}
bool palindrome( string s )
{
    string temp = "" ;
    for( int i=0 ; i<s.length() ; i++ )
    {
        if( valide( s[i] ) )
            temp.push_back( s[i] ) ;
    }
    
    for( int i=0 ; i<s.length() ; i++ )
     lower( temp[i] ) ;
    
    int left = 0 , right = temp.length()-1 ;
    for( ; left <= right ; left++ , right-- )
    {
        if( temp[left] != temp[right] )
            return 0 ;
        return 1 ;
    }
    return 0 ;
}
int main()
{
    string s;
    cout<<"enter a string\n";
    cin >> s ;
    cout<<"string is palindrome or not "<<palindrome(s)<<endl ;
    return 0;
}