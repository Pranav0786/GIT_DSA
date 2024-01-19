#include<bits/stdc++.h>
using namespace std;

class Node
{
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

bool is_Node_found( Node* root , int val )
{
    if( root == NULL )
        return false ;

    if( root->data == val )
        return true ;

     if( root->data > val )
        return is_Node_found(root->left , val ) ;

    else    
        return is_Node_found( root->right , val ) ;
}

int find_min_element( Node* root )
{
    Node* temp = root ;

    while( temp->left != NULL )
        temp = temp->left ;

    return temp->data ;
}

int find_max_element( Node* root )
{
    Node* temp = root ;

    while( temp->right != NULL )
        temp = temp->right ;
    
    return temp->data ;
}

int main()
{
    Node* root = NULL ;
    cout <<"enter data for root\n" ;

    take_input( root ) ;

    cout << "\nprinting\n" ;
    LevelOrderTravelsal( root ) ;

    cout << endl << endl ;
    cout << "Node is present or not: " << is_Node_found( root , 50 ) << endl  ;
    return 0;
}