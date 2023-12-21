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

void print( Node* &head )
{
    Node* temp = head ;
    while( temp != NULL )
    {
        cout << temp->data << " " ;
        temp = temp->next ;
    }
}
int main()
{
    Node* first = new Node(1) ;
    Node* second = new Node(2) ;
    Node* third = new Node(3) ;
    Node* fourth = new Node(4) ;
    Node* fifth = new Node(5) ;

    first->next = second ;
    second->next = third ;
    third->next = fourth ;
    fourth->next = fifth ;
    
    print(first) ;
    return 0;
}