// inorder pre -> max element in left subtree
// inorder succ -> min element in right subtree

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data ;
    Node* left ;
    Node* right ;

    Node( int val )
    {
        data = val ;
        left = NULL ;
        right = NULL ;
    }
};

int find_min_element( Node* root )
{
    Node* temp = root ;

    while( temp->right != NULL )
        temp = temp->right ;

    return temp->data ;
}

int find_max_element( Node* root )
{
    Node* temp = root ;

    while( temp->left != NULL )
        temp = temp->left ;
     
    return temp->data ;
}

Node* build_bst( Node* root , int val ) 
{
    Node* NewNode = new Node(val) ;
    if( root == NULL )
    {
        root = NewNode ;
        return root ;
    }

    if( root->data > val )
        root->left = build_bst( root->left , val ) ;

    else 
        root->right = build_bst( root->right , val ) ;

    return root ;
}

void take_input( Node* &root ) 
{
    int val ;
    cin >> val ;
    while( val != -1 )
    {
        root = build_bst( root , val ) ;
        cin >> val ;
    }
}

int inorder_predeccer( Node* root )
{
    return find_max_element( root ) ;
}

int inorder_secceser( Node* root )
{
    return find_min_element( root ) ;
}

int main()
{
    Node* root = NULL ;
    take_input( root ) ;

    Node* p ;
    cout << inorder_predeccer( p->left ) ;
    cout << inorder_secceser( p->right ) ;

    return 0;
}