#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string repetedpart( string s )
{
    string part = {} ;
    int a=0 ;
    for( int i=0 ; i<s.length() ; i++ )
    {
        for( int j=i+1 ; j<s.length() ; j++ )
        {
            if( s[i] == s[j] )
            {
                part.push_back( s[j] ) ;
                a = a|1 ;
            }
        }
        if( a==1 )
            part.push_back( s[i] ) ;
    }
    return part ;
}
string removeduplicate( string s )
{
    string part = repetedpart(s) ;
    cout<< part << endl ;
    while( s.length()!=0 && s.find(part) < s.length() )
        s.erase( s.find(part) , part.length() ) ;
    return s ;

}
int main()
{
    string s ;
    cout<<"enter a string\n" ;
    cin >> s ;
    cout<< removeduplicate(s) << endl ; 

    return 0;
}