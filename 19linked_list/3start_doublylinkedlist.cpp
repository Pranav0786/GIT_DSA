#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data ;
    Node* prev ;
    Node* next ;

    Node()
    {
        this-> data = 0 ;
        this-> prev = NULL ;
        this-> next = NULL ;
    }
    Node( int data )
    {
        this->data = data ;
        this->prev = NULL ;
        this->next = NULL ;
    }
} ;
int getlength( Node* &head )
{
    int len = 0 ;
    Node* temp = head ;
    while( temp != NULL )
    {
        len++ ;
        temp = temp->next ;
    }
    return len ;
}
void print( Node* head )
{
    while( head != NULL )
    {
        cout << head->data << " " ;
        head = head->next ;
    }
    cout << endl ;
}

int main()
{
    Node* first = new Node(10) ;
    Node* second = new Node(20) ;
    Node* third = new Node(30) ;

    first->next = second ;
    second->prev = first ;

    second->next = third ;
    third->prev = second ;

    print( first ) ;
    return 0;
}