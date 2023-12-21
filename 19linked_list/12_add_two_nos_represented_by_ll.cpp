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

Node* reverse_ll( Node* &head)
{
    Node* prev = NULL ; 
    Node* curr = head ; 
    while( curr != NULL )
    {
        Node* forword = curr->next ; 
        curr->next = prev ; 
        prev = curr ; 
        curr = forword ; 
    }

    return prev ; 
}

Node* solve( Node* &head1 , Node* &head2 )
{
    // reverse both ll
    head1 = reverse_ll(head1) ;
    head2 = reverse_ll(head2) ;

    // add both ll 
    Node* ansHead = NULL ;
    Node* ansTail = NULL ;

    int carry = 0 ;
    while( head1 != NULL && head2 != NULL )
    {
        // calculate sum digit carry
        int sum = carry + head1->data + head2->data ; 
        int digit = sum % 10 ;
        carry = sum/10 ; 
        // new node
        Node* newnode = new Node( digit ) ;
        // attach new node
        if( ansHead == NULL )
        {
            ansHead = newnode ;
            ansTail = newnode ;
        }
        else
        {
            ansTail->next = newnode ;
            ansTail = newnode ;
        }

        head1 = head1->next ;
        head2 = head2->next ;
    }
    // head1 is greater than head2
    while( head1 != NULL )
    {
        int sum = carry + head1->data ;
        int digit = sum % 10 ;
        carry = sum /10 ;

        Node* newnode = new Node( digit ) ;
        ansTail ->next = newnode ;
        ansTail = newnode ;

        head1 = head1->next ;
    }
    // head2 is greater than head1
    while( head2 != NULL )
    {
        int sum = carry + head2->data ;
        int digit = sum % 10 ;
        carry = sum /10 ;

        Node* newnode = new Node( digit ) ;
        ansTail ->next = newnode ;
        ansTail = newnode ;

        head2 = head2->next ;
    }

    // carry is not equal to zero
    while( carry != 0 )
    {
        int sum = carry ;
        int digit = sum % 10 ;
        carry = sum / 10 ;
        Node* newnode = new Node( digit ) ;
        ansTail->next = newnode ;
        ansTail = newnode ;
    }

    ansHead = reverse_ll( ansHead ) ;
    return ansHead ;
}

void print( Node* &head )
{
    Node* temp = head ;
    while( temp!= NULL )
    {
        cout << temp->data ; 
        temp = temp->next ; 
    }
    cout << endl ; 
}

int main()
{
    Node* head1 = new Node(2) ; 
    Node* second1 = new Node(4) ; 

    head1->next = second1 ; 

    Node* head2 = new Node(2) ; 
    Node* second2 = new Node(3) ; 
    Node* third2 = new Node(4) ; 

    head2->next = second2 ; 
    second2 ->next = third2 ; 

    Node* ans = solve( head1 , head2 ) ; 
    print( ans ) ; 
    return 0 ; 
}

// TC = O( max( m,n ) ) 
// SC = O(1)