// LeetCode Que 61

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class ListNode 
{
    public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution 
{
public:

    int findlen( ListNode* head ) 
    {
        int count = 0 ;
        while( head != NULL )
        {
            count++ ;
            head = head->next ;
        }
        return count ;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        if( head == NULL ) return head ;

        int len = findlen(head) ;
        k = k%len ;
        if( k == 0 ) return head ;

        int q = len-k-1 ;
        ListNode* temp = head ;
        
        while( q != 0 )
        {
            temp = temp->next ;
            q-- ;
        }

        ListNode* ans = temp->next ;
        temp->next = NULL ;
        ListNode* temp2 = ans ;

        while( temp2->next != NULL )
            temp2 = temp2->next ;

        temp2->next = head ;
        return ans ;

    }
};

int main()
{
    return 0;
}