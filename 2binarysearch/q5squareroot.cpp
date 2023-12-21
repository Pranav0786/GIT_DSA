#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int root(int n)
{
    int s=0 , e= n-1 ;
    int mid = s/2 + e/2 ;
    while(s<=e)
    {
        if( mid*mid == n )
            return mid;
        else if( mid*mid > n )
            e = mid-1 ;
        else if( mid*mid < n )
            s = mid+1 ;
        mid = s/2 + e/2 ;
    }
    return 0 ;
}
double point( int n , int precision , int tempsol )
{
    double factor = 1 ;
    double ans = tempsol ;
    for(int i=0 ; i < precision ; i++ )
    {
        factor/=10 ;
        for( double j=ans ; j*j < n ; j+=factor )
            ans = j ;
    }
    return ans ;
}
int main()
{
    int n;
    cout<<"enter a num\n";
    cin>>n;
    int tempsol = root(n);
    cout<<"Answer is "<<point( n , 3 , tempsol )<<endl;
    return 0;
}