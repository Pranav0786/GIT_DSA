// leetcode que 904

#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int totalFruit(vector<int>& f) {
        int n = f.size() ;
        int l = 0 , r = 0 , maxi = 0 ;
        unordered_map<int,int>mp ; // fruit , freq 
        while( r < n )
        {
            mp[f[r]]++ ;
            if( mp.size() > 2 )
            {
                mp[f[l]]-- ;
                if( mp[f[l]] == 0 )
                    mp.erase(f[l]) ;
                l++ ;
            }
            else
            {
                maxi = max( maxi , r-l+1 ) ;
            }
            r++ ;
        }
        return maxi ;
    }
};

