#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool ispossible( vector<int>v , int size , int num , int mid)
{
    int studentcount = 1 ;
    int pagecount = 0 ;
    for( int i=0 ; i<size ; i++ )
    {
        if( pagecount + v[i] <= mid )
            pagecount+=v[i];
        else
        {
            studentcount++ ;
            if( studentcount > num || v[i] > mid )
                return false ;
            pagecount = 0 ;
            pagecount+=v[i] ;
        }
    }
    return true ;
}
int allocatebook( vector< int > v ,int size, int num )
{
    int s=0 ;
    int sum = 0;
    for( int i=0 ; i<size ; i++ )
        sum += v[i] ; 
    int e = sum ;
    int mid = s/2 + e/2 ;
    int ans =0;
    while( s<=e )
    {
        if( ispossible( v , size , num , mid ) )
        {
            ans = v[mid] ;
            e = mid-1 ;
        }
        else
            s = mid+1 ;
        mid = s/2 + e/2 ;
    }
    return ans ;
}
int main()
{
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    allocatebook(v,4,2);
    cout << allocatebook << endl ;
    return 0;
}