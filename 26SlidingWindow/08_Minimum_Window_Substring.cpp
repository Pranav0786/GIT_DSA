// leetcode 76

#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size() ;
        unordered_map<char,int>mp ;
        for( auto i : t )
            mp[i]++ ;
        int l = 0 , r = 0 , minl = INT_MAX , ct = 0 , idx = -1 ;
        while( r < n )
        {
            if( mp.find(s[r]) != mp.end() ) 
            {
                mp[s[r]]-- ;
                if( mp[s[r]] >= 0 )
                    ct++ ;
            }
            while( ct == t.size() ) 
            {
                if( r-l+1 < minl )
                {
                    minl = r-l+1 ;
                    idx = l ;
                }
                if( mp.find(s[l]) != mp.end() ) 
                {
                    mp[s[l]]++ ;
                    if( mp[s[l]] > 0 )
                        ct-- ;
                }
                l++;
            }
            r++ ;
        }
        if( minl == INT_MAX ) 
            return ""; 
        return s.substr(idx, minl) ;
    }
};