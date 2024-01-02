#include<bits/stdc++.h>
using namespace std;

void reverse_k_elements( queue<int> &q , int k ) 
{
    int size = q.size() ;

    stack<int> s ;
    int count = 0 ;

    while( !q.empty() && count < k )
    {
        int top = q.front() ;
        q.pop() ;
        s.push(top) ;
    }

    while( !s.empty() )
    {
        int top = s.top() ;
        s.pop() ;
        q.push( top ) ;
    }

    count = 0 ;

    while( count < size-k  )
    {
        int top = q.front() ;
        q.pop() ;
        q.push( top ) ;
        count++ ;
    }
}
int main()
{
    queue<int> q ;
    q.push(10) ;
    q.push(20) ;
    q.push(30) ;
    q.push(40) ;
    q.push(50) ;
    q.push(60) ;
    q.push(70) ;

    reverse_k_elements( q , 3 ) ;

    while( !q.empty() )
    {
        cout << q.front() << " " ;
        q.pop() ;
    }
    cout << endl ;

    return 0;
}