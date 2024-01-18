#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data ;
    node* left ;
    node * right ;
    
    node( int data )
    {
        this->data = data ;
        left = NULL ;
        right = NULL ;
    }
};

node* buildTree( node* root )
{
    cout << "entre the data for root\n" ;
    int data ;
    cin >> data ; 
    root = new node( data ) ;
    if( data == -1 )
        return NULL ;

    cout << "enter the data for left of " <<data << endl  ;
    root->left = buildTree(root->left) ;
    cout << "enter the data for right of "<<data << endl ;
    root->right = buildTree(root->right) ;

    return root ;
}

void print_left_node( node* root )
{
    if( root == NULL )
        return ;

    if( root->left == NULL && root->right == NULL )
        return ;

    cout << root->data << endl ;
    print_left_node( root->left ) ;
    print_left_node( root->right ) ;

}

void print_leaf_node( node* root )
{
    if( root == NULL )
        return ;

    if( root->left == NULL && root->right == NULL )
        cout << root->data << " " ;

    if( root->left )
        print_leaf_node( root->left ) ;
    
    else 
        print_leaf_node( root->right ) ;

}

void print_right_node( node* root )
{
    if( root == NULL )
        return ;

    if( root->left == NULL && root->right == NULL )
        return ;

    if( root->right )
        print_right_node( root->right ) ;

    else 
        print_right_node( root->left ) ;

    cout << root->data << " " ;
}

void boundary_travelsal( node* root )
{
    if( root == NULL )
        return ;

    print_left_node( root->left ) ;

    print_leaf_node( root ) ;

    print_right_node( root->right ) ;
}

int main()
{
    node* root = NULL ;
    root = buildTree( root  ) ;

    cout << endl << endl ;
    boundary_travelsal( root ) ;

    return 0;
}