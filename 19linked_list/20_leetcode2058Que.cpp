// LeetCode Que 2058

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        vector<int> ans(2,-1) ;
        if( head == NULL || head->next == NULL || head->next->next == NULL )
            return ans ;

        ListNode* prev = head ;
        ListNode* curr =  head->next ;
        ListNode* nxt = curr->next ;

        int firstcp = -1 ;
        int lastcp = -1 ;
        int mini = INT_MAX ; 
        int i = 1 ;

        while( nxt != NULL )
        {
            bool iscp = ( (prev->val < curr->val && curr->val > nxt->val) || 
                (prev->val >curr->val && curr->val < nxt->val ) )
                    ? true : false ; 

            if( iscp && firstcp == -1 )
            {
                firstcp = i ;
                lastcp = i ;
            }
            else if( iscp )
            {
                mini = min( mini , i-lastcp ) ;
                lastcp = i ;
            }

            ++i ;
            prev = prev->next ;
            curr = curr->next ;
            nxt = nxt->next ;
        }

        if( lastcp == firstcp ) return ans ;
        else 
        {
            ans[0] = mini ;
            ans[1] = lastcp - firstcp ;
        }

        return ans ;

    }
};

int main()
{
    return 0;
}