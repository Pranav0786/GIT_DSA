// LeetCode 394

#include<bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    string decodeString(string s) {
        
        stack<string> st ;

        for( auto ch:s )
        {
            if( ch == ']' ) 
            {
                string ToRepeat = "" ;
                while( !st.empty() && st.top() != "[" ) 
                {
                    string top = st.top() ;
                    ToRepeat += top ;
                    st.pop() ;
                }
                st.pop() ;

                string numerical = "" ;
                while( !st.empty() && isdigit( st.top()[0] ) )
                {
                    numerical += st.top() ;
                    st.pop() ;
                }

                reverse( numerical.begin() , numerical.end() ) ;
                int n = stoi(numerical) ;

                // decode
                string currDecode = "" ;
                while(n--)
                    currDecode += ToRepeat ;

                st.push(currDecode) ;

            }

            else
            {
                string temp(1,ch) ;
                st.push(temp) ;

            }
        }
        
        string ans = "" ;
        while( !st.empty() )
        {
            ans += st.top() ;
            st.pop() ;
        }

        reverse(ans.begin() , ans.end() ) ;
        
        return ans ;
    }
};