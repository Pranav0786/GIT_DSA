#include<bits/stdc++.h>
using namespace std;

void solve(stack<int> &s , int target )
{
    if( s.empty() )
    {
        s.push( target ) ;
        return ;
    }

    int temp = s.top() ;
    s.pop() ;
    // rec call
    solve( s , target ) ;
    // back track
    s.push( temp ) ;
}
void insert_top_at_bottom( stack<int> &s )
{
    if( s.empty() )
    {
        cout << "stack is empty\n" ;
        return ;
    }

    int target = s.top() ;
    s.pop() ;
    solve( s, target ) ;
    
}
int main()
{
    stack<int> s ;

    for( int i = 10 ; i< 80; i+=10 )
        s.push(i) ;

    insert_top_at_bottom( s ) ;

    while( !s.empty() )
    {
        cout << s.top() <<" " ;
        s.pop() ;
    }
    
    return 0;
}