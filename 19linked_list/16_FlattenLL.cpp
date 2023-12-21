// gfg que 

#include<iostream>
#include<bits/stdc++.h>
using namespace std ; 

class Node
{
    public:
    int data ; 
    Node* next ; 
    Node* bottom ; 

    Node()
    {
        data = 00 ;
        next = NULL ;
        bottom = NULL ;
    }
    Node( int data )
    {
        this->data = data ; 
        this->next = NULL ;
        this->bottom = NULL ; 
    }
};

Node* merge( Node* a , Node* b )
{
    // merge by recursion
    if( a == NULL ) return b ; 
    if( b == NULL ) return a ; 
    
    Node* ans = NULL ;
    if( a->data <= b->data )
    {
        ans = a ;
        ans->bottom = merge( a->bottom , b ) ; 
    }
    
    else
    {
        ans = b ;
        ans->bottom = merge( a , b->bottom ) ; 
    } 
    
    return ans ; 
}

Node *flatten(Node *root)
{
   // reverse sorting 
   if( root == NULL ) return root ;  
   
   Node* result = merge( root , flatten( root->next ) ) ; 
   return result ; 
    
}

int main()
{
    return 0 ; 
}