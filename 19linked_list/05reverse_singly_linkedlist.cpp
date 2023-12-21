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
        this -> data = 0 ;
        this -> next = NULL ;
    }
    Node( int data )
    {
        this-> data = data ;
        this-> next = NULL ;
    }
};

Node* reverse_linkedlist( Node* &prev , Node* &curr )
{
    if( curr == NULL )
        return prev ;
    
    Node* forword = curr->next ;
    curr->next = prev ;
    
    return reverse_linkedlist( curr , forword ) ;
}

void print( Node* &head )
{
    Node* temp = head ;
    while( temp != NULL)
    {
        cout << temp->data << " " ;
        temp = temp->next ;
    }
    cout << endl ;
} 


int main()
{
    Node* first = new Node(10) ;
    Node* second = new Node(20) ;
    Node* third = new Node(30) ;
    Node* fourth = new Node(40) ;
    Node* fifth = new Node(50) ;

    first->next = second ;
    second->next = third ;
    third->next = fourth ;
    fourth->next = fifth ;

    Node* head = first ;
    print( head ) ;

    Node* prev = NULL ;
    Node* curr = head ;

    // recursive
    // head = reverse_linkedlist( prev , curr ) ;
    // print( head ) ;

    // loop
    while( curr != NULL )
    {
        Node* forward = curr->next ;
        curr->next = prev ;
        prev = curr ;
        curr = forward ;
    }
    print( prev ) ;
    return 0;

}