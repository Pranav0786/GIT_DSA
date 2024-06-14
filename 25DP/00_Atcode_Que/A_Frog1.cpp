// https://atcoder.jp/contests/dp/tasks/dp_a 

#include<bits/stdc++.h>
using namespace std;

int solve( int n, vector<int>&v , vector<int>&dp )
{
    if( n == 0 )
        return 0 ;
    if( dp[n] != -1 )
        return dp[n] ;
    int cost = INT_MAX ;
    cost = min( solve(n-1,v,dp)+abs(v[n]-v[n-1]) , cost ) ;
    if( n > 1 )
        cost = min( solve(n-2,v,dp)+abs(v[n]-v[n-2]) , cost ) ;
    return dp[n] = cost ;
}

int main()
{
    int n ;
    cin >> n ;
    vector<int>v(n) ;
    for( int i = 0 ; i < n ; i++ )
        cin >> v[i] ;
    vector<int>dp(n+1,-1) ;
    cout << solve( n-1 , v , dp ) << endl ;
}
