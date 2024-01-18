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
    int data  ;
    cin >> data ;

    root = new node(data) ;
    if( data == -1 ) return NULL ;

    cout << "enter the data for left of "<<data << endl ;
    root->left = buildTree( root->left ) ;
    cout << "enter the data for right of "<<data << endl ;
    root->right = buildTree( root->right ) ;

    return root ;
}
void postorder_travalsel( node* root )
{
    if( root == NULL ) return  ;

    postorder_travalsel( root->left ) ;
    postorder_travalsel( root->right ) ;
    cout << root->data << " " ;
}
int main()
{
    node* root = NULL ;
    root = buildTree( root ) ;
    cout << endl; 

    postorder_travalsel( root ) ;
    return 0;
}