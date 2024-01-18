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

void LevelOrderTravelsal( node* root )
{
    queue<node*> q ;
    q.push( root ) ;
    q.push(NULL) ;

    while( !q.empty() ) 
    {
        node* temp = q.front() ;
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
int main()
{
    node* root = NULL ;
    root = buildTree( root  ) ;

    cout << endl ;
    LevelOrderTravelsal( root ) ;
    return 0;
}