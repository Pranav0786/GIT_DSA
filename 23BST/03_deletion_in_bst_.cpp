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

Node* find_node( Node* root , int val )
{
    if( root == NULL )
        return NULL ;

    if( root->data == val )
        return root ;

     if( root->data > val )
        return find_node(root->left , val ) ;

    else    
        return find_node( root->right , val ) ;
}

int find_max_element( Node* root )
{
    Node* temp = root ;

    while( temp->left != NULL )
        temp = temp->left ;
     
    return temp->data ;
}

int inorder_predeccer( Node* root )
{
    return find_max_element( root ) ;
}

Node* delete_node( Node* root , int target )
{
    if( root == NULL )
        return NULL ;

    if( root->data == target )
    {
        if( !root->left && !root->right )
            return NULL ;

        else if( root->left == NULL && root->right != NULL )
        {
            Node* child = root->right ;
            return child ;
        }

        else if( root->left != NULL && root->right == NULL )
        {
            Node* child = root->left ;
            return child ;
        }

        else
        {
            int inorderpre = inorder_predeccer( root->left ) ;
            root->data = inorderpre ;
            root->left = delete_node(root->left , inorderpre ) ;

            return root ;
        }
    }
    
    else if( target > root->data )
        root->right = delete_node( root->right , target ) ;

    else if( target < root->data )
        root->left = delete_node( root->left , target ) ;

    return root ;
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

int main()
{
    Node* root = NULL ;
    take_input( root ) ;

    cout << endl ;
    LevelOrderTravelsal( root ) ;

    root = delete_node( root , 110 ) ;

    cout << endl ;
    LevelOrderTravelsal( root ) ;

    return 0;
}