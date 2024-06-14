// https://atcoder.jp/contests/dp/tasks/dp_b

#include<bits/stdc++.h>
using namespace std;

int solve( int n, vector<int>&v , vector<int>&dp ,int k )
{
    if( n == 0 )
        return 0 ;
    if( dp[n] != -1 )
        return dp[n] ;
    int cost = INT_MAX ;
    for( int j = 1 ; j <= k ; j++ )
    {
        if( n-j >= 0 )
            cost = min( solve(n-j ,v,dp , k )+abs(v[n]-v[n-j]) , cost ) ;
    }
    
    return dp[n] = cost ;
}

int main()
{
    int n , k ;
    cin >> n >> k ;
    vector<int>v(n) ;
    for( int i = 0 ; i < n ; i++ )
        cin >> v[i] ;
    vector<int>dp(n+1,-1) ;
    cout << solve( n-1 , v , dp , k ) << endl ;
}
