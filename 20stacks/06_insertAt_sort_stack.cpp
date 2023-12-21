#include<bits/stdc++.h>
using namespace std;

void insertSorted( stack<int> &s , int target )
{
    if( s.empty() )
    {
        s.push(target) ;
        return ;
    }

    if( s.top() >= target )
    {
        s.push(target) ;
        return ; 
    }

    int temp = s.top() ;
    s.pop() ;
    
    insertSorted( s , target ) ;
    s.push(temp) ;
}

void sort_stack(stack<int> &s )
{
    if( s.empty() )
        return  ;

    int temp = s.top() ;
    s.pop() ;

    sort_stack( s ) ;
    insertSorted( s , temp ); 

}
int main()
{
    stack<int> s ;

    s.push(100) ;
    s.push(40) ;
    s.push( 90 ) ;
    s.push(20 ) ;
    s.push( 30 ) ;

    int target = 35 ;

    sort_stack( s ) ;

    while( !s.empty() )
    {
        cout << s.top() <<" " ;
        s.pop() ;
    }

    return 0;
}