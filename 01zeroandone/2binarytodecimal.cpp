#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int ans=0,i=0;
    while(n)
    {
        int digit = n%10;
        n=n/10;
        if(digit ==1)
            ans=pow(2,i)+ans;
        i++;
    }
    cout<<ans;
    return 0;
}