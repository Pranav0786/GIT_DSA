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

    // recursive way
    cout << calculate( n  , dp ) << endl ;

    // tabulation way
    for( int i = 0 ; i< n ; i++ )
    {
        if( n <= 1 )
            dp[i] = i ;
        else    
            dp[i] = dp[i-1] + dp[i-2] ;
    }
    cout << dp[n-1] << endl ;

    


    return 0 ;
}
