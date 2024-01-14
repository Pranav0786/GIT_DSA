// LeetCode 134

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int deficit = 0 ; // lack of gas
        int balance = 0 ; // curr gas available
        int start = 0 ;   // starting index of circle

        for( int i = 0 ; i < gas.size() ; i++ )
        {
            balance += gas[i] - cost[i] ;

            if( balance < 0 )
            {
                deficit += balance ;
                balance = 0 ;
                start = i+1 ;
            }
        }
        
        if( balance + deficit >= 0 )
            return start ;

        return -1 ;
    }
};


int main()
{
    return 0;
}