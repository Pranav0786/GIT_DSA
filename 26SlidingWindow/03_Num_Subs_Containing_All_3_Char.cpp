// leetcode 1358

#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size() ; 
        int a = -1 , b = -1 , c = -1 ;
        int ans = 0 ;
        for( int i = 0 ; i < n ; i++ )
        {
            if( s[i] == 'a' ) a = i ;
            else if( s[i] == 'b' ) b = i ;
            else c = i ;
            
            if( a != -1 && b != -1 && c != -1 )
                ans += min( a , min( b , c ) )+1 ;
        }
        return ans ;
    }
};

