#include<bits/stdc++.h>
using namespace std;

void insert_at_bottom(stack<int> &s , int target )
{
    if( s.empty() )
    {
        s.push( target ) ;
        return ;
    }

    int temp = s.top() ;
    s.pop() ;
    // rec call
    insert_at_bottom( s , target ) ;
    // back track
    s.push( temp ) ;
}

void reverse_stack(  stack<int> &s )
{
    // base case
    if( s.empty() )
        return ;

    int target = s.top() ;
    s.pop() ;

    reverse_stack(s) ;

    insert_at_bottom( s , target ) ;
}

int main()
{
    stack<int> s ;

    for( int i = 10 ; i< 80; i+=10 )
        s.push(i) ;

    reverse_stack( s ) ;

    while( !s.empty() )
    {
        cout << s.top() <<" " ;
        s.pop() ;
    }

    return 0;
}