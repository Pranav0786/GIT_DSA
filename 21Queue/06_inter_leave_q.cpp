#include<bits/stdc++.h>
using namespace std;
 
void inter_leave_Q( queue<int> &q )
{
    if( q.empty() )
        return ;

    int size = q.size() ;
    int k = size/2 ;
    int count = 0 ;

    queue<int> temp ;
    while( !q.empty() )
    {
        temp.push( q.front() ) ;
        q.pop() ;
        count++ ;

        if( count == k )
            break ;
    }

    while( !q.empty() && !temp.empty() )
    {
        int f = temp.front() ;
        temp.pop() ;

        int s = q.front() ;
        q.pop() ;

        q.push(f) ;
        q.push(s) ; 
    }

    if( size & 1 )
    {
        q.push( q.front() ) ;
        q.pop() ;
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

    inter_leave_Q( q ) ;

    while( !q.empty() )
    {
        cout << q.front() << " " ;
        q.pop() ;
    }
    cout << endl ;

    return 0;
}