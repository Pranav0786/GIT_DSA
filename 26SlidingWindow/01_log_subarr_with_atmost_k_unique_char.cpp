#include<bits/stdc++.h>
using namespace std;
#define ll long long

int solve( string s , int k )
{
    int n = s.size() ;
    int l = 0 , r = 0 , maxi = 0 ;
    unordered_map<char,int>mp ; // char , freq 
    while( r < n )
    {
        mp[s[r]]++ ;
        if( mp.size() > k )
        {
            mp[s[l]]-- ;
            if( mp[s[l]] == 0 )
                mp.erase(s[l]) ;
            l++ ;
        }
        else
            maxi = max( maxi , r-l+1 ) ;
        r++ ;
    }
    return maxi ;
}

void pranav()
{
    cout << "Enter string and value of k\n" ;
    string s ;
    cin >> s ;
    int k ; 
    cin >> k ;
    int ans = solve(s , k ) ;
    cout << ans << endl ;
}

int main()
{
    int t ;
    cin >> t ;
    while( t-- )
        pranav() ;
    return 0 ;
}