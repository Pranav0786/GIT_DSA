#include<bits/stdc++.h>
using namespace std;
 
void solve( int arr[] , int size , int k )
{
    deque<int> q ;

    // process first window of size k 
    for( int i = 0 ; i < k ; i++ )
    {
        if( arr[i] < 0 )
            q.push_back(i) ;
    }

    // remaining window 
    for( int i = k ; i < size ; i++ )
    {
        // ans of last window
        if( q.empty() ) 
            cout << '0' << " " ;

        else    
            cout << arr[ q.front() ] << " " ;

        // remove out of window elements
        while( !q.empty() && i-q.front() >= k )
            q.pop_front() ;

        // check curr element for insertion
        if( arr[i] < 0 )
            q.push_back(i) ;
    }

    // ans of last window
    if( q.empty() ) 
        cout << '0' << " " ;

    else    
        cout << arr[ q.front() ] << " " ;

}

int main()
{
    int size = 8 ;
    int arr[size] = {12,-1,-7,8,-15,30,16,28} ;
    int k = 3 ;

    solve( arr , size , k ) ;
    cout << endl ;

    return 0;
}