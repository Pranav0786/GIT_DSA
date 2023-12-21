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

Node* find_middle_node( Node* &head )
{
    if( head == NULL )
    {
        cout <<"list is empty\n" ;
        return head ;
    }

    if( head->next == NULL )
        return head ;
    
    Node* slow = head ;
    Node* fast = head->next ;
    while( fast != NULL  )
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

void print( Node* &head ) 
{
    Node* temp = head ;
    while( temp != NULL )
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
    Node* sixth = new Node(60) ;

    first->next = second ;
    second->next = third ;
    third->next = fourth ;
    fourth->next = fifth ;
    fifth->next = sixth ;
    Node* head = first ;
    print( head ) ;

    cout << find_middle_node( head )->data << endl  ;
    return 0;
}