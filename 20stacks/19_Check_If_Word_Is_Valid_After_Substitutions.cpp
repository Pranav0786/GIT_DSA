// LeetCode 1003

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st ;
        int i= 0 ;
        if( s[i] != 'a' ) return false ;

        while( i < s.size() ) 
        {
            char c = s[i] ;
            if( c == 'a' ) 
                st.push(c) ;

            else if( c == 'b' )
            {
                if( !st.empty() && st.top() == 'a' ) 
                    st.push(c) ;

                else 
                    return false ;
            }

            else  
            {
                if( !st.empty() && st.top() == 'b' )
                {
                    st.pop();
                    if( !st.empty() )
                        st.pop() ;
                    
                    else return false ;
                }
                
                else return false ;
                
            } 

            i++ ;
        }

        if( st.empty() ) return true ;
        else return false ;
    }
};

int main()
{
    return 0;
}