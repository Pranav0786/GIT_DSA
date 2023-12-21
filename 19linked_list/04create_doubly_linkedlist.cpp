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
        data = 0 ;
        prev = next = NULL ;
    }
    Node( int data )
    {
        this->data = data ;
        prev = next = NULL ;
    }
} ;
int findlength( Node* &head )
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
void insert_at_head( Node* &head , Node* &tail , int data )
{
    Node* New = new Node( data ) ;
    if( head == NULL )
    {
        head = New ;
        tail = New ;
        return ;
    }
    New->next = head ;
    head->prev = New ;
    head = New ; 
}
void insert_at_tail( Node* &head , Node* &tail , int data )
{
    Node* New = new Node( data ) ; 
    if( head == NULL )
    {
        head = New ;
        tail = New ;
        return ;
    }
    tail->next = New ;
    New->prev = tail ;
    tail = New ;
}
void insert_at_position( Node* &head , Node* &tail , int data , int position )
{
    if( head == NULL || position <= 1 )
    {
        insert_at_head( head , tail , data ) ;
        return ;
    }
    if( position > findlength(head) )
    {
        insert_at_tail( head , tail , data ) ;
        return ;
    }
    Node* New = new Node( data ) ;
    Node* prev = head ;
    position = position-2 ;
    while( position )
    {
        prev = prev->next ;
        position-- ;
    }
    Node* curr = prev->next ;
    prev->next = New ;
    New->prev = prev ;
    New->next = curr ;
    curr->prev = New ;
}
void delete_at_head( Node* &head )
{
    if( head == NULL )
    {
        cout <<"list is empty\n" ;
        return ;
    }
    if( head->next == NULL )
    {
        Node* temp = head ;
        head = NULL ;
        delete temp ;
        return ;
    }
    Node* temp = head ;
    head = head->next ;
    head->prev = NULL ;
    temp->next = NULL ;
    delete temp ;
}
void delete_at_tail( Node* &head , Node* &tail )
{
    if( head == NULL )
    {
        cout <<"list is empty\n" ;
        return ;
    }
    if( head->next == NULL )
    {
        Node* temp = head ;
        head = NULL ;
        delete temp ;
        return ;
    }
    Node* temp = head ;
    while( temp->next != tail )
        temp = temp->next ;

    Node* q = tail ;
    tail = temp ;

    temp = q ;
    temp->prev = NULL ;
    tail->next = NULL ;
    delete temp ;
}
void delete_at_position( Node* &head , Node* &tail , int position )
{
    if( position <=1 )
    {
        delete_at_head( head ) ;
        return ;
    }
    if( position == findlength( head ) ) 
    {
        delete_at_tail( head , tail ) ;
        return ;
    }
    if( position > findlength( head ) )
    {
        cout <<"Invalide position\n" ;
        return ;
    }
    Node* left = head ;
    for( int i=1 ; i<position-1 ; i++ )
        left = left->next ;
    
    Node* temp = left->next ;
    Node* right = temp->next ;

    right->prev = left ;
    left->next = right ;
    temp->next = NULL ;
    temp->prev = NULL ;
    delete temp ;
}

void print( Node* &head )
{
    if( head == NULL )
    {
        cout << "list is empty\n" ;
        return ;
    }
    Node* temp = head ;
    while( temp != NULL )
    {
        cout << temp->data << " " ;
        temp->prev = temp ;
        temp = temp->next ;
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

    Node* head = first ;
    Node* tail = third ;

    insert_at_head( head , tail , 33 ) ;
    print( head ) ;
    insert_at_tail( head , tail , 55 ) ;
    print( head ) ;
    insert_at_position( head , tail , 7777 , 5 ) ;
    print( head ) ;
    delete_at_tail( head , tail ) ;
    print( head ) ;
    delete_at_position( head , tail , 1) ;
    print( head ) ;
    return 0;
}