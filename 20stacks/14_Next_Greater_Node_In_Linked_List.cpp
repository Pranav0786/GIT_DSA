// LeetCode 1019

#include<bits/stdc++.h>
using namespace std;

struct  ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> input ;
        ListNode* temp  = head ;
        while( temp != NULL )
        {
            input.push_back( temp->val ) ;
            temp = temp->next ;
        }
        stack<int> st ;
        st.push(INT_MAX) ;
        vector<int> ans(input.size()) ;
        for( int i = input.size()-1 ; i>=0 ; i-- )
        {
            int curr = input[i] ;

            while( curr >= st.top() )
                st.pop() ;

            ans[i] = st.top() ;

            st.push( curr ) ;
        }

        for( int i = 0 ; i < ans.size() ; i++ )
        {
            if( ans[i] == INT_MAX ) 
                ans[i] = 0 ;
        }
        
        return ans ;
    }
};

int main()
{
    return 0;
}