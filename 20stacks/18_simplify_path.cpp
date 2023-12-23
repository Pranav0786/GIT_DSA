// LeetCode 71

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void buildans( stack<string> &st , string &ans )
    {
        if(st.empty() ) return ;

        string temp = st.top() ;
        st.pop() ;
        buildans( st , ans ) ;
        ans += temp ;
    }

    string simplifyPath(string path) {
        stack<string> st ;
        int i = 0 ;
        while( i < path.size() )
        {
            int start = i ;
            int end = start + 1 ;

            while( end < path.size() && path[end] != '/' ) end++ ;

            string minpath = path.substr( start , end-start ) ;
            i = end ;

            if( minpath == "/" || minpath == "/." ) continue ;

            if( minpath != "/.." ) 
                st.push(minpath) ;

            else if( !st.empty() )  
                st.pop() ;
        }

        string ans = st.empty() ? "/" : "" ;

        buildans( st , ans ) ;
        return ans ;
    }
};

int main()
{
    return 0;
}