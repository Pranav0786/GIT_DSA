// LeetCode 2181

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
    ListNode* mergeNodes(ListNode* head) {
        if( head == NULL )
            return head ;

        ListNode* slow = head ;
        ListNode* fast = head->next ;
        ListNode* lastnode = NULL ;
        ListNode* anshead = slow ;

        int sum = 0 ;
        while( fast != NULL )
        {
            if( fast->val != 0 )
                sum += fast->val ;

            else
            {
                slow->val = sum ;
                lastnode = slow ;
                slow = slow->next ;
                sum = 0 ;
            }

            fast = fast->next ;
                
        }

        delete slow ;
        lastnode->next = NULL ;

        return anshead ;
    }
};
int main()
{
    return 0;
}