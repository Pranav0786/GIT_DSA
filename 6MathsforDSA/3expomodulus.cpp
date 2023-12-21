#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int ans( int num , int exp , int mod )
{
    int res = 1 ;
    while( exp>0 )
    {
        if( exp&1 ) // odd
            res = ( 1LL * (res) * (num % mod) ) %mod ;
        num = ( 1LL * (num)%mod * (num)%mod ) %mod ;
        num = num>>1 ;

    }
    return res ;
} 
int main()
{
    int num , exp , mod ;
    cout<<"enter num exp mod\n" ;
    cin>>num>>exp>>mod ;
    cout<< ans(num , exp , mod )<<endl ;
    return 0;
}