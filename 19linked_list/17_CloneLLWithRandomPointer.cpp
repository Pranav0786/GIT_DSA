// LeetCode Que = 138

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node 
{
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) 
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:

    Node* helper(Node* head , unordered_map<Node*, Node*> &mp) // SC O(n)
    {
        if( head == NULL ) return NULL ;

        Node* newhead = new Node( head->val ) ;
        mp[head] = newhead ;
        newhead->next = helper(head->next , mp ) ;

        if( head->random != NULL )
            newhead->random = mp[head->random] ;

        return newhead ;
    }

    Node* solve( Node* head ) // SC O(1)
    {
        if( head == NULL ) return NULL ;
        // Step1 Clone A->A'
        Node* temp = head ;
        while( temp != NULL )
        {
            Node* cloneNode = new Node( temp->val ) ;
            cloneNode->next = temp->next ;
            temp->next = cloneNode ;
            temp = temp->next->next ;
        }
        // Step2 Assign random links of A' with the help of A
        temp = head ;
        while( temp != NULL )
        {
            Node* cloneNode = temp->next ;
            if( temp->random == NULL )
                cloneNode->random = NULL ;
            else 
                cloneNode->random = temp->random->next ;
            temp = temp->next->next ; 
        }
        // Step3 detach A and A'
        temp = head ;
        Node* cloneNode = temp->next ;
        while(temp != NULL )
        {
            Node* clone = temp->next ;
            temp->next = temp->next->next ;
            if( clone->next != NULL )
                clone->next = clone->next->next ;
            temp = temp->next ;
        }

        return cloneNode ;
    }

    Node* copyRandomList(Node* head) {
        // unordered_map<Node*, Node*> mp ;  // healper
        // return helper( head , mp ) ;

        return solve( head) ;
    }
};

int main()
{
    return 0;
}