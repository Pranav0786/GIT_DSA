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

// Method One
void sorting_replace_data( Node* &head )
{
    int zero = 0 , one = 0 , two = 0 ;
    Node* temp = head ;
    while( temp!=NULL)
    {
        if( temp->data == 0 ) zero++ ;
        if( temp->data == 1 ) one++ ;
        if( temp->data == 2 ) two++ ;
        temp = temp->next ;
    }

    temp = head ;
    while( temp != NULL )
    {
        while( zero && temp != NULL )
        {
            temp->data = 0 ;
            temp = temp->next ;
            zero-- ;
        }
        while( one && temp != NULL )
        {
            temp->data = 1 ;
            temp = temp->next ;
            one-- ;
        }
        while( two && temp != NULL )
        {
            temp->data = 2 ;
            temp = temp->next ;
            two-- ;
        }
    }
}

// Method Two
void sorting_notreplacing_data(Node* &head )
{
    // create dummy nodes 
    Node* zero = new Node(-1) ;
    Node* zerotail = zero ;
    Node* one = new Node(-1) ;
    Node* onetail = one ;
    Node* two = new Node(-1) ;
    Node* twotail = two ;


    Node* temp = head; 
    while( temp !=NULL)
    {
        Node* curr = temp ;
        temp = temp->next ;
        curr->next = NULL ;

        if( curr->data == 0 )
        {
            zerotail->next = curr ;
            zerotail = zerotail->next ;
        }
        else if( curr->data == 1)
        {
            onetail->next = curr ;
            onetail = onetail->next ;
        }
        else
        {
            twotail->next = curr ;
            twotail = twotail->next ;
        }
    }

    // joind
    zerotail->next = one->next ;
    onetail->next = two->next ;
    head = zero->next ;

    // separate dummy nodes
    zero->next = NULL ;
    two->next = NULL ;
    one->next = NULL ;

    // delete dummy nodes
    delete zero ;
    delete one ;
    delete two ;
    
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
    Node* head = new Node(1) ;
    Node* second = new Node(2) ;
    Node* third = new Node(0) ;
    Node* forth = new Node(0) ;
    Node* fifth = new Node(0) ;
    Node* sixth = new Node(1) ;
    Node* seven = new Node(1) ;
    Node* eight = new Node(1) ;
    Node* nine = new Node(1) ;

    head->next = second;
    second->next = third ;
    third->next = forth ;
    forth->next = fifth ;
    fifth->next = sixth ;
    sixth->next = seven ; 
    seven->next = eight ;
    eight->next = nine ;

    print(head) ;
    // sorting_replace_data( head ) ;

    sorting_notreplacing_data( head ) ;

    print(head) ;
    return 0;

}  

// TC = O(n) 
// SC = O(1)