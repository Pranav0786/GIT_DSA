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

void insert_at_head( Node* &head ,Node* &tail, int data )
{
    Node* New = new Node(data) ;
    if( head == NULL )
    {
        head = New ;
        tail = New ;
        return ;
    }
    New->next = head ;
    head = New ;
}
void insert_at_tail( Node* &head , Node* &tail , int data )
{
    Node* New = new Node(data) ;
    if( head == NULL )
    {
        head = New ;
        tail = New ;
        return ;
    }
    tail->next = New ;
    tail = New ;
    // Node* temp = head ;
    // while( temp->next != NULL )
    //     temp = temp->next ;

    // temp->next = New ;
}
int findlength( Node* &head )
{
    Node* temp = head ;
    int count = 1 ;
    while( temp != NULL )
    {
        temp = temp->next ;
        count++ ;
    } 
    return count ;
}
void insert_at_position( Node* &head , Node* &tail , int data , int position )
{
    Node *New = new Node( data ) ;
    if( head == NULL )
    {
        head = New ;
        tail = New ;
        return ; 
    }

    if( position == 0 )
    {
        insert_at_head( head , tail , data ) ;
        return ;
    }

    if( position >= findlength( head ) )
    {
        insert_at_tail( head , tail , data ) ;
        return ;
    }

    Node* pre = head ;
    for( int i=1 ; i<position ; i++ )
        pre = pre->next ;
    
    Node* cur = pre->next ;
    New->next = cur ;
    pre->next = New ;
}
void delete_at_head( Node* &head )
{
    if( head == NULL )
    {
        cout <<"list is empty\n";
        return ;
    }
    Node* temp = head ;
    head = head->next ;
    temp->next = NULL ;
    delete temp ;
}
void delete_at_tail( Node* &head , Node* &tail )
{
    if( head == NULL )
    {
        cout <<"list is empty\n";
        return ;
    }
    if( head->next == NULL ) 
    {
        delete head ;
        return ;
    }
    Node* temp = head ;
    while( temp->next != tail )
        temp = temp->next ;
    
    Node* pre = temp ;
    temp = temp->next ;
    tail = pre ;
    delete temp ; 
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
    Node* head = NULL ;
    Node* tail = NULL ;
    insert_at_head( head ,tail , 50 ) ;
    insert_at_head( head ,tail , 40 ) ;
    insert_at_head( head ,tail , 30 ) ;
    insert_at_head( head ,tail , 20 ) ;
    insert_at_head( head ,tail , 10 ) ;
    insert_at_tail( head ,tail , 100 ) ;
    print( head ) ;
    insert_at_position( head , tail , 99 , 6) ;
    print( head ) ;
    delete_at_head( head ) ;
    print( head ) ;
    delete_at_tail( head , tail ) ;
    print( head ) ;
    return 0;
}