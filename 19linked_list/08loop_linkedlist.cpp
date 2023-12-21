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

bool is_loop_present( Node* &head )
{ 
    Node* slow = head ;
    Node* fast = head ;

    while( fast != NULL )
    {
        fast = fast->next ;
        if( fast != NULL )
        {
            fast = fast->next ;
            slow = slow->next ;
        }
        
        if( slow == fast ) return 1 ;
    }
    return 0 ;
}

bool is_loop_present( Node* &head , Node* &slow  , Node* &fast )
{

    while( fast != NULL )
    {
        fast = fast->next ;
        if( fast != NULL )
        {
            fast = fast->next ;
            slow = slow->next ;
        }
        
        if( slow == fast ) return 1 ;
    }
    return 0 ;
}

Node* startint_point_loop( Node* &head )
{
    Node* slow = head ;
    Node* fast = head ;

    Node* prev = NULL ;

    if( is_loop_present( head , slow , fast ) )
    {
        slow = head ;

        while( fast != slow )
        {
            slow = slow->next ;
            fast = fast->next ;
        }

        return fast ;
    }
    else
        cout << "loop is not present\n" ;

    return NULL ;

}

int main()
{
    Node* head = new Node(10) ;
    Node* second = new Node(20) ;
    Node* third = new Node(30) ;
    Node* forth = new Node(40) ;
    Node* fifth = new Node(50) ;
    Node* sixth = new Node(60) ;
    Node* seven = new Node(70) ;
    Node* eight = new Node(80) ;
    Node* nine = new Node(90) ;
    Node* tenth = new Node(100) ;

    head->next = second;
    second->next = third ;
    third->next = forth ;
    forth->next = fifth ;
    fifth->next = sixth ;
    sixth->next = seven ; 
    seven->next = eight ;
    eight->next = nine ;
    nine->next = tenth ;
    tenth->next = sixth ;

    if( is_loop_present( head ) ) 
        cout <<"Loop is present\n" ;

    else cout << "Loop is not present\n" ;

    Node* index = startint_point_loop( head ) ;

    cout << "Starting index of loop: "<<index->data << endl ;
    return 0;

}