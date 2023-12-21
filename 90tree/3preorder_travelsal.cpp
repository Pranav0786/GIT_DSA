#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    int data ;
    node* left ;
    node* right ;

    node( int data )
    {
        this->data = data ;
        left = NULL ;
        right = NULL ;
    }
};

node* buildTree( node* root )
{
    cout <<"enter the data for root\n" ;
    int data ;
    cin >> data ;
    root = new node(data ) ;
    if( data == -1 ) return NULL ;

    cout << "enter the data for left of "<<data << endl ;
    root->left = buildTree( root->left) ;
    cout << "enter the data for right of "<<data << endl ;
    root->right = buildTree( root->right) ;

    return root ;
}
void preorder_travelsal( node* root )
{
    if( root ==  NULL )
        return ;

    cout << root->data << " " ;
    preorder_travelsal( root->left ) ;
    preorder_travelsal( root->right ) ;
}
int main()
{
    node* root = NULL ;
    root = buildTree( root ) ;
    cout << endl ;

    preorder_travelsal( root ) ;
    return 0;
}