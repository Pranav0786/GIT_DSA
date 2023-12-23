// GFG Que

#include<bits/stdc++.h>
using namespace std;

int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int> st ;
        
        for( int i=0 ; i < n ; i++ )
            st.push(i) ;
            
        while( st.size() != 1 )
        {
            int a = st.top() ;
            st.pop() ;
            int b = st.top() ;
            st.pop() ;
            
            if( M[a][b] == 1 )
                st.push(b) ;
        
            else if( M[b][a] == 1 )
                st.push(a) ;
        }
        
        int ans = st.top() ;
        st.pop() ;
        
        for( int i =0 ; i < n ; i++ )
        {
            if( M[ans][i] == 1 )
                return -1 ;
        }
        for( int i =0 ; i < n ; i++ )
        {
            if( i == ans ) continue ;
            
            if( M[i][ans] == 0 )
                return -1 ;
        }
        
        return ans ;
    }
    
int main()
{
    return 0;
} 