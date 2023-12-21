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

void remove_dublicates( Node* &head )
{
    Node* curr = head ;
    while( curr->next != NULL )
    {
        if( curr->data == curr->next->data ) 
        {
            Node* temp = curr->next ; 
            curr->next = curr->next->next ; 
            temp->next = NULL ; 
            delete temp ; 
        }
        
        else
            curr = curr->next ; 
    }
}

int main()
{
    Node* head = new Node(10) ;
    Node* second = new Node(20) ;
    Node* third = new Node(30) ;
    Node* forth = new Node(40) ;
    Node* fifth = new Node(50) ;
    Node* sixth = new Node(50) ;
    Node* seven = new Node(60) ;
    Node* eight = new Node(70) ;
    Node* nine = new Node(70) ;
    Node* tenth = new Node(70) ;

    head->next = second;
    second->next = third ;
    third->next = forth ;
    forth->next = fifth ;
    fifth->next = sixth ;
    sixth->next = seven ; 
    seven->next = eight ;
    eight->next = nine ;
    nine->next = tenth ;

    print( head ) ;

    remove_dublicates( head ) ;
    
    print( head ) ;

    return 0;
}

// TC = O(n) 
// SC = O(1)