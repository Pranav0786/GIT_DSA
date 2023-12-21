// Leetcode 148

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class ListNode
{
    public:
    int val ;
    ListNode* next ;

    ListNode()
    {
        this->val = 0 ;
        this->next = NULL ;
    }

    ListNode( int val )
    {
        this->val = val ;
        this->next = NULL ;
    }
};

class Solution {
public:

    ListNode* findmid( ListNode* head )
    {
        ListNode* slow = head ;
        ListNode* fast = head->next ;

        while( fast != NULL )
        {
            fast = fast->next ;
            if( fast != NULL )
            {
                fast = fast->next ;
                slow = slow->next ;
            }
        }

        return slow ; 
    }

    ListNode* merge( ListNode* list1, ListNode* list2 )
    {
        ListNode* anshead = new ListNode(-1) ;
        ListNode* anstail = anshead ;

        ListNode* head1 = list1 ;
        ListNode* head2 = list2 ;

        while( head1 != NULL && head2 != NULL )
        {
            if( head1->val <= head2->val )
            {
                ListNode* temp = head1 ;
                head1 = head1->next ;
                temp->next = NULL ;
                anstail->next = temp ;
                anstail = anstail->next ;
            }

            else
            {
                ListNode* temp = head2 ;
                head2 = head2->next ;
                temp->next = NULL ;
                anstail->next = temp ;
                anstail = anstail->next ;
            }
        }

        if( head1 != NULL ) // head1 is remaining   join all head1
            anstail->next = head1 ;

        if( head2 != NULL )    // head2 is remaining   join all head2
            anstail->next = head2 ;


        ListNode* temp = anshead ;
        anshead = anshead->next ;
        temp->next = NULL ;
        delete temp ;

        return anshead ;
    }

    ListNode* sortList(ListNode* head) 
    {
        if( head == NULL || head->next == NULL ) return head ;

        // Break LL int two halves using mid node
        ListNode* mid = findmid( head ) ;
        ListNode* left = head ;
        ListNode* right = mid->next ;
        mid->next = NULL ;

        // sort RE
        left = sortList( left ) ;
        right = sortList( right ) ;

        // merge both left and right LLs
        ListNode* ans = merge( left , right ) ;
        return ans ;
    }
};


int main()
{
    return 0;
}