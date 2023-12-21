// LeetCode 160

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data ;
    Node* next ;

    Node()
    {
        data = 00 ;
        next = NULL ;
    }
    Node( int data )
    {
        this->data = data ; 
        this->next = NULL ; 
    }
};

class Solution 
{
public:
    Node *getIntersectionNode(Node *headA, Node *headB) {
        Node* a = headA ;
        Node* b = headB ;

        while( a->next!=NULL && b->next!=NULL )
        {
            if( a == b ) return a ;
            a = a->next ;
            b = b->next ;
        }

        if( a->next==NULL ) // b is larger
        {
            int blen = 0 ;
            while( b->next != NULL )
            {
                blen++ ;
                b = b->next ;
            }
            while( blen-- )
                headB = headB->next ;
        }

        if( b->next==NULL ) // a is larger
        {
            int alen = 0 ;
            while( a->next != NULL )
            {
                alen++ ;
                a = a->next ;
            }
            while( alen-- )
                headA = headA->next ;
        }

        while( headA != headB )
        {
            headA = headA->next ;
            headB = headB->next ;
        }

        return headA ;
    }
};


int main()
{
    return 0;
}