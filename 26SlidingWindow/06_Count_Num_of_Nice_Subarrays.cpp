// leetcode 1248

#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int solve( vector<int>&nums , int k )
    {
        int n = nums.size() ;
        int l = 0 , r = 0 , ans = 0 , odd = 0 ;
        while( r < n )
        {
            if( nums[r]%2 != 0 )
                odd++ ;
            while( odd > k )
            {
                if( nums[l]%2 != 0 )
                    odd-- ;
                l++ ;
            }
            ans += r-l+1 ;
            r++ ;
        }
        return ans ;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve( nums , k ) - solve( nums , k-1 ) ;
    }
};