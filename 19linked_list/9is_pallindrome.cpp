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
        data = 0 ;
        next = NULL ;
    }

    Node( int data )
    {
        this->data = data ;
        this->next = NULL ;
    }
};

Node* reverse_linkedlist( Node* &head )
{
    Node* curr = head ;
    Node* prev = NULL ;

    while( curr != NULL )
    {
        Node* forword = curr->next ;
        curr->next = prev ;
        prev = curr ;
        curr = forword ;
    }

    return prev ;
}

bool is_pallindrome( Node* &head )
{
    if( head==NULL) return 1 ;
    if( head->next == NULL ) return 1 ;

    Node* slow = head ;
    Node* fast = head->next ;

    while( fast!=NULL )
    {
        fast = fast->next ;
        if( fast!=NULL )
        {
            fast = fast->next ;
            slow = slow->next ;
        }
    }

    slow->next = reverse_linkedlist( slow->next ) ;

    Node* first = head ;  
    Node* second = slow->next ;

    while( second != NULL )
    {
        if( first->data != second->data )
            return 0 ;
        first = first->next ;
        second = second->next ;
    }

    return 1 ;
}

int main()
{
    Node* head = new Node(10) ;
    Node* second = new Node(20) ;
    Node* third = new Node(30) ;
    Node* forth = new Node(40) ;
    Node* fifth = new Node(50) ;
    Node* sixth = new Node(50) ;
    Node* seven = new Node(40) ;
    Node* eight = new Node(30) ;
    Node* nine = new Node(20) ;
    Node* tenth = new Node(10) ;

    head->next = second;
    second->next = third ;
    third->next = forth ;
    forth->next = fifth ;
    fifth->next = sixth ;
    sixth->next = seven ; 
    seven->next = eight ;
    eight->next = nine ;
    nine->next = tenth ;

    if( is_pallindrome( head ) )
        cout << "list is pallindrome\n" ;
    else cout << "list is not pallindrome\n " ;

    return 0;
}

// TC = O(n) 
// SC = O(1)