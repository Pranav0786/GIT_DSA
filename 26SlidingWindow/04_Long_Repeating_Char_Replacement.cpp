// leetcode 424

#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size() ;
        int maxl = 0 ,l = 0 , r = 0 ;
        int tempf = 0 ;
        unordered_map<char,int>mp ;
        while( r < n )
        {
            mp[s[r]]++ ;
            tempf = max( tempf , mp[s[r]]) ;
            if( r-l+1 - tempf > k )
            {
                mp[s[l]]-- ;
                l++ ;
            }
            else
                maxl = max( maxl , r-l+1 ) ;
            r++ ;
        }
        return maxl ;
    }
};

