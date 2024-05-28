#include<bits/stdc++.h>
using namespace std;

int calculate( int n , vector<int>&dp )
{
    if( n <= 1 )
        return n ;
    if( dp[n] != -1 )
        return dp[n] ;
    dp[n] = calculate( n-1 , dp ) + calculate( n-2 , dp ) ;
    return dp[n] ;
}
int main()
{
    int n ;
    cin >> n ;
    vector<int> dp(n+1,-1) ;
    cout << calculate( n  , dp ) << endl ;
    return 0 ;
}
