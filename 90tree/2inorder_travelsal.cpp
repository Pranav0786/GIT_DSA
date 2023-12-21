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
    cout << "enter the data for root\n" ;
    int data ;
    cin >> data ;
    root = new node(data) ;

    if( data == -1 ) return NULL ;

    cout << "enter the data of left of "<< data << endl ;
    root->left = buildTree( root->left ) ;
    cout << "enter the data of right of "<< data << endl ;
    root->right = buildTree( root->right ) ;

    return root ;
}
void inorder_travelsal( node* root )
{
    if( root == NULL )
        return ;
    
    inorder_travelsal( root->left ) ;
    cout<< root->data << " " ;
    inorder_travelsal( root->right ) ;
    
}
int main()
{
    node* root = NULL ;
    root = buildTree( root ) ;

    cout << endl ;

    inorder_travelsal( root ) ;
    return 0;
}