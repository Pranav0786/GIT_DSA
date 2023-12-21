#include<bits/stdc++.h>
using namespace std;
 
void printmiddle( stack<int> &s , int total_size )
{
    if( s.size() == total_size/2 +1 )
    {
        cout << "Middle element is: " << s.top() << endl ;
        return  ;
    }

    int temp = s.top() ;
    s.pop() ;

    printmiddle( s , total_size ) ;
    s.push(temp) ;
}

int main()
{
    stack<int> s ;
    
    for( int i = 10 ; i < 80 ; i+= 10 )
        s.push( i ) ;

    int total_size = s.size() ;
    printmiddle( s , total_size ) ;

    return 0;
}