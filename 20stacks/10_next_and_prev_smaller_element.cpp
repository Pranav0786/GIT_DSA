#include<bits/stdc++.h>
using namespace std;

vector<int> next_smaller( vector<int> v )
{
    stack<int> s ;
    s.push(-1) ;

    vector<int> ans(v.size()) ;

    for( int i = v.size()-1 ; i>=0 ; i-- )
    {
        int curr = v[i] ;

        while( s.top() >= curr )
            s.pop() ;

        ans[i] = s.top() ;

        s.push(curr) ;
    }

    return ans ;
}

vector<int> previous_smaller( vector<int> v )
{
    stack<int> s ;
    s.push(-1) ;
    vector<int> ans(v.size()) ;

    for( int i= 0 ; i < v.size() ; i++ )
    {
        int curr = v[i] ;
        while( s.top() >= curr )
            s.pop() ;

        ans[i] = s.top() ;

        s.push(curr) ;
    }   

    return ans ; 
}

int main()
{
    vector<int> v = {2,1,4,3};

    vector<int> NextSmaller = next_smaller( v ) ;
    vector<int> PreviousSmaller = previous_smaller( v ) ;

    for( int i=0 ; i < NextSmaller.size() ; i++ )
        cout << NextSmaller[i] << " " ;
    cout << endl;

    for( int i=0 ; i < PreviousSmaller.size() ; i++ )
        cout << PreviousSmaller[i] << " " ;
    cout << endl;

    return 0;
}