#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data ;
    Node* left ;
    Node* right ;

    Node( int data )
    {
        this->data = data ;
        this->left = NULL ;
        this->right = NULL ;
    }
};

void LevelOrderTravelsal( Node* root )
{
    queue<Node*> q ;
    q.push( root ) ;
    q.push(NULL) ;

    while( !q.empty() ) 
    {
        Node* temp = q.front() ;
        q.pop() ;

        if( temp == NULL )
        {
            cout << endl ;
            if( !q.empty() ) 
                q.push(NULL) ;
        }
        else
        {
            cout << temp->data <<" " ;
            if( temp->left ) 
                q.push( temp->left) ;
            if( temp->right )
                q.push( temp->right ) ;
        }
    
    }
}

int find_position( int arr[] , int n , int element )
{
    for( int i=0 ; i < n ; i++ )
    {
        if( arr[i] == element )
            return i ;
    }

    return -1 ;
}

Node* build_tree_from_pre_in_order( int preorder[] , int inorder[] , int size , int &pre_index , 
                                    int in_start , int in_end )
{
    // base case
    if( pre_index >= size || in_start > in_end ) 
        return NULL ;

    // step A
    int element = preorder[pre_index++] ;
    Node* root = new Node(element) ;
    int pos = find_position( inorder , size , element ) ;

    // step B 
    // root->left solve
    root->left = build_tree_from_pre_in_order( preorder , inorder , size , pre_index , in_start , pos-1 ) ;

    // step C 
    // root->right solve
    root->right = build_tree_from_pre_in_order( preorder , inorder , size , pre_index , pos+1 , in_end ) ;

    return root ;
    
}
int main()
{
    int inorder[] = {40,20,50,10,60,30,70} ;
    int preorder[] = {10,20,40,50,30,60,70} ;

    int size = 7 ;
    int pre_index = 0 ;
    int in_start = 0 ;
    int in_end = size-1 ;

    Node* root = build_tree_from_pre_in_order(preorder , inorder , size , pre_index , in_start , in_end ) ;

    cout << "Printing\n" ;
    LevelOrderTravelsal( root ) ;
    return 0;
}