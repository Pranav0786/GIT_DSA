// gfg Que

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    
    Node(int x)
    {
        data = x;
        next = NULL;
    }
    
};

class Solution
{
    public:
    void linkdelete( struct Node  *head, int M, int N ) 
    {
        //Add code here 
         if( head == NULL ) return ;
        
        Node* it = head ;
        for( int i=0 ; i< M-1 ; i++ )
        {
            if( it == NULL ) return ;
            it = it->next ;
        }
        
        if( it == NULL ) return ;
        
        Node* Mthnode = it ;
        it = it->next ;
        
        for( int i=0 ; i< N ; i++ )
        {
            if( it == NULL ) break ;
            Node* temp = it->next ;
            it->next = NULL ;
            delete it ;
            it = temp ; 
        }
        
        Mthnode->next = it ;
        
        linkdelete( it , M , N ) ;
    }
};
int main()
{
    return 0;
}