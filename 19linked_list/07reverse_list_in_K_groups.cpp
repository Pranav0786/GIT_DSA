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

Node* reverse_in_K( Node* &head , int k )
{
    if( head == NULL )
    {
        cout << "list is empty\n" ;
        return head ;
    }
    if( k > getlength( head ) )
    {
        cout <<"lack of list\n" ;
        return head ;
    }

    Node* prev = NULL ;
    Node* curr = head ;
    Node* forword = curr->next ;

    for( int i=0 ; i< k ; i++ )
    {
        forword = curr->next ;
        curr->next = prev ; 
        prev = curr ;
        curr = forword ;
    }

    if( forword != NULL )
        head->next = reverse_in_K( forword , k ) ;
    
    return prev ;
}

void print( Node* &head )
{
    Node* temp = head ;
    while( temp!= NULL )
    {
        cout << temp->data <<" " ;
        temp = temp->next ;
    }
    cout << endl ;
}

int main()
{
    Node* first = new Node(10) ;
    Node* second = new Node(20) ;
    Node* third = new Node(30) ;
    Node* forth = new Node(40) ;
    Node* fifth = new Node(50) ;
    Node* sixth = new Node(60) ;
    Node* seven = new Node(70) ;
    Node* eight = new Node(80) ;
    Node* nine = new Node(90) ;

    first->next = second;
    second->next = third ;
    third->next = forth ;
    forth->next = fifth ;
    fifth->next = sixth ;
    sixth->next = seven ; 
    seven->next = eight ;
    eight->next = nine ;

    Node* head = first ;
    print( head ) ;
    
    int k = 3 ;
    head = reverse_in_K( head , k ) ;
    print( head ) ;
    return 0;
}