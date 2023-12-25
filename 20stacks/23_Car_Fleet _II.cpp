// LeetCode 1776

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        
        vector<double> ans( cars.size() , -1 ) ;
        stack<int> st ;

        for( int i = cars.size()-1 ; i>=0; i-- )
        {
            // chaek if car ahead of cuurent car is faster
            while( !st.empty() && cars[st.top()][1] >= cars[i][1] ) 
                st.pop() ;

            while( !st.empty() )
            {
                double currtime = (double) (cars[st.top()][0] - cars[i][0]) /  
                                   ( cars[i][1] - cars[st.top ()][1] ) ;

                if( ans[st.top()] == -1 || currtime <= ans[st.top()] ) 
                {
                    ans[i] = currtime ;
                    break ;
                }

                st.pop() ;
            }

            st.push(i) ;
        }

        return ans ;
    }
};

int main()
{
    return 0;
}