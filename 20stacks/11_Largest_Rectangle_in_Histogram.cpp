// LeetCode 84

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> next_smaller_index( vector<int> v )
    {
        stack<int> s ;
        s.push(-1) ;

        vector<int> ans(v.size()) ;

        for( int i = v.size()-1 ; i>=0 ; i-- )
        {
            int curr = v[i] ;

            while( s.top() != -1 && v[s.top()] >= curr )
                s.pop() ;

            ans[i] = s.top() ;

            s.push(i) ;
        }

        return ans ;
    }

    vector<int> previous_smaller_index( vector<int> v )
    {
        stack<int> s ;
        s.push(-1) ;
        vector<int> ans(v.size()) ;

        for( int i= 0 ; i < v.size() ; i++ )
        {
            int curr = v[i] ;
            while( s.top() != -1 && v[s.top()] >= curr )
                s.pop() ;

            ans[i] = s.top() ;

            s.push(i) ;
        }   

        return ans ; 
    }
    int largestRectangleArea(vector<int>& h) 
    {
        vector<int>prevsmaller = previous_smaller_index( h ) ;
        vector<int>nextsmaller = next_smaller_index( h ) ;

        int size = h.size() ;
        int area = INT_MIN ;

        for( int i = 0 ; i < h.size() ; i++ )
        {
            int len = h[i] ; 
            if( nextsmaller[i] == -1 ) nextsmaller[i] = size ;

            int width = nextsmaller[i] - prevsmaller[i] -1 ;
            int temp = len * width ;
            area = max(temp,area) ;
        }

        return area ;
    }
};

int main()
{
    
    return 0;
}