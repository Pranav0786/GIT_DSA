#include<bits/stdc++.h>
using namespace std;

void reverse_q_using_stack( queue<int> &q )
{
    stack<int> s ;

    while( !q.empty() )
    {
        int top = q.front() ;
        s.push(top) ;
        q.pop() ;
    }

    while( !s.empty() )
    {
        int top = s.top() ;
        q.push( top ) ;
        s.pop() ;
    }
}

void reverse_q_using_recursion( queue<int> &q )
{
    if( q.empty() ) 
        return ;

    int top = q.front() ;
    q.pop() ;
    
    reverse_q_using_recursion( q ) ;

    q.push( top ) ;

}
int main()
{
    queue<int> q ;
    q.push(10) ;
    q.push(20) ;
    q.push(30) ;
    q.push(40) ;
    q.push(50) ;

    // reverse_q_using_stack(q) ;

    reverse_q_using_recursion( q ) ;

    while( !q.empty() )
    {
        cout << q.front() << " " ;
        q.pop() ;
    }
    cout << endl ;
    return 0;
}