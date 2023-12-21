// LeetCode 1047

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st ;

        for( auto ch :s )
        {
            if ( !st.empty() && ch == st.top() )
                st.pop() ;
            
            else
                st.push( ch ) ;
        }
        
        string ans ;
        while( !st.empty() )
        {
            ans += st.top() ;
            st.pop() ;
        }

        reverse( ans.begin() , ans.end() ) ;
        return ans ;    

    }
}; 
int main()
{

    return 0;
}