// LeetCode 239

#include<bits/stdc++.h>
using namespace std;
 

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        deque<int> dq ;
        vector<int> ans ;

        // first k size window
        for( int i = 0 ; i < k ; i++ )
        {
            while( !dq.empty() && nums[i] >= nums[dq.back()] )
                dq.pop_back() ;

            dq.push_back(i) ;
        }

        // store ans
        ans.push_back( nums[dq.front()] ) ;

        // remaining windows
        for( int i = k ; i < nums.size() ; i++ )
        {
            // out of window remove
            if( !dq.empty() && i-dq.front() >= k )
                dq.pop_front() ;

            while( !dq.empty() && nums[i] >= nums[dq.back()] )
                dq.pop_back() ;

            dq.push_back(i) ;

            ans.push_back( nums[dq.front()] ) ;
        }

        return ans ;

    }
};


int main()
{
    return 0;
}