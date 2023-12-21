// gfg Que

#include<bits/stdc++.h>
using namespace std;

int countRev (string s)
{
    int size = s.size() ;
    if( size%2 != 0 ) return -1 ;
    
    int ans = 0 ;
    stack<int> st ;
    
    for( auto ch : s )
    {
        if( ch == '{')
            st.push( ch ) ;
        else
        {
            if( !st.empty() && st.top()== '{' ) 
                st.pop() ;
            else
                st.push( ch ) ;
        }
    }
    
    // count reversal 
    while( !st.empty() )
    {
        char a = st.top() ; st.pop() ;
        char b = st.top() ; st.pop() ;
        
        if( a== b )
            ans+=1 ;
        else    
            ans+=2 ;
    }
    
    return ans ;
    
}

int main()
{
    return 0;
}