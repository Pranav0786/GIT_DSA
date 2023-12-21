// LeetCode 32

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        if( s.size() <= 1 ) return 0 ;

        stack<int> st ;
        st.push(-1) ;
        int maxi = 0 ;
        for( int i=0 ; i < s.size() ; i++ )
        {
            char c = s[i] ;
            if( c == '(' )
                st.push(i) ;
            else
            {
                st.pop() ;
                if( st.empty() ) 
                    st.push(i) ;
                    
                else
                {
                    int len = i - st.top() ;
                    maxi = max(maxi , len ) ;
                }
            }
        }

        return maxi ;
    }
};

int main()
{
    return 0;
}